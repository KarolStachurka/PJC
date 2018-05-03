#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    ui->helixPicture->setPixmap(helix.scaled(30, 30));
    ui->slugPicture->setPixmap(slug.scaled(30, 30));
    ui->wormPicture->setPixmap(worm.scaled(30, 30));
    ui->lettucePicture->setPixmap(lettuce.scaled(30, 30));
    ui->cabbagePicture->setPixmap(cabbage.scaled(30, 30));
    ui->grassPicture->setPixmap(grass.scaled(30, 30));

    scene = new myQGraphicsscene(this);
    scene->installEventFilter(this);
    connect(scene,SIGNAL(sendCoords(int,int)),this,SLOT(getMouseCoords(int,int)));

    //thread to maintaining simulation
    secondThread = new SimulationThread(this);
    qRegisterMetaType <Board>("Board");
    connect(this, SIGNAL(startSimulation(bool)),secondThread,SLOT(onSimStarted(bool)));
    connect(this,SIGNAL(endSecondThread(bool)),secondThread,SLOT(endThread(bool)));
    connect(this,SIGNAL(sendPrevBoard(Board)),secondThread,SLOT(getPrevBoard(Board)));
    connect(secondThread,SIGNAL(sendNextBoard(Board)),this,SLOT(getNextBoard(Board)));
    secondThread->start();

    this->board = Board(10, 10, 0, 0);
}

MainWindow::~MainWindow()
{

    emit endSecondThread(true);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    scene->clear();
    delete scene;
    delete secondThread;
    delete ui;
}
void MainWindow::displayBoard(Board board)
{
    for (unsigned int i = 0; i< boardObjects.size();i++)
    {
        delete (boardObjects.at(i));
    }
    boardObjects.clear();
    boardObjects.resize(board.getBoardColumnsNumber()*board.getBoardRowsNumber());
    qDeleteAll(ui->qBoard->items());
    scene->clear();
    delete scene;
    scene = new myQGraphicsscene(this);
    scene->installEventFilter(this);
    connect(scene,SIGNAL(sendCoords(int,int)),this,SLOT(getMouseCoords(int,int)));

    vector <Field> currentBoard = board.getBoard();
    int boardRows = board.getBoardRowsNumber();
    int boardColumns = board.getBoardColumnsNumber();
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem;
    for (int row = 0; row < boardRows; row++) {
        for (int col = 0; col < boardColumns; col++)
        {
            Field current = currentBoard[row * boardColumns + col];
            if(current.snail && current.plant)
                switch (current.snail->getType()) {
                case 1:
                    item = scene->addPixmap(snailWithPlant);
                    break;
                case 2:
                    item = scene->addPixmap(slugWithPlant);
                    break;
                case 3:
                    item = scene->addPixmap(wormWithPlant);
                    break;
                default:
                    item = scene->addPixmap(empty);
                    break;
                }
            else if (current.snail)
                switch (current.snail->getType()) {
                case 1:
                    item = scene->addPixmap(helix);
                    break;
                case 2:
                    item = scene->addPixmap(slug);
                    break;
                case 3:
                    item = scene->addPixmap(worm);
                    break;
                default:
                    item = scene->addPixmap(empty);
                    break;
                }
            else if(current.plant)
            {
                switch (current.plant->getType()) {
                case 1:
                    item = scene->addPixmap(lettuce);
                    break;
                case 2:
                    item = scene->addPixmap(cabbage);
                    break;
                case 3:
                    item = scene->addPixmap(grass);
                    break;
                default:
                    item = scene->addPixmap(empty);
                    break;
                }
            }
            else
                item = scene->addPixmap(empty);
            item->moveBy(15*row, 15*col);
            boardObjects.at(row*boardColumns + col) =  item;
            item = NULL;
        }
    }
    currentBoard.clear();
    ui->qBoard->setScene(scene);
    ui->qBoard->setMaximumHeight(boardColumns*15);
    ui->qBoard->setMaximumWidth(boardRows*15);
}

void MainWindow::on_nextTurn_clicked()
{
    if(this->board.getTurn() > 0)
    {
        board.nextTurn();
        QPointF center = ui->qBoard->mapToScene(ui->qBoard->viewport()->rect()).boundingRect().center();
        displayBoard(board);
        ui->qBoard->centerOn(center);
        QString turnNumber = QString::number(board.getTurn());
        QString plantNumber = QString::number(board.getPlantNumber());
        QString snailNumber = QString::number(board.getSnailNumber());
        ui->turnNumberDisplay->setText(turnNumber);
        ui->plantNumberDisplay->setText(plantNumber);
        ui->snailNumberDisplay->setText(snailNumber);
    }
}

void MainWindow::on_automaticMode_clicked()
{
    QString text1 = "Start";
    QString text2 = "Pause";
    int lettuce = ui->lettuceNumberEdit->value();
    int cabbage = ui->cabbageNumberEdit->value();
    int grass = ui->grassNumberEdit->value();
    int helix = ui->helixNumberEdit->value();
    int slug = ui->slugNumberEdit->value();
    int worm = ui->wormNumberEdit->value();
    if(ui->mapHuge->isChecked() && board.getTurn() < 1)
    {
        if(ui->randomStartCheckBox->isChecked())
            this->board = Board(75, 75, lettuce, cabbage, grass, helix, slug ,worm);
        else
            this->board = Board(75, 75, 0, 0);
    }
    else if(ui->mapMedium->isChecked() && board.getTurn() < 1)
    {
        if(ui->randomStartCheckBox->isChecked())
            this->board = Board(50, 50, lettuce, cabbage, grass, helix, slug ,worm);
        else
            this->board = Board(50, 50, 0, 0);
    }
    else if(board.getTurn() < 1)
    {
        if(ui->randomStartCheckBox->isChecked())
            this->board = Board(30, 30, lettuce, cabbage, grass, helix, slug ,worm);
        else
            this->board = Board(30, 30, 0, 0);
    }
    if(!simStarted)
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->automaticMode->setText(text2);
        ui->nextTurn->setEnabled(false);
        ui->resetButton->setEnabled(false);
        simStarted = true;
        emit startSimulation(simStarted);
        emit sendPrevBoard(this->board);
    }
    else
    {
        ui->automaticMode->setText(text1);
        ui->nextTurn->setEnabled(true);
        ui->resetButton->setEnabled(true);
        simStarted = false;
        emit startSimulation(simStarted);
    }

}
void MainWindow::getNextBoard(Board board)
{
    this->board = board;
    QPointF center = ui->qBoard->mapToScene(ui->qBoard->viewport()->rect()).boundingRect().center();
    displayBoard(board);
    ui->qBoard->centerOn(center);
    QString turnNumber = QString::number(board.getTurn());
    QString plantNumber = QString::number(board.getPlantNumber());
    QString snailNumber = QString::number(board.getSnailNumber());
    ui->turnNumberDisplay->setText(turnNumber);
    ui->plantNumberDisplay->setText(plantNumber);
    ui->snailNumberDisplay->setText(snailNumber);
}

void MainWindow::on_resetButton_clicked()
{
    int lettuce = ui->lettuceNumberEdit->value();
    int cabbage = ui->cabbageNumberEdit->value();
    int grass = ui->grassNumberEdit->value();
    int helix = ui->helixNumberEdit->value();
    int slug = ui->slugNumberEdit->value();
    int worm = ui->wormNumberEdit->value();
    if(ui->mapHuge->isChecked())
    {
        if(ui->randomStartCheckBox->isChecked())
            this->board = Board(75, 75, lettuce, cabbage, grass, helix, slug ,worm);
        else
            this->board = Board(75, 75, 0, 0);
    }
    else if(ui->mapMedium->isChecked())
    {
        if(ui->randomStartCheckBox->isChecked())
            this->board = Board(50, 50, lettuce, cabbage, grass, helix, slug ,worm);
        else
            this->board = Board(50, 50, 0, 0);
    }
    else
    {
        if(ui->randomStartCheckBox->isChecked())
            this->board = Board(30, 30, lettuce, cabbage, grass, helix, slug ,worm);
        else
            this->board = Board(30, 30, 0, 0);
    }
    board.nextTurn();
    displayBoard(board);
}
void MainWindow::getMouseCoords(int x, int y)
{
    if(!simStarted && board.getTurn() > 0 && ui->tabWidget->currentIndex() == 3)
    {
        int type = 0;
        if(ui->addHelixRadioButton->isChecked())
            type = 1;
        if(ui->addSlugRadioButton->isChecked())
            type = 2;
        if(ui->addWormRadioButton->isChecked())
            type = 3;
        board.addSnail(x/15, y/15, type);
        QString turnNumber = QString::number(board.getTurn());
        QString plantNumber = QString::number(board.getPlantNumber());
        QString snailNumber = QString::number(board.getSnailNumber());
        ui->turnNumberDisplay->setText(turnNumber);
        ui->plantNumberDisplay->setText(plantNumber);
        ui->snailNumberDisplay->setText(snailNumber);
    }
    if(!simStarted && board.getTurn() > 0 && ui->tabWidget->currentIndex() == 2)
    {
        int type = 0;
        if(ui->addLettuceRadioButton->isChecked())
            type = 1;
        if(ui->addCabbageRadioButton->isChecked())
            type = 2;
        if(ui->addGrassRadioButton->isChecked())
            type = 3;
        board.addPlant(x/15, y/15,type);
        QString turnNumber = QString::number(board.getTurn());
        QString plantNumber = QString::number(board.getPlantNumber());
        QString snailNumber = QString::number(board.getSnailNumber());
        ui->turnNumberDisplay->setText(turnNumber);
        ui->plantNumberDisplay->setText(plantNumber);
        ui->snailNumberDisplay->setText(snailNumber);
    }
    if(!simStarted && board.getTurn() > 0 && ui->tabWidget->currentIndex() == 1)
    {
         vector <Field> currentBoard = board.getBoard();
         Field current = currentBoard[(x/15) * board.getBoardColumnsNumber() + (y/15)];
         QString info = "";
         if(current.plant != NULL)
            info += QString::fromStdString(current.plant->getPlantInfo());
         if(current.snail != NULL)
            info += QString::fromStdString(current.snail->getSnailInfo());
         ui->plainTextEdit->clear();
         ui->plainTextEdit->appendPlainText(info);
    }
    QPointF center = ui->qBoard->mapToScene(ui->qBoard->viewport()->rect()).boundingRect().center();
    displayBoard(board);
    ui->qBoard->centerOn(center);
}

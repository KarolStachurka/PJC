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
    ui->helixPicture1->setPixmap(helix.scaled(30, 30));
    ui->slugPicture1->setPixmap(slug.scaled(30, 30));
    ui->wormPicture1->setPixmap(worm.scaled(30, 30));
    ui->lettucePicture1->setPixmap(lettuce.scaled(30, 30));
    ui->cabbagePicture1->setPixmap(cabbage.scaled(30, 30));
    ui->grassPicture1->setPixmap(grass.scaled(30, 30));

    scene = new myQGraphicsscene(this);
    scene->installEventFilter(this);
    connect(scene,SIGNAL(sendCoords(int,int)),this,SLOT(getMouseCoords(int,int)));

    //thread to maintaining simulation
    secondThread = new SimulationThread(this);
    qRegisterMetaType <Game>("Game");
    connect(this, SIGNAL(startSimulation(bool)), secondThread, SLOT(onSimStarted(bool)));
    connect(this, SIGNAL(endSecondThread(bool)), secondThread, SLOT(endThread(bool)));
    connect(this, SIGNAL(sendCurrentGame(Game)), secondThread, SLOT(getCurrentGame(Game)));
    connect(secondThread, SIGNAL(sendUpdatedGame(Game)), this, SLOT(getUpdatedGame(Game)));
    secondThread->start();

    this->game = Game();
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
void MainWindow::displayBoard()
{
    int boardRows, boardCols;
    game.getBoardSize(boardRows, boardCols);
    //cleaning memory and preparing new scene
    for (unsigned int i = 0; i< boardObjects.size();i++)
    {
        delete (boardObjects.at(i));
    }
    boardObjects.clear();
    boardObjects.resize(boardRows*boardCols);
    qDeleteAll(ui->qBoard->items());
    scene->clear();
    delete scene;
    scene = new myQGraphicsscene(this);
    scene->installEventFilter(this);
    connect(scene, SIGNAL(sendCoords(int,int)), this, SLOT(getMouseCoords(int,int)));


    vector<int> board = game.getEncodedBoard();
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem;
    for (int row = 0; row < boardRows; row++) {
        for (int col = 0; col < boardCols; col++)
        {
            switch(board.at(row * boardCols + col)){
            case 1:
                item = scene->addPixmap(lettuce);
                break;
            case 2:
                item = scene->addPixmap(cabbage);
                break;
            case 3:
                item = scene->addPixmap(grass);
                break;
            case 10:
                item = scene->addPixmap(helix);
                break;
            case 20:
                item = scene->addPixmap(slug);
                break;
            case 30:
                item = scene->addPixmap(worm);
                break;
            case 11:
                item = scene->addPixmap(snailWithPlant);
                break;
            case 12:
                item = scene->addPixmap(snailWithPlant);
                break;
            case 13:
                item = scene->addPixmap(snailWithPlant);
                break;
            case 21:
                item = scene->addPixmap(slugWithPlant);
                break;
            case 22:
                item = scene->addPixmap(slugWithPlant);
                break;
            case 23:
                item = scene->addPixmap(slugWithPlant);
                break;
            case 31 :
                item = scene->addPixmap(wormWithPlant);
                break;
            case 32 :
                item = scene->addPixmap(wormWithPlant);
                break;
            case 33 :
                item = scene->addPixmap(wormWithPlant);
                break;
            default:
                item = scene->addPixmap(empty);
                break;
            }
            item->moveBy(15*row, 15*col);
            boardObjects.at(row*boardCols + col) =  item;
        }
    }
    ui->qBoard->setScene(scene);
    ui->qBoard->setMaximumHeight(boardCols*15);
    ui->qBoard->setMaximumWidth(boardRows*15);
}

void MainWindow::on_nextTurn_clicked()
{
    if(game.getTurnNumber() > 0)
    {
        game.nextTurn();
        QPointF center = ui->qBoard->mapToScene(ui->qBoard->viewport()->rect()).boundingRect().center();
        displayBoard();
        ui->qBoard->centerOn(center);
        updateCounterValues();

    }
}

void MainWindow::on_automaticMode_clicked()
{
    int lettuce = ui->lettuceNumberEdit->value();
    int cabbage = ui->cabbageNumberEdit->value();
    int grass = ui->grassNumberEdit->value();
    int helix = ui->helixNumberEdit->value();
    int slug = ui->slugNumberEdit->value();
    int worm = ui->wormNumberEdit->value();
    if(ui->mapHuge->isChecked() && game.getTurnNumber() < 1)
    {
        if(!ui->emptyMapCheckBox->isChecked())
        {
             game.newGame(3, lettuce, cabbage, grass, helix, slug ,worm);
        }
        else
        {
            game.newGame(3, 0, 0, 0, 0, 0, 0);
        }
    }
    else if(ui->mapMedium->isChecked() && game.getTurnNumber() < 1)
    {
        if(!ui->emptyMapCheckBox->isChecked())
        {
            game.newGame(2, lettuce, cabbage, grass, helix, slug ,worm);
        }
        else
        {
            game.newGame(2, 0, 0, 0, 0, 0, 0);
        }
    }
    else if(game.getTurnNumber() < 1)
    {
        if(!ui->emptyMapCheckBox->isChecked())
        {
            game.newGame(1, lettuce, cabbage, grass, helix, slug ,worm);
        }
        else
        {
            game.newGame(1, 0, 0, 0, 0, 0, 0);
        }
    }
    if(!simStarted)
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->automaticMode->setText(text2);
        ui->nextTurn->setEnabled(false);
        ui->resetButton->setEnabled(false);
        simStarted = true;
        emit startSimulation(simStarted);
        emit sendCurrentGame(this->game);
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
void MainWindow::updateCounterValues()
{
    int lettuce = 0, cabbage = 0, grass = 0, helix = 0, slug = 0, worm = 0;
    game.getOrganismsNumber(lettuce, cabbage, grass, helix, slug, worm);
    QString turnNumber = QString::number(game.getTurnNumber());
    QString lettuceNumber = QString::number(lettuce);
    QString cabbageNumber = QString::number(cabbage);
    QString grassNumber = QString::number(grass);
    QString helixNumber = QString::number(helix);
    QString slugNumber = QString::number(slug);
    QString wormNumber = QString::number(worm);
    ui->turnNumberDisplay->setText(turnNumber);
    ui->lettuceNumber->setText(lettuceNumber);
    ui->cabbageNumber->setText(cabbageNumber);
    ui->grassNumber->setText(grassNumber);
    ui->helixNumber->setText(helixNumber);
    ui->slugNumber->setText(slugNumber);
    ui->wormNumber->setText(wormNumber);
}
void MainWindow::getUpdatedGame(Game game)
{
    this->game = game;
    QPointF center = ui->qBoard->mapToScene(ui->qBoard->viewport()->rect()).boundingRect().center();
    displayBoard();
    ui->qBoard->centerOn(center);
    updateCounterValues();
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
        if(!ui->emptyMapCheckBox->isChecked())
        {
            game.newGame(3, lettuce, cabbage, grass, helix, slug ,worm);
        }
        else
        {
            game.newGame(3, 0, 0, 0, 0, 0, 0);
        }
    }
    else if(ui->mapMedium->isChecked())
    {
        if(!ui->emptyMapCheckBox->isChecked())
        {
            game.newGame(2, lettuce, cabbage, grass, helix, slug ,worm);
        }
        else
        {
            game.newGame(2, 0, 0, 0, 0, 0, 0);
        }
    }
    else
    {
        if(!ui->emptyMapCheckBox->isChecked())
        {
            game.newGame(1, lettuce, cabbage, grass, helix, slug ,worm);
        }
        else
        {
            game.newGame(1, 0, 0, 0, 0, 0, 0);
        }
    }
    game.nextTurn();
    displayBoard();
    updateCounterValues();
    ui->tabWidget->setCurrentIndex(1);
}
void MainWindow::getMouseCoords(int x, int y)
{
    if(!simStarted && game.getTurnNumber() > 0 && ui->tabWidget->currentIndex() == 3)
    {
        int index = 0;
        if(ui->addHelixRadioButton->isChecked())
            index = 1;
        if(ui->addSlugRadioButton->isChecked())
            index = 2;
        if(ui->addWormRadioButton->isChecked())
            index = 3;
        game.addOrganism(x/15, y/15, index, "snail");
        updateCounterValues();
    }
    if(!simStarted && game.getTurnNumber() > 0 && ui->tabWidget->currentIndex() == 2)
    {
        int index = 0;
        if(ui->addLettuceRadioButton->isChecked())
            index = 1;
        if(ui->addCabbageRadioButton->isChecked())
            index = 2;
        if(ui->addGrassRadioButton->isChecked())
            index = 3;
        game.addOrganism(x/15, y/15, index, "plant");
        updateCounterValues();
    }
    if(!simStarted && game.getTurnNumber() > 0 && ui->tabWidget->currentIndex() == 1)
    {
         QString info = QString::fromStdString(game.getFieldInfo(x/15, y/15));
         ui->plainTextEdit->clear();
         ui->plainTextEdit->appendPlainText(info);

    }
    QPointF center = ui->qBoard->mapToScene(ui->qBoard->viewport()->rect()).boundingRect().center();
    displayBoard();
    ui->qBoard->centerOn(center);
}

void MainWindow::on_killPlantsButton_clicked()
{
    game.removePlants();
    displayBoard();
    updateCounterValues();
}

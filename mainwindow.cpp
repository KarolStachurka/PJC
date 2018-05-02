#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    ui->helixPicture->setPixmap(snail.scaled(30,30));
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

    this->board = Board(50, 50, 50, 100);
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
            if(current.getSnailExistence() && current.getPlantExistence())
                item = scene->addPixmap(snailCabbage);
            else if (current.getSnailExistence())
                item = scene->addPixmap(snail);
            else if(current.getPlantExistence())
                item = scene->addPixmap(cabbage);
            else
                item = scene->addPixmap(empty);
            item->moveBy(15*row, 15*col);
            boardObjects.at(row*boardColumns + col) =  item;
            item = NULL;
        }
    }
    currentBoard.clear();
    ui->qBoard->setScene(scene);
}

void MainWindow::on_nextTurn_clicked()
{
    board.nextTurn();
    displayBoard(board);
    QString turnNumber = QString::number(board.getTurn());
    QString plantNumber = QString::number(board.getPlantNumber());
    QString snailNumber = QString::number(board.getSnailNumber());
    ui->turnNumberDisplay->setText(turnNumber);
    ui->plantNumberDisplay->setText(plantNumber);
    ui->snailNumberDisplay->setText(snailNumber);
}

void MainWindow::on_automaticMode_clicked()
{
    QString text1 = "Start";
    QString text2 = "Pause";
    if(ui->mapHuge->isChecked() && board.getTurn() < 1)
        this->board = Board(75, 75, 100, 1000);
    else if(ui->mapMedium->isChecked() && board.getTurn() < 1)
        this->board = Board(50, 50, 50, 100);
    else if(board.getTurn() < 1)
        this->board = Board(10, 10, 0, 10);
    if(!simStarted)
    {
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
    ui->qBoard->items().clear();
    displayBoard(board);
    QString turnNumber = QString::number(board.getTurn());
    QString plantNumber = QString::number(board.getPlantNumber());
    QString snailNumber = QString::number(board.getSnailNumber());
    ui->turnNumberDisplay->setText(turnNumber);
    ui->plantNumberDisplay->setText(plantNumber);
    ui->snailNumberDisplay->setText(snailNumber);
}

void MainWindow::on_resetButton_clicked()
{
    if(ui->mapHuge->isChecked())
        this->board = Board(75, 75, 100, 1000);
    else if(ui->mapMedium->isChecked())
        this->board = Board(50, 50, 50, 100);
    else
        this->board = Board(30, 30, 10, 100);
    displayBoard(board);
}
void MainWindow::getMouseCoords(int x, int y)
{
    if(!simStarted && board.getTurn() > 0 && ui->tabWidget->currentIndex() == 2)
    {
        board.addSnail(x/15,y/15);
        displayBoard(board);
        QString turnNumber = QString::number(board.getTurn());
        QString plantNumber = QString::number(board.getPlantNumber());
        QString snailNumber = QString::number(board.getSnailNumber());
        ui->turnNumberDisplay->setText(turnNumber);
        ui->plantNumberDisplay->setText(plantNumber);
        ui->snailNumberDisplay->setText(snailNumber);
    }
    if(!simStarted && board.getTurn() > 0 && ui->tabWidget->currentIndex() == 0)
    {
         vector <Field> currentBoard = board.getBoard();
         Field current = currentBoard[(x/15) * board.getBoardColumnsNumber() + (y/15)];
         QString info = QString::fromStdString(current.getFieldInfo());
         ui->plainTextEdit->clear();
         ui->plainTextEdit->appendPlainText(info);
    }

}

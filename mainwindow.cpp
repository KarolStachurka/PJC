#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    Board board(10, 10, 10, 1);
    this->board = board;
    QString turnNumber = QString::number(board.getTurn());
    ui->turnNumberDisplay->setText(turnNumber);
    displayBoard(board);
}
void MainWindow::displayBoard(Board board)
{
    scene = new QGraphicsScene(this);
    ui->qBoard->setScene(scene);
    vector <Field> currentBoard = board.getBoard();
    int boardRows = board.getBoardRowsNumber();
    int boardColumns = board.getBoardColumnsNumber();
    for (int row = 0; row < boardRows; row++) {
        for (int col = 0; col < boardColumns; col++)
        {
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem;
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
            boardObjects.push_back(item);
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_nextTurn_clicked()
{
    board.nextTurn();
    displayBoard(board);
    QString turnNumber = QString::number(board.getTurn());
    ui->turnNumberDisplay->setText(turnNumber);
}

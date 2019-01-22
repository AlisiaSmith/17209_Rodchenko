#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::setColAndRow(int col, int row)
{
    tableWidget->setColumnCount(col);
    tableWidget->setRowCount(row);

    columns = col;
    rows = row;

    for(int i = 0; i < columns; i++)
        for(int j = 0; j < rows; j++)
        {
            tableWidget->setItem(j, i, new QTableWidgetItem());
            tableWidget->item(j, i)->setBackground(Qt::black);
        }

    for(int i = 0; i < columns; i++)
        tableWidget->setColumnWidth(i, 24);

    for(int i = 0; i < rows; i++)
        tableWidget->setRowHeight(i, 24);

    int maxWidth = 1300;
    int maxHeight = 1000;
    if (((columns + 1) * 24 - 16) < maxWidth) maxWidth = (columns + 1) * 24 - 16;
    if (((rows + 1) * 24 - 16) < maxHeight) maxHeight = (rows + 1) * 24 - 16;

    tableWidget->setMinimumWidth(maxWidth);
    tableWidget->setMinimumHeight(maxHeight);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rows = 40; columns = 50;

    tableWidget = new QTableWidget(this);

    tableWidget->verticalHeader()->hide();
    tableWidget->horizontalHeader()->hide();

    setColAndRow(columns, rows);

    f = new Field(columns, rows);
}

MainWindow::~MainWindow()
{
    for(int i = 0; i < columns; i++)
        for(int j = 0; j < rows; j++)
         delete  tableWidget->item(j, i);

    delete tableWidget;
    delete ui;
    delete f;
}

void MainWindow::rePaint()
{
    for(int i = 0; i < columns; i++)
        for(int j = 0; j <  rows; j++)
            if(f->getCell(i, j).now)
                tableWidget->item(j, i)->setBackground(Qt::cyan);
            else
                tableWidget->item(j, i)->setBackground(Qt::black);
    repaint();

}

void MainWindow::on_Random_clicked()
{
    f->random();

    rePaint();
}

void MainWindow::on_Step_clicked()
{
    f->step();

    rePaint();
}

bool MainWindow::isNotEnd()
{
    return f->isNotEnd();
}

void MainWindow::on_Start_clicked()
{
    f->computation();

    while(isNotEnd())
    {
        f->step();
        rePaint();
        f->computation();
        usleep(100000);
    }

}

void MainWindow::on_Save_clicked()
{
    f->save();
}


void MainWindow::on_Load_clicked()
{
    f->load();

    for(int i = 0; i < columns; i++)
        for(int j = 0; j < rows; j++)
         delete   tableWidget->item(j, i);

    setColAndRow(f->getWidht(), f->getHeight());

    rePaint();
}


void MainWindow::on_Clear_clicked()
{
   f->clear();

   rePaint();

}

void MainWindow::on_tableWidget_cellClicked(int row, int col)
{
   f->click(col, row);

   rePaint();
}

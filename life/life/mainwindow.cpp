#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::setColAndRow(int col, int row)
{
     ui->tableWidget->setColumnCount(col);
     ui->tableWidget->setRowCount(row);

    columns = col;
    rows = row;

    for(int i = 0; i < columns; i++)
        for(int j = 0; j < rows; j++)
        {
             ui->tableWidget->setItem(j, i, new QTableWidgetItem());
             ui->tableWidget->item(j, i)->setBackground(Qt::black);
        }

    for(int i = 0; i < columns; i++)
         ui->tableWidget->setColumnWidth(i, 24);

    for(int i = 0; i < rows; i++)
         ui->tableWidget->setRowHeight(i, 24);

    int maxWidth = 1300;
    int maxHeight = 970;
    if (((columns + 1) * 24 - 16) < maxWidth) maxWidth = (columns + 1) * 24 - 16;
    if (((rows + 1) * 24 - 16) < maxHeight) maxHeight = (rows + 1) * 24 - 16;

     ui->tableWidget->setMinimumWidth(maxWidth);
     ui->tableWidget->setMinimumHeight(maxHeight);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rows = 40; columns = 50;

     ui->tableWidget->verticalHeader()->hide();
     ui->tableWidget->horizontalHeader()->hide();

    setColAndRow(columns, rows);

    f = new Field(columns, rows);
}

MainWindow::~MainWindow()
{
    for(int i = 0; i < columns; i++)
        for(int j = 0; j < rows; j++)
         delete   ui->tableWidget->item(j, i);

    delete ui;
    delete f;
}

void MainWindow::rePaint()
{
    for(int i = 0; i < columns; i++)
        for(int j = 0; j <  rows; j++)
            if(f->getCell(i, j).now)
                 ui->tableWidget->item(j, i)->setBackground(Qt::cyan);
            else
                 ui->tableWidget->item(j, i)->setBackground(Qt::black);
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
    QTime t;

    t.start();

    while(isNotEnd())
    {
        if(t.elapsed() < 100) continue;
        t.restart();
        f->step();
        rePaint();
        f->computation();

        if(mousePressEvent())  break;
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
         delete    ui->tableWidget->item(j, i);

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

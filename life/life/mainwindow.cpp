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
    int maxHeight = 970;
    if (((columns + 1) * 24 - 16) < maxWidth) maxWidth = (columns + 1) * 24 - 16;
    if (((rows + 1) * 24 - 16) < maxHeight) maxHeight = (rows + 1) * 24 - 16;

    for (int i = 0; i < 6; i++)
        but[i].setGeometry(maxWidth + 100, 200 + i * 70, 200, 50 );


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

    timer = new QTimer;
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(Time()));

    but = new QPushButton[6];

    QString s[] = {"Random", "Step", "Start", "Save", "Load", "Clear"};

    for (int i = 0; i < 6; i++)
    {
        but[i].setParent(this);
        //but[i].setGeometry(1000, 200 + i * 70, 250, 60 );
        but[i].setText(s[i]);
    }

        connect(&but[0],SIGNAL(clicked()), this, SLOT(on_Random_clicked()));
        connect(&but[1],SIGNAL(clicked()), this, SLOT(on_Step_clicked()));
        connect(&but[2],SIGNAL(clicked()), this, SLOT(on_Start_clicked()));
        connect(&but[3],SIGNAL(clicked()), this, SLOT(on_Save_clicked()));
        connect(&but[4],SIGNAL(clicked()), this, SLOT(on_Load_clicked()));
        connect(&but[5],SIGNAL(clicked()), this, SLOT(on_Clear_clicked()));

        connect(tableWidget,SIGNAL(cellClicked(int,int)), this, SLOT(on_tableWidget_cellClicked(int, int)));

        setColAndRow(columns, rows);

        f = new Field(columns, rows);
}

MainWindow::~MainWindow()
{
    delete timer;

    for(int i = 0; i < columns; i++)
        for(int j = 0; j < rows; j++)
         delete  tableWidget->item(j, i);

    delete[] but;
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

void MainWindow::Time()
{
        f->computation();
        f->step();
        rePaint();
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
    static bool recountOn = false;
    recountOn = !recountOn;
    if(recountOn)
    {
        timer->start();
        but[2].setText("Stop");
    }
    else
    {
        timer->stop();
        but[2].setText("Start");
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

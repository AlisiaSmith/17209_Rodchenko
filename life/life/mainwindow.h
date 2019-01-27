#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <unistd.h>

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>

#include "field.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void rePaint();

    void setColAndRow(int col, int row);

    bool isNotEnd();
private slots:
    void on_Random_clicked();

    void on_Step_clicked();

    void on_Start_clicked();

    void on_Save_clicked();

    void on_Load_clicked();

    void on_Clear_clicked();

    void on_tableWidget_cellClicked(int col, int row);

    void Time();
private:
    Ui::MainWindow *ui; 
    Field *f;

    QTimer *timer;

    int rows;
    int columns;


    //QPushButton *ButRand;
};
#endif // MAINWINDOW_H

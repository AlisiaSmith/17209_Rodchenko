/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Random;
    QPushButton *Step;
    QPushButton *Start;
    QPushButton *Save;
    QPushButton *Load;
    QPushButton *Clear;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1566, 1014);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1310, 150, 201, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Random = new QPushButton(verticalLayoutWidget);
        Random->setObjectName(QStringLiteral("Random"));

        verticalLayout->addWidget(Random);

        Step = new QPushButton(verticalLayoutWidget);
        Step->setObjectName(QStringLiteral("Step"));

        verticalLayout->addWidget(Step);

        Start = new QPushButton(verticalLayoutWidget);
        Start->setObjectName(QStringLiteral("Start"));

        verticalLayout->addWidget(Start);

        Save = new QPushButton(verticalLayoutWidget);
        Save->setObjectName(QStringLiteral("Save"));

        verticalLayout->addWidget(Save);

        Load = new QPushButton(verticalLayoutWidget);
        Load->setObjectName(QStringLiteral("Load"));

        verticalLayout->addWidget(Load);

        Clear = new QPushButton(verticalLayoutWidget);
        Clear->setObjectName(QStringLiteral("Clear"));

        verticalLayout->addWidget(Clear);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 41, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1566, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Random->setText(QApplication::translate("MainWindow", "Random", Q_NULLPTR));
        Step->setText(QApplication::translate("MainWindow", "Step", Q_NULLPTR));
        Start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        Save->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        Load->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        Clear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

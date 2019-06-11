/********************************************************************************
** Form generated from reading UI file 'QTcpServerDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCPSERVERDEMO_H
#define UI_QTCPSERVERDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTcpServerDemoClass
{
public:
    QWidget *centralWidget;
    QListWidget *listMsg;
    QLabel *labelInfo;
    QListWidget *listClient;
    QLabel *labelUI;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTcpServerDemoClass)
    {
        if (QTcpServerDemoClass->objectName().isEmpty())
            QTcpServerDemoClass->setObjectName(QString::fromUtf8("QTcpServerDemoClass"));
        QTcpServerDemoClass->resize(600, 511);
        centralWidget = new QWidget(QTcpServerDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listMsg = new QListWidget(centralWidget);
        listMsg->setObjectName(QString::fromUtf8("listMsg"));
        listMsg->setGeometry(QRect(10, 240, 581, 192));
        labelInfo = new QLabel(centralWidget);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(10, 30, 571, 16));
        listClient = new QListWidget(centralWidget);
        listClient->setObjectName(QString::fromUtf8("listClient"));
        listClient->setGeometry(QRect(10, 50, 581, 171));
        labelUI = new QLabel(centralWidget);
        labelUI->setObjectName(QString::fromUtf8("labelUI"));
        labelUI->setGeometry(QRect(10, 10, 571, 16));
        QTcpServerDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTcpServerDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        QTcpServerDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTcpServerDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QTcpServerDemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTcpServerDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QTcpServerDemoClass->setStatusBar(statusBar);

        retranslateUi(QTcpServerDemoClass);

        QMetaObject::connectSlotsByName(QTcpServerDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTcpServerDemoClass)
    {
        QTcpServerDemoClass->setWindowTitle(QApplication::translate("QTcpServerDemoClass", "QTcpServerDemo", nullptr));
        labelInfo->setText(QApplication::translate("QTcpServerDemoClass", "TextLabel", nullptr));
        labelUI->setText(QApplication::translate("QTcpServerDemoClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTcpServerDemoClass: public Ui_QTcpServerDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCPSERVERDEMO_H

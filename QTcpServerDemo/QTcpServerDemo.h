#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTcpServerDemo.h"

class QTcpServerDemo : public QMainWindow
{
	Q_OBJECT

public:
	QTcpServerDemo(QWidget *parent = Q_NULLPTR);
	void SetLabel(std::string info);
	void AddMsg(std::string msg);
	void AddClient(std::string client);

private:
	Ui::QTcpServerDemoClass ui;
};

#include "QTcpServerDemo.h"
#include <sstream>
#include <qthread.h>

QTcpServerDemo::QTcpServerDemo(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);
	std::stringstream ss;
	ss << "UI ThreadID:" << QThread::currentThreadId();
	std::string info = ss.str() ;
	
	ui.labelUI->setText(info.c_str());
}

void QTcpServerDemo::SetLabel(std::string info) {
	ui.labelInfo->setText(info.c_str());
}

void QTcpServerDemo::AddMsg(std::string msg) {
	ui.listMsg->insertItem(0, QString(msg.c_str()));
}

void QTcpServerDemo::AddClient(std::string client) {
	QListWidgetItem qwi;	
	qwi.setText(QString(client.c_str()));
	qwi.setData(1, 1);
	ui.listClient->insertItem(0, &qwi);
}
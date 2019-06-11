#include "DMMPackageSocket.h"
#include "QTcpServerDemo.h"
#include <sstream>
#include <qthread.h>
#include <qabstractsocket.h>

DMMPackageSocket::DMMPackageSocket(QTcpSocket *parent, DMMServer* pServer)
	: mpts(parent),
	mdms(pServer){
	// 绑定可读取信号。有数据时自动读取。
	connect(qobject_cast<QIODevice *>(mpts), &QIODevice::readyRead, this, &DMMPackageSocket::readyRead);
	//connect(qobject_cast<QAbstractSocket *>(mpts), &QAbstractSocket::disconnected, this, &DMMPackageSocket::disconnected);
	//connect(qobject_cast<QAbstractSocket *>(mpts), &QAbstractSocket::error(int), this, &DMMPackageSocket::error);
}

DMMPackageSocket::~DMMPackageSocket(){
	//delete mpts;
}

void DMMPackageSocket::readyRead() {
	QTcpSocket * pSocket = qobject_cast<QTcpSocket *>(sender());
	QByteArray buf = mpts->readAll(); //这里接受数据。
	//std::stringstream ss;
	//ss << "socket:" << pSocket->socketDescriptor() << " ThreadID: " << QThread::currentThreadId() << " msg: " << buf.operator const char *();
	//mdms->mpDemo->AddMsg(ss.str()); // 显示收到的数据。
	//std::string info = ss.str();
	//qDebug() << info.c_str();
	mpts->write(buf); // echo 回显数据。
}


void DMMPackageSocket::error(QAbstractSocket::SocketError) {

}

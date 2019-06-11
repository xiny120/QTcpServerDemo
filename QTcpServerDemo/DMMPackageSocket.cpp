#include "DMMPackageSocket.h"
#include "QTcpServerDemo.h"
#include <sstream>
#include <qthread.h>
#include <qabstractsocket.h>

DMMPackageSocket::DMMPackageSocket(QTcpSocket *parent, DMMServer* pServer)
	: mpts(parent),
	mdms(pServer){
	// �󶨿ɶ�ȡ�źš�������ʱ�Զ���ȡ��
	connect(qobject_cast<QIODevice *>(mpts), &QIODevice::readyRead, this, &DMMPackageSocket::readyRead);
	//connect(qobject_cast<QAbstractSocket *>(mpts), &QAbstractSocket::disconnected, this, &DMMPackageSocket::disconnected);
	//connect(qobject_cast<QAbstractSocket *>(mpts), &QAbstractSocket::error(int), this, &DMMPackageSocket::error);
}

DMMPackageSocket::~DMMPackageSocket(){
	//delete mpts;
}

void DMMPackageSocket::readyRead() {
	QTcpSocket * pSocket = qobject_cast<QTcpSocket *>(sender());
	QByteArray buf = mpts->readAll(); //����������ݡ�
	//std::stringstream ss;
	//ss << "socket:" << pSocket->socketDescriptor() << " ThreadID: " << QThread::currentThreadId() << " msg: " << buf.operator const char *();
	//mdms->mpDemo->AddMsg(ss.str()); // ��ʾ�յ������ݡ�
	//std::string info = ss.str();
	//qDebug() << info.c_str();
	mpts->write(buf); // echo �������ݡ�
}


void DMMPackageSocket::error(QAbstractSocket::SocketError) {

}

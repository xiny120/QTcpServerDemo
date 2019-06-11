#include "DMMServer.h"
#include "DMMPackageSocket.h"
#include "QTcpServerDemo.h"
#include <sstream>


DMMServer::DMMServer(QObject *parent)
	: QObject(parent),
	mqtss(this){
	mpDemo = qobject_cast<QTcpServerDemo *>(parent);
}

DMMServer::~DMMServer(){
	std::lock_guard<std::recursive_mutex> lg(mmutex);
	std::list< DMMPackageSocket*>::iterator iter;
	for (iter = mqtslist.begin(); iter != mqtslist.end(); iter++) {
		delete(*iter);
	}
}

void DMMServer::Start(std::wstring addr, ushort port) {
	connect(&mqtss, &QTcpServer::newConnection, this, &DMMServer::newConnection);
	connect(&mqtss, &QTcpServer::acceptError, this, &DMMServer::acceptError);
	mqtss.listen(QHostAddress::Any, port);
}

void DMMServer::newConnection(){
	QTcpSocket* pSocket = mqtss.nextPendingConnection(); // nextPendingConnection 返回的QTcpSocket* QTcpServer会自动删除的。
	DMMPackageSocket* pSock = new DMMPackageSocket(pSocket,this);
	connect(qobject_cast<QAbstractSocket *>(pSocket), &QAbstractSocket::disconnected, this, &DMMServer::disconnected);
	std::lock_guard<std::recursive_mutex> lg(mmutex);
	mqtslist.push_back(pSock);
	//std::stringstream ss;
	//ss << "online count: " << mqtslist.size();
	//mpDemo->SetLabel(ss.str());
}


void DMMServer::disconnected() {
	QTcpSocket * pSocket = qobject_cast<QTcpSocket *>(sender());
	if (pSocket == nullptr)
		return;
	std::lock_guard<std::recursive_mutex> lg(mmutex);
	//mqtslist.remove_if([=](DMMPackageSocket* i) {return i->Get() == pSocket; });
	std::list< DMMPackageSocket*>::iterator iter = std::find_if(mqtslist.begin(), mqtslist.end(), [=](DMMPackageSocket* i) {return i->Get() == pSocket; });
	DMMPackageSocket* pS = (*iter);
	mqtslist.erase(iter);
	delete pS;
	
	//std::stringstream ss;
	//ss << "online count: " << mqtslist.size();
	//mpDemo->SetLabel(ss.str());
	
}

void DMMServer::acceptError(QAbstractSocket::SocketError socketError){
	qDebug() << "SimpleTcpSocketServerDemo::displayError " << socketError;
}
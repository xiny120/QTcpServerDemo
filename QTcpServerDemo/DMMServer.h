#pragma once

#include <QObject>
#include <QtNetwork/qtcpserver.h>
#include <QtNetwork/qtcpsocket.h>
#include <string>
#include <mutex>
#include <thread>
#include <list>

class DMMPackageSocket;
class QTcpServerDemo;
class DMMServer : public QObject{
	Q_OBJECT
public:
	QTcpServerDemo* mpDemo;
	DMMServer(QObject *parent);
	~DMMServer();
	void Go();
	void Start(std::wstring addr,ushort port);
private:
	QTcpServer mqtss; // �����˿�
	std::recursive_mutex mmutex;
	std::list< DMMPackageSocket*> mqtslist; // socket�ͻ��б�
private slots:
	void newConnection();
	void disconnected();
	void error(QAbstractSocket::SocketError);
	void acceptError(QAbstractSocket::SocketError socketError);

};

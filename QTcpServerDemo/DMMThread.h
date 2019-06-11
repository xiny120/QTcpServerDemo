#pragma once

#include <QThread>
class QTcpServerDemo;

class DMMThread : public QThread
{
	Q_OBJECT

public:
	DMMThread(QObject *parent);
	~DMMThread();

	void run();
	QTcpServerDemo* mpDemo;

};

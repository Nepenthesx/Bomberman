#ifndef TEMPORARYOBJECT_H
#define TEMPORARYOBJECT_H

#include <QObject>
#include <QTimer>

class TemporaryObject : public QObject
{
    Q_OBJECT

private:
    QTimer* timer;
    bool isTimeout;

    void setTimer(int lifetime);

protected:
    bool checkTimeout();

public:
    TemporaryObject(int lifetime);
    virtual void onTimeout() = 0;

private slots:
    void changeTimeoutStatus();
};

#endif // TEMPORARYOBJECT_H

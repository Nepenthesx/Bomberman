#ifndef TEMPORARYOBJECT_H
#define TEMPORARYOBJECT_H

#include <QObject>
#include <QTimer>

class TemporaryObject : public QObject
{
    Q_OBJECT

protected:
    QTimer* timer;
    bool isTimeout = false;

    void setTimer(int lifetime);
public:
    TemporaryObject(int lifetime);
    virtual void onTimeout() = 0;

public slots:
    void changeTimeoutStatus();
};

#endif // TEMPORARYOBJECT_H

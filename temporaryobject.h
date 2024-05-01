#ifndef TEMPORARYOBJECT_H
#define TEMPORARYOBJECT_H

#include <QObject>
#include <QTimer>

class TemporaryObject : public QObject
{
    Q_OBJECT

private:
    QTimer* timer;

    void setTimer(int lifetime);
protected:
    bool isTimeout = false;
public:
    TemporaryObject(int lifetime);
    virtual void onTimeout() = 0;

public slots:
    void changeTimeoutStatus();
};

#endif // TEMPORARYOBJECT_H

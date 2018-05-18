#ifndef LOGFRAME_H
#define LOGFRAME_H

#include <QFrame>

namespace Ui {
class LogFrame;
}

class LogFrame : public QFrame
{
    Q_OBJECT

public:
    explicit LogFrame(QWidget *parent = 0);
    ~LogFrame();

private:
    Ui::LogFrame *ui;
};

#endif // LOGFRAME_H

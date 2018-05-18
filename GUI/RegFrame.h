#ifndef REGFRAME_H
#define REGFRAME_H

#include <QFrame>

namespace Ui {
class RegFrame;
}

class RegFrame : public QFrame
{
    Q_OBJECT

public:
    explicit RegFrame(QWidget *parent = 0);
    ~RegFrame();

private:
    Ui::RegFrame *ui;
};

#endif // REGFRAME_H

#include "RegFrame.h"
#include "ui_RegFrame.h"

RegFrame::RegFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::RegFrame)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

RegFrame::~RegFrame()
{
    delete ui;
}

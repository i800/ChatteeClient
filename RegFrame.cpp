#include "RegFrame.h"
#include "ui_RegFrame.h"

RegFrame::RegFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::RegFrame)
{
    ui->setupUi(this);
}

RegFrame::~RegFrame()
{
    delete ui;
}

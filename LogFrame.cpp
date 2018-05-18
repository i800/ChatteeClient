#include "LogFrame.h"
#include "ui_LogFrame.h"

LogFrame::LogFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::LogFrame)
{
    ui->setupUi(this);
}

LogFrame::~LogFrame()
{
    delete ui;
}

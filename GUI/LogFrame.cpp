#include "LogFrame.h"
#include "ui_LogFrame.h"
#include "Core/Core.h"
#include <QDebug>

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

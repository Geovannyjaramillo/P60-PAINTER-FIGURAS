#include "painter.h"
#include "ui_painter.h"

painter::painter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::painter)
{
    ui->setupUi(this);
}

painter::~painter()
{
    delete ui;
}


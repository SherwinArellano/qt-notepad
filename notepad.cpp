#include "notepad.h"
#include "./ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::newDocument()
{

}

void Notepad::openDocument()
{

}

void Notepad::saveDocument()
{

}

void Notepad::saveAsDocument()
{

}

void Notepad::printDocument()
{

}

void Notepad::exit()
{

}

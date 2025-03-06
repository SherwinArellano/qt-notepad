#include "notepad.h"
#include "./ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, &Notepad::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &Notepad::openDocument);
    connect(ui->actionSave, &QAction::triggered, this, &Notepad::saveDocument);
    connect(ui->actionSave_as, &QAction::triggered, this, &Notepad::saveAsDocument);
    connect(ui->actionPrint, &QAction::triggered, this, &Notepad::printDocument);
    connect(ui->actionExit, &QAction::triggered, this, &Notepad::exit);
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

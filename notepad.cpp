#include "notepad.h"
#include "./ui_notepad.h"

#include <QFileDialog>
#include <QMessageBox>

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
    QString filename = QFileDialog::getOpenFileName(this, "Open a file");
    if (filename.isEmpty()) {
        return;
    }

    QFile file(filename);
    currentFilename = filename;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file" + file.errorString());
        return;
    }

    setWindowTitle(filename);

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
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

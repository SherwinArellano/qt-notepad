#include "notepad.h"
#include "./ui_notepad.h"
#include "aboutdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QFontDialog>
#include <QDebug>
#include <QCloseEvent>

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    setWindowTitle("New document");
    setMinimumSize(280, 160);

    ui->textEdit->setStyleSheet("QTextEdit:focus { outline: none; }"); // remove purple focus line

    connect(ui->actionNew, &QAction::triggered, this, &Notepad::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &Notepad::openDocument);
    connect(ui->actionSave, &QAction::triggered, this, &Notepad::saveDocument);
    connect(ui->actionSave_as, &QAction::triggered, this, &Notepad::saveAsDocument);
    connect(ui->actionPrint, &QAction::triggered, this, &Notepad::printDocument);
    connect(ui->actionSelect_font, &QAction::triggered, this, &Notepad::selectFont);
    connect(ui->actionAbout, &QAction::triggered, this, &Notepad::showAboutDialog);
    connect(ui->actionExit, &QAction::triggered, this, &Notepad::exit);

    loadWindowSize();
    loadUserPreferences();
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::newDocument()
{
    currentFilename.clear();
    ui->textEdit->setText(QString());
    setWindowTitle("New document");
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
    QString filenameToSave;

    if (currentFilename.isEmpty()) {
        // Handle new document; it's a new document if there's no currentFilename
        filenameToSave = QFileDialog::getSaveFileName(this, "Save");
        if (filenameToSave.isEmpty()) {
            return;
        }

        currentFilename = filenameToSave;
    } else {
        // Handle already opened document
        filenameToSave = currentFilename;
    }

    QFile file(filenameToSave);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setWindowTitle(filenameToSave);

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    file.close();
}

void Notepad::saveAsDocument()
{
    QString filenameToSave = QFileDialog::getSaveFileName(this, "Save as");
    if (filenameToSave.isEmpty()) {
        return;
    }

    QFile file(filenameToSave);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    currentFilename = filenameToSave;

    setWindowTitle(filenameToSave);

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    file.close();
}

void Notepad::printDocument()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)
    QPrinter printDev;
#if QT_CONFIG(printdialog)
    QPrintDialog dialog(&printDev, this);

    if (dialog.exec() == QDialog::Rejected) {
        return;
    }
#endif // QT_CONFIG(printdialog)
    ui->textEdit->print(&printDev);
#else
    QMessageBox::information(this, "Printing Not Supported", "Printing is not supported in this build.");
#endif // QT_CONFIG(printer)
}

void Notepad::selectFont()
{
    bool hasFontSelected;
    QFont font = QFontDialog::getFont(&hasFontSelected, ui->textEdit->font(), this);
    if (hasFontSelected) {
        ui->textEdit->setFont(font);
        settings.setValue("user/font", font.toString());
    }
}

void Notepad::exit()
{
    QCoreApplication::quit();
}

void Notepad::loadUserPreferences()
{
    QString fontString = settings.value("user/font", "Arial").toString();
    QFont font;
    font.fromString(fontString);
    ui->textEdit->setFont(font);
}

void Notepad::saveWindowSize()
{
    settings.setValue("window/width", width());
    settings.setValue("window/height", height());
}

void Notepad::loadWindowSize()
{
    int width = settings.value("window/width", 800).toInt();
    int height = settings.value("window/height", 600).toInt();
    resize(width, height);
}

void Notepad::closeEvent(QCloseEvent *event) {
    saveWindowSize();
    QMainWindow::closeEvent(event);
}

void Notepad::showAboutDialog()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}


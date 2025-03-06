#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    setWindowTitle("About Notepad");

    connect(ui->close_button, &QPushButton::clicked, this, &AboutDialog::close);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

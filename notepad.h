#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
    // The Notepad class is forward-declared to avoid circular dependencies.
    class Notepad;
}
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void newDocument();

    void openDocument();

    void saveDocument();

    void saveAsDocument();

    void printDocument();

    void selectFont();

    void exit();

private:
    Ui::Notepad *ui;
    QString currentFilename;
    QSettings settings;

    void loadUserPreferences();
};
#endif // NOTEPAD_H

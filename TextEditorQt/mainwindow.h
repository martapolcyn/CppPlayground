#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNowy_triggered();

    void on_actionOtworz_triggered();

    void on_actionZapisz_jako_triggered();

    void on_actionDrukuj_triggered();

    void on_actionZamknij_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWklej_triggered();

    void on_actionWytnij_triggered();

    void on_actionCofnij_triggered();

    void on_actionWykonaj_ponownie_triggered();

    void on_textEdit_textChanged();

    int countSeparators(QString text, char separator);

    void on_cbBold_toggled(bool checked);

    void on_cbUnderline_toggled(bool checked);

    void on_cbItalic_toggled(bool checked);

    void on_cbStrikethrough_toggled(bool checked);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNowy_triggered()
{
    currentFile.clear();
    setWindowTitle("Niezapisany plik");
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionOtworz_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Otworz plik");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "ERROR", "Nie mozna otworzyc pliku.");
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();
}


void MainWindow::on_actionZapisz_jako_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz jako ");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "ERROR", "Nie mozna zapisac pliku.");
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_actionDrukuj_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Drukarka");
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "ERROR", "Nie mozna polaczyc sie z drukarka.");
        return;
    }
    ui->textEdit->print(&printer);
}


void MainWindow::on_actionZamknij_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionKopiuj_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionWklej_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionWytnij_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCofnij_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionWykonaj_ponownie_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();

    int c = text.length();
    ui->leCharacters->setText(QString::number(c));

    int w = MainWindow::countSeparators(text, ' ');
    ui->leWords->setText(QString::number(w));

    int s = 0;
    for (int i=0; i<c; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' ) {
            s++;
        }
    }
    ui->leSentences->setText(QString::number(s));

    int p = MainWindow::countSeparators(text, '\n');
    ui->leParagraphs->setText(QString::number(p));
}


int MainWindow::countSeparators(QString text, char separator) {
    int counter;
    if (text.length() == 0) {
        counter = 0;
    } else {
        counter = 1;
    }
    for (int i=0; i<text.length(); i++) {
        if (text[i] == separator || text[i] == '\n') {
            counter++;
        }
    }
    return counter;
}


void MainWindow::on_cbBold_toggled(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);

}


void MainWindow::on_cbUnderline_toggled(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}


void MainWindow::on_cbItalic_toggled(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}


void MainWindow::on_cbStrikethrough_toggled(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setStrikeOut(checked);
    ui->textEdit->setFont(font);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QFont font = ui->textEdit->font();
    font.setPointSize(value);
    ui->textEdit->setFont(font);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cryptopp/integer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_btnBase64Encode_clicked()
{
  auto input = ui->textInput->toPlainText().toUtf8();
  auto output = input.toBase64();
  if(hexOutput) {
    output = output.toHex();
  }
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnBase64Decode_clicked()
{
  auto input = ui->textInput->toPlainText().toUtf8();
  auto output = QByteArray::fromBase64(input);
  if(hexOutput) {
    output = output.toHex();
  }
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_checkBoxHexOutput_stateChanged(int arg1)
{
  if(arg1 == Qt::Checked) {
    hexOutput = true;
  } else {
    hexOutput = false;
  }
}

void MainWindow::on_btnIntToHex_clicked()
{
    auto input = ui->textInput->toPlainText().toUtf8();
    using namespace CryptoPP;
    Integer i(input.data());
    auto o = IntToString<Integer>(i,16);
    auto output = QString::fromStdString(o);
    ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnIntToDec_clicked()
{
  auto input = ui->textInput->toPlainText().toUtf8();
  using namespace CryptoPP;
  Integer i(input.data());
  auto o = IntToString<Integer>(i,10);
  auto output = QString::fromStdString(o);
  ui->textOutput->setPlainText(output);
}

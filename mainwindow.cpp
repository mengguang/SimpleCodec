#include "mainwindow.h"
#include "cryptopp/integer.h"

#include "cryptopp/sha.h"
#include "cryptopp/sha3.h"
#include "cryptopp/keccak.h"
#include "ui_mainwindow.h"

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "cryptopp/md5.h"

#include <osrng.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_btnBase64Encode_clicked() {
  auto input = ui->textInput->toPlainText().toUtf8();
  auto output = input.toBase64();
  if (hexOutput) {
    output = output.toHex();
  }
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnBase64Decode_clicked() {
  auto input = ui->textInput->toPlainText().toUtf8();
  auto output = QByteArray::fromBase64(input);
  if (hexOutput) {
    output = output.toHex();
  }
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_checkBoxHexOutput_stateChanged(int arg1) {
  if (arg1 == Qt::Checked) {
    hexOutput = true;
  } else {
    hexOutput = false;
  }
}

void MainWindow::on_btnIntToHex_clicked() {
  auto input = ui->textInput->toPlainText().toUtf8();
  using namespace CryptoPP;
  Integer i(input.data());
  auto o = IntToString<Integer>(i, 16);
  auto output = QString::fromStdString(o);
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnIntToDec_clicked() {
  auto input = ui->textInput->toPlainText().toUtf8();
  using namespace CryptoPP;
  Integer i(input.data());
  auto o = IntToString<Integer>(i, 10);
  auto output = QString::fromStdString(o);
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnHashSHA256_clicked() {
  auto input = ui->textInput->toPlainText().toUtf8();
  using namespace CryptoPP;
  SHA256 hash;
  hash.Update((byte *)input.data(), input.size());
  QByteArray digest(hash.DIGESTSIZE, 0);
  hash.Final((byte *)digest.data());
  auto output = QString(digest.toHex());
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnHashSHA1_clicked()
{
  auto input = ui->textInput->toPlainText().toUtf8();
  using namespace CryptoPP;
  SHA1 hash;
  hash.Update((byte *)input.data(), input.size());
  QByteArray digest(hash.DIGESTSIZE, 0);
  hash.Final((byte *)digest.data());
  auto output = QString(digest.toHex());
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnHashMD5_clicked()
{
  auto input = ui->textInput->toPlainText().toUtf8();
  using namespace CryptoPP;
  Weak::MD5 hash;
  hash.Update((byte *)input.data(), input.size());
  QByteArray digest(hash.DIGESTSIZE, 0);
  hash.Final((byte *)digest.data());
  auto output = QString(digest.toHex());
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnHashKeccak256_clicked()
{
  auto input = ui->textInput->toPlainText().toUtf8();
  using namespace CryptoPP;
  Keccak_256 hash;
  hash.Update((byte *)input.data(), input.size());
  QByteArray digest(hash.DIGESTSIZE, 0);
  hash.Final((byte *)digest.data());
  auto output = QString(digest.toHex());
  ui->textOutput->setPlainText(output);
}

void MainWindow::on_btnRandom_clicked()
{
  using namespace CryptoPP;
  AutoSeededRandomPool prng;
  QByteArray data(256,0);
  prng.GenerateBlock((byte *)data.data(), data.size());
  ui->textOutput->setPlainText(data.toHex());
}

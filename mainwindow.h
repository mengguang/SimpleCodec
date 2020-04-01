#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  QByteArray calcHash(const QString algo, const QByteArray &input);
private slots:
  void on_btnBase64Encode_clicked();

  void on_btnBase64Decode_clicked();

  void on_checkBoxHexOutput_stateChanged(int arg1);

  void on_btnIntToHex_clicked();

  void on_btnIntToDec_clicked();

  void on_btnHashSHA256_clicked();

  void on_btnHashSHA1_clicked();

  void on_btnHashMD5_clicked();

  void on_btnHashKeccak256_clicked();

  void on_btnRandom_clicked();

  void on_btnUUID_clicked();

 private:
  Ui::MainWindow *ui;
  bool hexOutput;
};
#endif // MAINWINDOW_H

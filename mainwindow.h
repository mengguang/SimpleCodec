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

 private slots:
  void on_btnBase64Encode_clicked();

  void on_btnBase64Decode_clicked();

  void on_checkBoxHexOutput_stateChanged(int arg1);

  void on_btnIntToHex_clicked();

  void on_btnIntToDec_clicked();

 private:
  Ui::MainWindow *ui;
  bool hexOutput;
};
#endif // MAINWINDOW_H

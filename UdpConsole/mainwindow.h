#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QUdpSocket* udp;
    quint16 port;
    QHostAddress address;
    bool state;

    void setStatus();

private slots:
    void readDatagram();
    void on_portBox_valueChanged(int arg1);
    void on_ipLine_editingFinished();
    void on_connectButton_clicked();
};
#endif // MAINWINDOW_H

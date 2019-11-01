#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegExp>
#include <QRegExpValidator>
#include <QNetworkDatagram>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegExp ipRegex("^" + ipRange
                    + "\\." + ipRange
                    + "\\." + ipRange
                    + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    ui->ipLine->setValidator(ipValidator);

    ui->ipLine->setText(QHostAddress(QHostAddress::Broadcast).toString());

    udp = new QUdpSocket(this);
    connect(udp, &QUdpSocket::readyRead, this, &MainWindow::readDatagram);

    port = static_cast<quint16>(ui->portBox->value());
    address.setAddress(ui->ipLine->text());
    state = false;

    setStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readDatagram() {
    while(udp->hasPendingDatagrams()) {
        QByteArray msg;
        msg.resize(udp->pendingDatagramSize());
        msg = udp->receiveDatagram().data();
        ui->consoleText->appendHtml(QString("<p>%1</p>").arg(QString(msg)));
    }
}

void MainWindow::setStatus() {
    if(state) {
        ui->connectButton->setText("Disconnect");
        ui->statusLabel->setText(QString("Connected on %1:%2").arg(address.toString()).arg(port));
    } else {
        ui->connectButton->setText("Connect");
        ui->statusLabel->setText(QString("Disconnected"));
    }
}

void MainWindow::on_portBox_valueChanged(int arg1)
{
    port = static_cast<quint16>(arg1);
}

void MainWindow::on_ipLine_editingFinished()
{
    address.setAddress(ui->ipLine->text());
}

void MainWindow::on_connectButton_clicked()
{
    if(state) {
        state = false;
        udp->close();
    }
    else {
        if(address.isEqual(QHostAddress(QHostAddress::Broadcast))) {
            udp->bind(port, QAbstractSocket::ShareAddress);
        } else {
            udp->bind(address, port);
        }
        state = true;
    }
    setStatus();
}

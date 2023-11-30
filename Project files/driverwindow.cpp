//
// Created by Rares on 27.06.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DriverWindow.h" resolved

#include "driverwindow.h"
#include "ui_DriverWindow.h"
#include "sstream"
#include "QColor"
using namespace std;

DriverWindow::DriverWindow(Services& _services, Driver& _driverOfThisWindow, QWidget *parent) :  services(_services),
        driverOfThisWindow(_driverOfThisWindow),
        QWidget(parent), ui(new Ui::DriverWindow) {
    ui->setupUi(this);
    updateReportList();
    ui->scoreLabel->setText(QString::fromStdString( to_string(driverOfThisWindow.getScore())));
    ui->locationLabel->setText(QString::fromStdString( to_string(driverOfThisWindow.getLocation().first) + ":" +
                                                       to_string(driverOfThisWindow.getLocation().second)));
    connectSignals();
}

DriverWindow::~DriverWindow() {
    delete ui;
}

void DriverWindow::updateReportList()
{
    ui->reportsListWidget->clear();
    int i = 0;
    for (auto report: services.getReportsOfInterest(driverOfThisWindow.getLocation().first,
                                                    driverOfThisWindow.getLocation().second))
    {
        ui->reportsListWidget->addItem(QString::fromStdString(report.toString()));
        if (report.isValid())
        {
            //ui->reportsListWidget->item(i)->setForeground(QColor::green); //bold it later
        }
        i++;
    }
}

void DriverWindow::updateMessages()
{
    ui->messagesListWidget->clear();
    for (auto message: services.getAllMessages())
    {
        ui->messagesListWidget->addItem(QString::fromStdString(message));
    }
}

void DriverWindow::update() {
    QWidget::update();
    updateReportList();
    updateMessages();
}

void DriverWindow::sendMessage()
{
    string message = ui->messageLineEdit->text().toStdString();
    services.sendMessage(driverOfThisWindow.getName(), message);
    update();
}

void DriverWindow::connectSignals() {
    connect(ui->sendMessageButton, &QPushButton::clicked, this, [&]()
    {
        sendMessage();
    });
    connect(ui->reportButton, &QPushButton::clicked, this, [&]()
    {
        addReport();
    });
    connect(ui->validateButton, &QPushButton::clicked, this, [&]()
    {
        validateReport();
    });
}


void DriverWindow::addReport()
{
    services.addReport(driverOfThisWindow, ui->descriptionLineEdit->text().toStdString(),
                       ui->xCoordLineEdit->text().toInt(), ui->yCoordLineEdit->text().toInt());
    update();
}

void DriverWindow::validateReport()
{
    std::string text = ui->reportsListWidget->currentItem()->text().toStdString();
    stringstream stream{text};
    string description;
    getline(stream, description, ';');
    services.validateReport(description, driverOfThisWindow.getName());
    //services.validateReport()
    //update();
}

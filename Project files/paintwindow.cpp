//
// Created by Rares on 27.06.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PaintWindow.h" resolved

#include "paintwindow.h"
#include "ui_PaintWindow.h"
#include "QPaintEvent"
#include "QPainter"

PaintWindow::PaintWindow(Services& _services, QWidget *parent) : services(_services),
        QWidget(parent), ui(new Ui::PaintWindow) {
    ui->setupUi(this);
}

PaintWindow::~PaintWindow() {
    delete ui;
    for (auto label: listOfLabels)
    {
        delete label;
    }
}

void PaintWindow::update() {
    QWidget::update();
    repaint();
}

void PaintWindow::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    int i = 0;
//    for (auto label : listOfLabels){
//        label->hide();
//        //listOfLabels.erase(label);
//        std::swap(listOfLabels[i], listOfLabels[listOfLabels.size()]);
//        listOfLabels.pop_back();
//        delete label;
//    i++;}
    i = 0;
    for (auto report: services.getAllReports())
    {
        painter.drawEllipse(report.getLocation().first*10, report.getLocation().second*10, 100, 100);
        //QLabel* label;
        //if (i > listOfLabels.size())
            //label = new QLabel(this);
        //else label = listOfLabels[i];
        //label->setText(QString::fromStdString(report.getDescription() + "\n" +
        //std::to_string(report.getLocation().first) + ":" + std::to_string(report.getLocation().second)  ));
        //label->setAlignment(report.getLocation().first*10, report.getLocation().second*10);
        //ui->verticalLayout->addWidget(label);
        //label->show();
        //listOfLabels.push_back(label);
        i++;
    }
}

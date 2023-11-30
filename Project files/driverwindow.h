//
// Created by Rares on 27.06.2023.
//

#ifndef OOP_FINAL_EXAM_DRIVERWINDOW_H
#define OOP_FINAL_EXAM_DRIVERWINDOW_H

#include <QWidget>
#include "observer design pattern.h"
#include "Services.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DriverWindow; }
QT_END_NAMESPACE

class DriverWindow : public QWidget, public Observer { //!!!
Q_OBJECT

public:
    DriverWindow(Services& _services, Driver& _driverOfThisWindow, QWidget *parent = nullptr);

    ~DriverWindow() override;
    void update() override;

private:
    Ui::DriverWindow *ui;
    Services& services;
    Driver& driverOfThisWindow;
    void connectSignals();
    void updateReportList();

    void updateMessages();

    void sendMessage();

    void addReport();

    void validateReport();
};


#endif //OOP_FINAL_EXAM_DRIVERWINDOW_H

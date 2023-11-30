//
// Created by Rares on 27.06.2023.
//

#ifndef OOP_FINAL_EXAM_PAINTWINDOW_H
#define OOP_FINAL_EXAM_PAINTWINDOW_H

#include <QWidget>
#include "Services.h"
#include "QLabel"
QT_BEGIN_NAMESPACE
namespace Ui { class PaintWindow; }
QT_END_NAMESPACE

class PaintWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit PaintWindow(Services& _services, QWidget *parent = nullptr);

    ~PaintWindow() override;

private:
    Ui::PaintWindow *ui;
    Services& services;
    std::vector<QLabel*> listOfLabels;
    void update() override;
    void paintEvent(QPaintEvent *event) override;
};


#endif //OOP_FINAL_EXAM_PAINTWINDOW_H

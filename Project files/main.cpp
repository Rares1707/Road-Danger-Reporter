#include <QApplication>
#include "driverwindow.h"
#include "vector"
#include "paintwindow.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repository repository{"C:\\Users\\Rares\\Desktop\\Semester 2\\OOP\\OOP-Diverse\\OOP Final Exam\\drivers.txt",
                          "C:\\Users\\Rares\\Desktop\\Semester 2\\OOP\\OOP-Diverse\\OOP Final Exam\\reporters.txt"};
    Services services{repository};
    vector<DriverWindow*> listOfWindows;
    for (auto driver: repository.getAllDrivers())
    {
        DriverWindow* window = new DriverWindow{services, driver};
        listOfWindows.push_back(window);
        window->show();
        window->setWindowTitle(QString::fromStdString(driver.getName()));
        services.add(window);

    }
    PaintWindow paintWindow{services};
    paintWindow.show();
//    for (auto* window: listOfWindows)
//    {
//        delete window;
//    }
    return QApplication::exec();
}

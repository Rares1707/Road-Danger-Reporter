//
// Created by Rares on 27.06.2023.
//

#include "Services.h"
#include "cmath"
std::vector<Driver> &Services::getAllDrivers() {
    return repository.getAllDrivers();
}

std::vector<Report> &Services::getAllReports() {
    return repository.getAllReports();
}

std::vector<Report> Services::getReportsOfInterest(int x, int y) {
    //return repository.getAllReports();
    std::vector<Report> data;
    for (auto report: repository.getAllReports())
    {
        int xReport = report.getLocation().first;
        int yReport = report.getLocation().second;
        if (10> sqrt( pow(x-xReport, 2) + pow(y - yReport, 2) ))
        {
            data.push_back(report);
        }
    }
    return data;
}

Services::Services(Repository &repository) : repository(repository) {}

std::vector<std::string> Services::getAllMessages() {
    return messages;
}

void Services::sendMessage(std::string driverName, std::string message) {
    messages.push_back(driverName + ": " + message);
    notify();
}

void Services::addReport(Driver reporter, std::string description, int xCoord, int yCoord) {
    if (description.empty())
        return;
    int xReport = reporter.getLocation().first;
    int yReport = reporter.getLocation().second;
    if (20 < sqrt( pow(xCoord-xReport, 2) + pow(yCoord - yReport, 2) ))
    {
        return;
    }
    repository.addReport(Report(reporter.getName(), description, std::make_pair(xCoord, yCoord), 0));
    notify();
}

void Services::validateReport(std::string reportDescription, std::string validatorName)
{
    for (auto& report: getAllReports())
    {
        if (report.getDescription() == reportDescription)
        {
            report.validate(validatorName);
        }
    }
    repository.saveReportsToFile();
    notify();
}

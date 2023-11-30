//
// Created by Rares on 27.06.2023.
//

#include "Repository.h"
#include "fstream"


using namespace std;
std::vector<Driver> &Repository::getAllDrivers() {
    return listOfDrivers;
}

std::vector<Report> &Repository::getAllReports() {
    return listOfReports;
}

void Repository::saveReportsToFile()
{
    ofstream fout(reportsFile);
    for (auto report: listOfReports)
    {
        fout << report.toString();
    }
    fout.close();
}

void Repository::addReport(Report report)
{
    listOfReports.push_back(report);
    saveReportsToFile();
}

Repository::Repository(const std::string &driversFile, const std::string &reportsFile) : driversFile(driversFile),
                                                                                         reportsFile(reportsFile) {
    loadDriversFromFile();
    loadReportsFromFile();
}

void Repository::loadDriversFromFile() {
    std::ifstream fin(driversFile);
    std::string name;
    std::pair<double, double> location;
    int xCoordinate, yCoordinate;
    string xCoordinateString, yCoordinateString, scoreString;
    int score;
    while (std::getline(fin, name, ';'))
    {
        getline(fin, xCoordinateString, ';');
        getline(fin, yCoordinateString, ';');

        xCoordinate= stod(xCoordinateString);
        yCoordinate= stod(yCoordinateString);

        getline(fin, scoreString, ';');
        score= stod(scoreString);
        listOfDrivers.emplace_back(name, make_pair(xCoordinate, yCoordinate), score);
    }
    fin.close();
}

void Repository::loadReportsFromFile() {
    std::ifstream fin(reportsFile);
    std::string description, reporterName;
    std::pair<double, double> location;
    bool validationStatus;
    int xCoordinate, yCoordinate;
    string xCoordinateString, yCoordinateString, statusString;
    while (std::getline(fin, description, ';'))
    {
        getline(fin, reporterName, ';');
        getline(fin, xCoordinateString, ';');
        getline(fin, yCoordinateString, ';');

        xCoordinate= stod(xCoordinateString);
        yCoordinate= stod(yCoordinateString);

        getline(fin, statusString, ';');
        validationStatus= stod(statusString);
        listOfReports.emplace_back(description, reporterName, make_pair(xCoordinate, yCoordinate), validationStatus);
    }
    fin.close();
}

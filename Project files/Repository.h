//
// Created by Rares on 27.06.2023.
//

#ifndef OOP_FINAL_EXAM_REPOSITORY_H
#define OOP_FINAL_EXAM_REPOSITORY_H
#include "Driver.h"
#include "Report.h"
#include "vector"

class Repository {
private:
    std::vector<Driver> listOfDrivers;
    std::vector<Report> listOfReports;
    std::string driversFile;
    std::string reportsFile;
    void loadDriversFromFile();
    void loadReportsFromFile();

public:
    Repository(const std::string &driversFile, const std::string &reportsFile);
    std::vector<Driver>& getAllDrivers();
    std::vector<Report>& getAllReports();

    void addReport(Report report);

    void saveReportsToFile();
};


#endif //OOP_FINAL_EXAM_REPOSITORY_H

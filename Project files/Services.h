//
// Created by Rares on 27.06.2023.
//

#ifndef OOP_FINAL_EXAM_SERVICES_H
#define OOP_FINAL_EXAM_SERVICES_H
#include "Repository.h"
#include "observer design pattern.h"

class Services: public Subject{
private:
    Repository& repository;
    std::vector<std::string> messages;
public:
    explicit Services(Repository &repository);

public:
    std::vector<Driver>& getAllDrivers();
    std::vector<Report>& getAllReports();
    std::vector<std::string> getAllMessages();
    void sendMessage(std::string driverName, std::string message); //fix name later
    std::vector<Report> getReportsOfInterest(int x, int y);
    void addReport(Driver reporter, std::string description, int xCoord, int yCoord);

    void validateReport(std::string reportDescription, std::string validatorName);
};


#endif //OOP_FINAL_EXAM_SERVICES_H

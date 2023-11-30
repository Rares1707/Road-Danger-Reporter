//
// Created by Rares on 27.06.2023.
//

#ifndef OOP_FINAL_EXAM_REPORT_H
#define OOP_FINAL_EXAM_REPORT_H
#include "string"


class Report {
    std::string description, reporterName;
    std::pair<double, double> location;
    bool validationStatus;
    int numberOfValidations;
public:
    const std::string &getDescription() const;

    const std::string &getReporterName() const;

    const std::pair<double, double> &getLocation() const;

    bool isValid() const;
    std::string toString() const;
    void validate(std::string nameOfValidator);

public:
    Report(const std::string &description, const std::string &reporterName, const std::pair<double, double> &location,
           bool validationStatus);
};


#endif //OOP_FINAL_EXAM_REPORT_H

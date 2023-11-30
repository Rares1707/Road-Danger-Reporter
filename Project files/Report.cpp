//
// Created by Rares on 27.06.2023.
//

#include "Report.h"

Report::Report(const std::string &description, const std::string &reporterName,
               const std::pair<double, double> &location, bool validationStatus) : description(description),
                                                                                   reporterName(reporterName),
                                                                                   location(location),
                                                                                   validationStatus(validationStatus) {
    numberOfValidations=0;
}

const std::string &Report::getDescription() const {
    return description;
}

const std::string &Report::getReporterName() const {
    return reporterName;
}

const std::pair<double, double> &Report::getLocation() const {
    return location;
}

bool Report::isValid() const {
    return validationStatus;
}

std::string Report::toString() const {
    return description + ";" + reporterName + ";" + std::to_string(location.first) +  ";" +
            std::to_string(location.second) + ";" + std::to_string(validationStatus) + ";";
}

void Report::validate(std::string nameOfValidator) {
    if (nameOfValidator != this->reporterName)
        numberOfValidations++;
    if (numberOfValidations>=2)
        validationStatus = true;

}

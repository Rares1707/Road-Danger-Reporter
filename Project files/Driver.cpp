//
// Created by Rares on 27.06.2023.
//

#include "Driver.h"

Driver::Driver(const std::string &name, const std::pair<double, double> &location, int score) : name(name),
                                                                                                location(location),
                                                                                                score(score) {}

const std::string &Driver::getName() const {
    return name;
}

const std::pair<double, double> &Driver::getLocation() const {
    return location;
}

int Driver::getScore() const {
    return score;
}

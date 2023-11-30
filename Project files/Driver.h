//
// Created by Rares on 27.06.2023.
//

#ifndef OOP_FINAL_EXAM_DRIVER_H
#define OOP_FINAL_EXAM_DRIVER_H
#include "string"

class Driver {
    std::string name;
    std::pair<double, double> location;
    int score;
public:
    const std::string &getName() const;

    const std::pair<double, double> &getLocation() const;

    int getScore() const;

public:
    Driver(const std::string &name, const std::pair<double, double> &location, int score);
};


#endif //OOP_FINAL_EXAM_DRIVER_H

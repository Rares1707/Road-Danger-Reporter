//
// Created by Rares on 27.06.2023.
//

#ifndef OOP_FINAL_EXAM_OBSERVER_DESIGN_PATTERN_H
#define OOP_FINAL_EXAM_OBSERVER_DESIGN_PATTERN_H

#include "vector"

class Observer{
public:
    virtual ~Observer()=default;
    virtual void update()=0;
};

class Subject{
private:
    std::vector<Observer*> observerList;

public:
    virtual ~Subject()=default;
    virtual void notify()
    {
        for (auto observer: observerList)
            observer->update();
    }
    void add(Observer* observer)
    {
        for (auto obs: observerList)
        {
            if (obs == observer)
                return;
        }
        observerList.push_back(observer);
    }
    void remove(Observer* observer)
    {
        int i=0;
        for (auto obs: observerList)
        {
            if (obs == observer)
            {
                std::swap(observerList[i], observerList[observerList.size()]);
                observerList.pop_back();
            }
            i++;
        }

    }
};

#endif //OOP_FINAL_EXAM_OBSERVER_DESIGN_PATTERN_H

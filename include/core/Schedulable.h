#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H

class Schedulable {
public:
    virtual ~Schedulable() {}
    virtual void schedule() = 0;
    virtual void cancelSchedule() = 0;
};

#endif
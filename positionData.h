//
// Created by n2one on 10.02.2020.
//

#ifndef LSYSTEM2DINTERPRETER_POSITIONDATA_H
#define LSYSTEM2DINTERPRETER_POSITIONDATA_H


class positionData {
public:
    float x,y,q;

    positionData(float x, float y, float q) : x(x), y(y), q(q) {}

    positionData() {}
};


#endif //LSYSTEM2DINTERPRETER_POSITIONDATA_H

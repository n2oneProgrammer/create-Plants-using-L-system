//
// Created by n2one on 09.02.2020.
//

#ifndef LSYSTEM2DINTERPRETER_TURTLE_H
#define LSYSTEM2DINTERPRETER_TURTLE_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <stack>
#include "positionData.h"

class turtle {
    positionData pos;
    std::stack < positionData > saveposition;
    bool isPaint=true;
public:
    turtle(float x, float y);
    void walk(sf::RenderWindow *window, float dis);
    void turn(float q);
    void paint(bool p);
    void savePosition();
    void teleport();
};


#endif //LSYSTEM2DINTERPRETER_TURTLE_H

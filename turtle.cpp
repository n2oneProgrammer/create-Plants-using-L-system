//
// Created by n2one on 09.02.2020.
//

#include <cmath>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "turtle.h"

turtle::turtle(float x, float y) {
    pos.x = x;
    pos.y = y;
    pos.q = -90;
}

void turtle::turn(float q) {
    pos.q += q;
}


void turtle::paint(bool p) {
    isPaint = p;
}

void turtle::walk(sf::RenderWindow *window, float dis) {
    float x2 = pos.x + dis * cos(pos.q * M_PI/180);
    float y2 = pos.y + dis * sin(pos.q *M_PI/180);
    if (isPaint) {


        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(pos.x, pos.y)),
                        sf::Vertex(sf::Vector2f(x2, y2))
                };

        window->draw(line, 2, sf::Lines);
    }
    pos.x = x2;
    pos.y = y2;
}

void turtle::savePosition() {
   saveposition.push(pos);
}

void turtle::teleport() {
    pos = saveposition.top();
    saveposition.pop();
}

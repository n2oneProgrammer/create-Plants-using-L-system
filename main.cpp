#include <SFML/Graphics.hpp>
#include <iostream>
#include "turtle.h"

#define distanceWalk 2
#define angle 25.7


std::string preprocessingCommands(std::string commands, std::string **gramma, int count) {
    std::string result;
    for (char cmd:commands) {
        bool finded = false;
        for (int i = 0; i < count; i++) {
            if (cmd == (*gramma)[i][0]) {
                result += gramma[i][1];
                finded = true;
                break;
            }
        }
        if (!finded) {
            result += cmd;
        }
    }
    std::cout << result<<"\n";
    return result;
}

void runCommands(turtle *turtle, sf::RenderWindow *windows, char cmd) {
    switch (cmd) {
        case 'F':
            turtle->walk(windows, distanceWalk);
            break;

        case '+':
            turtle->turn(-angle);
            break;
        case '-':
            turtle->turn(angle);
            break;
        case '[':
            turtle->savePosition();
            break;
        case ']':
            turtle->teleport();
            break;
        default:
            std::cout << "ERROR";
    }

}

void createimg(turtle *turtle, sf::RenderWindow *windows, const std::string& commands) {
    for (char cmd:commands) {
        runCommands(turtle, windows, cmd);
    }
}


int main() {
    sf::RenderWindow window(sf::VideoMode(500, 700), "SFML works!");

    auto **gramma = new std::string *[2];

    for (int i = 0; i < 2; i++) {
        gramma[i] = new std::string[2];
    }
    gramma[0][0] = "X";
    gramma[0][1] = "F[+X][-X]FX";
    gramma[1][0] = "F";
    gramma[1][1] = "FF";
    std::string commands = "X";


//    for (int i = 0; i < 1; i++) {
//        gramma[i] = new std::string[2];
//        gramma[i][0] = "F";
//        gramma[i][1] = "F-F+F+FF-F-F+F";
//    }
//    std::string commands = "F-F-F-F";
    for (int i = 0; i < 7; i++) {
        commands = preprocessingCommands(commands, gramma, 2);
    }
    std::cout<<commands<<"\n";

    bool generate= false;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(!generate) {
            window.clear();
            turtle turtle(250, 700);
            createimg(&turtle, &window, commands);
            window.display();
            generate = true;
        }
    }

    return 0;
}
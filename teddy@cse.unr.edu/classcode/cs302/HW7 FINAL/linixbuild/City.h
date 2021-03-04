// City.h : Models a City
//

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

class City {
    private:
        int x;
        int y;
    public:
        City();
        City(int x, int y);
        
        int getX();
        int getY();
        double distanceTo(City city);

        std::string getAllele();

};

//Constructs a randomly placed city
City::City() {
    srand(time(NULL));
    this->x = rand() % 200;
    this->y = rand() % 200;
}

//Constructs a city at chosen x and y location
City::City(int x, int y) : x{ x }, y{ y } {
}

//Gets city's x coordinate
int City::getX() {
    return this->x;
}

//Gets city's y coordinate
int City::getY() {
    return this->y;
}

//Gets distance to given city
double City::distanceTo(City city) {
    int xDistance = std::abs(getX() - city.getX());
    int yDistance = std::abs(getY() - city.getY());
    double distance = sqrt((xDistance * xDistance) + (yDistance * yDistance));

    return distance;
}

std::string City::getAllele() {

    if (this == nullptr) {
        std::cout << "WHYYYYYYYYYYYYYYY" << std::endl;
    }
    
    std::string s;
    s += x;
    s += '&';
    s += y;
    return s;
}

#endif //end City class
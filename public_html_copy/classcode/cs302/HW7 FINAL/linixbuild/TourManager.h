// TourManager.h : Holds the cities of a tour
//

#ifndef TOURMANAGER_H
#define TOURMANAGER_H

#include <string>
#include <vector>
#include "City.h"


class TourManager {
    private:
        static TourManager* inst;

        std::vector<City> destinationCities;
        TourManager();

    public:
        static TourManager* getInst();

        void addCity(City city);
        City* getCity(int index);
        int numberOfCities();
};

TourManager::TourManager() {


}

 TourManager* TourManager::inst = 0;

 TourManager* TourManager::getInst() {
    if (inst == 0) {
        inst = new TourManager();
    }

    return inst;
}


//Adds a destination city
void TourManager::addCity(City city) {

    destinationCities.push_back(city);
}

//Get a city
City* TourManager::getCity(int index) {
    using namespace std;

    City* val = &destinationCities.at(index);
    if (val == nullptr) {
        cout << "error in getCity() tour manager" << endl;
    }
    return val;
}

//Get number of destination cities
int TourManager::numberOfCities() {
    
    return destinationCities.size();
}

#endif
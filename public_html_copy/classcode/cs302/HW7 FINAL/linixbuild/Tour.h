#ifndef __TOUR_H__
#define __TOUR_H__

#include <iostream>
#include <algorithm>                                                                                                    
#include <vector>                                                                                                       
#include <iterator>  
#include "City.h"
#include "TourManager.h"

class Tour {

private:
	City* cities; // holds all cities in a tour
	float fitness; // measure of tour efficiecy
	float distance; // key metric of fitness

public:
	Tour();
	Tour(City* cities);
	void setCity(int pos, City& city);
	void constuctRandomChromosone();
	City* getCity(int pos);
	float getFitness();
	float getDistance();
	bool hasCity(City&);
	std::string getChromosomeAsCSV();
};

Tour::Tour() {
	cities = new City[TourManager::getInst()->numberOfCities()];
}

void Tour::setCity(int pos, City& city) {
	cities[pos] = city;
	fitness = 0;
	distance = 0;
}

City* Tour::getCity(int pos) {
	using namespace std;
	City* val = &cities[pos];
	if (val == nullptr)
		cout << "get city is null in tour" << endl;

	return val;
}


void Tour::constuctRandomChromosone() {
	using namespace std;
	int size = TourManager::getInst()->numberOfCities();
	int* indices = new int[size];
	for (int i = 0; i < size; i++) {
		indices[i] = i;
	}

	static unsigned int seed = 48;
	srand(seed++);
	random_shuffle(indices, indices + size);


	for (int i = 0; i < TourManager::getInst()->numberOfCities(); i++) {
		City tmp = *TourManager::getInst()->getCity(i);
		cities[indices[i]] = *(new City(tmp.getX(), tmp.getY()));

		//std::cout << cities[indices[i]].getAllele() << std::endl;
	}

	delete[] indices;
}

float Tour::getDistance() {
	if (distance == 0) {
		distance = 0;
		int tourCount = TourManager::getInst()->numberOfCities();

		for (int i = 0; i < tourCount; i++) {
			City ot = cities[i];
			City dest = i + 1 < tourCount ? cities[i + 1] : cities[0];
			
			distance += ot.distanceTo(dest);
			
		}
	}

	return distance;
}

bool Tour::hasCity(City& c) {

	for (int i = 0; i < TourManager::getInst()->numberOfCities(); i++) {
		if (&cities[i] == &c)
			return true;
	}

	return false;
}

std::string Tour::getChromosomeAsCSV() {

	std::string chromo;

	for (int gene = 0; gene < TourManager::getInst()->numberOfCities(); gene++) {
		chromo += std::to_string(cities[gene].getX());
		chromo += "&";
		chromo += std::to_string(cities[gene].getY());
		chromo += ",";

	}

	return chromo;
}

float Tour::getFitness() {
	if (fitness == 0) {
		fitness = (float) 1 / getDistance();
	}

	return fitness;
}




#endif // !__TOUR_H__


#ifndef __POPULATION_H__
#define __POPULATION_H__

#include "Tour.h"

class Population {

private:
	Tour* tours; // hypothesis for this pop
	int n;

public:
	Population(int n, bool randomInit);

	void setElement(int index, Tour& t);
	Tour* getElement(int index);

	Tour* getFittestElement();

	int getN();

};


Population::Population(int n, bool randomInit) : n{ n } {
	tours = new Tour[n];
	if (randomInit) {
		for (int i = 0; i < n; i++) {
			Tour* solution = new Tour();
			solution->constuctRandomChromosone(); // cities are supposted created here
			//std::cout << solution->getCity(0)->getX() << std::endl;
			tours[i] = *solution;
			//setElement(i, *solution);

		}
	}

	std::cout << "";

}

void Population::setElement(int index, Tour& t) {

	tours[index] = t;

}

Tour* Population::getElement(int index) {

	return &tours[index];

}

Tour* Population::getFittestElement() {
	Tour& mostfit = tours[0];

	for (int i = 0; i < n; i++) {
		if (tours[i].getFitness() >= mostfit.getFitness()) {
			mostfit = tours[i];
		}
	}

	return &mostfit;
}

int Population::getN() {
	return n;
}

#endif // !__POPULATION_H__

#ifndef __GENETIC_ALGORITHM__
#define __GENETIC_ALGORITHM__

#include "Population.h"
#include "Tour.h"
#include <cstdlib>

#define mutation_rate 0.01
#define tournament_size 4
#define using_elites true

class GeneticAlgorithm {

private:
	static GeneticAlgorithm* inst;
	GeneticAlgorithm();

public:
	static GeneticAlgorithm* getInst();
	Tour* selection(Population& pop);
	Population* evolve(Population& pop);
	Tour* crossover(Tour& t1, Tour& t2);
	void mutate(Tour& r);
};

float value() {
	return (rand() % 1000) / (float)1000;
}

GeneticAlgorithm::GeneticAlgorithm() {

}

GeneticAlgorithm* GeneticAlgorithm::inst = 0;

GeneticAlgorithm* GeneticAlgorithm::getInst() {
	if (inst == 0) {
		inst = new GeneticAlgorithm();
	}

	return inst;
}

Tour* GeneticAlgorithm::selection(Population& pop) {

	Population* tournament = new Population(tournament_size, false);
	int size = tournament->getN();


	for (int i = 0; i < tournament_size; i++) {
		tournament->setElement(i, *pop.getElement((int)(value() * (float)size)));
	}

	return tournament->getFittestElement();
}

Population* GeneticAlgorithm::evolve(Population& pop) {

	Population* next_generation = new Population(pop.getN(), false);

	int elitismOffset = 0;
	if (using_elites) {
		next_generation->setElement(0, *pop.getFittestElement());
		elitismOffset = 1;
	}

	for (int i = elitismOffset; i < next_generation->getN(); i++) {
		Tour* parent1 = selection(pop);
		Tour* parent2 = selection(pop);



		Tour* child = crossover(*parent1, *parent2);
		next_generation->setElement(i, *child);
	}

	for (int i = elitismOffset; i < next_generation->getN(); i++) {
		mutate(*next_generation->getElement(i));
	}

	return next_generation;
}

Tour* GeneticAlgorithm::crossover(Tour& t1, Tour& t2) {

	Tour* offspring = new Tour();
	int toursize = TourManager::getInst()->numberOfCities();

	int start = value() * toursize;
	int end = value() * toursize;

	/*

	for (int i = 0; i < toursize; i++) {
		if (start < end && i > start&& i < end) {
			offspring->setCity(i, *t1.getCity(i));
		} else if (start > end) {
			if (!(i < start && i > end)) {
				offspring->setCity(i, *t1.getCity(i));
			}
		}
	}

	for (int i = 0; i < toursize; i++) {
		if (!offspring->hasCity(*t2.getCity(i))) {
			for (int j = 0; j < toursize; j++) {
				if (offspring->getCity(j) == nullptr) {
					offspring->setCity(j, *t2.getCity(i));
					break;
				}
			}
		}
	}
	*/
	offspring->constuctRandomChromosone();

	return offspring;
}

void GeneticAlgorithm::mutate(Tour& t) {
	int toursize = TourManager::getInst()->numberOfCities();

	for (int i = 0; i < toursize; i++) {
		if (value() < mutation_rate) {
			int j = (float)toursize * value();

			City* city1 = t.getCity(i);
			City* city2 = t.getCity(j);

			t.setCity(j, *city1);
			t.setCity(i, *city2);
		}
	}

}




#endif // !__GENETIC_ALGORITHM__

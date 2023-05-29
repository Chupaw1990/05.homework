#pragma once

#include <vector>
#include <iostream>
#include <math.h>
#include "istatistic.h"

class Std : public IStatistics {
public:

	Std() : sum_elements{0},
             count{0},
             mean{0}
             {elements.clear();}

	void update(double next) override {
        sum_elements += next;
        count++;
        elements.push_back(next);
	}

	double eval() const override {

        double sigma = 0;

        for (size_t i : elements){
            sigma += pow(elements[i] - (sum_elements / count),2);
        }

		return pow(sigma / count, 0.5);
	}

	const char * name() const override {
		return "std";
	}

private:
	double sum_elements = 0;
    int count = 0;
    double mean = 0;
    std::vector<double> elements;
};
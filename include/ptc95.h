#pragma once

#include <vector>
#include <algorithm>
#include <math.h>
#include "istatistic.h"

class Pct95 : public IStatistics {
public:

	Pct95() : count{0}
            {elements.clear();}

	void update(double next) override {
        count++;
        elements.push_back(next);
        std::sort(elements.begin(), elements.end());
	}

	double eval() const override {

        double step = 100.0 / count;
        int index = 95 / step; 

		return elements[index];
	}

	const char * name() const override {
		return "pct95";
	}

private:
    int count = 0;
    std::vector<double> elements;
};
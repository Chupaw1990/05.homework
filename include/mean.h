#pragma once

#include "istatistic.h"

class Mean : public IStatistics {
public:

	Mean() : sum_elements{0},
             count{0} {}

	void update(double next) override {
        sum_elements += next;
        count++;
	}

	double eval() const override {
		return sum_elements / count;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double sum_elements = 0;
    int count = 0;
};
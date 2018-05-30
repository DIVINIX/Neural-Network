#pragma once

#define NB_INPUTS 15
#define NB_OUTPUTS 8
#define NB_NEURONS 3


typedef struct Input {
	double value;
	double weight;
};

typedef struct Output {
	double value;
	double expected;
};


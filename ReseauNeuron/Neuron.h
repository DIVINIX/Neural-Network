#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>

#include "constants.h"


class Neuron
{
private:
	std::vector<Input> _inputs;
	Output _output;

	double _bias;


public:
	Neuron(double bias);
	Neuron(std::vector<Input> inputs, Output output, double bias);
	~Neuron();

	double treatment(double rate);
	void aggregation();
	void activation();
	void calculationWeight(double rate);

	int getOutputValue();

	void setInputs(std::vector<Input> inputs);
	void setOutput(Output _output);
};


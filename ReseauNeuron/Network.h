#pragma once

#include "Neuron.h"

class Network
{
	std::vector<Input> _inputs;
	std::vector<Output> _outputs;
	std::vector<Neuron*> _neurons;

public:
	Network();
	Network(std::vector<Input> inputs, std::vector<Output> outputs);
	~Network();

	void treatment(double rate);

	std::vector<Neuron*> getNeurons();
	
	void setInputs(std::vector<Input> inputs);
	void setOutputs(std::vector<Output> outputs);

	void updateNeuron();
};


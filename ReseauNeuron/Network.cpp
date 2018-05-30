#include "Network.h"

using namespace std;

Network::Network()
{
	//-------------------------
	// Préparation des neurons
	//-------------------------

	for (int i = 0; i < NB_NEURONS; i++)
	{
		double bias = rand() % 10 + 1;
		_neurons.push_back(new Neuron(bias));
	}
}

Network::Network(vector<Input> inputs, vector<Output> outputs)
{
	//-------------------------
	// Préparation des neurons
	//-------------------------

	for (int i = 0; i < NB_NEURONS; i++)
	{
		double bias = rand() % 10 + 1;
		_neurons.push_back(new Neuron(bias));
	}

	_inputs = inputs;
	_outputs = outputs;	
}

Network::~Network()
{
	// Do nothing ...
}

void Network::treatment(double rate)
{
	for (int i = 0; i < NB_NEURONS; i++)
		_neurons.at(i)->treatment(rate);

}

vector<Neuron*> Network::getNeurons()
{
	return _neurons;
}

void Network::setInputs(std::vector<Input> inputs)
{
	_inputs = inputs;
}

void Network::setOutputs(std::vector<Output> output)
{
	_outputs = output;
}

void Network::updateNeuron()
{
	for (int i = 0; i < NB_NEURONS; i++)
	{
		_neurons.at(i)->setInputs(this->_inputs);
		_neurons.at(i)->setOutput(this->_outputs.at(i));
	}
}

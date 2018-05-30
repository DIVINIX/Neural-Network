#include "Neuron.h"

Neuron::Neuron(double bias)
{
	_bias = bias;
}

Neuron::Neuron(std::vector<Input> inputs, Output output, double bias)
	: _output(output), _bias(bias)
{
	_inputs = inputs;
}


Neuron::~Neuron()
{
}

double Neuron::treatment(double rate)
{
	aggregation();
	activation();
	calculationWeight(rate);
	return _output.value;
}

void Neuron::aggregation()
{
	double sum = 0;

	for (int i = 0; i < NB_INPUTS; i++)
		sum += _inputs.at(i).value *_inputs.at(i).weight;

	_output.value = sum;
}

void Neuron::activation()
{
	if (_output.value >= _bias)
		_output.value = 1;
	else
		_output.value = 0;
}

void Neuron::calculationWeight(double rate)
{
	double error = _output.expected - _output.value;

	for (int i = 0; i < NB_INPUTS; i++)
		_inputs[i].weight = _inputs[i].weight + (rate * error * _inputs[i].value);
}

int Neuron::getOutputValue()
{
	return _output.value;
}

void Neuron::setInputs(std::vector<Input> inputs)
{
	_inputs = inputs;
}

void Neuron::setOutput(Output output)
{
	_output = output;
}
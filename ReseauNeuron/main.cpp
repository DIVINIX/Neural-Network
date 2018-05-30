#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "Neuron.h"
#include "constants.h"
#include "Network.h"

#define NB_INPUTS 15
#define NB_LINES 8
#define NB_NEURONS 3

using namespace std;

vector<Input> getInputs(int currentLine)
{
	//-------------------------
	// Préparation des entrées 
	//-------------------------

	vector<Input> inputs;

	double TMPinputs[NB_LINES][NB_INPUTS] = {
		{ 1,1,1,1,0,1,1,0,1,1,0,1,1,1,1 },
	{ 0,1,0,0,1,0,0,1,0,0,1,0,0,1,0 },
	{ 1,1,1,0,0,1,1,1,1,1,0,0,1,1,1 },
	{ 1,1,1,0,0,1,1,1,1,0,0,1,1,1,1 },
	{ 1,0,1,1,0,1,1,1,1,0,0,1,0,0,1 },
	{ 1,1,1,1,0,0,1,1,1,0,0,1,1,1,1 },
	{ 1,1,1,1,0,0,1,1,1,1,0,1,1,1,1 },
	{ 1,1,1,0,0,1,0,0,1,0,0,1,0,1,1 }
	};

	for (int i = 0; i < NB_INPUTS; i++)
		inputs.push_back({ TMPinputs[currentLine][i], 1 });

	return inputs;
}

vector<Output> getOuputs(int currentLine)
{
	//-------------------------
	// Préparation des sorties
	//-------------------------

	vector<Output> outputs;

	double expectedOutputs[NB_LINES][NB_NEURONS] = {
		{ 0,0,0 },
	{ 0,0,1 },
	{ 0,1,0 },
	{ 0,1,1 },
	{ 1,0,0 },
	{ 1,0,1 },
	{ 1,1,0 },
	{ 1,1,1 }
	};

	for (int i = 0; i < NB_LINES; i++)
		outputs.push_back({ -1, expectedOutputs[currentLine][i] });

	return outputs;
}

void treatment(int currentLine, Network *network)
{
	network->setInputs(getInputs(currentLine));
	network->setOutputs(getOuputs(currentLine));
	network->updateNeuron();

	double rate = rand() % 10 + 50;

	//##############################
	// On lance l'apprentissage
	//##############################
	printf("On lance l'apprentissage ... \n");
	for (int i = 0; i < 1000; i++)
	{
		network->treatment(rate);

		rate = rate * 0.99;
	}

	//##############################
	// On affiche le résultat
	//##############################
	vector<Neuron*> _neurons = network->getNeurons();
	int i = 1;
	for (Neuron* n : _neurons)
	{
		cout << "Sortie neuron " << i  << " : " << n->getOutputValue() << endl;
		i++;
	}
		
}

int main() {

	int currentLine = 0;	

	//-------------------------
	// Préparation du réseau
	//-------------------------
	Network * network = new Network(getInputs(0),getOuputs(0));

	//##############################
	// START
	//##############################
	printf("Bienvenue sur le systeme ABBR (taper \"exit\" pour quitter le systeme)\n");

	while (true)
	{
		int currentLine = 0;

		printf("Quel ligne souhaitez-vous ? ");
		string strIn;
		getline(cin, strIn);
		if (strIn.compare("out") == 0)
			continue;

		currentLine = atoi(strIn.c_str());
		if (currentLine >= 0 && currentLine < 8)
		{
			treatment(currentLine, network);
		}
		else
		{
			printf("\n Les lignes sont comprises entre 0 et %i \n", NB_LINES - 1);
		}
	}

	system("PAUSE");
}
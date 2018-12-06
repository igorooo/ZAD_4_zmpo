#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "CIndividual.h"
#include "Knapsack.h"
#include "CGeneticAlgorithm.h"

int main() {

    int SIZE = 5;

    srand(time(0));

    Knapsack* KN = new Knapsack(5,12);

    double vTab[] = {1.0, 2.1, 3, 4, 5};
    double wTab[] = {1.5, 2.6, 2, 4, 4.5};

    vector<double> weights;
    vector<double> values;

    for(int i = 0; i < SIZE; i++){
        weights.push_back(wTab[i]);
        values.push_back(vTab[i]);
    }

    int POP_SIZE = 10;
    int END_GEN = 10;
    double CROSS_PROB = 0.7;
    double MUT_PROB = 0.1;


    KN->fill_values(values);
    KN->fill_weights(weights);

    /*
    CIndividual* CI = new CIndividual(SIZE,12,0.7,0.1,KN);

    CI->print_gen();  */

    CGeneticAlgorithm* CGA = new CGeneticAlgorithm(POP_SIZE,END_GEN,CROSS_PROB,MUT_PROB,KN);

    CGA->run_ga();
    CGA->print_wh_gen();


    return 0;
}
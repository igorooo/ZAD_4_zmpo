#include <iostream>
#include "CIndividual.h"
#include "Knapsack.h"

int main() {


    Knapsack* KN = new Knapsack(5,12);


    KN->fill_values();
    KN->fill_weights();

    CIndividual* CI = new CIndividual(5,12,0.7,0.1,KN);

    CI->print_gen();


    return 0;
}
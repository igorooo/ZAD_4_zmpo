//
// Created by qivi on 11/28/18.
//

#ifndef ZAD_4_ZMPO_CINDIVIDUAL_H
#define ZAD_4_ZMPO_CINDIVIDUAL_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Knapsack.h"

#define EPSILON 0.001

using namespace std;


class CIndividual {

private:
    bool *GENOTYPE;
    int SIZE;
    double MAX_LOAD;
    double FITNESS;
    double CROSS_PROB,MUT_PROB;
    Knapsack* KNAPSACK;



public:
    void c_fitness();
    double fitness();
    void mutation();   //  0 <= PROBABILITY <=1
    CIndividual* cross(CIndividual* PARENT_B,int CROSS_PARTITION);  // this = PARENT_A
    bool brandom(double PROBA);
    void create_genotype();
    void print_gen();

    CIndividual(CIndividual &CLONE);
    CIndividual(int SIZE, double MAX_LOAD, double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK);
    CIndividual(int SIZE, double MAX_LOAD, double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK, bool* GENOTYPE);
    ~CIndividual();

    bool operator<(CIndividual &OBJECT);




};


#endif //ZAD_4_ZMPO_CINDIVIDUAL_H

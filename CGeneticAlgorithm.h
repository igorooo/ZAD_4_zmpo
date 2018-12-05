//
// Created by qivi on 11/29/18.
//

#ifndef ZAD_4_ZMPO_CGENETICALGORITHM_H
#define ZAD_4_ZMPO_CGENETICALGORITHM_H


#include <cstdlib>
#include <iostream>
#include "CIndividual.h"
#include "Knapsack.h"

class CGeneticAlgorithm {

private:
    int POP_SIZE;
    int END_GENERATION;  //amount of iterations
    int CURRENT_GEN;
    double CROSS_PROBA;  //PROBABILITY
    double MUTATION_PROBA; //PROBABILITY
    CIndividual*** WHOLE_GENERATION;
    Knapsack* KNAPSACK;

public:
    void cr_fst_gen();  //create first generation
    void next_gen(int LAST_GEN_POS);
    void find_cur_leader(int POS);
    CIndividual* wh_gen_leader(); //whole generation leader
    CIndividual* parent(int POS);

    void run_ga();

    CGeneticAlgorithm(int POP_SIZE,int END_GENERATION, double CROSS_PROBA, double MUTATION_PROBA, Knapsack* KNAPSACK );
    ~CGeneticAlgorithm();







};


#endif //ZAD_4_ZMPO_CGENETICALGORITHM_H

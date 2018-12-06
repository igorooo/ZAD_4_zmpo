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
    bool DONE;

public:
    void cr_fst_gen();  //create first generation
    void next_gen();  //create next gen
    void find_cur_leader(int POS); //current generation leader
    CIndividual* wh_gen_leader(); //whole generations leader
    CIndividual* parent(int POS);  // random parent

    void run_ga();
    void print_wh_gen();
    void print_gen(int POS);

    CGeneticAlgorithm(int POP_SIZE,int END_GENERATION, double CROSS_PROBA, double MUTATION_PROBA, Knapsack* KNAPSACK );
    ~CGeneticAlgorithm();







};


#endif //ZAD_4_ZMPO_CGENETICALGORITHM_H

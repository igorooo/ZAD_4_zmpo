//
// Created by qivi on 11/29/18.
//

#include "CGeneticAlgorithm.h"

void CGeneticAlgorithm::cr_fst_gen() {

        CIndividual** CInARRAY = new CIndividual*[this->POP_SIZE +2];

        for(int i = 0; i < this->POP_SIZE; i++){

                CInARRAY[i] = new CIndividual(KNAPSACK->size(),KNAPSACK->max_load(),this->CROSS_PROBA,this->MUTATION_PROBA,this->KNAPSACK);
        }

        this->CURRENT_GEN = 0;
        *(this->WHOLE_GENERATION) = CInARRAY;
        this->find_cur_leader(0);

}

void CGeneticAlgorithm::next_gen() {

        CIndividual* PARENT_A;
        CIndividual* PARENT_B;
        int CROSS_PART;


        for(int POP_ITER = 0; POP_ITER < this->POP_SIZE; POP_ITER++){

            PARENT_A = this->parent(this->CURRENT_GEN);
            PARENT_B = this->parent(this->CURRENT_GEN);

            CROSS_PART = (rand()%(this->KNAPSACK->size()-1))+1;

            this->WHOLE_GENERATION[this->CURRENT_GEN+1][POP_ITER++] = PARENT_A->cross(PARENT_B,CROSS_PART);

            if(POP_ITER < this->POP_SIZE){

                this->WHOLE_GENERATION[this->CURRENT_GEN+1][POP_ITER++] = PARENT_B->cross(PARENT_A,CROSS_PART);
            }

        }

        this->CURRENT_GEN ++;
        this->find_cur_leader(this->CURRENT_GEN);
}

void CGeneticAlgorithm::find_cur_leader(int POS) {

        CIndividual* LEADER = this->WHOLE_GENERATION[POS][0];

        for(int i = 0; i < this->POP_SIZE; i++){

                if( this->WHOLE_GENERATION[POS][i] > LEADER )
                        LEADER = this->WHOLE_GENERATION[POS][i];
        }

        this->WHOLE_GENERATION[POS][this->POP_SIZE] = LEADER;
}

CIndividual* CGeneticAlgorithm::parent(int POS) {

        int CANDIDATE_A = rand()%this->POP_SIZE;
        int CANDIDATE_B = rand()%this->POP_SIZE;

        if(this->WHOLE_GENERATION[POS][CANDIDATE_A] > this->WHOLE_GENERATION[POS][CANDIDATE_B]){
                return this->WHOLE_GENERATION[POS][CANDIDATE_A];
        }

        else{
                return this->WHOLE_GENERATION[POS][CANDIDATE_B];
        }

}


CIndividual* CGeneticAlgorithm::wh_gen_leader() {

        CIndividual* WH_LEADER = this->WHOLE_GENERATION[0][this->POP_SIZE];

        for(int POP_ITER = 0; POP_ITER < this->POP_SIZE; POP_ITER++){

                if(this->WHOLE_GENERATION[POP_ITER][this->POP_SIZE] > WH_LEADER){
                        WH_LEADER = this->WHOLE_GENERATION[POP_ITER][this->POP_SIZE];
                }
        }

        return WH_LEADER;
}

void CGeneticAlgorithm::run_ga() {

}

CGeneticAlgorithm::CGeneticAlgorithm(int POP_SIZE, int END_GENERATION, double CROSS_PROBA, double MUTATION_PROBA,
                                     Knapsack *KNAPSACK) {


        WHOLE_GENERATION= new CIndividual** [KNAPSACK->size()+2];
        this->POP_SIZE = POP_SIZE;
        this->KNAPSACK = KNAPSACK;
        this->CROSS_PROBA = CROSS_PROBA;
        this->MUTATION_PROBA = MUTATION_PROBA;
        this->END_GENERATION = END_GENERATION;
        this->CURRENT_GEN = 0;

}

CGeneticAlgorithm::~CGeneticAlgorithm() {

}


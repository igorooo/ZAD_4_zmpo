//
// Created by qivi on 11/28/18.
//

#include "CIndividual.h"

void CIndividual::c_fitness() {

    double SUM_OF_VALUE = 0, SUM_OF_WEIGHT = 0;

    for(int i = 0; i < this->SIZE; i++){

        if( this->GENOTYPE[i] ){

            SUM_OF_VALUE += this->KNAPSACK->value_of_item(i);
            SUM_OF_WEIGHT += this->KNAPSACK->weight_of_item(i);
        }
    }

    if( (this->MAX_LOAD - SUM_OF_WEIGHT > 0) || (fabs(this->MAX_LOAD - SUM_OF_WEIGHT) < EPSILON )){   // LESS OR EQUAL FOR FLOAT N
        this->FITNESS = SUM_OF_VALUE;
    }

    else{
        this->FITNESS = 0;
    }

}

double CIndividual::fitness() {
    return this->FITNESS;
}


bool CIndividual::brandom(double PROBA) {

    double R = double(rand()%1001) / 1000.0;

    return (PROBA - R > 0);
}

void CIndividual::mutation() {

    for(int i = 0; i < this->SIZE ; i++){

        if(brandom(this->MUT_PROB)){
            this->GENOTYPE[i] = !(this->GENOTYPE[i]);
        }
    }
}

CIndividual* CIndividual::cross(CIndividual* PARENT_B, int CROSS_PARTITION) {

    if(brandom(this->CROSS_PROB)){

        bool* N_GENOTYPE = new bool[this->SIZE];

        for(int i = 0; i < CROSS_PARTITION; i++){
            N_GENOTYPE[i] = this->GENOTYPE[i];
        }

        for(int i = CROSS_PARTITION; i < this->SIZE; i++){
            N_GENOTYPE[i] = PARENT_B->GENOTYPE[i];
        }

        return (new CIndividual(this->SIZE,this->MAX_LOAD,this->CROSS_PROB, this->MUT_PROB,this-> KNAPSACK, N_GENOTYPE));
    }

    else{
        return new CIndividual( *this );
    }

}


CIndividual::CIndividual(CIndividual &CLONE) {

    bool *GENOTYPE = new bool[CLONE.SIZE];

    for(int i = 0; i < CLONE.SIZE; i++){
        GENOTYPE[i] = CLONE.GENOTYPE[i];
    }

    this->GENOTYPE = GENOTYPE;

    this->SIZE = CLONE.SIZE;
    this->MAX_LOAD = CLONE.MAX_LOAD;
    this->CROSS_PROB = CLONE.CROSS_PROB;
    this->MUT_PROB = CLONE.MUT_PROB;
    this->KNAPSACK = CLONE.KNAPSACK;
    this->FITNESS = CLONE.FITNESS;
}

CIndividual::CIndividual(int SIZE, double MAX_LOAD, double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK) {

    this->SIZE = SIZE;
    this->MAX_LOAD = MAX_LOAD;
    this->CROSS_PROB = CROSS_PROB;
    this->MUT_PROB = MUT_PROB;
    this->KNAPSACK = KNAPSACK;

    this->create_genotype();

    this->c_fitness();
}

CIndividual::CIndividual(int SIZE, double MAX_LOAD, double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK, bool *GENOTYPE) {

    this->SIZE = SIZE;
    this->MAX_LOAD = MAX_LOAD;
    this->CROSS_PROB = CROSS_PROB;
    this->MUT_PROB = MUT_PROB;
    this->KNAPSACK = KNAPSACK;

    this->GENOTYPE = GENOTYPE;

    this->c_fitness();
}

CIndividual::~CIndividual() {

    delete[] GENOTYPE;
}

bool CIndividual::operator>(CIndividual &OBJECT) {
    return (this->FITNESS > OBJECT.FITNESS);
}

void CIndividual::create_genotype() {

    this->GENOTYPE = new bool[this->SIZE +1];

    for(int i = 0; i < this->SIZE; i++){

        this->GENOTYPE[i] = (bool)(rand()%2);
    }

}

void CIndividual::print_gen() {

    for(int i = 0; i < this->SIZE; i++){
        cout<<this->GENOTYPE[i];
    }
    cout<<" fitness: "<<this->FITNESS<<endl;

}







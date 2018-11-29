//
// Created by qivi on 11/28/18.
//

#ifndef ZAD_4_ZMPO_CINDIVIDUAL_H
#define ZAD_4_ZMPO_CINDIVIDUAL_H

#define EPSILON 0.0001


class CIndividual {

private:
    bool *GENOTYPE;
    int SIZE;
    double MAX_LOAD;
    double FITNESS;


public:
    double fitness();
    void mutation(double PROBABILITY);   //  0 <= PROBABILITY <=1
    CIndividual cross(CIndividual PARENT_B);  // this = PARENT_A

    CIndividual();
    CIndividual(int SIZE, int MAX_LOAD);
    ~CIndividual();

    bool operator<(CIndividual &OBJECT);




};


#endif //ZAD_4_ZMPO_CINDIVIDUAL_H

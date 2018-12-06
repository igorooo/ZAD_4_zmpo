//
// Created by qivi on 11/29/18.
//

#include "CGeneticAlgorithm.h"

void CGeneticAlgorithm::cr_fst_gen() {

        CIndividual** CInARRAY = new CIndividual*[this->POP_SIZE +2];



        for(int i = 0; i < this->POP_SIZE; i++){

                CInARRAY[i] = new CIndividual(this->KNAPSACK->size(),this->KNAPSACK->max_load(),this->CROSS_PROBA,this->MUTATION_PROBA,this->KNAPSACK);
               // CInARRAY[i]->print_gen();
        }

        this->CURRENT_GEN = 0;
        this->WHOLE_GENERATION[0] = CInARRAY;
        this->find_cur_leader(0);

        cout<<"FRST GEN: ";
        this->print_gen(0);

}

void CGeneticAlgorithm::next_gen() {

        CIndividual* PARENT_A;
        CIndividual* PARENT_B;
        int CROSS_PART,POP_ITER = 0;

        CIndividual** CInARRAY = new CIndividual*[this->POP_SIZE +2];


        //for(int POP_ITER = 0; POP_ITER < this->POP_SIZE; POP_ITER++){
        while(POP_ITER < this->POP_SIZE){

            //cout<<CURRENT_GEN<<"<-"<<endl;
            PARENT_A = this->parent(this->CURRENT_GEN);
            PARENT_B = this->parent(this->CURRENT_GEN);

            CROSS_PART = (rand()%(this->KNAPSACK->size()-2))+1;

           // this->WHOLE_GENERATION[this->CURRENT_GEN+1][POP_ITER++] = PARENT_A->cross(PARENT_B,CROSS_PART);

           CInARRAY[POP_ITER++] = new CIndividual(*PARENT_A->cross(PARENT_B,CROSS_PART));

            if(POP_ITER < this->POP_SIZE){

               // this->WHOLE_GENERATION[this->CURRENT_GEN+1][POP_ITER++] = PARENT_B->cross(PARENT_A,CROSS_PART);
                CInARRAY[POP_ITER++] = new CIndividual(*PARENT_B->cross(PARENT_A,CROSS_PART));
            }

        }

        cout<<"GEN: "<<this->CURRENT_GEN<<" : ";
        this->print_gen(this->CURRENT_GEN);

        if(CURRENT_GEN > 0){
                cout<<"GEN(before) "<<this->CURRENT_GEN-1<<" : ";
                this->print_gen(this->CURRENT_GEN-1);
        }

        this->CURRENT_GEN ++;
        this->WHOLE_GENERATION[this->CURRENT_GEN] = CInARRAY;
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

        int CANDIDATE_A = rand()%(this->POP_SIZE);
        int CANDIDATE_B = rand()%(this->POP_SIZE);
        //cout<<CANDIDATE_A<<" "<<CANDIDATE_B<<endl;


        //DEBUG
        /*
        if(WHOLE_GENERATION[POS][CANDIDATE_A] == NULL || WHOLE_GENERATION[POS][CANDIDATE_B] == NULL){
                cout<<"Err : pos: "<<POS<<" "<<CANDIDATE_A<<" "<<CANDIDATE_B<<endl;
        } */

        if(this->WHOLE_GENERATION[POS][CANDIDATE_A] > this->WHOLE_GENERATION[POS][CANDIDATE_B]){
                return this->WHOLE_GENERATION[POS][CANDIDATE_A];
        }

        return this->WHOLE_GENERATION[POS][CANDIDATE_B];

}


CIndividual* CGeneticAlgorithm::wh_gen_leader() {

        cout<<"------TEST wh_gen_leader"<<endl;
        this->print_gen(0);

        CIndividual* WH_LEADER = this->WHOLE_GENERATION[0][this->POP_SIZE];

        for(int POP_ITER = 0; POP_ITER < this->END_GENERATION; POP_ITER++){

                if(this->WHOLE_GENERATION[POP_ITER][this->POP_SIZE] > WH_LEADER){
                        WH_LEADER = this->WHOLE_GENERATION[POP_ITER][this->POP_SIZE];
                }
        }

        cout<<endl<<"---wh"<<endl;
        this->print_gen(0);
        cout<<endl<<"-----"<<endl;

        return WH_LEADER;
}

void CGeneticAlgorithm::run_ga() {

        if(this->POP_SIZE < 2){
                cout<<" POP_SIZE must be greater than 1"<<endl;
                return;
        }

        this->cr_fst_gen();

        while(this->CURRENT_GEN < this->END_GENERATION){

                cout<<"run_ga"<<this->CURRENT_GEN
                this->next_gen();

        }

        this->CURRENT_GEN--;
        this->wh_gen_leader();
        this->DONE = true;
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
        this->DONE = false;

}

CGeneticAlgorithm::~CGeneticAlgorithm() {

}

void CGeneticAlgorithm::print_wh_gen() {

        if(!this->DONE){
                cout<<"AG is not done yet!"<<endl;
                return;
        }

        this->WHOLE_GENERATION[0][0]->print_gen();
        cout<<", ";
        this->WHOLE_GENERATION[0][1]->print_gen();
        cout<<", ";
        this->WHOLE_GENERATION[0][2]->print_gen();
        cout<<", ";
        this->WHOLE_GENERATION[0][3]->print_gen();
        cout<<endl;


        for(int i = 0; i < this->END_GENERATION; i++){

                cout<<"GEN "<<i<<" : ";
                this->print_gen(i);
                cout<<endl;
        }

        //cout<<endl<<endl<<"Leader of whole generations: ";
        //this->wh_gen_leader()->print_gen();
        //cout<<endl;
}

void CGeneticAlgorithm::print_gen(int POS) {


        for (int i = 0; i < this->POP_SIZE; i++) {
                this->WHOLE_GENERATION[POS][i]->print_gen();
                cout << " ";
        }
        cout << endl;
}


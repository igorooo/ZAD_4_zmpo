//
// Created by qivi on 12/4/18.
//

#include "Knapsack.h"

int Knapsack::n_items() {
    return this->N_ITEMS;
}

double Knapsack::max_load() {
    return this->MAX_LOAD;
}

double Knapsack::weight_of_item(int POS) {
    return this->WEIGHT_OF_ITEMS[POS];
}

double Knapsack::value_of_item(int POS) {
    return this->VALUE_OF_ITEMS[POS];
}

void Knapsack::fill_weights() {

    for(int i = 0; i < this->N_ITEMS; i++){
        cin>>this->WEIGHT_OF_ITEMS[i];
    }
}

void Knapsack::fill_values() {

    for(int i = 0; i < this->N_ITEMS; i++){
        cin>>this->VALUE_OF_ITEMS[i];
    }
}

Knapsack::Knapsack(int N_ITEMS, double MAX_LOAD) {

    this->N_ITEMS = N_ITEMS;
    this->MAX_LOAD = MAX_LOAD;

    this->VALUE_OF_ITEMS = new double[N_ITEMS +1];
    this->WEIGHT_OF_ITEMS = new double[N_ITEMS +1];

}

Knapsack::~Knapsack() {

    delete[] VALUE_OF_ITEMS;
    delete[] WEIGHT_OF_ITEMS;
}

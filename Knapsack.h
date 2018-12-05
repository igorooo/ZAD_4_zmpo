//
// Created by qivi on 12/4/18.
//

#ifndef ZAD_4_ZMPO_KNAPSACK_H
#define ZAD_4_ZMPO_KNAPSACK_H

#include <iostream>
#include <vector>

#define ARR_LEN(ar) (sizeof(ar) / sizeof(*ar))

using namespace std;

class Knapsack {

private:
    int N_ITEMS;
    double MAX_LOAD;
    double* WEIGHT_OF_ITEMS;
    double* VALUE_OF_ITEMS;

public:
    int n_items();
    double max_load();
    double weight_of_item(int POS);
    double value_of_item(int POS);
    int size();

    void fill_weights(vector<double> TAB);
    void fill_values(vector<double> TAB);

    Knapsack(int N_ITEMS, double MAX_LOAD);
    ~Knapsack();


};


#endif //ZAD_4_ZMPO_KNAPSACK_H

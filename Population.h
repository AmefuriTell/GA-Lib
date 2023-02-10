#ifndef _H_POPULATION_
#define _H_POPULATION_

#include <bits/stdc++.h>
#include "Individual.h"

class Population
{
public:
    Population(int arg_number_of_individuals, int arg_chromosome_length, int arg_max_generation);
    ~Population();
    void sort(int l, int r);

    void print_all();

    Individual **individual;    //個体群

    int number_of_individuals;  //1世代ごとの個体数
    int chromosome_length;      //個体の染色体の長さ
    int max_generation;         //最大世代数

private:
};

#endif
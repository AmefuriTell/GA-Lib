#include "Population.h"

Population::Population(int arg_number_of_individuals, int arg_chromosome_length, int arg_max_generation)
{

    number_of_individuals = arg_number_of_individuals;
    chromosome_length = arg_chromosome_length;
    max_generation = arg_max_generation;

    individual = new Individual*[number_of_individuals];
    for(int i = 0; i < number_of_individuals; i++)
    {
        individual[i] = new Individual(chromosome_length);
    }

    sort(0, number_of_individuals);
}

Population::~Population()
{
    for(int i = 0; i < number_of_individuals; i++)
    {
        delete individual[i];
    }
    delete[] individual;
}

void Population::print_all()
{
    for (int i = 0; i < number_of_individuals; i++)
    {
        individual[i]->print();
    }
}

void Population::sort(int l, int r)
{
    
    if(r - l > 1)
    {
        int mid = l + (r - l) / 2;
        sort(l, mid);//右をソート
        sort(mid, r);//左をソート

        //結合
        std::deque<Individual*> buf;
        for(int i = l; i < mid; i++)buf.push_back(individual[i]);
        for(int i = r - 1; i >= mid; i--)buf.push_back(individual[i]);
        for (int i = l; i < r; i++)
        {
            if(buf.back()->score < buf.front()->score)
            {
                individual[i] = buf.back();
                buf.pop_back();
            }
            else
            {
                individual[i] = buf.front();
                buf.pop_front();
            }
        }
    }
}
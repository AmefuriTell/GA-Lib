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

    qsort(individual, number_of_individuals, sizeof(Individual), comp_Individual);
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
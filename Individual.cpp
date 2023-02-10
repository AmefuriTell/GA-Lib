#include <bits/stdc++.h>
#include "Individual.h"

Individual::Individual(){}

Individual::Individual(int arg_chromosome_length)
{
    set(arg_chromosome_length);
}
void Individual::set(int arg_chromosome_length)
{
    chromosome_length = arg_chromosome_length;

    chromosome = new bool[chromosome_length];
    make_new_chromosome();
}

Individual::~Individual()
{
    delete[] chromosome;
}

void Individual::print()
{
    for (int i = 0; i < chromosome_length; i++)
    {
        printf("%d ", chromosome[i]);
    }
    
    printf(" : score = %.0Lf", score);

    printf("\n");
}

void Individual::make_new_chromosome()
{
    for (int i = 0; i < chromosome_length; i++)
    {
        chromosome[i] = rand() % 2;
    }
    evaluate();
}

void Individual::evaluate()
{
    score = 0;
    for (int i = 0; i < chromosome_length; i++)
    {
        score += chromosome[i];
    }
}

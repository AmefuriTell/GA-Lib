#include <bits/stdc++.h>
#include "Individual.h"
#include "Population.h"
using namespace std;

int main()
{
    //ランダムシード生成
    srand((unsigned int)time(NULL));

    //個体群を生成
    Population population(10, 10, 100);

    population.print_all();

}
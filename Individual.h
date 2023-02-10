#ifndef _H_INDIVIDUAL_
#define _H_INDIVIDUAL_

class Individual
{
public:
    Individual();
    Individual(int arg_chromosome_length);
    ~Individual();

    void set(int arg_chromosome_length);

    void print();
    
    bool *chromosome;
    int chromosome_length;
    long double score;

    int operator < (const Individual *obj);
private:
    void make_new_chromosome();
    void evaluate();
};

#endif
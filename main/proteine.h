#ifndef PROTEINE_H
#define PROTEINE_H
#include <iostream>
#include "result.h"
using namespace std;
class proteine
{
public:

    string name;

    proteine();
    proteine(string s, int p);
    proteine(result& s);
    ~proteine();
    int getscore();
    void addscore();
    int score;
};

#endif // PROTEINE_H

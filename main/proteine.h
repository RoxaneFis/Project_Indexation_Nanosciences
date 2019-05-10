#ifndef PROTEINE_H
#define PROTEINE_H
#include <iostream>
using namespace std;
class proteine
{
public:

    string name;

    proteine();
    proteine(string s, int p);
    ~proteine();
    int getscore();

private:
    int score;
};

#endif // PROTEINE_H

#include "proteine.h"

proteine::proteine()
{

}
proteine::proteine(string s, int p){
    name= s;
    score=p;
}
proteine::~proteine(){

}
proteine::proteine(result& s){
    name=s.name;
    score=0;

}

int proteine::getscore(){
    return score;
}
void proteine::addscore(){
    score=score+1;
}

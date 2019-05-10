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
int proteine::getscore(){
    return score;
}

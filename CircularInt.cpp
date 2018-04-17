#include<iostream>
#include "CircularInt.hpp"
using namespace std;
CircularInt::CircularInt(int s,int e){
    this->s=s;
    this->e=e;
    this->cur=s;
}


/*CircularInt& operator+=(int num) const{
    this->s+=num;
    return this->s;
}
*/
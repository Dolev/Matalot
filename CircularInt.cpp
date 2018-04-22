#include<iostream>
#include "CircularInt.hpp"
using namespace std;
CircularInt::CircularInt(int s,int e){
    this->s=s;
    this->e=e;
    this->cur=s;
}


CircularInt& CircularInt:: operator+=(int num) {
      this->cur+=num;
      cur=cur%e;
        return *this;
    }
 CircularInt& CircularInt:: operator++(int num) {
    cur++;
     return *this;
 }
//   CircularInt::CircularInt& operator++(int) { 
//       this->cur++;
//         return *this;
//     }
      const CircularInt CircularInt:: operator-()  {
        return CircularInt{e-cur,e};
    }
    

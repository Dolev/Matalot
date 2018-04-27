#include<iostream>
#include "CircularInt.hpp"
#include<string>
using namespace std;
CircularInt::CircularInt(int s,int e){
    this->s=s;
    this->e=e;
    this->cur=s;
}

void CircularInt::fix(){ //function to fixthe cur in the range

    int y = e-s+1;

    if(cur>= s && cur<= e){

        return;

    }

    while(cur < s) cur += y;

    while(cur > e) cur -= y;

}


CircularInt& CircularInt:: operator+=(int num) {
      cur=cur+num;
      fix();
        return *this;
    }
    
CircularInt& CircularInt:: operator-=(int num) {
     cur=cur-num;
     fix();
    return *this;
    }
    
CircularInt& CircularInt:: operator *=(int num){
     cur=cur*num;
     fix();
     return *this;
 }
 
 CircularInt& CircularInt::operator/=(int num){
     if(num==0){throw string("eror:we can't divide in zero!");}
     if(cur%num!=0){throw string("There is no number x in {"+to_string(s)+","+to_string(e)+"} such that x*"+to_string(num)+"="+to_string(cur)); }
     cur/=num;
     fix();
     return *this;
 }
 
 //_______________________________________________________________________

    
 const CircularInt CircularInt:: operator++(int num) {//postfix
    CircularInt cpy(*this);
    ++cur;
    fix();
     return cpy;
 }
 CircularInt& CircularInt:: operator++() {//perfix
    cur++;
     return *this;
 }
 const CircularInt CircularInt:: operator--(int num) {//postfix
    CircularInt cpy(*this);
    --cur;
     return cpy;
 }
 CircularInt& CircularInt:: operator--() {//perfix
    cur--;
     return *this;
 }
 
 //_______________________________________________________________________hour and hour
 
 const CircularInt CircularInt:: operator+(const CircularInt& c){
     CircularInt cpy(*this);
     cpy.cur+=c.cur;
     cpy.fix();
     return cpy;
 }
  const CircularInt CircularInt:: operator*( const CircularInt& c){
     CircularInt cpy(*this);
     cpy.cur*=c.cur;
     cpy.fix();
     return cpy;
 }
 const CircularInt CircularInt:: operator/(const CircularInt& c){
    if(c.cur==0){throw string("eror:we can't divide in zero!");}
    if(cur%c.cur!=0){throw string("There is no number x in {"+to_string(s)+","+to_string(e)+"} such that x*"+to_string(c.cur)+"="+to_string(cur)); }
    CircularInt cpy(*this);
    cpy.cur/=c.cur;
    cpy.fix();
    return cpy;
 }
 const CircularInt CircularInt:: operator%(const CircularInt& c){
     return CircularInt{cur%c.cur,e};
 }
 const CircularInt CircularInt:: operator-(const CircularInt& c){
      CircularInt cpy(*this);
     cpy.cur-=c.cur;
     cpy.fix();
     return cpy;
 }
 
 
 //_______________________________________________________________________
    CircularInt CircularInt:: operator-()  {
    CircularInt cpy(*this); 
    cpy.cur = cpy.e - cpy.cur;
    cpy.fix();
    return cpy;
        }
        
 //_______________________________________________________________________hour and num
 
  const CircularInt CircularInt:: operator/(int num){
  if(num==0){throw string("eror:we can't divide in zero!");}
  if(cur%num!=0){throw string("There is no number x in {"+to_string(s)+","+to_string(e)+"} such that x*"+to_string(num)+"="+to_string(cur)); }

  return CircularInt{cur/num,e};
  }
 
  const CircularInt CircularInt::operator+(int num){//cur/number
  CircularInt cpy(*this);
  cpy.cur+=num;
  cpy.fix();
  return cpy;
  }
  const CircularInt CircularInt::operator-(int num){//cur/number
  CircularInt cpy(*this);
  cpy.cur-=num;
  cpy.fix();
  return cpy;
  }
  const CircularInt CircularInt::operator*(int num){//cur/number
  CircularInt cpy(*this);
  cpy.cur*=num;
  cpy.fix();
  return cpy;
  }
 
//_______________________________________________________________________
 
 CircularInt& CircularInt:: operator+=(const CircularInt& c){//this cur+c.cur
     cur=cur+c.cur;
     fix();
     return *this;
 }
 
 CircularInt& CircularInt:: operator-=(const CircularInt& c){//this cur-c.cur
     cur=cur-c.cur;
     fix();
     return *this;
 }
 
 CircularInt& CircularInt::operator*=(const CircularInt& c){//this cur*c.cur
     cur=cur*c.cur;
     fix();
     return *this;
}


 CircularInt& CircularInt:: operator/=(const CircularInt& c){//this cur/c.cur
 if(c.cur==0){throw string("eror:c.cur=0");}
 if(cur%c.cur!=0){throw string("eror:cur/c.cur not int");}
 cur=cur/c.cur;
 return *this;
 }
 
 
//_______________________________________________________________________
    CircularInt& CircularInt:: operator=(const CircularInt& c){
     e=c.e;
     s=c.s;
     cur=c.cur;
     return *this;
    }
    
    CircularInt& CircularInt::operator=(int num){
     cur=num;
     fix();
     return *this;
    }
 

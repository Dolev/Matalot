#include<iostream>
#include "CircularInt.hpp"
#include<string>
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
    
CircularInt& CircularInt:: operator-=(int num) {
      this->cur-=num;
      cur=cur%e;
      if(cur<=s) {throw string("eror:num>cur");}
        return *this;
    }
    
 CircularInt& CircularInt:: operator++(int num) {
    CircularInt& cpy=*this;
    cur++;
     return cpy;
 }
 CircularInt& CircularInt:: operator++() {
    cur++;
     return *this;
 }
 CircularInt& CircularInt:: operator--(int num) {
    CircularInt& cpy=*this;
    cur--;
     return cpy;
 }
 CircularInt& CircularInt:: operator--() {
    cur--;
     return *this;
 }
 
 CircularInt CircularInt:: operator+(const CircularInt& c){
     return CircularInt{(cur+c.cur)%e,e};
 }
 
 CircularInt& CircularInt:: operator *=(int num){
     cur=(cur*num)%e;
     return *this;
 }
 
 
 const CircularInt CircularInt:: operator-()  {
        return CircularInt{e-cur,e};
        }
  CircularInt CircularInt:: operator/(int num){
     if(cur%num!=0){throw string("There is no number x in {"+to_string(s)+","+to_string(e)+"} such that x*"+to_string(num)+"="+to_string(cur)); }
     return CircularInt{cur/num,e};
 }
 CircularInt& CircularInt:: operator=(const CircularInt& c){
     e=c.e;
     s=c.s;
     cur=c.cur;
     return *this;
 }
 CircularInt CircularInt:: operator*( const CircularInt& c){
    return CircularInt{(cur*c.cur)%e,e}; 
 }
 CircularInt CircularInt:: operator/(const CircularInt& c){
     return CircularInt{(cur/c.cur),e};
 }
 CircularInt CircularInt:: operator%(const CircularInt& c){
     return CircularInt{cur%c.cur,e};
 }
 
 CircularInt& CircularInt:: operator+=(const CircularInt& c){//this cur+c.cur
     cur=(cur+c.cur)%e;
     return *this;
 }
 
 CircularInt& CircularInt:: operator-=(const CircularInt& c){//this cur-c.cur
 cur=(cur-c.cur);
 if(cur<s){throw string("eror:the cur is < s");}
 return *this;
 }
 
 CircularInt& CircularInt::operator*=(const CircularInt& c){//this cur*c.cur
cur=(cur*c.cur)%e;
return *this;
}


 CircularInt& CircularInt:: operator/=(const CircularInt& c){//this cur/c.cur
 if(c.cur==0){throw string("eror:c.cur=0");}
 if(cur%c.cur!=0){throw string("eror:cur/c.cur not int");}
 cur=cur/c.cur;
 return *this;
 }
 
 

    
 



    

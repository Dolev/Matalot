#include<iostream>
using namespace std;
class CircularInt {
    private:
       int s,e;
    public:
       int cur;
       CircularInt(int s,int e);
       CircularInt& operator+=(int num);
       friend ostream& operator<< (ostream& os, const CircularInt& c);
       CircularInt& operator++(int) ;
       const CircularInt operator-();
       friend CircularInt operator-(const int& num, CircularInt& c);
       
      
     

       

};
 
   
   inline ostream& operator<< (ostream& os, const CircularInt& c) {
    os << c.cur << endl;
    return os;
    }
   inline CircularInt operator-(const int& num, CircularInt& c){// int-hour
   c.cur=((num+12)-c.cur)%c.e;
   return c;
   }




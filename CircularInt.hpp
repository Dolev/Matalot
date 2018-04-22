#include<iostream>
using namespace std;
class CircularInt {
    private:
       int s,e;
    public:
       int cur;
       CircularInt(int s,int e);
       CircularInt& operator+=(int num);
       CircularInt& operator++(int) ;
       CircularInt operator+(const CircularInt& c);//hour+hour
       const CircularInt operator-();
       CircularInt& operator *=(int num);
       CircularInt operator/(int num);
       
       //friend function
       friend ostream& operator<< (ostream& os, const CircularInt& c);
       friend CircularInt operator-(const int& num, CircularInt& c);
       
    //   friend CircularInt operator+(const CircularInt& c1, const CircularInt& c2);
      
     

       

};
 
   
   inline ostream& operator<< (ostream& os, const CircularInt& c) {
    os << c.cur << endl;
    return os;
    }
   inline CircularInt operator-(const int& num, CircularInt& c){// int-hour
   c.cur=((num+12)-c.cur)%c.e;
   return c;
   }
//   inline friend CircularInt operator+(const CircularInt& c1, const CircularInt& c2){//hour+hour
//     return CircularInt{(c1.cur+c2.cur)%c1.e,c1.e}
//   }




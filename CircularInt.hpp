#include<iostream>
using namespace std;
class CircularInt {
    private:
       int s,e;
    public:
       int cur;
       CircularInt(int s,int e);
       
       CircularInt& operator++(int) ;//++postfix
       CircularInt& operator++();//++perfix
       CircularInt& operator--(int);//--postfix
       CircularInt& operator--();//--perfix
       
       CircularInt operator*( const CircularInt& c);//a*b
       CircularInt operator+(const CircularInt& c);//hour+hour
       CircularInt operator%(const CircularInt& c);
       const CircularInt operator-();//e-cur
       CircularInt operator/(int num);//cur/number
       CircularInt operator /(const CircularInt& c);//a/b
       CircularInt& operator=(const CircularInt& c);//a=b
       
       
       CircularInt& operator *=(int num);//(number*cur)%e
       CircularInt& operator+=(int num);//cur+number
       CircularInt& operator-=(int num);//cur-number
       
       CircularInt& operator-=(const CircularInt& c);//this cur-c.cur
       CircularInt& operator+=(const CircularInt& c);//this cur+c.cur
       CircularInt& operator*=(const CircularInt& c);//this cur*c.cur
       CircularInt& operator/=(const CircularInt& c);//this cur/c.cur
       
       
       
       //friend function
       friend ostream& operator<< (ostream& os, const CircularInt& c);//output
       friend CircularInt operator-(const int& num, CircularInt& c);
       friend bool operator==(const CircularInt& c1, const CircularInt& c2);//a=b?
       friend bool operator!=(const CircularInt& c1, const CircularInt& c2);//a!=b?
       friend bool operator>(const CircularInt& c1, const CircularInt& c2);//a>b?
       friend bool operator<(const CircularInt& c1, const CircularInt& c2);//a<b
       friend bool operator>=(const CircularInt& c1, const CircularInt& c2);//a>=b
       friend bool operator<=(const CircularInt& c1, const CircularInt& c2);//a<=b
       friend bool operator!(const CircularInt& c1);//!a
       friend bool operator&&(const CircularInt& c1, const CircularInt& c2);//a&&b
       friend bool operator||(const CircularInt& c1, const CircularInt& c2);//a||b
       

       

       
   
      
     

       

};
 
   
   inline ostream& operator<< (ostream& os, const CircularInt& c) {
    os << c.cur << endl;
    return os;
    }
    
   inline CircularInt operator-(const int& num, CircularInt& c){// int-hour
   c.cur=((num+12)-c.cur)%c.e;
   return c;
   }
   
   inline bool operator==(const CircularInt& c1, const CircularInt& c2) {
    
    return ((c1.s==c2.s)&&(c1.e==c2.e)&&(c1.cur==c2.cur));
   }
   
  inline bool operator!=(const CircularInt& c1, const CircularInt& c2){
      return((c1.s!=c2.s)||(c1.e!=c2.e)||(c1.cur!=c2.cur));
   }
  
  inline bool operator>(const CircularInt& c1, const CircularInt& c2){
      return(c1.cur>c2.cur);
  }
  
  inline bool operator<(const CircularInt& c1, const CircularInt& c2){
      return(c1.cur<c2.cur);
  }
  
  inline bool operator>=(const CircularInt& c1, const CircularInt& c2){
      return(c1.cur>=c2.cur);
  }
  
  inline bool operator<=(const CircularInt& c1, const CircularInt& c2){
      return(c1.cur<=c2.cur);
  }
  
  inline bool operator!(const CircularInt& c1){
      return(!c1.cur);
  }
  
  inline bool operator&&(const CircularInt& c1, const CircularInt& c2){
      return(c1.cur&&c2.cur);
  }
  
  inline bool operator||(const CircularInt& c1, const CircularInt& c2){
      return(c1.cur||c2.cur);
  }
   





#include<iostream>
using namespace std;
#include<string>
class CircularInt {
    private:
       int s,e;
       void fix();
    public:
       int cur;
       CircularInt(int s,int e);
       
       const CircularInt operator++(int) ;//++postfix
       CircularInt& operator++();//++perfix
       const CircularInt operator--(int);//--postfix
       CircularInt& operator--();//--perfix
       
       const CircularInt operator*( const CircularInt& c);//a*b
       const CircularInt operator+(const CircularInt& c);//hour+hour
       const CircularInt operator-(const CircularInt& c);
       const CircularInt operator/(const CircularInt& c);//a/b
       
       const CircularInt operator+(const int num);//cur+num
       const CircularInt operator/(const int num);//cur/number
       const CircularInt operator-(const int num);//cur/number
       const CircularInt operator*(const int num);//cur/number
       

       const CircularInt operator%(const CircularInt& c);
       CircularInt operator-();//e-cur
       CircularInt& operator=(const CircularInt& c);//a=b
       CircularInt& operator=(int num);//a=num;
       
      
       
       CircularInt& operator *=(int num);//(number*cur)%e
       CircularInt& operator+=(int num);//cur+number
       CircularInt& operator-=(int num);//cur-number
       CircularInt& operator/=(int num);//cur/number
       
       
       CircularInt& operator-=(const CircularInt& c);//this cur-c.cur
       CircularInt& operator+=(const CircularInt& c);//this cur+c.cur
       CircularInt& operator*=(const CircularInt& c);//this cur*c.cur
       CircularInt& operator/=(const CircularInt& c);//this cur/c.cur
       
       
       
       //friend function
       friend ostream& operator<< (ostream& os, const CircularInt& c);//output
       friend istream& operator>> (istream& input,  CircularInt& c);  // (cin)
       
       
       friend const CircularInt operator-(const int& num, CircularInt& c);
       friend const CircularInt operator+ (const int& num, CircularInt& c); 
       friend const CircularInt operator* (const int& num, CircularInt& c);
       friend const CircularInt operator/ (const int& num, CircularInt& c);
       
       
       
       
       friend bool operator==(const CircularInt& c1, const CircularInt& c2);//a=b?
       friend bool operator!=(const CircularInt& c1, const CircularInt& c2);//a!=b?
       friend bool operator>(const CircularInt& c1, const CircularInt& c2);//a>b?
       friend bool operator<(const CircularInt& c1, const CircularInt& c2);//a<b
       friend bool operator>=(const CircularInt& c1, const CircularInt& c2);//a>=b
       friend bool operator<=(const CircularInt& c1, const CircularInt& c2);//a<=b
       friend bool operator!(const CircularInt& c1);//!a
       friend bool operator&&(const CircularInt& c1, const CircularInt& c2);//a&&b
       friend bool operator||(const CircularInt& c1, const CircularInt& c2);//a||b
       
       // int and CircularInt
       friend bool operator != ( const int& i,const CircularInt& c1);
       friend bool operator == ( const int& i,const CircularInt& c1);
       friend bool operator <= ( const int& i,const CircularInt& c1);
       friend bool operator >= ( const int& i,const CircularInt& c1);
       friend bool operator < ( const int& i,const CircularInt& c1);
       friend bool operator > ( const int& i,const CircularInt& c1);
       //CircularInt and int 
       friend bool operator == ( const CircularInt& c1,const int& i);
       friend bool operator != ( const CircularInt& c1,const int& i);
       friend bool operator >= ( const CircularInt& c1,const int& i);
       friend bool operator <= ( const CircularInt& c1,const int& i);
       friend bool operator > ( const CircularInt& c1,const int& i);
       friend bool operator < ( const CircularInt& c1,const int& i);
       

       

       
   
      
     

       

};
 
   
   inline ostream& operator<< (ostream& os, const CircularInt& c) {
    os << c.cur << endl;
    return os;
    }
    inline istream& operator>> (istream& input,  CircularInt& c){ // (cin)
    int x;
        input >> x ;
        if(x<c.s || x>c.e){
    throw string("The number "+to_string(x)+" is not in the range )");
        }
        else{
        c.cur=x;           
        }
        return input;
    }
    
   inline const CircularInt operator-(const int& num, CircularInt& c){// int-hour
   c.cur=num-c.cur;
   c.fix();
   return c;
   }
//   inline CircularInt operator-(const int& num, CircularInt& c){// int-hour
//   c.cur=num-c.cur;
//   c.fix();
//   return c;
//   }
  inline const CircularInt operator+ (const int& num, CircularInt& c){
    c.cur+=num;
    c.fix();
    return c;
  }
  inline const CircularInt operator* (const int& num, CircularInt& c){
    c.cur*=num;
    c.fix();
    return c;
  }
  inline const CircularInt operator/(const int& num, CircularInt& c){
    CircularInt cpy(c);
    int d=(c.e-c.s)+1;
    cpy.cur=(num/cpy.cur)%d;
    if (cpy.cur<=0){cpy.cur+=d;}
    return cpy;
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
   //int and CircularInt____________________________________________________________________________________
   inline bool operator != ( const int& i,const CircularInt& c1){
          return(i!=c1.cur);
   }
   inline bool operator == ( const int& i,const CircularInt& c1){
          return(i==c1.cur);
   }
   inline bool operator <= ( const int& i,const CircularInt& c1){
          return(i<=c1.cur);
   }
   inline bool operator >= ( const int& i,const CircularInt& c1){
         return(i>=c1.cur);
   } 
   inline bool operator > ( const int& i,const CircularInt& c1){
         return(i>c1.cur);
   } 
   inline bool operator < ( const int& i,const CircularInt& c1){
         return(i<c1.cur);
   } 
   //CircularInt and int_____________________________________________________________________________________ 
   inline bool operator != ( const CircularInt& c1,const int& i){
          return(c1.cur!=i);
   }
    inline bool operator == ( const CircularInt& c1,const int& i){
          return(c1.cur==i);
   }
    inline bool operator <= ( const CircularInt& c1,const int& i){
          return(c1.cur<=i);
   }
    inline bool operator >= ( const CircularInt& c1,const int& i){
          return(c1.cur>=i);
   }
    inline bool operator > ( const CircularInt& c1,const int& i){
          return(c1.cur>i);
   }
    inline bool operator < ( const CircularInt& c1,const int& i){
          return(c1.cur<i);
   }





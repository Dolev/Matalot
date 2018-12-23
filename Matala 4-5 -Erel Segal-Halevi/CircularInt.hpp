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
       
       const CircularInt operator*( const CircularInt& c);//hour*hour
       const CircularInt operator+(const CircularInt& c);//hour+hour
       const CircularInt operator-(const CircularInt& c);//hour-hour
       const CircularInt operator/(const CircularInt& c);//hour/hour
       
       const CircularInt operator+(const int num);//hour+num
       const CircularInt operator/(const int num);//hour/num
       const CircularInt operator-(const int num);//hour-num
       const CircularInt operator*(const int num);//hour*number
       

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
       
       
       
       //friend function:
       friend ostream& operator<< (ostream& os, const CircularInt& c);//output
       friend istream& operator>> (istream& input,  CircularInt& c);  // (cin)
       
       
       friend const CircularInt operator-(const int& num, CircularInt& c);//num-hour
       friend const CircularInt operator+ (const int& num, CircularInt& c);//num+hour
       friend const CircularInt operator* (const int& num, CircularInt& c);//num*hourv
       friend const CircularInt operator/ (const int& num, CircularInt& c);//num/hour
       
       
       
       
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
       friend bool operator != ( const int& i,const CircularInt& c1);//i!=hour
       friend bool operator == ( const int& i,const CircularInt& c1);//i==hour
       friend bool operator <= ( const int& i,const CircularInt& c1);//i<=hour
       friend bool operator >= ( const int& i,const CircularInt& c1);//i>=hour
       friend bool operator < ( const int& i,const CircularInt& c1);//i<hour
       friend bool operator > ( const int& i,const CircularInt& c1);//i>hour
       //CircularInt and int 
       friend bool operator == ( const CircularInt& c1,const int& i);//hour==i
       friend bool operator != ( const CircularInt& c1,const int& i);//hour!=i
       friend bool operator >= ( const CircularInt& c1,const int& i);//hour>=i
       friend bool operator <= ( const CircularInt& c1,const int& i);//hour<=i
       friend bool operator > ( const CircularInt& c1,const int& i);//hour>i
       friend bool operator < ( const CircularInt& c1,const int& i);//hour<i

   };

   inline ostream& operator<< (ostream& os, const CircularInt& c) {//(cout)
     int ret=c.cur;
     return os<<to_string(ret);
    }
    inline istream& operator>> (istream& input,  CircularInt& c){ // (cin)
    int x;
    input>>x;
    if(x<c.s || x>c.e){
    throw string("The number "+to_string(x)+" is not in the range )");
        }
        else{
        c.cur=x;           
        }
        return input;
    }
    
   inline const CircularInt operator-(const int& num, CircularInt& c){// int-hour
   CircularInt cpy(c);
   int d=(cpy.e-cpy.s)+1;
   cpy.cur=(num-cpy.cur)%d;
   if(cpy.cur<cpy.s){
       cpy.cur+=d;
   }
   return cpy;
   }

  inline const CircularInt operator+ (const int& num, CircularInt& c){//num+hour
    CircularInt cpy(c);
   int d=(cpy.e-cpy.s)+1;
   cpy.cur=(cpy.cur+num)%d;
   if(cpy.cur<cpy.s){
       cpy.cur+=d;
   }
   return cpy;
  }
  inline const CircularInt operator* (const int& num, CircularInt& c){//num*hour
    CircularInt cpy(c);
   int d=(cpy.e-cpy.s)+1;
   cpy.cur=(num*cpy.cur)%d;
   if(cpy.cur<cpy.s){
       cpy.cur+=d;
   }
   return cpy;
  }
  inline const CircularInt operator/(const int& num, CircularInt& c){//num/c
    CircularInt cpy(c);
    int d=(cpy.e-cpy.s)+1;
    cpy.cur=(num/cpy.cur)%d;
    if(cpy.cur<cpy.s){
    cpy.cur+=d;
    }
     return cpy;
  }
   
   //__________________________________________________________________________________________________
   
   
   
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





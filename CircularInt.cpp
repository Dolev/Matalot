inline CircularInt operator-(const int& num, CircularInt& c){// int-hour
   c.cur=num-c.cur;
   c.fix();
   return c;
   }
   inline CircularInt operator+ (const int& num, CircularInt& c){
    c.cur+=num;
    c.fix();
    return c;
   }
   inline CircularInt operator* (const int& num, CircularInt& c){
    c.cur*=num;
    c.fix();
    return c;
   }
   inline CircularInt operator/ (const int& num, CircularInt& c){
    if(c.cur==0){throw string(" eror:we can't divide in zero!");}
    if(num%c.cur!=0){throw string(" eror");}
    c.cur=num/c.cur;
    c.fix()
    return c;
   }
   

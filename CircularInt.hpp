#include<iostream>
using namespace std;
class CircularInt {
    private:
       int s,e;
    public:
       int cur;
       CircularInt(int s,int e);
       friend ostream& operator<< (ostream& os, const CircularInt& c);
       friend const& operator<< (const CircularInt& c);
       

};
inline ostream& operator<< (ostream& os, const CircularInt& c) {
    os << c.cur << endl;
    return os;
}
inline const CircularInt operator+=(const CircularInt& c,int num) {
    return CircularInt();
}

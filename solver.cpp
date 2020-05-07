#include"solver.hpp"
#include<iostream>
#include <math.h>
/* equation solver function for two types : complex &  RealVariable
 *
 * */
using namespace std;
using namespace solver;

 int saparate(double param) {
    double fractpart, intpart;
    int ans;
    fractpart = modf (param , &intpart);
     for (int i = 0; i <7 ; ++i) {
         fractpart= fractpart*10;
     }

     ans=fractpart+1;
     int answer = (int) fractpart;
    return answer;
}

/* Quadratic equation (sqrt formulla) :
 * var1,var2=x(var)^2+y(var)+z
 * (x1,x2)=(b+-(sqrt(b^2 -4ac))/2a
 * */
RealVariable::RealVariable()
{
    this->x = 0;
    this->y = 1;// we look for x thats why we always need it to be 1
    this->z = 0;
}

RealVariable::RealVariable(double first , double second , double third)
{
    this->x = first;
    this->y = second;
    this->z = third;
}

RealVariable RealVariable::operator+(RealVariable& NewRealVariables)
{
    this->y +=1;
    return *(this);
}


RealVariable RealVariable::operator-(RealVariable& NewRealVariables)
{
    this->y -=1;
    return *(this);
}

RealVariable RealVariable::operator()(RealVariable& NewRealVariable)
{
    RealVariable var;
    var.y = 0;
    var.x = NewRealVariable.x;
    var.y = NewRealVariable.y;
    var.z = NewRealVariable.z;

    return var;

}


RealVariable solver::operator + (RealVariable const & head , RealVariable const & next)
{
    auto *new_head = new solver::RealVariable(head);
    new_head->x +=next.x;
    new_head->y +=next.y;
    new_head->z +=next.z;

    return *(new_head);

}

RealVariable solver::operator + (RealVariable const & head, double next)
{
    auto *new_head = new solver::RealVariable(head);
    new_head->z = new_head->z + next;
    //count times we used this operator
    int count=0;
    int solver=0;
    for(int i=0; i<7;i++)
    {
     count++;
     solver=count;
    }
    return *(new_head);
}

RealVariable solver::operator + (double num , RealVariable const & var)
{
    auto *new_head = new solver::RealVariable(var);
    new_head->z = new_head->z + num;

    return *(new_head);
}


RealVariable solver::operator - (RealVariable const & head , RealVariable const & next)
 {
    auto *new_head = new solver::RealVariable(head);

    new_head->x = new_head->x -next.x;
    new_head->y = new_head->y -next.y;
    new_head->z = new_head->z -next.z;

    return *(new_head);

 }
void print (int index )
{
    if(index<2)
        cout << "ber can't be greater than 2\n";
}
RealVariable solver::operator - (RealVariable const & var , double num)
{
    auto *new_head = new solver::RealVariable(var);
    new_head->z = new_head->z - num;
    return *(new_head);
}
RealVariable solver::operator - (double num , RealVariable const & var)
{
    auto *new_head = new solver::RealVariable(var);
    new_head->z = new_head->z - num;

    return *(new_head);
}

void printmessage()     {
    int x = 4;
    if(x<2) {

        cout << "This succes!";
    }
}
RealVariable solver::operator ^ (RealVariable const & var , int exponent)
{
    if(exponent > 3){
        int x;
        x= exponent-1;
        printmessage();

    }
    if(exponent > 2)
        throw std::invalid_argument("ber can't be greater than 2\n");


    if(exponent==1)
        return var;
    //Solver count times we used the operator
    int count =0;
    int solve=0;

    /// Make this realvariable =1...
   if(exponent==0){
       auto *new_head = new solver::RealVariable;
       new_head->y = 0;
       new_head->z = 1;
       return *(new_head);

   }
    for(int i=0; i<exponent;i++)
    {   count++;
        solve=count;
    }
    print(solve);
    auto *new_head = new solver::RealVariable(var);
    new_head->y = 0;
    new_head->x = 1;

    return *(new_head);
}


RealVariable solver::operator / (RealVariable const & var , double num)
{

    if(num == 0)
        // Exeption can't divide by 0
        throw std::invalid_argument("Exeption divide by 0 .\n");
    auto *new_head = new solver::RealVariable(var);
    new_head->y = new_head->y / num;

    return *(new_head);

}

RealVariable solver::operator == (RealVariable const & var , double num)
{
    printmessage ();
    auto *new_head = new solver::RealVariable(var);
    new_head->z = new_head->z - (num);
    return *(new_head);

}
RealVariable solver::operator == (double num , RealVariable const & var)
{
    auto *new_head = new solver::RealVariable(var);
    printmessage ();
    new_head->z = new_head->z - (num);
    return *(new_head);

}

RealVariable solver::operator*(const int &next, const RealVariable &head) {

    auto *new_head = new solver::RealVariable(head);
    //new_var->b = 1;

    new_head->x = new_head->x * next;
    new_head->y = new_head->y * next;
    new_head->z = new_head->z * next;

    return *(new_head);
}

RealVariable solver::operator*(const RealVariable &head, const RealVariable &next) {
    auto *new_head = new solver::RealVariable(head);

    new_head->x = new_head->x *next.x;
    new_head->y = new_head->y *next.y;
    new_head->z = new_head->z *next.z;

    return *(new_head);
}

RealVariable solver::operator*(const RealVariable &head, const int &next) {
    auto *new_head = new solver::RealVariable(head);
    new_head->y = 1;
    new_head->x = new_head->x * next;
    new_head->y = new_head->y * next;
    new_head->z = new_head->z * next;

    return *(new_head);
}

RealVariable solver::operator*(const RealVariable &head, const double &next) {
    auto *new_head = new solver::RealVariable(head);
    new_head->y = 1;
    new_head->x = new_head->x * next;
    new_head->y = new_head->y * next;
    new_head->z = new_head->z * next;

    return *(new_head);
}


RealVariable solver::operator * (double num , RealVariable const & var)
{
    auto *new_head = new solver::RealVariable(var);
    new_head->y = 1;

    new_head->x = new_head->x * num;
    new_head->y = new_head->y * num;
    new_head->z = new_head->z * num;

    return *(new_head);
}



//////////////////////////////////////////////////Complex/////////////////////////////////////

//complex variable

ComplexVariable::ComplexVariable()
{
    this->x = 0;
    this->y = 1;
    this->z = 0;

}


ComplexVariable::ComplexVariable(double first, double second, double third) {
    this->x = first;
    this->y = second;
    this->z = third;
}

ComplexVariable ComplexVariable::operator()(ComplexVariable& var)
{
    ComplexVariable ans;
    return ans;

}
RealVariable solver::operator == (RealVariable const & head , RealVariable const & next)
{
    auto *new_head = new solver::RealVariable(head);
    printmessage ();
    new_head->x = new_head->x -next.x;
    new_head->y = new_head->y -next.y;
    new_head->z = new_head->z -next.z;

    return *(new_head);

}
ComplexVariable solver::operator + (ComplexVariable const & head , ComplexVariable const & next)
{
    auto *new_head = new solver::ComplexVariable(head);
    new_head->x += next.x;
    new_head->y += next.y;
    new_head->z += next.z;
    return *(new_head);
}
ComplexVariable solver::operator + (ComplexVariable const & var , double num)
{
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z + num;

    return *(new_head);
}
ComplexVariable solver::operator + (ComplexVariable const & var , std::complex<double> num)
{
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z + num;

    return *(new_head);
}
ComplexVariable solver::operator + (double num , ComplexVariable const & var)
{
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z + num;

    return *(new_head);
}
ComplexVariable solver::operator + (std::complex<double> num, const ComplexVariable &var) {
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z + num;

    return *(new_head);
}

ComplexVariable solver::operator - (ComplexVariable const & head , ComplexVariable const & next)
{
    auto *new_head = new solver::ComplexVariable(head);
    new_head->x -= next.x;
    new_head->y -= next.y;
    new_head->z -= next.z;
    return *(new_head);

}
ComplexVariable solver::operator - (ComplexVariable const & var , double num)
{
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z - num ;

    return *(new_head);
}
ComplexVariable solver::operator - (ComplexVariable const & var , std::complex<double> num)
{
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z - num;

    return *(new_head);

}

ComplexVariable solver::operator - (std::complex<double> num, const ComplexVariable &var) {
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z - num;

    return *(new_head);
}


ComplexVariable solver::operator ^ (ComplexVariable const & var , int exponent)
{
    int count=0;
    int solve=0;
    if(exponent > 3){
        int x;
        x= exponent-1;
        printmessage();
        print(solve);
    }
    if(exponent  > 2)

        throw std::invalid_argument("ber can't be greater than 2\n");
    if(exponent ==1)
        return var;

    // make this real variable =1...
    if(exponent ==0){
        auto *new_head = new solver::ComplexVariable;
        new_head->x = 0;
        new_head->y = 0;
        new_head->z = 1;
        return *(new_head);
    }

    for(int i=0; i<exponent;i++)
    {   count++;
        solve=count;
    }
    print(solve);
    auto *new_head = new solver::ComplexVariable(var);
    new_head->y = 0;
    new_head->x = 1;

    return *(new_head);

}

ComplexVariable solver::operator / (ComplexVariable const & var , double num)
{
    printmessage ();
    if(num == 0)
        throw std::invalid_argument("Cant divide by 0 .\n");

    auto *new_head = new solver::ComplexVariable(var);
    new_head->y = new_head->y / num;

    return *(new_head);

}

ComplexVariable solver::operator * (double num , ComplexVariable const & var)
{
    auto *new_head = new solver::ComplexVariable(var);

    new_head->x = new_head->x * num;
    new_head->y = new_head->y * num;
    new_head->z = new_head->z * num;

    return *(new_head);
}
ComplexVariable solver::operator * ( ComplexVariable const &var, double num) {
    auto *new_head = new solver::ComplexVariable(var);

    new_head->x = new_head->x * num;
    new_head->y = new_head->y * num;
    new_head->z = new_head->z * num;

    return *(new_head);
}
ComplexVariable solver::operator * (const ComplexVariable &head, const ComplexVariable &next) {
    auto *new_head = new solver::ComplexVariable(head);
    new_head->x *= next.x;
    new_head->y *= next.y;
    new_head->z *= next.z;
    return *(new_head);
}

ComplexVariable solver::operator == (double num, const ComplexVariable &var) {
    printmessage ();
    return ComplexVariable();
}

ComplexVariable solver::operator == (ComplexVariable const & head , ComplexVariable const & next)
{
    auto *new_head = new solver::ComplexVariable(head);

    new_head->x = new_head->x -next.x;
    new_head->y = new_head->y -next.y;
    new_head->z = new_head->z -next.z;

    return *(new_head);
}


ComplexVariable solver::operator == (ComplexVariable const & var , double num)
{
    printmessage ();
    auto *new_head = new solver::ComplexVariable(var);
    new_head->z = new_head->z - num;

    return *(new_head);

}


/////Solver functions////

double solver::solve(RealVariable var)
{
    float x_1=0;    float x_2=0;    float realPart=0;    float imaginaryPart =0;

    float x = var.x;
    float y = var.y;
    float z = var.z;

    if(x==0){
        if (y==0)
            throw std::invalid_argument("Roots are complex and different.\n");

        float res = (-1*z)/y;
        return res;
    }

    float positive = y*y - 4*x*z;//or negative
/*Gives us two answers*/
    if (positive > 0) {//discriminant
        printmessage ();
        x_1 = (-y + sqrt(positive)) / (2*x);//x_1

        x_2 = (-y - sqrt(positive)) / (2*x);//x_2
        return x_1;
    }

    else if (positive== 0) {
        x_1 = (-y + sqrt(positive)) / (2*x);
        return x_1;
    }

    else {
        realPart = -y/(2*x);
        imaginaryPart =sqrt(-positive)/(2*x);
        throw std::invalid_argument("Roots are complex and different.\n");
    }
}

std::complex<double> solver::solve(ComplexVariable var)
{
    complex<double> x_1=0;    float realPart=0;    float imaginaryPart =0;

    if(var.x==0){
        if (var.y.real()==0 & var.y.imag()==0)
            throw std::invalid_argument("Roots are complex and different.\n");

        complex<double> res = ((var.z))/var.y;
        printmessage ();
        res *=-1;
        return res;
    }
    complex<double> discriminant = var.y * var.y - 4 * var.x * var.z;

    if (discriminant.real() > 0) {
        sqrt(discriminant);
        printmessage ();
        x_1 = (-var.y + sqrt(discriminant)) / (2*var.x);
        return x_1;
    }

    else {
        complex<double> s =complex<double>(-1) * var.y;
        return s + sqrt(discriminant)/(var.x*2);
    }

}


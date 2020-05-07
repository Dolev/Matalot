
#pragma once

#include<iostream>
#include<complex>

namespace solver
{
    /* ax^2 + bx + c = 0 */
    class RealVariable
    {
    public:
        double x , y , z ;

        /* empty constructor */
        RealVariable();
        RealVariable(double first, double second , double third);
        RealVariable operator+(RealVariable& var);
        RealVariable operator-(RealVariable& var);
        RealVariable operator()(RealVariable& var);

        friend RealVariable operator + (RealVariable const & var1 , RealVariable const & var2);
        friend RealVariable operator + (RealVariable const & var , double num);
        friend RealVariable operator + (double num , RealVariable const & var);

        friend RealVariable operator - (RealVariable const & head , RealVariable const & next);
        friend RealVariable operator - (RealVariable const & var , double num);
        friend RealVariable operator - (double num , RealVariable const & var);

        friend RealVariable operator ^ (RealVariable const & var , int pow);

        friend RealVariable operator * (double num , RealVariable const & var);
        friend RealVariable operator * (RealVariable const & head , RealVariable const & next);
        friend RealVariable operator * (RealVariable const & head , int const & next);
        friend RealVariable operator * (RealVariable const & head , double const & next);
        friend RealVariable operator * ( int const & next,RealVariable const & head );

        friend RealVariable operator / (RealVariable const & var , double num);
        //friend RealVariable operator / (double const & var , RealVariable num);

        friend RealVariable operator == (RealVariable const & var , double num);
        friend RealVariable operator == (RealVariable const & var1 , RealVariable const & var2);
        friend RealVariable operator == (double num , RealVariable const & var);


    };

    class ComplexVariable
    {
    public:
        double x;
        std::complex<double> y , z ;

        /* empty constructor */
        ComplexVariable();
        ComplexVariable(double first, double second , double third);

        ComplexVariable operator()(ComplexVariable& var);

        friend ComplexVariable operator + (ComplexVariable const & head , ComplexVariable const & next);
        friend ComplexVariable operator + (ComplexVariable const & head , std::complex<double> next);
        friend ComplexVariable operator + (ComplexVariable const & head , double next);
        friend ComplexVariable operator + (double num , ComplexVariable const & var);
        friend ComplexVariable operator + (std::complex<double> num , ComplexVariable const & var);


        friend ComplexVariable operator - (ComplexVariable const & head , ComplexVariable const & next);
        friend ComplexVariable operator - (ComplexVariable const & var , double num);
        friend ComplexVariable operator - (ComplexVariable const & var , std::complex<double> num);
        friend ComplexVariable operator - (std::complex<double> num , ComplexVariable const & var);

        friend ComplexVariable operator ^ (ComplexVariable const & var , int pow);

        friend ComplexVariable operator * (double num , ComplexVariable const & var);
        friend ComplexVariable operator * (ComplexVariable const & var,double num );
        friend ComplexVariable operator * (ComplexVariable const & head,ComplexVariable const & next);

        friend ComplexVariable operator / (ComplexVariable const & var , double num);

        friend ComplexVariable operator == (ComplexVariable const & var , double num);
        friend ComplexVariable operator == (double num,ComplexVariable const & var);
        friend ComplexVariable operator == (ComplexVariable const & head , ComplexVariable const & next);

    };
    double solve(RealVariable var);
    std::complex<double> solve(ComplexVariable var);

}
void print(int index);
 int saparate(double rhs);
void printmessage ();


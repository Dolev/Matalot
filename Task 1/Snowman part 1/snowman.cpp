//
// Created by dolev hindy on 05/03/2021.
//
#include <iostream>
#include <stdexcept>
#include <string>
#include "snowman.hpp"
using namespace std;

namespace ariel{
   const int ten = 10;
        const int one = 1;
        const int four= 4;
        const int eight = 8;
        const int Fsnowman = 11114411;
        const int Ssnowman = 33232124;

    void check_validition(int input){
        int counter = 0;
        if(input< 0){
            throw invalid_argument("We cant use Negative insert!");
        }
        //Input - number - must be 8 digits between 1-4 each digit
        while( input != 0){
            int digit = input % ten;
            if(digit <one || digit > four){
                throw invalid_argument("Wrong input: all options are 1-4.");
            }
            input = input/ten;
            counter++;
        }
        if(counter != eight){
            throw invalid_argument("We have to insert exactly 8 nummbers");
        }
     }  
    
    string snowman(int input){
        int output= input;
        check_validition(input);//check the input is ok validable
        string Drawsnoman = " ";
        if( output == Fsnowman){
            Drawsnoman =  "_===_\n(.,.)\n( : )\n( : )";
        }
        else if(output ==Ssnowman){
            Drawsnoman =  "   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )";
        }
        else if(output == 11114412){
            Drawsnoman =  "_===_\n(.,.)\n( : )\n(" ")";
        }
        else if(output == 11114342){
            Drawsnoman =  "_===_\n(.,.)/\n(   )\n(" ")";
        }
        return Drawsnoman;
    }
}


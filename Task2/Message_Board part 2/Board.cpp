#include "Board.hpp"
#include<map>
#include <iostream>
using namespace std;

namespace ariel {
     void Board::post(unsigned int row, unsigned column, Direction direction,string const &message) {
         //insert my post 
        if(direction==Direction::Vertical){
        NumRow=message.length();
        NumColumn++;
         for(unsigned int i=0;i<message.length();i++){
                 MyBoard[row][column]=message.at(i);
                 row++;
            }
            }
                  if(direction==Direction::Horizontal){
            NumColumn=message.length();
            NumRow++;
            for(unsigned int i=0;i<message.length();i++){
              
                 MyBoard[row][column]=message.at(i);
                 column++;
            }
            }

         }
     

    string Board::read(unsigned int row, unsigned int column, Direction direction,unsigned int length) {
           string result;
           char output=0;
           if(direction==Direction::Horizontal){

            for (unsigned int i = 0; i < length; i++) {  
                       if(MyBoard[row][column]==0){
                           result+= '_';
                           column++;
              }
                       else{
                             output=MyBoard[row][column];
                             result+=output;
                             column++;

                           }
              }
        }

          if(direction==Direction::Vertical){
          for (unsigned int i = 0; i < length; i++) {  

                if(MyBoard[row][column]==0){
                   result+= '_';
                   row++;
                }
                else{
                     output=MyBoard[row][column];
                     result+=output;
                     row++;
                }

                 }
               }
            return result;
    }

     void Board::show() {
         
	 //unsigned int lastRow = NumRow; //
    for (unsigned i = 0; i < NumRow; i++)
    {
        for (unsigned j = 0; j < NumColumn; j++)
        {
            cout<<MyBoard[i][j];
        }   
        cout<< endl;
    }
    
	}
}


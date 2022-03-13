#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "mat.hpp"
using namespace std;
using namespace ariel;



string ariel::matsame(int columns, int rows, char symb1){
    /*
    we will create the string ans.
    we will create a nested for loop.
    the outer loop representing the rows and the inner loop the columns.
    we will add symb1 to the string the amount of column times and than add '\n'.
    and repeat till we create a string representing the whole rug.
    */
    string ans;
    for (int j=0;j<rows; j++){ // rows
        for (int i=0; i< columns; i++){ // columns
        ans.push_back(symb1);
        }
         ans.append("\n");
    }
    return ans;
   
}


string ariel::matreg( int columns, int rows, char symb1, char symb2){
    
    /*
    we will create an vector of chars the length of the matrix.
    we will create some vals.
    int rowhalf= half the rows lower value.
    int colhalf= half the columns lower value.
    int counter= 1
    string ans
    we will initiate the vector with all values being symb1.
    we will create a nested for loop.
    the outer loop representing the rows and the inner loop the columns.
    we will go through the vector, 
    if the value is symb1 we will add the first char to the string else we will add symb2 to the string.
    we will add '\n' to the string, and then update the array.
    if the row is smaller the half the rows
        then we check if the row is odd or even.
        in both cases we will create a for loop from the counter, to (the amount of columns - counter)
                if it is even we will change the value to symb2.
                if it is odd we will change the value to symb1.
    else we will decremenrt the counter
        then create a for loop from counter to (the amount of columns - counter)
        if the vector is symb2 we will change to symb1, and if it is symb1 we will change to symb2.
    */
    
    
    std::vector<char> v;
    v.reserve(columns);
    int rowhalf=rows/2;
    int counter=1;

    string ans;

    for (int i=0; i< columns; i++){
        v.push_back(symb1);
    }

    for (int j=0;j<rows; j++){ // rows
        for (int i=0; i< columns; i++){ // columns
            if(v.at(i)==symb1){
                ans.push_back(symb1);
            }
            else{
                ans.push_back(symb2);
            }
        }
        ans.append("\n");
        if(j<rowhalf){

            if(j%2==0){
                for (int k= counter; k<columns-counter;k++){
                    v.at(k)=symb2;
                }
            }
            else{
                for (int k= counter; k<columns-counter;k++){
                    v.at(k)=symb1;
                } 
            }
            counter++;
        }
        else{
            counter--;
            for( int k=counter; k<columns-counter;k++){
                if(v.at(k)==symb2){
                    v.at(k)=symb1;
                }
                else{ 
                    v.at(k)=symb2;
                } 
            }
        }
    }  
    return ans;
}



string ariel::matlong(int columns, int rows, char symb1, char symb2){
    
    /*
    we will create an vectors of chars the length of the matrix.
    we will create some vals.
    int rowhalf= half the rows lower value.
    int colhalf= half the columns lower value.
    int counter= colhalf
    string ans
    we will initiate the vector with symb1.
    we will create a nested for loop.
    the outer loop representing the rows and the inner loop the columns.
    we will go through the vector, 
    if the value is symb1 we will add the first char to the string else we will add symb2 to the string.
    we will add '\n' to the string, and then update the array.
    if the row is smaller or equal to half the columns of bigger or equal to (the amout of columns - half the columns -1).
        if the row is smaller the half the rows
            then we check if the row is odd or even.
            in both cases we will create a for loop from the row+1, to (the amount of columns - the row -1)
                if it is even we will change the value to symb2.
                if it is odd we will change the value to symb1.
        else we will do a for loop from counter to (the amount of columns -counter)
        if the value is symb2 we will change to symb1 and if symb1 we will change to symb2.
        than we will decrease the counter by 1.
    else we dont need to change what is added to the string because the rug is a much longer than it is wide. 
    */


    std::vector<char> v;
    v.reserve(columns);
    int rowhalf=rows/2;
    int colhalf=columns/2;
    int counter=colhalf;

    string ans;

    for (int i=0; i< columns; i++){
        v.push_back(symb1);
    }
    for (int j=0;j<rows; j++){ // rows
       for (int i=0; i< columns; i++){ // columns
            if(v.at(i)==symb1){
                ans.push_back(symb1);
            }
            else{
                ans.push_back(symb2);
            }
        }
    ans.append("\n");
        if (j<colhalf || j>= rows-colhalf-1){ // if not in this range we dont need to change what is printed
            if(j<rowhalf){
                if(j%2==0){
                    for (int k= j+1; k<columns-j-1;k++){
                        v.at(k)=symb2;
                    }
                }
                else{
                    for (int k= j+1; k<columns-j-1;k++){
                        v.at(k)=symb1;
                    }
                }
            }
            else{
                for (int y=counter; y< columns-counter;y++){
                    if(v.at(y)==symb2){
                       v.at(y)=symb1;
                    }
                    else{
                        v.at(y)=symb2;
                    }
                }
                counter--;                  
            }
        }  
    }
    return ans;
}



string ariel::mat(int columns, int rows, char symb1, char symb2){
    /*
    
    we will check for all reasons the function shoudnt run and throw exceptions.
    if there is no reason to throw an exception we will check if the symbols are the same
    else we will check if the matrix is a long matrix or regular matrix.
    we need to know if it is long so that we can repeat the middle row as long as needed.
    */

    int smallest = ' ';
    int biggest = '~';
   
        if(columns==0 || rows==0){
            throw std::invalid_argument( "size of row or column is 0" );
        }
        if(columns<0 || rows<0){
            throw std::invalid_argument( "size of row or column is negatve" );
        }
        if (columns%2==0 || rows%2==0){
            throw std::invalid_argument( "Mat size is always odd" );
        }
       
        if(symb1==' ' || symb1=='\n' || symb1=='\r' || symb1=='\t' ||symb2==' ' || symb2=='\n' || symb2=='\r' || symb2=='\t'){
            throw std::invalid_argument( "invalid symbol" );
        }
        if(symb1 < smallest || symb2<smallest || symb1>biggest || symb2>biggest){
            throw std::invalid_argument( "invalid symbol" );
        }
        
        if(symb1==symb2 || rows ==1 || columns==1){
            return matsame(columns,rows,symb1);
        }    
        
        if(columns+4>rows){
            return matreg(columns,rows,symb1,symb2);
        }
        
        return matlong(columns,rows,symb1,symb2);

}


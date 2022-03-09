#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "mat.hpp"
using namespace std;
using namespace ariel;



string ariel::matsame(int a, int b, char c){
    /*
    we will create the string ans.
    we will create a nested for loop.
    the outer loop representing the rows and the inner loop the columns.
    we will add the char to the string the amount of column times and than add '\n'.
    and repeat till we create a string representing the whole rug.
    */
    string ans;
    for (int j=0;j<b; j++){ // rows
        for (int i=0; i< a; i++){ // columns
        ans.push_back(c);
        }
         ans.append("\n");
    }
    return ans;
   
}


string ariel::matreg( int a, int b, char c, char d){
    
    /*
    we will create an array of booleans the length of the matrix.
    we will create some vals.
    int rowhalf= half the rows lower value.
    int colhalf= half the columns lower value.
    int counter= 1
    string ans
    we will initiate the array with all values being false.
    we will create a nested for loop.
    the outer loop representing the rows and the inner loop the columns.
    we will go through the array, 
    if the value is false we will add the first char to the string else we will add the second char to the string.
    we will add '\n' to the string, and then update the array.
    if the row is smaller the half the rows
        then we check if the row is odd or even.
        in both cases we will create a for loop from the counter, to (the amount of columns - counter)
                if it is even we will change the value to true.
                if it is odd we will change the value to false.
    else we will decremenrt the counter
        then create a for loop from counter to (the amount of columns - counter)
        if the array is true we will change to false, and if is false we will change to true.
    */
    
    
    std::vector<char> v;
    v.reserve(a);
    int rowhalf=b/2;
    int counter=1;

    string ans;

    for (int i=0; i< a; i++){
        v.push_back(c);
    }

    for (int j=0;j<b; j++){ // rows
        for (int i=0; i< a; i++){ // columns
            if(v.at(i)==c){
                ans.push_back(c);
            }
            else{
                ans.push_back(d);
            }
        }
        ans.append("\n");
        if(j<rowhalf){

            if(j%2==0){
                for (int k= counter; k<a-counter;k++){
                    v.at(k)=d;
                }
            }
            else{
                for (int k= counter; k<a-counter;k++){
                    v.at(k)=c;
                } 
            }
            counter++;
        }
        else{
            counter--;
            for( int k=counter; k<a-counter;k++){
                if(v.at(k)==d){
                    v.at(k)=c;
                }
                else{ 
                    v.at(k)=d;
                } 
            }
        }
    }  
    return ans;
}



string ariel::matlong(int a, int b, char c, char d){
    
    /*
    we will create an array of booleans the length of the matrix.
    we will create some vals.
    int rowhalf= half the rows lower value.
    int colhalf= half the columns lower value.
    int counter= colhalf
    string ans
    we will initiate the array with all values being false.
    we will create a nested for loop.
    the outer loop representing the rows and the inner loop the columns.
    we will go through the array, 
    if the value is false we will add the first char to the string else we will add the second char to the string.
    we will add '\n' to the string, and then update the array.
    if the row is smaller or equal to half the columns of bigger or equal to (the amout of columns - half the columns -1).
        if the row is smaller the half the rows
            then we check if the row is odd or even.
            in both cases we will create a for loop from the row+1, to (the amount of columns - the row -1)
                if it is even we will change the value to true.
                if it is odd we will change the value to false.
        else we will do a for loop from counter to (the amount of columns -counter)
        if the value is true we willl change to false and if false we change to true.
        than we will decrease the counter by 1.
    else we dont need to change what is added ti the string because the rug is a much longer than it is wide. 
    */


    std::vector<char> v;
    v.reserve(a);
    int rowhalf=b/2;
    int colhalf=a/2;
    int counter=colhalf;

    string ans;

    for (int i=0; i< a; i++){
        v.push_back(c);
    }
    for (int j=0;j<b; j++){ // rows
       for (int i=0; i< a; i++){ // columns
            if(v.at(i)==c){
                ans.push_back(c);
            }
            else{
                ans.push_back(d);
            }
        }
    ans.append("\n");
        if (j<colhalf || j>= b-colhalf-1){ // if not in this range we dont need to change what is printed
            if(j<rowhalf){
                if(j%2==0){
                    for (int k= j+1; k<a-j-1;k++){
                        v.at(k)=d;
                    }
                }
                else{
                    for (int k= j+1; k<a-j-1;k++){
                        v.at(k)=c;
                    }
                }
            }
            else{
                for (int y=counter; y< a-counter;y++){
                    if(v.at(y)==d){
                       v.at(y)=c;
                    }
                    else{
                        v.at(y)=d;
                    }
                }
                counter--;                  
            }
        }  
    }
    return ans;
}



string ariel::mat(int a, int b, char c, char d){
    /*
    
    we will check for all reasons the function shoudnt run and throw exceptions.
    if there is no reason to throw an exception we will check if the symbols are the same
    else we will check if the matrix is a long matrix or regular matrix.
    we need to know if it is long so that we can repeat the middle row as long as needed.
    */
   
        if(a==0 || b==0){
            throw std::invalid_argument( "size of row or column is 0" );
        }
        if(a<0 || b<0){
            throw std::invalid_argument( "size of row or column is negatve" );
        }
        if (a%2==0 || b%2==0){
            throw std::invalid_argument( "Mat size is always odd" );
        }
       
        if(c==' ' || c=='\n' || c=='\r' || c=='\t' ||d==' ' || d=='\n' || d=='\r' || d=='\t'){
            throw std::invalid_argument( "invalid symbol" );
        }
        
        if(c==d){
            return matsame(a,b,c);
        }    
        
        if(a+4>b){
            return matreg(a,b,c,d);
        }
        
        return matlong(a,b,c,d);

}




    
    
  




// int main(){   
//   cout << "i hate c++"<< endl;
//   // cout << ariel::mat(5,3,'-','+');
// //     string s= mat(111,57,'*','/');
// //     std::cout << s<<"\n"<< endl;
// //    s= mat(3,3,'+','-'); 
// //     cout << s<<" \n"<< endl;
// //   s=  mat(1,1,'^','-'); 
// //     cout << s<<" \n"<< endl;
// //  s=   mat(1,3,'&','*'); 
// //     cout << s<<" \n"<< endl;
// //    s= mat(3,1,'$','+'); 
// //     cout << s<<"\n "<< endl; 
// //    s= mat(7,3,'/','-'); 
// //     cout <<s<< "\n "<< endl;
// //    s= mat(7,9,'@','*'); 
// //     cout << s<<" \n"<< endl;
// //   s=  mat(5,11,'@','*'); 
// //     cout <<s<< " \n"<< endl;
// //    s= mat(7,21,'@','*'); 
// //     cout << s<<" \n"<< endl;
// //    s= mat(11,5,'*','*'); 
// //     cout << s<<" \n"<< endl;
   
// //     s=mat(47,25,'*','$');
// //      cout << s<<" \n"<< endl;
// //     s=mat(25,47,'*','$');
// //      cout << s<<" \n"<< endl;
// //     s=mat(77, 11, '-', '+');
// //      cout << s<<" \n"<< endl;
// //    s= mat(15, 83, '!', '@');
// //      cout << s<<" \n"<< endl;


//     return 0;
// }
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <random>
// #include<cstdlib>
// #include <string>
// #include <vector>
#include "mat.hpp"
using namespace std;



int main(){   

    time_t curr_time; // this will give us the current time
    srand(curr_time); // this will make the randum genarotor seed be the currenet time thus we wont keep on getting the same random number.
   

    // small rugs
    int nums1[] ={1,3,5};
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            char symb1= rand() % 95+32; // this will give us a random number between 32 and 126. if you add 
            char symb2= rand() % 95+32; // the sum is 127 but the rndom number will be from 32 to 126 it doesnt include the last number(127).
            try{
                cout<< "rows  "<< nums1[j]<< "  columns  " << nums1[i]<<"  first synmbol  " << symb1<< "  second symbol  "<< symb2<< endl;
                cout << ariel::mat(nums1[i],nums1[j],symb1,symb2) <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }
        }
    } 

    //bigger rugs- this will use matreg and matlong (possibly matsame is there are 2 of the same symbols)
    int nums2[] ={13,23,85};
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            char symb1= rand() % 95+32;
            char symb2= rand() % 95+32;
            try{
                cout<< "rows  "<< nums2[j]<< "  columns  " << nums2[i]<<"  first synmbol  " << symb1<< "  second symbol  "<< symb2<<endl;
                cout << ariel::mat(nums2[i],nums2[j],symb1,symb2) <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  // if an exception is cought it will be an illegal symbol
	        }
        }
    }

    cout<< "rows  "<< 4<< "  columns  " << 7<<endl;
    cout << ariel::mat(7,5,'#','#') <<endl; // same symbol 

    try{
        cout<< "rows  "<< 4<< "  columns  " << 7<<endl;
        cout << ariel::mat(7,4,'#','/') <<endl;  // contains even should throw an error
    }
    catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  
    }
    
    try{
        cout<< "rows  "<< 0<< "  columns  " << 7<<endl;
        cout << ariel::mat(7,0,'#','/') <<endl; // contains 0 should throw an error
    }
    catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  
    }
    
    try{
        cout<< "rows  "<< -5<< "  columns  " << 7<<endl;
        cout << ariel::mat(7,-5,'#','/') <<endl; // contains negative should throw an error
    }
    catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  
    }
   
    try{
        cout<< "rows  "<< 7<< "  columns  " << 7<<endl;
        cout << ariel::mat(7,7,' ','/') <<endl; // contains illegal symbol should throw an error
    }
    catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  
    }

    int row;
    int col;
    char symb1;
    char symb2;
    cout << endl;
    cout << "please enter the amout of rows"<< endl;
    cin >> row;
    cout << "please enter the amout of cols"<< endl;
    cin >> col;
    cout << "please enter the first symvol"<< endl;
    cin >> symb1;
    cout << "please enter the second symbol"<< endl;
    cin >> symb2;
   
    try{
        cout<< "rows  "<< row << "  columns  " << col <<endl;
        cout << ariel::mat(col,row,symb1,symb2) <<endl; // contains illegal symbol should throw an error
    }
    catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  
    } 



    return 0;
}
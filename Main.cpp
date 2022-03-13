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

    time_t curr_time;
    srand(curr_time);


    int nums1[] ={1,3,5};
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            char symb1= rand() % 94+32;
            char symb2= rand() % 94+32;
            try{
                cout<< "rows  "<< nums1[j]<< "  columns  " << nums1[i]<<"  first synmbol  " << symb1<< "  second symbol  "<< symb2<< endl;
                cout << ariel::mat(nums1[i],nums1[j],symb1,symb2) <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }
        }
    } 

    int nums2[] ={13,23,85};
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            char symb1= rand() % 94+32;
            char symb2= rand() % 94+32;
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

            

    return 0;
}
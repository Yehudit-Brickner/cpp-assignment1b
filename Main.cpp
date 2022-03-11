#include <iostream>
#include <stdexcept>
// #include <ctime>
#include <random>
// #include <string>
// #include <vector>
#include "mat.hpp"
using namespace std;
// using namespace ariel;

// namespace ariel{
//     string mat(int columns, int rows, char symb1, char symb2);
// 	string matreg(int columns, int rows, char symb1, char symb2);
//     string matlong(int columns, int rows, char symb1, char symb2);
//     string matsame(int columns, int rows, char symb1);
// }


int main(){   

    

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(32, 126);
    char c= distr(eng);
    cout << c<< endl;

    int nums1[] ={1,3,5};
    
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            char c= distr(eng);
            char d= distr(eng);
            try{
                cout<< "rows  "<< nums1[j]<< "  columns  " << nums1[i]<<"  first synmbol  " << c<< "  second symbol  "<< d<< endl;
                cout << ariel::mat(nums1[i],nums1[j],c,d) <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }
        }
    } 

    int nums2[] ={13,23,85};
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            char c= distr(eng);
            char d= distr(eng);
            try{
                cout<< "rows  "<< nums2[j]<< "  columns  " << nums2[i]<<"  first synmbol  " << c<< "  second symbol  "<< d<<endl;
                cout << ariel::mat(nums2[i],nums2[j],c,d) <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }
        }
    } 

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

            int row ='a';
            int col = 'c';
            cout<< "rows  "<< row << "  columns  " << col <<endl;
            cout << ariel::mat(col,row,'*','/') <<endl; 
            


         




   



    return 0;
}
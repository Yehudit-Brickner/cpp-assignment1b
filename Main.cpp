#include <iostream>
#include <stdexcept>
// #include <ctime>
#include <random>
// #include <string>
// #include <vector>

using namespace std;
// using namespace ariel;

namespace ariel{
    string mat(int a, int b, char c, char d);
	string matreg(int a, int b, char c, char d);
    string matlong(int a, int b, char c, char d);
    string matsame(int a, int b, char c);
}


int main(){   

    // srand((unsigned) time(0));
    // int result =(rand());
    // std::cout<< result % 126 << endl;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(32, 126);
    // char c= distr(eng);
    // cout << c<< endl;

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
                cout << ariel::mat(7,4,'#','/') <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }
            try{
                cout<< "rows  "<< 0<< "  columns  " << 7<<endl;
                cout << ariel::mat(7,0,'#','/') <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }
            try{
                cout<< "rows  "<< -5<< "  columns  " << 7<<endl;
                cout << ariel::mat(7,-5,'#','/') <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }
             try{
                cout<< "rows  "<< 7<< "  columns  " << 7<<endl;
                cout << ariel::mat(7,7,' ','/') <<endl; 
            }
            catch (exception& ex) {
	 	        cout << "   caught exception: " << ex.what() << endl;  
	        }



   //chars 32-126
//   cout << "i hate c++"<< endl;
//   std::cout << ariel::mat(5,3,'*','=') <<endl;
// string s= ariel::mat(111,57,'*','/');
//     std::cout << s<<"\n"<< endl;
//    s= mat(3,3,'+','-'); 
//     cout << s<<" \n"<< endl;
//   s=  mat(1,1,'^','-'); 
//     cout << s<<" \n"<< endl;
//  s=   mat(1,3,'&','*'); 
//     cout << s<<" \n"<< endl;
//    s= mat(3,1,'$','+'); 
//     cout << s<<"\n "<< endl; 
//    s= mat(7,3,'/','-'); 
//     cout <<s<< "\n "<< endl;
//    s= mat(7,9,'@','*'); 
//     cout << s<<" \n"<< endl;
//   s=  mat(5,11,'@','*'); 
//     cout <<s<< " \n"<< endl;
//    s= mat(7,21,'@','*'); 
//     cout << s<<" \n"<< endl;
//    s= mat(11,5,'*','*'); 
//     cout << s<<" \n"<< endl;
   
//     s=mat(47,25,'*','$');
//      cout << s<<" \n"<< endl;
//     s=mat(25,47,'*','$');
//      cou-t << s<<" \n"<< endl;
//     s=mat(77, 11, '-', '+');
//      cout << s<<" \n"<< endl;
//    s= mat(15, 83, '!', '@');
//      cout << s<<" \n"<< endl;


    return 0;
}
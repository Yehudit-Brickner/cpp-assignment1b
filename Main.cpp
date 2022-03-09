#include <iostream>
#include <stdexcept>
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
//   cout << "i hate c++"<< endl;
  std::cout << ariel::mat(5,3,'-','+') <<endl;
string s= ariel::mat(111,57,'*','/');
    std::cout << s<<"\n"<< endl;
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
//      cout << s<<" \n"<< endl;
//     s=mat(77, 11, '-', '+');
//      cout << s<<" \n"<< endl;
//    s= mat(15, 83, '!', '@');
//      cout << s<<" \n"<< endl;


    return 0;
}
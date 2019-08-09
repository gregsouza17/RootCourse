#include <iostream>

void changeP(double *v_p){  //2
  *v_p=10.;  //3
  std::cout << "Inside the Change Instance: " << *v_p << "\n";
} //4

int main(){
  double p(3.1415); //1
  std::cout << "Before Change: "<<p << "\n";
  changeP( &p ); // 2
   std::cout << "After Change: "<<p << "\n";
} 

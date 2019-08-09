#include <iostream>

int main(void){
  double a(2.1); //a is a double
  double* p_a; //p_a is a pointer to a double
  p_a=&a; //makes p_a poin to a
  
  std::cout << "a is a double With value: " <<
    a <<" \t Stored at: " << &a << "\n";
  std::cout << "p_a is a pointer With Value: " <<
    p_a << "\nPointing to the value: " << *p_a << "\n"; 
}

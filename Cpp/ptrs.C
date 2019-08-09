#include <iostream>

void pwhere(double x);
void pwhere2(double* x);

main(){

  // double* a = new double(1.996);
  // double b(3.14);
  // std::cout << "Adress of a: " << a <<
  //   "\t Value at a: " << *a <<"\n" <<
  //   "Adress of b: " << &b << "\t Value in b" << b << "\n"; 

  // double c;
  // c = *a;
  // std::cout << (&c == a) << "\n";
  
  // double d(4.2);
  // std::cout << "Adress of a: " << a <<
  //   "\t Value at a: " << *a << "\n";
  // a = &d;
  // std::cout << "Adress of a: " << a <<
  //   "\t Value at a: " << *a << "\n";

  double x(13.17);
  // std::cout << "Adress of x: " << &x <<
  //   "\t Value at &x: " << x <<"\n";
  // pwhere(x);
  std::cout << "Adress of x: " << &x <<
      "\t Value at &x: " << x <<"\n";

  pwhere2(&x);
  std::cout << "Adress of x: " << &x <<
    "\t Value at &x: " << x <<"\n";
}

void pwhere(double x){
  x=1.0;
  std::cout << "Inside pwhere \nAdress of x: " << &x <<
    "\t Value at &x: " << x <<"\nOutside pwhere2 \n";

  return;
}

void pwhere2(double* x){
  *x=0.999;
  std::cout << "Inside pwhere2 \nAdress of x: " << x <<
    "\t Value at &x: " << *x <<"\nOutside pwhere2 \n";

  return;
}

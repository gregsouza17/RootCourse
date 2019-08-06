#include <iostream>

#define N 1000

void tst1(double a[N]);
void tst2(double *a, int size_a);

int main(void){

  double a[N];
  std::cout << "Printin an array" << a << "\n Arrays are pointers!!" <<
    "The array has size: " << sizeof(a) <<"\n \n" ;

  double *b = new double[N];
  std::cout << "Printin the pointer" << b << "\n" <<
    "The pointer has size: " << sizeof(b) << "\n" ;

  tst1(a);

  tst2(b, N);
  

}

void tst1(double a[]){

  std::cout <<"Tst1 size of input: " << sizeof(a) << "\n" <<
    " Arrays are demoted to pointers  in the input!!\n";
}


void tst2(double *a, int size_a){

  std::cout << " Tst2 size of input: " << sizeof(a) << "\n \n"; 
}

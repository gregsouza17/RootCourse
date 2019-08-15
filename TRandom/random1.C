#include <iostream>
#include <ctime>
#include "TRandom3.h"

void uniformPrint();
void gausPrint();
void PoissonHist();

void random1(){

  //  uniformPrint();
  // gausPrint();
  PoissonHist();
}

void uniformPrint(){
  
  TRandom3 rand(std::time(0));
  for(int i=0; i<100; i++)
    std::cout<< rand.Uniform(-1,1) << "\n";
  
}

void gausPrint(){
  TRandom3 rand(std::time(0));
  for(int i=0; i<100; i++)
    std::cout<<rand.Gaus() << "\n";
}

void PoissonHist(){

  
  TH1I* h1 = new TH1I("h1", "Integer Poisson Histogram", 50, 0,51);

  TRandom3 rand(std::time(0));
  for(int i=0; i<10000; i++){
    h1->Fill(rand.Poisson(20.));
  }

  h1->Draw();
  
}

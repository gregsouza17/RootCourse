#include "TFunction.h"

void oneFunc(){
  // TF1 f1("func1", "sin(x)/x",0,10);
  // f1.Draw();

  TF1* f1 = new TF1("func1", "sin(x)/x",0,10);

  f1->Draw();  
}


void twoFunc(){
  // TF1 f1("func1", "sin(x)/x", 0, 10); 
  // TF1 f2("func2", "exp(-x)", 0, 10);
  // f1.Draw();
  // f2.Draw("same");
  
  TF1* f1 = new TF1("func1", "sin(x)/x", 0, 10); 
  TF1* f2 = new TF1("func2", "exp(-x)" , 0, 10);
  
  f1->Draw();
  f2->Draw("same");

  
}

void funcDraw(){
  twoFunc();
  
}
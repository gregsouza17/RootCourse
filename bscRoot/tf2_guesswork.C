#include <iostream>


void f2plot();
Double_t myFunc(Double_t *val, Double_t *par);
void myPlot();

void tf2_guesswork(){

  
  f2plot();
}


void f2plot(){

  TF2* f2 = new TF2("f2", "sin(x)*sin(y)/(x*y)",
		    /*x range*/  -10,10,
		    /*y range */ -10,10);
  
  f2->Draw("surf2");
}

void myPlot(){

  TF2 *f = new TF2("myf", myFunc, /*x*/-1, 1, /*y*/-1,1);
  f->Draw("surf");
  
}


Double_t myFunc(Double_t *val, Double_t *par){
  
  Double_t x = val[0];
  Double_t y = val[1];
  return x*x - y*y + x*y/4;
}

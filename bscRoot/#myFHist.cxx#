#include <iostream>
#include "TF1.h"
#include "TH1D.h"


void myFHist(){

  //Creating your own function
  TF1* myfunc = new TF1("myfunc", "gaus", 0,3);
  /* the gaussian function has 3 parameters as [0]*exp(-()(x-[1])/[2])^2)*/
  
  myfunc->SetParameters(/*[0]*/ 10.0,
		   /*[1]*/ 1.0 ,
		   /*[2]*/ 0.5 );
  //myfunc->Draw();
  
  TH1D* h2 = new TH1D("hist2", "Histogram from my function",100, -3,3);
  h2->FillRandom("myfunc", 10000);
  myfunc->SetParameter(1, -1.0);
  h2->FillRandom("myfunc", 10000);

  
  h2->Draw();
}

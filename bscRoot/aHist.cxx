#include <iostream>
#include "TH1D.h"

void aHist(){
  //  TH1D h1("hist1", "Histogram from a gaussian", 100, -3, 3);
  TH1D* h1 = new TH1D("hist1", "Histogram from a gaussian", 100, -3, 3);
  std::cout << h1->GetBinWidth(0) << "\n";

  h1->FillRandom("gaus", 10000);

  //Draw with errors
  h1->Draw(); //h1.Draw();
  
  
}
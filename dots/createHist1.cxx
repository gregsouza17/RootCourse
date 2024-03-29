
Double_t myfunction(Double_t *val, Double_t *par){
  
  Double_t xlow(-3.);
  Double_t xhigh(3.);
  Double_t u, f, fmg;
  u=*val;
  
  TF1* mg= new TF1("mg", "gaus", xlow,xhigh);
  mg->SetParameters(3.742, 0.77777, 0.999);
  fmg=mg->Eval(u);
  TRandom *rand = new TRandom();
  
  f=fmg*(1+ 0.3*rand->Gaus(u,0.05));

  return f;
}


void createHist1(){

  TFile* fout = new TFile("hist1.root", "RECREATE");

  TF1* mf= new TF1("mf",myfunction);

  TH1D *h1 = new TH1D("hist1", "A Hist", 100, -4, 4);
  h1->FillRandom("mf",40000);

  TF1* twoG= new TF1("tg", "gaus(0)+gaus(3)");
  twoG->SetParameters(3.,3.14,1.,1.,9.33,1.);

  TH1D *h2 = new TH1D("hist2", "B Hist", 200, 0, 15);
  h2->FillRandom("tg", 80000);

  
  //h2->Draw();
  //  h1->Draw();

  fout->Write();
  fout->Close();
  
}

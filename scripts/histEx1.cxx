void makeHist(std::string filename);
void readHist(std::string filename);
void fitHist(std::string filename);

void histEx1(){
  std::string fname("oneHist.root");
  makeHist(fname);
  fitHist(fname);
  // readHist(fname);
  
}

void makeHist(std::string filename){

  TFile* f1 = new TFile(filename.c_str(), "RECREATE");
  TH1D* h1 = new TH1D("h1", "A Gaussian Histogram", 100, -3,3);
  h1->FillRandom("gaus", 10000);
  f1->WriteObject(h1, "aHist", "TObject::kOverwrite");
  f1->Close();
  
}

void readHist(std::string filename){

  TFile* f1 = new TFile(filename.c_str(), "READ");
  TH1D* h1 = (TH1D*) f1->Get("aHist");
  h1->Draw();
  std::cout << "Number of Entries: " <<
    h1->GetEntries() << "\n";
  std::cout << "Mean: "<< h1->GetMean() <<"\n";
  std::cout <<" Standart Deviation: " <<
    h1->GetStdDev() <<"\n";
}

void fitHist(std::string filename){

    
  TFile* theFile = new TFile(filename.c_str(), "UPDATE");
  TH1D* h1 = (TH1D*) theFile->Get("aHist");
  TF1* f1 = new TF1("myfunc", "gaus", -3,3);
  f1->SetParameters(h1->GetBinContent(50), h1->GetMean(),
		    h1->GetStdDev());
  h1->Fit("myfunc");
  f1->Write();
  theFile->WriteObject(h1, "Fitted_aHist", "TObject::kOverwrite");
  theFile->Close();
}

#include <iostream>
#include <string>

double TotalE_Alpha(std::string filename);
void detPhotonsHist(std::string filename);
void dPperEnergyHist(std::string filename);

void treeEx1(){
  std::string fname("simulation.root");
  // std::cout << TotalE_Alpha(fname) << "\n";
  // detPhotonsHist(fname);
  dPperEnergyHist(fname);
}

double TotalE_Alpha(std::string filename){
 //Opening the File
  TFile* fin=new TFile(filename.c_str(),"READ");
  //Setting the branch address
  TTree* t1= (TTree*) fin->Get("t1");
  double alphaEnergy;
  t1->SetBranchAddress("alphaEnergy", &alphaEnergy);

  
  //Summing for total energy
  Double_t TotalEnergy(0);
  for(int i=0; i<t1->GetEntries(); i++){
    t1->GetEntry(i);
    //std::cout << alphaEnergy << "\n";
    TotalEnergy += alphaEnergy;
  }
    
  
  fin->Close();

  return TotalEnergy;
}

void detPhotonsHist(std::string filename){
 //Opening the File
  TFile* fin=new TFile(filename.c_str(),"READ");
  //Setting the branch address
  TTree* t1= (TTree*) fin->Get("t1");
  double alphaEnergy;
  t1->SetBranchAddress("alphaEnergy", &alphaEnergy);

  TH1D* h1= new TH1D("h1", "Alpha Energy",
		       /*n bins*/ 100,
		       /*xl range*/ 0,5);

  for(int i=0; i<t1->GetEntries(); i++){
    t1->GetEntry(i);
    h1->Fill(alphaEnergy);
  }

  h1->Draw();

  
}

void dPperEnergyHist(std::string filename){
  //Opening the File
  TFile* fin=new TFile(filename.c_str(),"READ");
  //Setting the branch address
  TTree* t1= (TTree*) fin->Get("t1");
  double alphaEnergy, detPhotons;
  t1->SetBranchAddress("alphaEnergy", &alphaEnergy);
  t1->SetBranchAddress("detPhotons", &detPhotons);

  TH1D* h1 = new TH1D("h1", "Det Photons Per Energy",
		      /*nbins*/ 100,
		      /*x range*/ 700, 1000);

  double r;
  for(int i=0; i<t1->GetEntries(); i++){
    t1->GetEntry(i);
    r=detPhotons/alphaEnergy;
    h1->Fill(r);
  }

  h1->Draw();
 
}

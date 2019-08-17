#include <ctime>

double Uavarage(int N);
void lawW();
void lawU();
void lawFit();

void lawLN(){
  lawW();
  lawU();
  lawFit();
}

void lawFit(){
  TFile *fin = new TFile("law.root", "READ");
  TH1D* h10 = (TH1D*) fin->Get("h20");
  double xmin(0), xmax(1);
  TF1 fgaus("myGaus", "gaus", xmin, xmax);

  //Let set the initial guesses for our gaussian fit
  double mean, sigma, peak(400);
  mean = h10->GetMean();
  sigma = h10->GetStdDev();

  fgaus.SetParameters(peak, mean, sigma);

  h10->Fit("myGaus");

  h10->Draw();

  double expectedMean(0.5), expectedSigma(std::sqrt(1/240.));

  
  
  mean = fgaus.GetParameter(1);
  sigma = fgaus.GetParameter(2);

  std::cout << "Difference in Mean: "  <<
    (expectedMean-mean)/expectedMean << "\n";
  
  std::cout << "Difference in Sigma: "  <<
    (expectedSigma-sigma)/expectedSigma << "\n";
  
  
}

void lawU(){

  TFile *fin = new TFile("law.root", "UPDATE");
  TTree *t1 = (TTree*) fin->Get("t1");
  double U10, U20, U100, gaus;
  t1->SetBranchAddress("gaus", &gaus);
  t1->SetBranchAddress("Uavg10", &U10);
  t1->SetBranchAddress("Uavg20", &U20);
  t1->SetBranchAddress("Uavg100", &U100);

  double xmin(0.0), xmax(1.0);
  int nbins(200);
 
  TH1D *h10 = new TH1D("h10", "Histogram for 10 points", nbins, xmin ,xmax);
  
  TH1D *h100 =
    new TH1D("h100", "Histogram for 100 points", nbins, xmin ,xmax);
  
  TH1D *h20 = new TH1D("h20", "Histogram for 20 points", nbins, xmin ,xmax);


  int nentries = t1->GetEntries();
  // t1->Scan();
  
  for(int i=0; i<nentries;i++){
    t1->GetEntry(i);
     h10->Fill(U10);		
     h20->Fill(U20);
     h100->Fill(U100);
  }

  h10->Write();
  h20->Write();
  h100->Write();
  fin->Close();
  
}

void lawW(){

  TFile *fout = new TFile("law.root", "RECREATE");

  TTree *t1 = new TTree("t1", "Law of Large Numbers Tree");
  double Uavg10, Uavg20, Uavg100, gaus;
  t1->Branch("Uavg10", &Uavg10, "Uavg10/D" );
  t1->Branch("Uavg20", &Uavg20, "Uavg20/D" );
  t1->Branch("Uavg100", &Uavg100, "Uavg100/D");
  t1->Branch("gaus", &gaus, "gaus/D");

  TRandom3 randG(std::time(0));
  
  for(int i=0; i<10000; i++){
    Uavg10=Uavarage(10);
    Uavg20=Uavarage(20);
    Uavg100=Uavarage(100);
    gaus= randG.Gaus(0.5, std::sqrt(1/12.));
    t1->Fill();
  }

  t1->Write();

  fout->Close();
  
}

double Uavarage(int N){
  static TRandom3 RandGen(std::time(0));
  
  double avg(0);
  for(int i=0; i<N; i++){
    avg+=RandGen.Uniform();
  }

  return avg/N;
  
}

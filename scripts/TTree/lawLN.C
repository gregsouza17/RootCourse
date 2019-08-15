#include <ctime>


double Uavarage(int N);


void lawLN(){

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
  
}

double Uavarage(int N){
  static TRandom3 RandGen(std::time(0));
  
  double avg(0);
  for(int i=0; i<N; i++){
    avg+=RandGen.Uniform();
  }

  return avg/N;
  
}

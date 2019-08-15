void treeEx2W();

void treeEx2(){
  treeEx2W();
}

void treeEx2W(){

  TFile *fout = new TFile("foutEx2.root", "RECREATE");

  TTree *t1 = new TTree("Trand", "Random Tree");
  double gaus, land;
  int entry;
  t1->Branch("gaus", &gaus, "gaus/D");
  t1->Branch("entry", &entry, "entry/I");

  TRandom3 rand;

  for(int i=0; i <10000; i++){
    gaus = rand.Gaus();
    entry=i;
    t1->Fill();
  }

  t1->Write();
}

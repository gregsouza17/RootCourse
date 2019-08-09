void f1Write(std::string filename);
void f1Read(std::string filename);

void funcWR(){
  std::string fname("f1.root");
  f1Write(fname);
  f1Read(fname);
}

void f1Write(std::string filename){
  TFile* file1 = new TFile(filename.c_str(), "RECREATE");
  TF1* f1 = new TF1("f1", "sin(x)/x", 0, 10);
  f1->Write();
  file1->Write();
  file1->Close();
}

void f1Read(std::string filename){
  TFile* Afile = new TFile(filename.c_str(), "READ");
  //Getting from a file IMPORTANT:
  TF1* f1 = (TF1*)  Afile->Get("f1");
  f1->Draw();
}

void twoFDraw(){
  double xmin(0.), xmax(10.0);
  TF1* f1 = new TF1("f1", "sin(x)/x"    , xmin, xmax);
  TF1* f2 = new TF1("f2", "exp(-x)", xmin, xmax);
  f1->Draw();
  f2->Draw("same");
}

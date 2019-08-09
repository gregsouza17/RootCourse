void f1Draw2(){
  double xmin(0), xmax(3.);
  TF1* f1 = new TF1("myfunc", "sin(x)/x",xmin,xmax);
  f1->Draw();
}

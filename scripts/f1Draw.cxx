void f1Draw(){
  double xmin(0), xmax(3.);
  TF1 f1("myfunc", "sin(x)/x",xmin,xmax);
  f1.Draw();
}
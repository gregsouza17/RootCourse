void surfTF2(){
  double xmin(-5.), xmax(5.), ymin(-5.), ymax(5.);
  TF2* f1= new TF2("f1", "sin(x)*sin(2*y)/(x*y)",
		   xmin ,xmax, ymin, ymax );
  f1->Draw("surf1");
    
}

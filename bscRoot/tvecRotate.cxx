

void tvecRotate(){

  TVector3 v1(1,2,3);
  v1.RotateX(TMath::Pi()/2);
  v1.SetY(-v1.Y());
  
  TVector2 v2(v1.XYvector());
  std::cout<<v1.X() <<" , " << v1.Y() << " , " << v1.Z() << "\n";
  std::cout<<v2.X() <<" , " << v2.Y() << "\n";
  
}

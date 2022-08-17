//root macros
//#include "TTree.h"
void generator(){
  TFile fOut("kaon.root", "RECREATE");
  TTree tree ("kaon", "kaon");
  Double_t p1_x, p1_y, p1_z, p1_e;
  tree.Branch("p1_x", &p1_x, "p1_x/D");
  tree.Branch("p1_y", &p1_y, "p1_y/D");
  tree.Branch("p1_z", &p1_z, "p1_z/D");
  tree.Branch("p1_e", &p1_e, "p1_e/D");

  Double_t p2_x, p2_y, p2_z, p2_e;
  tree.Branch("p2_x", &p2_x, "p2_x/D");
  tree.Branch("p2_y", &p2_y, "p2_y/D");
  tree.Branch("p2_z", &p2_z, "p2_z/D");
  tree.Branch("p2_e", &p2_e, "p2_e/D");

  Double_t invmass;
  tree.Branch("invmassa", &invmass, "invmass/D");

  Double_t m_kaon = 0.498; //GeV
  Double_t m_pion = 0.135;
  Double_t p_kaon = 5.0; //GeV
  Double_t beta = p_kaon / sqrt(p_kaon * p_kaon + m_kaon * m_kaon);

  Int_t nEvents = 1e6;

  TH2F * inv_mass = new TH2F("inv_mass", "; Transverce momentum, GeV; Invariant mass, GeV", 100, 0., 8., 100, 0., 12.0);

  for (Int_t i = 0; i < nEvents; i++){
    Double_t e_pion = m_kaon / 2;
    Double_t p_pion = sqrt(e_pion * e_pion - m_pion * m_pion);
    Double_t cos_theta = 2 * gRandom -> Rndm() - 1;
    Double_t sin_theta = sqrt(1 - cos_theta * cos_theta);
    Double_t phi = gRandom -> Rndm() * 2 * 3.14159;

    Double_t px1 = p_pion * sin_theta * cos(phi);
    Double_t py1 = p_pion * sin_theta * sin(phi);
    Double_t pz1 = p_pion * cos_theta;

    Double_t px2 = -px1;
    Double_t py2 = -py1;
    Double_t pz2 = -pz1;

    TLorentzVector pion1 (px1, py1, pz1, e_pion);
    TLorentzVector pion2 (px2, py2, pz2, e_pion);

    pion1.Boost(0., 0., beta);
    pion2.Boost(0., 0., beta);

    p1_x = pion1.Px();
    p1_y = pion1.Py();
    p1_z = pion1.Pz();
    p1_e = pion1.E();

    p2_x = pion2.Px();
    p2_y = pion2.Py();
    p2_z = pion2.Pz();
    p2_e = pion2.E();

    p1_x = gRandom -> Gaus(p1_x, 1);
    p1_y = gRandom -> Gaus(p1_y, 1);
    p1_z = gRandom -> Gaus(p1_z, 1);
    p1_e = gRandom -> Gaus(p1_e, 1);

    p2_x = gRandom -> Gaus(p2_x, 1);
    p2_y = gRandom -> Gaus(p2_y, 1);
    p2_z = gRandom -> Gaus(p2_z, 1);
    p2_e = gRandom -> Gaus(p2_e, 1);

    Double_t momentum = pow(p1_x + p2_x, 2) + pow(p1_y + p2_y, 2) + pow(p1_z + p2_z, 2);
    invmass = sqrt(pow(p1_e + p2_e, 2) - momentum);
    //std::cout << sqrt(momentum) << std::endl;
    Double_t trans_mom = sqrt(pow(p1_y + p2_y, 2) + pow(p1_x + p2_x, 2));

    tree.Fill();
    inv_mass -> Fill(trans_mom, invmass);
  }

  TCanvas *c1 = new TCanvas ("c1", "invariant_mass", 1200, 800);
	c1 -> cd();
  inv_mass -> SetStats(0);
	inv_mass -> Draw("colz");
  //inv_mass -> Draw();
	c1 -> Update();
	c1 -> Modified();
	c1 -> Print("invmass_1_0.png");

  fOut.Write();
  fOut.Close();
}

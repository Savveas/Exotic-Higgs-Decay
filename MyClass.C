#define MyClass_cxx
#include <iostream>
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>



// define structure with TLorentzVector, btag values
  struct btagsort {
  TLorentzVector vec;
  float btag1;
};
  bool compare_btag(const btagsort& x, const btagsort& y)
  {
  return x.btag1 > y.btag1;
  }
  



void MyClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MyClass.C
//      root> MyClass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->Set//BranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
if (fChain == 0) return;


TString dir="M15/";
  Long64_t nentries = fChain->GetEntriesFast();
  TFile f(dir+"histos_signal.root","recreate");
  //TFile f("histos_back_TTbarSemileptonic.root","recreate");
  //TFile f("histos_back_TTbarDileptonic.root","recreate");
  //TFile f("histos_back_TTbarHadronic.root","recreate");
  //TFile f("histos_back_WJetsToLNu70to100.root","recreate");
  //TFile f("histos_back_WJetsToLNu100to200.root","recreate");
  //TFile f("histos_back_WJetsToLNu200to400.root","recreate");
  //TFile f("histos_back_WJetsToLNu400to600.root","recreate");
  //TFile f("histos_back_WJetsToLNu600to800.root","recreate");
  //TFile f("histos_back_WJetsToLNu800to1200.root","recreate");
  //TFile f("histos_back_WJetsToLNu1200to2500.root","recreate");
  //TFile f("histos_back_WJetsToLNu_0.root","recreate");
  //TFile f("histos_back_qcd_bctoE_80to170.root","recreate");
  //TFile f("histos_back_qcd_bctoE_170to250.root","recreate");
  //TFile f("histos_back_qcd_bctoE_250toInf.root","recreate");


  //N_expected calculations
  float Br_W_to_lep=0.1046+0.105+0.1075;
  float Br_W_to_qq=0.6832;
  float Br_qcd_bctoe_80to170=0.01183;
  float Br_qcd_bctoe_170to250=0.02492;
  float Br_qcd_bctoe_250toInf=0.03375;


  float sigma_signal=1.37*Br_W_to_lep*0.61;
  float sigma_back_Semileptonic=365.34*Br_W_to_lep;
  float sigma_back_Dileptonic=88.29*Br_W_to_lep;
  float sigma_back_Hadronic=377.96*Br_W_to_lep;
  float sigma_back_WJetsToLNu70to100=1353*1.21*Br_W_to_lep;
  float sigma_back_WJetsToLNu100to200=1346*1.21*Br_W_to_lep;
  float sigma_back_WJetsToLNu200to400=359.7*1.21*Br_W_to_lep;
  float sigma_back_WJetsToLNu400to600=48.91*1.21*Br_W_to_lep;
  float sigma_back_WJetsToLNu600to800=12.05*1.21*Br_W_to_lep;
  float sigma_back_WJetsToLNu800to1200=5.501*1.21*Br_W_to_lep;
  float sigma_back_WJetsToLNu1200to2500=1.329*1.21*Br_W_to_lep;
  float sigma_back_WJetsToLNu_0=0.0326*1.21*Br_W_to_lep;
  float sigma_back_qcd_bctoE_80to170=3221000*Br_qcd_bctoe_80to170;
  float sigma_back_qcd_bctoE_170to250=105771*Br_qcd_bctoe_170to250;
  float sigma_back_qcd_bctoE_205toInf=21094.1*Br_qcd_bctoe_250toInf;
  float L_integrated=41.5*pow(10.,3.);



  float N_expected_signal=sigma_signal*L_integrated;
  float N_expected_back_Semileptonic=sigma_back_Semileptonic*L_integrated;
  float N_expected_back_Dileptonic=sigma_back_Dileptonic*L_integrated;
  float N_expected_back_Hadronic=sigma_back_Hadronic*L_integrated;
  float N_expected_back_WJetsToLNu70to100=sigma_back_WJetsToLNu70to100*L_integrated;
  float N_expected_back_WJetsToLNu100to200=sigma_back_WJetsToLNu100to200*L_integrated;
  float N_expected_back_WJetsToLNu200to400=sigma_back_WJetsToLNu200to400*L_integrated;
  float N_expected_back_WJetsToLNu400to600=sigma_back_WJetsToLNu400to600*L_integrated;
  float N_expected_back_WJetsToLNu600to800=sigma_back_WJetsToLNu600to800*L_integrated;
  float N_expected_back_WJetsToLNu800to1200=sigma_back_WJetsToLNu800to1200*L_integrated;
  float N_expected_back_WJetsToLNu1200to2500=sigma_back_WJetsToLNu1200to2500*L_integrated;
  float N_expected_back_WJetsToLNu_0=sigma_back_WJetsToLNu_0*L_integrated;
  float N_expected_back_qcd_bctoE_80to170=sigma_back_qcd_bctoE_80to170*L_integrated;
  float N_expected_back_qcd_bctoE_170to250=sigma_back_qcd_bctoE_170to250*L_integrated;
  float N_expected_back_qcd_bctoE_250toInf=sigma_back_qcd_bctoE_205toInf*L_integrated;



  float w_signal=N_expected_signal/totalNumberofEvents;
  float w_back_Semileptonic=N_expected_back_Semileptonic/totalNumberofEvents;
  float w_back_Dileptonic=N_expected_back_Dileptonic/totalNumberofEvents;
  float w_back_Hadronic=N_expected_back_Hadronic/totalNumberofEvents;
  float w_back_WJetsToLNu70to100=N_expected_back_WJetsToLNu70to100/totalNumberofEvents;
  float w_back_WJetsToLNu100to200=N_expected_back_WJetsToLNu100to200/totalNumberofEvents;
  float w_back_WJetsToLNu200to400=N_expected_back_WJetsToLNu200to400/totalNumberofEvents;
  float w_back_WJetsToLNu400to600=N_expected_back_WJetsToLNu400to600/totalNumberofEvents;
  float w_back_WJetsToLNu600to800=N_expected_back_WJetsToLNu600to800/totalNumberofEvents;
  float w_back_WJetsToLNu800to1200=N_expected_back_WJetsToLNu800to1200/totalNumberofEvents;
  float w_back_WJetsToLNu1200to2500=N_expected_back_WJetsToLNu1200to2500/totalNumberofEvents;
  float w_back_WJetsToLNu_0=N_expected_back_WJetsToLNu_0/totalNumberofEvents;
  float w_back_qcd_bctoE_80to170=N_expected_back_qcd_bctoE_80to170/totalNumberofEvents;
  float w_back_qcd_bctoE_170to250=N_expected_back_qcd_bctoE_170to250/totalNumberofEvents;
  float w_back_qcd_bctoE_250toInf=N_expected_back_qcd_bctoE_250toInf/totalNumberofEvents;
  

  

  float w(0.);
  float N_expected(0.);
if (std::string(f.GetName()) == dir+ "histos_signal.root") {
  w = w_signal;
  N_expected= N_expected_signal;
  std::cout << " Signal weight = " << w_signal << std::endl;
} else if (std::string(f.GetName()) == "histos_back_TTbarSemileptonic.root") {
  w = w_back_Semileptonic;
  N_expected= N_expected_back_Semileptonic;
  std::cout << " Backround weight (TTbar_Semileptonic) = " << w_back_Semileptonic << std::endl;
} else if (std::string(f.GetName()) == "histos_back_TTbarDileptonic.root"){
  w = w_back_Dileptonic; 
  N_expected= N_expected_back_Dileptonic;
  std::cout << " Backround weight (TTbar_Dileptonic) = " << w_back_Dileptonic << std::endl;
} else if (std::string(f.GetName()) == "histos_back_TTbarHadronic.root"){
  w = w_back_Hadronic; 
  N_expected= N_expected_back_Hadronic;
  std::cout << " Backround weight (TTbar_Hadronic) = " << w_back_Hadronic << std::endl;
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu70to100.root"){
  w = w_back_WJetsToLNu70to100; 
  N_expected= N_expected_back_WJetsToLNu70to100;
  std::cout << " Backround weight (TTbar_WJetsToLNu70to100) = " << w_back_WJetsToLNu70to100 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu100to200.root"){
  w = w_back_WJetsToLNu100to200; 
  N_expected= N_expected_back_WJetsToLNu100to200;
  std::cout << " Backround weight (TTbar_WJetsToLNu100to200) = " << w_back_WJetsToLNu100to200 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu200to400.root"){
  w = w_back_WJetsToLNu200to400; 
  N_expected= N_expected_back_WJetsToLNu200to400;
  std::cout << " Backround weight (TTbar_WJetsToLNu200to400) = " << w_back_WJetsToLNu200to400 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu400to600.root"){
  w = w_back_WJetsToLNu400to600; 
  N_expected= N_expected_back_WJetsToLNu400to600;
  std::cout << " Backround weight (TTbar_WJetsToLNu400to600) = " << w_back_WJetsToLNu400to600 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu600to800.root"){
  w = w_back_WJetsToLNu600to800; 
  N_expected= N_expected_back_WJetsToLNu600to800;
  std::cout << " Backround weight (TTbar_WJetsToLNu600to800) = " << w_back_WJetsToLNu600to800 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu800to1200.root"){
  w = w_back_WJetsToLNu800to1200; 
  N_expected= N_expected_back_WJetsToLNu800to1200;
  std::cout << " Backround weight (TTbar_WJetsToLNu800to1200) = " << w_back_WJetsToLNu800to1200 << std::endl;  
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu1200to2500.root"){
  w = w_back_WJetsToLNu1200to2500; 
  N_expected= N_expected_back_WJetsToLNu1200to2500;
  std::cout << " Backround weight (TTbar_WJetsToLNu1200to2500) = " << w_back_WJetsToLNu1200to2500 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_WJetsToLNu_0.root"){
  w = w_back_WJetsToLNu400to600; 
  N_expected= N_expected_back_WJetsToLNu_0;
  std::cout << " Backround weight (TTbar_WJetsToLNu_0) = " << w_back_WJetsToLNu_0 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_qcd_bctoE_80to170.root"){
  w = w_back_qcd_bctoE_80to170; 
  N_expected= N_expected_back_qcd_bctoE_80to170;
  std::cout << " Backround weight (QCD_bctoE_80to170) = " << w_back_qcd_bctoE_80to170 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_qcd_bctoE_170to250.root"){
  w = w_back_qcd_bctoE_170to250; 
  N_expected= N_expected_back_qcd_bctoE_170to250;
  std::cout << " Backround weight (QCD_bctoE_170to250) = " << w_back_qcd_bctoE_170to250 << std::endl;
} else if (std::string(f.GetName()) == "histos_back_qcd_bctoE_250toInf.root"){
  w = w_back_qcd_bctoE_250toInf; 
  N_expected= N_expected_back_qcd_bctoE_250toInf;
  std::cout << " Backround weight (QCD_bctoE_250toInf) = " << w_back_qcd_bctoE_250toInf << std::endl;
}



  //muon 
  TH1F *h_mn_pt = new TH1F("h_mn_pt","muon pt distribution",100,0.,500.);
  TH1F *h_mn_eta = new TH1F("h_mn_eta","muon pseudorapidity distribution",100,-5.,5.);
  TH1F *h_mn_phi = new TH1F("h_mn_phi","muon phi distribution",100,-5.,5.);  


  //TH2F *h_mn_pt_eta = new TH2F("h_mn_pt_eta","muon pt-eta distribution",100,0.,500.,100,-3.,3.);
  //TH2F *h_mn_phi_eta = new TH2F("h_mn_phi_eta","muon phi-eta distribution",100,0.,500.,100,-3.,3.);


  //TH2F *h_mn_en_phi = new TH2F("h_mn_en_phi","electron-muon phi ditribution",100,-5.,5.,100,-5.,5.);


  TH1F *h_en_pt = new TH1F("h_en_pt","electron pt distribution",500,0.,500.); 
  TH1F *h_en_eta = new TH1F("h_en_eta","electron pseudorapidity distribution",100,-5.,5.);
  TH1F *h_en_phi = new TH1F("h_en_phi","electron phi distribution",100,-5.,5.);


  //TH2F *h_en_pt_eta = new TH2F("h_en_pt_eta","electron pt-eta distribution",100,0.,500.,100,-3.,3.);


  TH1F *h_jet1_pt = new TH1F("h_jet1_pt","jet1 distribution",500,0.,500.);
  TH1F *h_jet1_eta = new TH1F("h_jet1_eta","jet pseudorapidity distribution",100,-5.,5.);
  TH1F *h_jet1_phi = new TH1F("h_jet1_phi","jet phi distribution",100,-5.,5.);
  TH1F *h_jet1_m = new TH1F("h_jet1_m","jet mass distributions",100,0.,100);
  TH1F *h_jet2_pt = new TH1F("h_jet2_pt","jet2 distribution",500,0.,500.);
  TH1F *h_jet2_eta = new TH1F("h_jet2_eta","jet2 pseudorapidity distribution",100,-5.,5.);
  TH1F *h_jet2_phi = new TH1F("h_jet2_phi","jet phi distribution",100,-5.,5.);
  TH1F *h_jet2_m = new TH1F("h_jet2_m","jet mass distributions",100,0.,100);
  TH1F *h_jet3_pt = new TH1F("h_jet3_pt","jet3 distribution",500,0.,500.);
  TH1F *h_jet3_eta = new TH1F("h_jet3_eta","jet3 pseudorapidity distribution",100,-5.,5.);
  TH1F *h_jet3_phi = new TH1F("h_jet3_phi","jet phi distribution",100,-5.,5.);
  TH1F *h_jet3_m = new TH1F("h_jet3_m","jet mass distributions",100,0.,100);
  TH1F *h_jet4_pt = new TH1F("h_jet4_pt","jet4 distribution",500,0.,500.);
  TH1F *h_jet4_eta = new TH1F("h_jet4_eta","jet4 pseudorapidity distribution",100,-5.,5.);
  TH1F *h_jet4_phi = new TH1F("h_jet4_phi","jet phi distribution",100,-5.,5.);
  TH1F *h_jet4_m = new TH1F("h_jet4_m","jet mass distributions",100,0.,100);


  TH1F *h_b_jet1_pt = new TH1F("h_b_jet1_pt","bjet1 distribution",500,0.,500.);
  TH1F *h_b_jet1_eta = new TH1F("h_b_jet1_eta","bjet1 pseudorapidity distribution",100,-5.,5.);
  TH1F *h_b_jet1_phi = new TH1F("h_b_jet1_phi","bjet1 phi distribution",100,-5.,5.);
  TH1F *h_b_jet1_m = new TH1F("h_b_jet1_m","bjet1 mass distributions",100,0.,100);
  TH1F *h_b_jet2_pt = new TH1F("h_b_jet2_pt","bjet2 distribution",500,0.,500.);
  TH1F *h_b_jet2_eta = new TH1F("h_b_jet2_eta","bjet2 pseudorapidity distribution",100,-5.,5.);
  TH1F *h_b_jet2_phi = new TH1F("h_b_jet2_phi","bjet2 phi distribution",100,-5.,5.);
  TH1F *h_b_jet2_m = new TH1F("h_b_jet2_m","bjet2 mass distributions",100,0.,100);
  TH1F *h_b_jet3_pt = new TH1F("h_b_jet3_pt","bjet3 distribution",500,0.,500.);
  TH1F *h_b_jet3_eta = new TH1F("h_b_jet3_eta","bjet3 pseudorapidity distribution",100,-5.,5.);
  TH1F *h_b_jet3_phi = new TH1F("h_b_jet3_phi","bjet3 phi distribution",100,-5.,5.);
  TH1F *h_b_jet3_m = new TH1F("h_b_jet3_m","bjet3 mass distributions",100,0.,100);
  TH1F *h_b_jet4_pt = new TH1F("h_b_jet4_pt","bjet4 distribution",500,0.,500.);
  TH1F *h_b_jet4_eta = new TH1F("h_b_jet4_eta","bjet4 pseudorapidity distribution",100,-5.,5.);
  TH1F *h_b_jet4_phi = new TH1F("h_b_jet4_phi","bjet4 phi distribution",100,-5.,5.);
  TH1F *h_b_jet4_m = new TH1F("h_b_jet4_m","bjet4 mass distributions",100,0.,100);


  TH1F *h_met_pt = new TH1F("h_met_pt","met_pt distribution",100,0.,500.);


  //TH2F *h_met_mn_pt = new TH2F("h_met_mn_pt","MET-muon pt distribution",100,0.,500.,100,0.,500);
  //TH2F *h_met_en_pt = new TH2F("h_met_en_pt","MET-electron pt distribution",100,0.,500.,100,0.,500);


  TH1F *h_mt = new TH1F("h_mt","transverse mass distribution",100,0.,400.);


  TH1F *h_d_phi_w_h = new TH1F("h_d_phi_w_h","d_phi between W boson and Higgs boson",100,0.,M_PI);


  TH1F *h_jet_pt = new TH1F("h_jet_pt","jet_pt distribution",100,0.,500.);
  TH1F *h_h_pt = new TH1F("h_h_pt","h_pt distribution",100,0.,500.);
  TH1F *h_h_phi = new TH1F("h_h_phi","h_phi distribution",100,-5.,5.);
  TH1F *h_h_eta = new TH1F("h_h_eta","h_eta distribution",100,-5.,5.);
  TH1F *h_jet_m = new TH1F("h_jet_m","jets sum mass",200,0,1000);
  TH1F *h_inv_m = new TH1F("h_inv_m","invariant mass (after b_tagging)",200,0,1000);


  TH1F *h_H_T = new TH1F("h_H_T","H_T",100,0.,700.);

  TH1F *h_w_pt = new TH1F("h_w_pt","w_pt distribution",100,0.,500.);
  TH1F *h_w_phi = new TH1F("h_w_phi","w_phi distribution",100,-5.,5.);
  TH1F *h_w_eta = new TH1F("h_w_eta","w_eta distribution",100,-5.,5.);
  TH1F *h_w_m = new TH1F("h_w_m","w_m distribution",100,0.,300.);


  TH1F *h_dR_jet_muon = new TH1F("h_dR_jet_muon","dR between jet and muon distribution ",100,0.,6.);
  TH1F *h_dR_jet_electron = new TH1F("h_dR_jet_electron","dR between jet and electron distribution ",100,0.,6.);


  TH1F *h_dR_jet_muon_after=new TH1F("h_dR_jet_muon_after","dR between jets and muons",100,0.,6.);
  TH1F *h_dR_jet_electron_after=new TH1F("h_dR_jet_electron_after","dR between jets and electron",100,0.,6.);
  TH1F *h_jet_mult=new TH1F("h_jet_mult","jet multiplicity",10,0.,10.);
  TH1F *h_b_jet_mult=new TH1F("h_b_jet_mult","b_jet multiplicity",10,0.,10.);


  TH1F *h_lep_pt = new TH1F("h_lep_pt","Lepton pt distribution",100,0.,500.);
  TH1F *h_lep_phi = new TH1F("h_lep_phi","Lepton phi distribution",100,-5.,5.);
  TH1F *h_lep_eta = new TH1F("h_lep_eta","Lepton pseudorapidity distribution",100,-5.,5.);
  TH1F *h_lep_m = new TH1F("h_lep_m","Lepton mass distribution",100,0.,0.3);


  TH1F *h_dR_av = new TH1F("h_dR_av","Distance in the eta-phi plane between any b-tag pair, averaged over all possible combinations per event",100,0.,6.);


  TH1F *h_minDelta_m = new TH1F("h_minDelta_m","The minimum difference in m(b1b2) - m(b3b4) among the possible pairing scenarios",100,0.,50.);


  TH1F *h_d_phi_j_E = new TH1F("h_d_phi_j_E","Minimum azimuthal opening angle",100,0.,M_PI);


  TH1F *h_Nbjets_after = new TH1F("h_Nbjets_after","Number of jets after the cuts",10,0.,10.);


  TH1F *h_btag_0 = new TH1F("h_btag_0","b_tag_0 discriminator",50,0.,1.);
  TH1F *h_btag_1 = new TH1F("h_btag_1","b_tag_1 discriminator",50,0.,1.);
  TH1F *h_btag_2 = new TH1F("h_btag_2","b_tag_2 discriminator",50,0.,1.);
  TH1F *h_btag_3 = new TH1F("h_btag_3","b_tag_3 discriminator",50,0.,1.);


  

  TTree *my_tree = new TTree("my_tree","Global variables");
  Float_t mt;
  Float_t inv_m;
  Float_t met_pt_;
  Float_t btag_0;
  Float_t btag_1;
  Float_t btag_2;
  Float_t btag_3;
  Float_t lep_pt;
  Int_t Nbjets_after;
  Float_t w_pt;
  Float_t d_phi_w_h;
  Int_t Njets_after;
  Float_t dR_av;
  Float_t minDelta_m;
  Float_t d_phi_j_E;
  Float_t h_pt;
  Float_t H_T;
  my_tree->Branch("w",&w,"w/F");
  my_tree->Branch("mt",&mt,"mt/F");
  my_tree->Branch("inv_m",&inv_m,"inv_m/F");
  my_tree->Branch("met_pt",&met_pt,"met_pt/F");
  my_tree->Branch("btag_0",&btag_0,"btag_0/F");
  my_tree->Branch("btag_1",&btag_1,"btag_1/F");
  my_tree->Branch("btag_2",&btag_2,"btag_2/F");
  my_tree->Branch("btag_3",&btag_3,"btag_3/F");
  my_tree->Branch("lep_pt",&lep_pt,"lep_pt/F");
  my_tree->Branch("Nbjets_after",&Nbjets_after,"Nbjets_after/I");
  my_tree->Branch("w_pt",&w_pt,"w_pt/F");
  my_tree->Branch("d_phi_w_h",&d_phi_w_h,"d_phi_w_h/F");
  my_tree->Branch("Njets_after",&Njets_after,"Njets_after/I");
  my_tree->Branch("dR_av",&dR_av,"dR_av/F");
  my_tree->Branch("minDelta_m",&minDelta_m,"minDelta_m/F");
  my_tree->Branch("d_phi_j_E",&d_phi_j_E,"d_phi_j_E/F");
  my_tree->Branch("h_pt",&h_pt,"h_pt/F");
  my_tree->Branch("H_T",&H_T,"_H_T/F");

  Long64_t nbytes = 0, nb = 0;
  
  

  int count_N1(0);
  int count_N2(0);
  int count_N3(0);
  int count_N4(0);
  


for (Long64_t jentry=0; jentry<nentries;jentry++) {
  nb = fChain->GetEntry(jentry);   nbytes += nb;
  Long64_t ientry = LoadTree(jentry);


  // Require at least 1 lepton
  vector<TLorentzVector> vec_muons;
  vector<TLorentzVector> vec_electrons;
  vector<TLorentzVector> vec_leptons;


for (int i=0; i<mn; i++) {



	TLorentzVector p_muon;
	p_muon.SetPxPyPzE(mn_px[i],mn_py[i],mn_pz[i],mn_en[i]);
	


	// pt/eta cuts (detector acceptance cuts: pT>20 GeV and |eta|<2.4)
if (p_muon.Pt()<20. || fabs(p_muon.Eta())>2.4) continue;
	// Require muon to pass good Identification and Isolation:
if ( !(mn_passId[i]) || !(mn_passIso[i]) ) continue; 



	// store muons in new vector:
	vec_leptons.push_back(p_muon);
  vec_muons.push_back(p_muon);
 

}

  int Nmuons=vec_muons.size(); // Muon multiplicity
  

for (int i=0; i<en; i++) {



	TLorentzVector p_electron;
	p_electron.SetPxPyPzE(en_px[i],en_py[i],en_pz[i],en_en[i]);
	


	// pt/eta cuts (detector acceptance cuts: pT>20 GeV and |eta|<2.4)
if (p_electron.Pt()<20. || fabs(p_electron.Eta())>2.4) continue;
	// Require electron to pass good Identification and Isolation:
if ( !(en_passId[i]) || !(en_passIso[i]) ) continue; 

  

	// store muons in new vector:
	vec_leptons.push_back(p_electron);
  vec_electrons.push_back(p_electron);
 
}


  int Nelectrons=vec_electrons.size(); // Electron multiplicity
  int Nleptons=vec_leptons.size(); // Lepton multiplicity
if (Nleptons == 0) continue;



 count_N1++;
    

  TLorentzVector mn_p;
  //muon
if(Nmuons>=1) {
  mn_p.SetPxPyPzE(vec_muons[0].Px(),vec_muons[0].Py(),vec_muons[0].Pz(),vec_muons[0].E());
  float mn_eta=mn_p.Eta();
  float mn_phi=mn_p.Phi();
  float mn_pt=mn_p.Pt();
  h_mn_eta->Fill(mn_eta);
  h_mn_pt->Fill(mn_pt);
  h_mn_phi->Fill(mn_phi);
  //h_mn_pt_eta->Fill(mn_pt,mn_eta,w);
  //h_met_mn_pt->Fill(met_pt,mn_pt,w);
  //h_mn_phi_eta->Fill(mn_phi,mn_eta,w);
}




  TLorentzVector en_p;
if(Nelectrons>=1) {
  //electron
  en_p.SetPxPyPzE(vec_electrons[0].Px(),vec_electrons[0].Py(),vec_electrons[0].Pz(),vec_electrons[0].E());
  float en_eta=en_p.Eta();
  float en_phi=en_p.Phi();
  float en_pt=en_p.Pt();
  h_en_eta->Fill(en_eta);
  h_en_pt->Fill(en_pt);
  h_en_phi->Fill(en_phi);
  //h_en_pt_eta->Fill(en_pt,en_eta,w);
  //h_met_en_pt->Fill(met_pt,en_pt,w);
  //h_mn_en_phi->Fill(mn_phi,en_phi,w);
  
}


  //Cross cleaning
  vector<TLorentzVector> jet_vec;
  vector<TLorentzVector> Njet_vec;
  vector<TLorentzVector> bjet_vec;
  vector<float> btag(0);
for (Int_t ijet= 0; ijet < jet; ijet++)
{
  TLorentzVector pjet;
  pjet.SetPxPyPzE(jet_px[ijet],jet_py[ijet],jet_pz[ijet],jet_en[ijet]);
  

  //check muon jet overlap
  bool overlap(false);
  float dR_jet_muon=ROOT::Math::VectorUtil::DeltaR(pjet,mn_p);
  float dR_jet_electron=ROOT::Math::VectorUtil::DeltaR(pjet,en_p);
  h_dR_jet_muon->Fill(dR_jet_muon);
  h_dR_jet_electron->Fill(dR_jet_electron);
if (dR_jet_muon < 0.4 || dR_jet_electron < 0.4)
{
  overlap = true;
}
if (overlap)
{
  continue;
}
  jet_vec.push_back(pjet);
  btag.push_back(jet_btag1[ijet]);
  


  //b-jet indetification
  if (jet_btag1[ijet]>0.4941) bjet_vec.push_back(pjet);  
}  
  //cout<<" savvas "<< btag.size()<< " savvas  "<< jet_vec.size()<<endl;
  //std::cout << " before sorting " << bjet_vec[ijet] << std::endl;
  vector<btagsort> vec_struct_bjet;
  btagsort dummy_btagsort;


  //dR after cross cleaning
  TLorentzVector p_jet_after;
  int jet_mult;
  jet_mult=jet_vec.size();
  h_jet_mult->Fill(jet_mult);
for (int ijet_after = 0; ijet_after <jet_mult; ijet_after++)
{
  p_jet_after.SetPtEtaPhiE(jet_vec[ijet_after].Pt(),jet_vec[ijet_after].Eta(),jet_vec[ijet_after].Phi(),jet_vec[ijet_after].E());
  float dR_mn_jet_after=ROOT::Math::VectorUtil::DeltaR(p_jet_after,mn_p);
  float dR_en_jet_after=ROOT::Math::VectorUtil::DeltaR(p_jet_after,en_p);
  h_dR_jet_muon_after->Fill(dR_mn_jet_after);
  h_dR_jet_electron_after->Fill(dR_en_jet_after);
}



  // Require at least 3 jets
if(jet_mult<3) continue;
  count_N2++;



  int bjet_mult;
  bjet_mult=bjet_vec.size();
  h_b_jet_mult->Fill(bjet_mult);



if (bjet_mult<3) continue;
  count_N3++;
  //int Nbjets;
  //Nbjets=bjet_vec.size();



  //Transverse Mass (MT)
  TLorentzVector p_lepton;
  p_lepton.SetPtEtaPhiE(vec_leptons[0].Pt(),vec_leptons[0].Eta(),vec_leptons[0].Phi(),vec_leptons[0].E());
  float d_phi = std::abs(vec_leptons[0].Phi()-met_phi);
  if (d_phi>M_PI){
	d_phi=d_phi-(2*M_PI);
}
  Float_t MT;
  float lep_eta=p_lepton.Eta();
  lep_pt=p_lepton.Pt();
  float lep_phi=p_lepton.Phi();
  float lep_m=p_lepton.M();
  MT=sqrt(2*lep_pt*met_pt*(1-cos(d_phi)));
if (MT<50 || met_pt<30)continue;
  count_N4++;
  mt=MT;
  h_mt->Fill(MT);
  h_lep_pt->Fill(lep_pt);
  h_lep_phi->Fill(lep_phi);
  h_lep_m->Fill(lep_m);
  h_lep_eta->Fill(lep_eta);
  h_Nbjets_after->Fill(bjet_mult);
  Nbjets_after=bjet_mult;
  Njets_after=jet_mult;



for (int ijet = 0 ; ijet < btag.size(); ijet++){
  dummy_btagsort.vec = jet_vec[ijet];
  dummy_btagsort.btag1 = btag[ijet];
  vec_struct_bjet.push_back(dummy_btagsort);
}
for(int k=0; k<vec_struct_bjet.size(); k++){
//if (vec_struct_bjet[k].btag1>0.4941){
	//cout<<"before sorting "<<vec_struct_bjet[k].btag1<< "   "<<endl;
//}
}
  sort(vec_struct_bjet.begin(), vec_struct_bjet.end(), compare_btag);
for(int k=0; k<vec_struct_bjet.size(); k++){
//if (vec_struct_bjet[k].btag1>0.4941){
	//cout<<"after sorting "<<vec_struct_bjet[k].btag1<< "   "<<endl;
//}
 float btag1_value = vec_struct_bjet[k].btag1;

if (k == 0) {
  if(std::isnan(btag_0)){
  std::cout << "At entry = " << jentry << " the value of btag_0 is " << btag_0 <<std::endl;
  }
  h_btag_0->Fill(btag1_value);
  btag_0=btag1_value;
} else if (k == 1) {
  h_btag_1->Fill(btag1_value);
  btag_1=btag1_value;
} else if (k == 2) {
  h_btag_2->Fill(btag1_value);
  btag_2=btag1_value;
} else if (k == 3) {
  h_btag_3->Fill(btag1_value);
  btag_3=btag1_value;
}
}

  //jets pt & pseudorapidity  
  float jet1_eta=jet_vec[0].Eta();
  float jet1_pt=jet_vec[0].Pt();
  float jet1_phi=jet_vec[0].Phi();
  h_jet1_eta->Fill(jet1_eta);
  h_jet1_pt->Fill(jet1_pt);  
  h_jet1_phi->Fill(jet1_phi);
  float jet2_eta=jet_vec[1].Eta();
  float jet2_pt=jet_vec[1].Pt();
  float jet2_phi=jet_vec[1].Phi();
  h_jet2_eta->Fill(jet2_eta);
  h_jet2_pt->Fill(jet2_pt);
  h_jet2_phi->Fill(jet2_phi);
  float jet3_eta=jet_vec[2].Eta();
  float jet3_pt=jet_vec[2].Pt();
  float jet3_phi=jet_vec[2].Phi();
  float jet3_m=jet_vec[2].M();
  h_jet3_eta->Fill(jet3_eta);
  h_jet3_pt->Fill(jet3_pt);
  h_jet3_phi->Fill(jet3_phi);
if(jet_mult>3){
  float jet4_eta=jet_vec[3].Eta();
  float jet4_pt=jet_vec[3].Pt();
  float jet4_phi=jet_vec[3].Phi();
  h_jet4_eta->Fill(jet4_eta);
  h_jet4_pt->Fill(jet4_pt);
  h_jet4_phi->Fill(jet4_phi);
}



  //bjets pt & pseudorapidity  
  float bjet1_eta=bjet_vec[0].Eta();
  float bjet1_pt=bjet_vec[0].Pt();
  float bjet1_phi=bjet_vec[0].Phi();
  h_b_jet1_eta->Fill(bjet1_eta);
  h_b_jet1_pt->Fill(bjet1_pt);  
  h_b_jet1_phi->Fill(bjet1_phi);
  float bjet2_eta=bjet_vec[1].Eta();
  float bjet2_pt=bjet_vec[1].Pt();
  float bjet2_phi=bjet_vec[1].Phi();
  h_b_jet2_eta->Fill(bjet2_eta);
  h_b_jet2_pt->Fill(bjet2_pt);
  h_b_jet2_phi->Fill(bjet2_phi);
  float bjet3_eta=bjet_vec[2].Eta();
  float bjet3_pt=bjet_vec[2].Pt();
  float bjet3_phi=bjet_vec[2].Phi();
  h_b_jet3_eta->Fill(bjet3_eta);
  h_b_jet3_pt->Fill(bjet3_pt);
  h_b_jet3_phi->Fill(bjet3_phi);
if(bjet_mult>3){
  float bjet4_eta=bjet_vec[3].Eta();
  float bjet4_pt=bjet_vec[3].Pt();
  float bjet4_phi=bjet_vec[3].Phi();
  h_b_jet4_eta->Fill(bjet4_eta);
  h_b_jet4_pt->Fill(bjet4_pt);
  h_b_jet4_phi->Fill(bjet4_phi);
}



  
  TLorentzVector jet_p=jet_vec[0]+jet_vec[1]+jet_vec[2];
  //invariant mass
  TLorentzVector h_b_p=bjet_vec[0]+bjet_vec[1]+bjet_vec[2];
  


if (jet_mult>3)
{
  jet_p+=jet_vec[3];
}
if (bjet_mult>3)
{
  h_b_p+=bjet_vec[3];
}



  //float jet_m=jet_p.M();
  float jet_phi=jet_p.Phi();
  float jet_pt=jet_p.Pt();
  float jet_eta=jet_p.Eta();
  inv_m=h_b_p.M();
  float h_phi=h_b_p.Phi();
  h_pt=h_b_p.Pt();
  float h_eta=h_b_p.Eta();
  h_h_phi->Fill(h_phi);
  h_h_eta->Fill(h_eta);
  h_h_pt->Fill(jet_p.Pt());
  h_inv_m->Fill(h_b_p.M());
  H_T=0.;
for (int i = 0; i < jet_vec.size(); i++)
{
  H_T+=jet_vec[i].Pt();
}
  h_H_T->Fill(H_T);


  //MET
  h_met_pt->Fill(met_pt);
  met_pt_=met_pt;


  //W boson
  TLorentzVector met_p;
  met_p.SetPtEtaPhiE(met_pt,0,met_phi,0);
  TLorentzVector w_p=met_p+vec_leptons[0];
  w_pt=w_p.Pt();
  float w_phi=w_p.Phi();
  float w_eta=w_p.Eta();
  float w_m=w_p.M();
  h_w_pt->Fill(w_pt);
  h_w_eta->Fill(w_eta);
  h_w_phi->Fill(w_phi);
  h_w_m->Fill(w_m);


  //D_phi
  d_phi_w_h=abs(w_p.DeltaPhi(h_b_p));
  h_d_phi_w_h->Fill(d_phi_w_h);



  //scalar sum of the handronic activity
  h_jet_pt->Fill(jet_pt);
  //h_jet_phi->Fill(jet_phi,w);
  //h_jet_eta->Fill(jet_eta,w);


  
  //dR(b,b)^{ave}
  TLorentzVector had_p = bjet_vec[0] + bjet_vec[1] + bjet_vec[2];
  float dR_01 = ROOT::Math::VectorUtil::DeltaR(bjet_vec[0],bjet_vec[1]);
  float dR_02 = ROOT::Math::VectorUtil::DeltaR(bjet_vec[0],bjet_vec[2]);
  float dR_12 = ROOT::Math::VectorUtil::DeltaR(bjet_vec[1],bjet_vec[2]);
if (bjet_mult>3){
  float dR_03 = ROOT::Math::VectorUtil::DeltaR(bjet_vec[0],bjet_vec[3]);
  float dR_13 = ROOT::Math::VectorUtil::DeltaR(bjet_vec[1],bjet_vec[3]);
  float dR_23 = ROOT::Math::VectorUtil::DeltaR(bjet_vec[2],bjet_vec[3]);
  dR_av = (dR_01 + dR_02 + dR_12 + dR_23 + dR_03 + dR_13) / 6.;
  //Delta{m_{b,b}}_min
  float m1 = std::abs((bjet_vec[0].M() + bjet_vec[1].M()) - (bjet_vec[2].M() + bjet_vec[3].M()));
  float m2 = std::abs((bjet_vec[0].M() + bjet_vec[2].M()) - (bjet_vec[1].M() + bjet_vec[3].M()));
  float m3 = std::abs((bjet_vec[0].M() + bjet_vec[3].M()) - (bjet_vec[1].M() + bjet_vec[2].M()));
  minDelta_m = TMath::Min(m3,TMath::Min(m1,m2));
  h_minDelta_m->Fill(minDelta_m);
}else {
  dR_av = (dR_01 + dR_02 + dR_12)/3.;
}
  h_dR_av->Fill(dR_av);

  //Delta_phi
  float min_dphi=100000;
for (int i=0; i<bjet_vec.size(); i++){
if (bjet_vec[i].DeltaPhi(met_p)<min_dphi){
  min_dphi=bjet_vec[i].DeltaPhi(met_p);
}
}
  h_d_phi_j_E->Fill(min_dphi);
  d_phi_j_E=min_dphi;
  my_tree->Fill();
  //tree->Print();
  

  


if (ientry < 0) break;
  // if (Cut(ientry) < 0) continue;
} // end EVENT loop


  


  std::cout << " Number of entries = " << totalNumberofEvents << std::endl;
  std::cout << " Nevents at step 1 (at least 1 lepton) = " << count_N1 << " and eff_1 = " << (float)count_N1/(float)totalNumberofEvents << " and Nexpected " << N_expected << std::endl;
  std::cout << " Nevents at step 2 (at least 3 jets) = " << count_N2 << " and eff_2 =" << (float)count_N2/(float)totalNumberofEvents <<  " and Nexpected " << N_expected*((float)count_N2/(float)totalNumberofEvents) << std::endl;
  std::cout << " Nevents at step 3 (at least 3 b-jets) = " << count_N3 << " and eff_3 = " << (float)count_N3/(float)totalNumberofEvents <<  " and Nexpected " << N_expected*((float)count_N3/(float)totalNumberofEvents) << std::endl;;
  std::cout << " Nevents at step 4 (MT > 50 and MET >30) = " << count_N4 << " and eff_4 = " << (float)count_N4/(float)totalNumberofEvents <<  " and Nexpected " << N_expected*((float)count_N4/(float)totalNumberofEvents) << std::endl;;



  h_mn_pt->Write();
  h_mn_eta->Write();
  h_mn_phi->Write();
  //h_mn_pt_eta->Write();
  //h_mn_en_phi->Write();
  h_en_pt->Write();
  h_en_eta->Write();
  h_en_phi->Write();
  //h_en_pt_eta->Write();
  h_jet1_pt->Write();
  h_jet1_eta->Write();
  h_jet1_phi->Write();
  h_jet2_pt->Write();
  h_jet2_eta->Write();
  h_jet2_phi->Write();
  h_jet3_pt->Write();
  h_jet3_eta->Write();
  h_jet3_phi->Write();
  h_jet4_pt->Write();
  h_jet4_eta->Write();
  h_jet4_phi->Write();
  h_b_jet1_pt->Write(); 
  h_b_jet1_eta->Write();
  h_b_jet1_phi->Write();
  h_b_jet2_pt->Write();
  h_b_jet2_eta->Write();
  h_b_jet2_phi->Write();
  h_b_jet3_pt->Write();
  h_b_jet3_eta->Write();
  h_b_jet3_phi->Write();
  h_b_jet4_pt->Write();
  h_b_jet4_eta->Write();
  h_b_jet4_phi->Write();
  h_met_pt->Write();
  //h_met_mn_pt->Write();
  //h_met_en_pt->Write();
  h_mt->Write();
  h_d_phi_w_h->Write();
  h_jet_pt->Write();
  h_h_pt->Write();
  h_h_phi->Write();
  h_h_eta->Write();
  //h_jet_m->Write();
  h_inv_m->Write();
  h_w_pt->Write();
  h_w_phi->Write();
  h_w_eta->Write();
  h_w_m->Write();
  h_lep_pt->Write();
  h_lep_phi->Write();
  h_lep_eta->Write();
  h_lep_m->Write();
  h_dR_jet_muon->Write();
  h_dR_jet_electron->Write();
  h_dR_jet_muon_after->Write();
  h_dR_jet_electron_after->Write();
  h_jet_mult->Write();
  h_b_jet_mult->Write();
  h_dR_av->Write();
  h_minDelta_m->Write();
  h_d_phi_j_E->Write();
  h_Nbjets_after->Write();
  //h_mn_phi_eta->Write();
  h_btag_0->Write();
  h_btag_1->Write();
  h_btag_2->Write();
  h_btag_3->Write();
  my_tree->Write();
  f.Close();
}

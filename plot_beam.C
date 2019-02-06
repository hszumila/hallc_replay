#include <TSystem.h>
#include <TString.h>
#include "TFile.h"
#include "TTree.h"
#include <TNtuple.h>
#include "TCanvas.h"
#include <iostream>
#include <fstream>
#include "TMath.h"
#include "TH1F.h"
#include <TH2.h>
#include <TStyle.h>
#include <TGraph.h>
#include <TROOT.h>
#include <TMath.h>
#include <TLegend.h>
#include <TPaveLabel.h>
#include <TProfile.h>
#include <TObjArray.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include<math.h>
using namespace std;

void plot_beam(Int_t nrun=2187){
  TString basename="";
  /*
   if (basename=="") {
     cout << " Input the basename of the root file (assumed to be in worksim)" << endl;
     cin >> basename;
   }
  */
  basename=Form("coin_replay_production_%i",nrun);
  //basename=Form("hms_replay_production_all_%i",nrun);
gStyle->SetPalette(1,0);
 gStyle->SetOptStat(11111);
 gStyle->SetOptFit(11);
 gStyle->SetTitleOffset(1.,"Y");
 gStyle->SetTitleOffset(.7,"X");
 gStyle->SetLabelSize(0.04,"XY");
 gStyle->SetTitleSize(0.06,"XY");
 gStyle->SetPadLeftMargin(0.12);
   TString inputroot;
   inputroot="ROOTfiles/"+basename+"_1000000.root";
   TString outputhist;
   outputhist= "plots/"+basename+"_hist.root";
 TObjArray HList(0);
     TString outputpdf;
    outputpdf=basename+".pdf";
 TString htitle=basename;
 TPaveLabel *title = new TPaveLabel(.15,.90,0.95,.99,htitle,"ndc");
 //
TFile *fsimc = new TFile(inputroot); 
TTree *tsimc = (TTree*) fsimc->Get("E");
TTree *tt = (TTree*) fsimc->Get("T");

// Define branches
 Double_t  ibcm1;
   tsimc->SetBranchAddress("ibcm1",&ibcm1);
 Double_t  SAXpos;
   tsimc->SetBranchAddress("IPM3H07A.XPOS",&SAXpos);
 Double_t  SAXraw;
   tsimc->SetBranchAddress("IPM3H07A.XRAW",&SAXraw);
 Double_t  SAYpos;
   tsimc->SetBranchAddress("IPM3H07A.YPOS",&SAYpos);
 Double_t  SAYraw;
   tsimc->SetBranchAddress("IPM3H07A.YRAW",&SAYraw);
 Double_t  SBXpos;
   tsimc->SetBranchAddress("IPM3H07B.XPOS",&SBXpos);
 Double_t  SBXraw;
   tsimc->SetBranchAddress("IPM3H07B.XRAW",&SBXraw);
 Double_t  SBYpos;
   tsimc->SetBranchAddress("IPM3H07B.YPOS",&SBYpos);
 Double_t  SBYraw;
   tsimc->SetBranchAddress("IPM3H07B.YRAW",&SBYraw);
 Double_t  SCXpos;
   tsimc->SetBranchAddress("IPM3H07C.XPOS",&SCXpos);
 Double_t  SCXraw;
   tsimc->SetBranchAddress("IPM3H07C.XRAW",&SCXraw);
 Double_t  SCYpos;
   tsimc->SetBranchAddress("IPM3H07C.YPOS",&SCYpos);
 Double_t  SCYraw;
   tsimc->SetBranchAddress("IPM3H07C.YRAW",&SCYraw);
   //Double_t  HMSzpos;
   //tt->SetBranchAddress("H.react.z",&HMSzpos);
 Double_t  SHMSzpos;
   tt->SetBranchAddress("P.react.z",&SHMSzpos);
   //Double_t HMS_beta;
   //tt->SetBranchAddress("H.gtr.beta",&HMS_beta);
   Double_t SHMS_beta;
   tt->SetBranchAddress("P.gtr.beta",&SHMS_beta);
   //Double_t HMS_cer;
   //tt->SetBranchAddress("H.cer.npeSum",&HMS_cer);
   Double_t SHMS_cer;
   tt->SetBranchAddress("P.hgcer.npeSum",&SHMS_cer);
   //Double_t HMS_delta;
   //tt->SetBranchAddress("H.gtr.dp",&HMS_delta);
   Double_t SHMS_delta;
   tt->SetBranchAddress("P.gtr.dp",&SHMS_delta);


   Double_t Xtar_AB;
   Double_t Ytar_AB;
   Double_t Xtar_AC;
   Double_t Ytar_AC;
   Double_t Xtar_BC;
   Double_t Ytar_BC;

   TFile * fout = new TFile(outputhist,"RECREATE");


  // Define histograms
   TH1F *hSAXraw = new TH1F("hSAXraw",Form("Run %d ; SAX Raw (mm); Counts",nrun),100,-5,5);
   TH1F *hSAYraw = new TH1F("hSAYraw",Form("Run %d ; SAY Raw (mm); Counts",nrun),100,-5,5);
   TH1F *hSBXraw = new TH1F("hSBXraw",Form("Run %d ; SBX Raw (mm); Counts",nrun),100,-5,5);
   TH1F *hSBYraw = new TH1F("hSBYraw",Form("Run %d ; SBY Raw (mm); Counts",nrun),100,-5,5);
   TH1F *hSCXraw = new TH1F("hSCXraw",Form("Run %d ; SCX Raw (mm); Counts",nrun),100,-5,5);
   TH1F *hSCYraw = new TH1F("hSCYraw",Form("Run %d ; SCY Raw (mm); Counts",nrun),100,-5,5);
   TH1F *hSAXpos = new TH1F("hSAXpos",Form("Run %d ; SAX Pos (mm); Counts",nrun),100,-5,5);
   TH1F *hSAYpos = new TH1F("hSAYpos",Form("Run %d ; SAY Pos (mm); Counts",nrun),100,-5,5);
   TH1F *hSBXpos = new TH1F("hSBXpos",Form("Run %d ; SBX Pos (mm); Counts",nrun),100,-5,5);
   TH1F *hSBYpos = new TH1F("hSBYpos",Form("Run %d ; SBY Pos (mm); Counts",nrun),100,-5,5);
   TH1F *hSCXpos = new TH1F("hSCXpos",Form("Run %d ; SCX Pos (mm); Counts",nrun),100,-5,5);
   TH1F *hSCYpos = new TH1F("hSCYpos",Form("Run %d ; SCY Pos (mm); Counts",nrun),100,-5,5);
   TH1F *hXtar_AB = new TH1F("hXtar_AB",Form("Run %d ; X target (use AB) (mm); Counts",nrun),100,-5,5);
   TH1F *hYtar_AB = new TH1F("hYtar_AB",Form("Run %d ; Y target (use AB) (mm); Counts",nrun),100,-5,5);
   TH1F *hYptar_AB = new TH1F("hYptar_AB",Form("Run %d ; Y' target (use AB) (mm); Counts",nrun),100,-0.05,0.05);
   TH1F *hXtar_AC = new TH1F("hXtar_AC",Form("Run %d ; X target (use AC) (mm); Counts",nrun),100,-5,5);
   TH1F *hYtar_AC = new TH1F("hYtar_AC",Form("Run %d ; Y target (use AC) (mm); Counts",nrun),100,-5,5);
   TH1F *hYptar_AC = new TH1F("hYptar_AC",Form("Run %d ; Y' target (use AC) (mm); Counts",nrun),100,-0.05,0.05);
   TH1F *hXtar_BC = new TH1F("hXtar_BC",Form("Run %d ; X target (use BC) (mm); Counts",nrun),100,-5,5);
   TH1F *hYtar_BC = new TH1F("hYtar_BC",Form("Run %d ; Y target (use BC) (mm); Counts",nrun),100,-5,5);
   TH1F *hYptar_BC = new TH1F("hYptar_BC",Form("Run %d ; Y' target (use BC) (mm); Counts",nrun),100,-0.05,0.05);
   TH1F *hz = new TH1F("hz",Form("Run %d ; HMS react.z; Counts",nrun),100,-5,5);
   TH1F *sz = new TH1F("sz",Form("Run %d ; SHMS react.z; Counts",nrun),100,-5,5);
   TH1F *zdiff = new TH1F("zdiff",Form("Run %d ; SHMS - HMS react.z; Counts",nrun),100,-5,5);

   // loop through data
   Double_t SA_zpos, SB_zpos,SC_zpos,SAX_off,SAY_off,SBX_off,SBY_off,SCX_off,SCY_off,SAX_scale, SAY_scale,SBX_scale,SBY_scale,SCX_scale,SCY_scale;
   

   if(nrun<6000){
     SA_zpos=320.42*10.; //mm
     SB_zpos=224.86*10.; //mm
     SC_zpos=129.44*810.; //mm
     SAX_off = -0.05;
     SAY_off = -0.2;
     SBX_off = 0.08;
     SBY_off = +0.38;
     SCX_off = -0.89;
     SCY_off = +0.47;
     SAX_scale = -0.98;
     SAY_scale = 0.97;
     SBX_scale = -1.12;
     SBY_scale = 1.17;
     SCX_scale = -0.96;
     SCY_scale = 0.47;
   }
   else{
     SA_zpos=320.17; //mm
     SB_zpos=224.81; //mm
     SC_zpos=129.38; //mm
     SAX_off = -0.05+0.21;
     SAY_off = -0.2+0.36;
     SBX_off = 0.08+0.12;
     SBY_off = +0.38+0.36;
     SCX_off = -0.89-0.29;
     SCY_off = +0.47+0.31;
     SAX_scale = -0.98;
     SAY_scale = 0.97;
     SBX_scale = -1.12;
     SBY_scale = 1.17;
     SCX_scale = -0.96;
     SCY_scale = 0.47;
   }
Long64_t nentries = tsimc->GetEntries();
	for (int i = 0; i < nentries; i++) {
      		tsimc->GetEntry(i);
                if (ibcm1>0.1) {
		  hSAXraw->Fill(SAXraw);
		  hSAYraw->Fill(SAYraw);
		  hSBXraw->Fill(SBXraw);
		  hSBYraw->Fill(SBYraw);
		  hSCXraw->Fill(SCXraw);
		  hSCYraw->Fill(SCYraw);
		  SAXpos=SAX_off-SAX_scale*SAXraw;
		  SAYpos=SAY_off+SAY_scale*SAYraw;
		  SBXpos=SBX_off-SBX_scale*SBXraw;
		  SBYpos=SBY_off+SBY_scale*SBYraw;
		  SCXpos=SCX_off-SCX_scale*SCXraw;
		  SCYpos=SCY_off+SCY_scale*SCYraw;
		  hSAXpos->Fill(SAXpos);
		  hSAYpos->Fill(SAYpos);
		  hSBXpos->Fill(SBXpos);
		  hSBYpos->Fill(SBYpos);
		  hSCXpos->Fill(SCXpos);
		  hSCYpos->Fill(SCYpos);
		  Xtar_AB = SAXpos - (SAXpos-SBXpos)/(SA_zpos-SB_zpos)*SA_zpos;
		  Ytar_AB = SAYpos - (SAYpos-SBYpos)/(SA_zpos-SB_zpos)*SA_zpos;
		  Xtar_AC = SAXpos - (SAXpos-SCXpos)/(SA_zpos-SC_zpos)*SA_zpos;
		  Ytar_AC = SAYpos - (SAYpos-SCYpos)/(SA_zpos-SC_zpos)*SA_zpos;
		  Xtar_BC = SBXpos - (SBXpos-SCXpos)/(SB_zpos-SC_zpos)*SB_zpos;
		  Ytar_BC = SBYpos - (SBYpos-SCYpos)/(SB_zpos-SC_zpos)*SB_zpos;
		  hXtar_AB->Fill(Xtar_AB);
		  hYtar_AB->Fill(Ytar_AB);
		  hYptar_AB->Fill((SAYpos-SBYpos)/(SA_zpos-SB_zpos));
		  hXtar_AC->Fill(Xtar_AC);
		  hYtar_AC->Fill(Ytar_AC);
		  hYptar_AC->Fill((SAYpos-SCYpos)/(SA_zpos-SC_zpos));
		  hXtar_BC->Fill(Xtar_BC);
		  hYtar_BC->Fill(Ytar_BC);
		  hYptar_BC->Fill((SBYpos-SCYpos)/(SB_zpos-SC_zpos));

		}
	}
	/*
Long64_t nentries2 = tt->GetEntries();
	for (int i = 0; i < nentries2; i++) {
      		tt->GetEntry(i);
                if (max(HMSzpos,SHMSzpos)<20 && SHMS_beta>0.6 && SHMS_beta<1.5 && HMS_beta>0.8&& HMS_beta<1.2 && SHMS_cer<0.1 && HMS_cer>0.0 && abs(HMS_delta)<8 && abs(SHMS_delta)<10) {
		  hz->Fill(HMSzpos);
		  sz->Fill(SHMSzpos);
		  zdiff->Fill(SHMSzpos - HMSzpos);
		}
	}
	*/
	// plot
TCanvas *c1 = new TCanvas("c1", "Target", 900,800);
c1->Divide(2,3);
 c1->cd(1);
 hXtar_AB->Draw();
 c1->cd(2);
 hYtar_AB->Draw();
 c1->cd(3);
 hXtar_AC->Draw();
 c1->cd(4);
   hYtar_AC->Draw();
 c1->cd(5);
  hXtar_BC->Draw();
 c1->cd(6);
 hYtar_BC->Draw();
   outputpdf="plots/"+basename+"_beam.pdf";
   c1->Update();
   c1->Draw();
   c1->Write();
   fout->Save();
c1->Print(outputpdf+"(");

TCanvas *c2 = new TCanvas("c2", "Spectrometer z position", 900,800);
c2->Divide(1,3);
 c2->cd(1);
 hz->Draw();
 c2->cd(2);
 sz->Draw();
 c2->cd(3);
 zdiff->Draw();
   c2->Update();
   c2->Draw();
   c2->Write();
   fout->Save();
c2->Print(outputpdf+"(");

TCanvas *c3 = new TCanvas("c3", "Angle at Target", 900,800);
c3->Divide(1,3);
 c3->cd(1);
 hYptar_AB->Draw();
 c3->cd(2);
 hYptar_AC->Draw();
 c3->cd(3);
 hYptar_BC->Draw();
 outputpdf="plots/"+basename+"_beam.pdf";
 c3->Update();
 c3->Draw();
 c3->Write();
 fout->Save();
 c3->Print(outputpdf+")");
 fout->Write();
 fout->Close();


}

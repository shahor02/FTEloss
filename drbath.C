{

  gROOT->LoadMacro("dr.C");
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  /*
  HistoManager* hcs = new HistoManager("","detCyl2T_ITS.root",1,"hcs");
  HistoManager* hcg = new HistoManager("","detCyl2T_GLO.root",1,"hcg");
  //
  HistoManager* hcps = new HistoManager("","detCyl2T_bp28_ITS.root",1,"hcps");
  HistoManager* hcpg = new HistoManager("","detCyl2T_bp28_GLO.root",1,"hcpg");
  */
  HistoManager* hcs = new HistoManager("","itsUp_Deut_ITS.root",1,"hcs");
  HistoManager* hcg = new HistoManager("","itsUp_Deut_GLO.root",1,"hcg");
  //
  HistoManager* hcps = new HistoManager("","itsCyl_deut_ITS.root",1,"hcps");
  HistoManager* hcpg = new HistoManager("","itsCyl_deut_GLO.root",1,"hcpg");
  //
  //  HistoManager* hss = new HistoManager("","detStd2T_ITS.root",1,"hss");
  //  HistoManager* hsg = new HistoManager("","detStd2T_GLO.root",1,"hsg");
  
  //
  dr(hcs, kRed, 2, 1, kFALSE, "ITS2");
  dr(hcg, kRed, 3, 2, kTRUE, "");
  //
  dr(hcps, kGreen+2, 2, 1, kTRUE, "ITS3");
  dr(hcpg, kGreen+2, 3, 2, kTRUE, "");
  //
  //  dr(hss, kBlue, 2, 1, kTRUE, "ITS2");
  // dr(hsg, kBlue, 3, 2, kTRUE, "");
  //
  TGraph* gitssa = (TGraph*)hcs->GetGraph(0)->Clone("itssa");
  TGraph* gitstpc = (TGraph*)hcg->GetGraph(0)->Clone("itstpc");
  gitssa->SetLineColor(kBlack);
  gitstpc->SetLineColor(kBlack);
  TLegendEntry* lge1 = lg->AddEntry(gitssa,"ITS only","lp");
  lge1->SetTextColor(kBlack);
  lge1->SetTextFont(62);
  TLegendEntry* lge2 = lg->AddEntry(gitstpc,"ITS+TPC","lp");
  lge2->SetTextColor(kBlack);
  lge2->SetTextFont(62);

  lg->SetHeader("Deuteron");
  
  cnv[0]->cd();
  lg->Draw();

  cnv[2]->cd();
  lg->Draw();
  
}

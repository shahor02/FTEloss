TCanvas *cnv[4] = {0};
TLegend *lg = 0;

void dr(HistoManager* hm, Int_t color=0, Int_t linewidth=0, Int_t linestyle=0, Bool_t same=kFALSE, const char* cmt="")
{
  for (int i=0;i<4;i++) {
    if (!cnv[i]) {
      cnv[i] = new TCanvas(Form("cnv%d",i),Form("cnv%d",i));
      cnv[i]->Clear();
      cnv[i]->cd();
      cnv[i]->SetBottomMargin(0.15);
      cnv[i]->SetLeftMargin(0.15);
      gPad->SetGrid();

      if (i==0) {
	lg = new TLegend(0.4,0.2,0.8,0.6);
	same = kFALSE;
      }
    }
  }

  gStyle->SetOptStat(0);
  TString opt = same ? "l" : "al";
  TString legComm = cmt;
  cnv[0]->cd();
  hm->GetGraph(0)->Draw(opt.Data());
  gPad->SetLogx();
  if (color>0) hm->GetGraph(0)->SetLineColor(color);
  if (linewidth>0) hm->GetGraph(0)->SetLineWidth(linewidth);
  hm->GetGraph(0)->SetLineStyle(linestyle);
  gPad->Modified();
  hm->GetGraph(0)->GetHistogram()->GetXaxis()->SetTitleSize(0.05);
  hm->GetGraph(0)->GetHistogram()->GetYaxis()->SetTitleSize(0.05);
  hm->GetGraph(0)->GetHistogram()->GetXaxis()->SetTitleOffset(1.33);
  hm->GetGraph(0)->GetHistogram()->GetYaxis()->SetTitleOffset(1.2);
  hm->GetGraph(0)->GetHistogram()->GetXaxis()->SetRangeUser(0.05,1.);
  if (!legComm.IsNull()) {
    TLegendEntry* lge = lg->AddEntry(hm->GetGraph(0),legComm.Data(),"lp");
    lge->SetTextColor(color);
    lge->SetTextFont(62);
  }
  //
  cnv[1]->cd();
  hm->GetGraph(1)->Draw(opt.Data());
  hm->GetGraph(1)->SetMinimum(0.5);
  hm->GetGraph(1)->SetMaximum(30.);
  //hm->GetGraph(1)->SetMinimum(0.1); // for 5kG
  //hm->GetGraph(1)->SetMaximum(10.);
  
  gPad->SetLogy();  gPad->SetLogx();
  if (color>0) hm->GetGraph(1)->SetLineColor(color);
  hm->GetGraph(1)->SetLineStyle(linestyle);
  if (linewidth>0) hm->GetGraph(1)->SetLineWidth(linewidth);
  gPad->Modified();
  hm->GetGraph(1)->GetHistogram()->GetXaxis()->SetTitleSize(0.05);
  hm->GetGraph(1)->GetHistogram()->GetYaxis()->SetTitleSize(0.05);
  hm->GetGraph(1)->GetHistogram()->GetXaxis()->SetTitleOffset(1.33);
  hm->GetGraph(1)->GetHistogram()->GetYaxis()->SetTitleOffset(1.2);

  //
  cnv[2]->cd();
  hm->GetGraph(2)->Draw(opt.Data());
  gPad->SetLogy();  gPad->SetLogx();
  if (color>0) hm->GetGraph(2)->SetLineColor(color);
  hm->GetGraph(2)->SetLineStyle(linestyle);
  if (linewidth>0) hm->GetGraph(2)->SetLineWidth(linewidth);
  gPad->Modified();
  hm->GetGraph(2)->GetHistogram()->GetXaxis()->SetTitleSize(0.05);
  hm->GetGraph(2)->GetHistogram()->GetYaxis()->SetTitleSize(0.05);
  hm->GetGraph(2)->GetHistogram()->GetXaxis()->SetTitleOffset(1.33);
  hm->GetGraph(2)->GetHistogram()->GetYaxis()->SetTitleOffset(1.2);

  
  //
  cnv[3]->cd();
  hm->GetGraph(3)->Draw(opt.Data());
  gPad->SetLogy();  gPad->SetLogx();
  if (color>0) hm->GetGraph(3)->SetLineColor(color);
  hm->GetGraph(3)->SetLineStyle(linestyle);
  if (linewidth>0) hm->GetGraph(3)->SetLineWidth(linewidth);
  gPad->Modified();
  hm->GetGraph(3)->GetHistogram()->GetXaxis()->SetTitleSize(0.05);
  hm->GetGraph(3)->GetHistogram()->GetYaxis()->SetTitleSize(0.05);
  hm->GetGraph(3)->GetHistogram()->GetXaxis()->SetTitleOffset(1.33);
  hm->GetGraph(3)->GetHistogram()->GetYaxis()->SetTitleOffset(1.2);
}

using namespace RooFit;

void mc_cocktailFitter(){
    TCanvas* c1 = new TCanvas("","",1920,980);
    RooRealVar Mpi0eta("Mpi0eta","Mpi0eta",0,3);
    RooPlot* massPlot = Mpi0eta.frame(Title("Mpi0eta")); 
    TLegend* leg1 = new TLegend(0.6,0.6,0.89,0.89);

    // a2pi
    TH1F* Mpi0eta_a2pi;
    TFile* data_a2pi = TFile::Open("a2pi/degALL_a2pi_hists_DSelector.root");
    data_a2pi->GetObject("pi0eta1D_Cut",Mpi0eta_a2pi);
    cout << "Bins in Mpi0eta_a2pi: " << Mpi0eta_a2pi->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_a2pi("dHist_Mpi0eta_a2pi","dHist_Mpi0eta_a2pi",Mpi0eta,Mpi0eta_a2pi);
    RooHistPdf dPdf_Mpi0eta_a2pi("dPdf_Mpi0eta_a2pi","dPdf_Mpi0eta_a2pi",Mpi0eta,dHist_Mpi0eta_a2pi,1);

    // b1to5g 
    TH1F* Mpi0eta_b1to5g;
    TFile* data_b1to5g = TFile::Open("b1to5g/degALL_b1to5g_hists_DSelector.root");
    data_b1to5g->GetObject("pi0eta1D_Cut",Mpi0eta_b1to5g);
    cout << "Bins in Mpi0eta_b1to5g: " << Mpi0eta_b1to5g->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_b1to5g("dHist_Mpi0eta_b1to5g","dHist_Mpi0eta_b1to5g",Mpi0eta,Mpi0eta_b1to5g);
    RooHistPdf dPdf_Mpi0eta_b1to5g("dPdf_Mpi0eta_b1to5g","dPdf_Mpi0eta_b1to5g",Mpi0eta,dHist_Mpi0eta_b1to5g,1);

    // f1_1285_to_etapipi
    TH1F* Mpi0eta_f1_1285_to_etapipi;
    TFile* data_f1_1285_to_etapipi = TFile::Open("f1_1285_to_etapipi/degALL_f1_1285_to_etapipi_hists_DSelector.root");
    data_f1_1285_to_etapipi->GetObject("pi0eta1D_Cut",Mpi0eta_f1_1285_to_etapipi);
    cout << "Bins in Mpi0eta_f1_1285_to_etapipi: " << Mpi0eta_f1_1285_to_etapipi->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_f1_1285_to_etapipi("dHist_Mpi0eta_f1_1285_to_etapipi","dHist_Mpi0eta_f1_1285_to_etapipi",Mpi0eta,Mpi0eta_f1_1285_to_etapipi);
    RooHistPdf dPdf_Mpi0eta_f1_1285_to_etapipi("dPdf_Mpi0eta_f1_1285_to_etapipi","dPdf_Mpi0eta_f1_1285_to_etapipi",Mpi0eta,dHist_Mpi0eta_f1_1285_to_etapipi,1);

    // eta_to_3pi
    TH1F* Mpi0eta_eta_to_3pi;
    TFile* data_eta_to_3pi = TFile::Open("eta_to_3pi/degALL_eta_to_3pi_hists_DSelector.root");
    data_eta_to_3pi->GetObject("pi0eta1D_Cut",Mpi0eta_eta_to_3pi);
    cout << "Bins in Mpi0eta_eta_to_3pi: " << Mpi0eta_eta_to_3pi->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_eta_to_3pi("dHist_Mpi0eta_eta_to_3pi","dHist_Mpi0eta_eta_to_3pi",Mpi0eta,Mpi0eta_eta_to_3pi);
    RooHistPdf dPdf_Mpi0eta_eta_to_3pi("dPdf_Mpi0eta_eta_to_3pi","dPdf_Mpi0eta_eta_to_3pi",Mpi0eta,dHist_Mpi0eta_eta_to_3pi,1);

    // etap_to_etapipi
    TH1F* Mpi0eta_etap_to_etapipi;
    TFile* data_etap_to_etapipi = TFile::Open("etap_to_etapipi/degALL_etap_to_etapipi_hists_DSelector.root");
    data_etap_to_etapipi->GetObject("pi0eta1D_Cut",Mpi0eta_etap_to_etapipi);
    cout << "Bins in Mpi0eta_etap_to_etapipi: " << Mpi0eta_etap_to_etapipi->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_etap_to_etapipi("dHist_Mpi0eta_etap_to_etapipi","dHist_Mpi0eta_etap_to_etapipi",Mpi0eta,Mpi0eta_etap_to_etapipi);
    RooHistPdf dPdf_Mpi0eta_etap_to_etapipi("dPdf_Mpi0eta_etap_to_etapipi","dPdf_Mpi0eta_etap_to_etapipi",Mpi0eta,dHist_Mpi0eta_etap_to_etapipi,1);

    // pi0pi0
    TH1F* Mpi0eta_pi0pi0;
    TFile* data_pi0pi0 = TFile::Open("pi0pi0/degALL_pi0pi0_hists_DSelector.root");
    data_pi0pi0->GetObject("pi0eta1D_Cut",Mpi0eta_pi0pi0);
    cout << "Bins in Mpi0eta_pi0pi0: " << Mpi0eta_pi0pi0->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_pi0pi0("dHist_Mpi0eta_pi0pi0","dHist_Mpi0eta_pi0pi0",Mpi0eta,Mpi0eta_pi0pi0);
    RooHistPdf dPdf_Mpi0eta_pi0pi0("dPdf_Mpi0eta_pi0pi0","dPdf_Mpi0eta_pi0pi0",Mpi0eta,dHist_Mpi0eta_pi0pi0,1);

    // a0
    TH1F* Mpi0eta_a0;
    TFile* data_a0 = TFile::Open("a0/degALL_a0_hists_DSelector.root");
    data_a0->GetObject("pi0eta1D_Cut",Mpi0eta_a0);
    cout << "Bins in Mpi0eta_a0: " << Mpi0eta_a0->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_a0("dHist_Mpi0eta_a0","dHist_Mpi0eta_a0",Mpi0eta,Mpi0eta_a0);
    RooHistPdf dPdf_Mpi0eta_a0("dPdf_Mpi0eta_a0","dPdf_Mpi0eta_a0",Mpi0eta,dHist_Mpi0eta_a0,1);

    // a2
    TH1F* Mpi0eta_a2;
    TFile* data_a2 = TFile::Open("a2/degALL_a2_hists_DSelector.root");
    data_a2->GetObject("pi0eta1D_Cut",Mpi0eta_a2);
    cout << "Bins in Mpi0eta_a2: " << Mpi0eta_a2->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_a2("dHist_Mpi0eta_a2","dHist_Mpi0eta_a2",Mpi0eta,Mpi0eta_a2);
    RooHistPdf dPdf_Mpi0eta_a2("dPdf_Mpi0eta_a2","dPdf_Mpi0eta_a2",Mpi0eta,dHist_Mpi0eta_a2,1);

    // omega_pi0g
    TH1F* Mpi0eta_omega_pi0g;
    TFile* data_omega_pi0g = TFile::Open("omega_pi0g/degALL_omega_pi0g_hists_DSelector.root");
    data_omega_pi0g->GetObject("pi0eta1D_Cut",Mpi0eta_omega_pi0g);
    cout << "Bins in Mpi0eta_omega_pi0g: " << Mpi0eta_omega_pi0g->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_omega_pi0g("dHist_Mpi0eta_omega_pi0g","dHist_Mpi0eta_omega_pi0g",Mpi0eta,Mpi0eta_omega_pi0g);
    RooHistPdf dPdf_Mpi0eta_omega_pi0g("dPdf_Mpi0eta_omega_pi0g","dPdf_Mpi0eta_omega_pi0g",Mpi0eta,dHist_Mpi0eta_omega_pi0g,1);


    // acutal data
    TH1F* Mpi0eta_data;
    TFile* data = TFile::Open("degALL_data_2017_BA_hists_DSelector.root");
    data->GetObject("pi0eta1D_Cut",Mpi0eta_data);
    cout << "Bins in Mpi0eta_data: " << Mpi0eta_data->GetNbinsX() << endl;
    RooDataHist dHist_Mpi0eta_data("dHist_Mpi0eta_data","dHist_Mpi0eta_data",Mpi0eta,Mpi0eta_data);
    RooHistPdf dPdf_Mpi0eta_data("dPdf_Mpi0eta_data","dPdf_Mpi0eta_data",Mpi0eta,dHist_Mpi0eta_data,1);
    //dPdf_Mpi0eta_data.plotOn(massPlot, LineColor(kBlack), Name("rooName_data"), LineStyle(kDashed),Normalization(15));
    
    //dPdf_Mpi0eta_a2pi.plotOn(massPlot, LineColor(kBlack), Name("rooName_a2pi"));
    //dPdf_Mpi0eta_a2.plotOn(massPlot, LineColor(kRed), Name("rooName_a2"));
    //dPdf_Mpi0eta_omega_pi0g.plotOn(massPlot, LineColor(kGreen), Name("rooName_omega_pi0g"));
    //dPdf_Mpi0eta_a0.plotOn(massPlot,LineColor(kMagenta), Name("rooName_a0"));
    //dPdf_Mpi0eta_pi0pi0.plotOn(massPlot,LineColor(kBlue), Name("rooName_pi0pi0"));
    //dPdf_Mpi0eta_etap_to_etapipi.plotOn(massPlot,LineColor(kOrange), Name("rooName_etap_to_etapipi"));
    //dPdf_Mpi0eta_eta_to_3pi.plotOn(massPlot,LineColor(kCyan), Name("rooName_eta_to_3pi"));
    //dPdf_Mpi0eta_f1_1285_to_etapipi.plotOn(massPlot,LineColor(kTeal), Name("rooName_f1_1285_to_etapipi"));
    //dPdf_Mpi0eta_b1to5g.plotOn(massPlot,LineColor(kYellow), Name("rooName_b1to5g"));


    RooRealVar a2_frac("a2_frac","a2 fraction", 0.5,0,1);
    RooRealVar a0_frac("a0_frac","a0 fraction", 0.2,0,1);
    RooRealVar b1to5g_frac("b1_frac","b1 fraction", 0.2,0,1);

    //RooRealVar a2pi_frac("a2pi_frac", "a2pi fraction", 0.05,0,1);
    //RooRealVar omega_pi0g_frac("omega_frac","omega fraction", 0.05,0,1);
    //RooRealVar pi0pi0_frac("pi0pi0_frac","pi0pi0 fraction", 0.05,0,1);
    //RooRealVar etap_to_etapipi_frac("etap_frac","etap fraction", 0.05,0,1);
    //RooRealVar eta_to_3pi_frac("eta_frac","eta fraction", 0.05,0,1);
    //RooRealVar f1_1285_to_etapipi_frac("f1_frac","f1 fraction", 0.05,0,1);
    RooAddPdf sum("sum","sum",
            RooArgList(
                dPdf_Mpi0eta_a0,
                dPdf_Mpi0eta_a2,
                //dPdf_Mpi0eta_b1to5g,
                dPdf_Mpi0eta_pi0pi0
                //dPdf_Mpi0eta_a2pi
                //dPdf_Mpi0eta_omega_pi0g,
                //dPdf_Mpi0eta_etap_to_etapipi,
                //dPdf_Mpi0eta_eta_to_3pi,
                //dPdf_Mpi0eta_f1_1285_to_etapipi,
                ),
            RooArgList(
                a0_frac,
                a2_frac
                //b1to5g_frac
                //omega_pi0g_frac,
                //a2pi_frac,
                //pi0pi0_frac,
                //etap_to_etapipi_frac,
                //eta_to_3pi_frac,
                //f1_1285_to_etapipi_frac//,
                )
            );
    dHist_Mpi0eta_data.plotOn(massPlot);
    Mpi0eta.setRange("fitRange",0.65,1.4);
    sum.fitTo(dHist_Mpi0eta_data,Range("fitRange"));
    sum.plotOn(massPlot, LineColor(kBlue), Name("rooName_sum"));
    sum.plotOn(massPlot, Name("component_a2"), Components("dPdf_Mpi0eta_a2"), LineStyle(kDashed), LineColor(kBlack));
    sum.plotOn(massPlot, Name("component_a0"), Components("dPdf_Mpi0eta_a0"), LineStyle(kDashed), LineColor(kMagenta));
    //sum.plotOn(massPlot, Name("component_b1to5g"), Components("dPdf_Mpi0eta_b1to5g"), LineStyle(kDashed), LineColor(kOrange));
    sum.plotOn(massPlot, Name("component_pi0pi0"), Components("dPdf_Mpi0eta_pi0pi0"), LineStyle(kDashed), LineColor(kBlue));
    massPlot->Draw();

    //leg1->AddEntry("rooName_data","data","lp");
    //leg1->AddEntry("rooName_a2pi","a2pi","lp");
    //leg1->AddEntry("rooName_b1to5g","b1-5g","lp");
    //leg1->AddEntry("rooName_f1_1285_to_etapipi","f1(1285)-etapipi","lp");
    //leg1->AddEntry("rooName_eta_to_3pi","eta-3pi","lp");
    //leg1->AddEntry("rooName_etap_to_etapipi","etap-etapipi","lp");
    //leg1->AddEntry("rooName_pi0pi0","pi0pi0","lp");
    //leg1->AddEntry("rooName_a0","a0-etapi","lp");
    //leg1->AddEntry("rooName_a2","a2-etapi","lp");
    //leg1->AddEntry("rooName_omega_pi0g","omega-pi0g","lp");
    leg1->AddEntry("component_a2", "a2","LP");
    leg1->AddEntry("component_a0", "a0","LP");
    //leg1->AddEntry("component_b1to5g", "b1to5g","LP");
    leg1->AddEntry("component_pi0pi0", "pi0pi0","LP");
    leg1->Draw();
    c1->SaveAs("Mpi0eta_fit.png");


}

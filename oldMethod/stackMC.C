// This code looks at the summed MC reactions and stacks all the processes on top of each other over various histograms
// This will allow us to see what backgrounds are reduced given difference weightings, i.e. compare how sideband subtraction differ
// from q-factors in terms of backgrounds subtracted
//
// Also, compares to a0+a2 simulations. This allows us to see how the influence of backgrounds affects the performance of the q-values.
// It is clear that sideband subtraction doesnt care but we see that q-values heavily depend on it. 
bool compareTo_a0a2=false;

void stackMC(){
    gSystem->Exec("mkdir -p stackHists");

    // 0 = a0
    // 1 = a2
    // 2 = b1to5g
    // 3 = a2pi
    // 4 = etap
    // 5 = eta
    // 6 = f1(1285)
    // 7 = omega
    // 8 = pi0pi0 
    std::vector<string> mcprocesses = {"a0","a2","b1to5g","a2pi","etap","eta","f1_1285","omega","pi0pi0"};
    std::vector<int> colors = {1,1,kRed-7,8,4,41,38,kCyan+1,kOrange+1,9};
    
    //TFile* dataFile = TFile::Open("./allMC_trees.root");
    TFile* dataFile = TFile::Open("/d/grid13/ln16/q-values-2/results_summedMC/diagnosticPlots/postQVal_flatTree.root");
    TTree* dataTree;
    dataFile->GetObject("degALL_acc_mEllipse_tree_flat",dataTree);

    double AccWeight;
    double sbWeight;
    double sbWeightPi0;
    double sbWeightEta;
    double qvalue;
    double Meta;
    double Mpi0;
    double Mpi0g1;
    double Mpi0g2;
    double Mpi0eta;
    double cosTheta_X_cm;
    double cosTheta_eta_gj;
    double phi_eta_gj;
    int mcprocess; 

    dataTree->SetBranchAddress("AccWeight",&AccWeight);
    dataTree->SetBranchAddress("weightBS",&sbWeight);
    dataTree->SetBranchAddress("weightBSpi0",&sbWeightPi0);
    dataTree->SetBranchAddress("weightBSeta",&sbWeightEta);
    dataTree->SetBranchAddress("mcprocess",&mcprocess); 
    dataTree->SetBranchAddress("qvalue",&qvalue);

    dataTree->SetBranchAddress("Meta",&Meta);
    dataTree->SetBranchAddress("Mpi0",&Mpi0);
    dataTree->SetBranchAddress("Mpi0eta",&Mpi0eta);
    dataTree->SetBranchAddress("cosTheta_X_cm", &cosTheta_X_cm); 	
    dataTree->SetBranchAddress("cosTheta_eta_gj",&cosTheta_eta_gj);
    dataTree->SetBranchAddress("phi_eta_gj",&phi_eta_gj); 
    dataTree->SetBranchAddress("Mpi0g1",&Mpi0g1);
    dataTree->SetBranchAddress("Mpi0g2",&Mpi0g2);


    std::vector<string> weightings = {"none","as","asbs","asq"};

    TH1F* dHist_Meta[9][4];
    TH1F* dHist_Mpi0[9][4];
    TH1F* dHist_Mpi0eta[9][4];
    TH1F* dHist_cosThetaEta_GJ[9][4];
    TH1F* dHist_cosThetaX_CM[9][4];
    TH1F* dHist_phiEta_GJ[9][4];
    TH1F* dHist_Mpi0g[9][4];

    THStack* hs_Meta;
    THStack* hs_Mpi0;
    THStack* hs_Mpi0eta;
    THStack* hs_cosThetaEta_GJ;
    THStack* hs_cosThetaX_CM;
    THStack* hs_phiEta_GJ;
    THStack* hs_Mpi0g;

    TLegend* legs[7];
    TCanvas* c1 = new TCanvas("","",1080,1080);
    cout << "Defined variables" << endl;

    for (int iWeight=0; iWeight<weightings.size(); ++iWeight){
        for (int i=0; i<mcprocesses.size(); ++i){
            dHist_Meta[i][iWeight] = new TH1F( ("dHist_Meta_"+mcprocesses[i]+"_"+weightings[iWeight]).c_str(), "M(#eta); M(#eta) GeV; Events/0.003 GeV", 200, 0.25, 0.85);//Events/0.002 GeV", 300, 0.25, 0.85 );
            dHist_Mpi0[i][iWeight] = new TH1F( ("dHist_Mpi0_"+mcprocesses[i]+"_"+weightings[iWeight]).c_str(), "M(#pi^{0}); M(#pi^{0}) GeV; Events/0.001 GeV", 200, 0.05, 0.25 );
            dHist_Mpi0eta[i][iWeight] = new TH1F( ("dHist_Mpi0eta_"+mcprocesses[i]+"_"+weightings[iWeight]).c_str(), "M(#pi^{0}#eta); M(#pi^{0}#eta) GeV; Events/0.01 GeV", 350, 0, 3.5 );
            dHist_cosThetaEta_GJ[i][iWeight] = new TH1F( ("dHist_cosThetaEta_GJ_"+mcprocesses[i]+"_"+weightings[iWeight]).c_str(), "cos(#theta) GJ of #eta; cos(#theta) of #eta; Events/0.02 GeV", 100, -1, 1 );
            dHist_cosThetaX_CM[i][iWeight] = new TH1F( ("dHist_cosThetaX_CM_"+mcprocesses[i]+"_"+weightings[iWeight]).c_str(), "cos(#theta) of CM #eta; cos(#theta) of #eta; Events/0.02 GeV", 100, 0.9, 1 );
            dHist_phiEta_GJ[i][iWeight] = new TH1F( ("dHist_phiEta_GJ_"+mcprocesses[i]+"_"+weightings[iWeight]).c_str(), "#phi of #eta;#phi of #eta ;Events/0.02 GeV", 90, -180, 180 );
            dHist_Mpi0g[i][iWeight] = new TH1F( ("dHist_Mpi0g_"+mcprocesses[i]+"_"+weightings[iWeight]).c_str(), "M(#pi^{0}g); M(#pi^{0}g) GeV; Events/0.001 GeV", 350, 0, 3.5 );

            dHist_Meta[i][iWeight]->SetFillColor(colors[i]);
            dHist_Mpi0[i][iWeight]->SetFillColor(colors[i]);
            dHist_Mpi0eta[i][iWeight]->SetFillColor(colors[i]);
            dHist_cosThetaEta_GJ[i][iWeight]->SetFillColor(colors[i]);
            dHist_cosThetaX_CM[i][iWeight]->SetFillColor(colors[i]);
            dHist_phiEta_GJ[i][iWeight]->SetFillColor(colors[i]);
            dHist_Mpi0g[i][iWeight]->SetFillColor(colors[i]);

            int lineColor;
            if (mcprocesses[i] == "a0" || mcprocesses[i] == "a1"){ 
                lineColor = 0;
            }
            else{ lineColor = 1; }
            dHist_Meta[i][iWeight]->SetLineColor(lineColor);
            dHist_Mpi0[i][iWeight]->SetLineColor(lineColor);
            dHist_Mpi0eta[i][iWeight]->SetLineColor(lineColor);
            dHist_cosThetaEta_GJ[i][iWeight]->SetLineColor(lineColor);
            dHist_cosThetaX_CM[i][iWeight]->SetLineColor(lineColor);
            dHist_phiEta_GJ[i][iWeight]->SetLineColor(lineColor);
            dHist_Mpi0g[i][iWeight]->SetLineColor(lineColor);
        }
    }

    cout << "Initialized histograms" << endl;
    
    ULong64_t nentries = dataTree->GetEntries();
    
    double totalWeight;
    for (int ientry=0; ientry<nentries; ++ientry){
        for (int iWeight=0; iWeight<weightings.size(); ++iWeight){
            dataTree->GetEntry(ientry);
            if(weightings[iWeight]=="none"){ totalWeight=1;}
            if(weightings[iWeight]=="as"){ totalWeight=AccWeight;}
            if(weightings[iWeight]=="asbs"){ totalWeight=AccWeight*sbWeight;}
            if(weightings[iWeight]=="asq"){ totalWeight=AccWeight*qvalue;}

            dHist_Meta[mcprocess][iWeight]->Fill(Meta,totalWeight);
            dHist_Mpi0[mcprocess][iWeight]->Fill(Mpi0,totalWeight);
            dHist_Mpi0eta[mcprocess][iWeight]->Fill(Mpi0eta,totalWeight);
            dHist_cosThetaEta_GJ[mcprocess][iWeight]->Fill(cosTheta_eta_gj,totalWeight);
            dHist_cosThetaX_CM[mcprocess][iWeight]->Fill(cosTheta_X_cm,totalWeight);
            dHist_phiEta_GJ[mcprocess][iWeight]->Fill(phi_eta_gj,totalWeight);
            dHist_Mpi0g[mcprocess][iWeight]->Fill(Mpi0g1,totalWeight);
            dHist_Mpi0g[mcprocess][iWeight]->Fill(Mpi0g2,totalWeight);
        }
    }

    cout << "Filled all the histograms" << endl;

    cout << "Stacking histograms" << endl;
    for (int iWeight=0; iWeight<weightings.size(); ++iWeight){
        hs_Meta = new THStack(("hs_Meta"+weightings[iWeight]).c_str(),"Stacked Processes - Meta");
        hs_Mpi0 = new THStack(("hs_Mpi0"+weightings[iWeight]).c_str(),"Stacked Processes - Mpi0");
        hs_Mpi0eta = new THStack(("hs_Mpi0eta"+weightings[iWeight]).c_str(),"Stacked Processes - Mpi0eta");
        hs_cosThetaEta_GJ = new THStack(("hs_cosThetaEta_GJ"+weightings[iWeight]).c_str(),"Stacked Processes - cosThetaEta_GJ");
        hs_cosThetaX_CM = new THStack(("hs_cosThetaX_CM"+weightings[iWeight]).c_str(),"Stacked Processes - cosThetaX_CM");
        hs_phiEta_GJ = new THStack(("hs_phiEta_GJ"+weightings[iWeight]).c_str(),"Stacked Processes - phiEta_GJ");
        hs_Mpi0g = new THStack(("hs_Mpi0g"+weightings[iWeight]).c_str(),"Stacked Processes - Mpi0g");
        for (int i=0; i<7; ++i){
            legs[i] = new TLegend(0.1,0.6,0.2,0.9);
        }
        for (int i=0; i<mcprocesses.size(); ++i){
            hs_Meta->Add(dHist_Meta[i][iWeight],"HIST");
            hs_Mpi0->Add(dHist_Mpi0[i][iWeight],"HIST");
            hs_Mpi0eta->Add(dHist_Mpi0eta[i][iWeight],"HIST");
            hs_cosThetaEta_GJ->Add(dHist_cosThetaEta_GJ[i][iWeight],"HIST");
            hs_cosThetaX_CM->Add(dHist_cosThetaX_CM[i][iWeight],"HIST");
            hs_phiEta_GJ->Add(dHist_phiEta_GJ[i][iWeight],"HIST");
            hs_Mpi0g->Add(dHist_Mpi0g[i][iWeight],"HIST");

            legs[0]->AddEntry(dHist_Meta[i][iWeight],(mcprocesses[i]).c_str(),"f");
            legs[1]->AddEntry(dHist_Mpi0[i][iWeight],(mcprocesses[i]).c_str(),"f");
            legs[2]->AddEntry(dHist_Mpi0eta[i][iWeight],(mcprocesses[i]).c_str(),"f");
            legs[3]->AddEntry(dHist_cosThetaEta_GJ[i][iWeight],(mcprocesses[i]).c_str(),"f");
            legs[4]->AddEntry(dHist_cosThetaX_CM[i][iWeight],(mcprocesses[i]).c_str(),"f");
            legs[5]->AddEntry(dHist_phiEta_GJ[i][iWeight],(mcprocesses[i]).c_str(),"f");
            legs[6]->AddEntry(dHist_Mpi0g[i][iWeight],(mcprocesses[i]).c_str(),"f");
        } 
        cout << "stacked hists for one weighting scheme" << endl;

        c1->Clear();
        //c1->SetLeftMargin(0);
        //c1->SetRightMargin(0);
        hs_Meta->Draw();
        legs[0]->Draw();
        c1->SaveAs(("stackHists/"+weightings[iWeight]+"-stack-Meta.png").c_str());

        c1->Clear();
        hs_Mpi0->Draw();
        legs[1]->Draw();
        c1->SaveAs(("stackHists/"+weightings[iWeight]+"-stack-Mpi0.png").c_str());

        c1->Clear();
        hs_Mpi0eta->Draw();
        legs[2]->Draw();
        c1->SaveAs(("stackHists/"+weightings[iWeight]+"-stack-Mpi0eta.png").c_str());

        c1->Clear();
        hs_cosThetaEta_GJ->Draw();
        legs[3]->Draw();
        c1->SaveAs(("stackHists/"+weightings[iWeight]+"-stack-cosThetaEta_GJ.png").c_str());

        c1->Clear();
        hs_cosThetaX_CM->Draw();
        legs[4]->Draw();
        c1->SaveAs(("stackHists/"+weightings[iWeight]+"-stack-cosThetaX_CM.png").c_str());

        c1->Clear();
        hs_phiEta_GJ->Draw();
        legs[5]->Draw();
        c1->SaveAs(("stackHists/"+weightings[iWeight]+"-stack-phiEta_GJ.png").c_str());

        c1->Clear();
        hs_Mpi0g->Draw();
        legs[6]->Draw();
        c1->SaveAs(("stackHists/"+weightings[iWeight]+"-stack-Mpi0g.png").c_str());
    }


    if (compareTo_a0a2){
        cout << "\nMake some histograms comapring various distributions of SUMMED vs a0+a2 datasets to check q-value performance" << endl;

        // Load the trees with the q-factors performed on only the a0+a2 simulations
        TFile* dataFile_a0a2 = TFile::Open("/d/grid13/ln16/q-values-2/results_a0a2MC/diagnosticPlots/postQVal_flatTree.root");
        dataFile_a0a2->GetObject("degALL_acc_mEllipse_tree_flat",dataTree);
        dataTree->SetBranchAddress("AccWeight",&AccWeight);
        dataTree->SetBranchAddress("weightBS",&sbWeight);
        dataTree->SetBranchAddress("weightBSpi0",&sbWeightPi0);
        dataTree->SetBranchAddress("weightBSeta",&sbWeightEta);
        dataTree->SetBranchAddress("mcprocess",&mcprocess); 
        dataTree->SetBranchAddress("qvalue",&qvalue);

        dataTree->SetBranchAddress("Meta",&Meta);
        dataTree->SetBranchAddress("Mpi0",&Mpi0);
        dataTree->SetBranchAddress("Mpi0eta",&Mpi0eta);
        dataTree->SetBranchAddress("cosTheta_X_cm", &cosTheta_X_cm); 	
        dataTree->SetBranchAddress("cosTheta_eta_gj",&cosTheta_eta_gj);
        dataTree->SetBranchAddress("phi_eta_gj",&phi_eta_gj); 
        dataTree->SetBranchAddress("Mpi0g1",&Mpi0g1);
        dataTree->SetBranchAddress("Mpi0g2",&Mpi0g2);

        TH1F* dHist_Meta_a0a2[4];
        TH1F* dHist_Mpi0_a0a2[4];
        TH1F* dHist_Mpi0eta_a0a2[4];
        TH1F* dHist_cosThetaEta_GJ_a0a2[4];
        TH1F* dHist_cosThetaX_CM_a0a2[4];
        TH1F* dHist_phiEta_GJ_a0a2[4];
        TH1F* dHist_Mpi0g_a0a2[4];
        for (int iWeight=0; iWeight<weightings.size(); ++iWeight){
            /// Add up the a0 and a2 histograms of the SUMMED dataset so we can compare the q-values performance
            dHist_Meta[0][iWeight]->Add(dHist_Meta[1][iWeight]);
            dHist_Mpi0[0][iWeight]->Add(dHist_Mpi0[1][iWeight]);
            dHist_Mpi0eta[0][iWeight]->Add(dHist_Mpi0eta[1][iWeight]);
            dHist_cosThetaEta_GJ[0][iWeight]->Add(dHist_cosThetaEta_GJ[1][iWeight]);
            dHist_cosThetaX_CM[0][iWeight]->Add(dHist_cosThetaX_CM[1][iWeight]);
            dHist_phiEta_GJ[0][iWeight]->Add(dHist_phiEta_GJ[1][iWeight]);
            dHist_Mpi0g[0][iWeight]->Add(dHist_Mpi0g[1][iWeight]);

            dHist_Meta[0][iWeight]->SetFillColor(kOrange);
            dHist_Mpi0[0][iWeight]->SetFillColor(kOrange);
            dHist_Mpi0eta[0][iWeight]->SetFillColor(kOrange);
            dHist_cosThetaEta_GJ[0][iWeight]->SetFillColor(kOrange);
            dHist_cosThetaX_CM[0][iWeight]->SetFillColor(kOrange);
            dHist_phiEta_GJ[0][iWeight]->SetFillColor(kOrange);
            dHist_Mpi0g[0][iWeight]->SetFillColor(kOrange);
            dHist_Meta[0][iWeight]->SetLineColor(kOrange);
            dHist_Mpi0[0][iWeight]->SetLineColor(kOrange);
            dHist_Mpi0eta[0][iWeight]->SetLineColor(kOrange);
            dHist_cosThetaEta_GJ[0][iWeight]->SetLineColor(kOrange);
            dHist_cosThetaX_CM[0][iWeight]->SetLineColor(kOrange);
            dHist_phiEta_GJ[0][iWeight]->SetLineColor(kOrange);
            dHist_Mpi0g[0][iWeight]->SetLineColor(kOrange);

            // Initialize the histograms for the a0+a2 dataset
            dHist_Meta_a0a2[iWeight] = new TH1F( ("dHist_Meta_a0a2_"+weightings[iWeight]).c_str(), "M(#eta); M(#eta) GeV; Events/0.003 GeV", 200, 0.25, 0.85);//Events/0.002 GeV", 300, 0.25, 0.85 );
            dHist_Mpi0_a0a2[iWeight] = new TH1F( ("dHist_Mpi0_a0a2_"+weightings[iWeight]).c_str(), "M(#pi^{0}); M(#pi^{0}) GeV; Events/0.001 GeV", 200, 0.05, 0.25 );
            dHist_Mpi0eta_a0a2[iWeight] = new TH1F( ("dHist_Mpi0eta_a0a2_"+weightings[iWeight]).c_str(), "M(#pi^{0}#eta); M(#pi^{0}#eta) GeV; Events/0.01 GeV", 350, 0, 3.5 );
            dHist_cosThetaEta_GJ_a0a2[iWeight] = new TH1F( ("dHist_cosThetaEta_GJ_a0a2_"+weightings[iWeight]).c_str(), "cos(#theta) GJ of #eta; cos(#theta) of #eta; Events/0.02 GeV", 100, -1, 1 );
            dHist_cosThetaX_CM_a0a2[iWeight] = new TH1F( ("dHist_cosThetaX_CM_a0a2_"+weightings[iWeight]).c_str(), "cos(#theta) of CM #eta; cos(#theta) of #eta; Events/0.02 GeV", 100, 0.9, 1 );
            dHist_phiEta_GJ_a0a2[iWeight] = new TH1F( ("dHist_phiEta_GJ_a0a2_"+weightings[iWeight]).c_str(), "#phi of #eta;#phi of #eta ;Events/0.02 GeV", 90, -180, 180 );
            dHist_Mpi0g_a0a2[iWeight] = new TH1F( ("dHist_Mpi0g_a0a2_"+weightings[iWeight]).c_str(), "M(#pi^{0}g); M(#pi^{0}g) GeV; Events/0.001 GeV", 350, 0, 3.5 );

            // fill the histograms for the a0+a2 dataset
            nentries = dataTree->GetEntries();
            for (int ientry=0; ientry<nentries; ientry++)
            {
                dataTree->GetEntry(ientry);
                if(weightings[iWeight]=="none"){ totalWeight=1;}
                if(weightings[iWeight]=="as"){ totalWeight=AccWeight;}
                if(weightings[iWeight]=="asbs"){ totalWeight=AccWeight*sbWeight;}
                if(weightings[iWeight]=="asq"){ totalWeight=AccWeight*qvalue;}

                dHist_Meta_a0a2[iWeight]->Fill(Meta,totalWeight);
                dHist_Mpi0_a0a2[iWeight]->Fill(Mpi0,totalWeight);
                dHist_Mpi0eta_a0a2[iWeight]->Fill(Mpi0eta,totalWeight);
                dHist_cosThetaEta_GJ_a0a2[iWeight]->Fill(cosTheta_eta_gj,totalWeight);
                dHist_cosThetaX_CM_a0a2[iWeight]->Fill(cosTheta_X_cm,totalWeight);
                dHist_phiEta_GJ_a0a2[iWeight]->Fill(phi_eta_gj,totalWeight);
                dHist_Mpi0g_a0a2[iWeight]->Fill(Mpi0g1,totalWeight);
                dHist_Mpi0g_a0a2[iWeight]->Fill(Mpi0g2,totalWeight);
            }
            TLegend* leg = new TLegend(0.1,0.6,0.2,0.9);

            c1->Clear();
            dHist_Meta[0][iWeight]->Draw("HIST");
            dHist_Meta_a0a2[iWeight]->Draw("HIST SAME");
            leg->AddEntry(dHist_Meta[0][iWeight],"SUMMED","f");
            leg->AddEntry(dHist_Meta_a0a2[iWeight],"a0+a2","l");
            leg->Draw();
            c1->SaveAs(("stackHists/"+weightings[iWeight]+"-summed_vs_a0a2_Meta.png").c_str());

            c1->Clear();
            leg->Clear();
            dHist_Mpi0[0][iWeight]->Draw("HIST");
            dHist_Mpi0_a0a2[iWeight]->Draw("HIST SAME");
            leg->AddEntry(dHist_Mpi0[0][iWeight],"SUMMED","f");
            leg->AddEntry(dHist_Mpi0_a0a2[iWeight],"a0+a2","l");
            leg->Draw();
            c1->SaveAs(("stackHists/"+weightings[iWeight]+"-summed_vs_a0a2_Mpi0.png").c_str());

            c1->Clear();
            leg->Clear();
            dHist_Mpi0eta[0][iWeight]->Draw("HIST");
            dHist_Mpi0eta_a0a2[iWeight]->Draw("HIST SAME");
            leg->AddEntry(dHist_Mpi0eta[0][iWeight],"SUMMED","f");
            leg->AddEntry(dHist_Mpi0eta_a0a2[iWeight],"a0+a2","l");
            leg->Draw();
            c1->SaveAs(("stackHists/"+weightings[iWeight]+"-summed_vs_a0a2_Mpi0eta.png").c_str());

            c1->Clear();
            leg->Clear();
            dHist_cosThetaEta_GJ[0][iWeight]->Draw("HIST");
            dHist_cosThetaEta_GJ_a0a2[iWeight]->Draw("HIST SAME");
            leg->AddEntry(dHist_cosThetaEta_GJ[0][iWeight],"SUMMED","f");
            leg->AddEntry(dHist_cosThetaEta_GJ_a0a2[iWeight],"a0+a2","l");
            leg->Draw();
            c1->SaveAs(("stackHists/"+weightings[iWeight]+"-summed_vs_a0a2_cosThetaEta_GJ.png").c_str());

            c1->Clear();
            leg->Clear();
            dHist_cosThetaX_CM[0][iWeight]->Draw("HIST");
            dHist_cosThetaX_CM_a0a2[iWeight]->Draw("HIST SAME");
            leg->AddEntry(dHist_cosThetaX_CM[0][iWeight],"SUMMED","f");
            leg->AddEntry(dHist_cosThetaX_CM_a0a2[iWeight],"a0+a2","l");
            leg->Draw();
            c1->SaveAs(("stackHists/"+weightings[iWeight]+"-summed_vs_a0a2_cosThetaX_CM.png").c_str());

            c1->Clear();
            leg->Clear();
            dHist_phiEta_GJ[0][iWeight]->Draw("HIST");
            dHist_phiEta_GJ_a0a2[iWeight]->Draw("HIST SAME");
            leg->AddEntry(dHist_phiEta_GJ[0][iWeight],"SUMMED","f");
            leg->AddEntry(dHist_phiEta_GJ_a0a2[iWeight],"a0+a2","l");
            leg->Draw();
            c1->SaveAs(("stackHists/"+weightings[iWeight]+"-summed_vs_a0a2_phiEta_GJ.png").c_str());

            c1->Clear();
            leg->Clear();
            dHist_Mpi0g[0][iWeight]->Draw("HIST");
            dHist_Mpi0g_a0a2[iWeight]->Draw("HIST SAME");
            leg->AddEntry(dHist_Mpi0g[0][iWeight],"SUMMED","f");
            leg->AddEntry(dHist_Mpi0g_a0a2[iWeight],"a0+a2","l");
            leg->Draw();
            c1->SaveAs(("stackHists/"+weightings[iWeight]+"-summed_vs_a0a2_Mpi0g.png").c_str());
        }
    }
}
















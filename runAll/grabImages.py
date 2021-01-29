import ROOT
import os

'''
This code reads in the mc cocktail datasets and draws some useful plots onto a canvas
It is interesting to look at the 2D Mpi0 vs Meta, GJ angle, and M(pi0eta) with the last being overlaid with data
to compare shapes
'''

folders=["a0","a2","b1to5g","a2pi","etap_to_etapipi","eta_to_3pi","f1_1285_to_etapipi","omega_pi0g","pi0pi0"]
hists=["eta_cosTheta_GJvsM_Cut","pi0eta1D_Cut","pi0eta_mEllipsePre"]
drawOpts=["COLZ","HIST","COLZ"]
currentFile="degALL_acc_mEllipse_hists_DSelector.root"
outputName="montage.pdf"
dataFile="/d/grid15/ln16/pi0eta/092419/degALL_data_2017_allCuts_hists_DSelector.root"
datROOT=ROOT.TFile.Open(dataFile)
dataHist=datROOT.Get("pi0eta1D_Cut")
overlayNormalization=[0.25,0.2,0.32,0.2,0.2,0.5,0.2,0.07,0.5]

for i in range(len(folders)):
    print("Chdir to: "+folders[i])
    os.chdir(folders[i])
    print("Current file: "+currentFile)
    mcROOT=ROOT.TFile.Open(currentFile)
    canvas=ROOT.TCanvas("","",2560,1600)
    canvas.Divide(2,2);
    for j in range(len(hists)):
        print("  grabbing: "+hists[j])
        canvas.cd(j+1)
        hist=mcROOT.Get(hists[j])
        if (hists[j]=="pi0eta1D_Cut"):
            hist.SetLineColor(1)
            hist.DrawNormalized(drawOpts[j],overlayNormalization[i])
            dataHist.SetLineColor(2)
            dataHist.DrawNormalized(drawOpts[j]+" SAME")
        else:
            hist.Draw(drawOpts[j])
    print("  saving as: "+outputName)
    canvas.SaveAs(outputName)
    os.chdir("..")

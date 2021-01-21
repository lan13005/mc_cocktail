import ROOT
ROOT.gROOT.SetBatch(True)


#- b1 -> omega pi0, (omega -> pi0 g) + pi0 -> 5g:
#  use gen_amp with
#/d/home/sdobbs/grid13/MCtest/etapi_bg/b1_5g/gen_amp_b1_5gamma_t5.cfg
#- a2 pi0 -> (a2 -> eta pi0) + pi0 -> 6g:
#  use gen_amp with
#/d/home/sdobbs/grid13/MCtest/etapi_bg/a2pi_etapi0pi0/gen_amp_a2pi_6g.cfg
#- eta -> 3pi0 -> 6g:
#  use genEtaRegge with /d/home/sdobbs/grid13/MCtest/etapi_bg/eta_3pi0/eta548.in
#- eta' -> eta pi0 pi0 -> 6g:
#  use genEtaRegge with
#/d/home/sdobbs/grid13/MCtest/etapi_bg/etap_etapi0pi0/eta958.in
#- f1(1285) -> eta pi0 p0i -> 6g:
#  use genEtaRegge with
#/d/home/sdobbs/grid13/MCtest/etapi_bg/f1_etapi0pi0/f1_1285.in

fileTags = [
        "b1to5g",
        "f1_1285_to_etapipi",
        "eta_to_3pi",
        "etap_to_etapipi",
        "a2pi",
        "pi0pi0",
        "a0",
        "a2",
        "omega_pi0g"
        ]

efficiencies=[]
imgFolder="images"
canvasOverlay=ROOT.TCanvas("pi0eta1D_overlay","",1280,720)
overlayNormalization=[0.3,0.2,0.2,0.2,0.3,0.5,0.03,0.03,0.05]

# Set output level. at 2000 we will see output from SaveAs
ROOT.gErrorIgnoreLevel=2000
for iFile, fileTag in enumerate(fileTags):
    # Deal with thrown trees
    print("-----------")
    treeName="degALL_thrownCheck_tree_DSelector.root"
    fullPath=fileTag+"/"+treeName
    thrownTree=ROOT.TFile.Open(fullPath)
    nThrown=thrownTree.Get("Thrown_Tree").GetEntries()
    print(fullPath+" "+str(nThrown))

    # Deal with thrown histograms
    histsName="degALL_thrownCheck_hists_DSelector.root"
    fullPath=fileTag+"/"+histsName
    hists=ROOT.TFile.Open(fullPath)
    hist=hists.massX
    canvas=ROOT.TCanvas("","",1280,720)
    hist.Draw("COLZ")
    canvas.SaveAs(imgFolder+"/thrownMass_"+fileTag+".png")
    canvas.Close()
    hist=hists.hThrownTopologies
    canvas=ROOT.TCanvas("","",1280,720)
    hist.DrawNormalized()
    canvas.SaveAs(imgFolder+"/topologies_"+fileTag+".png")
    canvas.Close()
    if fileTag=="pi0pi0":
        hist=hists.massPi0Pi0
        canvas=ROOT.TCanvas("","",1280,720)
        hist.DrawNormalized()
        canvas.SaveAs(imgFolder+"/mass_"+fileTag+".png")
        canvas.Close()

    # Deal with reconstructed trees
    treeName="degALL_acc_treeFlat_DSelector.root"
    fullPath=fileTag+"/"+treeName
    tree=ROOT.TFile.Open(fullPath)
    nRecon=tree.Get("degALL_acc_tree_flat").GetEntries()
    print(fullPath+" "+str(nRecon))
    efficiency=1.0*nRecon/nThrown
    efficiencies.append(efficiency)

    # Deal with reconstructed hists
    histsName="degALL_acc_hists_DSelector.root"
    fullPath=fileTag+"/"+histsName
    hists=ROOT.TFile.Open(fullPath)
    dataHistName="/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/degALL_data_2017_BA_hists_DSelector.root"
    dataHists=ROOT.TFile.Open(dataHistName)
    hist=hists.CutsPassed
    hist.LabelsOption("a","x") # sort x-axis labels alphabetically
    canvas=ROOT.TCanvas("","",1280,720)
    hist.DrawNormalized()
    canvas.SaveAs(imgFolder+"/cutsHist_"+fileTag+".png")
    canvas.Close()
    #-- 
    hist=hists.pi0eta1D_Cut
    canvas=ROOT.TCanvas("","",1280,720)
    hist.Draw()
    canvas.SaveAs(imgFolder+"/pi0eta1D_"+fileTag+".png")
    canvas.Close()
    canvasOverlay.cd()
    hist.DrawNormalized("HIST",overlayNormalization[iFile])
    dataHist=dataHists.pi0eta1D_Cut
    dataHist.SetLineColor(2)
    dataHist.DrawNormalized("HIST SAME");
    canvasOverlay.SaveAs(imgFolder+"/pi0eta1D_"+fileTag+"-overlay.png")
    #-- 
    hist=hists.pi0eta_mEllipsePre
    canvas=ROOT.TCanvas("","",1280,720)
    hist.Draw("COLZ")
    canvas.SaveAs(imgFolder+"/pi0eta_mEllipsePre_"+fileTag+".png")
    canvas.Close()


canvas=ROOT.TCanvas("","",1280,720)
dataHist=dataHists.pi0eta1D_Cut
dataHist.Draw("HIST")
canvas.SaveAs(imgFolder+"/pi0eta1D_data.png")



print("\n")
for efficiency,fileTag in zip(efficiencies,fileTags):
    print("("+fileTag+") Efficiency - "+str(efficiency))

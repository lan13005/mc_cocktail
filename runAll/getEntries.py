import ROOT
ROOT.gROOT.SetBatch(True)
import os


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

    # Deal with reconstructed trees
    treeName="degALL_acc_mEllipse_treeFlat_DSelector.root"
    fullPath=fileTag+"/"+treeName
    tree=ROOT.TFile.Open(fullPath)
    nRecon=tree.Get("degALL_acc_mEllipse_tree_flat").GetEntries()
    print(fullPath+" "+str(nRecon))
    efficiency=1.0*nRecon/nThrown
    efficiencies.append(efficiency)

print("\n")
for efficiency,fileTag in zip(efficiencies,fileTags):
    print("("+fileTag+") Efficiency - "+str(efficiency))

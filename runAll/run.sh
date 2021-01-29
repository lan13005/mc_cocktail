###############################
# This program is pretty dumb so things to need to be just right to work
# THE CHAINS IN runDSelector_7_17_14 NEED TO BE UNCOMMENTED
# There are certain lines in runDSelector_7_17_14 that will be commneted and uncommented to run over the correct root files
# mcprocess will be updated and topologyString also to make sure we are linking the correct process and the thrown topologies
# A directory will be made to store the outputs after the program finishes which we can hadd all together.
##############################

# -- if you do decide to copy DSelector_ver20 make sure you update the topologyString to choose correct one for each topology
# --    also you need might need to change the cuts. Might have chosen different cuts like chiSq 
#cp $grid15/pi0eta/092419/DSelector_ver20.C .
#cp $grid15/pi0eta/092419/DSelector_ver20.h .
cp $grid15/pi0eta/092419/DSelector_helperFuncs.h .

sed -i '36,44 s|^|//|' runDSelector_7_17_14.C
sed -i '36,44 s|^|//|' runDSelectorThrown.C

sed -i 's/tag=".*";/tag="_acc_mEllipse";/' runDSelector_7_17_14.C
sed -i 's/tag=".*";/tag="_acc_mEllipse";/' DSelector_ver20.C
# {0:"a0",1:"a2",2:"b1to5g",3:"a2pi",4:"etap_to_etapipi",5:"eta_to_3pi",6:"f1_1285_to_etapipi",7:"omega_pi0g",8:"pi0pi0"}

sed -i '36 s|^//||' runDSelector_7_17_14.C
sed -i '36 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=0;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="4#gammap[#pi^{0},#eta]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="4#gammap[#pi^{0},#eta]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '36 s|^|//|' runDSelector_7_17_14.C
sed -i '36 s|^|//|' runDSelectorThrown.C
mkdir -p a0
mv *.root a0

sed -i '37 s|^//||' runDSelector_7_17_14.C
sed -i '37 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=1;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="4#gammap[#pi^{0},#eta]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="4#gammap[#pi^{0},#eta]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '37 s|^|//|' runDSelector_7_17_14.C
sed -i '37 s|^|//|' runDSelectorThrown.C
mkdir -p a2
mv *.root a2

sed -i '38 s|^//||' runDSelector_7_17_14.C
sed -i '38 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=3;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[2#pi^{0},#eta]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[2#pi^{0},#eta]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '38 s|^|//|' runDSelector_7_17_14.C
sed -i '38 s|^|//|' runDSelectorThrown.C
mkdir -p a2pi
mv *.root a2pi

sed -i '39 s|^//||' runDSelector_7_17_14.C
sed -i '39 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=2;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="5#gammap[2#pi^{0}]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="5#gammap[2#pi^{0}]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '39 s|^|//|' runDSelector_7_17_14.C
sed -i '39 s|^|//|' runDSelectorThrown.C
mkdir -p b1to5g
mv *.root b1to5g

sed -i '40 s|^//||' runDSelector_7_17_14.C
sed -i '40 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=4;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[2#pi^{0},#eta]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[2#pi^{0},#eta]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '40 s|^|//|' runDSelector_7_17_14.C
sed -i '40 s|^|//|' runDSelectorThrown.C
mkdir -p etap_to_etapipi
mv *.root etap_to_etapipi

sed -i '41 s|^//||' runDSelector_7_17_14.C
sed -i '41 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=5;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[3#pi^{0}]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[3#pi^{0}]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '41 s|^|//|' runDSelector_7_17_14.C
sed -i '41 s|^|//|' runDSelectorThrown.C
mkdir -p eta_to_3pi
mv *.root eta_to_3pi

sed -i '42 s|^//||' runDSelector_7_17_14.C
sed -i '42 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=6;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[2#pi^{0},#eta]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="6#gammap[2#pi^{0},#eta]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '42 s|^|//|' runDSelector_7_17_14.C
sed -i '42 s|^|//|' runDSelectorThrown.C
mkdir -p f1_1285_to_etapipi
mv *.root f1_1285_to_etapipi

sed -i '43 s|^//||' runDSelector_7_17_14.C
sed -i '43 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=7;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="3#gammap[#pi^{0}]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="3#gammap[#pi^{0}]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '43 s|^|//|' runDSelector_7_17_14.C
sed -i '43 s|^|//|' runDSelectorThrown.C
mkdir -p omega_pi0g
mv *.root omega_pi0g

sed -i '44 s|^//||' runDSelector_7_17_14.C
sed -i '44 s|^//||' runDSelectorThrown.C
sed -i 's|mcprocess=.*;|mcprocess=8;|' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="4#gammap[2#pi^{0}]"/' DSelector_ver20.C
sed -i 's/topologyString=".*"/topologyString="4#gammap[2#pi^{0}]"/' DSelector_thrown.C
#root -l -b -q runDSelector_7_17_14.C
root -l -b -q runDSelectorThrown.C
sed -i '44 s|^|//|' runDSelector_7_17_14.C
sed -i '44 s|^|//|' runDSelectorThrown.C
mkdir -p pi0pi0
mv *.root pi0pi0

sed -i '36,44 s|^//||' runDSelector_7_17_14.C
sed -i '36,44 s|^//||' runDSelectorThrown.C

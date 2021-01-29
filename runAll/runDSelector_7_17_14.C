// macro to process analysis TTree with DSelector
// We cannot just run this macro, the library doesnt load properly. We can run the following two lines of code
//.x $(ROOT_ANALYSIS_HOME)/scripts/Load_DSelector.C
//.x runDSelector.C

#include <iostream> 
#include <fstream>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"


//R__LOAD_LIBRARY(/group/halld/Software/builds/Linux_CentOS7-x86_64-gcc4.8.5/gluex_root_analysis/gluex_root_analysis-0.5/Linux_CentOS7-x86_64-gcc4.8.5/lib/libDSelector.so)
//R__LOAD_LIBRARY(/d/home/ln16/gluex_top/gluex_root_analysis/gluex_root_analysis_1.7.0/Linux_CentOS7-x86_64-gcc4.8.5/lib/libDSelector.so) 
R__LOAD_LIBRARY(libDSelector.so)

void runDSelector_7_17_14(bool useproof = 1, string path = "") 
{
	cout << "Loaded using R__LOAD_LIBRARY" << endl;
	// Load DSelector library
	gROOT->ProcessLine(".x $(ROOT_ANALYSIS_HOME)/scripts/Load_DSelector.C");
	// change the directory that proof saves the data to
	//gEnv->SetValue("ProofLite.Sandbox", "/d/grid15/ln16/.proof");
	int proof_Nthreads = 24;
	//int proof_Nthreads = 50;

	// open ROOT files and TTree
	//TString nameOfTree = "pi0eta__B3_F1_M7_M17_Tree"; // pi0eta__B4_Tree is the old one
	//TString nameOfTree = "pi0eta__B4_F1_M7_M17_Tree"; // pi0eta__B4_Tree is the old one
	TString nameOfTree = "pi0eta__B4_M17_M7_Tree"; 
	//TString nameOfTree = "pi0pi0__B3_F1_U1_M7_Tree";
	TChain *chain = new TChain(nameOfTree);

        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/5M/a0/tree_pi0eta*.root");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/5M/a2/tree_pi0eta*.root");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/30M/a2pi/tree_pi0eta*");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/30M/b1/tree_pi0eta__B4_M17_M7_gen_amp*");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/30M/etap_to_etapipi/tree_pi0eta*");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/30M/eta_to_3pi/tree_pi0eta*");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/30M/f1_to_etapipi/tree_pi0eta*");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/30M/omega_pi0g/tree_pi0eta*.root");
        chain->Add("/d/grid15/ln16/rootFiles/pi0eta/seansBkgMC/rootTrees/30M/pi0pi0/tree_pi0eta*");

	string degAngle="degALL";
        string tag="_acc_mEllipse";

	//string options = sample;
	string options = "";
	if(useproof) { // add TTree to chain and use PROOFLiteManager
		string outputHistFileName;
                string outputTreeFileName;
		outputHistFileName = degAngle+tag+"_hists_DSelector.root";
		outputTreeFileName = degAngle+tag+"_tree_DSelector.root"; 
	
		DPROOFLiteManager::Process_Chain(chain, "DSelector_ver20.C+",  proof_Nthreads, outputHistFileName, outputTreeFileName, options);
	}
	else { // get TTree and use standard TTree::Process
		//TFile *f = TFile::Open(fileName);
		//TTree *tree = (TTree*)f->Get("omega_skim_Tree");
		chain->Process("DSelector_ver20.C+", options.data());
		
	}
	
	//putenv(oldHome);
	//system("echo Returning to  Home At:");
	//system("echo $HOME");
	cout << "\033[1;31mMAKE SURE IF YOU ARE RUNNING ON PI0PI0 DATA WE USE mergePi0.root WITH THE CORRECT FILE!\n1)Change file name in mergePi0.root\n2)root -l -b -q mergePi0.root \033[0m\n";
	cout << "\033[1;31mRemember that Mpi0, Meta, Mpi0eta fundamental branches have a cut applied on them! This is for SPlotting to define a better region \033[0m\n";

	return;
}

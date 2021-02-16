void DoContour2DSterileGridRP11RP12RP13DATA_LogScale_LowEFit( 
                                                      double Dm41 = 0.01,
                                                      double dcpp = 0.0,
                                                      double d14p = 0.0,
                                                      double d24p = 0.0,
                                                      double th34p = 0.0,
                                                      double th13float = 0.0,
                                                      double th23float = 0.0,
                                                      double dmsq32float = 0.0,
                                                      int qdnt = 0,
                                                      int inv = 0,
                                                      bool lowEfit = true) {
  gROOT->LoadMacro("$SRT_PRIVATE_CONTEXT/NueAna/macros/LoadLibs.C");
  LoadLibs();

  // Reco E
  Int_t nr = 6;
  Double_t r[7] = {6., 7., 8., 9., 10., 11., 12.};

  Int_t nr_lowEfit = 11;
  Double_t r_lowEfit[12] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12.};

  // PID
  Int_t np = 2;
  Double_t p[3] = {0.7, 0.8, 1.0};

  Int_t nt = 600;
  Double_t t[601];
  for (int i = 0; i < 601; i++) {
    t[i] = 0.1 * i;
  }

  // ----
  // From Adam

  Extrapolate2D *E1 = new Extrapolate2D();
  if (!lowEfit) {
    E1->SetRecoBins(nr, r);
  } else {
    E1->SetRecoBins(nr_lowEfit, r_lowEfit);
  }
  E1->SetPIDBins(np, p);
  E1->SetTrueBins(nt, t);
  E1->SetFarPOT(2.96697e20);  // R11 alone (from AnaNue-F)
  E1->SetPID("E50S491");
  E1->SetFNforBeamNue();
  E1->SetRunPeriod(1);
  if (!lowEfit) {
    E1->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");  // Currently
    E1->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP11.root");  
  } else {
    E1->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Low_Std_AllRuns.root");  // Currently   
    E1->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP11_LowE.root");  
  }
  E1->SetXSecFile("inputs/XSecFile/xsec_minos_modbyrs4_v3_5_0_mk.root");
  E1->SetMREFile("inputs/MRE/MRE_Correction_MINOS_AfterSSPIDCut_r4_00_ND_20190728.root");
  E1->SetPrintResult();
  E1->SetOscMethod(3);
  E1->GetPrediction();

  Extrapolate2D *E2 = new Extrapolate2D();
  if (!lowEfit) {
    E2->SetRecoBins(nr, r);
  } else {
    E2->SetRecoBins(nr_lowEfit, r_lowEfit);
  }
  E2->SetPIDBins(np, p);
  E2->SetTrueBins(nt, t);
  E2->SetFarPOT(2.80296e20);  // R12 alone (from AnaNue-F)
  E2->SetPID("E50S491");
  E2->SetFNforBeamNue();
  E2->SetRunPeriod(2);
  if (!lowEfit) {
    E2->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");  // Currently
    E2->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP12.root");
  } else {
    E2->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Low_Std_AllRuns.root");  // Currently   
    E2->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP12_LowE.root");
  }
  E2->SetXSecFile("inputs/XSecFile/xsec_minos_modbyrs4_v3_5_0_mk.root");
  E2->SetMREFile("inputs/MRE/MRE_Correction_MINOS_AfterSSPIDCut_r4_00_ND_20190728.root");
  E2->SetPrintResult();
  E2->SetOscMethod(3);
  E2->GetPrediction();

  Extrapolate2D *E3 = new Extrapolate2D();
  if(!lowEfit) {
    E3->SetRecoBins(nr, r);
  } else {
    E3->SetRecoBins(nr_lowEfit, r_lowEfit);
  }
  E3->SetPIDBins(np, p);
  E3->SetTrueBins(nt, t);
  E3->SetFarPOT(3.88486e+20);
  E3->SetPID("E50S491");
  E3->SetFNforBeamNue();
  E3->SetRunPeriod(3);
  if (!lowEfit) {
    E3->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");  // Currently
    E3->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP13.root");
  } else {
    E3->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Low_Std_AllRuns.root");  // Currently   
    E3->SetFNFile("inputs/ExtrapolationFiles/ExtrapFile_SSPID_E50S491_RP13_LowE.root");
  }
  E3->SetXSecFile("inputs/XSecFile/xsec_minos_modbyrs4_v3_5_0_mk.root");
  E3->SetMREFile("inputs/MRE/MRE_Correction_MINOS_AfterSSPIDCut_r4_00_ND_20190728.root");
  E3->SetPrintResult();
  E3->SetOscMethod(3);
  E3->GetPrediction();

  // PDG values (http://pdglive.lbl.gov/Particle.action?node=S067)
  double th12 = 0.5873;
  double dm21 = 7.53e-5;

  double th34 = th34p * TMath::Pi();
  double dcp = dcpp * TMath::Pi();
  double d14 = d14p * TMath::Pi();
  double d24 = d24p * TMath::Pi();
  double th23 = th23float;
  double dm32 = dmsq32float;
  double th13 = th23float;

  ErrorCalc *E = new ErrorCalc();
  if (!lowEfit) {
    E->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Std_R11R12R13.root");  // Currently
  } else {
    E->SetNDDataFile("inputs/BeamDecompose/HOOHE_2pid_E50S491_Low_Std_AllRuns.root");  // Currently   
  }
  E->AddExtrap(E1);
  E->AddExtrap(E2);
  E->AddExtrap(E3);
  E->SetSysFileDir("inputs/Systematics/");

  E->AddFNExtrapSyst("Abs E-scale", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma",
                     "Minus1Sigma", "Nominal", "AbsEScale", 2, true);
  E->AddFNExtrapSyst("EMvsHad", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma",
                     "Minus1Sigma", "Nominal", "EMvsHad", 2, true);
  E->AddFNExtrapSyst("Had1 (Baryon $x_f$)", "Hadup1", "Hadup1", "Hadup1",
                     "Hadup1", "Nominal", "had1", 2, true);
  E->AddFNExtrapSyst("Had2 ($\\pi^{0}$ sel.)", "Hadup2", "Hadup2", "Nominal",
                     "Nominal", "Nominal", "had2", 2, true);
  E->AddFNExtrapSyst("Had3 (mult. corr.)", "Hadup3", "Hadup3", "Hadup3",
                     "Hadup3", "Nominal", "had3", 2, true);
  E->AddFNExtrapSyst("Had4 (imp. amb.)", "Hadup4", "Hadup4", "Hadup4", "Hadup4",
                     "Nominal", "had4", 2, true);
  E->AddFNExtrapSyst("Had5 ($p_T$ squz)", "Hadup5", "Hadup5", "Hadup5",
                     "Hadup5", "Nominal", "had5", 2, true);
  E->AddFNExtrapSyst("Had6 (iso. 2-body dec.)", "Hadup6", "Hadup6", "Hadup6",
                     "Hadup6", "Nominal", "had6", 2, true);
  E->AddFNExtrapSyst("Had10", "Hadup10", "Hadup10", "Nominal", "Nominal",
                     "Nominal", "had10", 2, true);
  E->AddFNExtrapSyst("Hadron Mult.", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma",
                     "Minus1Sigma", "Nominal", "HadMult", 2, true);
  E->AddFNExtrapSyst("KNO", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma",
                     "Minus1Sigma", "Nominal", "KNO", 0, true);
  E->AddFNExtrapSyst("MAQE", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma",
                     "Minus1Sigma", "Nominal", "MAQE", 0, true);
  E->AddFNExtrapSyst("MARES", "Plus1Sigma", "Plus1Sigma", "Minus1Sigma",
                     "Minus1Sigma", "Nominal", "MARES", 0, true);
  E->AddFNExtrapSyst("Rel E-scale (F $\\pm 1\\sigma$)", "Plus1Sigma", "Nominal",
                     "Minus1Sigma", "Nominal", "Nominal", "RelEScale", 0, true);
  E->AddFNExtrapSyst("Rel E-scale (N $\\pm 1\\sigma$)", "Nominal", "Plus1Sigma",
                     "Nominal", "Minus1Sigma", "Nominal", "RelEScale", 0, true);
  E->AddFNExtrapSyst("$\\nu_{\\tau}$ xsec", "Plus1Sigma", "Plus1Sigma",
                     "Minus1Sigma", "Minus1Sigma", "Nominal", "TauXSec", 2,
                     true);
  E->AddFNExtrapSyst("$\\nu_{\\mu}$ MAQE", "Plus1Sigma", "Plus1Sigma",
                     "Minus1Sigma", "Minus1Sigma", "Nominal", "CCMAQE", 1,
                     true);
  E->AddFNExtrapSyst("$\\nu_{\\mu}$ MARES", "Plus1Sigma", "Plus1Sigma",
                     "Minus1Sigma", "Minus1Sigma", "Nominal", "CCMARES", 1,
                     true);
  E->AddFNExtrapSyst("$\\nu_{\\mu}$ KNO", "Plus1Sigma", "Plus1Sigma",
                     "Minus1Sigma", "Minus1Sigma", "Nominal", "CCKNO", 1, true);
  E->AddFNExtrapSyst("CCEnergyShift", "plus10pct", "plus10pct", "minus10pct",
                     "minus10pct", "normal", "CCEnergyShift", 1, true);
  E->AddFNExtrapSyst("CCSigNC", "plus50pct", "plus50pct", "minus50pct",
                     "minus50pct", "normal", "CCSigNC", 1, true);

  // Constant errors
  E->AddSpecialFNSyst("TauNorm", 0.024, "NULL", "NULL", 2);
  E->AddSpecialFNSyst("NueNorm", 0.024, "NULL", "NULL", 3);
  E->AddSpecialFNSyst("Norm", 0.02, "NULL", "NULL", 1);

  if (!lowEfit) {
    E->AddCovarianceMatrix("MRE", "inputs/MRE/MRE_ErrMatrix_20190728_r4_00.root", "syst_mre", 3);
    E->AddCovarianceMatrix("MRCC2", "inputs/MRCC/MRCC_ErrMatrix_2PIDbins_SSPID_09062020.root",  "syst_mrcc",  2);  // NuTauCC
    E->AddCovarianceMatrix("MRCC4", "inputs/MRCC/MRCC_ErrMatrix_2PIDbins_SSPID_09062020.root",  "syst_mrcc",  4);  // NumuCC and NC
  } else {
    E->AddCovarianceMatrix("MRE", "inputs/MRE/MRE_ErrMatrix_LowE5b_20200817_r4_00.root", "syst_mre", 3);
    E->AddCovarianceMatrix("MRCC2", "inputs/MRCC/MRCC_ErrMatrix_2PIDbins_SSPID_LowE5b_10082020.root",  "syst_mrcc", 2);
    E->AddCovarianceMatrix("MRCC4", "inputs/MRCC/MRCC_ErrMatrix_2PIDbins_SSPID_LowE5b_10082020.root",  "syst_mrcc", 4);
  }
  // E->AddCovarianceMatrix("Inflate", "inputs/Systematics/Inflate_Syst/Inflate_ErrMatrix_2PIDbins_SSPID_26062020.root", "syst_inflate", 0);

  // Initialize the Errors
  E->CalculateSystErrorMatrix();
/*
  E1->SetOscPar(OscPar::kTh12, th12);
  E1->SetOscPar(OscPar::kDeltaM12, dm21);
  E1->SetOscPar(OscPar::kTh23, th23);
  E1->SetOscPar(OscPar::kDeltaM23, dm32);
  E1->SetOscPar(OscPar::kTh13, th13);
  E1->SetOscPar(OscPar::kDelta, dcp);
  E1->SetOscPar(OscPar::kDelta14, d14);
  E1->SetOscPar(OscPar::kDelta24, d24);
  E1->SetOscPar(OscPar::kTh34, th34);
  E1->SetOscPar(OscPar::kDm41, Dm41);
  E1->OscillatePrediction();

  E2->SetOscPar(OscPar::kTh12, th12);
  E2->SetOscPar(OscPar::kDeltaM12, dm21);
  E2->SetOscPar(OscPar::kTh23, th23);
  E2->SetOscPar(OscPar::kDeltaM23, dm32);
  E2->SetOscPar(OscPar::kTh13, th13);
  E2->SetOscPar(OscPar::kDelta, dcp);
  E2->SetOscPar(OscPar::kDelta14, d14);
  E2->SetOscPar(OscPar::kDelta24, d24);
  E2->SetOscPar(OscPar::kTh34, th34);
  E2->SetOscPar(OscPar::kDm41, Dm41);
  E2->OscillatePrediction();

  E3->SetOscPar(OscPar::kTh12, th12);
  E3->SetOscPar(OscPar::kDeltaM12, dm21);
  E3->SetOscPar(OscPar::kTh23, th23);
  E3->SetOscPar(OscPar::kDeltaM23, dm32);
  E3->SetOscPar(OscPar::kTh13, th13);
  E3->SetOscPar(OscPar::kDelta, dcp);
  E3->SetOscPar(OscPar::kDelta14, d14);
  E3->SetOscPar(OscPar::kDelta24, d24);
  E3->SetOscPar(OscPar::kTh34, th34);
  E3->SetOscPar(OscPar::kDm41, Dm41);
  E3->OscillatePrediction();

  // Runs 11, 12, 13  box opening
  TH1D *nobs = new TH1D("nobs", "", 24, -0.5, 23.5);

  nobs->SetBinContent(1,  0); // LEM [0.7, 0.8]; E [1,   2]
  nobs->SetBinContent(2,  0); // LEM [0.8, 1.0]; E [1,   2]
  nobs->SetBinContent(3,  0); // LEM [0.7, 0.8]; E [2,   3]
  nobs->SetBinContent(4,  0); // LEM [0.8, 1.0]; E [2,   3]
  nobs->SetBinContent(5, 10); // LEM [0.7, 0.8]; E [3,   4]
  nobs->SetBinContent(6,  4); // LEM [0.8, 1.0]; E [3,   4]
  nobs->SetBinContent(7, 15); // LEM [0.7, 0.8]; E [4,   5]
  nobs->SetBinContent(8, 13); // LEM [0.8, 1.0]; E [4,   5]
  nobs->SetBinContent(9, 22); // LEM [0.7, 0.8]; E [5,   6]
  nobs->SetBinContent(10,14); // LEM [0.8, 1.0]; E [5,   6]
  
  nobs->SetBinContent(11, 18);  // LEM [0.7, 0.8]; E [6,   7]
  nobs->SetBinContent(12, 26);  // LEM [0.8, 1.0]; E [6,   7]
  nobs->SetBinContent(13, 11);  // LEM [0.7, 0.8]; E [7,   8]
  nobs->SetBinContent(14, 20);  // LEM [0.8, 1.0]; E [7,   8]
  nobs->SetBinContent(15,  8);  // LEM [0.7, 0.8]; E [8,   9]
  nobs->SetBinContent(16, 16);  // LEM [0.8, 1.0]; E [8,   9]
  nobs->SetBinContent(17,  7);  // LEM [0.7, 0.8]; E [9,  10]
  nobs->SetBinContent(18,  7);  // LEM [0.8, 1.0]; E [9,  10]
  nobs->SetBinContent(19,  5);  // LEM [0.7, 0.8]; E [10, 11]
  nobs->SetBinContent(20,  2);  // LEM [0.8, 1.0]; E [10, 11]
  nobs->SetBinContent(21,  3);  // LEM [0.7, 0.8]; E [11, 12]
  nobs->SetBinContent(22,  7);  // LEM [0.8, 1.0]; E [11, 12]

  NueFit2D *S = new NueFit2D();
  S->AddError(E);
  S->AddExtrap(E1);
  S->AddExtrap(E2);
  S->AddExtrap(E3);
  S->SetNObs(nobs);
  S->SetFitMethod(4);

  std::stringstream fileout;

  if (inv == 1) {
    cout << "Activating IH!" << endl;
    //S->LetsIH(1);
    if (qdnt == 0) {
      S->SetSinSqTh14Range(0, 0.25);
      S->SetSinSqTh24Range(0, 0.25);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeA-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 1) {
      S->SetSinSqTh14Range(0.25, 0.5);
      S->SetSinSqTh24Range(0, 0.25);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeB-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 2) {
      S->SetSinSqTh14Range(0.25, 0.5);
      S->SetSinSqTh24Range(0.25, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeC-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 3) {
      S->SetSinSqTh14Range(0.0, 0.25);
      S->SetSinSqTh24Range(0.25, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeD-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 4) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0, 0.5);
      S->SetSinSqTh24Range(0, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTA-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 5) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0.5, 1.0);
      S->SetSinSqTh24Range(0, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTB-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 6) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0.5, 1.0);
      S->SetSinSqTh24Range(0.5, 1.0);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTC-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 7) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0, 0.5);
      S->SetSinSqTh24Range(0.5, 1.0);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_IH_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTD-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else {
      cout << "Learn your quads!" << endl;
      return;
    }
  } else {
    if (qdnt == 0) {
      S->SetSinSqTh14Range(0, 0.25);
      S->SetSinSqTh24Range(0, 0.25);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeA-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 1) {
      S->SetSinSqTh14Range(0.25, 0.5);
      S->SetSinSqTh24Range(0, 0.25);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeB-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 2) {
      S->SetSinSqTh14Range(0.25, 0.5);
      S->SetSinSqTh24Range(0.25, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeC-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 3) {
      S->SetSinSqTh14Range(0.0, 0.25);
      S->SetSinSqTh24Range(0.25, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-TypeD-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 4) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0, 0.5);
      S->SetSinSqTh24Range(0, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTA-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 5) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0.5, 1.0);
      S->SetSinSqTh24Range(0, 0.5);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTB-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 6) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0.5, 1.0);
      S->SetSinSqTh24Range(0.5, 1.0);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTC-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else if (qdnt == 7) {
      cout << "Coarse Granulatity ZP5" << endl;
      S->SetSinSqTh14Range(0, 0.5);
      S->SetSinSqTh24Range(0.5, 1.0);
      fileout << "R2DSSE50S491_3FNovember2020_RP11RP12RP13DATA_Dm41-" << Dm41 << "_DDD-" << dcpp << "-" << d14p << "-" << d24p << "_50x50-CGTD-T34-" << th34p << "_th13-" << th13float << "_th23-" << th23float << "_dmsq32-" << dmsq32float << ".root";
    } else {
      cout << "Learn your quads!" << endl;
      return;
    }
  }

  cout << "File named: " << fileout.str() << endl;
  bool DoCombineFit = true;
  S->SetOutputFile(fileout.str());
  S->Run2DSterileSlice_LogScale(DoCombineFit, lowEfit);
*/  
  return;
}

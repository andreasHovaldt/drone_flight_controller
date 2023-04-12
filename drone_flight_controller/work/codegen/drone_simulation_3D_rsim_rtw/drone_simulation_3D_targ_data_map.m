    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 58;
            section.data(58)  = dumData; %prealloc

                    ;% rtP.PIDController2_D
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.PIDController3_D
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.PIDController1_D
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.PIDController_D
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.PIDController5_D
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.PIDController4_D
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.PIDController_I
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.PIDController1_I
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.PIDController2_I
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.PIDController3_I
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.PIDController4_I
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.PIDController5_I
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.PIDController2_InitialCondition
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.PIDController3_InitialCondition
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.PIDController1_InitialCondition
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.PIDController_InitialConditionF
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.PIDController5_InitialCondition
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.PIDController4_InitialCondition
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.PIDController2_InitialConditi_n
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.PIDController3_InitialConditi_e
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.PIDController1_InitialConditi_i
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.PIDController_InitialConditio_i
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.PIDController5_InitialConditi_b
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.PIDController4_InitialConditi_g
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.PIDController3_LowerSaturationL
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.PIDController_LowerSaturationLi
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.PIDController5_LowerSaturationL
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.PIDController2_N
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.PIDController3_N
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.PIDController1_N
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.PIDController_N
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtP.PIDController5_N
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtP.PIDController4_N
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtP.PIDController2_P
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% rtP.PIDController3_P
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% rtP.PIDController1_P
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% rtP.PIDController_P
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% rtP.PIDController5_P
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% rtP.PIDController4_P
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% rtP.PIDController3_UpperSaturationL
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% rtP.PIDController_UpperSaturationLi
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% rtP.PIDController5_UpperSaturationL
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% rtP.y_ref_Amp
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 42;

                    ;% rtP.y_ref_Bias
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 43;

                    ;% rtP.y_ref_Freq
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 44;

                    ;% rtP.y_ref_Phase
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 45;

                    ;% rtP.Integrator2_IC
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 46;

                    ;% rtP.Integrator1_IC
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 47;

                    ;% rtP.x_ref_Amp
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 48;

                    ;% rtP.x_ref_Bias
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 49;

                    ;% rtP.x_ref_Freq
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 50;

                    ;% rtP.x_ref_Phase
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 51;

                    ;% rtP.Constant_Value
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 52;

                    ;% rtP.z_ref_Amp
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 53;

                    ;% rtP.z_ref_Bias
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 54;

                    ;% rtP.z_ref_Freq
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 55;

                    ;% rtP.z_ref_Phase
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 56;

                    ;% rtP.Constant3_Value
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 57;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 66;
            section.data(66)  = dumData; %prealloc

                    ;% rtB.current_pos
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.Sum2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.ProportionalGain
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% rtB.Integrator
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% rtB.DerivativeGain
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% rtB.Filter
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% rtB.SumD
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% rtB.FilterCoefficient
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% rtB.Sum
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 10;

                    ;% rtB.Integrator1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 11;

                    ;% rtB.Sum4
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 14;

                    ;% rtB.ProportionalGain_b
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 15;

                    ;% rtB.Integrator_j
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 16;

                    ;% rtB.DerivativeGain_m
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 17;

                    ;% rtB.Filter_e
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 18;

                    ;% rtB.SumD_h
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 19;

                    ;% rtB.FilterCoefficient_k
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 20;

                    ;% rtB.Sum_o
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 21;

                    ;% rtB.Saturation
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 22;

                    ;% rtB.Sum1
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 23;

                    ;% rtB.ProportionalGain_m
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 24;

                    ;% rtB.Integrator_e
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 25;

                    ;% rtB.DerivativeGain_h
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 26;

                    ;% rtB.Filter_j
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 27;

                    ;% rtB.SumD_j
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 28;

                    ;% rtB.FilterCoefficient_a
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 29;

                    ;% rtB.Sum_p
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 30;

                    ;% rtB.Sum3
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 31;

                    ;% rtB.ProportionalGain_i
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 32;

                    ;% rtB.Integrator_h
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 33;

                    ;% rtB.DerivativeGain_l
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 34;

                    ;% rtB.Filter_m
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 35;

                    ;% rtB.SumD_n
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 36;

                    ;% rtB.FilterCoefficient_e
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 37;

                    ;% rtB.Sum_h
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 38;

                    ;% rtB.Saturation_f
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 39;

                    ;% rtB.Constant
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 40;

                    ;% rtB.Sum5
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 41;

                    ;% rtB.ProportionalGain_d
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 42;

                    ;% rtB.Integrator_l
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 43;

                    ;% rtB.DerivativeGain_g
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 44;

                    ;% rtB.Filter_ey
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 45;

                    ;% rtB.SumD_no
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 46;

                    ;% rtB.FilterCoefficient_d
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 47;

                    ;% rtB.Sum_e
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 48;

                    ;% rtB.Saturation_b
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 49;

                    ;% rtB.Sum_pm
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 50;

                    ;% rtB.ProportionalGain_f
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 51;

                    ;% rtB.Integrator_a
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 52;

                    ;% rtB.DerivativeGain_a
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 53;

                    ;% rtB.Filter_g
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 54;

                    ;% rtB.SumD_f
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 55;

                    ;% rtB.FilterCoefficient_ku
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 56;

                    ;% rtB.Sum_c
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 57;

                    ;% rtB.Constant3
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 58;

                    ;% rtB.TmpSignalConversionAtInport2
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 59;

                    ;% rtB.u
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 62;

                    ;% rtB.u_l
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 65;

                    ;% rtB.IntegralGain
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 68;

                    ;% rtB.IntegralGain_j
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 69;

                    ;% rtB.IntegralGain_k
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 70;

                    ;% rtB.IntegralGain_i
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 71;

                    ;% rtB.IntegralGain_b
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 72;

                    ;% rtB.IntegralGain_kx
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 73;

                    ;% rtB.lin_acc
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 74;

                    ;% rtB.ang_acc
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 77;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% rtDW.Angacc_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.Angpos_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.Angvel_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.Linacc_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.Linpos_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.Linvel_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.Refcompcurrent_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.Scope_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.ToWorkspace_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.ToWorkspace1_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.ToWorkspace2_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.Scope_PWORK_d.LoggedData
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW._IWORK
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW._IWORK_n
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.Saturation_MODE
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.Saturation_MODE_e
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.Saturation_MODE_g
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 344102616;
    targMap.checksum1 = 268445277;
    targMap.checksum2 = 270014698;
    targMap.checksum3 = 1195129220;


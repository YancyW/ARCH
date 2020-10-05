# ARCH 
Analyse input event root files and generate observables

## change.log
- 2016/12:  v0.01 
    - Thanks to Zhao Li.   Following his sample for JEP part.
- 2017/4:   v0.02 
    - Thanks to Ning Chen. Following his sample for EFLowParticle and btag part. 
    - And crosscheck for Massdrop part.
- 2017/5:   v0.03 
    - Add analysis code for pythia final states
- 2017/7:   v0.04 
    - correct the makefile, now it will generate the obj file in each folder, so the makefile can only compile the latest file, instead of all files. 
    - But I still need to improve the makefile, maybe with autoconf/automake, because at present, the makefile still don't know the change in the head file.
- 2017/7:   v0.10 *
    - completely change the structure. 
    - Now a new class particle "AParticle" is defined, all analysis are based on this class. The input file, like delphes root, slcio, stdhep.. , are transfered to this class first.
      This particle class can store all information about one particle, no matter the four momentum and their useful  kinematic value, or the detector information for final states, which means this particle class is very large
            size, but it also make me to pass the argument very easily. In the future version, I will try to decrease the size of one particle events. 
- 2017/7:   v0.11 
    - BDT analysis are added, but the variables in the BDT are still fixed. I need to make it use arbitary variables from the input in the future version. 
- 2017/10:  v0.12 *
    - split cuts to Analyse_Root package, this package only for generate variables/observables. 
- 2017/10:  v0.13 *
    - change AJet Class based on AParticle, so Jet can also use all functions for AParticle
    - complete three cases for zh signal analysis.
- 2017/11: v0.14
    - debug for memory leak
    - change jet properties into particle, now jet is also a pool.
- 2020/10: v0.15
    - code has been tested in JEP/CNN/2HDMtype1 paper. 


TARGET=ARCH

CXX=g++
FLAGS=-std=c++14 -g

#RootPath=/home/ywang/Software/executable/root
#YAMLPath=/home/ywang/Software/lib/yaml-cpp/
#DelphesPath=/home/ywang/Software/executable/MG5_aMC_v2_6_5/Delphes
#DelphesextPath=/home/ywang/Software/executable/MG5_aMC_v2_6_5/Delphes/external
#FastjetPath=/home/ywang/Software/lib/fastjet-install/lib

RootPath=${HOME}/Software/executable/root
YAMLPath=${HOME}/Software/lib/yaml-cpp/
DelphesPath=${HOME}/Software/executable/MG5_aMC_v2_6_5/Delphes
DelphesextPath=${HOME}/Software/executable/MG5_aMC_v2_6_5/Delphes/external
FastjetPath=${HOME}/Software/lib/fastjet-install/lib

INCLUDE = -I. -I..  -I$(RootPath)/include  \
		    -I$(DelphesPath) \
		    -I$(DelphesextPath) \
            -I$(DelphesextPath)/ExRootAnalysis\
		    -I${YAMLPath}/include


LIBS = -lboost_filesystem -lboost_system  -Wl,-rpath,$(DelphesPath) -L$(DelphesPath) -lDelphes ${YAMLPath}/libyaml-cpp.a  
ROOTLIBS = -L${RootPath}/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lEG -lm -ldl -rdynamic
FASTLIBS = -Wl,-rpath,${FastjetPath} -lm -L${FastjetPath} -lfastjettools -lfastjet
#ROOTLIBS := $(shell root-config --libs)
#FASTLIBS := $(shell fastjet-config --libs)

SRCS = \
$(TARGET).cpp \
Fram/Fram.cpp Fram/Fsection.cpp \
Function/Fbasic.cpp Function/Fvector.cpp Function/Ffastjet.cpp Function/Fdelphes.cpp Function/Froot.cpp Function/Ffile.cpp\
Function/FTLorentzVector.cpp \
Lib/MessageFormat.cpp Lib/PlotSetting.cpp Lib/libstructure.cpp Lib/Define.cpp\
Class/Detector.cpp Class/file.cpp\
RWpara/RWfile.cpp RWpara/RWDraw.cpp RWpara/RWbasic.cpp RWpara/RWEvent.cpp RWpara/RWcombine.cpp RWpara/RWglobal.cpp RWpara/RWjet.cpp\
RWpara/RWlepton.cpp RWpara/RWmet.cpp RWpara/RWphoton.cpp RWpara/RWrecoil.cpp RWpara/RWjep.cpp RWpara/RWTag.cpp\
RWpara/RWMassDrop.cpp RWpara/RWNSubjettiness.cpp RWpara/RWBoostTag.cpp RWpara/RWJetSubStructure.cpp RWpara/RWVar.cpp\
RWpara/RWDetector.cpp \
Analyse/Analyse.cpp Analyse/Abasic.cpp Analyse/Aparticle.cpp Analyse/Adetector.cpp Analyse/Aequipment.cpp \
Analyse/ALepton.cpp \
Analyse/Acombine.cpp Analyse/Acomb_func.cpp Analyse/Arecoil.cpp Analyse/Acomb_recoil.cpp Analyse/ABTag.cpp\
Analyse/Ajep.cpp Analyse/Ajet_function.cpp Analyse/AMassDrop.cpp Analyse/ANSubjettiness.cpp \
Analyse/AHiggsTag.cpp Analyse/AJetSubStructure.cpp \
Analyse/Aslcio_particle.cpp \
Analyse/AN_rc_w_lnu.cpp \
Book/Book_single.cpp Book/Bfunc_single.cpp Book/Book_multi.cpp Book/Bfunc_multi.cpp \
AnalyseClass/Particle.cpp  AnalyseClass/Pool.cpp AnalyseClass/Pair.cpp  AnalyseClass/Lepton.cpp AnalyseClass/Object.cpp AnalyseClass/Jet.cpp\
AnalyseClass/Stdhep.cpp AnalyseClass/Slcio.cpp AnalyseClass/Delphes.cpp AnalyseClass/AnalyseClass.cpp \
AnalyseClass/Counter.cpp AnalyseClass/ParticleFunction.cpp  AnalyseClass/Species.cpp   AnalyseClass/Variable.cpp\
AnalyseClass/Object_Lepton.cpp AnalyseClass/Object_Jet.cpp  AnalyseClass/Object_Particle.cpp AnalyseClass/Object_Combine.cpp\
Function/Ftest.cpp


OBJS=$(patsubst %.cpp, %.o, $(SRCS))

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) -o $@ $^ $(FASTLIBS) $(ROOTLIBS)  $(LIBS)

%.o: %.cpp
	$(CXX) $(FLAGS) $(INCLUDE) -c $<  -o  $@

clean:
	-rm $(TARGET) $(OBJS)

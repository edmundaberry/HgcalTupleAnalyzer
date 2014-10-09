COMP=g++
FLAGS=
# FLAGS = -g
ROOTINC= -I`root-config --incdir`
ROOTLIBS=  `root-config --glibs --cflags | sed 's/-pthread//g'` -lMinuit 
INC= -I./include 
LIBS= ${ROOTLIBS} 
SRC= ./src
OBJECTS=$(SRC)/analysisClass.o $(SRC)/baseClass.o 
SELECTIONLIB=$(SRC)/HgcalTupleTree.o $(SRC)/baseClass.o $(SRC)/analysisClass.o 
COLLECTIONLIB=$(SRC)/Collection.o
PHYOBJECTSLIB=$(SRC)/Object.o $(SRC)/GenParticle.o $(SRC)/GenJet.o $(SRC)/PFCand.o $(SRC)/HGCEERecHit.o $(SRC)/HGCHEBRecHit.o $(SRC)/HGCHEFRecHit.o $(SRC)/PFCluster.o $(SRC)/HGCEECluster.o $(SRC)/HGCHEBCluster.o $(SRC)/HGCHEFCluster.o $(SRC)/PFJet.o $(SRC)/PFPrunedJet.o $(SRC)/PFPrunedR001Jet.o  $(SRC)/PFPrunedR003Jet.o  $(SRC)/PFPrunedR005Jet.o  $(SRC)/PFPrunedR008Jet.o  $(SRC)/PFPrunedR01Jet.o  $(SRC)/PFPrunedR02Jet.o  $(SRC)/PFPrunedR03Jet.o  $(SRC)/PFPrunedR04Jet.o  $(SRC)/PFPrunedR05Jet.o  $(SRC)/PFPrunedR1Jet.o  $(SRC)/PFPrunedR2Jet.o  $(SRC)/PFPrunedR3Jet.o  $(SRC)/PFPrunedR4Jet.o $(SRC)/PFPrunedR5Jet.o $(SRC)/likelihoodGetter.o
IDOBJECTSLIB=$(SRC)/GenParticleIDs.o $(SRC)/GenJetIDs.o $(SRC)/PFCandIDs.o $(SRC)/HGCEERecHitIDs.o $(SRC)/HGCHEBRecHitIDs.o $(SRC)/HGCHEFRecHitIDs.o $(SRC)/PFJetIDs.o $(SRC)/HGCEEClusterIDs.o $(SRC)/HGCHEBClusterIDs.o $(SRC)/HGCHEFClusterIDs.o

default: main

main: $(SRC)/main.o $(SELECTIONLIB) $(COLLECTIONLIB) $(PHYOBJECTSLIB) $(IDOBJECTSLIB)
	$(COMP) $(INC) $(ROOTINC) $(LIBS) $(FLAGS) $(CFLAGS) -o $@ $(SELECTIONLIB) $(COLLECTIONLIB) $(PHYOBJECTSLIB) $(IDOBJECTSLIB) $(SRC)/$@.o

.cc.o:
	$(COMP) -c $(INC) $(ROOTINC) $(FLAGS) $(CFLAGS) -o $@ $<

.C.o:
	$(COMP) -c $(INC) $(ROOTINC) $(FLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -rf main
	rm -rf $(SRC)/*.o


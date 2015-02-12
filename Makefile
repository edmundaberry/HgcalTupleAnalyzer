COMP=clang++
FLAGS= -std=c++11 -g
# FLAGS = -g
ROOTINC= -I`root-config --incdir`
ROOTLIBS=  `root-config --glibs --cflags | sed 's/-pthread//g'` -lMinuit 
INC= -I./include 
LIBS= ${ROOTLIBS} 
SRC= ./src
SELECTIONLIB=$(SRC)/HgcalTupleTree.o $(SRC)/baseClass.o $(SRC)/analysisClass.o 
COLLECTIONLIB=$(SRC)/Collection.o
PHYOBJECTSLIB=$(SRC)/Object.o $(SRC)/GenParticle.o $(SRC)/GenJet.o $(SRC)/PFCand.o $(SRC)/PFCluster.o $(SRC)/HGCEECluster.o $(SRC)/HGCHEBCluster.o $(SRC)/HGCHEFCluster.o $(SRC)/PFPrunedJet.o $(SRC)/PFCoreJet.o $(SRC)/likelihoodGetter.o  $(SRC)/HGCEERecHit.o $(SRC)/HGCHEBRecHit.o $(SRC)/HGCHEFRecHit.o 
IDOBJECTSLIB=$(SRC)/GenParticleIDs.o $(SRC)/GenJetIDs.o $(SRC)/PFCandIDs.o $(SRC)/HGCEERecHitIDs.o $(SRC)/HGCHEBRecHitIDs.o $(SRC)/HGCHEFRecHitIDs.o $(SRC)/PFJetIDs.o $(SRC)/HGCEEClusterIDs.o $(SRC)/HGCHEBClusterIDs.o $(SRC)/HGCHEFClusterIDs.o
ALL=$(SELECTIONLIB) $(COLLECTIONLIB) $(PHYOBJECTSLIB) $(IDOBJECTSLIB)
DEP= $(ALL:.o=.d)


default: main

main: $(SRC)/main.o $(SELECTIONLIB) $(COLLECTIONLIB) $(PHYOBJECTSLIB) $(IDOBJECTSLIB)
	$(COMP) $(INC) $(ROOTINC) $(LIBS) $(FLAGS) -o $@ $(SELECTIONLIB) $(COLLECTIONLIB) $(PHYOBJECTSLIB) $(IDOBJECTSLIB) $(SRC)/$@.o

.cc.o:
	$(COMP) -c -MMD -MP $(INC) $(ROOTINC) $(FLAGS) -o $@ $<

.C.o:
	$(COMP) -c -MMD -MP $(INC) $(ROOTINC) $(FLAGS) -o $@ $<

clean:
	rm -rf main
	rm -rf $(SRC)/*.o
	rm -rf $(SRC)/*.d

-include $(DEP)

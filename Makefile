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
PHYOBJECTSLIB=$(SRC)/Object.o $(SRC)/GenParticle.o $(SRC)/GenJet.o $(SRC)/PFCand.o $(SRC)/HGCEERecHit.o $(SRC)/HGCHEBRecHit.o $(SRC)/HGCHEFRecHit.o $(SRC)/PFJet.o $(SRC)/PFPrunedR5Jet.o
IDOBJECTSLIB=$(SRC)/GenParticleIDs.o $(SRC)/GenJetIDs.o $(SRC)/PFCandIDs.o $(SRC)/HGCEERecHitIDs.o $(SRC)/HGCHEBRecHitIDs.o $(SRC)/HGCHEFRecHitIDs.o $(SRC)/PFJetIDs.o

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


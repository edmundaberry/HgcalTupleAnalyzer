HgcalTupleAnalyzer
==================

Maintained by Edmund Berry: Edmund.A.Berry(at)CERN.CH

Code to analyze ntuples made by HcalTupleMaker:
* https://github.com/edmundaberry/HgcalTupleMaker

To compile:
* git clone git@github.com:edmundaberry/HgcalTupleAnalyzer.git
* cd HgcalTupleAnalyzer 
* ln -s $PWD/macros/analysisClass.C src/analysisClass.C
* make

Requires:
* ROOT: http://root.cern.ch
* gcc
import os, sys

rcut_factors = [ 
    0.001,
    0.005,
    0.008,
    0.01 ,
    0.02 ,
    0.03 ,
    0.04 ,
    0.05 ,
    0.1  ,
    0.2  ,
    0.3  ,
    0.4  ,
    0.5  
]

for factor in rcut_factors:
    
    name = str(factor).replace("0.","")
    
    old_src_file = "src/PFPrunedR003Jet.C"
    new_src_file = old_src_file.replace("003", name)

    old_header_file = "include/PFPrunedR003Jet.h"
    new_header_file = old_header_file.replace("003", name)
    
    cp_command_1 = "cp " + old_src_file + " " + new_src_file
    cp_command_2 = "cp " + old_header_file + " " + new_header_file
    
    perl_command_1 = "perl -pi -e 's/003/" + name + "/g' " + new_src_file
    perl_command_2 = "perl -pi -e 's/003/" + name + "/g' " + new_header_file

    os.system ( cp_command_1 )
    os.system ( cp_command_2 )
    
    os.system ( perl_command_1 )
    os.system ( perl_command_2 )

    print "$(SRC)/PFPrunedR" + name + "Jet.o ",

print "\n"

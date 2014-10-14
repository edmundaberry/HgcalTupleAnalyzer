import os 

r_parameters = [ 
    "R001",
    "R003",
    "R008",
    "R01",
    "R02",
    "R03",
    "R04",
    "R05",
    "R1",
    "R2",
    "R3",
    "R4",
    "R5" 
]

for r_parameter in r_parameters:
    commands = []
    commands.append( "cp include/PFPrunedR005Jet.h include/PFPruned"+r_parameter+"Jet.h")
    commands.append( "perl -pi -e 's/005/" + r_parameter[1:] + "/g' include/PFPruned"+r_parameter+"Jet.h")
    commands.append( "cp src/PFPrunedR005Jet.C src/PFPruned"+r_parameter+"Jet.C")
    commands.append( "perl -pi -e 's/005/" + r_parameter[1:] + "/g' src/PFPruned"+r_parameter+"Jet.C")

    for command in commands:
        print command
        os.system(command)
    

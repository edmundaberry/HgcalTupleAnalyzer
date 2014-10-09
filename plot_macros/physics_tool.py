from objects import *
import math

def phi_mpi_pi( x ) : 
    retval = x
    while retval >=       math.pi: retval -= (2. * math.pi)
    while retval <  -1. * math.pi: retval += (2. * math.pi)
    return retval

def deltaPhi(obj1, obj2):
    retval = phi_mpi_pi(obj1.phi - obj2.phi)
    return retval

def deltaR( obj1, obj2 ):
    deta = obj1.eta - obj2.eta
    dphi = deltaPhi(obj1, obj2)
    dr = math.sqrt(deta*deta + dphi*dphi)
    return dr

def getFlavor(jet, gen_particles):
    
    candidates_pt  = []
    candidates_pdg = []
    candidates     = []

    for gen_particle in gen_particles:
        dr = deltaR(jet, gen_particle)
        if dr > 0.3: continue
        if gen_particle.pdg >= 81 and gen_particle.pdg <= 100: continue
        if gen_particle.hasPartonDaughter: continue
        candidates.append ( gen_particle )
        candidates_pdg.append ( gen_particle.pdg ) 
        candidates_pt.append ( gen_particle.pt ) 
        
    index = -999
    
    if 4 in candidates_pdg:
        index = candidates_pdg.index( 4 ) 
    elif 5 in candidates_pdg:
        index = candidates_pdg.index( 5 ) 
    else:
        index = candidates_pt.index(max(candidates_pt))

    return candidates[index]

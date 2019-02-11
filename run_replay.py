#!/usr/bin/env python
import sys
import os
import subprocess
#import ROOT
#from ROOT import gROOT

#coin runs--7
#cRun=[1914,1915,1916,1917,1918,1919,6022]

#SHMS runs--18
#sRun=[1813,1814,1815,1816,1817,1818,1819,1820,1821,1822,1823,2233,2234,2235,2236,2237,2238,2239]
sRun=[7116,7124]
#cRun=[6620]

#replay coin runs
#for ic in range (0,7):
    # open root in hcana, run the file, and exit
#    subprocess.call("./hcana -b -q 'SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C(%d,%d)'" % (cRun[ic], -1),shell=True)

#replay SHMS runs
for ii in range (0,2):
    # open root in hcana, run the file, and exit
    subprocess.call("./hcana -b -q 'SCRIPTS/SHMS/PRODUCTION/replay_production_all_shms.C(%d,%d)'" % (sRun[ii], -1),shell=True)


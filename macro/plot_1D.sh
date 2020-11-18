#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}"  )" && pwd  )"

cd ${DIR}/

    mass_profile="{ \"./Event_Analyse_CEPC/events/zh2mu2j.root\"
    			}" 
    root -l  plot_1D.C"(${mass_profile})"


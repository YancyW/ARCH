#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}"  )" && pwd  )"

cd ${DIR}/

    mass_profile="{ \"./Event_Draw_2hdm/events_a/2hdm_sig_bp1.root\"
				  , \"./Event_Draw_2hdm/events_a/2hdm_sig_bp2.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_sig_bp3.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_sig_bp4.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_tjtata.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_ttll.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_wtatajj.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_tt_lep_lep.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_tt_lep_tau.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_tt_lep_quark.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_tt_tau_tau.root\"  
				  , \"./Event_Draw_2hdm/events_a/2hdm_tt_tau_quark.root\"  
    			}" 
    root -l  plot_1D.C"(${mass_profile})"


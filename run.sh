#!/bin/bash
if [[ -a  ./plot/*  ]] ; then
	rm ./plot/*
fi
if [[ -a  ./plot_compare/*  ]] ; then
	rm ./plot_compare/*
fi
make clean
make -j8
ctags -R
./Analyse_Root



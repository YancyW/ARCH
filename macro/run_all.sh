#!/bin/bash
if [[  $# != 1 ]]  ; then
|   echo "usage: ./run_all.sh subjob/no) "
|   exit
fi

sub=$1

path_profile=("path_higgs_2g2w.dat"
              "path_higgs_2g2b.dat"
			  )
path_length=${#path_profile[@]}

for (( j=0; j<$(( $path_length)); j++ ))
do
|   this_path=${path_profile[j]}

|   echo "----- submit job for ${this_path} process-----"
|   if [[ ${sub} == "subjob" ]] ; then
    |   ${HOME}/Code/Subjob/run_it_on_condor.sh ./run.sh ${this_path}
    |   sleep 2
|   else
|   |   ./run.sh ${this_path}
|   |   sleep 2
|   fi

done


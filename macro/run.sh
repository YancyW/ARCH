#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}"  )" && pwd  )"

cd ${DIR}/../

this_path=$1
echo ".run /ARCH " ${this_path}
./ARCH control_CEPC/${this_path}

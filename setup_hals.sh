#!/bin/bash
#
# setup_hals.sh    by    Aragon12
#
# a simple script.. to clone & setup qcom HALS
# for AOSP based pie roms
# the HALS cloned by the script has already Project Pathmaps reverted... to be used on non LOS based roms
#
# BEWARE: this script is very device specific for now

die() {
printf "\n\e[1;31mERROR: $1\e[0m\n"  1>&2
exit 1
}

usage() {
printf "%5s\e[1msetup_hals.sh by Aragon12\n"
printf "%5sa simple script.. to clone & setup qcom HALS for AOSP based pie roms\n"
printf "%10sUsage: $0 [ROM source path]\e[0m\n"
}

clean_hal() {
rm -rf $ROM_S/hardware/qcom/$1-caf/msm8996
}

clone_hal() {
git clone  https://github.com/aragon12/hardware_qcom_$1.git -b pie-caf-8996 $ROM_S/hardware/qcom/$1-caf
}

[ -z "$1" ] && usage && exit
[ ! -d "$1" ] && usage && die "dir $1 doesn't exists" 
ROM_S=$(realpath $1)
printf "Using $ROM_S as rom source dir\n"

printf "Cleaning existing HALS\n"
clean_hal "audio"
clean_hal "display"
clean_hal "media"

printf "Cloning HALS for AOSP PIE\n"
clone_hal "audio"
clone_hal "display"
clone_hal "media"

printf "\e[1;32mSuccessfully setup HALS!!!\n\e[0m"
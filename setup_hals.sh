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
for kek in $1
do
rm -rf hardware/qcom/$kek-caf/msm8996
done
}

clone_hal() {
for oof in $1
do
git clone  https://github.com/aragon12/hardware_qcom_$oof.git -b pie-caf-8996 hardware/qcom/$oof-caf
done
}

[ -z "$1" ] && usage && exit
[ ! -d "$1" ] && usage && die "dir $1 doesn't exists" 
cd $1
printf "Using $(realpath .) as rom source dir\n"

printf "Cleaning existing HALS\n"
clean_hal "audio display media"

printf "Cloning HALS for AOSP PIE\n"
clone_hal "audio display media"

printf "\e[1;32mSuccessfully setup HALS!!!\n\e[0m"

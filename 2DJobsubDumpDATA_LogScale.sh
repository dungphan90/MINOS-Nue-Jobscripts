#! /bin/env bash

# Always cd to the scratch area
cd $_CONDOR_SCRATCH_DIR
echo " "
echo "MY CONDOR SCRATCH = ${_CONDOR_SCRATCH_DIR}"

# I like keeping track of this
mypwd=`pwd`


#################  Define variables common to all JOBs ###############

PNFS=/pnfs/minos/persistent/users/dphan/nue2020-08192020/Common
CVF=/cvmfs/fermilab.opensciencegrid.org
CVM=/cvmfs/minos.opensciencegrid.org/minos

echo "Check CVMFS mounting..."
ls $CVF/products/common/etc/setups.sh
ls $MINOS_SETUP_DIR/setup_minossoft_FNALU.sh

source $CVF/products/common/etc/setups.sh
export MINOS_SETUP_DIR=$CVM/minossoft/setup

SETUPMINOS=$MINOS_SETUP_DIR/setup_minossoft_FNALU.sh
echo source $SETUPMINOS -r R3.11
source $SETUPMINOS -r R3.11

cd $mypwd

#################  Setting up the test release for JOBs ###############

testrelname=newR3.11-08272020
reltarball=${PNFS}/tarballs/${testrelname}.tar

moved_rel=${mypwd}/${testrelname}.tar
# I need to tar my test release and inputfiles and place them in PNFS
echo  "copy release tarball $reltarball"
echo  "     to              $moved_rel"
ifdh cp    ${reltarball}    ${moved_rel}
echo "Now untar-ing testrel"
tar xvf ${testrelname}.tar
# go into the dir to perform srt_setup -a
cd newR3.11-minosNue-082020
srt_setup -a
cd $mypwd

#################  Copy needed input files for JOBs ###############

massValueDouble=$1
parlist=$2
quad=$3
export INPUT_DIR=${PNFS}/tarballs/
export RESULTS_DIR=$4

ifdh cp ${INPUT_DIR}/inputs_withMRCCSyst_WithPulls_newCovMat.tar                                             inputs.tar
cp newR3.11-minosNue-082020/JobScripts/DoContour2DSterileGridRP11RP12RP13DATA_LogScale.C                     DoContour2DSterileGridRP11RP12RP13DATA_LogScale.C

echo "Now untar-ing systematic files and needed root files."
tar xvf inputs.tar

cd $mypwd

#################  Running the main script for this JOB ###############

ProcNum=$((1+$PROCESS))
parval=`head -n+"${ProcNum}" newR3.11-minosNue-082020/JobScripts/PARAMLIST | tail -1`
parval="${massValueDouble}, ${parval}"
echo ${parval}

loon -bq $SRT_PRIVATE_CONTEXT/NueAna/macros/LoadLibs.C "DoContour2DSterileGridRP11RP12RP13DATA_LogScale.C($parval,$quad,0)"

ifdh cp -D *.root $RESULTS_DIR

ls




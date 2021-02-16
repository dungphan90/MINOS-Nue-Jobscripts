#! /bin/env bash

# Always cd to the scratch area
cd $_CONDOR_SCRATCH_DIR
echo " "
echo "MY CONDOR SCRATCH = ${_CONDOR_SCRATCH_DIR}"

# I like keeping track of this
mypwd=`pwd`


#################  Define variables common to all JOBs ###############

PNFS=/pnfs/minos/persistent/users/dphan/Nue2020/Common
CVF=/cvmfs/fermilab.opensciencegrid.org
CVM=/cvmfs/minos.opensciencegrid.org/minos

source $CVF/products/common/etc/setups.sh
export MINOS_SETUP_DIR=$CVM/minossoft/setup

SETUPMINOS=$MINOS_SETUP_DIR/setup_minossoft_FNALU.sh
echo source $SETUPMINOS -r R3.11
source $SETUPMINOS -r R3.11

cd $mypwd

#################  Setting up the test release for JOBs ###############

testrelname=newR3.11.Jan28_2020
reltarball=${PNFS}/tarballs/${testrelname}.tar

moved_rel=${mypwd}/${testrelname}.tar
# I need to tar my test release and inputfiles and place them in PNFS
echo  "copy release tarball $reltarball"
echo  "     to              $moved_rel"
ifdh cp    ${reltarball}    ${moved_rel}
echo "Now untar-ing testrel"
tar xvf ${testrelname}.tar
# go into the dir to perform srt_setup -a
cd newR3.11
srt_setup -a
#gmake
#gmake
cd $mypwd

#################  Copy needed input files for JOBs ###############

parlist=$1
quad=$2
ifdh cp ${parlist} parlist
ProcNum=$((1+$PROCESS))
parval=`head -n+"${ProcNum}" parlist | tail -1`


export INPUT_DIR=${PNFS}/tarballs/
export RESULTS_DIR=$3

ifdh cp ${INPUT_DIR}/inputs_withMRCCSyst_WithPulls_newCovMat.tar                             inputs.tar
ifdh cp ${INPUT_DIR}/DoContour2DSterileGridRP11RP12RP13DATA.C                                DoContour2DSterileGridRP11RP12RP13DATA.C

echo "Now untar-ing systematic files and needed root files."
tar xvf inputs.tar

cd $mypwd

#################  Running the main script for this JOB ###############

loon -bq $SRT_PRIVATE_CONTEXT/NueAna/macros/LoadLibs.C "DoContour2DSterileGridRP11RP12RP13DATA.C($parval,$quad,0)"

ifdh cp -D *.root $RESULTS_DIR

ls

ls -a

echo "Finished script"

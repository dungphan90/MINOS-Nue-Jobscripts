#!/usr/bin/bash

# Example of running:
# bash ./newRun.sh 0d006

commonFolder=/pnfs/minos/persistent/users/dphan/Nue2020/Common

massValue=$1
workingFolder=/pnfs/minos/persistent/users/dphan/Nue2020/DM${massValue}
massValueListFile=${commonFolder}/inputs/DM${massValue}LIST_RERUN
numberOfPoints=`cat ${massValueListFile} | wc -l`

cd ${commonFolder}/jobs/
jobOptions="--OS=SL6 -G minos -N ${numberOfPoints} --resource-provides=usage_model=DEDICATED,OPPORTUNISTIC,OFFSITE --site=FermiGrid,FNAL,Caltech,BNL,Michigan,BU,Clemson,Colorado,Cornell,Hyak_CE,MIT,Nebraska,NotreDame,Stampede,HOSTED_STANFORD,SU-ITS,TTU,UCSD,Wisconsin --role=Analysis --expected-lifetime=20h --memory=2GB --disk=2GB"

echo "jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 0 ${workingFolder}/results/"
jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 0 ${workingFolder}/results/
echo "jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 1 ${workingFolder}/results/"
jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 1 ${workingFolder}/results/
echo "jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 2 ${workingFolder}/results/"
jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 2 ${workingFolder}/results/
echo "jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 3 ${workingFolder}/results/"
jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA.sh ${massValueListFile} 3 ${workingFolder}/results/

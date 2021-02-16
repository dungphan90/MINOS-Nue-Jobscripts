#!/usr/bin/bash

# Example of running:
# bash ./newRun_LogScale.sh 0d006 0.006

commonFolder=/pnfs/minos/persistent/users/dphan/nue2020-08192020/Common

massValueStr=$1
massValueDouble=$2
workingFolder=/pnfs/minos/persistent/users/dphan/nue2020-08192020/DM${massValueStr}
massValueStrListFile=/minos/app/dphan/newR3.11-minosNue-082020/JobScripts/PARAMLIST
numberOfPoints=`cat ${massValueStrListFile} | wc -l`
mkdir -p ${workingFolder}/results

cd ${commonFolder}/jobs/
jobOptions="--OS=SL6 -G minos -N ${numberOfPoints} --resource-provides=usage_model=DEDICATED,OPPORTUNISTIC --role=Analysis --expected-lifetime=48h --memory=12GB --disk=4GB"

jobsub_submit ${jobOptions} file://${commonFolder}/jobs/2DJobsubDumpDATA_LogScale.sh ${massValueDouble} ${massValueStrListFile} 0 ${workingFolder}/results/


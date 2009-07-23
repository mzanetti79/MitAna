#!/bin/bash
# $Id: make_doc.sh,v 1.3 2009/07/17 10:47:04 loizides Exp $


XPATH="./MitAna//macros/doc"

cd $CMSSW_BASE/src
for i in MitCommon MitAna MitPhysics; do
    find ${i}/*/interface -iname "*.h" -exec $XPATH/addDesc.sh "{}" \;
done

cd $CMSSW_BASE/src/MitAna/macros/doc
root -n -b -q make_doc.C+

sstring=$CMSSW_BASE/src
for i in htmldoc/*.html; do
    sed -e "s#$sstring##g" < $i > ${i}.mod
    mv ${i}.mod $i
done

cd $CMSSW_BASE/src
for i in MitCommon MitAna MitPhysics; do
    find ${i}/*/interface -iname "*.h" -exec $XPATH/rmDesc.sh "{}" \;
done

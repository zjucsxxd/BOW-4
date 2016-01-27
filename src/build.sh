#!/usr/bin/env bash
#
#     Description:  TODO
#
#         Version:  1.0
#         Created:  2016-01-26
#        Modified:  2016-01-26
#        Revision:  none
#
#          Author:  Zheng Yuhong , 371582812@qq.com
#        HOMEPAGE:  zhengyh.com
cd $(dirname $0)/..
git fetch log master
git subtree pull --prefix=dep/log log master --squash
ROOT_DIR=$(pwd)

mkdir -p ${ROOT_DIR}/inc
mkdir -p ${ROOT_DIR}/lib

cd ${ROOT_DIR}/dep/log/src/
sh build.sh
cp -r ${ROOT_DIR}/dep/log/inc/* ${ROOT_DIR}/inc
cp -r ${ROOT_DIR}/dep/log/lib/* ${ROOT_DIR}/lib

cd ${ROOT_DIR}/src
make ar

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
git submodule update --init --recursive
ROOT_DIR=$(pwd)

mkdir -p ${ROOT_DIR}/inc
mkdir -p ${ROOT_DIR}/lib

cd ${ROOT_DIR}/3rd/log/src/
sh build.sh
cp -r ${ROOT_DIR}/3rd/log/inc/* ${ROOT_DIR}/inc
cp -r ${ROOT_DIR}/3rd/log/lib/* ${ROOT_DIR}/lib

cd ${ROOT_DIR}/src
make ar

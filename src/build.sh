#!/usr/bin/env bash
#
#     Description:  TODO
#
#         Version:  1.0
#         Created:  2016-01-30
#        Modified:  2016-01-30
#        Revision:  none
#
#          Author:  Zheng Yuhong , 371582812@qq.com
#        HOMEPAGE:  zhengyh.com

cd $(dirname $0)/..
ROOT_DIR=$(pwd)

#dep init

#git remote add -f log git@github.com:zhengyuhong/log.git
#git subtree add --prefix=dep/log log master
#git fetch log master
#git subtree pull --prefix=dep/log log master

#git remote add -f filestream git@github.com:zhengyuhong/filestream.git
#git subtree add --prefix=dep/filestream filestream master
#git fetch filestream master
#git subtree pull --prefix=dep/filestream filestream master

mkdir -p ${ROOT_DIR}/inc
mkdir -p ${ROOT_DIR}/lib

cd ${ROOT_DIR}/dep/log/src
sh build.sh
cp -r ${ROOT_DIR}/dep/log/inc/* ${ROOT_DIR}/inc
cp -r ${ROOT_DIR}/dep/log/lib/* ${ROOT_DIR}/lib

cd ${ROOT_DIR}/dep/filestream/src
sh build.sh
cp -r ${ROOT_DIR}/dep/filestream/inc/* ${ROOT_DIR}/inc
cp -r ${ROOT_DIR}/dep/filestream/lib/* ${ROOT_DIR}/lib

cd ${ROOT_DIR}/src
make ar


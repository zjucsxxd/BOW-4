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

cd $(dirname $0)/../..
ROOT_DIR=$(pwd)

cd ${ROOT_DIR}/src
sh build.sh

cd ${ROOT_DIR}/src/test
make clean && make

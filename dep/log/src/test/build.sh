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
cd $(dirname $0)/../..
ROOt_DIR=$(pwd)
cd ${ROOt_DIR}/src
sh build.sh
cd ${ROOt_DIR}/src/test
make clean && make

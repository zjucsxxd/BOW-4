#!/usr/bin/env bash
#
#     Description:  TODO
#
#         Version:  1.0
#         Created:  2015-12-08
#        Modified:  2015-12-08
#        Revision:  none
#
#          Author:  Zheng Yuhong , 371582812@qq.com
#        HOMEPAGE:  zhengyh.com
cd $(dirname $0)/..
ROOT_DIR=$(pwd)
cd ${ROOT_DIR}/src
make ar

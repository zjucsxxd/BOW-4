/*
 * =====================================================================================
 *
 *    Description:  TODO
 *
 *        Version:  1.0
 *        Created:  2016-01-30
 *       Modified:  2016-01-30
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Zheng Yuhong , 371582812@qq.com
 *       HOMEPAGE:  zhengyh.com
 *
 * =====================================================================================
 */

#include <bow/bow.h>

int main(int argc, char* argv[]) {
    BOW bow("./wordrank.txt");
    bow.compute();
    return 0;
}


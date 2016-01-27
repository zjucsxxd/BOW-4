/*
 * =====================================================================================
 *
 *    Description:  example for filestream
 *
 *        Version:  1.0
 *        Created:  2016-01-26
 *       Modified:  2016-01-27
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Zheng Yuhong , 371582812@qq.com
 *       HOMEPAGE:  zhengyh.com
 *
 * =====================================================================================
 */

#include <iostream>
#include <thread>


#include "../../inc/filestream/filestream.h"

int foo(FileStream* fsp) {
    FileStream& fs = *fsp;
    std::vector<std::string> doc;
    if (!fs.get_document(doc)) {
        for (const auto& v : doc) {
            std::cout << v << std::endl;
        }
        std::cout << "----------------" << std::endl;
    } else {
        std::cout << "fail\n";
    }
    return 0;
}

int main(int argc, char* argv[]) {
    FileStream fs("./document.txt");
    std::thread a(foo, &fs);
    std::thread b(foo, &fs);

    std::cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    // pauses until a finishes
    a.join();
    b.join();
    std::cout << "foo and bar completed" << std::endl;
    return 0;
}

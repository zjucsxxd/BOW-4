/*
 * =====================================================================================
 *
 *    Description:  a tiny library of C++11 for flexible logging to files
 *
 *        Version:  1.0
 *        Created:  2015-01-26
 *       Modified:  2016-01-26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Zheng Yuhong , 371582812@qq.com
 *       HOMEPAGE:  zhengyh.com
 *
 * =====================================================================================
 */

#include "log.h"
#include <set>


// <=====================================================================================

Logger Logger::s_logger;
Logger::Logger() {
}

Logger::~Logger() {
    // 关闭所有文件指针
    std::set<FILE*> s;

    for (auto& pr : m_fpmap) {
        s.insert(pr.second);
    }


    for (auto& fp : s) {
        if (fp) {
            fclose(fp);
        }
    }

}

FILE* Logger::set_fp_stream(LogLevel level, const std::string& path) {
    static std::map<std::string, FILE*> fpmap;

    if (fpmap.find(path) == fpmap.end()) {
        fpmap[path] = fopen(path.c_str(), "a+");
    }

    FILE* fp = fpmap[path];
    if (s_logger.m_fpmap.find(level) != s_logger.m_fpmap.end()) {
        //level对应的文件指针已设置，重复设置则出错
        return NULL;
    }

    s_logger.m_fpmap[level] = fp;
    return fp;
}

FILE* Logger::get_fp_stream(LogLevel level) {
    if (s_logger.m_fpmap.find(level) != s_logger.m_fpmap.end()) {
        return s_logger.m_fpmap[level];
    }

    return stderr;

}

std::mutex& Logger::get_fp_mutex() {
    return s_logger.m_mtx;
}
// =====================================================================================>

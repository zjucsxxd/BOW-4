/*
 * =====================================================================================
 *
 *    Description:  example for Logger
 *
 *        Version:  1.0
 *        Created:  2015-01-26
 *       Modified:  2016-01-27
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Zheng Yuhong , 371582812@qq.com
 *       HOMEPAGE:  zhengyh.com
 *
 * =====================================================================================
 */

#include <log/log.h>

int main(int argc, char* argv[]) {
    Logger::set_fp_stream(Logger::debug, "./debug.log");
    Logger::set_fp_stream(Logger::fatal, "./error.log");
    Logger::set_fp_stream(Logger::warning, "./error.log");
    Logger::set_fp_stream(Logger::notice, "./notice.log");
    DEBUG_LOG("debug log message");
    FATAL_LOG("fatal log message");
    WARNING_LOG("warning log message");
    NOTICE_LOG("notice log message");
    STDERR_LOG("stderr log message");
    STDOUT_LOG("stdout log message");
    return 0;
}


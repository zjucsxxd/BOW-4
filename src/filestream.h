/*
 * =====================================================================================
 *
 *    Description:  TODO
 *
 *        Version:  1.0
 *        Created:  2016-01-26
 *       Modified:  2016-01-27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zheng Yuhong , 371582812@qq.com
 *       HOMEPAGE:  zhengyh.com
 *
 * =====================================================================================
 */

#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <mutex>
#include <future>


// <=====================================================================================
// BLOCK class FileStram;
class FileStream {
private:
    // 统一轻量级参数，用于调用私有成员函数的轻量级参数
    typedef std::vector<std::string> Document;
    typedef struct Parameter {
    public:
        Document* document;
        Parameter() {
            document = nullptr;
        }
    } Parameter;

private:
    // private member variable
    std::ifstream m_fin;
    std::mutex m_mtx;
    std::future<int> m_fut;
    Document m_document;

private:
    // private member function
    int stream2memory();

public:
    FileStream(const std::string& path);

    ~FileStream();

    int reset(const std::string& path);

    int get_document(std::vector<std::string>& document);


};//class FileStram
// =====================================================================================>

#endif//FILESTREAM_H

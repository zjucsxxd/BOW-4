/*
 * =====================================================================================
 *
 *    Description:  TODO
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

#include "filestream.h"
#include <log/log.h>

int FileStream::stream2memory() {
    DEBUG_LOG("FileStream::stream2memory");
    std::unique_lock<std::mutex> lck(m_mtx);
    Document& document = m_document;
    document.clear();
    std::ifstream& fin = m_fin;

    if (fin.eof()) {
        return 0;
    }

    std::string line;
    std::stringstream ss;;

    // <=====================================================================================
    // read line number
    uint32_t n;
    if (fin.good()) {
        if (getline(fin, line)) {
            ss.str(line);
            if (!(ss >> n)) {
                STDERR_LOG("std::stringstream >> failed");
                return -1;
            }
        } else {
            STDERR_LOG("getline failed");
            STDERR_LOG("eof%d", fin.eof());
            STDERR_LOG("fail%d", fin.fail());
            return -1;
        }
    } else {
        STDERR_LOG("std::ifstream state fail");
        return -1;
    }
    // =====================================================================================>


    // read line
    for (;;) {
        if (!n) {
            break;
        }
        if (getline(fin, line)) {
            if (line.size()) {
                document.push_back(line);
            }
            --n;
        } else {
            STDERR_LOG("getline failed");
            return -1;
        }
    }
    return 0;
}

FileStream::FileStream(const std::string& path) {
    m_fin.open(path.c_str());
}

FileStream::~FileStream() {
    m_fin.close();
}

int FileStream::reset(const std::string& path) {
    m_fin.close();
    m_fin.open(path.c_str());
    return 0;
}

int FileStream::get_document(std::vector<std::string>& document) {
    document.clear();
    Parameter parameter;
    parameter.document = &document;
    if (!m_document.size()) {
        if (stream2memory()) {
            STDERR_LOG("stream2memory failed");
            return -1;
        }
    } else {
        if (m_fut.get()) {
            STDERR_LOG("stream2memory failed");
            return -1;
        }
    }
    parameter.document->swap(m_document);
    m_fut = std::async([this]() {
        return stream2memory();
    });
    return 0;
}



/*
 * =====================================================================================
 *
 *    Description:  TODO
 *
 *        Version:  1.0
 *        Created:  2016-01-26
 *       Modified:  2016-01-29
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

int FileStream::stream2memory(Parameter& parameter) {
    auto& mtx = m_mtx;
    Document& document = m_document;
    auto& document_id = m_document_id;
    std::ifstream& fin = m_fin;

    std::unique_lock<std::mutex> lck(mtx);
    document.clear();

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
                STDERR_LOG("good[%d]", fin.good());
                STDERR_LOG("eof[%d]", fin.eof());
                STDERR_LOG("fail[%d]", fin.fail());
                STDERR_LOG("bad[%d]", fin.bad());
                return -1;
            }
            if (parameter.document_id) {
                if (!(ss >> document_id)) {
                    STDERR_LOG("std::stringstream >> failed");
                    STDERR_LOG("good[%d]", fin.good());
                    STDERR_LOG("eof[%d]", fin.eof());
                    STDERR_LOG("fail[%d]", fin.fail());
                    STDERR_LOG("bad[%d]", fin.bad());
                    return -1;
                }
            }
        } else {
            STDERR_LOG("getline failed");
            STDERR_LOG("good[%d]", fin.good());
            STDERR_LOG("eof[%d]", fin.eof());
            STDERR_LOG("fail[%d]", fin.fail());
            STDERR_LOG("bad[%d]", fin.bad());
            return -1;
        }
    } else {
        STDERR_LOG("std::ifstream state fail");
        STDERR_LOG("good[%d]", fin.good());
        STDERR_LOG("eof[%d]", fin.eof());
        STDERR_LOG("fail[%d]", fin.fail());
        STDERR_LOG("bad[%d]", fin.bad());
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

int FileStream::get_document(std::vector<std::string>& doc) {
    auto& fut = m_fut;
    auto& document = m_document;

    Parameter parameter;
    doc.clear();
    parameter.document = &doc;
    if (!document.size()) {
        if (stream2memory(parameter)) {
            STDERR_LOG("stream2memory failed");
            return -1;
        }
    } else {
        if (fut.get()) {
            STDERR_LOG("stream2memory failed");
            return -1;
        }
    }
    parameter.document->swap(document);
    fut = std::async([this, &parameter]() {
        return stream2memory(parameter);
    });
    return 0;
}

int FileStream::get_document(std::vector<std::string>& doc, std::string& doc_id) {
    auto& fut = m_fut;
    auto& document = m_document;
    auto& document_id = m_document_id;

    doc.clear();
    doc_id.clear();
    Parameter parameter;
    parameter.document_id = &doc_id;
    if (!document.size()) {
        if (stream2memory(parameter)) {
            STDERR_LOG("stream2memory failed");
            return -1;
        }
    } else {
        if (fut.get()) {
            STDERR_LOG("stream2memory failed");
            return -1;
        }
    }

    doc.swap(document);
    doc_id.swap(document_id);
    fut = std::async([this, &parameter]() {
        return stream2memory(parameter);
    });
    return 0;
}



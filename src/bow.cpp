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

#include "bow.h"

#include <log/log.h>


BOW::BOW(const std::string& path, const std::string& output_dir) : m_fs(path) {
    m_output_dir = output_dir;
}

int BOW::get_document(Parameter& parameter) {
    auto& fs = m_fs;

    if (!parameter.document) {
        STDERR_LOG("!parameter.document[%d]", !parameter.document);
        return -1;
    }

    Document& document = *parameter.document;
    document.clear();

    std::vector<std::string> vec;
    if (fs.get_document(vec)) {
        STDERR_LOG("FileStream::get_document failed");
        return -1;
    }

    std::stringstream ss;
    for (const auto& line : vec) {
        ss.clear();
        ss.str(line);
        std::vector<std::string> words;
        std::string wr;
        for (;;) {
            if (ss >> wr) {
                std::size_t sep = wr.find(':');
                std::string w = wr.substr(0, sep);
                words.push_back(w);
            } else {
                if (ss.eof()) {
                    break;
                }
                STDERR_LOG("std::stringstream >> failed");
                return -1;
            }
        }
        document.push_back(std::move(words));
    }

    return 0;
}

int BOW::compute() {
    NOTICE_LOG("BOW::compute start");
    if (output()) {
        STDERR_LOG("BOW::output failed");
        return -1;
    }
    NOTICE_LOG("BOW::compute finish");
    return 0;
}


int BOW::output() {
    NOTICE_LOG("BOW::output start");
    const auto& output_dir = m_output_dir;

    std::string path = output_dir + "/bow.txt";
    std::ofstream fout(path.c_str(), std::ofstream::out);
    for (;;) {
        Parameter parameter;
        Document document;
        parameter.document = &document;
        if (get_document(parameter)) {
            STDERR_LOG("BOW::get_document failed");
            return -1;
        }

        if (!document.size()) {
            break;
        }

        std::map<std::string, uint32_t> wc;
        for (const auto& words : document) {
            for (const auto& w : words) {
                wc[w] += 1;
            }
        }

        for (auto& pr : wc) {
            const auto& w = pr.first;
            const auto& weight = pr.second;
            fout << w << ':' << weight << ' ';
        }
        fout << std::endl;

    }
    fout.close();
    NOTICE_LOG("BOW::output finish");
    return 0;
}


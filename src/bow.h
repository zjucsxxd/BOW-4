/*
 * =====================================================================================
 *
 *    Description:  TODO
 *
 *        Version:  1.0
 *        Created:  2016-01-30
 *       Modified:  2016-01-30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zheng Yuhong , 371582812@qq.com
 *       HOMEPAGE:  zhengyh.com
 *
 * =====================================================================================
 */

#ifndef BOW_H
#define BOW_H

#include <filestream/filestream.h>
#include <stdint.h>
#include <vector>
#include <string>



// <=====================================================================================
// BLOCK class BOW;
class BOW {
private:
    // 统一轻量级参数，用于调用私有成员函数的轻量级参数
    typedef std::vector< std::vector<std::string> > Document;
    typedef struct Parameter {
    public:
        Document* document;
        Parameter() {
            document = nullptr;
        }
    } Parameter;

private:
    // private member variable
    FileStream m_fs;
    std::string m_output_dir;

private:
    // private member function
    int get_document(Parameter& parameter);
    // 输出数据
    int output();

public:
    BOW(const std::string& path, const std::string& output_dir = "./");

    // 计算
    int compute();


};//class BOW
// =====================================================================================>

#endif

#ifndef GLOBAL_H
#define GLOBAL_H
#include "Head.h"
#include "Element.h"
#include "UCL.h"
using std::wstring;

extern UCL *ucl;
extern TotalHead *totalHead;
extern SetHead *CDPSHead;
extern SetHead *CGPSHead;
extern vector<Element> CDPSSet;
extern vector<Element> CGPSSet;
extern string wstring_to_string(const wstring& wStr);
extern wstring string_to_wstring(const string& str);
extern string convert(string binStr);				//UTF8二进制序列转换为十六进制的Unicode码
extern CString text_change(CString content);       //将属性净荷转化为文本
extern bool element_exist(vector<Element> &ElementSet, 
						int elementNum, int &index); //判断属性集合 ElementSet 中是否有类别号为 elementNum的属性存在，并将索引保存在index中
#endif
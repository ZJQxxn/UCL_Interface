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
extern string convert(string binStr);				//UTF8����������ת��Ϊʮ�����Ƶ�Unicode��
extern CString text_change(CString content);       //�����Ծ���ת��Ϊ�ı�
extern bool element_exist(vector<Element> &ElementSet, 
						int elementNum, int &index); //�ж����Լ��� ElementSet ���Ƿ�������Ϊ elementNum�����Դ��ڣ���������������index��
#endif
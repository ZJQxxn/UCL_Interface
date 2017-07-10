//Declare sonme functions for explaining UCL Code
#ifndef CODE_EXP_H
#define CODE_EXP_H
#include <string>
#include <vector>
using std::string;
using std::vector;

long string_to_number(const string& s);		//将二进制字符串转换为整数
string explainVersion(vector<string>&);		//分析 版本
string explainTM(vector<string>&);			//分析 媒体类型
string explainPP(vector<string>&);			//分析 优先级与策略
string explainFlag(vector<string>&);		//分析 标志
string explainParseRule(vector<string>&);	//分析 解析规则
string explainSC(vector<string>&);			//分析 内容来源
string explainCategory(vector<string>&);	//分析 一级类别
string explainSubcategory(vector<string>&);	//分析 二级类别
string explainTopic(vector<string>&);		//分析 话题
string explainCT(vector<string>&);			//分析 内容版权与类型 
string explainSELC(vector<string>&);		//分析 安全能级码
string explainLanguage(vector<string>&);	//分析 语种
string explainSoC(vector<string>&);			//分析 内容长度
string explainTimestamp(vector<string>&);	//分析 时间戳
string explainSN(vector<string>&,int&);		//分析 顺序号
string explainMB(vector<string>&);			//分析 复用字节端
string explainCC(vector<string>&);			//分析 代码校验
#endif
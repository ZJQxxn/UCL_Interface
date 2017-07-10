//Declare sonme functions for explaining UCL Code
#ifndef CODE_EXP_H
#define CODE_EXP_H
#include <string>
#include <vector>
using std::string;
using std::vector;

long string_to_number(const string& s);		//���������ַ���ת��Ϊ����
string explainVersion(vector<string>&);		//���� �汾
string explainTM(vector<string>&);			//���� ý������
string explainPP(vector<string>&);			//���� ���ȼ������
string explainFlag(vector<string>&);		//���� ��־
string explainParseRule(vector<string>&);	//���� ��������
string explainSC(vector<string>&);			//���� ������Դ
string explainCategory(vector<string>&);	//���� һ�����
string explainSubcategory(vector<string>&);	//���� �������
string explainTopic(vector<string>&);		//���� ����
string explainCT(vector<string>&);			//���� ���ݰ�Ȩ������ 
string explainSELC(vector<string>&);		//���� ��ȫ�ܼ���
string explainLanguage(vector<string>&);	//���� ����
string explainSoC(vector<string>&);			//���� ���ݳ���
string explainTimestamp(vector<string>&);	//���� ʱ���
string explainSN(vector<string>&,int&);		//���� ˳���
string explainMB(vector<string>&);			//���� �����ֽڶ�
string explainCC(vector<string>&);			//���� ����У��
#endif
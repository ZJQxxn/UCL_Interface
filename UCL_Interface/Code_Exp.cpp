#include "stdafx.h"
#include "Code_Exp.h"
using std::to_string;

long string_to_number(const string& str)
{
	int flag = 1;
	char base = '0';
	int result = 0;
	for (int index = (str.length() - 1); index >= 0; --index)
	{
		result += (str[index] - base)*flag;
		flag *= 2;
	}
	return result;
}
//6.1.1
string explainVersion(string &str)
{
	string result = "Not Defined";
	string version = str.substr((1 * 8 - 3), 3);
//	cout << version << endl;
	if (version == "001")
	{
		return "UCL v1";
	}
	else if (version == "010")
	{
		return "UCL v2";
	}
	else if (version == "011")
	{
		return "UCL v3";
	}
	return result;
}

//6.1.2
string explainToM(string &str)
{
	string result = "Not Defined";
	string ToM = str.substr((1 * 8 - 8), 5);
	if (ToM == "10001")
	{
		return "������";
	}
	else if (ToM == "10010")
	{
		return "�㲥";
	}
	else if (ToM == "10011")
	{
		return "����";
	}
	else if (ToM == "10100")
	{
		return "��ֽ";
	}
	else if (ToM == "10101")
	{
		return "��־";
	}
	else if (ToM == "10110")
	{
		return "�鼮";
	}
	else if (ToM == "10111")
	{
		return "���";
	}
	else if (ToM == "11000")
	{
		return "Ӧ�ó���";
	}
	else if (ToM == "11111")
	{
		return "����";
	}
	return result;
}

//6.1.3
string explainPrecedence(string &str)
{
	string result = "Not Defined";
	string precedence = str.substr((2 * 8 - 4), (3 - 0 + 1));
	if (precedence == "1000")
	{
		return "�ؼ���extra urgent��";
	}
	else if (precedence == "1001")
	{
		return "������urgent��";
	}
	else if (precedence == "1010")
	{
		return "����immediate��";
	}
	else if (precedence == "1011")
	{
		return "���棨routine��";
	}
	else if (precedence == "1100")
	{
		return "���ڣ�periodic��";
	}
	else if (precedence == "1101")
	{
		return "��ʱ��fixed time��";
	}
	return result;
}

//6.1.4
string explainFlag(string &str)
{
	string result = "Not Defined";
	string flag = str.substr((2 * 8 - 8), (7 - 4 + 1));
	if (flag[3] == '0')
	{
		result = "UCL���벻������չ";
	}
	else if (flag[3] == '1')
	{
		result = "UCL���������չ";
	}
	if (flag[2] == '0')
	{
		result += "\n����������ݱ˴˷���";
	}
	else if (flag[2] == '1')
	{
		result += "\n�����Ѱ����ڰ���";
	}
	if (flag[1] == '0')
	{
		result += "\n���Բ���û�й���UCL��";
	}
	else if (flag[1] == '1')
	{
		result += "\n���Բ����й���UCL��";
	}
	return result;
}

//6.1.5
string explainParseRule(string &str)
{
	string parseRule1 = str.substr((3 * 8 - 2), 2) + str.substr((4 * 8 - 4), 4);
	string parseRule2 = str.substr((2 * 8 + 0), 6);
	long a1 = string_to_number(parseRule1);
	long a2 = string_to_number(parseRule2);
	string result = "һ�������׼��� :" + to_string(a1) + "\n���������� :" + to_string(a2);
	return result;
}

//6.1.6
string explainSoC(string &str)
{
	string result;
	string SoC1 = str.substr((3 * 8 -4), 4);
	string SoC2 = str.substr((4 * 8 + 0), 24);//
	if (SoC1.substr(1, 3) == "010")
	{
		result = "������Դ��ӦΪ��ַ��������ʽ\n";
	}
	else if (SoC1.substr(1, 3) == "001")
	{
		result = "������Դ��ӦΪ��������ʽ\n";
	}
	else if (SoC1.substr(1, 3) == "011")
	{
		result = "������Դ��ӦΪӦ����ص���ʽ\n";
	}
	result = result + "\n������Դ ��" + to_string(string_to_number(SoC2));
	return result;
}

//6.1.7
string explainCategory(string &str)
{
	string category = str.substr((7 * 8 + 0), 8);
	string result = "һ��������� :" + to_string(string_to_number(category));
	return result;
}

//6.1.8
string explainSubcategory(string &str)
{
	string subcategory = str.substr((8 * 8 + 0), 8);
	string result = "����������� :" + to_string(string_to_number(subcategory));
	return result;
}

//6.1.9
string explainTopic(string &str)
{
	string result = "Not Defined";
	string topic1 = str.substr((9 * 8 + 28), 4);
	string topic2 = str.substr((9 * 8 + 0), 28);
	if (topic1[3] == '0')
	{
		result = "�������⣨���ڻ��⣩  ";
	}
	else if (topic1[3] == '1')
	{
		result = "�ǹ������⣨С�ڻ��⣩";
	}
	return result;
}

//6.1.10
string explainToC(string &str)
{
	string result = "Not Defined";
	string ToC = str.substr((13 * 8 + 0), 8);
	if (ToC.substr(4, 3) == "001")
	{
		result = "������ģ�";
	}
	else if (ToC.substr(4, 3) == "010")
	{
		result = "Ӣ�Ӣ�ģ�";
	}
	else if (ToC.substr(4, 3) == "011")
	{
		result = "������ģ�";
	}
	else if (ToC.substr(4, 3) == "100")
	{
		result = "������ģ�";
	}
	else if (ToC.substr(4, 3) == "101")
	{
		result = "��������������ģ�";
	}
	else if (ToC.substr(4, 3) == "110")
	{
		result = "��������������ģ�";
	}
	else if (ToC.substr(4, 3) == "111")
	{
		result = "��������";
	}
	result = "���ݶ������� ��" + result + "\n���ݶ������� ��";
	if (ToC.substr(0, 4) == "0001")
	{
		result += "�ı�";
	}
	else if (ToC.substr(0, 4) == "0010")
	{
		result += "ͼ��";
	}
	else if (ToC.substr(0, 4) == "0011")
	{
		result += "��Ƶ";
	}
	else if (ToC.substr(0, 4) == "0100")
	{
		result += "��Ƶ";
	}
	else if (ToC.substr(0, 4) == "0101")
	{
		result += "����Ϣ";
	}
	else if (ToC.substr(0, 4) == "0110")
	{
		result += "Ӧ�ó���";
	}
	else if (ToC.substr(0, 4) == "0111")
	{
		result += "��������";
	}
	else
	{
		result += "Not Defined";
	}
	return result;
}

//6.1.11
string explainCAL(string &str)
{
	string result = "Not Defined";
	string CAL = str.substr((14 * 8 + 0), 8);
	if (CAL[7] == '0')
	{
		result = "UCL�����������ݶ���İ�Ȩ��Ϣ";
	}
	else if (CAL[7] == '1')
	{
		result = "UCL���������ݶ���İ�Ȩ��Ϣ";
	}
	if (CAL[6] == '0')
	{
		result += "\nUCL������ʶ�����ݶ���Ϊԭ��������";
	}
	else if (CAL[6] == '1')
	{
		result += "\nUCL������ʶ�����ݶ���Ϊת������";
	}
	if (CAL.substr(2, 3) == "000")
	{
		result += "\n���� :[1, 4)";
	}
	else if (CAL.substr(2, 3) == "001")
	{
		result += "\n���� :[4, 16)";
	}
	else if (CAL.substr(2, 3) == "010")
	{
		result += "\n���� :[16, 64)";
	}
	else if (CAL.substr(2, 3) == "011")
	{
		result += "\n���� :[64, 128)";
	}
	else if (CAL.substr(2, 3) == "100")
	{
		result += "\n���� :[128, 256)";
	}
	else if (CAL.substr(2, 3) == "101")
	{
		result += "\n���� :[256, 512)";
	}
	else if (CAL.substr(2, 3) == "110")
	{
		result += "\n���� :[512, 768)";
	}
	else if (CAL.substr(2, 3) == "111")
	{
		result += "\n���� :[768, 1024)";
	}
	if (CAL.substr(0, 2) == "00")
	{
		result += "B";
	}
	else if (CAL.substr(0, 2) == "01")
	{
		result += "KB";
	}
	else if (CAL.substr(0, 2) == "10")
	{
		result += "MB";
	}
	else if (CAL.substr(0, 2) == "11")
	{
		result += "GB";
	}
	return result;
}

//6.1.12
string explainSELC(string &str)
{
	string result = "Not Defined";
	string SELC = str.substr((15 * 8 + 0), 8);
	if (SELC.substr(6, 2) == "00")
	{
		result = "���б궨";
	}
	else if (SELC.substr(6, 2) == "01")
	{
		result = "�ѹ������ṩ����֤";
	}
	else if (SELC.substr(6, 2) == "01")
	{
		result = "�ѹ�Ȩ������������֤";
	}
	result = "��֤�ȼ� ��" + result;
	result = result + "\n�������簲ȫ���ܼ� ��" + to_string(string_to_number(SELC.substr(3, 3)));
	result = result + "\n�������ݰ�ȫ���ܼ� ��" + to_string(string_to_number(SELC.substr(0, 3)));
	return result;
}

//6.1.13
string explainTS(string &str)
{
	string result;
	string TS1 = str.substr((16 * 8 + 10), 30) + str.substr((22 * 8 - 2), 2);
	string TS2 = str.substr((16 * 8 + 0), 10);
	result = "UCL������ʱ�� ��" + TS1 + "\nʱ�����ֵ ��" + TS2;
	return result;
}

//6.1.14
string explainSN(string &str)
{
	string result = "Not Defined";
	string SN1 = str.substr((22 * 8 + 14), 2);
	string SN2 = str.substr((21 * 8 + 0), 6) + str.substr((22 * 8 + 0), 14);
	if (SN1[0] == '0')
	{
		result = "�����ø�˳�����/0x21";
	}
	else if(SN1[0] == '1')
	{
		result = "��˳�����������";
		if (SN1[1] == '0')
		{
			result += " �ڶ������Ƕ�ʱ�����Ĳ���";
		}
		else if (SN1[1] == '1')
		{
			result += " �ڶ�����Ϊ˳���";
		}
	}
	result = result + "\n�ڶ����� ��" + SN2;
	return result;
}

//6.1.15
string explainRB(string &str)
{
	string result = "Not Defined";
	string RB = str.substr((24 * 8 + 0), 48);
	if (RB.substr(46, 2) == "00")
	{
		result = "δ������";
	}
	else if (RB.substr(46, 2) == "01")
	{
		result = "��Ӧ�ó����Զ��巽ʽ����";
	}
	else if (RB.substr(46, 2) == "11")
	{
		result = "�ѱ������޶���UCL��׼������";
	}
	return result;
}

//6.1.16
string explainCC(string &str)
{
	string CC = str.substr((30 * 8 + 0), 16);
	string result = "CRCУ��� :"+ CC;
	return result;
}

//6.1.17
string explainCE(string &str)
{
	string result = "Not Defined";
	string flag = str.substr((2 * 8 - 8), (7 - 4 + 1));
	if (flag[3] == '1')
	{
		result = "��չ���ֳ���Ϊ" + to_string(string_to_number(flag.substr(1, 3))) + "�ֽ�";
	}
	return result;
}


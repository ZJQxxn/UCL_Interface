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
		return "互联网";
	}
	else if (ToM == "10010")
	{
		return "广播";
	}
	else if (ToM == "10011")
	{
		return "电视";
	}
	else if (ToM == "10100")
	{
		return "报纸";
	}
	else if (ToM == "10101")
	{
		return "杂志";
	}
	else if (ToM == "10110")
	{
		return "书籍";
	}
	else if (ToM == "10111")
	{
		return "广告";
	}
	else if (ToM == "11000")
	{
		return "应用程序";
	}
	else if (ToM == "11111")
	{
		return "其他";
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
		return "特急（extra urgent）";
	}
	else if (precedence == "1001")
	{
		return "紧急（urgent）";
	}
	else if (precedence == "1010")
	{
		return "急（immediate）";
	}
	else if (precedence == "1011")
	{
		return "常规（routine）";
	}
	else if (precedence == "1100")
	{
		return "周期（periodic）";
	}
	else if (precedence == "1101")
	{
		return "定时（fixed time）";
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
		result = "UCL代码不进行扩展";
	}
	else if (flag[3] == '1')
	{
		result = "UCL代码进行扩展";
	}
	if (flag[2] == '0')
	{
		result += "\n包与对象内容彼此分离";
	}
	else if (flag[2] == '1')
	{
		result += "\n对象已包含在包内";
	}
	if (flag[1] == '0')
	{
		result += "\n属性部分没有关联UCL域";
	}
	else if (flag[1] == '1')
	{
		result += "\n属性部分有关联UCL域";
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
	string result = "一级解码标准编号 :" + to_string(a1) + "\n二级解码编号 :" + to_string(a2);
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
		result = "内容来源对应为网址或域名形式\n";
	}
	else if (SoC1.substr(1, 3) == "001")
	{
		result = "内容来源对应为机构名形式\n";
	}
	else if (SoC1.substr(1, 3) == "011")
	{
		result = "内容来源对应为应用相关的形式\n";
	}
	result = result + "\n内容来源 ：" + to_string(string_to_number(SoC2));
	return result;
}

//6.1.7
string explainCategory(string &str)
{
	string category = str.substr((7 * 8 + 0), 8);
	string result = "一级分类类别 :" + to_string(string_to_number(category));
	return result;
}

//6.1.8
string explainSubcategory(string &str)
{
	string subcategory = str.substr((8 * 8 + 0), 8);
	string result = "二级分类类别 :" + to_string(string_to_number(subcategory));
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
		result = "公共话题（大众话题）  ";
	}
	else if (topic1[3] == '1')
	{
		result = "非公共话题（小众话题）";
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
		result = "汉语（中文）";
	}
	else if (ToC.substr(4, 3) == "010")
	{
		result = "英语（英文）";
	}
	else if (ToC.substr(4, 3) == "011")
	{
		result = "法语（法文）";
	}
	else if (ToC.substr(4, 3) == "100")
	{
		result = "俄语（俄文）";
	}
	else if (ToC.substr(4, 3) == "101")
	{
		result = "阿拉伯语（阿拉伯文）";
	}
	else if (ToC.substr(4, 3) == "110")
	{
		result = "西班牙语（西班牙文）";
	}
	else if (ToC.substr(4, 3) == "111")
	{
		result = "其他语种";
	}
	result = "内容对象语言 ：" + result + "\n内容对象类型 ：";
	if (ToC.substr(0, 4) == "0001")
	{
		result += "文本";
	}
	else if (ToC.substr(0, 4) == "0010")
	{
		result += "图像";
	}
	else if (ToC.substr(0, 4) == "0011")
	{
		result += "音频";
	}
	else if (ToC.substr(0, 4) == "0100")
	{
		result += "视频";
	}
	else if (ToC.substr(0, 4) == "0101")
	{
		result += "短信息";
	}
	else if (ToC.substr(0, 4) == "0110")
	{
		result += "应用程序";
	}
	else if (ToC.substr(0, 4) == "0111")
	{
		result += "复合类型";
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
		result = "UCL包不包含内容对象的版权信息";
	}
	else if (CAL[7] == '1')
	{
		result = "UCL包包含内容对象的版权信息";
	}
	if (CAL[6] == '0')
	{
		result += "\nUCL包所标识的内容对象为原创性内容";
	}
	else if (CAL[6] == '1')
	{
		result += "\nUCL包所标识的内容对象为转载内容";
	}
	if (CAL.substr(2, 3) == "000")
	{
		result += "\n区间 :[1, 4)";
	}
	else if (CAL.substr(2, 3) == "001")
	{
		result += "\n区间 :[4, 16)";
	}
	else if (CAL.substr(2, 3) == "010")
	{
		result += "\n区间 :[16, 64)";
	}
	else if (CAL.substr(2, 3) == "011")
	{
		result += "\n区间 :[64, 128)";
	}
	else if (CAL.substr(2, 3) == "100")
	{
		result += "\n区间 :[128, 256)";
	}
	else if (CAL.substr(2, 3) == "101")
	{
		result += "\n区间 :[256, 512)";
	}
	else if (CAL.substr(2, 3) == "110")
	{
		result += "\n区间 :[512, 768)";
	}
	else if (CAL.substr(2, 3) == "111")
	{
		result += "\n区间 :[768, 1024)";
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
		result = "自行标定";
	}
	else if (SELC.substr(6, 2) == "01")
	{
		result = "已过内容提供商认证";
	}
	else if (SELC.substr(6, 2) == "01")
	{
		result = "已过权威内容中心认证";
	}
	result = "认证等级 ：" + result;
	result = result + "\n关于网络安全的能级 ：" + to_string(string_to_number(SELC.substr(3, 3)));
	result = result + "\n关于内容安全的能级 ：" + to_string(string_to_number(SELC.substr(0, 3)));
	return result;
}

//6.1.13
string explainTS(string &str)
{
	string result;
	string TS1 = str.substr((16 * 8 + 10), 30) + str.substr((22 * 8 - 2), 2);
	string TS2 = str.substr((16 * 8 + 0), 10);
	result = "UCL包生成时刻 ：" + TS1 + "\n时间戳数值 ：" + TS2;
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
		result = "不启用该顺序号域/0x21";
	}
	else if(SN1[0] == '1')
	{
		result = "该顺序号域已启用";
		if (SN1[1] == '0')
		{
			result += " 第二部分是对时间戳域的补充";
		}
		else if (SN1[1] == '1')
		{
			result += " 第二部分为顺序号";
		}
	}
	result = result + "\n第二部分 ：" + SN2;
	return result;
}

//6.1.15
string explainRB(string &str)
{
	string result = "Not Defined";
	string RB = str.substr((24 * 8 + 0), 48);
	if (RB.substr(46, 2) == "00")
	{
		result = "未被启用";
	}
	else if (RB.substr(46, 2) == "01")
	{
		result = "以应用程序自定义方式启用";
	}
	else if (RB.substr(46, 2) == "11")
	{
		result = "已被后续修订的UCL标准所启用";
	}
	return result;
}

//6.1.16
string explainCC(string &str)
{
	string CC = str.substr((30 * 8 + 0), 16);
	string result = "CRC校验和 :"+ CC;
	return result;
}

//6.1.17
string explainCE(string &str)
{
	string result = "Not Defined";
	string flag = str.substr((2 * 8 - 8), (7 - 4 + 1));
	if (flag[3] == '1')
	{
		result = "扩展部分长度为" + to_string(string_to_number(flag.substr(1, 3))) + "字节";
	}
	return result;
}


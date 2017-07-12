#include "stdafx.h"
#include "Code_Exp.h"
#include "global.h"
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

string explainVersion(vector<string>& code)
{
	string result = "未定义";
	string version = code[0].substr(5,3);
	if (version == "001")
	{
		result= "UCL v1";
	}
	else if (version == "010")
	{
		result= "UCL v2";
	}
	else if (version == "011")
	{
		result= "UCL v3";
	}
	return result;
}

string explainTM(vector<string>& code)
{
	string result = "未定义";
	string TM = code[0].substr(0,5);
	if (TM == "01000")
	{
		result= "新闻与信息门户";
	}
	else if (TM == "01001")
	{
		result= "搜索引擎";
	}
	else if (TM == "01010")
	{
		result= "内容与资讯服务";
	}
	else if (TM == "01011")
	{
		result= "商业应用";
	}
	else if (TM == "01100")
	{
		result= "论坛与社区";
	}
	else if (TM == "01101")
	{
		result= "社交媒体与自媒体";
	}
	else if (TM == "01110")
	{
		result= "评论与舆情";
	}
	else if (TM == "01111")
	{
		result= "娱乐与游戏";
	}
	else if (TM == "10000")
	{
		result= "双结构网络应用";
	}
	else if (TM == "10101")
	{
		result = "网络图片与视听";
	}
	else if (TM == "10110")
	{
		result = "数字报刊与图书";
	}
	else if (TM == "10111")
	{
		result = "其他网络应用";
	}
	else if (TM == "11000")
	{
		result = "电视（第三媒体）";
	}
	else if (TM == "11001")
	{
		result = "广播（第二媒体）";
	}
	else if (TM == "11010")
	{
		result = "报刊（第一媒体）";
	}
	else if (TM == "11011")
	{
		result = "图书";
	}
	else if (TM == "11100")
	{
		result = "音像制品";
	}
	return result;
}

string explainPP(vector<string>& code)
{
	string result;
	string PP = code[1];
	//第一部分
	result = "优先级 ：" + to_string(string_to_number(PP.substr(5, 3))) + '\n';
	//第二部分
	if (PP.substr(4,1) == "0")
	{
		result += "高优先级非抢占式策略\n";
	}
	else if (PP.substr(4, 1) == "1")
	{
		result += "高优先级抢占式策略\n";
	}
	if (PP.substr(3, 1) == "0")
	{
		result += "即时分发\n";
	}
	else if (PP.substr(3, 1) == "1")
	{
		result += "定时分发\n";
	}
	//第三部分
	if (PP.substr(0,3) == "000")
	{
		result += "非循环分发\n";
	}
	else if (PP.substr(0,3) == "001")
	{
		result += "1小时内循环分发\n";
	}
	else if (PP.substr(0, 3) == "010")
	{
		result += "2小时内循环分发\n";
	}
	else if (PP.substr(0, 3) == "011")
	{
		result += "4小时内循环分发\n";
	}
	else if (PP.substr(0, 3) == "100")
	{
		result += "8小时内循环分发\n";
	}
	else if (PP.substr(0, 3) == "101")
	{
		result += "12小时内循环分发\n";
	}
	else if (PP.substr(0, 3) == "110")
	{
		result += "24小时内循环分发\n";
	}
	else if (PP.substr(0, 3) == "111")
	{
		result += "48小时内循环分发\n";
	}
	return result;
}

string explainFlag(vector<string>& code)
{
	string result;
	string flag = code[2];
	//第一部分
	if (flag.substr(7,1) == "0")
	{
		result += "UCL代码不进行扩展\n";
	}
	else if (flag.substr(7, 1) == "1")
	{
		result += "UCL代码进行扩展\n";
	}
	if (flag.substr(6,1) == "0")
	{
		result += "没有UCL属性部分\n";
	}
	else if (flag.substr(6, 1) == "1")
	{
		result += "有UCL属性部分\n";
	}
	//第二部分
	if (flag.substr(5, 1) == "0")
	{
		result += "复用字节段域不含定时或循环分发信息\n";
	}
	else if (flag.substr(5, 1) == "1")
	{
		result += "复用字节段域包含定时或循环分发信息\n";
	}
	if (flag.substr(4, 1) == "0")
	{
		result += "复用字节段域不含由应用定义的信息\n";
	}
	else if (flag.substr(4, 1) == "1")
	{
		result += "复用字节段域包含由应用定义的信息\n";
	}
	//第三部分
	if (flag.substr(6, 1) == "0")
	{
		return result;
	}
	else if (flag.substr(6, 1) == "1")
	{
		if (flag.substr(3, 1) == "0")
		{
			result += "UCL包与内容对象彼此分离\n";
		}
		else if (flag.substr(3, 1) == "1")
		{
			result += "内容对象已包含在UCL包中\n";
		}
		if (flag.substr(2, 1) == "0")
		{
			result += "UCL属性部分没有关联UCL域\n";
		}
		else if (flag.substr(2, 1) == "1")
		{
			result += "UCL属性部分有关联UCL域\n";
		}
		if (flag.substr(1, 1) == "0")
		{
			result += "UCL包遵循标准UCL标引方式\n";
		}
		else if (flag.substr(1, 1) == "1")
		{
			result += "UCL属性部分有用户自定义或扩展的属性域\n";
		}
		return result;
	}
}

string explainParseRule(vector<string>& code)
{
	string parseRule = code[3] + code[4].substr(4, 4);
	int n1 = string_to_number(parseRule.substr(6,6));
	int n2 = string_to_number(parseRule.substr(0,6));
	string result = "一级解码标准编号 :" + to_string(n1) + "\n二级解码编号 :" + to_string(n2);
	return result;
}

string explainSC(vector<string>& code)
{
	string result;
	string SC = code[4].substr(0, 4) + code[5] + code[6] + code[7];
	//第一部分
	if (SC.substr(25,3) == "001")
	{
		result = "内容来源对应为网址或域名形式\n";
	}
	else if (SC.substr(25, 3) == "010")
	{
		result = "内容来源对应为机构名形式\n";
	}
	else if (SC.substr(25, 3) == "010")
	{
		result = "内容来源对应为应用相关的形式\n";
	}
	else
	{
		result += "内容来源对应形式未定义\n";
	}
	//第二部分
	result = result + "内容来源 ：" + to_string(string_to_number(SC.substr(0,24)));
	return result;
}

string explainCategory(vector<string>& code)
{
	string category = code[8];
	string result = "一级分类类别 :" + to_string(string_to_number(category));
	return result;
}

string explainSubcategory(vector<string>& code)
{
	string subcategory = code[9];
	string result = "二级分类类别 :" + to_string(string_to_number(subcategory));
	return result;
}

string explainTopic(vector<string>& code)
{
	string result;
	string topic = code[10] + code[11] + code[12] + code[13];
	//第一部分
	if (topic.substr(7,1)=="0")
	{
		result = "大众话题\n";
	}
	else if (topic.substr(7, 1) == "1")
	{
		result = "小众话题\n";
	}
	//第二部分
	result = result + "话题 :" + to_string(string_to_number(topic.substr(0, 28)));
	return result;
}

string explainCT(vector<string>& code)
{
	string result;
	string CT = code[14];
	//第一部分
	if (CT.substr(7,1)=="0")
	{
		result += "UCL包标识的对象没有版权信息\n";
	}
	else if (CT.substr(7, 1) == "1")
	{
		result += "UCL包标识的对象具有版权信息\n";
	}
	if (CT.substr(6, 1) == "0")
	{
		result += "UCL包标识的内容对象为转载内容\n";
	}
	else if (CT.substr(6, 1) == "1")
	{
		result += "UCL包标识的内容对象为原创性内容\n";
	}
	if (CT.substr(5, 1) == "0")
	{
		result += "UCL包标识的内容对象为免费内容\n";
	}
	else if (CT.substr(5, 1) == "1")
	{
		result += "UCL包标识的内容对象为收费内容\n";
	}
	//第二部分
	if (CT.substr(0, 4) == "0000")
	{
		result += "内容对象所属类型：未定义\n";
	}
	else if (CT.substr(0, 4) == "0001")
	{
		result += "内容对象所属类型：文本\n";
	}
	else if (CT.substr(0, 4) == "0010")
	{
		result += "内容对象所属类型：图像\n";
	}
	else if (CT.substr(0, 4) == "0011")
	{
		result += "内容对象所属类型：音频\n";
	}
	else if (CT.substr(0, 4) == "0100")
	{
		result += "内容对象所属类型：视频\n";
	}
	else if (CT.substr(0, 4) == "0101")
	{
		result += "内容对象所属类型：彩信\n";
	}
	else if (CT.substr(0, 4) == "0110")
	{
		result += "内容对象所属类型：应用程序\n";
	}
	else if (CT.substr(0, 4) == "0111")
	{
		result += "内容对象所属类型：复合类型\n";
	}
	else
	{
		result += "内容对象所属类型：保留\n";
	}
	return result;
}

string explainSELC(vector<string>& code)
{
	string result;
	string SELC = code[15];
	//第一部分
	if (SELC.substr(6, 2) == "00")
	{
		result += "认证等级：UCL生成时自行标定\n";
	}
	else if (SELC.substr(6, 2) == "01")
	{
		result += "认证等级：已经过内容提供商认证\n";
	}
	else if (SELC.substr(6, 2) == "10")
	{
		result += "认证等级：已经过权威内容中心认证\n";
	}
	else
	{
		result += "认证等级：未定义\n";
	}
	//第二部分
	result = result + "物理安全程度 ：" + to_string(string_to_number(SELC.substr(3, 3))) + '\n';
	//第三部分
	result = result + "逻辑安全能级 ：" + to_string(string_to_number(SELC.substr(0, 3)));
	return result;
}

string explainLanguage(vector<string>& code)
{
	string language = code[16];
	string result;
	//第一部分
	if (language.substr(2, 6) == "111111")
	{
		result += "语种：其他\n";
	}
	else if (language.substr(2, 6) == "001000")
	{
		result += "语种：汉语（中文）\n";
	}
	else if (language.substr(2, 6) == "001001")
	{
		result += "语种：蒙古语（蒙古文）\n";
	}
	else if (language.substr(2, 6) == "001010")
	{
		result += "语种：藏语（藏文）\n";
	}
	else if (language.substr(2, 6) == "001011")
	{
		result += "语种：维吾尔语（维吾尔文）\n";
	}
	else if (language.substr(2, 6) == "001100")
	{
		result += "语种：哈萨克语（哈萨克文）\n";
	}
	else if (language.substr(2, 6) == "001101")
	{
		result += "语种：朝鲜语（朝鲜文）\n";
	}
	else if (language.substr(2, 6) == "001110")
	{
		result += "语种：柯尔克孜语（柯尔克孜文）\n";
	}
	else if (language.substr(2, 6) == "001111")
	{
		result += "语种：满语（满文）\n";
	}
	else if (language.substr(2, 6) == "010000")
	{
		result += "语种：傣语（傣文）\n";
	}
	else if (language.substr(2, 6) == "010001")
	{
		result += "语种：彝语（彝文）\n";
	}
	else if (language.substr(2, 6) == "010010")
	{
		result += "语种：壮语（壮文）\n";
	}
	else if (language.substr(2, 6) == "011111")
	{
		result += "语种：中国其他少数民族语言\n";
	}
	else if (language.substr(2, 6) == "100100")
	{
		result += "语种：英语（英文）\n";
	}
	else if (language.substr(2, 6) == "100101")
	{
		result += "语种：法语（法文）\n";
	}
	else if (language.substr(2, 6) == "100110")
	{
		result += "语种：俄语（俄文）\n";
	}
	else if (language.substr(2, 6) == "100111")
	{
		result += "语种：阿拉伯语（阿拉伯文）\n";
	}
	else if (language.substr(2, 6) == "101000")
	{
		result += "语种：西班牙语（西班牙文）\n";
	}
	else if (language.substr(2, 6) == "101001")
	{
		result += "语种：葡萄牙语（葡萄牙文）\n";
	}
	else if (language.substr(2, 6) == "101010")
	{
		result += "语种：德语（德文）\n";
	}
	else if (language.substr(2, 6) == "101011")
	{
		result += "语种：日语（日文）\n";
	}
	else if (language.substr(2, 6) == "101100")
	{
		result += "语种：印地语（印地文）\n";
	}
	else if (language.substr(2, 6) == "101101")
	{
		result += "语种：孟加拉语（孟加拉文）\n";
	}
	else if (language.substr(2, 6) == "101110")
	{
		result += "语种：意大利语（意大利文）\n";
	}
	else
	{
		result += "语种：未定义\n";
	}
	//第二部分
	if (language.substr(0, 2) == "00")
	{
		result += "UCL属性部分的主要语种与该域第一部分相同";
	}
	else if (language.substr(0, 2) == "01")
	{
		result += "UCL属性部分的主要语种与UCL属性描述元语言相同";
	}
	else if (language.substr(0, 2) == "11")
	{
		result += "UCL属性部分的主要语种与该域第一部分和UCL属性描述元语言均不相同";
	}

	return result;
}

string explainSoC(vector<string>& code)
{
	string result;
	string SoC = code[17].substr(3, 5);
	//第一部分
	if (SoC.substr(2, 3) == "000")
	{
		result += "内容对象长度取值：[1,4)\n";
	}
	else if (SoC.substr(2, 3) == "001")
	{
		result += "内容对象长度取值：[4,16)\n";
	}
	else if (SoC.substr(2, 3) == "010")
	{
		result += "内容对象长度取值：[16,64)\n";
	}
	else if (SoC.substr(2, 3) == "011")
	{
		result += "内容对象长度取值：[64,128)\n";
	}
	else if (SoC.substr(2, 3) == "100")
	{
		result += "内容对象长度取值：[128,256)\n";
	}
	else if (SoC.substr(2, 3) == "101")
	{
		result += "内容对象长度取值：[256,512)\n";
	}
	else if (SoC.substr(2, 3) == "110")
	{
		result += "内容对象长度取值：[512,768)\n";
	}
	else if (SoC.substr(2, 3) == "111")
	{
		result += "内容对象长度取值：[768,1024)\n";
	}
	//第二部分
	if (SoC.substr(0, 2) == "00")
	{
		result += "长度单位：B";
	}
	else if (SoC.substr(0, 2) == "01")
	{
		result += "长度单位：KB";
	}
	else if (SoC.substr(0, 2) == "10")
	{
		result += "长度单位：MB";
	}
	else if (SoC.substr(0, 2) == "11")
	{
		result += "长度单位：GB";
	}

	return result;
}

string explainTimestamp(vector<string>& code)
{
	string result;
	string timestamp = code[17].substr(0, 3) + code[18] 
		+ code[19] + code[20] + code[21] + code[22];
	//第一部分
	result = "UCL生成时刻：距协调世界时秒数：" + to_string(string_to_number(timestamp.substr(10, 33))) + '\n';
	//第二部分
	result = result + "毫秒级精度时间戳数值：" + to_string(string_to_number(timestamp.substr(0, 10)));
	
	return result;
}

string explainSN(vector<string>& code,int &length)
{
	string result;
	string SN_first;
	string SN_second;
	string SN_third;
	string SN_judge = code[23];
	//第一部分，判断域的总长度
	if (SN_judge.substr(6, 2) == "00" || SN_judge.substr(6, 2) == "01")
	{
		length = 1;
		result += "该域总长度为1字节\n";
		SN_first = SN_judge.substr(6, 2);
		SN_second = SN_judge.substr(4, 2);
		SN_third = SN_judge.substr(0, 4);
	}
	else if ((SN_judge += code[24]).substr(14, 2) == "10")
	{
		length = 2;
		result += "该域总长度为2字节\n";
		//SN_judge += code[24];
		SN_first = SN_judge.substr(14, 2);
		SN_second = SN_judge.substr(12, 2);
		SN_third = SN_judge.substr(0, 12);
	}
	else if ((SN_judge += code[25]).substr(22, 2) == "11")
	{
		length = 3;
		result += "该域总长度为3字节\n";
		//SN_judge += code[25];
		SN_first = SN_judge.substr(22, 2);
		SN_second = SN_judge.substr(20, 2);
		SN_third = SN_judge.substr(0, 20);
	}
	//第二部分和第三部分
	if (SN_first == "01")
	{
		string temp = SN_second + SN_third;
		result += "顺序号：" + to_string(string_to_number(temp)) + '\n';
	}
	else if (SN_first == "10" || SN_first == "11")
	{
		if (SN_first == "10")
		{
			if (SN_second.substr(1, 1) == "0")
			{
				result += "第三部分记录的是时间戳域基础上的微秒级精度时间戳数值\n";
			}
			else if (SN_second.substr(1, 1) == "1")
			{
				result += "第三部分记录的是一般顺序号\n";
			}
			result += "第三部分：" + to_string(string_to_number(SN_third));
		}

		if (SN_first == "11")
		{
			if (SN_second.substr(1, 1) == "0")
			{
				result += "第三部分记录的是时间戳域基础上的纳秒级精度时间戳数值\n";
			}
			else if (SN_second.substr(1, 1) == "1")
			{
				result += "第三部分记录的是一般顺序号\n";
			}
			result += "第三部分：" + to_string(string_to_number(SN_third));
		}
	}
	return result;
}

string explainMB(vector<string>& code)
{
	string result;
	string sub_flag = code[2].substr(4, 2);
	if (sub_flag == "00")
	{
		result += "该域未被启用\n";
	}
	else if (sub_flag == "01")
	{
		result += "该域记录有与应用相关的信息，但没有定时或循环分发信息\n";
	}
	else if (sub_flag == "10")
	{
		result += "该域记录有定时或循环分发信息，但没有其他的与应用有关的信息\n";
		//第一部分全取0，分析第二部分
		string sub_PP = code[1].substr(0, 4);
		int num = string_to_number(sub_PP);
		if (num >= 1 && num <= 7)
		{
			//只含循环周期
			string cycle_period = code[29];
			//循环周期第一部分
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "周期单位：保留\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "周期单位：秒\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "周期单位：分\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "周期单位：小时\n";
			}
			//循环周期第二部分
			result = result + "周期值：" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
		else if (num == 8)
		{
			//只含定时起点
			string timing_start = code[27] + code[28] + code[29];
			//分析定时起点信息
			result = result + "定时起点相对时间戳域的后移秒数：" + to_string(string_to_number(timing_start)) + '\n';

		}
		else if (num >= 9 && num <= 15)
		{
			//同时包含定时起点和循环周期
			//分析定时起点
			string timing_start = code[26] + code[27] + code[28];
			result = result + "定时起点相对时间戳域的后移秒数：" + to_string(string_to_number(timing_start)) + '\n';
			string cycle_period = code[29];
			//分析循环周期
			//循环周期第一部分
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "周期单位：未定义\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "周期单位：秒\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "周期单位：分\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "周期单位：小时\n";
			}
			//循环周期第二部分
			result = result + "周期值：" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
	}
	else if (sub_flag == "11")
	{
		result + "该域记录有定时或循环分发信息，而且有其他的与应用有关的信息\n";
		int SN_Length;
		explainSN(code, SN_Length);
		string MB;
		string sub_PP = code[1].substr(0, 4);
		int num = string_to_number(sub_PP);
		if (num >= 1 && num <= 7)
		{
			//第一部分
			for (int index = 23 + SN_Length; index <= 28; ++index)
			{
				MB += code[index];
			}
			result = result + "第一部分：\n" + MB;
			/*
				第二部分
				只含循环周期
			*/
			string cycle_period = code[29];
			//循环周期第一部分
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "周期单位：保留\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "周期单位：秒\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "周期单位：分\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "周期单位：小时\n";
			}
			//循环周期第二部分
			result = result + "周期值：" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
		else if (num == 8)
		{
			//第一部分
			for (int index = 23 + SN_Length; index <= 26; ++index)
			{
				MB += code[index];
			}
			result = result + "第一部分：\n" + MB;
			/*
				第二部分
				只含定时起点
			*/
			string timing_start = code[27] + code[28] + code[29];
			//分析定时起点信息
			result = result + "定时起点相对时间戳域的后移秒数：" + to_string(string_to_number(timing_start)) + '\n';

		}
		else if (num >= 9 && num <= 15)
		{
			//第一部分
			for (int index = 23 + SN_Length; index <= 25; ++index)
			{
				MB += code[index];
			}
			result = result + "第一部分：\n" + MB;
			/*	
				第二部分
				同时包含定时起点和循环周期
			*/
			//分析定时起点
			string timing_start = code[26] + code[27] + code[28];
			result = result + "定时起点相对时间戳域的后移秒数：" + to_string(string_to_number(timing_start)) + '\n';
			string cycle_period = code[29];
			//分析循环周期
			//循环周期第一部分
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "周期单位：保留\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "周期单位：秒\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "周期单位：分\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "周期单位：小时\n";
			}
			//循环周期第二部分
			result = result + "周期值：" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
	}
	return result;
}

string explainCC(vector<string>& code)
{
	string result = "校验码："+code[30] + code[31];
	return result;	
}

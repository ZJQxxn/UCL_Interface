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
	string result = "δ����";
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
	string result = "δ����";
	string TM = code[0].substr(0,5);
	if (TM == "01000")
	{
		result= "��������Ϣ�Ż�";
	}
	else if (TM == "01001")
	{
		result= "��������";
	}
	else if (TM == "01010")
	{
		result= "��������Ѷ����";
	}
	else if (TM == "01011")
	{
		result= "��ҵӦ��";
	}
	else if (TM == "01100")
	{
		result= "��̳������";
	}
	else if (TM == "01101")
	{
		result= "�罻ý������ý��";
	}
	else if (TM == "01110")
	{
		result= "����������";
	}
	else if (TM == "01111")
	{
		result= "��������Ϸ";
	}
	else if (TM == "10000")
	{
		result= "˫�ṹ����Ӧ��";
	}
	else if (TM == "10101")
	{
		result = "����ͼƬ������";
	}
	else if (TM == "10110")
	{
		result = "���ֱ�����ͼ��";
	}
	else if (TM == "10111")
	{
		result = "��������Ӧ��";
	}
	else if (TM == "11000")
	{
		result = "���ӣ�����ý�壩";
	}
	else if (TM == "11001")
	{
		result = "�㲥���ڶ�ý�壩";
	}
	else if (TM == "11010")
	{
		result = "��������һý�壩";
	}
	else if (TM == "11011")
	{
		result = "ͼ��";
	}
	else if (TM == "11100")
	{
		result = "������Ʒ";
	}
	return result;
}

string explainPP(vector<string>& code)
{
	string result;
	string PP = code[1];
	//��һ����
	result = "���ȼ� ��" + to_string(string_to_number(PP.substr(5, 3))) + '\n';
	//�ڶ�����
	if (PP.substr(4,1) == "0")
	{
		result += "�����ȼ�����ռʽ����\n";
	}
	else if (PP.substr(4, 1) == "1")
	{
		result += "�����ȼ���ռʽ����\n";
	}
	if (PP.substr(3, 1) == "0")
	{
		result += "��ʱ�ַ�\n";
	}
	else if (PP.substr(3, 1) == "1")
	{
		result += "��ʱ�ַ�\n";
	}
	//��������
	if (PP.substr(0,3) == "000")
	{
		result += "��ѭ���ַ�\n";
	}
	else if (PP.substr(0,3) == "001")
	{
		result += "1Сʱ��ѭ���ַ�\n";
	}
	else if (PP.substr(0, 3) == "010")
	{
		result += "2Сʱ��ѭ���ַ�\n";
	}
	else if (PP.substr(0, 3) == "011")
	{
		result += "4Сʱ��ѭ���ַ�\n";
	}
	else if (PP.substr(0, 3) == "100")
	{
		result += "8Сʱ��ѭ���ַ�\n";
	}
	else if (PP.substr(0, 3) == "101")
	{
		result += "12Сʱ��ѭ���ַ�\n";
	}
	else if (PP.substr(0, 3) == "110")
	{
		result += "24Сʱ��ѭ���ַ�\n";
	}
	else if (PP.substr(0, 3) == "111")
	{
		result += "48Сʱ��ѭ���ַ�\n";
	}
	return result;
}

string explainFlag(vector<string>& code)
{
	string result;
	string flag = code[2];
	//��һ����
	if (flag.substr(7,1) == "0")
	{
		result += "UCL���벻������չ\n";
	}
	else if (flag.substr(7, 1) == "1")
	{
		result += "UCL���������չ\n";
	}
	if (flag.substr(6,1) == "0")
	{
		result += "û��UCL���Բ���\n";
	}
	else if (flag.substr(6, 1) == "1")
	{
		result += "��UCL���Բ���\n";
	}
	//�ڶ�����
	if (flag.substr(5, 1) == "0")
	{
		result += "�����ֽڶ��򲻺���ʱ��ѭ���ַ���Ϣ\n";
	}
	else if (flag.substr(5, 1) == "1")
	{
		result += "�����ֽڶ��������ʱ��ѭ���ַ���Ϣ\n";
	}
	if (flag.substr(4, 1) == "0")
	{
		result += "�����ֽڶ��򲻺���Ӧ�ö������Ϣ\n";
	}
	else if (flag.substr(4, 1) == "1")
	{
		result += "�����ֽڶ��������Ӧ�ö������Ϣ\n";
	}
	//��������
	if (flag.substr(6, 1) == "0")
	{
		return result;
	}
	else if (flag.substr(6, 1) == "1")
	{
		if (flag.substr(3, 1) == "0")
		{
			result += "UCL�������ݶ���˴˷���\n";
		}
		else if (flag.substr(3, 1) == "1")
		{
			result += "���ݶ����Ѱ�����UCL����\n";
		}
		if (flag.substr(2, 1) == "0")
		{
			result += "UCL���Բ���û�й���UCL��\n";
		}
		else if (flag.substr(2, 1) == "1")
		{
			result += "UCL���Բ����й���UCL��\n";
		}
		if (flag.substr(1, 1) == "0")
		{
			result += "UCL����ѭ��׼UCL������ʽ\n";
		}
		else if (flag.substr(1, 1) == "1")
		{
			result += "UCL���Բ������û��Զ������չ��������\n";
		}
		return result;
	}
}

string explainParseRule(vector<string>& code)
{
	string parseRule = code[3] + code[4].substr(4, 4);
	int n1 = string_to_number(parseRule.substr(6,6));
	int n2 = string_to_number(parseRule.substr(0,6));
	string result = "һ�������׼��� :" + to_string(n1) + "\n���������� :" + to_string(n2);
	return result;
}

string explainSC(vector<string>& code)
{
	string result;
	string SC = code[4].substr(0, 4) + code[5] + code[6] + code[7];
	//��һ����
	if (SC.substr(25,3) == "001")
	{
		result = "������Դ��ӦΪ��ַ��������ʽ\n";
	}
	else if (SC.substr(25, 3) == "010")
	{
		result = "������Դ��ӦΪ��������ʽ\n";
	}
	else if (SC.substr(25, 3) == "010")
	{
		result = "������Դ��ӦΪӦ����ص���ʽ\n";
	}
	else
	{
		result += "������Դ��Ӧ��ʽδ����\n";
	}
	//�ڶ�����
	result = result + "������Դ ��" + to_string(string_to_number(SC.substr(0,24)));
	return result;
}

string explainCategory(vector<string>& code)
{
	string category = code[8];
	string result = "һ��������� :" + to_string(string_to_number(category));
	return result;
}

string explainSubcategory(vector<string>& code)
{
	string subcategory = code[9];
	string result = "����������� :" + to_string(string_to_number(subcategory));
	return result;
}

string explainTopic(vector<string>& code)
{
	string result;
	string topic = code[10] + code[11] + code[12] + code[13];
	//��һ����
	if (topic.substr(7,1)=="0")
	{
		result = "���ڻ���\n";
	}
	else if (topic.substr(7, 1) == "1")
	{
		result = "С�ڻ���\n";
	}
	//�ڶ�����
	result = result + "���� :" + to_string(string_to_number(topic.substr(0, 28)));
	return result;
}

string explainCT(vector<string>& code)
{
	string result;
	string CT = code[14];
	//��һ����
	if (CT.substr(7,1)=="0")
	{
		result += "UCL����ʶ�Ķ���û�а�Ȩ��Ϣ\n";
	}
	else if (CT.substr(7, 1) == "1")
	{
		result += "UCL����ʶ�Ķ�����а�Ȩ��Ϣ\n";
	}
	if (CT.substr(6, 1) == "0")
	{
		result += "UCL����ʶ�����ݶ���Ϊת������\n";
	}
	else if (CT.substr(6, 1) == "1")
	{
		result += "UCL����ʶ�����ݶ���Ϊԭ��������\n";
	}
	if (CT.substr(5, 1) == "0")
	{
		result += "UCL����ʶ�����ݶ���Ϊ�������\n";
	}
	else if (CT.substr(5, 1) == "1")
	{
		result += "UCL����ʶ�����ݶ���Ϊ�շ�����\n";
	}
	//�ڶ�����
	if (CT.substr(0, 4) == "0000")
	{
		result += "���ݶ����������ͣ�δ����\n";
	}
	else if (CT.substr(0, 4) == "0001")
	{
		result += "���ݶ����������ͣ��ı�\n";
	}
	else if (CT.substr(0, 4) == "0010")
	{
		result += "���ݶ����������ͣ�ͼ��\n";
	}
	else if (CT.substr(0, 4) == "0011")
	{
		result += "���ݶ����������ͣ���Ƶ\n";
	}
	else if (CT.substr(0, 4) == "0100")
	{
		result += "���ݶ����������ͣ���Ƶ\n";
	}
	else if (CT.substr(0, 4) == "0101")
	{
		result += "���ݶ����������ͣ�����\n";
	}
	else if (CT.substr(0, 4) == "0110")
	{
		result += "���ݶ����������ͣ�Ӧ�ó���\n";
	}
	else if (CT.substr(0, 4) == "0111")
	{
		result += "���ݶ����������ͣ���������\n";
	}
	else
	{
		result += "���ݶ����������ͣ�����\n";
	}
	return result;
}

string explainSELC(vector<string>& code)
{
	string result;
	string SELC = code[15];
	//��һ����
	if (SELC.substr(6, 2) == "00")
	{
		result += "��֤�ȼ���UCL����ʱ���б궨\n";
	}
	else if (SELC.substr(6, 2) == "01")
	{
		result += "��֤�ȼ����Ѿ��������ṩ����֤\n";
	}
	else if (SELC.substr(6, 2) == "10")
	{
		result += "��֤�ȼ����Ѿ���Ȩ������������֤\n";
	}
	else
	{
		result += "��֤�ȼ���δ����\n";
	}
	//�ڶ�����
	result = result + "����ȫ�̶� ��" + to_string(string_to_number(SELC.substr(3, 3))) + '\n';
	//��������
	result = result + "�߼���ȫ�ܼ� ��" + to_string(string_to_number(SELC.substr(0, 3)));
	return result;
}

string explainLanguage(vector<string>& code)
{
	string language = code[16];
	string result;
	//��һ����
	if (language.substr(2, 6) == "111111")
	{
		result += "���֣�����\n";
	}
	else if (language.substr(2, 6) == "001000")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "001001")
	{
		result += "���֣��ɹ���ɹ��ģ�\n";
	}
	else if (language.substr(2, 6) == "001010")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "001011")
	{
		result += "���֣�ά����ά����ģ�\n";
	}
	else if (language.substr(2, 6) == "001100")
	{
		result += "���֣���������������ģ�\n";
	}
	else if (language.substr(2, 6) == "001101")
	{
		result += "���֣�����������ģ�\n";
	}
	else if (language.substr(2, 6) == "001110")
	{
		result += "���֣��¶�������¶������ģ�\n";
	}
	else if (language.substr(2, 6) == "001111")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "010000")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "010001")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "010010")
	{
		result += "���֣�׳�׳�ģ�\n";
	}
	else if (language.substr(2, 6) == "011111")
	{
		result += "���֣��й�����������������\n";
	}
	else if (language.substr(2, 6) == "100100")
	{
		result += "���֣�Ӣ�Ӣ�ģ�\n";
	}
	else if (language.substr(2, 6) == "100101")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "100110")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "100111")
	{
		result += "���֣���������������ģ�\n";
	}
	else if (language.substr(2, 6) == "101000")
	{
		result += "���֣���������������ģ�\n";
	}
	else if (language.substr(2, 6) == "101001")
	{
		result += "���֣���������������ģ�\n";
	}
	else if (language.substr(2, 6) == "101010")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "101011")
	{
		result += "���֣�������ģ�\n";
	}
	else if (language.substr(2, 6) == "101100")
	{
		result += "���֣�ӡ���ӡ���ģ�\n";
	}
	else if (language.substr(2, 6) == "101101")
	{
		result += "���֣��ϼ�����ϼ����ģ�\n";
	}
	else if (language.substr(2, 6) == "101110")
	{
		result += "���֣�������������ģ�\n";
	}
	else
	{
		result += "���֣�δ����\n";
	}
	//�ڶ�����
	if (language.substr(0, 2) == "00")
	{
		result += "UCL���Բ��ֵ���Ҫ����������һ������ͬ";
	}
	else if (language.substr(0, 2) == "01")
	{
		result += "UCL���Բ��ֵ���Ҫ������UCL��������Ԫ������ͬ";
	}
	else if (language.substr(0, 2) == "11")
	{
		result += "UCL���Բ��ֵ���Ҫ����������һ���ֺ�UCL��������Ԫ���Ծ�����ͬ";
	}

	return result;
}

string explainSoC(vector<string>& code)
{
	string result;
	string SoC = code[17].substr(3, 5);
	//��һ����
	if (SoC.substr(2, 3) == "000")
	{
		result += "���ݶ��󳤶�ȡֵ��[1,4)\n";
	}
	else if (SoC.substr(2, 3) == "001")
	{
		result += "���ݶ��󳤶�ȡֵ��[4,16)\n";
	}
	else if (SoC.substr(2, 3) == "010")
	{
		result += "���ݶ��󳤶�ȡֵ��[16,64)\n";
	}
	else if (SoC.substr(2, 3) == "011")
	{
		result += "���ݶ��󳤶�ȡֵ��[64,128)\n";
	}
	else if (SoC.substr(2, 3) == "100")
	{
		result += "���ݶ��󳤶�ȡֵ��[128,256)\n";
	}
	else if (SoC.substr(2, 3) == "101")
	{
		result += "���ݶ��󳤶�ȡֵ��[256,512)\n";
	}
	else if (SoC.substr(2, 3) == "110")
	{
		result += "���ݶ��󳤶�ȡֵ��[512,768)\n";
	}
	else if (SoC.substr(2, 3) == "111")
	{
		result += "���ݶ��󳤶�ȡֵ��[768,1024)\n";
	}
	//�ڶ�����
	if (SoC.substr(0, 2) == "00")
	{
		result += "���ȵ�λ��B";
	}
	else if (SoC.substr(0, 2) == "01")
	{
		result += "���ȵ�λ��KB";
	}
	else if (SoC.substr(0, 2) == "10")
	{
		result += "���ȵ�λ��MB";
	}
	else if (SoC.substr(0, 2) == "11")
	{
		result += "���ȵ�λ��GB";
	}

	return result;
}

string explainTimestamp(vector<string>& code)
{
	string result;
	string timestamp = code[17].substr(0, 3) + code[18] 
		+ code[19] + code[20] + code[21] + code[22];
	//��һ����
	result = "UCL����ʱ�̣���Э������ʱ������" + to_string(string_to_number(timestamp.substr(10, 33))) + '\n';
	//�ڶ�����
	result = result + "���뼶����ʱ�����ֵ��" + to_string(string_to_number(timestamp.substr(0, 10)));
	
	return result;
}

string explainSN(vector<string>& code,int &length)
{
	string result;
	string SN_first;
	string SN_second;
	string SN_third;
	string SN_judge = code[23];
	//��һ���֣��ж�����ܳ���
	if (SN_judge.substr(6, 2) == "00" || SN_judge.substr(6, 2) == "01")
	{
		length = 1;
		result += "�����ܳ���Ϊ1�ֽ�\n";
		SN_first = SN_judge.substr(6, 2);
		SN_second = SN_judge.substr(4, 2);
		SN_third = SN_judge.substr(0, 4);
	}
	else if ((SN_judge += code[24]).substr(14, 2) == "10")
	{
		length = 2;
		result += "�����ܳ���Ϊ2�ֽ�\n";
		//SN_judge += code[24];
		SN_first = SN_judge.substr(14, 2);
		SN_second = SN_judge.substr(12, 2);
		SN_third = SN_judge.substr(0, 12);
	}
	else if ((SN_judge += code[25]).substr(22, 2) == "11")
	{
		length = 3;
		result += "�����ܳ���Ϊ3�ֽ�\n";
		//SN_judge += code[25];
		SN_first = SN_judge.substr(22, 2);
		SN_second = SN_judge.substr(20, 2);
		SN_third = SN_judge.substr(0, 20);
	}
	//�ڶ����ֺ͵�������
	if (SN_first == "01")
	{
		string temp = SN_second + SN_third;
		result += "˳��ţ�" + to_string(string_to_number(temp)) + '\n';
	}
	else if (SN_first == "10" || SN_first == "11")
	{
		if (SN_first == "10")
		{
			if (SN_second.substr(1, 1) == "0")
			{
				result += "�������ּ�¼����ʱ���������ϵ�΢�뼶����ʱ�����ֵ\n";
			}
			else if (SN_second.substr(1, 1) == "1")
			{
				result += "�������ּ�¼����һ��˳���\n";
			}
			result += "�������֣�" + to_string(string_to_number(SN_third));
		}

		if (SN_first == "11")
		{
			if (SN_second.substr(1, 1) == "0")
			{
				result += "�������ּ�¼����ʱ���������ϵ����뼶����ʱ�����ֵ\n";
			}
			else if (SN_second.substr(1, 1) == "1")
			{
				result += "�������ּ�¼����һ��˳���\n";
			}
			result += "�������֣�" + to_string(string_to_number(SN_third));
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
		result += "����δ������\n";
	}
	else if (sub_flag == "01")
	{
		result += "�����¼����Ӧ����ص���Ϣ����û�ж�ʱ��ѭ���ַ���Ϣ\n";
	}
	else if (sub_flag == "10")
	{
		result += "�����¼�ж�ʱ��ѭ���ַ���Ϣ����û����������Ӧ���йص���Ϣ\n";
		//��һ����ȫȡ0�������ڶ�����
		string sub_PP = code[1].substr(0, 4);
		int num = string_to_number(sub_PP);
		if (num >= 1 && num <= 7)
		{
			//ֻ��ѭ������
			string cycle_period = code[29];
			//ѭ�����ڵ�һ����
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "���ڵ�λ������\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "���ڵ�λ��Сʱ\n";
			}
			//ѭ�����ڵڶ�����
			result = result + "����ֵ��" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
		else if (num == 8)
		{
			//ֻ����ʱ���
			string timing_start = code[27] + code[28] + code[29];
			//������ʱ�����Ϣ
			result = result + "��ʱ������ʱ�����ĺ���������" + to_string(string_to_number(timing_start)) + '\n';

		}
		else if (num >= 9 && num <= 15)
		{
			//ͬʱ������ʱ����ѭ������
			//������ʱ���
			string timing_start = code[26] + code[27] + code[28];
			result = result + "��ʱ������ʱ�����ĺ���������" + to_string(string_to_number(timing_start)) + '\n';
			string cycle_period = code[29];
			//����ѭ������
			//ѭ�����ڵ�һ����
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "���ڵ�λ��δ����\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "���ڵ�λ��Сʱ\n";
			}
			//ѭ�����ڵڶ�����
			result = result + "����ֵ��" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
	}
	else if (sub_flag == "11")
	{
		result + "�����¼�ж�ʱ��ѭ���ַ���Ϣ����������������Ӧ���йص���Ϣ\n";
		int SN_Length;
		explainSN(code, SN_Length);
		string MB;
		string sub_PP = code[1].substr(0, 4);
		int num = string_to_number(sub_PP);
		if (num >= 1 && num <= 7)
		{
			//��һ����
			for (int index = 23 + SN_Length; index <= 28; ++index)
			{
				MB += code[index];
			}
			result = result + "��һ���֣�\n" + MB;
			/*
				�ڶ�����
				ֻ��ѭ������
			*/
			string cycle_period = code[29];
			//ѭ�����ڵ�һ����
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "���ڵ�λ������\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "���ڵ�λ��Сʱ\n";
			}
			//ѭ�����ڵڶ�����
			result = result + "����ֵ��" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
		else if (num == 8)
		{
			//��һ����
			for (int index = 23 + SN_Length; index <= 26; ++index)
			{
				MB += code[index];
			}
			result = result + "��һ���֣�\n" + MB;
			/*
				�ڶ�����
				ֻ����ʱ���
			*/
			string timing_start = code[27] + code[28] + code[29];
			//������ʱ�����Ϣ
			result = result + "��ʱ������ʱ�����ĺ���������" + to_string(string_to_number(timing_start)) + '\n';

		}
		else if (num >= 9 && num <= 15)
		{
			//��һ����
			for (int index = 23 + SN_Length; index <= 25; ++index)
			{
				MB += code[index];
			}
			result = result + "��һ���֣�\n" + MB;
			/*	
				�ڶ�����
				ͬʱ������ʱ����ѭ������
			*/
			//������ʱ���
			string timing_start = code[26] + code[27] + code[28];
			result = result + "��ʱ������ʱ�����ĺ���������" + to_string(string_to_number(timing_start)) + '\n';
			string cycle_period = code[29];
			//����ѭ������
			//ѭ�����ڵ�һ����
			if (cycle_period.substr(6, 2) == "00")
			{
				result += "���ڵ�λ������\n";
			}
			else if (cycle_period.substr(6, 2) == "01")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "10")
			{
				result += "���ڵ�λ����\n";
			}
			else if (cycle_period.substr(6, 2) == "11")
			{
				result += "���ڵ�λ��Сʱ\n";
			}
			//ѭ�����ڵڶ�����
			result = result + "����ֵ��" + to_string(string_to_number(cycle_period.substr(0, 6))) + '\n';
		}
	}
	return result;
}

string explainCC(vector<string>& code)
{
	string result = "У���룺"+code[30] + code[31];
	return result;	
}

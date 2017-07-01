//Head�ຯ���Ķ���
//������Head.h��

#include "stdafx.h"
#include "Head.h"
#include "UCL.h"
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;


/*Head ��ĺ�������*/
int Head::stringToInt(string& str) //string���͵Ķ���������ת��Ϊint���͵�ʮ��������
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

string Head::reverse(string str)
{
	string result;
	for (int index = str.length() - 1; index >= 0; index--)
	{
		result += str[index];
	}
	return result;
}

Head::Head(vector<string>::iterator& head_it)
{	
	vector <string>::iterator current_it = head_it;
	property_Type.push_back(*current_it++);

	//��������ͷ���ֽ�
	elementNum = stringToInt(current_it->substr(2, 4)) + 1;
	subLength = stringToInt(current_it->substr(0,2)) + 1; 
	property_Length.push_back(*current_it++);

	//��������ֵ�ӷ���
	string sub_Length_value;
	for (int count = 0; count < subLength; ++count, ++current_it)
	{
		sub_Length_value += reverse(*current_it);
		property_Length.push_back(*current_it);
	}
	sub_Length_value = reverse(sub_Length_value);
	setLength = stringToInt(sub_Length_value);

	//����������Ϣ�ӷ���
	property_Length.push_back(*current_it);
	current_it++;
	property_Length.push_back(*current_it);
	current_it++;

	//�������Ծ���
	for (int count = 0; count < (setLength - 4 - subLength); ++count,++current_it)
	{
		property_Content.push_back(*current_it);
	}
}

string Head::getSetType()
{
	string set_type_value = get_Type()[0].substr(4,4);
	string result = "δ����";
	if (set_type_value == "0001")
	{
		result = "CDPS";
	}
	else if (set_type_value == "1111")
	{
		result = "CGPS";
	}
	return result;
}

string Head::getAnalyseRule()
{
	string analyse_rules;
	analyse_rules = get_Type()[0].substr(0, 4);
	if (analyse_rules == "0000")
	{
		analyse_rules = "�޸�����������";
	}
	return analyse_rules;
}

int Head::getElementNum()
{
	return elementNum;
}

int Head::getSubLength()
{
	return subLength;
}

int Head::getSetLength()
{
	return setLength;
}

vector<string>& Head::get_Type()
{
	return property_Type;
}

vector<string>& Head::get_Length()
{
	return property_Length;
}

vector<string>& Head::get_Content()
{
	return property_Content;
}

vector<int> Head::analyse()
{
	vector<int> result;
	string sub_info_value;
	sub_info_value += reverse(get_Length()[1 + getSubLength()]);
	sub_info_value += reverse(get_Length()[2 + getSubLength()]);
	for (size_t index = 0; index < sub_info_value.length(); ++index)
	{
		if (sub_info_value[index] == '1')
		{
			result.push_back(index);
		}
	}
	return result;
}

/*TotalHead ��ĺ�������*/

string TotalHead::getSetType()
{
	string language_type = get_Type()[0].substr(4,4);
	string result = "δ����";
	if (language_type == "0000")
	{
		result = "����";
	}
	else if (language_type == "0001")
	{
		result = "����";
	}
	else if (language_type == "0010")
	{
		result = "Ӣ��";
	}
	else if (language_type == "0011")
	{
		result = "����";
	}
	else if (language_type == "0100")
	{
		result = "����";
	}
	else if (language_type == "0101")
	{
		result = "��������";
	}
	else if (language_type == "0110")
	{
		result = "��������";
	}
	else if (language_type == "0111")
	{
		result = "��������";
	}
	else if (language_type == "1000")
	{
		result = "����";
	}
	else if (language_type == "1001")
	{
		result = "����";
	}
	else if (language_type == "1010")
	{
		result = "����";
	}
	else if (language_type == "1111")
	{
		result = "����";
	}
	return result;
}

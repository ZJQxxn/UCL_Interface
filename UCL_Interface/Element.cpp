//Element�ຯ���Ķ���
//������Element.h��

#include "stdafx.h"
#include "Element.h"
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;


int Element::stringToInt(string& str) //string���͵Ķ���������ת��Ϊint���͵�ʮ��������
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

string Element::reverse(string& str)
{
	string result;
	for (int index = str.length() - 1; index >= 0; index--)
	{
		result += str[index];
	}
	return result;
}

Element::Element(vector<string>::iterator read_it)
{
	vector<string>::iterator current_it = read_it;
	property_Type.push_back(*current_it++);
	num = stringToInt(get_Type()[0].substr(4,4));

	property_Length.push_back(*current_it++);
	subLength = stringToInt(get_Length()[0].substr(0,2)) + 1;
	string sub_Length;
	for (int count = 0; count < subLength; ++count, ++current_it)
	{
		sub_Length += reverse(*current_it);
		property_Length.push_back(*current_it);
	}
	sub_Length = reverse(sub_Length);
	elementLength = stringToInt(sub_Length); 

	for (int count = 0; count < (elementLength - 2 - subLength); ++count, current_it++)
	{
		property_Content.push_back(*current_it);
	}
}

/*��ͬ����Ԫ�صļ��㺯��*/

/*vector<int> Element::analyse()
{
	vector<int> result;
	string sub_Info;//����������Ϣ����
	sub_Info = reverse(get_Length()[0].substr(2));
	for (size_t index = 0; index < sub_Info.length(); ++index)
	{
		if (sub_Info[index] == '1')
		{
			result.push_back(index);
		}
	}
	return result;
}*/

int Element::keywordsNum()
{
	return (stringToInt(get_Length()[0].substr(2, 3)) + 1);
}

int Element::authorNum()
{
	return stringToInt(get_Length()[0].substr(5,3));
}

int Element::authorCopNum()
{
	return stringToInt(get_Length()[0].substr(2, 3));
}

vector<int> Element::entity()
{
	string entity_value = get_Length()[0].substr(2, 6);
	vector <int> result;
	for (size_t i = 0; i < entity_value.size(); ++i)
	{
		if (entity_value[i] == '1')
			result.push_back(i);
	}
	return result;
}

int Element::flagNum()
{
	return stringToInt(get_Length()[0].substr(2, 3)) + 1;
}

int Element::relatedUCLNum()
{
	return (stringToInt(get_Length()[0].substr(2, 3)) + 1);
}

string Element::provenanceForm()
{
	string result = "δ����";
	string str = get_Length()[0].substr(2, 3);
	if (str == "001")
	{
		result = "��ַ��������ʽ";
	}
	else if (str == "010")
	{
		result = "��������ʽ";
	}
	else if (str == "011")
	{
		result = "Ӧ����ص���ʽ";
	}
	return result;
}

int Element::pathLength()
{
	return (stringToInt(get_Length()[0].substr(2, 4)) + 1);
}

string Element::signatureStandard()
{
	string result = "δ����";
	string str = get_Length()[0].substr(2, 4);
	if (str == "0001")
	{
		result = "CRC32";
	}
	else if (str == "0010")
	{
		result = "MD5";
	}
	else if (str == "0011")
	{
		result = "SHA-256";
	}
	else if (str == "0100")
	{
		result = "SHA-512";
	}
	return result;
}

int Element::responsibilityNum()
{
	return (stringToInt(get_Length()[0].substr(2, 3)) + 1);
}

/*get functions*/

int Element::getNum()
{
	return num;
}

int Element::getSubLength()
{
	return subLength;
}

int Element::getElementLength()
{
	return elementLength;
}

vector<string>& Element::get_Type()
{
	return property_Type;
}

vector<string>& Element::get_Length()
{
	return property_Length;
}

vector<string>& Element::get_Content()
{
	return property_Content;
}

string Element::getAnalyseRule()
{
	string analyse_rules;
	analyse_rules = get_Type()[0].substr(0, 4);
	if (analyse_rules == "0000")
	{
		analyse_rules = "�޸�����������";
	}
	return analyse_rules;
}

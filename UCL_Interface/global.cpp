#include "stdafx.h"
#include "global.h"
#include "YCodec.h"

UCL *ucl;
TotalHead *totalHead;
SetHead *CDPSHead;
SetHead *CGPSHead;
vector<Element> CDPSSet;
vector<Element> CGPSSet; 

string wstring_to_string(const wstring& wStr)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, wStr.c_str(), -1, NULL, 0, NULL, NULL);
	LPSTR lpszStr = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, wStr.c_str(), -1, lpszStr, nLen, NULL, NULL);
	string szStr = lpszStr;
	delete[] lpszStr;
	return szStr;
}

wstring string_to_wstring(const string& str)
{
	int nLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, NULL);
	LPWSTR lpwszStr = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, lpwszStr, nLen);
	wstring wszStr = lpwszStr;
	delete[] lpwszStr;
	return wszStr;
}

string binToHex(string str)
{
	string result;
	for (int i = 0; i < str.size() / 4; ++i)
	{
		if (str.substr(i * 4, 4) == "0000")
		{
			result += "0";
		}
		else if (str.substr(i * 4, 4) == "0001")
		{
			result += "1";
		}
		else if (str.substr(i * 4, 4) == "0010")
		{
			result += "2";
		}
		else if (str.substr(i * 4, 4) == "0011")
		{
			result += "3";
		}
		else if (str.substr(i * 4, 4) == "0100")
		{
			result += "4";
		}
		else if (str.substr(i * 4, 4) == "0101")
		{
			result += "5";
		}
		else if (str.substr(i * 4, 4) == "0110")
		{
			result += "6";
		}
		else if (str.substr(i * 4, 4) == "0111")
		{
			result += "7";
		}
		else if (str.substr(i * 4, 4) == "1000")
		{
			result += "8";
		}
		else if (str.substr(i * 4, 4) == "1001")
		{
			result += "9";
		}
		else if (str.substr(i * 4, 4) == "1010")
		{
			result += "a";
		}
		else if (str.substr(i * 4, 4) == "1011")
		{
			result += "b";
		}
		else if (str.substr(i * 4, 4) == "1100")
		{
			result += "c";
		}
		else if (str.substr(i * 4, 4) == "1101")
		{
			result += "d";
		}
		else if (str.substr(i * 4, 4) == "1110")
		{
			result += "e";
		}
		else if (str.substr(i * 4, 4) == "1111")
		{
			result += "f";
		}
	}
	return result;
}

string convert(string binStr)
{
	int count = binStr.size() / 8;
	string hexStr;
	string convert;
	for (int i = 0; i < count;)
	{
		string temp = binStr.substr(i * 8, 8);
		if (temp.substr(0, 1) == "0")
		{
			convert = "0" + temp.substr(1);
			hexStr = hexStr + "00" + binToHex(convert);
			i++;
		}
		else if (temp.substr(0, 3) == "110")
		{
			convert = "0" + temp.substr(3, 5);
			i++;
			temp = binStr.substr(i * 8, 8);
			convert += temp.substr(2);
			hexStr = hexStr + "0" + binToHex(convert);
			i++;
		}
		else if (temp.substr(0, 4) == "1110")
		{
			convert = temp.substr(4, 4);
			i++;
			temp = binStr.substr(i * 8, 8);
			convert += temp.substr(2);
			i++;
			temp = binStr.substr(i * 8, 8);
			convert += temp.substr(2);
			i++;
			hexStr = hexStr + binToHex(convert);
		}
	}
	return hexStr;
}

CString text_change(CString content)
{
	//将UTF8编码的二进制序列转换为Unicode码
	CString input(convert(wstring_to_string(content.GetBuffer())).c_str());
	//将unicode码转换为文本
	CString result;
	YCodec yCodec;
	// CString to char*
	int strlen = input.GetLength();
	char* str = new char[strlen + 1];
	memset(str, 0, strlen + 1);
	for (int i = 0; i<strlen; i++)	str[i] = input.GetAt(i);
	// hex string to wchar_t*
	int wchslen = 0;
	if (yCodec.HexStr2WChars(str, strlen, 4, NULL, &wchslen) != -1){
		wchar_t* wchs = new wchar_t[wchslen + 1];
		memset(wchs, 0, sizeof(wchar_t)*(wchslen + 1));
		int n = yCodec.HexStr2WChars(str, strlen, 4, wchs, &wchslen);
		if (n != -1){
			// wchar_t to CString
			wchar_t* pwch = wchs;
			for (int i = 0; i<wchslen; i++)	result.AppendChar(*pwch++);
		}
		if (wchs)	delete[]wchs;
	}
	return result;
}

bool element_exist(vector<Element> &ElementSet, int elementNum, int &index)
{
	for (size_t i = 0; i < ElementSet.size(); ++i)
	{
		if (ElementSet[i].getNum() == elementNum)
		{
			index = i;
			return true;
		}
	}
	return false;
}
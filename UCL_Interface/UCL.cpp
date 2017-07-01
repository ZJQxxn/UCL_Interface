//UCL类函数的定义
//声明在UCL.h中

#include "stdafx.h"
#include "UCL.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

UCL::UCL(const string& filename)
{
	readFromFile(filename);
}

void UCL::readFromFile(const string& filename)
{
	vector <string> UCL;
	ifstream file;
	file.open(filename);
	if (!file)
	{
		exit(1);
	}
	string str;
	file >> str;
	file.close();
	convert(str, UCL);
	vector <string>::iterator it = UCL.begin();
	for (size_t count = 0; count < 32; count++)
	{
		UCL_Code.push_back(*it);
		it++;
	}
	for (; it != UCL.end(); ++it)
	{
		UCL_Properties.push_back(*it);
	}

}

vector<string>& UCL::getCode()
{
	return UCL_Code;
}

vector<string>& UCL::getProperties()
{
	return UCL_Properties;
}

string UCL::hexToBin(char *str)
{
	string result;
	if (strlen(str) == 1) //不足八位的，补零构成八位
	{
		result += "0000";
	}
	for (size_t i = 0; i < strlen(str); ++i)
	{
		switch (str[i])
		{
		case '0':
			result += "0000";
			break;
		case '1':
			result += "0001";
			break;
		case '2':
			result += "0010";
			break;
		case '3':
			result += "0011";
			break;
		case '4':
			result += "0100";
			break;
		case '5':
			result += "0101";
			break;
		case '6':
			result += "0110";
			break;
		case '7':
			result += "0111";
			break;
		case '8':
			result += "1000";
			break;
		case '9':
			result += "1001";
			break;
		case 'a':
			result += "1010";
			break;
		case 'b':
			result += "1011";
			break;
		case 'c':
			result += "1100";
			break;
		case 'd':
			result += "1101";
			break;
		case 'e':
			result += "1110";
			break;
		case 'f':
			result += "1111";
			break;
		}

	}
	return result;
}

void UCL::convert(string &original, vector <string>&UCL)		//convert original(hex) to result(binary)
{
	char *sentence = new char[original.length()];
	char *tokenPtr;
	char *save;
	strcpy_s(sentence, original.length() + 1, original.c_str());  /*c_str() returns a char* with '\0'  (char* is temporary and can't be used for assignment)*/
	tokenPtr = strtok_s(sentence, "-", &save);
	while (tokenPtr != nullptr)
	{
		UCL.push_back(hexToBin(tokenPtr));
		tokenPtr = strtok_s(NULL, "-", &save);
	}
}
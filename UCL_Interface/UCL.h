//UCL类的声明
#ifndef UCL_H
#define UCL_H
#include <vector>
#include <string>
using std::string;
using std::vector;

class UCL
{
private:
	vector <string> UCL_Code;							//保存UCL Code部分
	vector <string> UCL_Properties;						//保存UCL Properties部分	 
	string hexToBin(char *str);							//string类型的一串十六进制数转换为string类型的一串二进制数
	void convert(string &original, vector <string>&UCL);//转换为UCL
public:
	UCL(const string& filename);
	void readFromFile(const string& filename);			//
	/*get functions*/
	vector<string>& getCode();							//
	vector<string>& getProperties();					//
};
#endif
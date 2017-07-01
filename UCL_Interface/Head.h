//属性头部基类与子类的声明
//声明 Head 类的成员函数和成员变量

#ifndef HEAD_H
#define HEAD_H
#include <string>
#include <vector>
using std::string;
using std::vector;

class Head
{
private:
	vector <string> property_Type;			//属性类型（1字节）
	vector <string> property_Length;		//属性长度（4~7字节）
	vector <string> property_Content;		//属性净荷
	int elementNum;							//集合元素个数
	int subLength;							//长度值子分量长度
	int setLength;							//集合长度

	int stringToInt(string& str);			//string类型的二进制字符串转换为十进制int
	string reverse(string);					//倒置
public:
	Head(vector<string>::iterator&);
	virtual string getSetType();			//判断集合类型 （在总头部里判断语言类型）
	vector<int> analyse();					//分析速配信息子分量
	string getAnalyseRule();				//返回解析规则字符串
	int getElementNum();					//计算集合包含的属性元素的个数

	/*get functions*/
	int getSubLength();						//返回长度值子分量长度
	int getSetLength();						//返回集合总长度
	vector<string>& get_Type();				//返回属性类型域
	vector<string>& get_Length();			//返回属性长度域
	vector<string>& get_Content();			//返回属性净荷域
};

class TotalHead:public Head
{
public:
	TotalHead(vector<string>::iterator head_it):Head(head_it){}
	virtual string getSetType();
};

class SetHead :public Head
{
public:
	SetHead(vector<string>::iterator head_it):Head(head_it){}
};
#endif
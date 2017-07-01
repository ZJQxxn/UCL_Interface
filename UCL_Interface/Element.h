//属性元素基类与子类的声明
#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <vector>
using std::string;
using std::vector;


class Element
{
private:
	int num;								//属性元素类别号
	vector<string> property_Type;			//属性类型（1字节）
	vector <string> property_Length;		//属性长度（4~7字节）
	vector <string> property_Content;		//属性净荷
	int subLength;							//长度值子分量长度
	int elementLength;						//属性元素总长度
	int stringToInt(string& str);			//string类型的二进制字符串转换为十进制int
	string reverse(string&);				//倒置
public:
	Element(vector<string>::iterator);

	/*不同属性元素的计算函数*/
	//vector<int> analyse();					//分析物理元素的速配信息子分量，返回的向量保存具有的物理元素的类别号
	int keywordsNum();						//计算内容关键词个数
	int authorNum();						//计算作者人数
	int authorCopNum();						//计算作者单位个数
	vector<int> entity();					//解析内容实体,并返回保存存在实体的序号
	int flagNum();							//计算内容标记的个数
	int relatedUCLNum();					//计算关联UCL个数
	string provenanceForm();				//解析内容出处
	int pathLength();						//计算传播路径的长度
	string signatureStandard();				//解析数字摘要的算法标准（适用于内容数字签名和UCL包数字签名）
	int responsibilityNum();				//计算内容责任链中责任主体的个数
	/*get functions*/
	int getNum();							//返回元素类别号
	int getSubLength();						//返回长度值子分量长度
	int getElementLength();					//返回元素总长度
	string getAnalyseRule();				//返回解析规则字符串
	vector<string>& get_Type();				//返回属性类型	
	vector<string>& get_Length();			//返回属性长度
	vector<string>& get_Content();			//返回属性净荷
};
#endif
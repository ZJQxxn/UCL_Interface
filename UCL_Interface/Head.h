//����ͷ�����������������
//���� Head ��ĳ�Ա�����ͳ�Ա����

#ifndef HEAD_H
#define HEAD_H
#include <string>
#include <vector>
using std::string;
using std::vector;

class Head
{
private:
	vector <string> property_Type;			//�������ͣ�1�ֽڣ�
	vector <string> property_Length;		//���Գ��ȣ�4~7�ֽڣ�
	vector <string> property_Content;		//���Ծ���
	int elementNum;							//����Ԫ�ظ���
	int subLength;							//����ֵ�ӷ�������
	int setLength;							//���ϳ���

	int stringToInt(string& str);			//string���͵Ķ������ַ���ת��Ϊʮ����int
	string reverse(string);					//����
public:
	Head(vector<string>::iterator&);
	virtual string getSetType();			//�жϼ������� ������ͷ�����ж��������ͣ�
	vector<int> analyse();					//����������Ϣ�ӷ���
	string getAnalyseRule();				//���ؽ��������ַ���
	int getElementNum();					//���㼯�ϰ���������Ԫ�صĸ���

	/*get functions*/
	int getSubLength();						//���س���ֵ�ӷ�������
	int getSetLength();						//���ؼ����ܳ���
	vector<string>& get_Type();				//��������������
	vector<string>& get_Length();			//�������Գ�����
	vector<string>& get_Content();			//�������Ծ�����
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
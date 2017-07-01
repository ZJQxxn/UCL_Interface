//����Ԫ�ػ��������������
#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <vector>
using std::string;
using std::vector;


class Element
{
private:
	int num;								//����Ԫ������
	vector<string> property_Type;			//�������ͣ�1�ֽڣ�
	vector <string> property_Length;		//���Գ��ȣ�4~7�ֽڣ�
	vector <string> property_Content;		//���Ծ���
	int subLength;							//����ֵ�ӷ�������
	int elementLength;						//����Ԫ���ܳ���
	int stringToInt(string& str);			//string���͵Ķ������ַ���ת��Ϊʮ����int
	string reverse(string&);				//����
public:
	Element(vector<string>::iterator);

	/*��ͬ����Ԫ�صļ��㺯��*/
	//vector<int> analyse();					//��������Ԫ�ص�������Ϣ�ӷ��������ص�����������е�����Ԫ�ص�����
	int keywordsNum();						//�������ݹؼ��ʸ���
	int authorNum();						//������������
	int authorCopNum();						//�������ߵ�λ����
	vector<int> entity();					//��������ʵ��,�����ر������ʵ������
	int flagNum();							//�������ݱ�ǵĸ���
	int relatedUCLNum();					//�������UCL����
	string provenanceForm();				//�������ݳ���
	int pathLength();						//���㴫��·���ĳ���
	string signatureStandard();				//��������ժҪ���㷨��׼����������������ǩ����UCL������ǩ����
	int responsibilityNum();				//������������������������ĸ���
	/*get functions*/
	int getNum();							//����Ԫ������
	int getSubLength();						//���س���ֵ�ӷ�������
	int getElementLength();					//����Ԫ���ܳ���
	string getAnalyseRule();				//���ؽ��������ַ���
	vector<string>& get_Type();				//������������	
	vector<string>& get_Length();			//�������Գ���
	vector<string>& get_Content();			//�������Ծ���
};
#endif
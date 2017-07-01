//UCL�������
#ifndef UCL_H
#define UCL_H
#include <vector>
#include <string>
using std::string;
using std::vector;

class UCL
{
private:
	vector <string> UCL_Code;							//����UCL Code����
	vector <string> UCL_Properties;						//����UCL Properties����	 
	string hexToBin(char *str);							//string���͵�һ��ʮ��������ת��Ϊstring���͵�һ����������
	void convert(string &original, vector <string>&UCL);//ת��ΪUCL
public:
	UCL(const string& filename);
	void readFromFile(const string& filename);			//
	/*get functions*/
	vector<string>& getCode();							//
	vector<string>& getProperties();					//
};
#endif
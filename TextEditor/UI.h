#pragma once
#include <string>

using namespace std;

class UI {
public:
	void save() const;														// ��content���ݱ��浽targetFilePath���ļ���
	string replace();															// ��dialogboxFilePath��Ӧ�����ݣ��൱�ڿ��滻�ı��ַ�����ȡ���滻content�����ؾ�content
	void replace(const string& content);							// �滻�ı��༭����contentΪ����content��δsave���ᱣ�浽�ļ��У�
	string getContent() const;
	void setTargetFilePath(const string& filePath);			// ����targetFilePath
	void setDialogboxFilePath(const string& filePath);	// ����dialogboxFilePath
	string getTargetFilePath() const;								// ��ȡĿ���ļ���·��
	string getDialogboxFilePath() const;							// ��ȡ�Ի����ļ���·�����Ի�������ݱ༭��replace���༭���в����ڱ༭������content������ʾ
private:
	string targetFilePath;							// ��ʾ��ǰ�༭����Ӧ���ļ����ļ�·��
	string dialogboxFilePath;					// ��ʾ�Ի����Ӧ���ļ����ļ�·��
	string content;									// ��ʾ��ǰ�༭�������ڵ��ļ�����
};
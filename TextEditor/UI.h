#pragma once
#include <string>

using namespace std;

class UI {
public:
	void save() const;														// 将content内容保存到targetFilePath的文件中
	string replace();															// 将dialogboxFilePath对应的内容（相当于可替换文本字符串）取出替换content，返回旧content
	void replace(const string& content);							// 替换文本编辑器的content为参数content（未save不会保存到文件中）
	string getContent() const;
	void setTargetFilePath(const string& filePath);			// 设置targetFilePath
	void setDialogboxFilePath(const string& filePath);	// 设置dialogboxFilePath
	string getTargetFilePath() const;								// 获取目标文件的路径
	string getDialogboxFilePath() const;							// 获取对话框文件的路径，对话框的内容编辑后replace到编辑器中才能在编辑器窗口content进行显示
private:
	string targetFilePath;							// 表示当前编辑器对应的文件的文件路径
	string dialogboxFilePath;					// 表示对话框对应的文件的文件路径
	string content;									// 表示当前编辑器窗口内的文件内容
};
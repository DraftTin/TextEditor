#include <iostream>
#include <fstream>
#include "UI.h"

using namespace std;

void UI::save() const {
	ofstream outfile(targetFilePath, ios::out);
	outfile << content;
	outfile.close();
}

string UI::replace() {
	ifstream infile;
	infile.open(dialogboxFilePath);
	if(!infile.good()) {
		ofstream outfile;
		outfile.open(dialogboxFilePath, ios::out);
		outfile.close();
	}
	char ch;
	string newContent;
	while (infile.get(ch)) {
		newContent.push_back(ch);
	}
	string oldContent = this->content;					// replaceǰ��¼���ε�����
	infile >> newContent;
	this->content = newContent;
	infile.close();
	return oldContent;
}

void UI::setTargetFilePath(const string& filePath) {
	this->targetFilePath = filePath;
	ifstream infile;
	infile.open(filePath);
	if (!infile.good()) {
		ofstream outfile;
		outfile.open(filePath, ios::out);
		outfile.close();
	}
	this->content.clear();			// ÿ�����������ļ�·��������ı�������ݲ����µ��ļ�������
	char ch;
	while (infile.get(ch)) {
		this->content.push_back(ch);
	}
	infile.close();
}

void UI::setDialogboxFilePath(const string& filePath) {
	this->dialogboxFilePath = filePath;
}

void UI::replace(const string& content) {
	this->content = content;
}

string UI::getContent() const {
	return content;
}

string UI::getTargetFilePath() const {
	return targetFilePath;
}

string UI::getDialogboxFilePath() const {
	return dialogboxFilePath;
}
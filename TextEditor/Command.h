#pragma once
#include <iostream>
#include <stack>
#include "UI.h"

using namespace std;

// execute ִ������
// undo 	 ����������������������������ܳ�������replace���򷵻�1��������ܳ�������save���򷵻�0
// descri	������������
class Command {
public:
	virtual void execute() = 0;
	virtual int undo() = 0;
	virtual string descri() const = 0;
};

class MnuSaveCommand : public Command {
public:
	MnuSaveCommand(UI* ui_) : ui(ui_) {}
public:
	virtual void execute() {
		ui->save();
	}
	virtual int undo() {
		// save����û��undo����
		return 0;
	}
	virtual string descri() const { return "ʹ������ѡ����б���....."; }
private:
	UI* ui;
};

class MnuReplaceCommand : public Command {
public:
	MnuReplaceCommand(UI* ui_) : ui(ui_) {}
public:
	virtual void execute() {
		oldContents.push(ui->replace());
	}
	virtual int undo() {
		cout << "ʹ������ѡ�����....." << endl;
		ui->replace(oldContents.top());
		oldContents.pop();
		return 1;
	}
	virtual string descri() const { return "ʹ������ѡ���滻....."; }
private:
	UI* ui;
	stack<string> oldContents;
};

class ToolSaveCommand : public Command {
public:
	ToolSaveCommand(UI* ui_) : ui(ui_) {}
public:
	virtual void execute() {
		ui->save();
	}
	virtual int undo() {
		// save����û��undo����
		return 0;
	}
	virtual string descri() const { return "ʹ�ù���ѡ���....."; }
private:
	UI* ui;
};

class ToolReplaceCommand : public Command {
public:
	ToolReplaceCommand(UI* ui_) : ui(ui_) {}
public:
	virtual void execute() {
		oldContents.push(ui->replace());
	}
	virtual int undo() {
		cout << "ʹ�ù���ѡ�����....." << endl;
		ui->replace(oldContents.top());
		oldContents.pop();
		return 1;
	}
	virtual string descri() const { return "ʹ�ù���ѡ���滻....."; }
private:
	UI* ui;
	stack<string> oldContents;
};

class PopSaveCommand : public Command {
public:
	PopSaveCommand(UI* ui_) : ui(ui_) {}
public:
	virtual void execute() {
		ui->save();
	}
	virtual int undo() {
		// save����û��undo����
		return 0;
	}
	virtual string descri() const { return "ʹ�õ������ڱ���....."; }
private:
	UI* ui;
};

class PopReplaceCommand : public Command {
public:
	PopReplaceCommand(UI* ui_) : ui(ui_) {}
public:
	virtual void execute() {
		oldContents.push(ui->replace());
	}
	virtual int undo() {
		cout << "ʹ�õ������ڻ���...." << endl;
		ui->replace(oldContents.top());
		oldContents.pop();
		return 1;
	}
	virtual string descri() const { return "ʹ�õ��������滻...."; }
private:
	UI* ui;
	stack<string> oldContents;
};

class EmptyCommand : public Command {
public:
	virtual void execute() {}
	virtual int undo() { return 0; }
	virtual string descri() const { return "������"; }
};




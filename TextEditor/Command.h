#pragma once
#include <iostream>
#include <stack>
#include "UI.h"

using namespace std;

// execute 执行命令
// undo 	 撤回命令，有两种情况，如果该命令能撤销，如replace，则返回1，如果不能撤销，如save，则返回0
// descri	返回命令描述
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
		// save命令没有undo操作
		return 0;
	}
	virtual string descri() const { return "使用下拉选项进行保存....."; }
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
		cout << "使用下拉选项回退....." << endl;
		ui->replace(oldContents.top());
		oldContents.pop();
		return 1;
	}
	virtual string descri() const { return "使用下拉选项替换....."; }
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
		// save命令没有undo操作
		return 0;
	}
	virtual string descri() const { return "使用工具选项保存....."; }
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
		cout << "使用工具选项回退....." << endl;
		ui->replace(oldContents.top());
		oldContents.pop();
		return 1;
	}
	virtual string descri() const { return "使用工具选项替换....."; }
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
		// save命令没有undo操作
		return 0;
	}
	virtual string descri() const { return "使用弹出窗口保存....."; }
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
		cout << "使用弹出窗口回退...." << endl;
		ui->replace(oldContents.top());
		oldContents.pop();
		return 1;
	}
	virtual string descri() const { return "使用弹出窗口替换...."; }
private:
	UI* ui;
	stack<string> oldContents;
};

class EmptyCommand : public Command {
public:
	virtual void execute() {}
	virtual int undo() { return 0; }
	virtual string descri() const { return "空命令"; }
};




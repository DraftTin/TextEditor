#pragma once
#include <vector>
#include <stack>

using namespace std;

class Command;
class UIController {
public: 
	UIController();
	~UIController();
	void setMnuCommand(int no, Command* cmd);
	void setToolCommand(int no, Command* cmd);
	void setPopCommand(int no, Command* cmd);
	void mnuCommandSended(int no);
	void toolCommandSended(int no);
	void popCommandSended(int no);
	void undoCommandSended();
	void showMnuCmd() const;
	void showToolCmd() const;
	void showPopCmd() const;
	void clearUndoLog();
private:
	vector<Command*> mnuList;
	vector<Command*> toolList;
	vector<Command*> popList;
	stack<Command*> undoStack;				// 非指针保存命令栈，防止命令保存的内容被替换
};
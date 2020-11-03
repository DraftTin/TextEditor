#include "Invoker.h"
#include "Command.h"

UIController::UIController() {
	// 最后一个是空命令
	mnuList = vector<Command*>(2, nullptr);
	toolList = vector<Command*>(2, nullptr);
	popList = vector<Command*>(2, nullptr);
	for (int i = 0; i < mnuList.size(); ++i) {
		mnuList[i] = new EmptyCommand();
		toolList[i] = new EmptyCommand();
		popList[i] = new EmptyCommand();
	}
}

UIController::~UIController() {
	for (int i = 0; i < mnuList.size(); ++i) {
		delete mnuList[i];
		delete toolList[i];
		delete popList[i];
	}
}

void UIController::setMnuCommand(int no, Command* cmd) {
	if (no < 0 || no >= mnuList.size()) {
		return;
	}
	mnuList[no] = cmd;
}

void UIController::setToolCommand(int no, Command* cmd) {
	if (no < 0 || no >= toolList.size()) {
		return;
	}
	toolList[no] = cmd;
}

void UIController::setPopCommand(int no, Command* cmd) {
	if (no < 0 || no >= popList.size()) {
		return;
	}
	popList[no] = cmd;
}


void UIController::mnuCommandSended(int no)  {
	if (no < 0 || no >= mnuList.size()) {
		return;
	}
	mnuList[no]->execute();
	undoStack.push(mnuList[no]);
}

void UIController::toolCommandSended(int no) {
	if (no < 0 || no >= toolList.size()) {
		return;
	}
	toolList[no]->execute();
	undoStack.push(toolList[no]);
}

void UIController::popCommandSended(int no) {
	if (no < 0 || no >= popList.size()) {
		return;
	}
	popList[no]->execute();
	undoStack.push(popList[no]);
}

// 撤销上一个命令
void UIController::undoCommandSended() {
	if (undoStack.empty()) return;
	Command* command;
	while (!undoStack.empty()) {
		// 一直undo，直到找到成功undo的命令为止
		command = undoStack.top();
		int flag = command->undo();
		undoStack.pop();
		if (flag == 1) break;
	}
}

void UIController::showMnuCmd() const {
	for (int i = 0; i < mnuList.size(); ++i) {
		cout << i << ". " << mnuList[i]->descri();
	}
	cout << mnuList.size() << ". " << "返回" << endl;
}

void UIController::showToolCmd() const {
	for (int i = 0; i < toolList.size(); ++i) {
		cout << i << ". " << toolList[i]->descri();
	}
	cout << toolList.size() << ". " << "返回" << endl;
}

void UIController::showPopCmd() const {
	for (int i = 0; i < popList.size(); ++i) {
		cout << i << ". " << popList[i]->descri();
	}
	cout << popList.size() << ". " << "返回" << endl;
}

void UIController::clearUndoLog() {
	while (!undoStack.empty()) undoStack.pop();
}
#include <iostream>
#include <fstream>
#include "PlayWindow.h"
#include "Invoker.h"
#include "Command.h"

using namespace std;

PlayWindow& PlayWindow::getInstance() {
	static shared_ptr<PlayWindow> instance;
	if (!instance) {
		instance = shared_ptr<PlayWindow>();;
	}
	return *instance;
}

void PlayWindow::run() {
	// 默认运行文本编辑文件
	UI* uiReceiver = new UI();
	// 默认路径D:\\untitle.txt
	uiReceiver->setTargetFilePath("D:\\untitle.txt");
	uiReceiver->setDialogboxFilePath("D:\\dialogbox.txt");
	UIController ui;
	MnuSaveCommand* cmd1 = new MnuSaveCommand(uiReceiver);
	MnuReplaceCommand* cmd2 = new MnuReplaceCommand(uiReceiver);
	ToolSaveCommand* cmd3 = new ToolSaveCommand(uiReceiver);
	ToolReplaceCommand* cmd4 = new ToolReplaceCommand(uiReceiver);
	PopSaveCommand* cmd5 = new PopSaveCommand(uiReceiver);
	PopReplaceCommand* cmd6 = new PopReplaceCommand(uiReceiver);
	// 设计命令按键
	ui.setMnuCommand(0, cmd1);
	ui.setMnuCommand(1, cmd2);
	ui.setToolCommand(0, cmd3);
	ui.setToolCommand(1, cmd4);
	ui.setPopCommand(0, cmd5);
	ui.setPopCommand(1, cmd6);
	
	
	// （编辑对话框的内从需要替换到文本框中才能进行显示）
	while (true) {
		cout << "当前编辑的文件路径：" << uiReceiver->getTargetFilePath() << endl;
		cout << "1. 显示下拉菜单" << endl;
		cout << "2. 显示工具栏" << endl;
		cout << "3. 显示弹出菜单" << endl;
		cout << "4. 编辑对话框" << endl;
		cout << "5. 查看文本框内容" << endl;
		cout << "6. 查看目标文件内容" << endl;
		cout << "7. 回退replace操作" << endl;
		cout << "8. 重新设置目标文件的路径" << endl;
		cout << "0.  退出" << endl;
		cout << "选择: ";
		int choice;
		cin >> choice;
		if (choice <= 0 || choice >= 9) {
			break;
		}
		if (choice == 1) {
			ui.showMnuCmd();
			int tmp;
			cin >> tmp;
			ui.mnuCommandSended(tmp);
		}
		else if (choice == 2) {
			ui.showToolCmd();
			int tmp;
			cin >> tmp;
			ui.toolCommandSended(tmp);
		}
		else if (choice == 3) {
			ui.showPopCmd();
			int tmp;
			cin >> tmp;
			ui.popCommandSended(tmp);
		}
		else if(choice == 4) {
			cout << "文本内容: ";
			string content;
			char c;
			c = getchar();	// 读取第一个换行符
			while ((c = getchar()) != '#') {
				content.push_back(c);
			}
			cout << "##########" << endl;
			cout << content << endl;
			cout << "##########" << endl;
			ofstream outfile;
			outfile.open(uiReceiver->getDialogboxFilePath());
			outfile << content;
			outfile.close();
		}
		else if (choice == 5) {
			cout << "文本框内容：" << endl;
			string textContent = uiReceiver->getContent();
			cout << textContent << endl;
		}
		else if (choice == 6) {
			ifstream infile;
			infile.open(uiReceiver->getTargetFilePath());
			cout << "目标文件内容：" << endl;
			if (infile.good()) {
				char ch;
				while (infile.get(ch)) {
					cout << ch;
				}
			}
			cout << endl;
			infile.close();
		}
		else if (choice == 7) {
			ui.undoCommandSended();
		}
		else if (choice == 8) {
			cout << "请输入文件路径: ";
			string filePath;
			cin >> filePath;
			uiReceiver->setTargetFilePath(filePath);
			ui.clearUndoLog();
			// 清空命令的内容
		}
	}
	delete uiReceiver;
}
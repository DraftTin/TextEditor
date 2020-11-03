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
	// Ĭ�������ı��༭�ļ�
	UI* uiReceiver = new UI();
	// Ĭ��·��D:\\untitle.txt
	uiReceiver->setTargetFilePath("D:\\untitle.txt");
	uiReceiver->setDialogboxFilePath("D:\\dialogbox.txt");
	UIController ui;
	MnuSaveCommand* cmd1 = new MnuSaveCommand(uiReceiver);
	MnuReplaceCommand* cmd2 = new MnuReplaceCommand(uiReceiver);
	ToolSaveCommand* cmd3 = new ToolSaveCommand(uiReceiver);
	ToolReplaceCommand* cmd4 = new ToolReplaceCommand(uiReceiver);
	PopSaveCommand* cmd5 = new PopSaveCommand(uiReceiver);
	PopReplaceCommand* cmd6 = new PopReplaceCommand(uiReceiver);
	// ��������
	ui.setMnuCommand(0, cmd1);
	ui.setMnuCommand(1, cmd2);
	ui.setToolCommand(0, cmd3);
	ui.setToolCommand(1, cmd4);
	ui.setPopCommand(0, cmd5);
	ui.setPopCommand(1, cmd6);
	
	
	// ���༭�Ի�����ڴ���Ҫ�滻���ı����в��ܽ�����ʾ��
	while (true) {
		cout << "��ǰ�༭���ļ�·����" << uiReceiver->getTargetFilePath() << endl;
		cout << "1. ��ʾ�����˵�" << endl;
		cout << "2. ��ʾ������" << endl;
		cout << "3. ��ʾ�����˵�" << endl;
		cout << "4. �༭�Ի���" << endl;
		cout << "5. �鿴�ı�������" << endl;
		cout << "6. �鿴Ŀ���ļ�����" << endl;
		cout << "7. ����replace����" << endl;
		cout << "8. ��������Ŀ���ļ���·��" << endl;
		cout << "0.  �˳�" << endl;
		cout << "ѡ��: ";
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
			cout << "�ı�����: ";
			string content;
			char c;
			c = getchar();	// ��ȡ��һ�����з�
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
			cout << "�ı������ݣ�" << endl;
			string textContent = uiReceiver->getContent();
			cout << textContent << endl;
		}
		else if (choice == 6) {
			ifstream infile;
			infile.open(uiReceiver->getTargetFilePath());
			cout << "Ŀ���ļ����ݣ�" << endl;
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
			cout << "�������ļ�·��: ";
			string filePath;
			cin >> filePath;
			uiReceiver->setTargetFilePath(filePath);
			ui.clearUndoLog();
			// ������������
		}
	}
	delete uiReceiver;
}
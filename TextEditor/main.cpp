#include "PlayWindow.h"
using namespace std;

int main() {
	PlayWindow& window = PlayWindow::getInstance();
	window.run();
	return 0;
}
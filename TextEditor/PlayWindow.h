#pragma once
#include "UI.h"

class PlayWindow {
public:
	static PlayWindow& getInstance();
private:
	PlayWindow() {}
	PlayWindow(const PlayWindow&) = delete;
	PlayWindow& operator=(const PlayWindow&) = delete;
public:
	void run();
};
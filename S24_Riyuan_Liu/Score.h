#pragma once
#include <vector>
#include "Rogue.h"
class score {
public:
	score();
	void Render(int x, int y);
	void addPoint(int x);
private:
	std::vector<std::string> filepath;
	int point=0;
};
#pragma once
#include"base/gameNode.h"

class WarriorInven : public gameNode,public singletonBase<WarriorInven>
{
private:
	image* warriorInvenImg;
	RECT warriorInvenRC;

	int vectorNum;
protected:
	void add_image();
	void set_vectorNum();
public:
	WarriorInven();
	~WarriorInven();

	HRESULT init();
	void release();
	void update();
	void render();

	void set_warriorInvenRC(int x, int y);
};

#define WInven WarriorInven::getSingleton()
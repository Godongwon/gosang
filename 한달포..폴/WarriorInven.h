#pragma once
#include"base/gameNode.h"

class WarriorInven : public gameNode,public singletonBase<WarriorInven>
{
private:
	image* warriorInvenImg;
	RECT warriorInvenRC;

	RECT WeaponitemRECT;
	RECT ArmeritemRECT;

	int vectorNum;
	bool isitemMove;
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

	int get_vectorNum() { return vectorNum; }
	void itemRender();
	void set_warriorInvenRC(int x, int y);
	void set_isitemMove(bool is) { isitemMove = is; }
	RECT get_warriorInvenRC() {	return warriorInvenRC;}
};

#define WInven WarriorInven::getSingleton()
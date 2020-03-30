#pragma once
#include "base/gameNode.h"
#include "warriorHead.h"
class monk : public gameNode
{

public:
	monk();
	~monk();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	
	void add_monkImg();
	void release_monkImg();
	//void add_monk();

};


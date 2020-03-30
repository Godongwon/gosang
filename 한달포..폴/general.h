#pragma once
#include"base/gameNode.h"
#include "warriorHead.h"
class general :public gameNode
{

public:
	general();
	~general();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void add_generalImg();
	void release_generalImg();


};


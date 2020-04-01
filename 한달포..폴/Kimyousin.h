#pragma once
#include "base/gameNode.h"
#include"warriorHead.h"
class Kimyousin :public gameNode
{
private :
	
public:
	Kimyousin();
	~Kimyousin();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void add_kimyouSinImg();
	void release_kinyouSinImg();

};


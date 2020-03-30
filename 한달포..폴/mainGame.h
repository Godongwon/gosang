#pragma once
#include "base/gameNode.h"
#include "Maptool.h"
#include "TwonScene.h"
#include "WarScene.h"
#include "startScene.h"

class mainGame : public gameNode
{
	
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


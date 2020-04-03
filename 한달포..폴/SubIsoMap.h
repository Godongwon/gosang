#pragma once
#include"base/gameNode.h"
#include"IsoTile.h"

class SubIsoMap : public gameNode
{
private:
	bool isDebug;

	
	int _currentTile;
	RECT rc[TILE_SIZE_X][TILE_SIZE_Y];
	RECT tree;
	int treeNum;

	int _frameX, _frameY;

public:
	SubIsoMap();
	~SubIsoMap();


	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

};


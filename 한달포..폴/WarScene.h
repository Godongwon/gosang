#pragma once
#include"base/gameNode.h"
#include "IsoTile.h"
#include"monster.h"
#include "battle.h"

class WarScene : public gameNode
{
private:
	tagTILE _tileMap[TILE_COUNT_X][TILE_COUNT_Y];

	monster* _monsterChild;
	battle* _battle;

	image*	_warSceneWindowImg;
	RECT	_warSceneWindowRC;

	image* _buttonImg;
	RECT _buttonRC;
	bool _isPush;

	bool _isplayerWin;
	bool _isMonsterWin;


public:
	WarScene();
	~WarScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void warload();
	virtual void Draw();
	void Collition();

	void Warrior_Atk();
	void Monster_Atk();

	
};


#pragma once
#include "base/gameNode.h"
#include "IsoTile.h"
#include"townMonster.h"
#include"store.h"
#include"warriorStore.h"
class TwonScene : public gameNode
{
private:
	tagTILE _tileMap[TILE_COUNT_X][TILE_COUNT_Y];

	townMonster* _townMonster;
	store* _store;
	warriorStore* _warriorStore;
	bool istextOut;
	int _textCount;

public:
	TwonScene();
	~TwonScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);

	virtual void townload();
	virtual void Draw();
	virtual void monsterturn();

	tagTILE get_tileMap(int x, int y) { return _tileMap[x][y]; }
	
	
};


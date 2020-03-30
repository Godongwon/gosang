#pragma once
#include"base/gameNode.h"
#include "IsoTile.h"

#define BIGNUM 5000	

enum ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,	//검색
	ASTAR_STATE_FOUND,		//발견
	ASTAR_STATE_NOWAY,		//길없음
	ASTAR_STATE_END

};
class Astar : public gameNode, public singletonBase<Astar>
{
private:
	tagTILE _AstarTile[TILE_COUNT_X][TILE_COUNT_Y];
	vector<tagTILE*> _openList;
	vector<tagTILE*> _closeList;


	ASTAR_STATE _astarState;
	COLORREF _selectTypeColor;

	int _startX, startY; //시작지점의 인덱스
	int _endX, _endY;	//도착지점의 인덱스
	int _lastIndex;		//나중에 추가된 클로즈 리스트의 인덱스

	bool _startPointset;	//시작지점이 배치 되었냐
	bool _endPointset;		//도착지점이 배치 되었냐

	int ci;
	int cg;
	int cj;


	HBRUSH newBrush, oldBrush;
	HFONT newFont, oldFont;
protected:

	void tileComposition();
	void addOpenList();
	void calculateH();
	void calculateF();
	void addCloseList();
	void checkArrive();
	void showWay(tagTILE* tile);

public:
	Astar();
	~Astar();

	HRESULT init();
	void release();
	void update();
	void render();



	void set_endXY(int x, int y)
	{
		_endX = x;
		_endY = y;
	}

};

#define ASTAR Astar::getSingleton()
#pragma once
#include"base/gameNode.h"
#include "IsoTile.h"

#define BIGNUM 5000	

enum ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,	//�˻�
	ASTAR_STATE_FOUND,		//�߰�
	ASTAR_STATE_NOWAY,		//�����
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

	int _startX, startY; //���������� �ε���
	int _endX, _endY;	//���������� �ε���
	int _lastIndex;		//���߿� �߰��� Ŭ���� ����Ʈ�� �ε���

	bool _startPointset;	//���������� ��ġ �Ǿ���
	bool _endPointset;		//���������� ��ġ �Ǿ���

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
#include "stdafx.h"
#include "Astar.h"
#include "IsoMap.h"

Astar::Astar()
{
}


Astar::~Astar()
{
	
}

HRESULT Astar::init()
{
	_astarState = ASTAR_STATE_END;
	_selectTypeColor = RGB(255, 255, 255);
	
	_startPointset = false;
	_endPointset = false;
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			
			_AstarTile[i][j] = ISOMAP->get_tileMap(i, j);
			_AstarTile[i][j].F = BIGNUM;
			_AstarTile[i][j].H = 0;
			_AstarTile[i][j].i = i;
			_AstarTile[i][j].j = j;
				
		}
	}
	

	return S_OK;
}

void Astar::release()
{
}

void Astar::update()
{
	
	addOpenList();
	calculateH();
	calculateF();
	addCloseList();
	checkArrive();
}

void Astar::render()
{
}

void Astar::tileComposition()
{
	/*
	bool walkable;			//�������� �ִ��� ����
	bool listOn;			//openlist�� �߰� �Ǿ����� ����
	*/
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			for (int z = 0; z < TILE_MAX; z++)
			{
				if (_AstarTile[i][j].tileKind[z] == TILEKIND_NONE)
				{
					_AstarTile[i][j].walkable = false;
					_AstarTile[i][j].liston = false;
				}
				else if (_AstarTile[i][j].tileKind[z] == TILEKIND_NOMAL)
				{
					_AstarTile[i][j].walkable = true;
					_AstarTile[i][j].liston = true;
				}
				else if (_AstarTile[i][j].tileKind[z] == TILEKIND_OBJECT)
				{
					_AstarTile[i][j].walkable = false;
					_AstarTile[i][j].liston = false;
				}
				else if (_AstarTile[i][j].tileKind[z] == TILEKIND_SPEEDDOWN)
				{
					_AstarTile[i][j].walkable = true;
					_AstarTile[i][j].liston = true;
				}
			}
		}//for(TILE_COUNT_Y)end
	}//for(TILE_COUNT_X)end
	_astarState = ASTAR_STATE_SEARCHING;
	_lastIndex = 0;
}



void Astar::addOpenList()
{
	ci = _closeList[_lastIndex]->i;
	cj = _closeList[_lastIndex]->j;
	cg = _closeList[_lastIndex]->G;

	if (ci!= 0)//0���� ���� �ƴϸ� ��ܶ��� ���
	{
		if (_AstarTile[ci - 1][cj].walkable)
		{
			if (!_AstarTile[ci][cj - 1].liston)
			{
				_AstarTile[ci][cj - 1].liston = true;
				_AstarTile[ci][cj - 1].color = RGB(220, 255, 220);
				_AstarTile[ci][cj - 1].G = cg + 10;
				_AstarTile[ci][cj - 1].parent = _closeList[_lastIndex];
				_openList.push_back(&_AstarTile[ci][cj - 1]);
			}
			else
			{
				if (cg + 10 < _AstarTile[ci][cj - 1].G)
				{
					_AstarTile[ci][cj - 1].G = cg + 10;
					_AstarTile[ci][cj - 1].parent = _closeList[_lastIndex];
				}
			}
		}//if end
		if (cj != 0)
		{
			if (_AstarTile[ci - 1][cj - 1].walkable&&_AstarTile[ci][cj].walkable&&_AstarTile[ci][cj - 1].walkable)
			{
				if (!_AstarTile[ci - 1][cj - 1].walkable)
				{
					_AstarTile[ci - 1][cj - 1].liston = true;
					_AstarTile[ci - 1][cj - 1].color = RGB(220, 255, 220);
					_AstarTile[ci - 1][cj - 1].G = cg + 14;
					_AstarTile[ci - 1][cj - 1].parent = _closeList[_lastIndex];
					_openList.push_back(&_AstarTile[ci - 1][cj - 1]);
				}
				else
				{
					if (cg + 14 < _AstarTile[ci - 1][cj - 1].G)
					{
						_AstarTile[ci - 1][cj - 1].G = cg + 14;
						_AstarTile[ci - 1][cj - 1].parent = _closeList[_lastIndex];
					}
				}
			}
		}//if end
		if (cj != TILE_COUNT_X - 1)//���� : ������ ���� �ƴ϶��
		{
			if (_AstarTile[ci][cj + 1].walkable)//����Ÿ���� �̵� �����ϴٸ�
			{
				_AstarTile[ci][cj + 1].liston - true;
				_AstarTile[ci][cj + 1].color = RGB(220, 255, 220);
				_AstarTile[ci][cj + 1].G = cg + 10;
				_AstarTile[ci][cj + 1].parent = _closeList[_lastIndex];
				_openList.push_back(&_AstarTile[ci][cj + 1]);
			}
			else
			{
				if (cg + 10 < _AstarTile[ci][cj + 1].G)
				{
					_AstarTile[ci][cj + 1].G = cg + 10;
					_AstarTile[ci][cj + 1].parent = _closeList[_lastIndex];
				}
			}
		}//ifend
	}//if (ci!= 0) end

	if (cj != 0)//���� : 0���� ���� �ƴ϶��?
	{
		if (_AstarTile[ci][cj - 1].walkable)
		{
			if (!_AstarTile[ci][cj - 1].liston)
			{
				_AstarTile[ci][cj - 1].liston = true;
				_AstarTile[ci][cj - 1].color = RGB(220, 255, 220);
				_AstarTile[ci][cj - 1].G = cg + 10;
				_AstarTile[ci][cj - 1].parent = _closeList[_lastIndex];
				_openList.push_back(&_AstarTile[ci][cj - 1]);
			}
			else
			{
				if (cg + 10 < _AstarTile[ci][cj - 1].G)
				{
					_AstarTile[ci][cj - 1].G = cg + 10;
					_AstarTile[ci][cj - 1].parent = _closeList[_lastIndex];
				}
			}
		}

		if (cj != TILE_COUNT_X - 1)//���������� �ƴ϶�� �ϴ� ���� ���
		{
			if (_AstarTile[ci][cj + 1].walkable)
			{
				if (_AstarTile[ci][cj + 1].liston)
				{
					_AstarTile[ci][cj + 1].liston = true;
					_AstarTile[ci][cj + 1].color = RGB(220, 255, 220);
					_AstarTile[ci][cj + 1].G = cg + 10;
					_AstarTile[ci][cj + 1].parent = _closeList[_lastIndex];
					_openList.push_back(&_AstarTile[ci][cj + 1]);
				}
				else
				{
					if (cg + 10 < _AstarTile[ci][cj + 1].G)
					{
						_AstarTile[ci][cj + 1].G = cg + 10;
						_AstarTile[ci][cj + 1].parent = _closeList[_lastIndex];
					}
				}
			}
		}//if end

		if (cj != TILE_COUNT_Y - 1)//���������� �ƴ϶�� �ϴ� ���� ���
		{
			if (_AstarTile[ci + 1][cj].walkable)
			{
				if (_AstarTile[ci + 1][cj].liston)
				{
					_AstarTile[ci + 1][cj].liston = true;
					_AstarTile[ci + 1][cj].color = RGB(220, 255, 220);
					_AstarTile[ci + 1][cj].G = cg + 10;
					_AstarTile[ci + 1][cj].parent = _closeList[_lastIndex];
					_openList.push_back(&_AstarTile[ci + 1][cj]);
				}
				else
				{
					if (cg + 10 < _AstarTile[ci + 1][cj].G)
					{
						_AstarTile[ci + 1][cj].G = cg + 10;
						_AstarTile[ci + 1][cj].parent = _closeList[_lastIndex];
					}
				}
			}
		}//if end

		if (cj != 0)//���ϴ� : 0���� ���� �ƴ϶��
		{
			if (_AstarTile[ci + 1][cj - 1].walkable&&_AstarTile[ci + 1][cj].walkable&&_AstarTile[ci][cj - 1].walkable)
			{
				if (!_AstarTile[ci + 1][cj - 1].liston)
				{
					_AstarTile[ci + 1][cj - 1].liston = true;
					_AstarTile[ci + 1][cj - 1].color = RGB(220, 255, 220);
					_AstarTile[ci + 1][cj - 1].G = cg + 14;
					_AstarTile[ci + 1][cj - 1].parent = _closeList[_lastIndex];
					_openList.push_back(&_AstarTile[ci + 1][cj - 1]);
				}
				else
				{
					if (cg + 14 < _AstarTile[ci + 1][cj - 1].G)
					{
						_AstarTile[ci + 1][cj - 1].G = cg + 14;
						_AstarTile[ci + 1][cj - 1].parent = _closeList[_lastIndex];
					}
				}
			}
		}//ifend
		if (cj != TILE_COUNT_X - 1)//���ϴ� : ������ ���� �ƴ϶��
		{
			if (_AstarTile[ci + 1][cj + 1].walkable&&_AstarTile[ci + 1][cj].walkable&&_AstarTile[ci][cj + 1].walkable)
			{
				if (!_AstarTile[ci + 1][cj + 1].liston)
				{
					_AstarTile[ci + 1][cj + 1].liston = true;
					_AstarTile[ci + 1][cj + 1].color = RGB(220, 255, 220);
					_AstarTile[ci + 1][cj + 1].G = cg + 14;
					_AstarTile[ci + 1][cj + 1].parent = _closeList[_lastIndex];
					_openList.push_back(&_AstarTile[ci + 1][cj + 1]);
				}
				else
				{
					if (cg + 14 < _AstarTile[ci + 1][cj + 1].G)
					{
						_AstarTile[ci + 1][cj + 1].G = cg + 14;
						_AstarTile[ci + 1][cj + 1].parent = _closeList[_lastIndex];
					}
				}
			}
		}//ifend
	}
}

void Astar::calculateH()
{
	for (int i = 0; i < _openList.size(); i++)
	{
		int vertical = (_endX - _openList[i]->j) * 10;
		int horizontal = (_endY - _openList[i]->i) * 10;

		if (vertical < 0)vertical *= -1;
		if (horizontal < 0)horizontal *= -1;

		_openList[i]->H = vertical + horizontal;
		
	}
}

void Astar::calculateF()
{
	for (int i = 0; i < _openList.size(); i++)
	{
		_openList[i]->F = _openList[i]->G + _openList[i]->H;
	}
}

void Astar::addCloseList()
{
	if (_openList.size() == 0)
	{
		_astarState = ASTAR_STATE_NOWAY;
		return;
	}
	int index = 0;
	int lowest = BIGNUM;

	for (int i = 0; i < _openList.size(); i++)
	{
		if (_openList[i]->F < lowest)
		{
			lowest = _openList[i]->F;
			index = i;
		}
	}
	_openList[index]->color = RGB(180, 180, 255);
	_closeList.push_back(_openList[index]);
	_openList.erase(_openList.begin() + index);
	_lastIndex++;
}

void Astar::checkArrive()
{
	if (_closeList[_lastIndex]->i == _endY && _closeList[_lastIndex]->j == _endX)
	{
		_astarState = ASTAR_STATE_FOUND;
		_closeList[_lastIndex]->color = RGB(255, 100, 100);
		showWay(_closeList[_lastIndex]);
	}
}

void Astar::showWay(tagTILE * tile)
{
	if (!(tile->i == _endY && tile->j == _endX))//���������� �ƴ϶��
	tile->color = RGB(255, 180, 180);
	tile = tile->parent;//Ÿ���� �θ� �����ؼ�showWay�Լ��� �ٽ� �ִ´�.

	if (tile->parent == NULL)//Ÿ���� �θ� ���������̸� �׸� ������
		return;
	else
		showWay(tile);//�ٽ� ȣ��
}

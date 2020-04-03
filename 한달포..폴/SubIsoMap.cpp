#include "stdafx.h"
#include "SubIsoMap.h"


SubIsoMap::SubIsoMap()
{
}


SubIsoMap::~SubIsoMap()
{
}

HRESULT SubIsoMap::init()
{
	
	for (int i = 0; i < TILE_SIZE_X; i++)
	{
		for (int j = 0; j < TILE_SIZE_Y; j++)
		{
			rc[i][j] = RectMake(
				SUBWINSIZEX / TILE_SIZE_X * i,
				300 / TILE_SIZE_Y * j + 200,
				SUBWINSIZEX / TILE_SIZE_X, 300 / TILE_SIZE_Y);
		}
	}
	tree = RectMake(0, 300, 160, 128);
	treeNum = 0;
	int currentTile = 0;

	isDebug = false;


	return S_OK;
}

void SubIsoMap::release()
{
}

void SubIsoMap::update()
{
	if (SUBWIN->getFrameIndex() != 3)
	{
		if (SUBWIN->getIsActive() && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			
			for (int i = 0; i < TILE_SIZE_Y; i++)
			{
				for (int j = 0; j < TILE_SIZE_X; j++)
				{
					if (PtInRect(&rc[j][i], SUBWIN->getSubWinMousePos()))
					{
						SUBWIN->setFramePoint(PointMake(j, i));
					}
				}
			}
		}
			
	}
	else
	{
		if (SUBWIN->getIsActive()&&KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			if (treeNum < 5)
			{
				treeNum += 1;
			}
		}
		else if (SUBWIN->getIsActive()&&KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			if (treeNum >0)
			{
				treeNum -= 1;
			}
		}

		if (SUBWIN->getIsActive() && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&tree, SUBWIN->getSubWinMousePos()))
			{
				SUBWIN->setFramePoint(PointMake(treeNum,0));
			}
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
	{
		isDebug = !isDebug;
	}
	

}

void SubIsoMap::render(HDC hdc)
{
	if (isDebug)
	{
		for (int i = 0; i < TILE_SIZE_X; i++)
		{
			for (int j = 0; j < TILE_SIZE_Y; j++)
			{
				if (SUBWIN->getFrameIndex() != 3)
				{
					RectangleMake(hdc, rc[i][j]);
				}
				else
				{
					RectangleMake(hdc, tree);

				}
			}
		}
	}
	switch (SUBWIN->getFrameIndex())
	{
	case 0:
		
		for (int i = 0; i < TILE_SIZE_Y; i++)
		{
			for (int j = 0; j < TILE_SIZE_X; j++)
			{
				IMAGEMANAGER->findImage("Mountin")->frameRender(hdc, rc[j][i].left, rc[j][i].top, j, i);
			}
		}
		break;
	case 1:
		for (int i = 0; i < TILE_SIZE_Y; i++)
		{
			for (int j = 0; j < TILE_SIZE_X; j++)
			{
				IMAGEMANAGER->findImage("Ground")->frameRender(hdc, rc[j][i].left, rc[j][i].top, j, i);
			}
		}
		
		break;
	case 2:
		for (int i = 0; i < TILE_SIZE_Y; i++)
		{
			for (int j = 0; j < TILE_SIZE_X; j++)
			{
				IMAGEMANAGER->findImage("Water")->frameRender(hdc, rc[j][i].left, rc[j][i].top, j, i);
			}
		}
		
		break;
	case 3:
		
		IMAGEMANAGER->findImage("Tree")->frameRender(hdc, tree.left, tree.top, treeNum, 0);
		break;

		
	}

	

}

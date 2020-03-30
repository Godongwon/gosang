#include "stdafx.h"
#include "IsoMap.h"


IsoMap::IsoMap()
{
}


IsoMap::~IsoMap()
{
}

HRESULT IsoMap::init()
{
	_isoX = 0;
	_isoY = 0;
	_center = 0;
	memset(_tileMap, 0, sizeof(_tileMap));

	CAMERAMANAGER->setCameraCenter(PointMake(INIT_X, INIT_Y));


	_isDebug = true;
	_currentCTRL = CTRL_DRAW;
	MapSetup();

	LeftTop();
	DrawRhombus();

	return S_OK;
}
void IsoMap::release()
{
}

void IsoMap::update()
{
	_currentCTRL = SUBWIN->getCTRL();

	CameraMove();
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_isDebug = !_isDebug;
	}
	
	
	if (!SUBWIN->getIsActive() && KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		
		float cellX = (float)(m_ptMouse.x - INIT_X);//((m_ptMouse.x + CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2) - INIT_X);

		if (cellX < 0)
		{
			cellX = (cellX - TILE_WIDTH) / (float)TILE_WIDTH;
		}
		else
		{
			cellX =cellX/(float)TILE_WIDTH;
		}
		int cellY = abs((m_ptMouse.y) - INIT_Y) / TILE_HEIGHT;//m_ptMouse.y + CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2
		cellY = (m_ptMouse.y  < INIT_Y) ? cellY * -1 : cellY;//+ CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2

		int isoX = (int)cellX + (int)cellY;
		int isoY = (int)cellY - (int)cellX;

		if (isoX >= 0 && isoX < TILE_COUNT_X&&
			isoY >= 0 && isoY < TILE_COUNT_Y)
		{
			int corner = getCornerIndex(isoX,isoY);
			if (isInRhombus(corner, isoX, isoY))corner = 0;
			switch (corner)
			{
			case 1:
				isoX = isoX - 1;
				break;
			case 2:
				isoY = isoY - 1;
				break;
			case 3:
				isoY = isoY + 1;
				break;
			case 4:
				isoX = isoX + 1;
				break;
			}
			setMap(isoX,isoY, false);

			_center = corner;
			_isoX = isoX;
			_isoY = isoY;
		}

	}
	
}

void IsoMap::render()
{
	
	sprintf_s(_tileNum, "isoX : %d | isoY : %d | corner : %d | %d : %d|", _isoX, _isoY, _center,SUBWIN->getFramePoint().x, SUBWIN->getFramePoint().y);
	TextOut(CAMERAMANAGER->getCameraDC(), WINSIZEX/2-100, 20, _tileNum, strlen(_tileNum));
	
	
	DrawTileMap();
	
	
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			for (int k = 1; k <5; k++)
			{
				if (CAMERAMANAGER->getCameraXY().x - 20 < _tileMap[i][j].p[1].x && (CAMERAMANAGER->getCameraXY().x + WINSIZEX) + 20 > _tileMap[i][j].p[3].x
					&& CAMERAMANAGER->getCameraXY().y - 20 < _tileMap[i][j].p[0].y && (CAMERAMANAGER->getCameraXY().y + WINSIZEY) + 20 > _tileMap[i][j].p[2].y)
				{
					for (int z = 0; z <= TILE_MAX; z++)
					{

						if (_tileMap[i][j].tileKind[z] == TILEKIND_NONE)
						{

							//Rectangle(getMemDC(), _tileMap[i][j].AstarRC.left, _tileMap[i][j].AstarRC.top, _tileMap[i][j].AstarRC.right, _tileMap[i][j].AstarRC.bottom);
							LineMake(getMemDC(), _tileMap[i][j].p[k - 1], _tileMap[i][j].p[k],RGB(255,255,255));
							//sprintf_s(_tileNum, "(%d,%d)", i, j);
							//TextOut(getMemDC(),
							//	_tileMap[i][j].left + RADIUS_WIDTH / 2 + 8,
							//	_tileMap[i][j].top + RADIUS_HEIGHT / 2 + 5, _tileNum, strlen(_tileNum));
						}
						
					}
				}
			}
		}
	}
}

void IsoMap::LeftTop()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			int left = INIT_X + (i*RADIUS_WIDTH) - (j*RADIUS_WIDTH);
			int top = INIT_Y + (i*RADIUS_HEIGHT) + (j*RADIUS_HEIGHT);

			_tileMap[i][j].left = left;
			_tileMap[i][j].top = top;
		}
	}
}

void IsoMap::DrawTileMap()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			

			for (int z = 0; z <= _tileMap[i][j].index; z++)
			{
				if (_tileMap[i][j].tileKind[z] != TILEKIND_NONE)
				{
					switch (_tileMap[i][j].tileNum[z])
					{
					case 0:
						IMAGEMANAGER->frameRender("Mountin", getMemDC(),
							_tileMap[i][j].left,
							_tileMap[i][j].top - _tileMap[i][j].height*z,
							_tileMap[i][j].tilePoint[z].x,
							_tileMap[i][j].tilePoint[z].y);
						break;
					case 1:
						IMAGEMANAGER->frameRender("Ground", getMemDC(),
							_tileMap[i][j].left,
							_tileMap[i][j].top - _tileMap[i][j].height*z,
							_tileMap[i][j].tilePoint[z].x,
							_tileMap[i][j].tilePoint[z].y);
						break;
					case 2:
						IMAGEMANAGER->frameRender("Water", getMemDC(),
							_tileMap[i][j].left,
							_tileMap[i][j].top - _tileMap[i][j].height * z,
							_tileMap[i][j].tilePoint[z].x,
							_tileMap[i][j].tilePoint[z].y);
						break;
					}
				}
			}
			
		}
	}
}


void IsoMap::DrawRhombus()
{

	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{			
			_tileMap[i][j].centerX = _tileMap[i][j].left + RADIUS_WIDTH;
			_tileMap[i][j].centerY = _tileMap[i][j].top + RADIUS_HEIGHT;

			
			_tileMap[i][j].p[0].x = _tileMap[i][j].centerX;
			_tileMap[i][j].p[0].y = _tileMap[i][j].centerY - RADIUS_HEIGHT;
				 
			_tileMap[i][j].p[1].x = _tileMap[i][j].centerX + RADIUS_WIDTH;
			_tileMap[i][j].p[1].y = _tileMap[i][j].centerY;
				 
			_tileMap[i][j].p[2].x = _tileMap[i][j].centerX;
			_tileMap[i][j].p[2].y = _tileMap[i][j].centerY + RADIUS_HEIGHT;
				 
			_tileMap[i][j].p[3].x = _tileMap[i][j].centerX - RADIUS_WIDTH;
			_tileMap[i][j].p[3].y = _tileMap[i][j].centerY;
				 
			_tileMap[i][j].p[4].x = _tileMap[i][j].centerX;
			_tileMap[i][j].p[4].y = _tileMap[i][j].centerY - RADIUS_HEIGHT;
			
			//_tileMap[i][j].AstarRC = RectMakeCenter(_tileMap[i][j].centerX, _tileMap[i][j].centerY,
			//	getDistance(_tileMap[i][j].p[3].x, _tileMap[i][j].p[3].y, _tileMap[i][j].p[1].x, _tileMap[i][j].p[1].y),
			//	getDistance(_tileMap[i][j].p[4].x, _tileMap[i][j].p[4].y, _tileMap[i][j].p[2].x, _tileMap[i][j].p[2].y));

		}
	}
	

}

int IsoMap::getCornerIndex(int isoX, int isoY)
{
	//클릭한 좌표점을 통해서 렉트의 LEFT TOP 을 구한다.
	int left = INIT_X + (isoX*RADIUS_WIDTH) - (isoY*RADIUS_WIDTH);
	int top = INIT_Y + (isoX*RADIUS_HEIGHT) + (isoY*RADIUS_HEIGHT);

	float dx = (m_ptMouse.x - left) / (float)TILE_WIDTH; //+CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2
	float dy = (m_ptMouse.y - top) / (float)TILE_HEIGHT;// +CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2)

	if (dx < 0.5f&&dy < 0.5f)return 1;
	if (dx >= 0.5f&&dy < 0.5f)return 2;
	if (dx < 0.5f&&dy >= 0.5f)return 3;
	if (dx >= 0.5f&&dy >= 0.5f)return 4;

	return 0;
}

bool IsoMap::isInRhombus(int corner, int isoX, int isoY)
{
	if (corner == 1)//lefttop
	{
		int left =INIT_X + (isoX*RADIUS_WIDTH) - (isoY*RADIUS_WIDTH);
		int top = INIT_Y + (isoX*RADIUS_HEIGHT) + (isoY*RADIUS_HEIGHT);

		float dx = (float)(m_ptMouse.x- left) /	RADIUS_WIDTH;	//  +CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2)
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT; //+CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2)

		if ((1.0f-dy) <= dx)return true;
		else return false;
	}
	else if (corner == 2)//righttop
	{
		int left = INIT_X + (isoX*RADIUS_WIDTH) - (isoY*RADIUS_WIDTH);
		left += RADIUS_WIDTH;

		int top = INIT_Y + (isoX*RADIUS_HEIGHT) + (isoY*RADIUS_HEIGHT);

		float dx = (float)(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if (dy >= dx)return true;
		else return false;
	}
	else if (corner == 3)//leftDown
	{
		int left =INIT_Y + (isoX*RADIUS_WIDTH) - (isoY*RADIUS_WIDTH);
		int top = INIT_Y+ (isoX*RADIUS_HEIGHT) + (isoY*RADIUS_HEIGHT);
		top += RADIUS_HEIGHT;

		float dx = (float)(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if (dy < dx)return true;
		else return false;
	}
	else if (corner == 4)//RIGHTdown
	{
		int left = INIT_X+ (isoX*RADIUS_WIDTH) - (isoY*RADIUS_WIDTH);
		left += RADIUS_WIDTH;
		int top = INIT_Y + (isoX*RADIUS_HEIGHT) + (isoY*RADIUS_HEIGHT);
		top += RADIUS_HEIGHT;

		float dx = (float)(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if ((1.0f-dy) > dx)return true;
		else return false;
	}


	return false;
}

void IsoMap::CameraMove()
{
	
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x, CAMERAMANAGER->getCameraCenter().y - 10));
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x, CAMERAMANAGER->getCameraCenter().y + 10));
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x-10, CAMERAMANAGER->getCameraCenter().y ));
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x+10, CAMERAMANAGER->getCameraCenter().y ));
	}
}

void IsoMap::MapSetup()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j].index = -1;
			_tileMap[i][j].height=50;

			_tileMap[i][j].tileKind[0] = TILEKIND_NONE;
		}
	}
}

void IsoMap::setMap(int isoX, int isoY, bool isAdd)
{
	int index = SUBWIN->getFrameIndex();

	switch (SUBWIN->getFrameIndex())
	{
	case 0:
		imageFrame = SUBWIN->getFramePoint();
		break;
	case 1:
		imageFrame = SUBWIN->getFramePoint();
	case 2:
		imageFrame = SUBWIN->getFramePoint();
		break;
	}
	_currentCTRL = SUBWIN->getCTRL();
	switch (_currentCTRL)
	{
	case CTRL_DRAW:
		if (isAdd)
		{
			if (!kindSelect(imageFrame.x, imageFrame.y) == TILEKIND_NONE && _tileMap[isoX][isoY].index == -1) break;
			_tileMap[isoX][isoY].index++;
			if (_tileMap[isoX][isoY].index >= TILE_MAX) _tileMap[isoX][isoY].index = TILE_MAX - 1;
			_tileMap[isoX][isoY].tileNum[_tileMap[isoX][isoY].index] = index;
			_tileMap[isoX][isoY].tileKind[_tileMap[isoX][isoY].index] = kindSelect(imageFrame.x, imageFrame.y);
			_tileMap[isoX][isoY].tilePoint[_tileMap[isoX][isoY].index] = imageFrame;
		}
		else
		{
			if (!kindSelect(imageFrame.x, imageFrame.y) == TILEKIND_NONE)break;

			if (_tileMap[isoX][isoY].index == -1)
			{
				_tileMap[isoX][isoY].index++;

				if (_tileMap[isoX][isoY].index >= TILE_MAX)
				{
					_tileMap[isoX][isoY].index = TILE_MAX - 1;
				}
				_tileMap[isoX][isoY].tileNum[_tileMap[isoX][isoY].index] = index;
				_tileMap[isoX][isoY].tileKind[_tileMap[isoX][isoY].index] = kindSelect(imageFrame.x, imageFrame.y);
				_tileMap[isoX][isoY].tilePoint[_tileMap[isoX][isoY].index] = imageFrame;
			}

		}
		break;
	case CTRL_ERASER:
		if (_tileMap[isoX][isoY].index > -1)
		{
			_tileMap[isoX][isoY].index--;
		}
		break;
	
		

	}



}

TILEKIND IsoMap::kindSelect(int frameX, int frameY)
{
	if (frameX == -1 && frameY == -1) return TILEKIND_NONE;

	if (SUBWIN->getFrameIndex() == 0|| SUBWIN->getFrameIndex() == 1)
	{
		return TILEKIND_NOMAL;
	}
	if (SUBWIN->getFrameIndex() == 2)
	{
		return TILEKIND_SPEEDDOWN;
	}
}

void IsoMap::TileInit()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j].index = -1;
		}
	}
}

void IsoMap::Load()
{
	ZeroMemory(&_tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y));
	if (_currentCTRL == CTRL_WARMAP)
	{
		_WarMap = CreateFile("WARMAP.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		ReadFile(_WarMap, _tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y), &read, NULL);
		CloseHandle(_WarMap);
	}
	else if (_currentCTRL == CTRL_TWONMAP)
	{
		_TwonMap = CreateFile("TWONMAP.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		ReadFile(_TwonMap, _tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y), &read, NULL);
		CloseHandle(_TwonMap);
	}
}

void IsoMap::Save()
{
	if (_currentCTRL == CTRL_WARMAP)
	{
		_WarMap = CreateFile("WARMAP.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		WriteFile(_WarMap, _tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y), &write, NULL);
		CloseHandle(_WarMap);
	}
	else if (_currentCTRL == CTRL_TWONMAP)
	{
		_TwonMap = CreateFile("TWONMAP.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		WriteFile(_TwonMap, _tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y), &write, NULL);
		CloseHandle(_TwonMap);
	}

}

void IsoMap::All()
{
	int index = SUBWIN->getFrameIndex();
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			if (!kindSelect(imageFrame.x, imageFrame.y) == TILEKIND_NONE)break;

			if (_tileMap[i][j].index == -1)
			{
				_tileMap[i][j].index++;

				if (_tileMap[i][j].index >= TILE_MAX)
				{
					_tileMap[i][j].index = TILE_MAX - 1;
				}
				_tileMap[i][j].tileNum[_tileMap[i][j].index] = index;
				_tileMap[i][j].tileKind[_tileMap[i][j].index] = kindSelect(imageFrame.x, imageFrame.y);
				_tileMap[i][j].tilePoint[_tileMap[i][j].index] = imageFrame;
			}
		}
	}
}

void IsoMap::Mouse_click()
{

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{

		float cellX = (float)(m_ptMouse.x - INIT_X);

		if (cellX < 0)
		{
			cellX = (cellX - TILE_WIDTH) / (float)TILE_WIDTH;
		}
		else
		{
			cellX = cellX / (float)TILE_WIDTH;
		}
		int cellY = abs(m_ptMouse.y - INIT_Y) / TILE_HEIGHT;
		cellY = (m_ptMouse.y < INIT_Y) ? cellY * -1 : cellY;

		int isoX = (int)cellX + (int)cellY;
		int isoY = (int)cellY - (int)cellX;

		if (isoX >= 0 && isoX < TILE_COUNT_X&&
			isoY >= 0 && isoY < TILE_COUNT_Y)
		{
			int corner = getCornerIndex(isoX, isoY);
			if (isInRhombus(corner, isoX, isoY))corner = 0;
			switch (corner)
			{
			case 1:
				isoX = isoX - 1;
				break;
			case 2:
				isoY = isoY - 1;
				break;
			case 3:
				isoY = isoY + 1;
				break;
			case 4:
				isoX = isoX + 1;
				break;
			}
			_isoClickX = isoX;
			_isoClickY = isoY;			
		}
		

	}
}

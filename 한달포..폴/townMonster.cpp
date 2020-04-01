#include "stdafx.h"
#include "townMonster.h"
#include "Player.h"

void townMonster::add_MonsterIdleImg()
{
	IMAGEMANAGER->addFrame("monsterLeftIdle", "resource/image/monster/idle/leftIdle.bmp", 4800, 299, 12, 1, 1);
	IMAGEMANAGER->addFrame("monsterRightIdle", "resource/image/monster/idle/rightIdle.bmp", 4800, 299, 12, 1, 1);
	IMAGEMANAGER->addFrame("monsterTopIdle", "resource/image/monster/idle/topIdle.bmp", 4800, 299, 12, 1, 1);
	IMAGEMANAGER->addFrame("monsterBottomIdle", "resource/image/monster/idle/bottomIdle.bmp", 4800, 299, 12, 1, 1);
}
void townMonster::add_MonsterMoveImg()
{
	IMAGEMANAGER->addFrame("monsterLeftMove", "resource/image/monster/move/leftMove.bmp", 6400, 299, 16, 1, 1);
	IMAGEMANAGER->addFrame("monsterRightMove", "resource/image/monster/move/rightMove.bmp", 6400, 299, 16, 1, 1);
	IMAGEMANAGER->addFrame("monsterTopMove", "resource/image/monster/move/topMove.bmp", 6400, 299, 16, 1, 1);
	IMAGEMANAGER->addFrame("monsterBottomMove", "resource/image/monster/move/bottomMove.bmp", 6400, 299, 16, 1, 1);
}
void townMonster::release_MonsterIdleImg()
{
	IMAGEMANAGER->deleteImage("monsterLeftIdle");
	IMAGEMANAGER->deleteImage("monsterRightIdle");
	IMAGEMANAGER->deleteImage("monsterTopIdle");
	IMAGEMANAGER->deleteImage("monsterBottomIdle");

	IMAGEMANAGER->deleteAnimation("monsterLeftIdle");
	IMAGEMANAGER->deleteAnimation("monsterRightIdle");
	IMAGEMANAGER->deleteAnimation("monsterTopIdle");
	IMAGEMANAGER->deleteAnimation("monsterBottomIdle");
}
void townMonster::release_MonsterMoveImg()
{
	IMAGEMANAGER->deleteImage("monsterLeftMove");
	IMAGEMANAGER->deleteImage("monsterRightMove");
	IMAGEMANAGER->deleteImage("monsterTopMove");
	IMAGEMANAGER->deleteImage("monsterBottomMove");

	IMAGEMANAGER->deleteAnimation("monsterLeftMove");
	IMAGEMANAGER->deleteAnimation("monsterRightMove");
	IMAGEMANAGER->deleteAnimation("monsterTopMove");
	IMAGEMANAGER->deleteAnimation("monsterBottomMove");
}
void townMonster::select_MonsterImg(VI_Monster monster)
{
	switch (monster->monsterWay)
	{
	case MONSTERWAY_LEFT:
		switch (monster->monsterMotion)
		{
		case MONSTERMOTION_IDLE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterLeftIdle");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterLeftIdle");
			break;
		case MONSTERMOTION_MOVE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterLeftMove");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterLeftMove");
		
			break;
		}
		break;
	case MONSTERWAY_RIGHT:
		switch (monster->monsterMotion)
		{
		case MONSTERMOTION_IDLE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterRightIdle");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterRightIdle");
			break;
		case MONSTERMOTION_MOVE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterRightMove");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterRightMove");
			break;
		}
		break;
	case MONSTERWAY_TOP:
		switch (vi_monster->monsterMotion)
		{
		case MONSTERMOTION_IDLE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterTopIdle");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterTopIdle");
			break;
		case MONSTERMOTION_MOVE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterTopMove");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterTopMove");
			break;
		}
		break;
	case MONSTERWAY_BOTTOM:
		switch (monster->monsterMotion)
		{
		case MONSTERMOTION_IDLE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterBottomIdle");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterBottomIdle");
			break;
		case MONSTERMOTION_MOVE:
			monster->monsterImg = IMAGEMANAGER->findImage("monsterBottomMove");
			monster->monsterAni = IMAGEMANAGER->findAnimation("monsterBottomMove");
			break;
		}
		break;
	}
}
void townMonster::townMonster_move()
{
	for (vi_monster = v_monster.begin(); vi_monster != v_monster.end(); ++vi_monster)
	{
		
		if (vi_monster->isMove)
		{
			vi_monster->MotionNum = 1;
			

		}
		else
		{
			vi_monster->MotionNum = 0;
			vi_monster->MoveNum = 0;
		}


		if (vi_monster->MotionNum == 0)
		{
			vi_monster->monsterMotion = MONSTERMOTION_IDLE;
			select_MonsterImg(vi_monster);
		}
		else
		{
			vi_monster->monsterMotion = MONSTERMOTION_MOVE;
			
			vi_monster->MoveNum++;
			if (vi_monster->MoveNum < 2)
			{
				switch (RND->getFromIntTo(0, 3))
				{
				case 0:
					vi_monster->monsterWay = MONSTERWAY_LEFT;
					break;
				case 1:
					vi_monster->monsterWay = MONSTERWAY_RIGHT;
					break;
				case 2:
					vi_monster->monsterWay = MONSTERWAY_LEFT;
					break;
				case 3:
					vi_monster->monsterWay = MONSTERWAY_RIGHT;
					break;

				}
			}
			select_MonsterImg(vi_monster);
		}
		
	}
}
void townMonster::townMonster_moveRC()
{
	for (vi_monster = v_monster.begin(); vi_monster != v_monster.end(); ++vi_monster)
	{
		if (vi_monster->monsterMotion == MONSTERMOTION_MOVE)
		{
			if (vi_monster->monsterWay == MONSTERWAY_LEFT)
			{
				OffsetRect(&vi_monster->monsterRC, -1, 0);
			}
			if (vi_monster->monsterWay == MONSTERWAY_RIGHT)
			{
				OffsetRect(&vi_monster->monsterRC, 1, 0);
			}
			if (vi_monster->monsterWay == MONSTERWAY_TOP)
			{
				OffsetRect(&vi_monster->monsterRC, 0, -1);
			}
			if (vi_monster->monsterWay == MONSTERWAY_BOTTOM)
			{
				OffsetRect(&vi_monster->monsterRC, 0, 1);
			}
		}
	}
}
void townMonster::turnMonster()
{
	for (vi_monster = v_monster.begin(); vi_monster != v_monster.end(); ++vi_monster)
	{
		if (vi_monster->isturnMonster)
		{
			if (vi_monster->monsterWay == MONSTERWAY_LEFT)
			{
				vi_monster->monsterWay = MONSTERWAY_RIGHT;
				vi_monster->isturnMonster = false;
			}
			else if (vi_monster->monsterWay == MONSTERWAY_RIGHT)
			{
				vi_monster->monsterWay = MONSTERWAY_LEFT;
				vi_monster->isturnMonster = false;
			}
			else if (vi_monster->monsterWay == MONSTERWAY_BOTTOM)
			{
				vi_monster->monsterWay = MONSTERWAY_TOP;
				vi_monster->isturnMonster = false;
			}
			else if (vi_monster->monsterWay == MONSTERWAY_TOP)
			{
				vi_monster->monsterWay = MONSTERWAY_BOTTOM;
				vi_monster->isturnMonster = false;
			}

		}

	}
}
//-----------------------------------------------------------------------------------------------------
townMonster::townMonster(){}
townMonster::~townMonster(){}
//-----------------------------------------------------------------------------------------------------

HRESULT townMonster::init()
{
	IMAGEMANAGER->addFrameImage("CountImg", "resource/image/카운트/카운트.bmp", 550, 140, 25, 5);
	IMAGEMANAGER->addImage("CountDeletImg", "resource/image/카운트/카운트삭제.bmp",22,28);
	
	add_MonsterIdleImg();
	add_MonsterMoveImg();

	imgY = 0;
	_isDebug = false;
	_isSceneChange = false;
	
	Monster _monster;
	ZeroMemory(&_monster, sizeof(V_Monster));
	
	
	for (int i = 0; i < RND->getFromIntTo(3, 10); i++)
	{
		_monster.monsterNum = i;
		_monster.x = WINSIZEX / 2;
		_monster.y = WINSIZEY / 2;
		_monster.monsterWay = MONSTERWAY_BOTTOM;
		_monster.monsterMotion = MONSTERMOTION_IDLE;
		_monster.monsterImg = IMAGEMANAGER->findImage("monsterBottomIdle");
		_monster.monsterAni = IMAGEMANAGER->findAnimation("monsterBottomIdle");
		_monster.monsterRC = RectMakeCenter(_monster.x, _monster.y, 400, 299);
		_monster.colisionCount = 0;
		_monster.frameSpeed = 0.04f;
		_monster.MotionNum = 0;
		_monster.MoveCount = 0;
		_monster.MoveNum = 0;
		_monster.isCollision = false;
		_monster.isMove = false;
		_monster.isturnMonster = false;
		_monster.countImg = IMAGEMANAGER->findImage("CountDeletImg");
		v_monster.push_back(_monster);
	}

	for (vi_monster = v_monster.begin(); vi_monster != v_monster.end(); ++vi_monster)
	{
		vi_monster->monsterAni->start();
	}

	return S_OK;
}

void townMonster::release()
{
	release_MonsterIdleImg();
	release_MonsterMoveImg();
}

void townMonster::update()
{
	for (vi_monster = v_monster.begin(); vi_monster != v_monster.end(); ++vi_monster)
	{
		vi_monster->x = vi_monster->monsterRC.right - (vi_monster->monsterRC.right - vi_monster->monsterRC.left) / 2;
		vi_monster->y = vi_monster->monsterRC.bottom - (vi_monster->monsterRC.bottom - vi_monster->monsterRC.top) / 2;

		vi_monster->collisionRC = RectMakeCenter(vi_monster->x, vi_monster->y - 100, 22, 28);

		RECT temp;
		if (IntersectRect(&temp, &PLAYER->player_getplayerRECT(), &vi_monster->monsterRC)
			&& getDistance(PLAYER->Player_getFocusX(), PLAYER->Player_getFocusY(), vi_monster->x, vi_monster->y) <= 70)
		{
				vi_monster->isCollision = true;
				vi_monster->colisionCount++;
				vi_monster->isMove = false;
				vi_monster->countImg = IMAGEMANAGER->findImage("CountImg");
				if ((vi_monster->colisionCount / 2) % 25 == 0 && vi_monster->colisionCount != 0)
				{
					imgY+=1;
				}
			
		}
		else
		{
			vi_monster->countImg = IMAGEMANAGER->findImage("CountDeletImg");
			vi_monster->isMove = true;
			vi_monster->isCollision = false;
			vi_monster->colisionCount = 0;
			imgY = 0;
		}
		
		if (vi_monster->colisionCount >=250 )
		{
			
			_isSceneChange = true;

		}

		vi_monster->monsterAni->frameUpdate(vi_monster->frameSpeed);
		vi_monster->monsterAni->start();
		

		
	}
	turnMonster();
	townMonster_move();
	townMonster_moveRC();
	if (KEYMANAGER->isOnceKeyDown(VK_F11))
	{
		_isDebug = !_isDebug;
	}
}

void townMonster::render()
{

	for (vi_monster = v_monster.begin(); vi_monster != v_monster.end(); vi_monster++)
	{
		if (_isDebug)
		{
			Rectangle(getMemDC(), vi_monster->monsterRC.left, vi_monster->monsterRC.top, vi_monster->monsterRC.right, vi_monster->monsterRC.bottom);
			char str[128];
			sprintf_s(str, "|num: %d |%d|%d|%d|%d| %d:%d |%d|", vi_monster->monsterNum, vi_monster->monsterAni->isPlay(), vi_monster->isCollision, vi_monster->colisionCount, vi_monster->MoveNum, vi_monster->x, vi_monster->y, vi_monster->isturnMonster);
			TextOut(getMemDC(), vi_monster->monsterRC.left, vi_monster->monsterRC.top, str, strlen(str));
			Rectangle(getMemDC(), vi_monster->collisionRC.left, vi_monster->collisionRC.top, vi_monster->collisionRC.right, vi_monster->collisionRC.bottom);
		}
		//char str[128];
		//sprintf_s(str, "%d",imgY);
		//TextOut(CAMERAMANAGER->getCameraDC(),WINSIZEX/2,0, str, strlen(str));
		vi_monster->monsterImg->aniRender(getMemDC(), vi_monster->monsterRC.left, vi_monster->monsterRC.top, vi_monster->monsterAni);
	
	}
	
}

void townMonster::set_TwonMonsterXY(int vecterNum, int monsterX, int monsterY)
{
	vi_monster = v_monster.begin() + vecterNum;
	vi_monster->x = monsterX;
	vi_monster->y = monsterY;
	vi_monster->monsterRC = RectMakeCenter(vi_monster->x, vi_monster->y, 400, 299);
}

void townMonster::countRender()
{
	for (vi_monster = v_monster.begin(); vi_monster != v_monster.end(); ++vi_monster)
	{
		if (vi_monster->isCollision)
		{
			vi_monster->countImg->frameRender(getMemDC(), vi_monster->collisionRC.left, vi_monster->collisionRC.top, (vi_monster->colisionCount / 2) % 25, (vi_monster->colisionCount / 50)%5);
		}
		else
		{
			vi_monster->countImg->render(getMemDC(), vi_monster->collisionRC.left, vi_monster->collisionRC.top);
		}
	}
}

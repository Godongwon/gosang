#include "stdafx.h"
#include "monster.h"
#include "Player.h"





void monster::add_monsterIdleImg()
{
	IMAGEMANAGER->addFrame("monsterChildLeftIdle", "resource/image/monster/idle/leftIdle.bmp", 4800, 299, 12, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildRightIdle", "resource/image/monster/idle/rightIdle.bmp", 4800, 299, 12, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildTopIdle", "resource/image/monster/idle/topIdle.bmp", 4800, 299, 12, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildBottomIdle", "resource/image/monster/idle/bottomIdle.bmp", 4800, 299, 12, 1, 1);
}
void monster::add_monsterMoveImg()
{
	IMAGEMANAGER->addFrame("monsterChildLeftMove", "resource/image/monster/move/leftMove.bmp", 6400, 299, 16, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildRightMove", "resource/image/monster/move/rightMove.bmp", 6400, 299, 16, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildTopMove", "resource/image/monster/move/topMove.bmp", 6400, 299, 16, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildBottomMove", "resource/image/monster/move/bottomMove.bmp", 6400, 299, 16, 1, 1);
}
void monster::add_monsterAtkImg()
{
	IMAGEMANAGER->addFrame("monsterChildLeftAtk",	"resource/image/monster/atk2/leftAtk.bmp", 3600, 299, 9, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildRightAtk",	"resource/image/monster/atk2/rightAtk.bmp", 3600, 299, 9, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildBottomAtk", "resource/image/monster/atk2/bottomAtk.bmp", 3600, 299, 9, 1, 1);
	IMAGEMANAGER->addFrame("monsterChildTopAtk",	"resource/image/monster/atk2/topAtk.bmp", 3600, 299, 9, 1, 1);
}
void monster::add_monsterDieImg()
{
	IMAGEMANAGER->addFrame("monsterChildDie", "resource/image/monster/Die/bottomDie.bmp", 6000, 299, 15, 1, 1);
}
void monster::release_monsterIdleImg()
{
	IMAGEMANAGER->deleteImage("monsterChildLeftIdle");
	IMAGEMANAGER->deleteImage("monsterChildRightIdle");
	IMAGEMANAGER->deleteImage("monsterChildTopIdle");
	IMAGEMANAGER->deleteImage("monsterChildBottomIdle");

	IMAGEMANAGER->deleteAnimation("monsterChildLeftIdle");
	IMAGEMANAGER->deleteAnimation("monsterChildRightIdle");
	IMAGEMANAGER->deleteAnimation("monsterChildTopIdle");
	IMAGEMANAGER->deleteAnimation("monsterChildBottomIdle");
}
void monster::release_monsterMoveImg()
{
	IMAGEMANAGER->deleteImage("monsterChildLeftMove");
	IMAGEMANAGER->deleteImage("monsterChildRightMove");
	IMAGEMANAGER->deleteImage("monsterChildTopMove");
	IMAGEMANAGER->deleteImage("monsterChildBottomMove");

	IMAGEMANAGER->deleteAnimation("monsterChildLeftIdle");
	IMAGEMANAGER->deleteAnimation("monsterChildRightIdle");
	IMAGEMANAGER->deleteAnimation("monsterChildTopIdle");
	IMAGEMANAGER->deleteAnimation("monsterChildBottomIdle");
}
void monster::release_monsterAtkImg()
{
	IMAGEMANAGER->deleteImage("monsterChildLeftAtk");
	IMAGEMANAGER->deleteImage("monsterChildRighttAtk");
	IMAGEMANAGER->deleteImage("monsterChildBottomAtk");
	IMAGEMANAGER->deleteImage("monsterChildTopAtk");

	IMAGEMANAGER->deleteAnimation("monsterChildLeftAtk");
	IMAGEMANAGER->deleteAnimation("monsterChildRighttAtk");
	IMAGEMANAGER->deleteAnimation("monsterChildBottomAtk");
	IMAGEMANAGER->deleteAnimation("monsterChildTopAtk");
}
void monster::release_monsterDieImg()
{
	IMAGEMANAGER->deleteImage("monsterChildDie");
	IMAGEMANAGER->deleteAnimation("monsterChildDie");
}
void monster::select_monsterImg(VI_MONSTERCHILD monsterChild)
{
	if (monsterChild->Hp <= 0)
	{
		monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildDie");
		monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildDie");
	}
	else
	{

		switch (monsterChild->monsterChildWay)
		{
		case MONSTERWAY_LEFT:
			switch (monsterChild->monsterChileMotion)
			{
			case MONSTERMOTION_IDLE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildLeftIdle");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildLeftIdle");
				break;
			case MONSTERMOTION_MOVE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildLeftMove");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildLeftMove");
				break;
			case MONSTERMOTION_ATK:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildLeftAtk");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildLeftAtk");
				break;
			}
			break;
		case MONSTERWAY_RIGHT:
			switch (monsterChild->monsterChileMotion)
			{
			case MONSTERMOTION_IDLE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildRightIdle");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildRightIdle");
				break;
			case MONSTERMOTION_MOVE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildRightMove");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildRightMove");
				break;
			case MONSTERMOTION_ATK:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildRightAtk");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildRightAtk");
				break;
			}
			break;
		case MONSTERWAY_TOP:
			switch (monsterChild->monsterChileMotion)
			{
			case MONSTERMOTION_IDLE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildTopIdle");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildTopIdle");
				break;
			case MONSTERMOTION_MOVE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildTopMove");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildTopMove");
				break;
			case MONSTERMOTION_ATK:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildTopAtk");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildTopAtk");
				break;
			}
			break;
		case MONSTERWAY_BOTTOM:
			switch (monsterChild->monsterChileMotion)
			{
			case MONSTERMOTION_IDLE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildBottomIdle");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildBottomIdle");
				break;
			case MONSTERMOTION_MOVE:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildBottomMove");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildBottomMove");
				break;
			case MONSTERMOTION_ATK:
				monsterChild->monsterChildImg = IMAGEMANAGER->findImage("monsterChildBottomAtk");
				monsterChild->monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildBottomAtk");
				break;
			}
			break;
		}
	}
}
void monster::monsterChild_Move(VI_MONSTERCHILD monsterChild)
{
	if (monsterChild->monsterChileMotion == MONSTERMOTION_MOVE)
	{
		switch (monsterChild->monsterChildWay)
		{
		case MONSTERWAY_LEFT:
			OffsetRect(&monsterChild->monsterChildRC, -1, 0);
			break;
		case MONSTERWAY_RIGHT:
			OffsetRect(&monsterChild->monsterChildRC, 1, 0);
			break;
		case MONSTERWAY_TOP:
			OffsetRect(&monsterChild->monsterChildRC, 0, -1);
			break;
		case MONSTERWAY_BOTTOM:
			OffsetRect(&monsterChild->monsterChildRC, 0, 1);
			break;
		}
	}
}
void monster::monsterChild_SelectMove(VI_MONSTERCHILD monsterChild)
{
	//플레이어가 위에 있다면? 몬스터는 아래로
	if (!monsterChild->isAtkmod)
	{
		if (PLAYER->Player_getFocusY() < monsterChild->y - 50)
		{
			monsterChild->monsterChileMotion = MONSTERMOTION_MOVE;
			monsterChild->monsterChildWay = MONSTERWAY_TOP;
		}
		//플레이어가 밑에 있다면? 몬스터는 위로
		else if (PLAYER->Player_getFocusY() > monsterChild->y + 50)
		{
			monsterChild->monsterChileMotion = MONSTERMOTION_MOVE;
			monsterChild->monsterChildWay = MONSTERWAY_BOTTOM;
		}
		//플레이어가 몬스터 기준으로 왼쪽에 있다면  왼쪽으로 진행
		else if (PLAYER->Player_getFocusX() < monsterChild->x - 50)
		{
			monsterChild->monsterChileMotion = MONSTERMOTION_MOVE;
			monsterChild->monsterChildWay = MONSTERWAY_LEFT;
		}
		//플레이어가 몬스터 기준으로 오른쪽에 있다면 오른쪽으로 진행
		else if (PLAYER->Player_getFocusX() > monsterChild->x + 50)
		{
			monsterChild->monsterChileMotion = MONSTERMOTION_MOVE;
			monsterChild->monsterChildWay = MONSTERWAY_RIGHT;
		}
	}
	//이 모두가 아니라면 
	else
	{
		//플레이어 거리를 두어서 공격모드로 진행
		//공격 방향 설정
		//플레이어가 몬스터의 중점보다 위에 있다면?
		
		if (PLAYER->Player_getFocusY() < monsterChild->y)
		{
			monsterChild->monsterChildWay = MONSTERWAY_TOP;
			monsterChild->monsterChileMotion = MONSTERMOTION_ATK;
		}
		//플레이어가 몬스터의 중점보다 밑에 있다면?
		else if (PLAYER->Player_getFocusY() > monsterChild->y)
		{
			monsterChild->monsterChildWay = MONSTERWAY_BOTTOM;
			monsterChild->monsterChileMotion = MONSTERMOTION_ATK;
		}
		//Y좌표는 X축도 같이 비교
		//플레이어가 몬스터의 중점보다 왼쪽에 있다면?
		else if (PLAYER->Player_getFocusX() < monsterChild->x)
		{
			monsterChild->monsterChildWay = MONSTERWAY_LEFT;
			monsterChild->monsterChileMotion = MONSTERMOTION_ATK;
		}
		else if (PLAYER->Player_getFocusX() > monsterChild->x)
		{
			monsterChild->monsterChildWay = MONSTERWAY_RIGHT;
			monsterChild->monsterChileMotion = MONSTERMOTION_ATK;
		}	
	}

}
void monster::monsterChild_AtkRect(VI_MONSTERCHILD monsterChild)
{
	if (monsterChild->monsterChileMotion == MONSTERMOTION_ATK)
	{
		if (monsterChild->monsterChildWay == MONSTERWAY_LEFT)
		{
			monsterChild->atkRC = RectMakeCenter(monsterChild->x - 50, monsterChild->y, 50, 50);
		}
		else if (monsterChild->monsterChildWay == MONSTERWAY_RIGHT)
		{
			monsterChild->atkRC = RectMakeCenter(monsterChild->x + 50, monsterChild->y, 50, 50);
		}
		else if (monsterChild->monsterChildWay == MONSTERWAY_TOP)
		{
			monsterChild->atkRC = RectMakeCenter(monsterChild->x, monsterChild->y -50, 50, 50);
		}
		else if (monsterChild->monsterChildWay == MONSTERWAY_BOTTOM)
		{
			monsterChild->atkRC = RectMakeCenter(monsterChild->x, monsterChild->y+50, 50, 50);
		}
	

	}
}
//나중에 하자 
void monster::monster_Die()
{
	vi_monsterChild = v_monsterChild.begin();
	for (; vi_monsterChild != v_monsterChild.end();)
	{
		if (vi_monsterChild->Hp <= 0 && vi_monsterChild->monsterChildAni->getNowIndex() == vi_monsterChild->monsterChildImg->getMaxFrameX())
		{
			vi_monsterChild = v_monsterChild.erase(vi_monsterChild);
		}
		else
		{
			vi_monsterChild++;
		}
	}

}
//---------------------------------------------------------------
monster::monster(){}
monster::~monster(){}
//---------------------------------------------------------------
HRESULT monster::init()
{
	add_monsterIdleImg();
	add_monsterMoveImg();
	add_monsterAtkImg();
	add_monsterDieImg();


	MonsterCHILD monsterchild;
	ZeroMemory(&monsterchild, sizeof(MonsterCHILD));
	for (int i = 0; i < 5; i++)
	{
		monsterchild.monsterChildNum = i + 1;
		monsterchild.x = WINSIZEX/2;
		monsterchild.y= WINSIZEY/2;
		monsterchild.monsterChildWay = MONSTERWAY_LEFT;
		monsterchild.monsterChileMotion = MONSTERMOTION_IDLE;
		monsterchild.monsterChildImg = IMAGEMANAGER->findImage("monsterChildLeftIdle");
		monsterchild.monsterChildAni = IMAGEMANAGER->findAnimation("monsterChildLeftIdle");
		monsterchild.monsterChildRC = RectMakeCenter(monsterchild.x, monsterchild.y, 400, 299);
		monsterchild.Hp = 100;
		monsterchild.frameSpeed = 0.04f;
		monsterchild.atk = 20;
		monsterchild.atkRC=RectMakeCenter(monsterchild.x, monsterchild.y, 50, 50);
		monsterchild.isAtkmod = false;
		v_monsterChild.push_back(monsterchild);

	}

	for (vi_monsterChild = v_monsterChild.begin(); vi_monsterChild != v_monsterChild.end(); ++vi_monsterChild)
	{
		vi_monsterChild->monsterChildAni->start();
		
	}


	return S_OK;
}

void monster::release()
{
	release_monsterIdleImg();
	release_monsterMoveImg();
	release_monsterAtkImg();
	release_monsterDieImg();
}

void monster::update()
{
	

		for (vi_monsterChild = v_monsterChild.begin(); vi_monsterChild != v_monsterChild.end(); vi_monsterChild++)
		{
			
			vi_monsterChild->x = vi_monsterChild->monsterChildRC.right - (vi_monsterChild->monsterChildRC.right - vi_monsterChild->monsterChildRC.left) / 2;
			vi_monsterChild->y = vi_monsterChild->monsterChildRC.bottom - (vi_monsterChild->monsterChildRC.bottom - vi_monsterChild->monsterChildRC.top) / 2;
			
			monsterChild_SelectMove(vi_monsterChild);
			if (vi_monsterChild->Hp > 0)
			{
				monsterChild_Move(vi_monsterChild);
			}
			if (vi_monsterChild->Hp < 0)
			{
				vi_monsterChild->Hp = 0;
			}
			monsterChild_AtkRect(vi_monsterChild);
			select_monsterImg(vi_monsterChild);
			if (vi_monsterChild->isAtkmod)
			{
				vi_monsterChild->monsterChileMotion = MONSTERMOTION_ATK;
			}
			vi_monsterChild->monsterChildAni->frameUpdate(vi_monsterChild->frameSpeed);
		
			vi_monsterChild->monsterChildAni->start();
		}
		
		monster_Die();
	}


void monster::render()
{
	for (vi_monsterChild = v_monsterChild.begin(); vi_monsterChild != v_monsterChild.end(); ++vi_monsterChild)
	{
		vi_monsterChild->monsterChildImg->aniRender(getMemDC(), vi_monsterChild->monsterChildRC.left, vi_monsterChild->monsterChildRC.top, vi_monsterChild->monsterChildAni);
		//Rectangle(getMemDC(), vi_monsterChild->atkRC.left, vi_monsterChild->atkRC.top, vi_monsterChild->atkRC.right, vi_monsterChild->atkRC.bottom);
	
	}

}

void monster::set_monsterChildXY(int vectorNum, int monsterX, int monsterY)
{
	vi_monsterChild = v_monsterChild.begin() + vectorNum;
	vi_monsterChild->x = monsterX;
	vi_monsterChild->y = monsterY;
	vi_monsterChild->monsterChildRC = RectMakeCenter(vi_monsterChild->x, vi_monsterChild->y, 400,299);
}

void monster::HP_render()
{
	for (vi_monsterChild = v_monsterChild.begin(); vi_monsterChild != v_monsterChild.end(); ++vi_monsterChild)
	{
		char str[128];
		sprintf_s(str, "%d번몬스터 채력 : %d HP", vi_monsterChild->monsterChildNum, vi_monsterChild->Hp);
		FontTextOut(CAMERAMANAGER->getCameraDC(), 15,75+ (30 * vi_monsterChild->monsterChildNum), str, 15, "HY견고딕", RGB(254, 254, 254));
	}
}

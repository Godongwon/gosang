#include "stdafx.h"
#include "battle.h"
#include "Player.h"
#include "warriorControl.h"
void battle::copy_playerVector()
{
	if (PLAYER->get_vPlayerWarrior().size() > 0)
	{
		for (int i = 0; i < PLAYER->get_vPlayerWarrior().size();)
		{
			WARRIOR_INFO temp;
			temp = PLAYER->get_vPlayerWarrior()[i];
			v_battlePlayerWarrior.push_back(temp);
			i++;
		}
	}
}
void battle::warrior_Move(VI_battlePlayerWarrior warrior)
{
	/*
	���콺 Ŭ�� �� ��ǥ�� ������
	Y�� ���� ��
	Y�� �� �� X�� ��
	���� ���� ���Ϳ� �浹�ϰ� �Ǹ�
	�������� ��ȯ
	//�뺴 ������ ����
	//���콺�� Ŭ���� ������ �����̵��� ����
	*/
	Atk_MouseClick();
	if (!warrior->isAtkmod)
	{
		if (_atkMouseY == -1 && _atkMouseX == -1)
		{
			warrior->warriorMonsion = WARRIORMONSION_IDLE;
		}
		//���콺 Ŭ���� ���̼� centerY�� �뺴 Y���� ���� �ִٸ� �����;�����
		else if (_atkMouseY > warrior->y+32 )
		{
			warrior->warriorWay = WARRIORWAY_BOTTOM;
			warrior->warriorMonsion = WARRIORMONSION_MOVE;
		}
		//���콺�� Ŭ���� ���̼� centerY�� �뺴 Y�� ���� �Ʒ��� ���ڸ� �ö󰡾�����
		else if (_atkMouseY < warrior->y+32 )
		{
			warrior->warriorWay = WARRIORWAY_TOP;
			warrior->warriorMonsion = WARRIORMONSION_MOVE;
		}
		//���콺�� Ŭ���� ���̼� centerX�� �뺴X�ຸ�� �����ʿ� �ִٸ� ���������� ��������?
		else if (_atkMouseX > warrior->x+64 )
		{
			warrior->warriorWay = WARRIORWAY_RIGHT;
			warrior->warriorMonsion = WARRIORMONSION_MOVE;
		}
		//���콺�� Ŭ���� ���̼� centerX�� �뺴X�ຸ�� ���ʿ� �ִٸ� �������� ��������?
		else if (_atkMouseX < warrior->x +64)
		{
			warrior->warriorWay = WARRIORWAY_LEFT;
			warrior->warriorMonsion = WARRIORMONSION_MOVE;
		}
		else
		{
			warrior->warriorMonsion = WARRIORMONSION_IDLE;
		}

	}
	if (warrior->warriorMonsion == WARRIORMONSION_MOVE)
	{
		if (warrior->warriorWay == WARRIORWAY_LEFT)
		{
			OffsetRect(&warrior->inGamewarroirRC, -1, 0);
		}
		else if (warrior->warriorWay == WARRIORWAY_RIGHT)
		{
			OffsetRect(&warrior->inGamewarroirRC, 1, 0);
		}
		else if (warrior->warriorWay == WARRIORWAY_TOP)
		{
			OffsetRect(&warrior->inGamewarroirRC, 0,-1 );
		}
		else if (warrior->warriorWay == WARRIORWAY_BOTTOM)
		{
			OffsetRect(&warrior->inGamewarroirRC, 0, 1);
		}
	}
	
}
void battle::Atk_MouseClick()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		_atkMouseX = m_ptMouse.x;
		_atkMouseY = m_ptMouse.y;
	}
}
void battle::Atk_Rectmake(VI_battlePlayerWarrior warrior)
{
	if (warrior->isAtkmod)
	{
		//�������� �����ϰ� ������
		if (warrior->warriorWay == WARRIORWAY_LEFT)
		{
			//�뺴�������� ���ʿ� ���� ��Ʈ
			warrior->AtkRC = RectMakeCenter(warrior->x - 25, warrior->y, 50, 50);
		}
		//���������� �����ϰ� ������
		else if (warrior->warriorWay == WARRIORWAY_RIGHT)
		{
			warrior->AtkRC = RectMakeCenter(warrior->x + 25, warrior->y, 50, 50);
		}
		//�������� �����ϰ� ������
		else if (warrior->warriorWay == WARRIORWAY_TOP)
		{
			warrior->AtkRC = RectMakeCenter(warrior->x, warrior->y-25, 50, 50);
		}
		//�Ʒ��� �����ϰ� ������
		else if (warrior->warriorWay == WARRIORWAY_BOTTOM)
		{
			warrior->AtkRC = RectMakeCenter(warrior->x, warrior->y+25, 50, 50);
		}
	}
}
void battle::select_warior(VI_battlePlayerWarrior warrior)
{
	if (warrior->warriornum == WARRIOR_KIM)
	{
		if (warrior->HP < 0)
		{
			warrior->warriorMonsion = WARRIORMONSION_DIE;
			warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_Die");
			warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_Die");
		}
		else
		{
			switch (warrior->warriorWay)
			{
			case WARRIORWAY_LEFT:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_LeftIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_LeftIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_LeftMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_LeftMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_LeftAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_LeftAtk");
					break;
				}
				break;
			case WARRIORWAY_RIGHT:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_RightIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_RightIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_RightMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_RightMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_RightAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_RightAtk");
				}
				break;
			case WARRIORWAY_TOP:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_TopIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_TopIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_TopMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_TopMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_TopAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_TopAtk");
				}
				break;
			case WARRIORWAY_BOTTOM:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_BottomIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_BottomIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_BottomMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_BottomMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Kim_BottomAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_BottomAtk");
				}
				break;
			}
		}
	}
	if (warrior->warriornum == WARRIOR_MONK)
	{
		if (warrior->HP < 0)
		{
			warrior->warriorMonsion = WARRIORMONSION_DIE;
			warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_Die");
			warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_Die");
		}
		else
		{
			switch (warrior->warriorWay)
			{
			case WARRIORWAY_LEFT:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_LeftIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_LeftIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_LeftMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_LeftMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_LeftAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_LeftAtk");
					break;
				}
				break;
			case WARRIORWAY_RIGHT:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_RightIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_RightIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_RightMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_RightMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_RightAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_RightAtk");
				}
				break;
			case WARRIORWAY_TOP:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_TopIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_TopIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_TopMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_TopMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_TopAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_TopAtk");
				}
				break;
			case WARRIORWAY_BOTTOM:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_BottomIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_BottomIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_BottomMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_BottomMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("Monk_BottomAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_BottomAtk");
				}
				break;
			}
		}
	}
	if (warrior->warriornum == WARRIOR_GENERAL)
	{
		if (warrior->HP < 0)
		{
			warrior->warriorMonsion = WARRIORMONSION_DIE;
			warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_Die");
			warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_Die");
		}
		else
		{
			switch (warrior->warriorWay)
			{
			case WARRIORWAY_LEFT:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_LeftIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_LeftIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_LeftMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_LeftMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_LeftAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_LeftAtk");
					break;
				}
				break;
			case WARRIORWAY_RIGHT:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_RightIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_RightIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_RightMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_RightMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_RightAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_RightAtk");
				}
				break;
			case WARRIORWAY_TOP:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_TopIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_TopIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_TopMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_TopMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_TopAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_TopAtk");
				}
				break;
			case WARRIORWAY_BOTTOM:
				switch (warrior->warriorMonsion)
				{
				case WARRIORMONSION_IDLE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_BottomIdle");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_BottomIdle");
					break;
				case WARRIORMONSION_MOVE:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_BottomMove");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_BottomMove");
					break;
				case WARRIORMONSION_ATK:
					warrior->inGamewarriorImg = IMAGEMANAGER->findImage("general_BottomAtk");
					warrior->inGamewarriorAni = IMAGEMANAGER->findAnimation("general_BottomAtk");
				}
				break;
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------
battle::battle(){}
battle::~battle(){}
//------------------------------------------------------------------------------------------------------------
HRESULT battle::init()
{
	_atkMouseX = -1;
	_atkMouseY = -1;
	WARRIORCONTROL->get_kim()->add_kimyouSinImg();
	WARRIORCONTROL->get_monk()->add_monkImg();
	WARRIORCONTROL->get_general()->add_generalImg();
	copy_playerVector();
	
	for (vi_battlePlayerWarrior = v_battlePlayerWarrior.begin(); vi_battlePlayerWarrior != v_battlePlayerWarrior.end(); ++vi_battlePlayerWarrior)
	{
		
		vi_battlePlayerWarrior->isAtkmod = false;
		select_warior(vi_battlePlayerWarrior);
		vi_battlePlayerWarrior->inGamewarriorAni->start();
	}


	return S_OK;
}

void battle::release()
{
	WARRIORCONTROL->release();
}

void battle::update()
{
	for (vi_battlePlayerWarrior = v_battlePlayerWarrior.begin(); vi_battlePlayerWarrior != v_battlePlayerWarrior.end(); vi_battlePlayerWarrior++ )
	{
		vi_battlePlayerWarrior->x = vi_battlePlayerWarrior->inGamewarroirRC.right - (vi_battlePlayerWarrior->inGamewarroirRC.right - vi_battlePlayerWarrior->inGamewarroirRC.left) / 2;
		vi_battlePlayerWarrior->y = vi_battlePlayerWarrior->inGamewarroirRC.bottom - (vi_battlePlayerWarrior->inGamewarroirRC.bottom - vi_battlePlayerWarrior->inGamewarroirRC.top) / 2;
		warrior_Move(vi_battlePlayerWarrior);
		select_warior(vi_battlePlayerWarrior);
		if (vi_battlePlayerWarrior->isAtkmod)
		{
			vi_battlePlayerWarrior->warriorMonsion = WARRIORMONSION_ATK;
		}
		Atk_Rectmake(vi_battlePlayerWarrior);

		vi_battlePlayerWarrior->inGamewarriorAni->start();
		vi_battlePlayerWarrior->inGamewarriorAni->frameUpdate(vi_battlePlayerWarrior->frameSpeed);
		
	}
	warrior_die();
}

void battle::render()
{
	for (vi_battlePlayerWarrior = v_battlePlayerWarrior.begin(); vi_battlePlayerWarrior != v_battlePlayerWarrior.end(); ++vi_battlePlayerWarrior)
	{
		vi_battlePlayerWarrior->inGamewarriorImg->aniRender(getMemDC(), vi_battlePlayerWarrior->inGamewarroirRC.left, vi_battlePlayerWarrior->inGamewarroirRC.top, vi_battlePlayerWarrior->inGamewarriorAni);
		//Rectangle(getMemDC(), vi_battlePlayerWarrior->AtkRC.left, vi_battlePlayerWarrior->AtkRC.top, vi_battlePlayerWarrior->AtkRC.right, vi_battlePlayerWarrior->AtkRC.bottom);
		//char str[128];
		//sprintf_s(str, "|%d", vi_battlePlayerWarrior->HP);
		//TextOut(CAMERAMANAGER->getCameraDC(), WINSIZEX -50, 0, str, strlen(str));
	}
	//char str[128];
	//sprintf_s(str, "%d|%d", _atkMouseX, _atkMouseY);
	//TextOut(CAMERAMANAGER->getCameraDC(), WINSIZEX / 2, 0, str, strlen(str));
}

void battle::warrior_RCmake(int num, int x, int y)
{
	vi_battlePlayerWarrior = v_battlePlayerWarrior.begin() + num;
	vi_battlePlayerWarrior->inGamewarroirRC = RectMakeCenter(x, y, vi_battlePlayerWarrior->inGamewarriorImg->getFrameWidth(), vi_battlePlayerWarrior->inGamewarriorImg->getFrameHeight());
}

void battle::Minus_warriorHP(int num, int monsterAtk)
{
	vi_battlePlayerWarrior = v_battlePlayerWarrior.begin() + num;
	vi_battlePlayerWarrior->HP -= monsterAtk;
}

void battle::warScene_render()
{
	char str[128];
	sprintf_s(str, "����� �뺴 �� : %d��",PLAYER->get_vPlayerWarrior().size());
	FontTextOut(CAMERAMANAGER->getCameraDC(), 35, 345 , str, 15, "HY�߰��", RGB(254, 254, 254));

	FontTextOut(CAMERAMANAGER->getCameraDC(), 29, 425, "������ ����ִ� �뺴 ��", 15, "HY�߰��", RGB(254, 254, 254));
	char str1[128];
	sprintf_s(str1, "%d��", v_battlePlayerWarrior.size());
	FontTextOut(CAMERAMANAGER->getCameraDC(), 90, 445, str1, 15, "HY�߰��", RGB(254, 254, 254));
}

void battle::warrior_die()
{
	vi_battlePlayerWarrior = v_battlePlayerWarrior.begin();
	for (; vi_battlePlayerWarrior != v_battlePlayerWarrior.end();)
	{
		if (vi_battlePlayerWarrior->HP < 0&& vi_battlePlayerWarrior->inGamewarriorAni->getNowIndex()== vi_battlePlayerWarrior->inGamewarriorImg->getMaxFrameX())
		{
			vi_battlePlayerWarrior = v_battlePlayerWarrior.erase(vi_battlePlayerWarrior);
		}
		else
		{
			vi_battlePlayerWarrior++;
		}
	}
}

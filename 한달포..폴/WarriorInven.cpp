#include "stdafx.h"
#include "WarriorInven.h"


void WarriorInven::add_image()
{
	IMAGEMANAGER->addImage("�뺴�κ��丮", "resource/image/�뺴�κ�/�뺴�κ�â.bmp", 336, 418);
	IMAGEMANAGER->addImage("�������̹���", "resource/image/�뺴�κ�/�뺴�̹���/�������κ�.bmp", 80, 80);
	IMAGEMANAGER->addImage("�����̹���", "resource/image/�뺴�κ�/�뺴�̹���/�����κ�.bmp", 80, 80);
	IMAGEMANAGER->addImage("�屺�̹���", "resource/image/�뺴�κ�/�뺴�̹���/�屺�κ�.bmp", 80, 80);
}
void WarriorInven::set_vectorNum()
{
	isitemMove = false;
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (PLAYER->get_vPlayerWarrior().size() - 1 > vectorNum)
		{
			vectorNum += 1;
		}
		else
		{
			vectorNum = PLAYER->get_vPlayerWarrior().size() - 1;
		}
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (vectorNum > 0)
		{
			vectorNum -= 1;
		}
		else
		{
			vectorNum = 0;
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------
WarriorInven::WarriorInven() {}
WarriorInven::~WarriorInven(){}
//-------------------------------------------------------------------------------------------------------------------

HRESULT WarriorInven::init()
{
	add_image();
	warriorInvenImg = IMAGEMANAGER->findImage("�뺴�κ��丮");
	
	vectorNum=0;

	
	return S_OK;
}

void WarriorInven::release()
{
	
}

void WarriorInven::update()
{
	//warrioritem 0:����
	//warrioritem 1:����
	if (PLAYER->get_vPlayerWarrior().size() != 0)
	{
		if (!isitemMove)
		{
			set_vectorNum();
			PLAYER->set_ItemRC(vectorNum, 0, warriorInvenRC.left + 123, warriorInvenRC.top + 223);
			PLAYER->set_ItemRC(vectorNum, 1, warriorInvenRC.left + 187, warriorInvenRC.top + 223);
			warriorRC = RectMake(warriorInvenRC.left + 22, warriorInvenRC.top + 157, 80, 80);
			if (PLAYER->get_vPlayerWarrior()[vectorNum].warriornum == WARRIOR_KIM)
			{
				warriorimg = IMAGEMANAGER->findImage("�������̹���");
			}
			else if (PLAYER->get_vPlayerWarrior()[vectorNum].warriornum == WARRIOR_GENERAL)
			{
				warriorimg = IMAGEMANAGER->findImage("�屺�̹���");
			}
			else if (PLAYER->get_vPlayerWarrior()[vectorNum].warriornum == WARRIOR_MONK)
			{
				warriorimg = IMAGEMANAGER->findImage("�����̹���");
			}
		}

	}
}

void WarriorInven::render()
{
	warriorInvenImg->render(getMemDC(), warriorInvenRC.left, warriorInvenRC.top);

	if (PLAYER->get_vPlayerWarrior().size() != 0)
	{
		char str[128];
		sprintf_s(str, "%d", vectorNum + 1);
		FontTextOut(getMemDC(), warriorInvenRC.left + 165, warriorInvenRC.top + 66, str, 30, "HY�߰��", RGB(254, 254, 254));
		char ATK[128];
		sprintf_s(ATK, "%d",PLAYER->get_vPlayerWarrior()[vectorNum].atk );
		FontTextOut(getMemDC(), warriorInvenRC.left + 62, warriorInvenRC.top + 297, ATK, 10, "HY�߰��", RGB(254, 254, 254));
		char DEF[128];
		sprintf_s(DEF, "%d", PLAYER->get_vPlayerWarrior()[vectorNum].def);
		FontTextOut(getMemDC(), warriorInvenRC.left + 62, warriorInvenRC.top + 330, DEF, 10, "HY�߰��", RGB(254, 254, 254));
		WeaponitemRECT = PLAYER->get_ItemRC(vectorNum, 0);
		ArmeritemRECT = PLAYER->get_ItemRC(vectorNum, 1);
		warriorimg->render(getMemDC(), warriorRC.left, warriorRC.top);
		if (PLAYER->get_vPlayerWarrior()[vectorNum].warriornum == WARRIOR_KIM)
		{
			FontTextOut(getMemDC(), warriorInvenRC.left + 30, warriorRC.bottom + 10, "������", 25, "HY�߰��", RGB(254, 254, 254));
		}
		else if (PLAYER->get_vPlayerWarrior()[vectorNum].warriornum == WARRIOR_GENERAL)
		{
			FontTextOut(getMemDC(), warriorInvenRC.left + 40, warriorRC.bottom + 10, "�屺", 25, "HY�߰��", RGB(254, 254, 254));

		}
		else if (PLAYER->get_vPlayerWarrior()[vectorNum].warriornum == WARRIOR_MONK)
		{
			FontTextOut(getMemDC(), warriorInvenRC.left + 40, warriorRC.bottom + 10, "����", 25, "HY�߰��", RGB(254, 254, 254));

		}
		
	}

	
}

void WarriorInven::itemRender()
{
	if (PLAYER->get_vPlayerWarrior().size() != 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (PLAYER->get_item(vectorNum, i).Img != nullptr)
			{
				if (i == 0)
				{
					PLAYER->get_item(vectorNum, i).Img->render(getMemDC(), WeaponitemRECT.left - 15, WeaponitemRECT.top);
				}
				if (i == 1)
				{
					PLAYER->get_item(vectorNum, i).Img->render(getMemDC(), ArmeritemRECT.left - 15, ArmeritemRECT.top);
				}
			}
		}
	}
}

void WarriorInven::set_warriorInvenRC(int x, int y)
{
	warriorInvenRC = RectMakeCenter(x, y, warriorInvenImg->getWidth(), warriorInvenImg->getHeight());
}

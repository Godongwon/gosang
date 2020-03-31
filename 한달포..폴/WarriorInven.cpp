#include "stdafx.h"
#include "WarriorInven.h"


void WarriorInven::add_image()
{
	IMAGEMANAGER->addImage("용병인벤토리", "resource/image/용병인벤/용병인벤창.bmp", 336, 418);
}
void WarriorInven::set_vectorNum()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (PLAYER->get_vPlayerWarrior().size() - 1 < vectorNum)
		{
			vectorNum += 1;
		}
		else
		{
			vectorNum = PLAYER->get_vPlayerWarrior().size() - 1;
		}
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (vectorNum < 0)
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
	warriorInvenImg = IMAGEMANAGER->findImage("용병인벤토리");
	vectorNum=0;
	return S_OK;
}

void WarriorInven::release()
{
	
}

void WarriorInven::update()
{
	//warrioritem 0:무기
	//warrioritem 1:갑옷
	set_vectorNum();
	PLAYER->get_viPlayerWarrior() = PLAYER->get_vPlayerWarrior().begin()+vectorNum;
	PLAYER->get_viPlayerWarrior()->warriorItem[0].itemRC = RectMake(warriorInvenRC.left + 123, warriorInvenRC.top + 233, 62, 52);
	PLAYER->get_viPlayerWarrior()->warriorItem[1].itemRC = RectMake(warriorInvenRC.left + 251, warriorInvenRC.top + 233, 62, 52);


	
}

void WarriorInven::render()
{
	PLAYER->get_viPlayerWarrior() = PLAYER->get_vPlayerWarrior().begin() + vectorNum;
	

}

void WarriorInven::set_warriorInvenRC(int x, int y)
{
	warriorInvenRC = RectMakeCenter(x, y, warriorInvenImg->getWidth(), warriorInvenImg->getHeight());
}

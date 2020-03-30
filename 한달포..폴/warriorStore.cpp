#include "stdafx.h"
#include "warriorStore.h"
#include"player.h"
#include"warriorControl.h"
void warriorStore::add_Img()
{
	IMAGEMANAGER->addFrameImage("warriorStore", "resource/image/용병상점/용병상점.bmp", 468 * 2, 150 * 2, 2, 1);
	IMAGEMANAGER->addImage("InwarriorStore", "resource/image/용병상점/용병상점창.bmp", 348 * 1.5, 418 * 1.5);
	IMAGEMANAGER->addFrameImage("고용버튼", "resource/image/용병상점/고용버튼.bmp", 98 * 1.5, 21 * 1.5, 2, 1);
	IMAGEMANAGER->addFrameImage("해고버튼", "resource/image/용병상점/해고버튼.bmp", 98 * 1.5, 21 * 1.5, 2, 1);
	IMAGEMANAGER->addImage("용병상점나가기버튼", "resource/image/용병상점/나가기버튼.bmp", 78 * 1.5, 27 * 1.5);
	IMAGEMANAGER->addImage("용병창2", "resource/image/용병상점/용병창2.bmp", 237, 46);
	//어깨
	IMAGEMANAGER->addFrameImage("김유신어깨", "resource/image/용병/어깨이미지/김유신어깨.bmp", 96, 41, 2, 1);
	IMAGEMANAGER->addFrameImage("스님어깨", "resource/image/용병/어깨이미지/스님어깨.bmp", 96, 41, 2, 1);
	IMAGEMANAGER->addFrameImage("장군어깨", "resource/image/용병/어깨이미지/장군어깨.bmp", 96, 41, 2, 1);
	IMAGEMANAGER->addFrameImage("플레이어김유신어깨", "resource/image/용병/어깨이미지/김유신어깨.bmp", 96, 41, 2, 1);
	IMAGEMANAGER->addFrameImage("플레이어스님어깨", "resource/image/용병/어깨이미지/스님어깨.bmp", 96, 41, 2, 1);
	IMAGEMANAGER->addFrameImage("플레이어장군어깨", "resource/image/용병/어깨이미지/장군어깨.bmp", 96, 41, 2, 1);

	IMAGEMANAGER->addImage("김유신선택", "resource/image/용병상점/선택창/김유신선택.bmp", 319 * 1.5, 82 * 1.5);
	IMAGEMANAGER->addImage("스님선택", "resource/image/용병상점/선택창/스님선택.bmp", 319 * 1.5, 82 * 1.5);
	IMAGEMANAGER->addImage("장군선택", "resource/image/용병상점/선택창/장군선택.bmp", 319 * 1.5, 82 * 1.5);
	IMAGEMANAGER->addImage("NONE", "resource/image/용병상점/선택창/NONE.bmp", 319 * 1.5, 82 * 1.5);

}
void warriorStore::ButtonInit()
{
	/*
	0:고용
	1:해고
	3:나가기
	*/
	_warriorButton[0].Buttonimg = IMAGEMANAGER->findImage("고용버튼");
	_warriorButton[0].ButtonRC = RectMake(_InwarriorStoreRC.left + 100, _InwarriorStoreRC.top + 543, _warriorButton[0].Buttonimg->getFrameWidth(), _warriorButton[0].Buttonimg->getFrameHeight());

	_warriorButton[1].Buttonimg = IMAGEMANAGER->findImage("해고버튼");
	_warriorButton[1].ButtonRC = RectMake((_InwarriorStoreRC.left + 100) + _warriorButton[0].Buttonimg->getFrameWidth(), _InwarriorStoreRC.top + 543, _warriorButton[1].Buttonimg->getFrameWidth(), _warriorButton[1].Buttonimg->getFrameHeight());

	_warriorButton[2].Buttonimg = IMAGEMANAGER->findImage("용병상점나가기버튼");
	_warriorButton[2].ButtonRC = RectMake(_InwarriorStoreRC.left + 201, _InwarriorStoreRC.top + 586, _warriorButton[2].Buttonimg->getWidth(), _warriorButton[2].Buttonimg->getHeight());
}
void warriorStore::ButtonRender()
{
	_warriorButton[0].Buttonimg->frameRender(getMemDC(), _warriorButton[0].ButtonRC.left, _warriorButton[0].ButtonRC.top, _warriorButton[0].Buttonimg->getFrameX(), 0);
	_warriorButton[1].Buttonimg->frameRender(getMemDC(), _warriorButton[1].ButtonRC.left, _warriorButton[1].ButtonRC.top, _warriorButton[1].Buttonimg->getFrameX(), 0);
	_warriorButton[2].Buttonimg->render(getMemDC(), _warriorButton[2].ButtonRC.left, _warriorButton[2].ButtonRC.top);
}
void warriorStore::Button_isPush()
{
	for (int i = 0; i < 3; i++)
	{
		if (_warriorButton[i].isPush)
		{
			_warriorButton[i].Buttonimg->setFrameX(1);
		}
		else
		{
			_warriorButton[i].Buttonimg->setFrameX(0);
		}
	}

}
void warriorStore::warrior_Display()
{
	if (WARRIORCONTROL->get_Vwarrior().size() != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
			_warriorDisplay[i].warriorDisplayRC = RectMake(_InwarriorStoreRC.left + 24, _InwarriorStoreRC.top + 225, _warriorDisplay[i].warriorDisplayimg->getWidth(), _warriorDisplay[i].warriorDisplayimg->getHeight());
			}
			else
			{
				_warriorDisplay[i].warriorDisplayRC = RectMake(_InwarriorStoreRC.left + 24, _warriorDisplay[i-1].warriorDisplayRC.bottom+2, _warriorDisplay[i].warriorDisplayimg->getWidth(), _warriorDisplay[i].warriorDisplayimg->getHeight());
			}
			_warriorPotrait[i].warriorPotraitRC = RectMake(_warriorDisplay[i].warriorDisplayRC.left + 4, _warriorDisplay[i].warriorDisplayRC.top + 2, 48, 41);
		}

	}
}
void warriorStore::warrior_DisplayRender()
{
	for (int i = 0; i < 3; i++)
	{
		_warriorDisplay[i].warriorDisplayimg->render(getMemDC(), _warriorDisplay[i].warriorDisplayRC.left, _warriorDisplay[i].warriorDisplayRC.top);
		_warriorPotrait[i].warriorPotraitimg->frameRender(getMemDC(), _warriorPotrait[i].warriorPotraitRC.left, _warriorPotrait[i].warriorPotraitRC.top,_warriorPotrait[i].warriorPotraitimg->getFrameX(), 0);
	}
}
void warriorStore::warrior_portrait()
{
	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(&_warriorDisplay[i].warriorDisplayRC, m_ptMouse))
		{
			_warriorPotrait[i].warriorPotraitimg->setFrameX(1);
			
		}
		else
		{
			_warriorPotrait[i].warriorPotraitimg->setFrameX(0);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(&_playerWarriorDisplay[i].PlayerwarriorDisplayRC, m_ptMouse))
		{
			_playerWarriorPotrait[i].warriorPotraitimg->setFrameX(1);

		}
		else
		{
			_playerWarriorPotrait[i].warriorPotraitimg->setFrameX(0);
		}
	}
}
void warriorStore::Sold_outWarrior()
{
	if (_isSoldKim)
	{
		FontTextOut(getMemDC(), _warriorDisplay[0].warriorDisplayRC.left + 100, _warriorDisplay[0].warriorDisplayRC.top + 10, "품절", 20, "HY견고딕", RGB(255, 255, 255));
	}
	else
	{
		char str1[128];
		sprintf_s(str1, "수량 : %d", _kim);
		FontTextOut(getMemDC(), _warriorDisplay[0].warriorDisplayRC.left + 100, _warriorDisplay[0].warriorDisplayRC.top + 10, str1, 20, "HY견고딕", RGB(255, 255, 255));
	}
	if (_isSoldMonk)
	{
		FontTextOut(getMemDC(), _warriorDisplay[1].warriorDisplayRC.left + 100, _warriorDisplay[1].warriorDisplayRC.top + 10, "품절", 20, "HY견고딕", RGB(255, 255, 255));
	}
	else
	{
		char str2[128];
		sprintf_s(str2, "수량 : %d", _monk);
		FontTextOut(getMemDC(), _warriorDisplay[1].warriorDisplayRC.left + 100, _warriorDisplay[1].warriorDisplayRC.top + 10, str2, 20, "HY견고딕", RGB(255, 255, 255));
	}
	if (_isSoldGen)
	{
		FontTextOut(getMemDC(), _warriorDisplay[2].warriorDisplayRC.left + 100, _warriorDisplay[2].warriorDisplayRC.top + 10, "품절", 20, "HY견고딕", RGB(255, 255, 255));
	}
	else
	{
		char str3[128];
		sprintf_s(str3, "수량 : %d", _gen);
		FontTextOut(getMemDC(), _warriorDisplay[2].warriorDisplayRC.left + 100, _warriorDisplay[2].warriorDisplayRC.top + 10, str3, 20, "HY견고딕", RGB(255, 255, 255));
	}
}
void warriorStore::Player_isWarrior()
{
	if (PLAYER->get_vPlayerWarrior().size() != 0)
	{
		for (int i = 0; i < PLAYER->get_vPlayerWarrior().size(); i++)
		{
			if (PLAYER->get_vPlayerWarrior()[i].warriornum == WARRIOR_KIM)
			{
				_isPlayerKim = true;
			}
			if (PLAYER->get_vPlayerWarrior()[i].warriornum == WARRIOR_MONK)
			{
				_isPlayerMonk = true;
			}
			if (PLAYER->get_vPlayerWarrior()[i].warriornum ==WARRIOR_GENERAL)
			{
				_isPlayergen = true;
			}
		}
	}
}
void warriorStore::Player_warrior()
{
	if (_isPlayerKim)
	{
		_playerWarriorDisplay[0].PlayerwarriorDisplayRC = RectMake(_InwarriorStoreRC.left + 263, _warriorDisplay[0].warriorDisplayRC.top, _playerWarriorDisplay[0].PlayerwarriorDisplayimg->getWidth(), _playerWarriorDisplay[0].PlayerwarriorDisplayimg->getHeight());
		_playerWarriorPotrait[0].warriorPotraitRC = RectMake(_playerWarriorDisplay[0].PlayerwarriorDisplayRC.left + 4, _playerWarriorDisplay[0].PlayerwarriorDisplayRC.top + 2, 48, 41);
	}
	if (_isPlayerMonk)
	{
		_playerWarriorDisplay[1].PlayerwarriorDisplayRC=RectMake(_InwarriorStoreRC.left + 263, _warriorDisplay[1].warriorDisplayRC.top, _playerWarriorDisplay[1].PlayerwarriorDisplayimg->getWidth(), _playerWarriorDisplay[1].PlayerwarriorDisplayimg->getHeight());
		_playerWarriorPotrait[1].warriorPotraitRC = RectMake(_playerWarriorDisplay[1].PlayerwarriorDisplayRC.left + 4, _playerWarriorDisplay[1].PlayerwarriorDisplayRC.top + 2, 48, 41);
	}

	if (_isPlayergen)
	{
		_playerWarriorDisplay[2].PlayerwarriorDisplayRC= RectMake(_InwarriorStoreRC.left + 263, _warriorDisplay[2].warriorDisplayRC.top, _playerWarriorDisplay[2].PlayerwarriorDisplayimg->getWidth(), _playerWarriorDisplay[2].PlayerwarriorDisplayimg->getHeight());
		_playerWarriorPotrait[2].warriorPotraitRC = RectMake(_playerWarriorDisplay[2].PlayerwarriorDisplayRC.left + 4, _playerWarriorDisplay[2].PlayerwarriorDisplayRC.top + 2, 48, 41);
	}
}
void warriorStore::Player_warriorRender()
{
	if (_isPlayerKim)
	{
		_playerWarriorDisplay[0].PlayerwarriorDisplayimg->render(getMemDC(), _playerWarriorDisplay[0].PlayerwarriorDisplayRC.left, _playerWarriorDisplay[0].PlayerwarriorDisplayRC.top);
		_playerWarriorPotrait[0].warriorPotraitimg->frameRender(getMemDC(), _playerWarriorPotrait[0].warriorPotraitRC.left, _playerWarriorPotrait[0].warriorPotraitRC.top, _playerWarriorPotrait[0].warriorPotraitimg->getFrameX(),0);
		char str[128];
		sprintf_s(str, "수량 : %d", PLAYER->get_Playerkim());
		FontTextOut(getMemDC(), _playerWarriorDisplay[0].PlayerwarriorDisplayRC.left + 100, _playerWarriorDisplay[0].PlayerwarriorDisplayRC.top + 10, str, 20, "HY견고딕", RGB(255, 255, 255));
		
	}
	if (_isPlayerMonk)
	{
		_playerWarriorDisplay[1].PlayerwarriorDisplayimg->render(getMemDC(), _playerWarriorDisplay[1].PlayerwarriorDisplayRC.left, _playerWarriorDisplay[1].PlayerwarriorDisplayRC.top);
		_playerWarriorPotrait[1].warriorPotraitimg->frameRender(getMemDC(), _playerWarriorPotrait[1].warriorPotraitRC.left, _playerWarriorPotrait[1].warriorPotraitRC.top, _playerWarriorPotrait[1].warriorPotraitimg->getFrameX(), 0);
		char str[128];
		sprintf_s(str, "수량 : %d", PLAYER->get_PlayerMonk());
		FontTextOut(getMemDC(), _playerWarriorDisplay[1].PlayerwarriorDisplayRC.left + 100, _playerWarriorDisplay[1].PlayerwarriorDisplayRC.top + 10, str, 20, "HY견고딕", RGB(255, 255, 255));
	}
	if (_isPlayergen)
	{
		_playerWarriorDisplay[2].PlayerwarriorDisplayimg->render(getMemDC(), _playerWarriorDisplay[2].PlayerwarriorDisplayRC.left, _playerWarriorDisplay[2].PlayerwarriorDisplayRC.top);
		_playerWarriorPotrait[2].warriorPotraitimg->frameRender(getMemDC(), _playerWarriorPotrait[2].warriorPotraitRC.left, _playerWarriorPotrait[2].warriorPotraitRC.top, _playerWarriorPotrait[2].warriorPotraitimg->getFrameX(), 0);
		char str[128];
		sprintf_s(str, "수량 : %d", PLAYER->get_PlayerGen());
		FontTextOut(getMemDC(), _playerWarriorDisplay[2].PlayerwarriorDisplayRC.left + 100, _playerWarriorDisplay[2].PlayerwarriorDisplayRC.top + 10, str, 20, "HY견고딕", RGB(255, 255, 255));
	}
}

void warriorStore::WarriorAccountinit()
{
	for (int i = 0; i < 4; i++)
	{
		warriorAccount[i]._warriorAccountRC = RectMake(_InwarriorStoreRC.left + (13 * 1.5), _InwarriorStoreRC.top + (33 * 1.5), warriorAccount[i]._warriorAccountImg->getWidth(), warriorAccount[i]._warriorAccountImg->getHeight());
	}
}

void warriorStore::WarriorAccountRender()
{

		if (_warriorPotrait[0].isClick || _playerWarriorPotrait[0].isClick)
		{
			warriorAccount[0]._warriorAccountImg->render(getMemDC(), warriorAccount[0]._warriorAccountRC.left, warriorAccount[0]._warriorAccountRC.top);
		}
		else if (_warriorPotrait[1].isClick || _playerWarriorPotrait[1].isClick)
		{
			warriorAccount[1]._warriorAccountImg->render(getMemDC(), warriorAccount[1]._warriorAccountRC.left, warriorAccount[1]._warriorAccountRC.top);
		}
		else if (_warriorPotrait[2].isClick || _playerWarriorPotrait[2].isClick)
		{
			warriorAccount[2]._warriorAccountImg->render(getMemDC(), warriorAccount[2]._warriorAccountRC.left, warriorAccount[2]._warriorAccountRC.top);
		}
		else
		{
			warriorAccount[3]._warriorAccountImg->render(getMemDC(), warriorAccount[3]._warriorAccountRC.left, warriorAccount[3]._warriorAccountRC.top);
		}
	

}

void warriorStore::Player_Money()
{
	char str[128];
	sprintf_s(str, "%d", PLAYER->Player_Money());
	FontTextOut(getMemDC(), _InwarriorStoreRC.left + 300, _InwarriorStoreRC.top + 549, str, 20, "HY견고딕", RGB(255, 255, 255));

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
warriorStore::warriorStore(){}
warriorStore::~warriorStore(){}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

HRESULT warriorStore::init()
{
	_isOpenWarriorStore = false;
	_isSoldKim = false;
	_isSoldGen = false;
	_isSoldMonk = false;

	_isPlayerKim=false;
	_isPlayerMonk=false;
	_isPlayergen=false;

	WARRIORCONTROL->init();

	add_Img();
	_warriorStoreImg = IMAGEMANAGER->findImage("warriorStore");
	_warriorStoreRC = RectMake(0, 0, _warriorStoreImg->getFrameWidth(), _warriorStoreImg->getFrameHeight());

	_InwarriorStoreImg= IMAGEMANAGER->findImage("InwarriorStore");
	add_warrior();
	
	for (int i = 0; i < 3; i++)
	{
		_warriorDisplay[i].warriorDisplayimg = IMAGEMANAGER->findImage("용병창2");
		_playerWarriorDisplay[i].PlayerwarriorDisplayimg= IMAGEMANAGER->findImage("용병창2");
	}

	_warriorPotrait[0].warriorPotraitimg = IMAGEMANAGER->findImage("김유신어깨");
	_warriorPotrait[1].warriorPotraitimg = IMAGEMANAGER->findImage("스님어깨");
	_warriorPotrait[2].warriorPotraitimg = IMAGEMANAGER->findImage("장군어깨");

	_playerWarriorPotrait[0].warriorPotraitimg = IMAGEMANAGER->findImage("플레이어김유신어깨");
	_playerWarriorPotrait[1].warriorPotraitimg = IMAGEMANAGER->findImage("플레이어스님어깨");
	_playerWarriorPotrait[2].warriorPotraitimg = IMAGEMANAGER->findImage("플레이어장군어깨");

	warriorAccount[0]._warriorAccountImg = IMAGEMANAGER->findImage("김유신선택");
	warriorAccount[1]._warriorAccountImg = IMAGEMANAGER->findImage("스님선택");
	warriorAccount[2]._warriorAccountImg = IMAGEMANAGER->findImage("장군선택");
	warriorAccount[3]._warriorAccountImg = IMAGEMANAGER->findImage("NONE");

	for (int i = 0; i < 3; i++)
	{
		_warriorButton[i].isPush = false;
		_warriorPotrait[i].isClick = false;
		_playerWarriorPotrait[i].isClick = false;

	}
	return S_OK;
}

void warriorStore::release()
{
	IMAGEMANAGER->deleteImage("warriorStore");
}

void warriorStore::update()
{
	_warriorStoreFocus.x= _warriorStoreRC.right - (_warriorStoreRC.right - _warriorStoreRC.left) / 2;
	_warriorStoreFocus.y = _warriorStoreRC.bottom - (_warriorStoreRC.bottom - _warriorStoreRC.top) / 2;

	RECT _player = PLAYER->player_getplayerRECT();
	RECT temp;
	if (IntersectRect(&temp, &_player, &_warriorStoreRC))
	{
		_warriorStoreImg->setFrameX(1);
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_isOpenWarriorStore = !_isOpenWarriorStore;
		}
	}
	else
	{
		_warriorStoreImg->setFrameX(0);
		if (_isOpenWarriorStore)
		{
			_isOpenWarriorStore = false;
		}
	}

	
	if (_isOpenWarriorStore)
	{
		_InwarriorStoreRC = RectMakeCenter(PLAYER->Player_getFocusX(), PLAYER->Player_getFocusY(), _InwarriorStoreImg->getWidth(), _InwarriorStoreImg->getHeight());
		WarriorAccountinit();
		ButtonInit();
		warrior_Display();
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < 3; i++)
			{

				if (PtInRect(&_warriorButton[i].ButtonRC, m_ptMouse))
				{
					_warriorButton[i].isPush = !_warriorButton[i].isPush;
				}
				if (PtInRect(&_warriorDisplay[i].warriorDisplayRC, m_ptMouse))
				{
					_warriorPotrait[i].isClick = !_warriorPotrait[i].isClick;
				}
				if (PtInRect(&_playerWarriorDisplay[i].PlayerwarriorDisplayRC, m_ptMouse))
				{
					_playerWarriorPotrait[i].isClick = !_playerWarriorPotrait[i].isClick;
				}
			}
		}
		//warrior_portrait();
		Button_isPush();
		buy_warrior();
		pay_warrior();
		Player_isWarrior();
		Player_warrior();
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (_warriorPotrait[i].isClick)
		{
			_warriorPotrait[i].warriorPotraitimg->setFrameX(1);	
		}
		else
		{
			_warriorPotrait[i].warriorPotraitimg->setFrameX(0);
		}
		if (_playerWarriorPotrait[i].isClick)
		{
			_playerWarriorPotrait[i].warriorPotraitimg->setFrameX(1);
		}
		else
		{
			_playerWarriorPotrait[i].warriorPotraitimg->setFrameX(0);
		}
	}

	if (_warriorButton[2].isPush)
	{
		_isOpenWarriorStore = false;
		for (int i = 0; i < 3; i++)
		{
			_warriorButton[i].isPush = false;
		}
	}
}
void warriorStore::render()
{
	
	_warriorStoreImg->frameRender(getMemDC(), _warriorStoreRC.left, _warriorStoreRC.top, _warriorStoreImg->getFrameX(), 0);

	if (_isOpenWarriorStore)
	{ 
		_InwarriorStoreImg->render(getMemDC(), _InwarriorStoreRC.left, _InwarriorStoreRC.top);
		ButtonRender();
		warrior_DisplayRender();
		Sold_outWarrior();
		Player_warriorRender();
		WarriorAccountRender();
		Player_Money();
	}
}
void warriorStore::set_warriorStore(int x, int y)
{
	_warriorStoreRC = RectMakeCenter(x, y, _warriorStoreImg->getFrameWidth(), _warriorStoreImg->getFrameHeight());
}
void warriorStore::add_warrior()
{
	
	_kim = RND->getFromIntTo(2, 5);
	_monk = RND->getFromIntTo(2, 5);
	_gen = RND->getFromIntTo(2, 5);

	for (int i = 1; i < _kim; i++)
	{
		WARRIORCONTROL->add_KimyouSin();
	}
	for (int i = 1; i < _monk; i++)
	{
		WARRIORCONTROL->add_monk();
	}
	for (int i = 1; i < _gen; i++)
	{
		WARRIORCONTROL->add_general();
	}
}
void warriorStore::buy_warrior()
{
	if (_warriorPotrait[0].isClick&&_warriorButton[0].isPush)
	{
		for(int i=0;i< WARRIORCONTROL->get_Vwarrior().size();)
		{
			if (WARRIORCONTROL->get_Vwarrior()[i].warriornum== WARRIOR_KIM)
			{
				WARRIOR_INFO temp;
				temp = WARRIORCONTROL->get_Vwarrior()[i];
				PLAYER->get_vPlayerWarriorPush(temp);
				PLAYER->Minus_Playermoney(temp.price);
				_kim -=1;
				PLAYER->set_PlayerWarrior(WARRIOR_KIM, 1, true);
				WARRIORCONTROL->removeVector(i);
				_warriorButton[0].isPush = false;
				_warriorPotrait[0].isClick = false;
				break;
			}
			else
			{
				if (i == WARRIORCONTROL->get_Vwarrior().size()-1)
				{
					_isSoldKim = true;
					_warriorButton[0].isPush = false;
					_warriorPotrait[0].isClick = false;
					break;
				}
				else
				{
					i++;
				}
			}
		}
	}
	if (_warriorPotrait[1].isClick&&_warriorButton[0].isPush)
	{
		for (int i = 0; i < WARRIORCONTROL->get_Vwarrior().size();)
		{
			if (WARRIORCONTROL->get_Vwarrior()[i].warriornum == WARRIOR_MONK)
			{
				WARRIOR_INFO temp;
				temp = WARRIORCONTROL->get_Vwarrior()[i];
				PLAYER->get_vPlayerWarriorPush(temp);
				PLAYER->Minus_Playermoney(temp.price);
				_monk -=1;
				PLAYER->set_PlayerWarrior(WARRIOR_MONK, 1, true);
				WARRIORCONTROL->removeVector(i);
				_warriorButton[0].isPush = false;
				_warriorPotrait[1].isClick = false;
				break;
			}
			else
			{

				if (i == WARRIORCONTROL->get_Vwarrior().size() - 1)
				{
					_isSoldMonk = true;
					_warriorButton[0].isPush = false;
					_warriorPotrait[1].isClick = false;
					break;
				}
				else
				{
					i++;
				}
			}
		}
	}
	 if (_warriorPotrait[2].isClick&&_warriorButton[0].isPush)
	{
		for (int i = 0; i < WARRIORCONTROL->get_Vwarrior().size();)
		{
			if (WARRIORCONTROL->get_Vwarrior()[i].warriornum ==WARRIOR_GENERAL)
			{
				WARRIOR_INFO temp;
				temp = WARRIORCONTROL->get_Vwarrior()[i];
				PLAYER->get_vPlayerWarriorPush(temp);
				PLAYER->Minus_Playermoney(temp.price);
				_gen -= 1;
				PLAYER->set_PlayerWarrior(WARRIOR_GENERAL, 1, true);
				WARRIORCONTROL->removeVector(i);
				_warriorButton[0].isPush = false;
				_warriorPotrait[2].isClick = false;
				break;
			}
			else
			{

				if (i == WARRIORCONTROL->get_Vwarrior().size() -1)
				{
					_isSoldGen = true;
					_warriorButton[0].isPush = false;
					_warriorPotrait[2].isClick = false;
					break;
				}
				else
				{
					i++;
				}
			}
		}
	}
}
void warriorStore::pay_warrior()
{
	if (_playerWarriorPotrait[0].isClick&&_warriorButton[1].isPush&&PLAYER->get_Playerkim() > 0)
	{
		for (int i = 0; i < PLAYER->get_vPlayerWarrior().size();)
		{
			if (PLAYER->get_vPlayerWarrior()[i].warriornum == WARRIOR_KIM)
			{
				WARRIOR_INFO temp;
				temp = PLAYER->get_vPlayerWarrior()[i];
				WARRIORCONTROL->WarriorPush(temp);
				PLAYER->Plus_Playermoney(temp.price);
				PLAYER->removePlayer(i);
				_kim += 1;
				PLAYER->set_PlayerWarrior(WARRIOR_KIM, 1, false);
				_playerWarriorPotrait[0].isClick = false;
				_warriorButton[1].isPush = false;
				break;
			}
		}
	}
	if (_playerWarriorPotrait[1].isClick&&_warriorButton[1].isPush&&PLAYER->get_PlayerMonk() > 0)
	{
		for (int i = 0; i < PLAYER->get_vPlayerWarrior().size();)
		{
			if (PLAYER->get_vPlayerWarrior()[i].warriornum == WARRIOR_MONK)
			{
				WARRIOR_INFO temp;
				temp = PLAYER->get_vPlayerWarrior()[i];
				WARRIORCONTROL->WarriorPush(temp);
				PLAYER->Plus_Playermoney(temp.price);
				PLAYER->removePlayer(i);
				_monk += 1;
				PLAYER->set_PlayerWarrior(WARRIOR_MONK, 1, false);
				_playerWarriorPotrait[1].isClick = false;
				_warriorButton[1].isPush = false;
				break;
			}
		}
	}
	if (_playerWarriorPotrait[2].isClick&&_warriorButton[1].isPush&&PLAYER->get_PlayerGen() > 0)
	{
		for (int i = 0; i < PLAYER->get_vPlayerWarrior().size();)
		{
			if (PLAYER->get_vPlayerWarrior()[i].warriornum ==WARRIOR_GENERAL)
			{
				WARRIOR_INFO temp;
				temp = PLAYER->get_vPlayerWarrior()[i];
				WARRIORCONTROL->WarriorPush(temp);
				PLAYER->Plus_Playermoney(temp.price);
				PLAYER->removePlayer(i);
				_gen += 1;
				PLAYER->set_PlayerWarrior(WARRIOR_GENERAL, 1, false);
				_playerWarriorPotrait[2].isClick = false;
				_warriorButton[1].isPush = false;
				break;
			}
		}
	}
}


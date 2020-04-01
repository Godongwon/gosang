#include "stdafx.h"
#include "interFace.h"


void interFace::fontout()
{
	char money[128];
	sprintf_s(money, "%d", PLAYER->Player_Money());
	FontTextOut(getMemDC(), _interfaceRC.left + 120, _interfaceRC.top + 743, money, 15, "°íµñ", RGB(0, 0, 0));
	int a = 0;
	if (PLAYER->get_vPlayerWarrior().size() != 0)
	{
		for (int i = 0; i < PLAYER->get_vPlayerWarrior().size(); i++)
		{
			a += PLAYER->get_vPlayerWarrior()[i].atk;
		}
	}
	else
	{
		a = 0;
	}
	char AllAtk[128];
	sprintf_s(AllAtk, "%d", a);
	FontTextOut(getMemDC(), _interfaceRC.left + 85, _interfaceRC.top + 717, AllAtk, 15, "°íµñ", RGB(0, 0, 0));
}

interFace::interFace()
{
}


interFace::~interFace()
{
}

HRESULT interFace::init()
{
	IMAGEMANAGER->addImage("mainPanal", "resource/image/ÇÃ·¹ÀÌ¾î/panal/mainPanal.bmp", 1024, 768);
	_interfaceimg = IMAGEMANAGER->findImage("mainPanal");
	_warriorDisplay = new interFaceWarriorDisplay;
	return S_OK;
}

void interFace::release()
{
}

void interFace::update()
{
	_interfaceRC = RectMakeCenter(PLAYER->Player_getFocusX(), PLAYER->Player_getFocusY(), 1024, 768);
	if (_warriorDisplay->get_vDisplay().size() != 0)
	{
		for (int i = 0; i < _warriorDisplay->get_vDisplay().size(); i++)
		{
			_warriorDisplay->set_displayRC(i, _interfaceRC, 0, i * 52);
		
		}
	}
	_warriorDisplay->update();
	
}

void interFace::render()
{
	//_interfaceimg->render(getMemDC(), _interfaceRC.left, _interfaceRC.top);
	_interfaceimg->render(getMemDC(), _interfaceRC.left, _interfaceRC.top);
	fontout();
	_warriorDisplay->render();
}

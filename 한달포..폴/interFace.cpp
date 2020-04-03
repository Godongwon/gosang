#include "stdafx.h"
#include "interFace.h"


void interFace::fontout()
{
	char money[128];
	sprintf_s(money, "%d", PLAYER->Player_Money());
	FontTextOut(getMemDC(), _interfaceRC.left + 120, _interfaceRC.top + 743, money, 15, "���", RGB(0, 0, 0));
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
	FontTextOut(getMemDC(), _interfaceRC.left + 85, _interfaceRC.top + 717, AllAtk, 15, "���", RGB(0, 0, 0));
}

interFace::interFace()
{
}


interFace::~interFace()
{
}

HRESULT interFace::init()
{
	IMAGEMANAGER->addImage("mainPanal", "resource/image/�÷��̾�/panal/mainPanal.bmp", 1024, 768);
	IMAGEMANAGER->addImage("����", "resource/image/�÷��̾�/panal/����.bmp", 50,50);
	IMAGEMANAGER->addImage("����â", "resource/image/�÷��̾�/panal/����â.bmp", 300,300);
	_interfaceimg = IMAGEMANAGER->findImage("mainPanal");
	optionImg= IMAGEMANAGER->findImage("����");
	optionWinddowimg = IMAGEMANAGER->findImage("����â");
	isInoption = false;
	
	_warriorDisplay = new interFaceWarriorDisplay;
	return S_OK;
}

void interFace::release()
{
}

void interFace::update()
{
	_interfaceRC = RectMakeCenter(PLAYER->Player_getFocusX(), PLAYER->Player_getFocusY(), 1024, 768);
	optionRC = RectMake(_interfaceRC.right - 50, _interfaceRC.top, 50, 50);
	

	if (PtInRect(&optionRC, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			isInoption = true;
			for (int i = 0; i < 2; i++)
			{
				_optionButton[i].isPush = false;
			}
		}
	}
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
	optionImg->render(getMemDC(), optionRC.left, optionRC.top);
	fontout();
	_warriorDisplay->render();
}

void interFace::optionWindow()
{
	optionRC = RectMakeCenter(PLAYER->Player_getFocusX(), PLAYER->Player_getFocusY(), 300, 300);
	_optionButton[0].optionButtonimg = new image;
	_optionButton[1].optionButtonimg = new image;
	_optionButton[0].optionButtonimg->init("resource/image/�÷��̾�/panal/��ư/�������ư.bmp", 450, 50, 3, 1);
	_optionButton[1].optionButtonimg->init("resource/image/�÷��̾�/panal/��ư/���ư���.bmp", 450, 50, 3, 1);

	_optionButton[0].optionButtonRC = RectMake(optionRC.left + 75, optionRC.top + 75, _optionButton[0].optionButtonimg->getFrameWidth(), _optionButton[0].optionButtonimg->getFrameHeight());
	_optionButton[1].optionButtonRC = RectMake(optionRC.left + 75, optionRC.top + 150, _optionButton[1].optionButtonimg->getFrameWidth(), _optionButton[1].optionButtonimg->getFrameHeight());
	

	for (int i = 0; i < 2; i++)
	{
		if (PtInRect(&_optionButton[i].optionButtonRC, m_ptMouse))
		{
			_optionButton[i].optionButtonimg->setFrameX(1);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_optionButton[i].isPush = true;
				_optionButton[i].optionButtonimg->setFrameX(3);
			}
		}
		else
		{
			_optionButton[i].optionButtonimg->setFrameX(0);
		}
	}
	if (_optionButton[1].isPush)
	{
		_optionButton[1].isPush = false;
		isInoption = false;
	}
	if (_optionButton[0].isPush)
	{
		_optionButton[0].isPush = false;
		SOUNDMANAGER->pause("TwonMusic");
		SCENEMANAGER->changeScene("StartScene");
		isInoption = false;
	}

}

void interFace::optionWindow_render()
{
	optionWinddowimg->render(getMemDC(), optionRC.left, optionRC.top);
	for (int i = 0; i < 2; i++)
	{
		_optionButton[i].optionButtonimg->frameRender(getMemDC(), _optionButton[i].optionButtonRC.left, _optionButton[i].optionButtonRC.top, _optionButton[i].optionButtonimg->getFrameX(), 0);
	}
}

#include "stdafx.h"
#include "startScene.h"


void startScene::add_image()
{
	IMAGEMANAGER->addImage("backGoundB", "resource/image/startScene/BackGround.bmp", 1024, 768);
	IMAGEMANAGER->addImage("title", "resource/image/startScene/title.bmp", 264, 232);
	IMAGEMANAGER->addImage("backGoundF","resource/image/startScene/startScene.bmp", 1024, 768);

	IMAGEMANAGER->addFrameImage("GamestartButton","resource/image/startScene/버튼/게임시작버튼.bmp", 450,50,3,1);
	IMAGEMANAGER->addFrameImage("GameEndButton","resource/image/startScene/버튼/게임종료버튼.bmp", 450,50,3,1);
	IMAGEMANAGER->addFrameImage("MaptoolButton","resource/image/startScene/버튼/맵툴버튼.bmp", 450,50,3,1);	

}
void startScene::release_image()
{
	IMAGEMANAGER->deleteImage("backGoundB");
	IMAGEMANAGER->deleteImage("title");
	IMAGEMANAGER->deleteImage("backGoundF");
	IMAGEMANAGER->deleteImage("GamestartButton");
	IMAGEMANAGER->deleteImage("GameEndButton");
	IMAGEMANAGER->deleteImage("MaptoolButton");

}
//------------------------------------------------------------------------------------------------------
startScene::startScene()
{
}
startScene::~startScene()
{
}
//------------------------------------------------------------------------------------------------------

HRESULT startScene::init()
{
	add_image();
	_backGroundback = IMAGEMANAGER->findImage("backGoundB");
	_backGroundfront = IMAGEMANAGER->findImage("backGoundF");
	_title= IMAGEMANAGER->findImage("title");
	button[0].buttonImg= IMAGEMANAGER->findImage("GamestartButton");
	button[1].buttonImg= IMAGEMANAGER->findImage("MaptoolButton");
	button[2].buttonImg= IMAGEMANAGER->findImage("GameEndButton");
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			button[i].buttonRC = RectMake(WINSIZEX / 2+100, WINSIZEY / 2+50, button[i].buttonImg->getFrameWidth(), button[i].buttonImg->getFrameHeight());
		}
		else
		{
			button[i].buttonRC = RectMake(WINSIZEX / 2+100, button[i-1].buttonRC.bottom+15, button[i].buttonImg->getFrameWidth(), button[i].buttonImg->getFrameHeight());
		}
		button[i].isPush = false;
	}
	SOUNDMANAGER->addSound("startMusic", "resource/sound/Scene/startScene.wav", true, true);
	SOUNDMANAGER->play("startMusic");


	return S_OK;
}

void startScene::release()
{
	release_image();
}

void startScene::update()
{
	CAMERAMANAGER->setCameraCenter(PointMake(WINSIZEX/2, WINSIZEY/2));
	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(&button[i].buttonRC, m_ptMouse))
		{
			button[i].buttonImg->setFrameX(1);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				button[i].isPush = true;
			}
		}
		else
		{
			button[i].buttonImg->setFrameX(0);
		}
		if (button[i].isPush)
		{
			button[i].buttonImg->setFrameX(2);
		}
	}
	if (button[0].isPush)//게임시작
	{
		SOUNDMANAGER->pause("startMusic");
		SCENEMANAGER->changeScene("Twon");
	}
	if (button[1].isPush)//맵툴
	{
		SCENEMANAGER->changeScene("Maptool");
	}
	if (button[2].isPush)//게임종료
	{
		PostQuitMessage(0);
	}

}

void startScene::render()
{
	_backGroundback->render(getMemDC(), 0, 0);
	_backGroundfront->alphaRender(getMemDC(), 0, 0, 100);
	_title->render(getMemDC(), WINSIZEX / 2, 100);
	for (int i = 0; i < 3; i++)
	{	
		//Rectangle(getMemDC(), button[i].buttonRC.left, button[i].buttonRC.top, button[i].buttonRC.right, button[i].buttonRC.bottom);
		button[i].buttonImg->frameRender(getMemDC(), button[i].buttonRC.left, button[i].buttonRC.top, button[i].buttonImg->getFrameX(), 0);
	}
}

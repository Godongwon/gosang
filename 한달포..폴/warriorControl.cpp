#include "stdafx.h"
#include "warriorControl.h"
#include "progressBar.h"

warriorControl::warriorControl()
{
}


warriorControl::~warriorControl()
{
}

HRESULT warriorControl::init()
{

	_kim = new Kimyousin;
	_monk = new monk;
	_general = new general;

	_kim->add_kimyouSinImg();
	_monk->add_monkImg();
	_general->add_generalImg();


	return S_OK;
}

void warriorControl::release()
{
	
}

void warriorControl::update()
{
}

void warriorControl::render()
{
}

void warriorControl::removeVector(int num)
{
	v_warrior.erase(v_warrior.begin() + num);
}

void warriorControl::WarriorMove(VI_Warrior warrior)
{
	
}

void warriorControl::add_KimyouSin()
{
	WARRIOR_INFO warrior;
	ZeroMemory(&warrior, sizeof(WARRIOR_INFO));

	warrior.warriornum = WARRIOR_KIM;
	warrior.warriorMonsion = WARRIORMONSION_IDLE;
	warrior.warriorWay = WARRIORWAY_BOTTOM;
	warrior.inGamewarriorImg = IMAGEMANAGER->findImage("Kim_BottomIdle");
	warrior.inGamewarroirRC = RectMake(WINSIZEX / 2, WINSIZEY / 2, 300, 240);
	warrior.inGamewarriorAni = IMAGEMANAGER->findAnimation("Kim_BottomIdle");
	warrior.warriorPotraitimg = new image;
	warrior.warriorPotraitimg->init("resource/image/¿ëº´/¾î±úÀÌ¹ÌÁö/±èÀ¯½Å¾î±ú.bmp", 96, 41, 2, 1);
	warrior.warriorPotraitRC = RectMake(0, 0, warrior.warriorPotraitimg->getFrameWidth(), warrior.warriorPotraitimg->getFrameHeight());
	warrior.x = warrior.inGamewarroirRC.right - (warrior.inGamewarroirRC.right - warrior.inGamewarroirRC.left) / 2;
	warrior.y = warrior.inGamewarroirRC.bottom - (warrior.inGamewarroirRC.bottom - warrior.inGamewarroirRC.top) / 2;
	warrior.AtkRC = RectMakeCenter(warrior.x, warrior.y, 50, 50);
	warrior.atk = 80;
	warrior.def = 50;
	warrior.HP = 100;
	warrior.price = 5000;
	warrior.frameSpeed = 0.2f;
	warrior.isSelect = false;
	warrior.isAtkmod = false;
	warrior.warriorProgressBar = new progressBar;
	warrior.warriorProgressBar->init("resource/image/progressBar/prograssBarF.bmp", "resource/image/progressBar/prograssBarB.bmp", 0, 0, 100, 10);
	warrior.warriorProgressBar->setGauge(warrior.HP,100);
	v_warrior.push_back(warrior);
}
void warriorControl::add_monk()
{
	WARRIOR_INFO warrior;
	ZeroMemory(&warrior, sizeof(WARRIOR_INFO));
	warrior.warriornum = WARRIOR_MONK;
	warrior.warriorMonsion = WARRIORMONSION_IDLE;
	warrior.warriorWay = WARRIORWAY_BOTTOM;
	warrior.inGamewarriorImg = IMAGEMANAGER->findImage("Monk_BottomIdle");
	warrior.inGamewarroirRC = RectMake(WINSIZEX / 2, WINSIZEY / 2, 98,90);
	warrior.inGamewarriorAni = IMAGEMANAGER->findAnimation("Monk_BottomIdle");
	warrior.warriorPotraitimg = new image;
	warrior.warriorPotraitimg->init("resource/image/¿ëº´/¾î±úÀÌ¹ÌÁö/½º´Ô¾î±ú.bmp", 96, 41, 2, 1);
	warrior.warriorPotraitRC = RectMake(0, 0, warrior.warriorPotraitimg->getFrameWidth(), warrior.warriorPotraitimg->getFrameHeight());
	warrior.x = warrior.inGamewarroirRC.right - (warrior.inGamewarroirRC.right - warrior.inGamewarroirRC.left) / 2;
	warrior.y = warrior.inGamewarroirRC.bottom - (warrior.inGamewarroirRC.bottom - warrior.inGamewarroirRC.top) / 2;
	warrior.AtkRC = RectMakeCenter(warrior.x, warrior.y, 50,50);
	warrior.atk = 30;
	warrior.def = 20;
	warrior.HP = 100;
	warrior.price = 1500;
	warrior.frameSpeed = 0.2f;
	warrior.isSelect = false;
	warrior.isAtkmod = false;
	warrior.warriorProgressBar = new progressBar;
	warrior.warriorProgressBar->init("resource/image/progressBar/prograssBarF.bmp", "resource/image/progressBar/prograssBarB.bmp", 0, 0, 100, 10);
	warrior.warriorProgressBar->setGauge(warrior.HP,100);
	v_warrior.push_back(warrior);
}

void warriorControl::add_general()
{
	WARRIOR_INFO warrior;
	ZeroMemory(&warrior, sizeof(WARRIOR_INFO));
	warrior.warriornum = WARRIOR_GENERAL;
	warrior.warriorMonsion = WARRIORMONSION_IDLE;
	warrior.warriorWay = WARRIORWAY_BOTTOM;
	warrior.inGamewarriorImg = IMAGEMANAGER->findImage("general_BottomIdle");
	warrior.inGamewarroirRC = RectMake(WINSIZEX / 2, WINSIZEY / 2, 174, 155);
	warrior.inGamewarriorAni = IMAGEMANAGER->findAnimation("general_BottomIdle");
	warrior.warriorPotraitimg = new image;
	warrior.warriorPotraitimg->init("resource/image/¿ëº´/¾î±úÀÌ¹ÌÁö/Àå±º¾î±ú.bmp", 96, 41, 2, 1);
	warrior.warriorPotraitRC = RectMake(0, 0, warrior.warriorPotraitimg->getFrameWidth(), warrior.warriorPotraitimg->getFrameHeight());
	warrior.x = warrior.inGamewarroirRC.right - (warrior.inGamewarroirRC.right - warrior.inGamewarroirRC.left) / 2;
	warrior.y = warrior.inGamewarroirRC.bottom - (warrior.inGamewarroirRC.bottom - warrior.inGamewarroirRC.top) / 2;
	warrior.AtkRC = RectMakeCenter(warrior.x, warrior.y, 50,50);
	warrior.atk = 70;
	warrior.def = 20;
	warrior.HP = 100;
	warrior.price = 3000;
	warrior.frameSpeed = 0.2f;
	warrior.isSelect = false;
	warrior.isAtkmod = false;
	warrior.warriorProgressBar = new progressBar;
	warrior.warriorProgressBar->init("resource/image/progressBar/prograssBarF.bmp", "resource/image/progressBar/prograssBarB.bmp", 0, 0, 100, 10);
	warrior.warriorProgressBar->setGauge(warrior.HP,100);
	v_warrior.push_back(warrior);
}




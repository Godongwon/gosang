#include "stdafx.h"
#include "general.h"


general::general()
{
}


general::~general()
{
}

HRESULT general::init()
{
	return S_OK;
}

void general::release()
{
}

void general::update()
{
}

void general::render()
{
}

void general::add_generalImg()
{
	
	//idle
	IMAGEMANAGER->addFrame("general_LeftIdle",	"resource/image/용병/장군/idle/leftidle.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_RightIdle", "resource/image/용병/장군/idle/rightidle.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_TopIdle",	"resource/image/용병/장군/idle/topidle.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_BottomIdle","resource/image/용병/장군/idle/bottomidle.bmp", 1392, 155, 8, 1);
	//move
	IMAGEMANAGER->addFrame("general_LeftMove","resource/image/용병/장군/move/leftMove.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_RightMove","resource/image/용병/장군/move/RightMove.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_TopMove","resource/image/용병/장군/move/TopMove.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_BottomMove","resource/image/용병/장군/move/BottomMove.bmp", 1392, 155, 8, 1);
	//atk
	IMAGEMANAGER->addFrame("general_LeftAtk",	"resource/image/용병/장군/Atk/leftAtk.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_RightAtk",	"resource/image/용병/장군/Atk/rightAtk.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_TopAtk",	"resource/image/용병/장군/Atk/TopAtk.bmp", 1392, 155, 8, 1);
	IMAGEMANAGER->addFrame("general_BottomAtk",	"resource/image/용병/장군/Atk/BottomAtk.bmp", 1392, 155, 8, 1);
	//die
	IMAGEMANAGER->addFrame("general_Die",	"resource/image/용병/장군/Die/die.bmp", 1566, 155, 9, 1);
	
}

void general::release_generalImg()
{
	
	//idle
	IMAGEMANAGER->deleteImage("general_LeftIdle");
	IMAGEMANAGER->deleteImage("general_RightIdle");
	IMAGEMANAGER->deleteImage("general_TopIdle");
	IMAGEMANAGER->deleteImage("general_BottomIdle");
	//move					
	IMAGEMANAGER->deleteImage("general_LeftMove");
	IMAGEMANAGER->deleteImage("general_RightMove");
	IMAGEMANAGER->deleteImage("general_TopMove");
	IMAGEMANAGER->deleteImage("general_BottomMove");
	//atk					
	IMAGEMANAGER->deleteImage("general_LeftAtk");
	IMAGEMANAGER->deleteImage("general_RightAtk");
	IMAGEMANAGER->deleteImage("general_TopAtk");
	IMAGEMANAGER->deleteImage("general_BottomAtk");
	//die	
	IMAGEMANAGER->deleteImage("general_Die");

	//idle
	IMAGEMANAGER->deleteAnimation("general_LeftIdle");
	IMAGEMANAGER->deleteAnimation("general_RightIdle");
	IMAGEMANAGER->deleteAnimation("general_TopIdle");
	IMAGEMANAGER->deleteAnimation("general_BottomIdle");
	//move			  
	IMAGEMANAGER->deleteAnimation("general_LeftMove");
	IMAGEMANAGER->deleteAnimation("general_RightMove");
	IMAGEMANAGER->deleteAnimation("general_TopMove");
	IMAGEMANAGER->deleteAnimation("general_BottomMove");
	//atk			   
	IMAGEMANAGER->deleteAnimation("general_LeftAtk");
	IMAGEMANAGER->deleteAnimation("general_RightAtk");
	IMAGEMANAGER->deleteAnimation("general_TopAtk");
	IMAGEMANAGER->deleteAnimation("general_BottomAtk");
	//die			  
	IMAGEMANAGER->deleteAnimation("general_Die");
}


//void general::add_general()
//{
//	WARRIOR_INFO warrior;
//	ZeroMemory(&warrior, sizeof(WARRIOR_INFO));
//	warrior.warriornum = WARRIOR_GENERAL;
//	warrior.warriorMonsion = WARRIORMONSION_IDLE;
//	warrior.warriorWay = WARRIORWAY_BOTTOM;
//	warrior.warriorImg = IMAGEMANAGER->findImage("general_portrait");
//	warrior.warriorRC = RectMake(WINSIZEX / 2, WINSIZEY / 2, warrior.warriorImg->getFrameWidth(), warrior.warriorImg->getFrameHeight());
//	warrior.inGamewarriorImg = IMAGEMANAGER->findImage("general_BottomIdle");
//	warrior.inGamewarroirRC = RectMake(WINSIZEX / 2, WINSIZEY / 2, warrior.inGamewarriorImg->getFrameWidth(), warrior.inGamewarriorImg->getFrameHeight());
//	warrior.inGamewarriorAni = IMAGEMANAGER->findAnimation("general_BottomIdle");
//	warrior.x = warrior.inGamewarroirRC.right - (warrior.inGamewarroirRC.right - warrior.inGamewarroirRC.left) / 2;
//	warrior.y = warrior.inGamewarroirRC.bottom - (warrior.inGamewarroirRC.bottom - warrior.inGamewarroirRC.top) / 2;
//	warrior.CollisionRC = RectMakeCenter(warrior.x, warrior.y, warrior.inGamewarriorImg->getFrameWidth() + 50, warrior.inGamewarriorImg->getFrameHeight() + 50);
//	warrior.atk = 70;
//	warrior.def = 20;
//	warrior.HP = 100;
//}

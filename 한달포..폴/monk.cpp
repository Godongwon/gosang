#include "stdafx.h"
#include "monk.h"


monk::monk()
{
}


monk::~monk()
{
}

HRESULT monk::init()
{
	return S_OK;
}

void monk::release()
{
}

void monk::update()
{
}

void monk::render()
{
}

void monk::add_monkImg()
{
	
	//idle
	IMAGEMANAGER->addFrame("Monk_LeftIdle",		"resource/image/�뺴/����/idle/leftIdle.bmp", 392, 90, 4, 1);
	IMAGEMANAGER->addFrame("Monk_RightIdle",	"resource/image/�뺴/����/idle/rightIdle.bmp", 392, 90, 4, 1);
	IMAGEMANAGER->addFrame("Monk_TopIdle",		"resource/image/�뺴/����/idle/topIdle.bmp", 392, 90, 4, 1);
	IMAGEMANAGER->addFrame("Monk_BottomIdle",	"resource/image/�뺴/����/idle/bottomIdle.bmp", 392, 90, 4, 1);
	//move
	IMAGEMANAGER->addFrame("Monk_LeftMove", "resource/image/�뺴/����/move/leftMove.bmp", 784, 90, 8, 1);
	IMAGEMANAGER->addFrame("Monk_RightMove", "resource/image/�뺴/����/move/rightMove.bmp", 784, 90, 8, 1);
	IMAGEMANAGER->addFrame("Monk_TopMove", "resource/image/�뺴/����/move/topMove.bmp", 784, 90, 8, 1);
	IMAGEMANAGER->addFrame("Monk_BottomMove", "resource/image/�뺴/����/move/bottomMove.bmp", 784, 90, 8, 1);
	//Atk
	IMAGEMANAGER->addFrame("Monk_LeftAtk", "resource/image/�뺴/����/Atk/leftAtk.bmp", 784, 90, 8, 1);
	IMAGEMANAGER->addFrame("Monk_RightAtk", "resource/image/�뺴/����/Atk/rightAtk.bmp", 784, 90, 8, 1);
	IMAGEMANAGER->addFrame("Monk_TopAtk", "resource/image/�뺴/����/Atk/topAtk.bmp", 784, 90, 8, 1);
	IMAGEMANAGER->addFrame("Monk_BottomAtk", "resource/image/�뺴/����/Atk/bottomAtk.bmp", 784, 90, 8, 1);
	//Die
	IMAGEMANAGER->addFrame("Monk_Die", "resource/image/�뺴/����/Die/monkDie.bmp", 784, 90, 8, 1);
}

void monk::release_monkImg()
{
	
	//idle
	IMAGEMANAGER->deleteImage("Monk_LeftIdle");
	IMAGEMANAGER->deleteImage("Monk_RightIdle");
	IMAGEMANAGER->deleteImage("Monk_TopIdle");
	IMAGEMANAGER->deleteImage("Monk_BottomIdle");
	//move
	IMAGEMANAGER->deleteImage("Monk_LeftMove");
	IMAGEMANAGER->deleteImage("Monk_RightMove");
	IMAGEMANAGER->deleteImage("Monk_TopMove");
	IMAGEMANAGER->deleteImage("Monk_BottomMove");
	//Atk
	IMAGEMANAGER->deleteImage("Monk_LeftAtk");
	IMAGEMANAGER->deleteImage("Monk_RightAtk");
	IMAGEMANAGER->deleteImage("Monk_TopAtk");
	IMAGEMANAGER->deleteImage("Monk_BottomAtk");
	//Die
	IMAGEMANAGER->deleteImage("Monk_Die");
	//idle
	IMAGEMANAGER->deleteAnimation("Monk_LeftIdle");
	IMAGEMANAGER->deleteAnimation("Monk_RightIdle");
	IMAGEMANAGER->deleteAnimation("Monk_TopIdle");
	IMAGEMANAGER->deleteAnimation("Monk_BottomIdle");
	//move		 
	IMAGEMANAGER->deleteAnimation("Monk_LeftMove");
	IMAGEMANAGER->deleteAnimation("Monk_RightMove");
	IMAGEMANAGER->deleteAnimation("Monk_TopMove");
	IMAGEMANAGER->deleteAnimation("Monk_BottomMove");
	//Atk		
	IMAGEMANAGER->deleteAnimation("Monk_LeftAtk");
	IMAGEMANAGER->deleteAnimation("Monk_RightAtk");
	IMAGEMANAGER->deleteAnimation("Monk_TopAtk");
	IMAGEMANAGER->deleteAnimation("Monk_BottomAtk");
	//Die		 
	IMAGEMANAGER->deleteAnimation("Monk_Die");

}

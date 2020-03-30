#include "stdafx.h"
#include "Kimyousin.h"

Kimyousin::Kimyousin()
{
}


Kimyousin::~Kimyousin()
{
}

HRESULT Kimyousin::init()
{
	
	

	return S_OK;
}

void Kimyousin::release()
{
}

void Kimyousin::update()
{
}

void Kimyousin::render()
{
}

void Kimyousin::add_kimyouSinImg()
{
	
	//idle
	IMAGEMANAGER->addFrame("Kim_LeftIdle", "resource/image/¿ëº´/±èÀ¯½Å/idle/leftidle.bmp", 3000, 240, 10, 1);
	IMAGEMANAGER->addFrame("Kim_RightIdle", "resource/image/¿ëº´/±èÀ¯½Å/idle/rightidle.bmp", 3000, 240, 10, 1);
	IMAGEMANAGER->addFrame("Kim_TopIdle", "resource/image/¿ëº´/±èÀ¯½Å/idle/topidle.bmp", 3000, 240, 10, 1);
	IMAGEMANAGER->addFrame("Kim_BottomIdle", "resource/image/¿ëº´/±èÀ¯½Å/idle/bottomidle.bmp", 3000, 240, 10, 1);
	//move
	IMAGEMANAGER->addFrame("Kim_LeftMove", "resource/image/¿ëº´/±èÀ¯½Å/move/leftMove.bmp", 2100, 240,7, 1);
	IMAGEMANAGER->addFrame("Kim_RightMove", "resource/image/¿ëº´/±èÀ¯½Å/move/rightMove.bmp", 2100, 240,7, 1);
	IMAGEMANAGER->addFrame("Kim_TopMove", "resource/image/¿ëº´/±èÀ¯½Å/move/topMove.bmp", 2100, 240,7, 1);
	IMAGEMANAGER->addFrame("Kim_BottomMove", "resource/image/¿ëº´/±èÀ¯½Å/move/bottomMove.bmp", 2100, 240,7, 1);
	//atk
	IMAGEMANAGER->addFrame("Kim_LeftAtk", "resource/image/¿ëº´/±èÀ¯½Å/Atk/Atkleft.bmp", 2400, 240, 8, 1);
	IMAGEMANAGER->addFrame("Kim_RightAtk", "resource/image/¿ëº´/±èÀ¯½Å/Atk/Atkright.bmp", 2400, 240, 8, 1);
	IMAGEMANAGER->addFrame("Kim_TopAtk", "resource/image/¿ëº´/±èÀ¯½Å/Atk/Atktop.bmp", 2400, 240, 8, 1);
	IMAGEMANAGER->addFrame("Kim_BottomAtk", "resource/image/¿ëº´/±èÀ¯½Å/Atk/Atkbottom.bmp", 2400, 240, 8, 1);
	//die
	IMAGEMANAGER->addFrame("Kim_Die", "resource/image/¿ëº´/±èÀ¯½Å/Die/die.bmp", 3600, 240, 12, 1);

}

void Kimyousin::release_kinyouSinImg()
{
	
	//idle
	IMAGEMANAGER->deleteImage("Kim_LeftIdle");
	IMAGEMANAGER->deleteImage("Kim_RightIdle");
	IMAGEMANAGER->deleteImage("Kim_TopIdle");
	IMAGEMANAGER->deleteImage("Kim_BottomIdle");
	//move					
	IMAGEMANAGER->deleteImage("Kim_LeftMove");
	IMAGEMANAGER->deleteImage("Kim_RightMove");
	IMAGEMANAGER->deleteImage("Kim_TopMove");
	IMAGEMANAGER->deleteImage("Kim_BottomMove");
	//atk					
	IMAGEMANAGER->deleteImage("Kim_LeftAtk");
	IMAGEMANAGER->deleteImage("Kim_RightAtk");
	IMAGEMANAGER->deleteImage("Kim_TopAtk");
	IMAGEMANAGER->deleteImage("Kim_BottomAtk");
	//die	
	IMAGEMANAGER->deleteImage("Kim_Die");

	//idle
	IMAGEMANAGER->deleteAnimation("Kim_LeftIdle");
	IMAGEMANAGER->deleteAnimation("Kim_RightIdle");
	IMAGEMANAGER->deleteAnimation("Kim_TopIdle");
	IMAGEMANAGER->deleteAnimation("Kim_BottomIdle");
	//move			  
	IMAGEMANAGER->deleteAnimation("Kim_LeftMove");
	IMAGEMANAGER->deleteAnimation("Kim_RightMove");
	IMAGEMANAGER->deleteAnimation("Kim_TopMove");
	IMAGEMANAGER->deleteAnimation("Kim_BottomMove");
	//atk			   
	IMAGEMANAGER->deleteAnimation("Kim_LeftAtk");
	IMAGEMANAGER->deleteAnimation("Kim_RightAtk");
	IMAGEMANAGER->deleteAnimation("Kim_TopAtk");
	IMAGEMANAGER->deleteAnimation("Kim_BottomAtk");
	//die			  
	IMAGEMANAGER->deleteAnimation("Kim_Die");
}



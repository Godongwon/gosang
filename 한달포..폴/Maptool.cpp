#include "stdafx.h"
#include "Maptool.h"



Maptool::Maptool()
{
}


Maptool::~Maptool()
{
}

HRESULT Maptool::init()
{

	IMAGEMANAGER->addFrameImage("Ground", "resource/image/¸ÊÅø/maptoolGround.bmp", 0, 0, 320, 320, 5, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Mountin", "resource/image/¸ÊÅø/maptoolMountin.bmp", 0, 0, 320, 256, 5, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Water", "resource/image/¸ÊÅø/maptoolWater.bmp", 0, 0, 320, 192, 5, 6, true, RGB(255, 0, 255));

	
	
	SUBWIN->setIsoMap(map);

#ifdef SUBWINOPEN
	SUBWIN->init();

#endif // SubWINOPEN

#ifdef SUBWINOPEN
	SUBWIN->setScene(sub);

#endif // SubWINOPEN

	map->init();
	

	return S_OK;
}

void Maptool::release()
{
	//IMAGEMANAGER->deleteImage("Ground");
	//IMAGEMANAGER->deleteImage("Mountin");
	//IMAGEMANAGER->deleteImage("Water");
}

void Maptool::update()
{
	map->update();
#ifdef SUBWINOPEN
	SUBWIN->update();
#endif // SUBWINOPEN
}

void Maptool::render()
{
	//Èò»ö ºñÆ®¸Ê
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===============================================================
	map->render();
#ifdef SUBWINOPEN
	SUBWIN->render();
	
#endif // SUBWINOPEN
	//=====================================================
	//¹é¹öÆÛÀÇ ³»¿ëÀ» HDC¿¡ ±×¸°´Ù.(Áö¿ìÁö¸¶!!)
	//this->getBackBuffer()->render(getHDC(), 0, 0);
}

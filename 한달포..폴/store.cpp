#include "stdafx.h"
#include "store.h"
#include "Player.h"

void store::add_itemImg()
{
	IMAGEMANAGER->addImage("도끼", "resource/image/상점/weapon/weapon.bmp",			 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("낫", "resource/image/상점/weapon/weapon2.bmp",			 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("글라디우스", "resource/image/상점/weapon/weapon3.bmp",	 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("장군검", "resource/image/상점/weapon/weapon4.bmp",		 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("용검", "resource/image/상점/weapon/weapon5.bmp",			 64*1.5, 32*1.5);
	
	IMAGEMANAGER->addImage("우주복", "resource/image/상점/armer/armer1.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("정장", "resource/image/상점/armer/armer2.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("장군옷", "resource/image/상점/armer/armer3.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("한복", "resource/image/상점/armer/armer4.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("일본갑옷", "resource/image/상점/armer/armer5.bmp",	64*1.5, 32*1.5);
}
void store::release_itemImg()
{
	IMAGEMANAGER->deleteImage("도끼");
	IMAGEMANAGER->deleteImage("낫");
	IMAGEMANAGER->deleteImage("글라디우스");
	IMAGEMANAGER->deleteImage("장군검");
	IMAGEMANAGER->deleteImage("용검");
}
void store::add_vItem(string name, STORE_KIND kind, int effect,int itemnum)
{
	STORE_ITEM item;
	ZeroMemory(&item, sizeof(STORE_ITEM));
	item.name = name;
	item.Img = IMAGEMANAGER->findImage(name);
	item.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 64,32);
	item.kind = kind;
	item.effect = effect;
	item.itemnum = itemnum;
	item.itemDisplayImg=IMAGEMANAGER->findImage("아이템창");
	item.itemDisplayRC = RectMakeCenter(storeInfo.InstoreRC.right - (storeInfo.InstoreRC.right - storeInfo.InstoreRC.left) / 2,	(storeInfo.InstoreRC.top + 50),118, 36);

	v_item.push_back(item);
}
void store::add_Buttoninit()
{
	/*
		0 : 무기버튼
		1 : 갑옷버튼
		3 : 포션버튼
		4 : 구매버튼
		5 : 나가기버튼
	*/
	//무기버튼
	_storeButton[0].storeButtonImg = IMAGEMANAGER->findImage("무기버튼");
	_storeButton[0].storeButtonRC = RectMake(storeInfo.InstoreRC.left + 4, storeInfo.InstoreRC.top + 55, _storeButton[0].storeButtonImg->getFrameWidth(), _storeButton[0].storeButtonImg->getFrameHeight());
	//갑옷버튼
	_storeButton[1].storeButtonImg = IMAGEMANAGER->findImage("갑옷버튼");
	_storeButton[1].storeButtonRC = RectMake(_storeButton[0].storeButtonRC.right + 2, storeInfo.InstoreRC.top + 55, _storeButton[1].storeButtonImg->getFrameWidth(), _storeButton[1].storeButtonImg->getFrameHeight());
	//포션버튼
	_storeButton[2].storeButtonImg = IMAGEMANAGER->findImage("포션버튼");
	_storeButton[2].storeButtonRC = RectMake(_storeButton[1].storeButtonRC.right + 2, storeInfo.InstoreRC.top + 55, _storeButton[2].storeButtonImg->getFrameWidth(), _storeButton[2].storeButtonImg->getFrameHeight());

	//구매버튼
	_storeButton[3].storeButtonImg = IMAGEMANAGER->findImage("구매버튼");
	_storeButton[3].storeButtonRC = RectMake(storeInfo.InstoreRC.left + 28, storeInfo.InstoreRC.top + 413, _storeButton[3].storeButtonImg->getFrameWidth(), _storeButton[3].storeButtonImg->getFrameHeight());

	//나가기버튼
	_storeButton[4].storeButtonImg = IMAGEMANAGER->findImage("나가기버튼");
	_storeButton[4].storeButtonRC = RectMake(storeInfo.InstoreRC.left + 317, storeInfo.InstoreRC.top + 446, _storeButton[4].storeButtonImg->getFrameWidth(), _storeButton[4].storeButtonImg->getFrameHeight());
}
void store::Button_Push(int i)
{
	
	if (_storeButton[i].isPush)
	{
		_storeButton[i].storeButtonImg->setFrameX(1);
	}
	else
	{
		_storeButton[i].storeButtonImg->setFrameX(0);
	}
}
void store::Button_PushRender(VI_ITEM item)
{
	//무기
	if (_storeButton[0].isPush)
	{
		if(item->kind== STOREKIND_WEAPON)
		{
			vi_item->itemDisplayImg->render(getMemDC(), vi_item->itemDisplayRC.left, vi_item->itemDisplayRC.top);
			vi_item->Img->render(getMemDC(), vi_item->rc.left, vi_item->rc.top);
		}
	}
	//아머
	else if (_storeButton[1].isPush)
	{
		if (item->kind == STOREKIND_ARMER)
		{
			vi_item->itemDisplayImg->render(getMemDC(), vi_item->itemDisplayRC.left, vi_item->itemDisplayRC.top);
			vi_item->Img->render(getMemDC(), vi_item->rc.left, vi_item->rc.top);
		}
	}
	else if (_storeButton[2].isPush)
	{
		if (item->kind == STOREKIND_POTION)
		{
			vi_item->itemDisplayImg->render(getMemDC(), vi_item->itemDisplayRC.left, vi_item->itemDisplayRC.top);
			vi_item->Img->render(getMemDC(), vi_item->rc.left, vi_item->rc.top);
		}
	}
}
//===============================================================================================================================================
store::store(){}
store::~store(){}
//=============================================================================================================================================== 

HRESULT store::init()
{

	isOpenStore = false;
	IMAGEMANAGER->addFrameImage("Store", "resource/image/상점/상점.bmp", 288 * 2.5, 82 * 2.5, 2, 1);
	IMAGEMANAGER->addImage("InStore", "resource/image/상점/인스토어창.bmp", 714, 473);
	IMAGEMANAGER->addImage("아이템창","resource/image/상점/아이템창2.bmp", 118*1.5, 36*1.5);

	IMAGEMANAGER->addFrameImage("무기버튼", "resource/image/상점/버튼/무기버튼.bmp", 466, 31, 2, 1);
	IMAGEMANAGER->addFrameImage("갑옷버튼", "resource/image/상점/버튼/갑옷버튼.bmp", 472, 31, 2, 1);
	IMAGEMANAGER->addFrameImage("포션버튼", "resource/image/상점/버튼/포션버튼.bmp", 464, 31, 2, 1);
	IMAGEMANAGER->addFrameImage("구매버튼", "resource/image/상점/버튼/구매버튼.bmp", 180, 21, 2, 1);
	IMAGEMANAGER->addFrameImage("나가기버튼", "resource/image/상점/버튼/나가기버튼.bmp", 156, 27, 2, 1);

	add_itemImg();

	storeInfo.storeImg = IMAGEMANAGER->findImage("Store");
	storeInfo.storeRC = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, storeInfo.storeImg->getFrameWidth(), storeInfo.storeImg->getFrameHeight());
	storeInfo.InstoreImg = IMAGEMANAGER->findImage("InStore");
	
	add_vItem("도끼", STOREKIND_WEAPON, 10,1);
	add_vItem("낫", STOREKIND_WEAPON, 15,2);
	add_vItem("글라디우스", STOREKIND_WEAPON, 20,3);
	add_vItem("장군검", STOREKIND_WEAPON, 25,4);
	add_vItem("용검", STOREKIND_WEAPON, 30,5);
	
	add_vItem("우주복",STOREKIND_ARMER, 10,6);
	add_vItem("정장",STOREKIND_ARMER, 15,7);
	add_vItem("장군옷", STOREKIND_ARMER, 20,8);
	add_vItem("한복", STOREKIND_ARMER, 25,9);
	add_vItem("일본갑옷", STOREKIND_ARMER, 30,10);

	for (int i = 0; i < 5; i++)
	{
		_storeButton[i].isPush = false;
	}

	
	
	return S_OK;
}

void store::release()
{
	IMAGEMANAGER->deleteImage("store");
	IMAGEMANAGER->deleteImage("InStore");
	release_itemImg();
}

void store::update()
{
	RECT temp;
	if (IntersectRect(&temp,&PLAYER->player_getplayerRECT(), &storeInfo.storeRC))
	{
		storeInfo.storeImg->setFrameX(1);
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			isOpenStore = !isOpenStore;
		}
	}
	else
	{
		storeInfo.storeImg->setFrameX(0);
		if (isOpenStore)
		{
			isOpenStore = false;
		}
	}
	if (isOpenStore)
	{
		storeInfo.InstoreRC = RectMakeCenter(PLAYER->Player_getFocusX(), PLAYER->Player_getFocusY(), storeInfo.InstoreImg->getWidth(), storeInfo.InstoreImg->getHeight());
		add_Buttoninit();
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < 5; i++)
			{
				if (PtInRect(&_storeButton[i].storeButtonRC,m_ptMouse))
				{
					_storeButton[i].isPush = !_storeButton[i].isPush;
				}
			}
		}
		for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
		{
		
				if (vi_item->kind == STOREKIND_WEAPON)
				{
					vi_item->itemDisplayRC = RectMakeCenter(storeInfo.InstoreRC.right - (storeInfo.InstoreRC.right - storeInfo.InstoreRC.left) / 2, storeInfo.InstoreRC.top + 80 + (vi_item->itemnum *(vi_item->itemDisplayImg->getHeight() + 2)), vi_item->itemDisplayImg->getWidth(), vi_item->itemDisplayImg->getHeight());
					vi_item->rc = RectMake(vi_item->itemDisplayRC.left + 2, vi_item->itemDisplayRC.top + 2, vi_item->Img->getWidth(), vi_item->Img->getHeight());
				}
				if (vi_item->kind == STOREKIND_ARMER)
				{
					vi_item->itemDisplayRC = RectMakeCenter(storeInfo.InstoreRC.right - (storeInfo.InstoreRC.right - storeInfo.InstoreRC.left) / 2, storeInfo.InstoreRC.top + 80 + ((vi_item->itemnum - 5) * (vi_item->itemDisplayImg->getHeight() + 2)), vi_item->itemDisplayImg->getWidth(), vi_item->itemDisplayImg->getHeight());
					vi_item->rc = RectMake(vi_item->itemDisplayRC.left + 2, vi_item->itemDisplayRC.top + 2, vi_item->Img->getWidth(), vi_item->Img->getHeight());
				}
		
		}
	}

	
	if (_storeButton[4].isPush)
	{
		isOpenStore = false; 
		for (int i = 0; i < 5; i++)
		{
			_storeButton[i].isPush = false;
		}
	}

}

void store::render()
{
	storeInfo.storeImg->frameRender(getMemDC(), storeInfo.storeRC.left, storeInfo.storeRC.top, storeInfo.storeImg->getFrameX(), 0);
	if (isOpenStore)
	{
		storeInfo.InstoreImg->render(getMemDC(), storeInfo.InstoreRC.left, storeInfo.InstoreRC.top);
		for (int i = 0; i < 5; i++)
		{
			Button_Push(i);
			_storeButton[i].storeButtonImg->frameRender(getMemDC(), _storeButton[i].storeButtonRC.left, _storeButton[i].storeButtonRC.top, _storeButton[i].storeButtonImg->getFrameX(),0);
		}
		for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
		{

			Button_PushRender(vi_item);

		}
	}
}

void store::set_storeXY(int x, int y)
{
	storeInfo.storeRC = RectMakeCenter(x, y, storeInfo.storeImg->getFrameWidth(), storeInfo.storeImg->getFrameHeight());
}

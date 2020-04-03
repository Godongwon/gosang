#include "stdafx.h"
#include "store.h"
#include "inven.h"

void store::add_itemImg()
{
	IMAGEMANAGER->addImage("����", "resource/image/����/weapon/weapon.bmp",			 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("����Į", "resource/image/����/weapon/weapon2.bmp",			 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("�۶��콺", "resource/image/����/weapon/weapon3.bmp",	 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("�屺��", "resource/image/����/weapon/weapon4.bmp",		 64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("���", "resource/image/����/weapon/weapon5.bmp",			 64*1.5, 32*1.5);
	
	IMAGEMANAGER->addImage("���ֺ�", "resource/image/����/armer/armer1.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("����", "resource/image/����/armer/armer2.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("�屺��", "resource/image/����/armer/armer3.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("�Ѻ�", "resource/image/����/armer/armer4.bmp",		64*1.5, 32*1.5);
	IMAGEMANAGER->addImage("�Ϻ�����", "resource/image/����/armer/armer5.bmp",	64*1.5, 32*1.5);
}
void store::release_itemImg()
{
	IMAGEMANAGER->deleteImage("����");
	IMAGEMANAGER->deleteImage("����Į");
	IMAGEMANAGER->deleteImage("�۶��콺");
	IMAGEMANAGER->deleteImage("�屺��");
	IMAGEMANAGER->deleteImage("���");
}
void store::add_vItem(string name, STORE_KIND kind, int effect,int itemnum,int price)
{
	STORE_ITEM item;
	ZeroMemory(&item, sizeof(STORE_ITEM));
	item.name = (string)name;
	item.Img = IMAGEMANAGER->findImage(name);
	item.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 64,32);
	item.kind = kind;
	item.effect = effect;
	item.itemnum = itemnum;
	item.itemDisplayImg=IMAGEMANAGER->findImage("������â");
	item.itemDisplayRC = RectMakeCenter(storeInfo.InstoreRC.right - (storeInfo.InstoreRC.right - storeInfo.InstoreRC.left) / 2,	(storeInfo.InstoreRC.top + 50), item.itemDisplayImg->getFrameWidth(), item.itemDisplayImg->getFrameHeight());
	item.isSelect = false;
	item.price = price;
	v_item.push_back(item);
}
void store::add_Buttoninit()
{
	/*
		0 : �����ư
		1 : ���ʹ�ư
		2 : ���ǹ�ư
		3 : ���Ź�ư
		4 : �������ư
	*/
	//�����ư
	_storeButton[0].storeButtonImg = IMAGEMANAGER->findImage("�����ư");
	_storeButton[0].storeButtonRC = RectMake(storeInfo.InstoreRC.left + 4, storeInfo.InstoreRC.top + 55, _storeButton[0].storeButtonImg->getFrameWidth(), _storeButton[0].storeButtonImg->getFrameHeight());
	//���ʹ�ư
	_storeButton[1].storeButtonImg = IMAGEMANAGER->findImage("���ʹ�ư");
	_storeButton[1].storeButtonRC = RectMake(_storeButton[0].storeButtonRC.right + 2, storeInfo.InstoreRC.top + 55, _storeButton[1].storeButtonImg->getFrameWidth(), _storeButton[1].storeButtonImg->getFrameHeight());
	//���ǹ�ư
	_storeButton[2].storeButtonImg = IMAGEMANAGER->findImage("���ǹ�ư");
	_storeButton[2].storeButtonRC = RectMake(_storeButton[1].storeButtonRC.right + 2, storeInfo.InstoreRC.top + 55, _storeButton[2].storeButtonImg->getFrameWidth(), _storeButton[2].storeButtonImg->getFrameHeight());

	//���Ź�ư
	_storeButton[3].storeButtonImg = IMAGEMANAGER->findImage("���Ź�ư");
	_storeButton[3].storeButtonRC = RectMake(storeInfo.InstoreRC.left + 28, storeInfo.InstoreRC.top + 413, _storeButton[3].storeButtonImg->getFrameWidth(), _storeButton[3].storeButtonImg->getFrameHeight());

	//�������ư
	_storeButton[4].storeButtonImg = IMAGEMANAGER->findImage("�������ư");
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
	//����
	if (_storeButton[0].isPush)
	{
		if(item->kind== STOREKIND_WEAPON)
		{
			_storeButton[1].isPush=false;
			_storeButton[2].isPush=false;
			vi_item->itemDisplayImg->frameRender(getMemDC(), vi_item->itemDisplayRC.left, vi_item->itemDisplayRC.top, vi_item->itemDisplayImg->getFrameX(),0);
			vi_item->Img->render(getMemDC(), vi_item->rc.left, vi_item->rc.top);
		}
	}
	//�Ƹ�
	else if (_storeButton[1].isPush)
	{
		if (item->kind == STOREKIND_ARMER)
		{
			_storeButton[0].isPush = false;
			_storeButton[2].isPush = false;
			vi_item->itemDisplayImg->frameRender(getMemDC(), vi_item->itemDisplayRC.left, vi_item->itemDisplayRC.top, vi_item->itemDisplayImg->getFrameX(), 0);
			vi_item->Img->render(getMemDC(), vi_item->rc.left, vi_item->rc.top);
		}
	}
	else if (_storeButton[2].isPush)
	{
		if (item->kind == STOREKIND_POTION)
		{
			_storeButton[0].isPush = false;
			_storeButton[1].isPush = false;
			vi_item->itemDisplayImg->frameRender(getMemDC(), vi_item->itemDisplayRC.left, vi_item->itemDisplayRC.top, vi_item->itemDisplayImg->getFrameX(), 0);
			vi_item->Img->render(getMemDC(), vi_item->rc.left, vi_item->rc.top);
		}
	}
}
void store::Not_select(bool is)
{
	if (is)
	{
		NotSelectCount++;
	
	}

}
//===============================================================================================================================================
store::store(){}
store::~store(){}
//=============================================================================================================================================== 

HRESULT store::init()
{

	isOpenStore = false;
	isNotSelect = false;
	NotSelectCount = 0;
	IMAGEMANAGER->addFrameImage("Store", "resource/image/����/����.bmp", 288 * 2.5, 82 * 2.5, 2, 1);
	IMAGEMANAGER->addImage("InStore", "resource/image/����/�ν����â2.bmp", 714, 473);
	IMAGEMANAGER->addImage("itemInfo", "resource/image/����/����������.bmp", 100,100);
	//IMAGEMANAGER->addImage("������â","resource/image/����/������â2.bmp", 118*1.5, 36*1.5);
	IMAGEMANAGER->addFrameImage("������â","resource/image/����/������â3.bmp", 236*1.5, 36*1.5,2,1);

	IMAGEMANAGER->addFrameImage("�����ư", "resource/image/����/��ư/�����ư.bmp", 466, 31, 2, 1);
	IMAGEMANAGER->addFrameImage("���ʹ�ư", "resource/image/����/��ư/���ʹ�ư.bmp", 472, 31, 2, 1);
	IMAGEMANAGER->addFrameImage("���ǹ�ư", "resource/image/����/��ư/���ǹ�ư.bmp", 464, 31, 2, 1);
	IMAGEMANAGER->addFrameImage("���Ź�ư", "resource/image/����/��ư/���Ź�ư.bmp", 180, 21, 2, 1);
	IMAGEMANAGER->addFrameImage("�������ư", "resource/image/����/��ư/�������ư.bmp", 156, 27, 2, 1);

	add_itemImg();

	storeInfo.storeImg = IMAGEMANAGER->findImage("Store");
	storeInfo.storeRC = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, storeInfo.storeImg->getFrameWidth(), storeInfo.storeImg->getFrameHeight());
	storeInfo.InstoreImg = IMAGEMANAGER->findImage("InStore");
	
	iteminfoimg = IMAGEMANAGER->findImage("itemInfo");
	

	add_vItem("����", STOREKIND_WEAPON, 20,1,2000);
	add_vItem("����Į", STOREKIND_WEAPON, 10,2,1000);
	add_vItem("�۶��콺", STOREKIND_WEAPON, 30,3,3000);
	add_vItem("�屺��", STOREKIND_WEAPON, 35,4,4000);
	add_vItem("���", STOREKIND_WEAPON, 40,5,5000);
	
	add_vItem("���ֺ�",STOREKIND_ARMER, 20,6,3000);
	add_vItem("����",STOREKIND_ARMER, 10,7,1000);
	add_vItem("�屺��", STOREKIND_ARMER,30  ,8,5000);
	add_vItem("�Ѻ�", STOREKIND_ARMER, 15,9,2000);
	add_vItem("�Ϻ�����", STOREKIND_ARMER, 25,10,4000);

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
	//release_itemImg();
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
			for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
			{
				if (PtInRect(&vi_item->itemDisplayRC, m_ptMouse))
				{
					vi_item->isSelect = !vi_item->isSelect;
				}
			}

		}
		for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
		{
		
				if (vi_item->kind == STOREKIND_WEAPON)
				{
					vi_item->itemDisplayRC = RectMakeCenter(storeInfo.InstoreRC.right - (storeInfo.InstoreRC.right - storeInfo.InstoreRC.left) / 2+ vi_item->itemDisplayImg->getFrameWidth()/2, storeInfo.InstoreRC.top + 80 + (vi_item->itemnum *(vi_item->itemDisplayImg->getHeight() + 2)), vi_item->itemDisplayImg->getFrameWidth(), vi_item->itemDisplayImg->getFrameHeight());
					vi_item->rc = RectMake(vi_item->itemDisplayRC.left + 2, vi_item->itemDisplayRC.top + 2, vi_item->Img->getWidth(), vi_item->Img->getHeight());
				}
				if (vi_item->kind == STOREKIND_ARMER)
				{
					vi_item->itemDisplayRC = RectMakeCenter(storeInfo.InstoreRC.right - (storeInfo.InstoreRC.right - storeInfo.InstoreRC.left) / 2- vi_item->itemDisplayImg->getFrameWidth()/2, storeInfo.InstoreRC.top + 80 + ((vi_item->itemnum - 5) * (vi_item->itemDisplayImg->getHeight() + 2)), vi_item->itemDisplayImg->getFrameWidth(), vi_item->itemDisplayImg->getFrameHeight());
					vi_item->rc = RectMake(vi_item->itemDisplayRC.left + 2, vi_item->itemDisplayRC.top + 2, vi_item->Img->getWidth(), vi_item->Img->getHeight());
				}
		}
				buy_item();
		
	}

	
	if (_storeButton[4].isPush)
	{
		isOpenStore = false; 
		for (int i = 0; i < 5; i++)
		{
			_storeButton[i].isPush = false;
		}
		for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
		{
			if (vi_item->isSelect)
			{
				vi_item->isSelect = false;
			}
		}
	}

}

void store::render()
{
	
	storeInfo.storeImg->frameRender(getMemDC(), storeInfo.storeRC.left, storeInfo.storeRC.top, storeInfo.storeImg->getFrameX(), 0);
	
	if (isOpenStore)
	{
		
		storeInfo.InstoreImg->render(getMemDC(), storeInfo.InstoreRC.left, storeInfo.InstoreRC.top);
		for (int i = 3; i < 5; i++)
		{
			Button_Push(i);
			_storeButton[i].storeButtonImg->frameRender(getMemDC(), _storeButton[i].storeButtonRC.left, _storeButton[i].storeButtonRC.top, _storeButton[i].storeButtonImg->getFrameX(),0);
		}
		for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
		{
			select_item(vi_item);
			vi_item->itemDisplayImg->frameRender(getMemDC(), vi_item->itemDisplayRC.left, vi_item->itemDisplayRC.top, vi_item->itemDisplayImg->getFrameX(), 0);
			vi_item->Img->render(getMemDC(), vi_item->rc.left, vi_item->rc.top);
		}
	
		if (NotSelectCount > 60)
		{
			isNotSelect = false;
			_storeButton[3].isPush = false;
			NotSelectCount = 0;
		}
		else if(_storeButton[3].isPush&&NotSelectCount<60)
		{
			FontTextOut(getMemDC(), _storeButton[3].storeButtonRC.right+10, _storeButton[3].storeButtonRC.top, "������ �������� �����ϴ�!!", 20, "HY�߰��", RGB(254, 254, 254));
		}
	}
}

void store::iteminfo_render()
{
	for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
	{
		if (PtInRect(&vi_item->itemDisplayRC, m_ptMouse))
		{
			iteminfoRC = RectMake(m_ptMouse.x, m_ptMouse.y, 100, 100);
			iteminfoimg->alphaRender(getMemDC(), iteminfoRC.left, iteminfoRC.top,150);
			FontTextOut(getMemDC(), iteminfoRC.left + 20, iteminfoRC.top + 4, vi_item->name.c_str(), 15, "HY�߰��", RGB(254, 254, 254));
			char effect[128];
			if (vi_item->kind == STOREKIND_WEAPON)
			{
				sprintf_s(effect, "���ݷ�  + %d", vi_item->effect);
			}
			else if (vi_item->kind == STOREKIND_ARMER)
			{
				sprintf_s(effect, "����  + %d", vi_item->effect);
			}
			FontTextOut(getMemDC(), iteminfoRC.left + 2, iteminfoRC.top + 34, effect, 15, "HY�߰��", RGB(254, 254, 254));
			char price[128];
			sprintf_s(price, "���� : %d", vi_item->price);
			FontTextOut(getMemDC(), iteminfoRC.left + 2, iteminfoRC.top + 64, price, 15, "HY�߰��", RGB(254, 254, 254));
		}
	}

	

}

void store::set_storeXY(int x, int y)
{
	storeInfo.storeRC = RectMakeCenter(x, y, storeInfo.storeImg->getFrameWidth(), storeInfo.storeImg->getFrameHeight());
}

void store::select_item(VI_ITEM item)
{
	if (item->isSelect)
	{
		item->itemDisplayImg->setFrameX(1);
	}
	else
	{
		item->itemDisplayImg->setFrameX(0);
	}
}

void store::buy_item()
{
	if (_storeButton[3].isPush)
	{
		for (int i=0;i<v_item.size();i++)
		{
			if (v_item[i].isSelect)
			{
				STORE_ITEM temp;
				temp = v_item[i];
				Inven->inven_push(temp);
				PLAYER->Minus_Playermoney(v_item[i].price);
				_storeButton[3].isPush = false;
				v_item[i].isSelect = false;
				break;
			}
			else
			{
				if (i == v_item.size()-1)
				{
					isNotSelect = true;
				}

			}

		}
		Not_select(isNotSelect);
	}

}

void store::pay_item(){}


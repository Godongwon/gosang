#include "stdafx.h"
#include "Player.h"
#include"IsoMap.h"
#include"Astar.h"
#include"inven.h"
#include"WarriorInven.h"
Player::Player(){}
Player::~Player(){}
//============================================================
//						플레이어 이미지 추가
//============================================================
void Player::playerIdleImgAdd()
{
	IMAGEMANAGER->addFrame("LeftIdle", "resource/image/플레이어/idle/leftIdle.bmp", 1176, 148, 6, 1, 1);
	IMAGEMANAGER->addFrame("RightIdle", "resource/image/플레이어/idle/RightIdle.bmp", 1176, 148, 6, 1, 1);
	IMAGEMANAGER->addFrame("BottomIdle", "resource/image/플레이어/idle/bottomIdle.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("TopIdle", "resource/image/플레이어/idle/topIdle.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("LefttopIdle", "resource/image/플레이어/idle/lefttopIdle.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("LeftbottomIdle", "resource/image/플레이어/idle/leftbottomIdle.bmp", 1568, 148, 8, 1, 1);
}
void Player::playerMoveImgAdd()
{
	IMAGEMANAGER->addFrame("LeftMove", "resource/image/플레이어/move/leftMove.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("RightMove", "resource/image/플레이어/move/RightMove.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("TopMove", "resource/image/플레이어/move/topMove.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("BottomMove", "resource/image/플레이어/move/bottomMove.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("LefttopMove", "resource/image/플레이어/move/lefttopMove.bmp", 1568, 148, 8, 1, 1);
	IMAGEMANAGER->addFrame("LeftbottomMove", "resource/image/플레이어/move/leftbottomMove.bmp", 1568, 148, 8, 1, 1);
}
void Player::playerIdleImgRelese()
{
	IMAGEMANAGER->deleteImage("LeftIdle");
	IMAGEMANAGER->deleteImage("RightIdle");
	IMAGEMANAGER->deleteImage("BottomIdle");
	IMAGEMANAGER->deleteImage("TopIdle");
	IMAGEMANAGER->deleteImage("LefttopIdle");
	IMAGEMANAGER->deleteImage("LeftbottomIdle");

	IMAGEMANAGER->deleteAnimation("LeftIdle");
	IMAGEMANAGER->deleteAnimation("RightIdle");
	IMAGEMANAGER->deleteAnimation("BottomIdle");
	IMAGEMANAGER->deleteAnimation("TopIdle");
	IMAGEMANAGER->deleteAnimation("LefttopIdle");
	IMAGEMANAGER->deleteAnimation("LeftbottomIdle");
}
void Player::playerMoveImgRelese()
{
	IMAGEMANAGER->deleteImage("LeftMove");
	IMAGEMANAGER->deleteImage("RightMove");
	IMAGEMANAGER->deleteImage("BottomMove");
	IMAGEMANAGER->deleteImage("TopMove");
	IMAGEMANAGER->deleteImage("LefttopMove");
	IMAGEMANAGER->deleteImage("LeftbottomMove");

	IMAGEMANAGER->deleteAnimation("LeftMove");
	IMAGEMANAGER->deleteAnimation("RightMove");
	IMAGEMANAGER->deleteAnimation("BottomMove");
	IMAGEMANAGER->deleteAnimation("TopMove");
	IMAGEMANAGER->deleteAnimation("LefttopMove");
	IMAGEMANAGER->deleteAnimation("LeftbottomMove");
}
//============================================================
void Player::PlayerImgSelect()
{
	switch (_playerInfo.playerWay)
	{
	case PlayerWay_bottom:
		switch (_playerInfo.playerMotion)
		{
		case Player_Idle:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("BottomIdle");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("BottomIdle");
			break;
		case Player_Move:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("BottomMove");          
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("BottomMove");
			break;
		}
		break;
	case PlayerWay_leftbottom:
		switch (_playerInfo.playerMotion)
		{
		case Player_Idle:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("LeftbottomIdle");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("LeftbottomIdle");
			break;
		case Player_Move:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("LeftbottomMove");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("LeftbottomMove");
			break;
		}
		break;
	case PlayerWay_left:
		switch (_playerInfo.playerMotion)
		{
		case Player_Idle:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("LeftIdle");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("LeftIdle");
			break;
		case Player_Move:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("LeftMove");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("LeftMove");
			break;
		}
		break;
	case PlayerWay_right:
		switch (_playerInfo.playerMotion)
		{
		case Player_Idle:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("RightIdle");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("RightIdle");
			break;
		case Player_Move:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("RightMove");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("RightMove");
			break;
		}
		break;
	case PlayerWay_lefttop:
		switch (_playerInfo.playerMotion)
		{
		case Player_Idle:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("LefttopIdle");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("LefttopIdle");
			break;
		case Player_Move:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("LefttopMove");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("LefttopMove");
			break;
		}
		break;
	case PlayerWay_top:
		switch (_playerInfo.playerMotion)
		{
		case Player_Idle:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("TopIdle");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("TopIdle");
			break;
		case Player_Move:
			_playerInfo.playerimg = IMAGEMANAGER->findImage("TopMove");
			_playerInfo.playerAni = IMAGEMANAGER->findAnimation("TopMove");
			break;
		}
		break;
	}
}
void Player::CameraMove()
{
	CAMERAMANAGER->setCameraCenter(PointMake(_focusPlayerimgX, _focusPlayerimgY));
}
void Player::PlayerPointMake()
{
	_playerInfo.playerPoint = PointMake(_focusPlayerX, _playerInfo.playerRC.bottom );
}
void Player::PlayerMove()
{
	if (KEYMANAGER->isStayKeyDown('W'))//up
	{
		_playerInfo.playerWay = PlayerWay_top;
		_playerInfo.playerMotion = Player_Move;
		PlayerImgSelect();
		_playerInfo.playerAni->start();
		OffsetRect(&_playerInfo.playerimgRC, 0, -5);
	}
	else if (KEYMANAGER->isStayKeyDown('S'))//down
	{
		_playerInfo.playerWay = PlayerWay_bottom;
		_playerInfo.playerMotion = Player_Move;
		PlayerImgSelect();
		_playerInfo.playerAni->start();
		OffsetRect(&_playerInfo.playerimgRC, 0, 5);
	}
	else if (KEYMANAGER->isStayKeyDown('A'))//left
	{
		_playerInfo.playerWay = PlayerWay_left;
		_playerInfo.playerMotion = Player_Move;
		PlayerImgSelect();
		_playerInfo.playerAni->start();
		OffsetRect(&_playerInfo.playerimgRC, -5, 0);
	}
	else if (KEYMANAGER->isStayKeyDown('D'))//right
	{
		_playerInfo.playerWay = PlayerWay_right;
		_playerInfo.playerMotion = Player_Move;
		PlayerImgSelect();
		_playerInfo.playerAni->start();
		OffsetRect(&_playerInfo.playerimgRC, 5, 0);
	}
	else
	{
		_playerInfo.playerMotion = Player_Idle;
		PlayerImgSelect();
		_playerInfo.playerAni->start();
	}
}
void Player::In_inven()
{
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		_isIninven = !_isIninven;
	}
	if (_isIninven)
	{
		Inven->set_invenRC(_focusPlayerX + 350, _focusPlayerY - 100);
		Inven->update();

	}
}
void Player::In_warriorInven()
{
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		_isInWarriorInven = !_isInWarriorInven;
	}
	if (_isInWarriorInven)
	{
		WInven->set_warriorInvenRC(_focusPlayerX , _focusPlayerY - 100);
		WInven->update();

	}
}
void Player::Mounting_item()
{
	
	if (_isIninven)
	{
		for (int i = 0; i < Inven->get_vitem().size(); i++)
		{
				
			if(PtInRect(&Inven->get_vitem()[i].rc, m_ptMouse))
			{
				if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
				{
					Inven->set_itemRC(i, m_ptMouse.x, m_ptMouse.y);
					if (v_playerWarrior.size() != 0)
					{

						if (Inven->get_vitem()[i].kind == STOREKIND_WEAPON)
						{
							_itemtype = 0;
						}
						else if (Inven->get_vitem()[i].kind == STOREKIND_ARMER)
						{
							_itemtype = 1;
						}
						RECT temp;
						if (_isInWarriorInven&&IntersectRect(&temp, &Inven->get_vitem()[i].rc, &get_ItemRC(WInven->get_vectorNum(), _itemtype)))
						{
							if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
							{
								vi_playerWarrior = v_playerWarrior.begin() + WInven->get_vectorNum();
								vi_playerWarrior->warriorItem[_itemtype] = Inven->get_vitem()[i];
								if (_itemtype == 0)
								{
									vi_playerWarrior->atk += Inven->get_vitem()[i].effect;
								}
								else if (_itemtype == 1)
								{
									vi_playerWarrior->def += Inven->get_vitem()[i].effect;
								}
								Inven->remove_vitem(i);
								Inven->set_isMove(false);
								break;
							}
						}
					}
				}
				else
				{
					Inven->set_isMove(false);
				}
			}
			
		}
	}
}
void Player::Remodeling_item()
{
	if (_isInWarriorInven)
	{
		for (int i = 0; i < v_playerWarrior.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (PtInRect(&v_playerWarrior[i].warriorItem[j].rc, m_ptMouse))
				{
					if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
					{
						WInven->set_isitemMove(true);
						vi_playerWarrior = v_playerWarrior.begin() + i;
						vi_playerWarrior->warriorItem[j].rc = RectMakeCenter(m_ptMouse.x, m_ptMouse.y, 62, 62);
						RECT temp;
						if (IntersectRect(&temp, &vi_playerWarrior->warriorItem[j].rc, &Inven->get_invenRC()))
						{
							Inven->inven_push(vi_playerWarrior->warriorItem[j]);
							if (j == 0)
							{
								vi_playerWarrior->atk -= vi_playerWarrior->warriorItem[j].effect;
							}
							else if (j == 1)
							{
								vi_playerWarrior->def -= vi_playerWarrior->warriorItem[j].effect;
							}
							ZeroMemory(&vi_playerWarrior->warriorItem[j],sizeof(STORE_ITEM));
							if (j == 0)
							{
								vi_playerWarrior->warriorItem[j].rc = RectMake(WInven->get_warriorInvenRC().left + 123, WInven->get_warriorInvenRC().top + 223, 62, 62);
							}
							else if (j == 1)
							{
								vi_playerWarrior->warriorItem[j].rc = RectMake(WInven->get_warriorInvenRC().left + 123, WInven->get_warriorInvenRC().top + 223, 62, 62);
							}
							break;
						}
					}
					else
					{
						WInven->set_isitemMove(false);
					}
				}
			}
		}
	}
}
HRESULT Player::init()
{
	playerIdleImgAdd();
	playerMoveImgAdd();

	_playerInfo.playerWay = PlayerWay_bottom;
	_playerInfo.playerMotion = Player_Idle;
	PlayerImgSelect();
	_playerInfo.playerimgRC = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _playerInfo.playerimg->getFrameWidth(), _playerInfo.playerimg->getFrameHeight());
	_playerInfo.playerRC = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 300,240);
	_playerInfo.money = 30000;
	_playerInfo.frameSpeed = 0.2f;
	_playerInfo.playerAni->start();

	_PlayerGen = 0;
	_PlayerKim = 0;
	_PlayerMonk = 0;

	_isDebug = false;
	Inven->init();
	WInven->init();
	_isIninven = false;
	_isInWarriorInven = false;
	_interface = new interFace;
	_interface->init();
	return S_OK;
}
void Player::release()
{
	playerIdleImgRelese();
	playerMoveImgRelese();
}
void Player::update()
{
	
	_focusPlayerimgX = _playerInfo.playerimgRC.right - (_playerInfo.playerimgRC.right - _playerInfo.playerimgRC.left) / 2;
	_focusPlayerimgY = _playerInfo.playerimgRC.bottom - (_playerInfo.playerimgRC.bottom - _playerInfo.playerimgRC.top) / 2;
	_focusPlayerX = _focusPlayerimgX;
	_focusPlayerY = _focusPlayerimgY;
	if (!_interface->get_isInoption())
	{
		CameraMove();
		PlayerPointMake();
		PlayerMove();
		In_inven();
		Mounting_item();
		In_warriorInven();
		if (v_playerWarrior.size() != 0)
		{
			Remodeling_item();
		}
		_interface->update();
		_playerInfo.playerRC = RectMakeCenter(_focusPlayerimgX, _focusPlayerimgY, 40, 70);
		_playerInfo.playerAni->frameUpdate(_playerInfo.frameSpeed);
		if (KEYMANAGER->isOnceKeyDown(VK_F1))
		{
			_isDebug = !_isDebug;
		}
	}

}
void Player::render()
{
	if (_isDebug)
	{
		Rectangle(getMemDC(), _playerInfo.playerimgRC.left, _playerInfo.playerimgRC.top, _playerInfo.playerimgRC.right, _playerInfo.playerimgRC.bottom);
		Rectangle(getMemDC(), _playerInfo.playerRC.left, _playerInfo.playerRC.top, _playerInfo.playerRC.right, _playerInfo.playerRC.bottom);
	}
	_playerInfo.playerimg->aniRender(getMemDC(), _playerInfo.playerimgRC.left, _playerInfo.playerimgRC.top, _playerInfo.playerAni);
	if (_isIninven)
	{
		Inven->render();
	}
	if (_isInWarriorInven)
	{
		WInven->render();
	}
	if (_isIninven)
	{
		Inven->item_render();
	}
	if (_isInWarriorInven)
	{
		WInven->itemRender();
	}
	_interface->render();
}
void Player::player_setFocus(int x, int y)
{
	_playerInfo.playerimgRC = RectMakeCenter(x,y- (_playerInfo.playerimg->getFrameHeight()/2), _playerInfo.playerimg->getFrameWidth(), _playerInfo.playerimg->getFrameHeight());
	_focusPlayerimgX = _playerInfo.playerimgRC.right - (_playerInfo.playerimgRC.right - _playerInfo.playerimgRC.left) / 2;
	_focusPlayerimgY = _playerInfo.playerimgRC.bottom - (_playerInfo.playerimgRC.bottom - _playerInfo.playerimgRC.top) / 2;
	_playerInfo.playerRC = RectMakeCenter(_focusPlayerimgX,_focusPlayerimgY,40,70);
}
void Player::removePlayer(int i)
{
	v_playerWarrior.erase(v_playerWarrior.begin() + i);
}
void Player::set_PlayerWarrior(WARRIOR_NUM warrior, int num, bool plus)
{
	{
		if (warrior == WARRIOR_KIM)
		{
			if (plus)
			{
				_PlayerKim += num;
			}
			else
			{
				_PlayerKim -= num;
			}
		}
		if (warrior == WARRIOR_MONK)
		{
			if (plus)
			{
				_PlayerMonk += num;
			}
			else
			{
				_PlayerMonk -= num;
			}
		}
		if (warrior == WARRIOR_GENERAL)
		{
			if (plus)
			{
				_PlayerGen += num;
			}
			else
			{
				_PlayerGen -= num;
			}
		}
	}
}


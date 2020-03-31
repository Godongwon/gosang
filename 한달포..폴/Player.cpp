#include "stdafx.h"
#include "Player.h"
#include"IsoMap.h"
#include"Astar.h"
#include"inven.h"
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
	_isIninven = false;
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
	CameraMove();
	PlayerPointMake();
	PlayerMove();
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		_isIninven = !_isIninven;
	}
	if (_isIninven)
	{
		Inven->set_invenRC(_focusPlayerX+350, _focusPlayerY-100);
		Inven->update();

	}
	_playerInfo.playerRC = RectMakeCenter(_focusPlayerimgX, _focusPlayerimgY, 40, 70);
	_playerInfo.playerAni->frameUpdate(_playerInfo.frameSpeed);
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_isDebug = !_isDebug;
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


#include "stdafx.h"
#include "gameNode.h"
#include "Player.h"
gameNode::gameNode()
{
}
gameNode::~gameNode()
{
}
image* gameNode::_backBuffer = NULL;
image * gameNode::setBackBuffer()
{

	_backBuffer = new image;
	_backBuffer->init(6000,6000);

	return _backBuffer;
}
HRESULT gameNode::init()
{


	_hdc = GetDC(m_hWnd);
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(m_hWnd);
	_managerInit = managerInit;

	if (managerInit)
	{

		setBackBuffer();
		//SetTimer(m_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		SCENEMANAGER->init();
		SOUNDMANAGER->init();
		EFFECTMANAGER->init();
		CAMERAMANAGER->init();
		PLAYER->init();
	}

	return S_OK;
}

void gameNode::release()

{
	if (_managerInit)
	{
		//타이머 해제
		//KillTimer(m_hWnd, 1);
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		RND->releaseSingleton();
		CAMERAMANAGER->releaseSingleton();
		PLAYER->releaseSingleton();

		KEYMANAGER->release();
		IMAGEMANAGER->release();
		TIMEMANAGER->release();
		SCENEMANAGER->release();
		EFFECTMANAGER->release();
		CAMERAMANAGER->relaese();
		PLAYER->release();
	}

	ReleaseDC(m_hWnd, _hdc);
}

void gameNode::update()
{

	//더블버퍼 이후 사용 하지 않는다.(true->false)
	//InvalidateRect(m_hWnd, NULL, false);
	CAMERAMANAGER->update();
}

void gameNode::render(HDC hdc)
{
}

void gameNode::render()
{
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC hdc;

	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		SUBWIN->setisActive(false);
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);

		m_ptMouse.x = m_ptMouse.x+ CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2;
		m_ptMouse.y= m_ptMouse.y+ CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2;

		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

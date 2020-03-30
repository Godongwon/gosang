#include "stdafx.h"
#include "Window.h"
#include "base/gameNode.h"
#include"IsoMap.h"


POINT Window::ptMouse = POINT{ 0,0 };
CTRL Window::_currentCTRL = CTRL_DRAW;

Window::Window()
{
	_SubWInBackBuffer = new image();
	_SubWInBackBuffer ->init(SUBWINSIZEX,SUBWINSIZEY);

}


Window::~Window()
{
	SAFE_DELETE(_SubWInBackBuffer);
}

void Window::init()
{
	CreateSubWindow();

	_isActive = false;

	int tempX = 10;

	_btnDraw=CreateWindow("button","Draw", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,			tempX, 0, 100, 20, hWnd, HMENU(0), m_hInstance, NULL);
	_btnEraser=CreateWindow("button","Eraser", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,		tempX, 30, 100, 20, hWnd, HMENU(1), m_hInstance, NULL);
	_btnInit=CreateWindow("button","Init", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,			tempX, 60, 100, 20, hWnd, HMENU(2), m_hInstance, NULL);
	_btnSave=CreateWindow("button","SAVE", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,			tempX+115, 0, 100, 20, hWnd, HMENU(3), m_hInstance, NULL);
	_btnLoad=CreateWindow("button","LOAD", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,			tempX+115, 30, 100, 20, hWnd, HMENU(4), m_hInstance, NULL);
	_btnObject=CreateWindow("button","EXIT", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,			SUBWINSIZEX / 2 - 50, SUBWINSIZEY - 50,100,20, hWnd, HMENU(5), m_hInstance, NULL);
	_btnMountin= CreateWindow("button", "Mountin", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,	tempX, 135, 70, 20, hWnd, HMENU(6), m_hInstance, NULL);
	_btnGround= CreateWindow("button", "Ground", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,		tempX, 160, 70, 20, hWnd, HMENU(7), m_hInstance, NULL);
	_btnWater= CreateWindow("button", "Water", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,		tempX +80, 160, 70, 20, hWnd, HMENU(8), m_hInstance, NULL);
	
	_selectWarMap= CreateWindow("button", "전투맵", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, tempX, 100, 100, 30, hWnd, HMENU(9), m_hInstance, NULL);
	_selectTwonMap= CreateWindow("button", "마을맵", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, tempX+115, 100, 100, 30, hWnd, HMENU(10), m_hInstance, NULL);
	
	_btnAll= CreateWindow("button", "All", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,		tempX +115, 60, 100, 20, hWnd, HMENU(11), m_hInstance, NULL);

	clickFrame = { 0,0 };
	_clickIndex = 0;

}

void Window::release()
{
}

void Window::update()
{
	if(_currentScene != NULL)
	{
		_currentScene->update();
	}
}

void Window::render()
{
	HDC hdc = GetDC(hWnd);
	PatBlt(_SubWInBackBuffer->getMemDC(), 0, 0, SUBWINSIZEX,SUBWINSIZEY, WHITENESS);
	//==============================================================================
	if (_currentScene != NULL)
	{
		_currentScene->render(_SubWInBackBuffer->getMemDC());
	}
	//==============================================================
	_SubWInBackBuffer->render(hdc);
	ReleaseDC(hWnd, hdc);
}

void Window::setScene(gameNode * Scene)
{
	_currentScene = Scene;
	_currentScene->init();
}

LRESULT Window::WndLogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_MOUSEMOVE:

		SUBWIN->setisActive(true);

		ptMouse.x = LOWORD(lParam);
		ptMouse.y = HIWORD(lParam);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		default:
			switch (LOWORD(wParam))
			{
			default:
			case CTRL_DRAW:
			case CTRL_ERASER:
				_currentCTRL = (CTRL)(LOWORD(wParam));
				break;
			case CTRL_INIT:
				SUBWIN->getIsoMap()->init();
				break;
			case CTRL_SAVE:
				SUBWIN->getIsoMap()->Save();
				break;
			case CTRL_LOAD:
				SUBWIN->getIsoMap()->Load();
				break;
			case CTRL_OBJECT:
				DestroyWindow(hWnd);
				SCENEMANAGER->changeScene("StartScene");
				break;
			case CTRL_MOUNTIN:
			case CTRL_GROUND:
			case CTRL_WATER:
				SUBWIN->setFrameIndex(LOWORD(wParam) - 6);
				break;
			case CTRL_WARMAP:
			case CTRL_TWONMAP:
				_currentCTRL = (CTRL)(LOWORD(wParam));
				break;
			case CTRL_ALL:
				SUBWIN->getIsoMap()->All();
				break;
			}
			break;
		}
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



void Window::CreateSubWindow()
{
	//로그 윈도우 생성
	int x, y, cx, cy;
	WNDCLASS wc;
	RECT rc;

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)Window::WndLogProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "맵툴소스";
	RegisterClass(&wc);
	//부모 윈도우 오른쪽으로 배치
	RECT rcWin;
	GetWindowRect(m_hWnd, &rcWin);

	cx = SUBWINSIZEX;
	cy = SUBWINSIZEY;
	x = rcWin.right;
	y = rcWin.top;

	rc.left = 0;
	rc.top = 0;
	rc.right = cx;
	rc.bottom = cy;

	HWND hParenthWnd = NULL;
	HINSTANCE hInst = NULL;

	hParenthWnd = m_hWnd;
	hInst = GetModuleHandle(NULL);

	hWnd=CreateWindow("맵툴소스", "맵툴소스", WS_POPUP | WS_CAPTION | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,x, y, cx, cy, hParenthWnd, NULL, hInst, NULL);

	AdjustWindowRect(&rc, WINSTYLE, FALSE);

	SetWindowPos(hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER);

	ShowWindow(hWnd, SW_SHOW);
}

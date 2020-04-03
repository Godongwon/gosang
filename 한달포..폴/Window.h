#pragma once
#include"base/singletonBase.h"


#define SUBWINSIZEX 300
#define SUBWINSIZEY 600

enum CTRL
{
	CTRL_DRAW,
	CTRL_ERASER,
	CTRL_INIT,//�׸��⵵��
	CTRL_SAVE,
	CTRL_LOAD,//���� �ҷ����� ����
	CTRL_EXIT,
	CTRL_MOUNTIN,
	CTRL_GROUND,
	CTRL_WATER,//�Ӽ�
	CTRL_TREE,
	CTRL_WARMAP,	//���� ��
	CTRL_TWONMAP,	//����
	CTRL_ALL,	//all
	CTRL_END
};

class IsoMap;

class Window : public singletonBase<Window>
{
private:

	HWND hWnd;
	static POINT ptMouse;

	image* _SubWInBackBuffer; //���������� �����
	gameNode* _currentScene;
	//�׸��� ����
	HWND _btnDraw;
	HWND _btnEraser;
	HWND _btnInit;
	//���� , �ҷ�����
	HWND _btnSave;
	HWND _btnLoad;
	//Ÿ�� �Ӽ� ���ϱ� 
	HWND _btnEXIT;
	HWND _btnMountin;
	HWND _btnGround;
	HWND _btnWater;
	HWND _btnTree;
	
	
	HWND _selectWarMap;
	HWND _selectTwonMap;
	HWND _btnAll;



	static CTRL _currentCTRL;
	POINT clickFrame;
	int _clickIndex;

	bool _isActive;

	IsoMap* Map;

public:
	Window();
	~Window();

	void init();
	void release();
	void update();
	void render();

	void setScene(gameNode* Scene);
	static LRESULT CALLBACK WndLogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	HWND getHwnd() { return hWnd; }

	static POINT getSubWinMousePos() { return ptMouse; }
	
	static CTRL getCTRL() { return _currentCTRL; }
	void setCTRL(CTRL ctrl) { _currentCTRL = ctrl; }

	void setisActive(bool isActive) { this->_isActive = isActive; }
	bool getIsActive() { return _isActive; }
	
	void setFramePoint(POINT frame) { clickFrame = frame; }
	POINT getFramePoint() { return clickFrame; }

	void setFrameIndex(int index) { _clickIndex = index; }
	int  getFrameIndex() {	return _clickIndex;	}

	void setIsoMap(IsoMap* map) { this->Map = map; }
	IsoMap* getIsoMap() { return Map; }

	void CreateSubWindow();





};


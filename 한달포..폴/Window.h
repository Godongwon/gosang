#pragma once
#include"base/singletonBase.h"


#define SUBWINSIZEX 300
#define SUBWINSIZEY 600

enum CTRL
{
	CTRL_DRAW,
	CTRL_ERASER,
	CTRL_INIT,//그리기도구
	CTRL_SAVE,
	CTRL_LOAD,//저장 불러오기 도구
	CTRL_EXIT,
	CTRL_MOUNTIN,
	CTRL_GROUND,
	CTRL_WATER,//속성
	CTRL_TREE,
	CTRL_WARMAP,	//전투 맵
	CTRL_TWONMAP,	//마을
	CTRL_ALL,	//all
	CTRL_END
};

class IsoMap;

class Window : public singletonBase<Window>
{
private:

	HWND hWnd;
	static POINT ptMouse;

	image* _SubWInBackBuffer; //서브윈도우 백버퍼
	gameNode* _currentScene;
	//그리기 도구
	HWND _btnDraw;
	HWND _btnEraser;
	HWND _btnInit;
	//저장 , 불러오기
	HWND _btnSave;
	HWND _btnLoad;
	//타일 속성 정하기 
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


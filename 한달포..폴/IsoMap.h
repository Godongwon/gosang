#pragma once
#include"base/gameNode.h"
#include"IsoTile.h"
class IsoMap : public gameNode, public singletonBase<IsoMap>
{
private:
	tagTILE _tileMap[TILE_COUNT_X][TILE_COUNT_Y];

	int _isoX, _isoY;
	int _center;
	char _tileNum[128];

	int _isoClickX, _isoClickY;
	POINT p[5];
	POINT imageFrame;
	CTRL _currentCTRL;

	HANDLE _WarMap;
	HANDLE _TwonMap;
	DWORD write;
	DWORD read;


	bool _isDebug;


public:
	IsoMap();
	~IsoMap();

	HRESULT init();
	void release();
	void update();
	void render();
	//leftrop
	void LeftTop();
	//타일맵을 그리자
	void DrawTileMap();
	//마름모를 그리자
	void DrawRhombus();
	//코너검출
	int getCornerIndex(int isoX, int isoY);
	//마름모 안에 있음?
	bool isInRhombus(int corner, int isoX, int isoY);

	void MapSetup();
	void setMap(int isoX, int isoY, bool isAdd);
	TILEKIND kindSelect(int frameX, int frameY);
	
	//카메라 이동
	void CameraMove();

	void TileInit();
	void Load();
	void Save();
	void All();

	void Mouse_click();
	int get_isoClickX() { return _isoClickX; }
	int get_isoClickY() { return _isoClickY; }
	tagTILE get_tileMap(int x, int y){return _tileMap[x][y];}
	TILEKIND get_tileKind(int x, int y) {return _tileMap[x][y].tileKind[1];}
};

#define ISOMAP IsoMap::getSingleton()


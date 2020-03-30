#include "stdafx.h"
#include "TwonScene.h"
#include "IsoMap.h"
//#include "Player.h"

TwonScene::TwonScene()
{
}


TwonScene::~TwonScene()
{
}

HRESULT TwonScene::init()
{
	
	//맵 타일 이미지
	IMAGEMANAGER->addFrameImage("Ground", "resource/image/맵툴/maptoolGround.bmp", 320, 320, 5, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Mountin", "resource/image/맵툴/maptoolMountin.bmp", 320, 256, 5, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Water", "resource/image/맵툴/maptoolWater.bmp", 320, 192, 5, 6, true, RGB(255, 0, 255));
	//로드
	townload();
	//===========================================================================================================================================================
	_townMonster = new townMonster;
	_townMonster->init();

	_store = new store;
	_store->init();
	_store->set_storeXY(_tileMap[35][35].centerX, _tileMap[35][35].centerY);

	_warriorStore = new warriorStore;
	_warriorStore->init();
	_warriorStore->set_warriorStore(_tileMap[15][35].centerX, _tileMap[15][35].centerY);

	for (int i = 0; i < _townMonster->get_vMonster().size(); i++)
	{
		int a =RND->getFromIntTo(0, 30);
		int b =RND->getFromIntTo(0, 30);
		_townMonster->set_TwonMonsterXY(i, _tileMap[a][b].centerX, _tileMap[a][b].centerY);
	}
	

	PLAYER->player_setFocus(_tileMap[69][69].centerX, _tileMap[69][69].centerY);
	istextOut = false;
	_textCount = 0;
	
	return S_OK;
}
void TwonScene::release()
{
	SAFE_DELETE(_townMonster);
	SAFE_DELETE(_store);
	SAFE_DELETE(_warriorStore);
}
void TwonScene::update()
{
	monsterturn();
	_townMonster->update();
	_store->update();
	_warriorStore->update();
	if (_townMonster->get_isSceneChange())
	{
		if (PLAYER->get_vPlayerWarrior().size() == 0)
		{
			_townMonster->set_SceneChange(false);
			istextOut = true;
		}
		else
		{
			SCENEMANAGER->changeScene("War");
		}
	}
	if (istextOut)
	{
		_textCount++;
	}
	PLAYER->update();


}
void TwonScene::render()
{                 
	Draw();

	if (_store->get_isOpenStore())
	{
		PLAYER->render();
		_store->render();
	}
	else if (_warriorStore->get_isOpenWarriorStore())
	{
		PLAYER->render();
		_warriorStore->render();
	}
	else
	{
		_townMonster->render();
		_warriorStore->render();
		_store->render();
		PLAYER->render();
	}
	_townMonster->countRender();
	if (istextOut&&_textCount < 300)
	{
	FontTextOut(getMemDC(),PLAYER->Player_getFocusX()-100,PLAYER->Player_getFocusY(),"고용된 용병이 없습니다!!", 20, "HY견고딕", RGB(255, 255, 255));
	}
	if (_textCount > 301)
	{
		istextOut = false;
		_textCount = 0;
	}

}
void TwonScene::townload()
{
	HANDLE _map;
	DWORD read;
	_map = CreateFile("TWONMAP.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(_map, _tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y), &read, NULL);
	CloseHandle(_map);
}
void TwonScene::Draw()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			if (CAMERAMANAGER->getCameraXY().x - 30 < _tileMap[i][j].p[1].x && (CAMERAMANAGER->getCameraXY().x + WINSIZEX) + 30 > _tileMap[i][j].p[3].x
				&& CAMERAMANAGER->getCameraXY().y - 30 < _tileMap[i][j].p[0].y && (CAMERAMANAGER->getCameraXY().y + WINSIZEY) + 30 > _tileMap[i][j].p[2].y)
			{

				for (int z = 0; z <= _tileMap[i][j].index; z++)
				{
					if (_tileMap[i][j].tileKind[z] != TILEKIND_NONE)
					{
						switch (_tileMap[i][j].tileNum[z])
						{
						case 0:
							IMAGEMANAGER->frameRender("Mountin", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height*z,
								_tileMap[i][j].tilePoint[z].x,
								_tileMap[i][j].tilePoint[z].y);
							break;
						case 1:
							IMAGEMANAGER->frameRender("Ground", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height*z,
								_tileMap[i][j].tilePoint[z].x,
								_tileMap[i][j].tilePoint[z].y);
							break;
						case 2:
							IMAGEMANAGER->frameRender("Water", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height * z,
								_tileMap[i][j].tilePoint[z].x,
								_tileMap[i][j].tilePoint[z].y);
							break;
						}
					}
				}

			}
		}
	}
	
}
void TwonScene::monsterturn()
{
	
	for (int i = 0; i < _townMonster->get_vMonster().size(); i++)
	{
		for (int a = 0; a < TILE_COUNT_X; a++)
		{
			if (_townMonster->get_MonsterWay(i) == MONSTERWAY_LEFT)
			{
				if (_tileMap[0][a].p[3].x > _townMonster->get_viMonsterXY(i).x)
				{
					_townMonster->set_Monsterturn(i, true);
				}
				if (_tileMap[a][69].p[0].x > _townMonster->get_viMonsterXY(i).x)
				{
					_townMonster->set_Monsterturn(i, true);
				}
				
			}
			if (_townMonster->get_MonsterWay(i) == MONSTERWAY_RIGHT)
			{

				if (_townMonster->get_viMonsterXY(i).x > _tileMap[a][0].p[1].x)
				{
					_townMonster->set_Monsterturn(i, true);

				}
				if (_townMonster->get_viMonsterXY(i).x > _tileMap[69][a].p[1].x)
				{
					_townMonster->set_Monsterturn(i, true);
				}

			}
		}
	}
	
}

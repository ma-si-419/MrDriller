#include "Stage.h"
namespace
{
	constexpr int kmapY = 4;
	constexpr int kmapX = 10;
}
Stage::Stage()
{
}
Stage::~Stage()
{
}
void Stage::Init()
{
	int stageMat[kmapY][kmapX] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	};
}

void Stage::Update()
{
}

void Stage::Draw()
{
	for (int y = 0; y < kmapY; y++)
	{
		for (int x = 0; x < kmapX; x++)
		{
			LoadMapData(stageMat[y][x]);
		}
	}
}
void LoadMapData(int mapData)
{
	//�}�b�v�f�[�^���O��������
	if (mapData == 0)
	{
		//�Ȃɂ����Ȃ�
	}
	//�}�b�v�f�[�^���P��������
	if (mapData == 1)
	{

	}
}

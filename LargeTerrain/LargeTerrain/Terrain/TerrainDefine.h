#pragma once
#include "stdafx.h"

namespace TERRAIN
{
	const INT32 WORLD_SIZE = 10240;

	const INT32 SECTOR_SIZE_MAX = 2048;
	const INT32 SECTOR_SIZE_MIN = 64;

	const INT32 ROOT_SECTOR_COUNT = (WORLD_SIZE / SECTOR_SIZE_MAX);

	const INT32 TILE_COUNT = 128;
	const INT32 HEIGHT_COUNT = TILE_COUNT + 1;

	const WCHAR SECTOR_FILE_PATH[MAX_PATH] = L"../bin/Resources/Map/Terrain/";
	const WCHAR SECTOR_FILE_NAME_FORMAT[MAX_PATH] = L"%02d_%04d_%04d.bin";

	enum class LOD_LEVEL
	{
		LOD_0, LOD_1, LOD_2, LOD_3, LOD_4, LOD_5, END
	};

	enum class SECTOR_CHILD_TYPE
	{
		LT, RT, RB, LB, END
	};

	constexpr float TILE_SIZE(LOD_LEVEL lodLevel)
	{
		//LOD레벨에 따라 0.5, 1, 2, 4, 8 , 16   타일 사이즈를 가진
		return 0.5f * (1 << (int)lodLevel);
	}

	constexpr float SECTOR_SIZE(LOD_LEVEL lodLevel)
	{
		return TILE_SIZE(lodLevel) * TILE_COUNT;
	}

	constexpr std::pair<int, int> GetSectorXY(LOD_LEVEL lodLevel, float posX, float posY)
	{
		float tileSize = TILE_SIZE(lodLevel);
		int sectorX = (int)(posX / tileSize);
		int sectorY = (int)(posY / tileSize);

		int sectorSize = (int)(SECTOR_SIZE(lodLevel));

		sectorX = std::min(std::max(0, sectorX), sectorSize - 1);
		sectorY = std::min(std::max(0, sectorY), sectorSize - 1);

		return std::make_pair(sectorX, sectorY);
	}
};


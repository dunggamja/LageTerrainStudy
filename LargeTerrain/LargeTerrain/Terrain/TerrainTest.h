#pragma once
#include "TerrainDefine.h"

namespace TERRAIN
{
	class TerrainTest : public Singleton<TerrainTest>
	{
	public:
		void CreateMapToTest(const std::wstring& rootPath, LOD_LEVEL lodLevel, int sectorX, int sectorY);
		void ReadMapToTest(const std::wstring& rootPath, LOD_LEVEL lodLevel, int sectorX, int sectorY);

		void CreateMapAllToTest();
	};
	
};
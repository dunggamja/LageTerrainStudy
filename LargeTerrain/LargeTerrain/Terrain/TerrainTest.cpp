#include "TerrainTest.h"

void TERRAIN::TerrainTest::CreateMapToTest(const std::wstring& rootPath, LOD_LEVEL lodLevel, int sectorX, int sectorY)
{
	WCHAR pathName[MAX_PATH] = { 0, };
	wsprintf(pathName, L"%s/%02d_%04d_%04d.bin", rootPath.c_str(), (int)lodLevel, sectorX, sectorY);

	float	height[HEIGHT_COUNT * HEIGHT_COUNT] = { 0, };
	VECTOR3	normal[HEIGHT_COUNT * HEIGHT_COUNT];
	bool	albedo[TILE_COUNT * TILE_COUNT] = { false, };

	std::ofstream output(pathName, std::ios::binary | std::ios::trunc);
	output.write((char*)height, sizeof(height));
	output.write((char*)normal, sizeof(normal));
	output.write((char*)albedo, sizeof(albedo));
	output.close();
}


void TERRAIN::TerrainTest::ReadMapToTest(const std::wstring& rootPath, LOD_LEVEL lodLevel, int sectorX, int sectorY)
{
	float	height[HEIGHT_COUNT * HEIGHT_COUNT] = { 0, };
	VECTOR3	normal[HEIGHT_COUNT * HEIGHT_COUNT];
	bool	albedo[TILE_COUNT * TILE_COUNT] = { false, };

	WCHAR pathName[MAX_PATH] = { 0, };
	wsprintf(pathName, L"%s/%02d_%04d_%04d.bin", rootPath.c_str(), (int)lodLevel, sectorX, sectorY);
	std::ifstream input(pathName, std::ios::binary);
	input.read((char*)height, sizeof(height));
	input.read((char*)normal, sizeof(normal));
	input.read((char*)albedo, sizeof(albedo));

	input.close();

	int a = 0;
}

void TERRAIN::TerrainTest::CreateMapAllToTest()
{
	std::wstring rootPath = L"../bin/Resources/Map/Terrain";
	for (int lodLevel = (int)TERRAIN::LOD_LEVEL::LOD_0; lodLevel < (int)TERRAIN::LOD_LEVEL::END; ++lodLevel)
	{
		int sectorCount = TERRAIN::ROOT_SECTOR_COUNT << ((int)TERRAIN::LOD_LEVEL::LOD_5 - lodLevel);
		concurrency::parallel_for(0, sectorCount, [&](int y)
		{
			for (int x = 0; x < sectorCount; ++x)
			{
				CreateMapToTest(rootPath, TERRAIN::LOD_LEVEL::LOD_0, x, y);
			}
		});
		/*for (int y = 0; y < sectorCount; ++y)
		{
			for (int x = 0; x < sectorCount; ++x)
			{
				CreateMapToTest(rootPath, (TERRAIN::LOD_LEVEL)lodLevel, x, y);
			}
		}*/
	}
}
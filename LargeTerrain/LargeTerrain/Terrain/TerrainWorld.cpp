#include "TerrainWorld.h"
#include "TerrainSector.h"

namespace TERRAIN 
{

	std::shared_ptr<Sector> World::GetSector(LOD_LEVEL lodLevel, int sectorX, int sectorY)
	{
		auto& sectorRepo = m_LODSectors.at((size_t)lodLevel);
		auto iterFind = sectorRepo.find(std::make_pair(sectorX, sectorY));
		if (iterFind != sectorRepo.end())
			return iterFind->second;
		else
			return std::shared_ptr<Sector>();
	}

	void World::StreamSectors(POS_XY playerPos)
	{
		std::list<std::pair<int, int>> loadSectors[(int)TERRAIN::LOD_LEVEL::END];

		
		concurrency::parallel_for(0, (int)TERRAIN::LOD_LEVEL::END, [&](int lodLevel)
		{
			auto& sectorRepo = m_LODSectorsOnLoading[lodLevel];
			
			sectorRepo.clear();
			for (auto& sectorXY : loadSectors[lodLevel])
			{
				auto pCurrentSector = GetSector((LOD_LEVEL)lodLevel, sectorXY.first, sectorXY.second);
				if (pCurrentSector == nullptr)
				{
					auto pNewSector = CreateSectorFromFile((LOD_LEVEL)lodLevel, sectorXY.first, sectorXY.second);
				}
			}

			m_LODSectors[lodLevel] = std::move(sectorRepo);
		});
	}


	std::shared_ptr<Sector> World::CreateSectorFromFile(LOD_LEVEL lodLevel, int sectorX, int sectorY)
	{
		auto pSector = std::make_shared<Sector>(sectorX, sectorY, lodLevel);
		if (!pSector)
			return std::shared_ptr<Sector>();


		WCHAR pathName[MAX_PATH] = { 0, };
		lstrcatW(pathName, SECTOR_FILE_PATH);
		lstrcatW(pathName, SECTOR_FILE_NAME_FORMAT);
		wsprintf(pathName, pathName, (int)lodLevel, sectorX, sectorY);
		
		
		std::ifstream input(pathName, std::ios::binary);
		input.read((char*)(pSector->GetHeights().data()), (pSector->GetHeights().size() * sizeof(std::remove_reference_t<decltype(pSector->GetHeights())>::value_type)));
		input.read((char*)(pSector->GetNormals().data()), (pSector->GetNormals().size() * sizeof(std::remove_reference_t<decltype(pSector->GetNormals())>::value_type)));
		input.read((char*)(pSector->GetAlbedos().data()), (pSector->GetAlbedos().size() * sizeof(std::remove_reference_t<decltype(pSector->GetAlbedos())>::value_type)));
		input.close();

		return pSector;
	}
};


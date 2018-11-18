#pragma once
#include "TerrainDefine.h"


namespace TERRAIN
{
	class Sector;
	class World : public Singleton<World>
	{
	public:
		using POS_XY = std::pair<float, float>;
		using MAP_SECTOR_INDEXED_POS_XY = boost::unordered_map < POS_XY, std::shared_ptr<Sector>>;
		using SECTOR_LOD_STREAM_CONTAINER = std::array<MAP_SECTOR_INDEXED_POS_XY, (int)TERRAIN::LOD_LEVEL::END>;

	private:		
		SECTOR_LOD_STREAM_CONTAINER		m_LODSectors;
		SECTOR_LOD_STREAM_CONTAINER		m_LODSectorsOnLoading;

	public:
		std::shared_ptr<Sector> GetSector(LOD_LEVEL lodLevel, int sectorX, int sectorY);
	public:
		void StreamSectors(POS_XY playerPos);

	private:
		std::shared_ptr<Sector> CreateSectorFromFile(LOD_LEVEL lodLevel, int sectorX, int sectorY);

	};
};
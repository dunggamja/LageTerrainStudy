#pragma once
#include "TerrainDefine.h"

namespace TERRAIN
{
	class Sector : public std::enable_shared_from_this<Sector>
	{
	public:
		using SharedPtr = std::shared_ptr<Sector>;
	private:
		float m_SectorX = 0.f;
		float m_SectorY = 0.f;
		LOD_LEVEL	m_LodLevel = LOD_LEVEL::LOD_0;

		std::array<float,	HEIGHT_COUNT * HEIGHT_COUNT>	m_Heights;		//���̰�.
		std::array<VECTOR3, HEIGHT_COUNT * HEIGHT_COUNT>	m_Normals;		//�븻��	����
		std::array<bool,	TILE_COUNT * TILE_COUNT>		m_Albedos;		//��ȿ�� Ÿ���ΰ�?

	public:
		Sector() = default;
		Sector(float sectorX, float sectorY, LOD_LEVEL lodLevel)
			: m_SectorX(sectorX), m_SectorY(sectorY), m_LodLevel(lodLevel)
		{}
		

		decltype(m_Heights)&	GetHeights() { return m_Heights; }
		decltype(m_Normals)&	GetNormals() { return m_Normals; }
		decltype(m_Albedos)&	GetAlbedos() { return m_Albedos; }

	};
};

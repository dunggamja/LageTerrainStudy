#pragma once
#include "stdafx.h"

class Object
{
private:
	INT64	m_ID = 0;
	VECTOR3 m_Position = { 0.f, 0.f, 0.f };

public:
	Object() = default;
	Object(INT64 id, VECTOR3 position = { 0.f, 0.f, 0.f })
		: m_ID(id)
		, m_Position(position)
	{}

public:
	INT64	GetID() const		{ return m_ID; }
	
	VECTOR3 GetPosition() const						{ return m_Position; }
	void	SetPosition(const VECTOR3& position)	{ m_Position = position; }

};
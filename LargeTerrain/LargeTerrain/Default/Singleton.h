#pragma once
#include "Define.h"

template <typename T>
class Singleton
{
public:
	virtual ~Singleton() {};


private:
	static std::unique_ptr<T>	m_Instance;
	static std::once_flag		m_Onceflag;

	Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton operator =(const Singleton&) = delete;

public:
	static T*	Instance()
	{
		std::call_once(m_Onceflag, []() 
		{
			m_Instance = std::unique_ptr<T>();
		});

		return m_Instance.get();
	}
};

template<typename T> std::unique_ptr<T>	Singleton<T>::m_Instance = nullptr;
template<typename T> std::once_flag		Singleton<T>::m_Onceflag; 

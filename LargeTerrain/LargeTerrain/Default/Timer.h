#pragma once

class Timer
{
public:
	Timer();

	float TotalTime()const; // in seconds
	float DeltaTime()const; // in seconds

	void Reset(); // Call before message loop.
	void Start(); // Call when unpaused.
	void Stop();  // Call when paused.
	void Tick();  // Call every frame.

private:
	double m_SecondsPerCount;
	double m_DeltaTime;

	INT64 m_BaseTime;
	INT64 m_PausedTime;
	INT64 m_StopTime;
	INT64 m_PrevTime;
	INT64 m_CurrTime;

	bool m_Stopped;
};
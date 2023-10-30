#pragma once
/// <summary>
/// Helper class to perform stopwatch functions, typically for measuring 
/// cooldown/lockout times.
/// </summary>

class ticker
{
public:
	ticker();
	ticker(const float startTime);
	void restart();
	void resetTime();
	void wake();
	void sleep();
	void tick(float dt);
	void forceEnd();
	bool isActive() const;
	bool ended() const;

private:
	bool active = false;
	float START_TIME;
	float time = 0.0f;
};


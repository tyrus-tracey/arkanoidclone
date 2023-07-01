#pragma once
/// <summary>
/// Helper class to perform stopwatch functions, typically for measuring 
/// cooldown/lockout times.
/// </summary>

class ticker
{
public:
	ticker(const float startTime);
	void reset();
	void stop();
	void tick(float dt);
	bool isActive() const;

private:
	bool active = false;
	float START_TIME;
	float time = 0.0f;
};


#pragma once

class Flag 
{
public:
	Flag() = default;
	Flag(const bool b);
	void raise();
	void clear();
	bool update();
	bool isRaised() const;

private:
	bool flagStatus = false;
};
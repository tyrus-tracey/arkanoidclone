#pragma once
#include "brickType.h"
#include "Flag.h"
#include "Soundbank.h"

class EventManager
{
public:
	EventManager(Soundbank& _soundbank);

	void brickHit(brickTypeEnum bType) const;
	void brickKill(brickTypeEnum bType) const;

	void paddleHit() const;

	void ballWallRebound() const;
	void ballDetonate() const;
	void ballLockBeep() const;

	void coreExplodeStart();
	void coreExplodeMini() const;
	void coreExplodeFinal() const;

	void levelNewLoaded();

	Flag flag_LevelGoalsComplete{ false };
	Flag flag_LevelOver{ false };
	Flag flag_ArmedBallLocked{ false };

	Flag flag_ballHoldSpawn{ false };

private:
	Soundbank& soundbank;
};


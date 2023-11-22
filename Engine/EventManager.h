#pragma once
#include "brickType.h"
#include "Flag.h"
#include "Soundbank.h"
#include "Scoreboard.h"

class EventManager
{
public:
	EventManager(Soundbank& _soundbank, Scoreboard& _scoreboard);

	void brickHit(brickTypeEnum bType) const;
	void brickKill(brickTypeEnum bType) const;

	void paddleHit() const;

	void ballWallRebound() const;
	void ballDissipate() const;
	void ballDetonate() const;
	void ballLockBeep() const;
	void ballArmed() const;

	void coreBallHold();
	void coreBallRelease();
	void coreExplodeStart();
	void coreExplodeMini() const;
	void coreExplodeFinal() const;

	void levelNewLoaded();

	Flag flag_LevelGoalsComplete{ false };
	Flag flag_LevelOver{ false };
	Flag flag_ArmedBallLocked{ false };

	Flag flag_ballHoldSpawn{ false };
	Flag flag_ClearAllBalls{ false };

private:
	Soundbank& soundbank;
	Scoreboard& scoreboard;
};

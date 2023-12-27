#pragma once
#include "brickType.h"
#include "Flag.h"
#include "Soundbank.h"
#include "Scoreboard.h"
#include "AnimationManager.h"

class EventManager
{
public:
	EventManager(Soundbank& _soundbank, Scoreboard& _scoreboard, AnimationManager& _animManager);
	void gameReset(Graphics& gfx);
	void gameStart();
	void resetFlags();

	void brickSpawn(const brickTypeEnum bType) const;
	void brickHit(brickTypeEnum bType) const;
	void brickKill(const brickTypeEnum bType, const Color bCol, const Vec2 bPos) const;
	void brickExplode(const brickTypeEnum bType, const Color bCol, const Vec2 bPos) const;

	void paddleHit() const;

	void ballLost();
	void ballWallRebound() const;
	void ballDissipate() const;
	void ballDetonate() const;
	void ballLockBeep() const;
	void ballArmed() const;

	void coreBallHold();
	void coreBallRelease();
	void coreExplodeStart();
	void coreExplodeMini() const;
	void coreExplodeFinal(const Vec2 pos) const;

	void levelNewLoaded();
	void levelReady();

	Flag flag_LevelGoalsComplete{ false };
	Flag flag_LevelOver{ false };
	Flag flag_LevelSpawnBall{ false };
	Flag flag_ArmedBallLocked{ false };

	Flag flag_ballLost{ false };
	Flag flag_ballHoldSpawn{ false };
	Flag flag_ClearAllBalls{ false };

private:
	Soundbank& soundbank;
	Scoreboard& scoreboard;
	AnimationManager& animManager;
};


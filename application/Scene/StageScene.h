#pragma once
#include "../Enemy/Enemy.h"
#include "../Player/Player.h"
#include "IScene.h"
#include "Novice.h"

class StageScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	std::unique_ptr<Player> player_;
	std::vector<std::unique_ptr<Enemy>> enemies_;
	bool isClear = false;
	int BackGround;
	int Left;
	int Right;
};

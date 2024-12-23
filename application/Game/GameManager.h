#pragma once
#include "../Input/InputManager.h"
#include "../Scene/IScene.h"
#include "../Scene/StageScene.h"
#include "../Scene/TitleScene.h"
#include "../Scene/ClearScene.h"
#include "Novice.h"
#include "memory"
class GameManager {
private:
	std::unique_ptr<IScene> sceneArr_[3];
	InputManager* inputManager_;

	int currentSceneNo_ = 0;
	int prevSceneNo_ = 0;

public:
	GameManager();
	~GameManager();
	int Run();
};

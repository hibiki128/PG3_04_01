#include "StageScene.h"
#include <dinput.h>

void StageScene::Init() { 
	inputManager_ = InputManager::GetInstance();
}

void StageScene::Update() {

	if (inputManager_->GetPreKey(DIK_SPACE) == 0 && inputManager_->GetKey(DIK_SPACE) != 0) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw() {  }

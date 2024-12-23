#include "TitleScene.h"
#include <dinput.h>

void TitleScene::Init() { 
	inputManager_ = InputManager::GetInstance();
}

void TitleScene::Update() {

	if (inputManager_->GetPreKey(DIK_SPACE) == 0 && inputManager_->GetKey(DIK_SPACE) != 0) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() { }

#include "TitleScene.h"
#include <dinput.h>

void TitleScene::Init() { 
	inputManager_ = InputManager::GetInstance();
	tex_ = Novice::LoadTexture("./resources/images/space.png");
}

void TitleScene::Update() {

	if (inputManager_->GetPreKey(DIK_SPACE) == 0 && inputManager_->GetKey(DIK_SPACE) != 0) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() { 
Novice::DrawSprite(280, 240, tex_, 1, 1, 0.0f, 0xffffffff);
}

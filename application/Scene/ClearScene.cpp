#include "ClearScene.h"
#include <dinput.h>

void ClearScene::Init() {
	inputManager_ = InputManager::GetInstance();
	tex_ = Novice::LoadTexture("./resources/images/space.png");
	tex2_ = Novice::LoadTexture("./resources/images/clear.png");
}

void ClearScene::Update() {

	if (inputManager_->GetPreKey(DIK_SPACE) == 0 && inputManager_->GetKey(DIK_SPACE) != 0) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() { 
Novice::DrawSprite(280, 540, tex_, 1, 1, 0.0f, 0xffffffff);
Novice::DrawSprite(280, 240, tex2_, 1, 1, 0.0f, 0xffffffff);
}

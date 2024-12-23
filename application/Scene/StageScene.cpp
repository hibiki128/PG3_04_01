#include "StageScene.h"
#include <dinput.h>

void StageScene::Init() {
	inputManager_ = InputManager::GetInstance();
	BackGround = Novice::LoadTexture("./resources/images/BackGround.png");
	Left = Novice::LoadTexture("./resources/images/Left.png");
	Right = Novice::LoadTexture("./resources/images/Right.png");
	player_ = std::make_unique<Player>();
	player_->Init();

	enemies_.resize(3); // 3体の敵を配置
	for (size_t i = 0; i < enemies_.size(); ++i) {
		enemies_[i] = std::make_unique<Enemy>();
		enemies_[i]->Init();

		float posY = 50.0f;

		float spacing = 1120.0f / 3.0f;

		float posX = 240.0f + i * spacing;

		// 敵の位置を設定
		enemies_[i]->SetPos({posX, posY});
	}
	isClear = false;
}


void StageScene::Update() {

	player_->Update();
	for (auto& enemy : enemies_) {
		enemy->SetBullets(player_->GetBullets());
		enemy->Update();
	}

	bool allEnemiesDead = true;
	for (auto& enemy : enemies_) {
		if (!enemy->IsDead()) {
			allEnemiesDead = false;
			break;
		}
	}

	if (allEnemiesDead) {
		isClear = true;
	}

	if (isClear) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw() { 
	Novice::DrawSprite(180, 0, BackGround, 1, 1, 0.0f, 0xffffffff);
	Novice::DrawSprite(0, 0, Left, 1, 1, 0.0f, 0xffffffff);
	Novice::DrawSprite(1100, 0, Right, 1, 1, 0.0f, 0xffffffff);
	player_->Draw();
	for (auto& enemy : enemies_) {
		enemy->Draw();
	}
}

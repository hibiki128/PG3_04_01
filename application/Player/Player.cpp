#include "Player.h"

void Player::Init() {
	input_ = InputManager::GetInstance();
	playerTex_ = Novice::LoadTexture("./resources/images/player.png");
	pos_ = {640.0f, 600.0f};
	scale_ = {0.5f, 0.5f};
	speed_ = {5.0f, 5.0f};
}

void Player::Update() {
	Move();
	Attack();
	for (auto& bullet : bullets_) {
		bullet->Update();
	}
}

void Player::Draw() {
	Novice::DrawSprite(int(pos_.x), int(pos_.y), playerTex_, scale_.x, scale_.y, 0.0f, 0xffffffff);
	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
}

void Player::Move() {
	if (input_->GetKey(DIK_D)) {
		pos_.x += speed_.x;
	}
	if (input_->GetKey(DIK_A)) {
		pos_.x -= speed_.x;
	}
	// ウィンドウ内に収める
	if (pos_.x < 0) {
		pos_.x = 0; // 左端
	}
	if (pos_.x > 1216) {
		pos_.x = 1216; // 右端
	}
}

void Player::Attack() {
	if (input_->GetPreKey(DIK_SPACE) == 0 && input_->GetKey(DIK_SPACE) != 0) {
		std::unique_ptr<PlayerBullet> bullet;
		bullet = std::make_unique<PlayerBullet>();
		bullet->Init();
		bullet->SetPos({pos_.x + 24, pos_.y +24});
		bullets_.push_back(std::move(bullet));
	}
}

#include "PlayerBullet.h"

void PlayerBullet::Init() { 
	tex_ = Novice::LoadTexture("./resources/images/white1x1.png"); 
	scale_ = {16.0f, 16.0f};
}

void PlayerBullet::Update() {
	if (!isDead_) {
		speed_.y = -5.0f;
		pos_.y += speed_.y;
	}
}

void PlayerBullet::Draw() {
	if (!isDead_) {
		Novice::DrawSprite(int(pos_.x), int(pos_.y), tex_, scale_.x, scale_.y, 0.0f, 0xffffffff);
	}
}

#include "Enemy.h"

void Enemy::Init() { tex_ = Novice::LoadTexture("./resources/images/enemy.png"); }

void Enemy::Update() {
	if (HP == 0) {
		isDead_ = true;
	} else {
		Collision();
		isDead_ = false;
	}
}

void Enemy::Draw() {
	if (!isDead_) {
		Novice::DrawSprite(int(pos_.x), int(pos_.y), tex_, scale_.x, scale_.y, 0.0f, 0xffffffff);
	}
}

void Enemy::Collision() {
	// 敵の中心位置を計算
	Vector2 enemyCenter = {
	    pos_.x + (radius),
	    pos_.y + (radius),
	};

	for (auto bullet : bullets_) {
		if (bullet->IsDead()) {
			continue; // 死んでいる弾は無視
		}

		// 弾の中心位置を取得
		Vector2 bulletCenter = bullet->GetCenterPos();

		// 敵と弾の中心間の距離を計算
		float distance = (bulletCenter - enemyCenter).Length();

		// 当たり判定（距離が半径の合計より小さい場合）
		if (distance < (bullet->GetRadius() + radius)) {
			bullet->SetDead(true); // 衝突した弾を消す
			HP -= 1;
		}
	}
}

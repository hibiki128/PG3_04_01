#pragma once
#include "../myVector2.h"
#include "Novice.h"

class PlayerBullet {
public:
	void Init();
	void Update();
	void Draw();

	void SetDead(bool isDead) { isDead_ = isDead; }
	void SetPos(const Vector2& pos) { pos_ = pos; }
	void SetScale(const Vector2& scale) { scale_ = scale; }

	Vector2 GetPos() const { return pos_; }
	Vector2 GetScale() const { return scale_; }

	Vector2 GetCenterPos() const {
		Vector2 center;
		center.x = pos_.x + scale_.x / 2.0f;
		center.y = pos_.y + scale_.y / 2.0f;
		return center;
	}

	float GetRadius() const {
		return scale_.x / 2.0f;
	}

	bool IsDead() const { return isDead_; }

private:
	Vector2 pos_;  
	Vector2 speed_;
	Vector2 scale_;
	int tex_;      
	bool isDead_;  
};

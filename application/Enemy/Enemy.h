#pragma once
#include "../Player/PlayerBullet.h"
#include "vector"
#include"numbers"
class Enemy {
public:
	void Init();
	void Update();
	void Draw();

	void SetBullets(const std::vector<PlayerBullet*>& bullets) { bullets_ = bullets; }
	void SetPos(const Vector2 pos) { pos_ = pos; }
	bool IsDead() { return isDead_; }

private:
	void Collision();

private:
	std::vector<PlayerBullet*> bullets_;
	Vector2 pos_;
	Vector2 scale_ = {2.0f, 2.0f};
	Vector2 speed_;
	float radius = 30.0f;
	int tex_;
	bool isDead_ = false;
	int HP = 1;
};

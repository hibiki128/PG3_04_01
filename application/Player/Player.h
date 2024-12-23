#pragma once
#include "../Input/InputManager.h"
#include "PlayerBullet.h"
#include "memory"
#include "vector"

class Player {
public:
	void Init();
	void Update();
	void Draw();

	std::vector<PlayerBullet*> GetBullets() const {
		std::vector<PlayerBullet*> bulletPtrs;
		for (const auto& bullet : bullets_) {
			bulletPtrs.push_back(bullet.get());
		}
		return bulletPtrs;
	}


private:
	void Move();
	void Attack();

private:
	InputManager* input_;

	int playerTex_;
	Vector2 pos_;
	Vector2 scale_;
	Vector2 speed_;

	std::vector<std::unique_ptr<PlayerBullet>> bullets_;
};

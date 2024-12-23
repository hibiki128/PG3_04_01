#pragma once
#include"Novice.h"
#include"../myVector2.h"

class Player {
public:
	void Init();
	void Update();
	void Draw();

private:
	int texHandle;
	Vector2 pos;
};

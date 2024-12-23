#include "InputManager.h"
#include <Novice.h>
InputManager* InputManager::instance = nullptr;

void InputManager::Init() {
	// 初期化時に前フレームの状態を全てリセット
	memset(preKeys, 0, sizeof(preKeys));
	memset(keys, 0, sizeof(keys));
}

void InputManager::Update() {
	// 現在のキー状態を前フレームの状態として保存
	memcpy(preKeys, keys, sizeof(preKeys));

	// 現在のキー状態を取得
	Novice::GetHitKeyStateAll(keys);
}

InputManager* InputManager::GetInstance() {
	if (instance == nullptr) {
		instance = new InputManager();
	}
	return instance;
}

void InputManager::Finalize() {
	delete instance;
	instance = nullptr;
}

bool InputManager::GetPreKey(char keyCode) {
	// 指定されたキーの前フレーム状態を返す（押されている場合は true）
	return preKeys[keyCode] != 0;
}

bool InputManager::GetKey(char keyCode) {
	// 指定されたキーの現在の状態を返す（押されている場合は true）
	return keys[keyCode] != 0;
}

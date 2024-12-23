#pragma once
class InputManager {
private:
	static InputManager* instance;

	InputManager() = default;
	~InputManager() = default;
	InputManager(InputManager&) = delete;
	InputManager& operator=(InputManager&) = delete;

public:
	void Init();
	void Update();

	static InputManager* GetInstance();

	void Finalize();

	bool GetPreKey(char keyCode);
	bool GetKey(char keyCode);

private:
	char keys[256] = {0};
	char preKeys[256] = {0};
};

#include <Novice.h>
#include"../Novice/GameManager.h"

const char kWindowTitle[] = "PG3_04_01_ハギワラ_ヒビキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	std::unique_ptr<GameManager> gameManager_;
	gameManager_ = std::make_unique<GameManager>();

	gameManager_->Run();
	
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

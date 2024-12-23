#include "GameManager.h"

GameManager::GameManager() { 
	sceneArr_[TITLE] = std::make_unique<TitleScene>(); 
	sceneArr_[STAGE] = std::make_unique<StageScene>(); 
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();
	inputManager_ = InputManager::GetInstance();
	inputManager_->Init();
	sceneArr_[TITLE]->Init();
}

GameManager::~GameManager() { inputManager_->Finalize(); }

int GameManager::Run() { 
while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();
	    inputManager_->Update();

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
		   sceneArr_[currentSceneNo_]->Init();
		}

		sceneArr_[currentSceneNo_]->Update();

		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		if (inputManager_->GetPreKey(DIK_ESCAPE) == 0 &&
			inputManager_->GetKey(DIK_ESCAPE) != 0) {
			break;
		}
	}
return 0;
}

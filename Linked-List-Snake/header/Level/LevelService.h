#pragma once

namespace Level
{
	class LevelController;
	enum class LevelNumber;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_to_load);
	};
}
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

		void spawnPlayer();
		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_to_load);

		float getCellWidth() const;
		float getCellHeight() const;
	};
}
#pragma once

namespace Level
{
	class LevelController;
	enum class LevelNumber;
	enum class LinkedListType;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;
		LinkedListType current_linked_list_type;

		void spawnLevelElements(LevelNumber level_to_load);
		void spawnFood();
		void spawnPlayer();
		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LinkedListType linked_list_type);

		float getCellWidth() const;
		float getCellHeight() const; 
		LevelNumber getCurrentLevel() const;
		void setCurrentLevel(LevelNumber level_to_load);
	};
}
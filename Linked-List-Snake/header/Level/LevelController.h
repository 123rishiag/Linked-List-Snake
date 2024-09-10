#pragma once
#include "../header/Element/ElementData.h"
#include<vector>

namespace Level
{
	class LevelView;
	class LevelModel;

	class LevelController
	{
	private:
		LevelView* level_view;
		LevelModel* level_model;

		void destroy();
	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		float getCellWidth() const;
		float getCellHeight() const;

		const std::vector<Element::ElementData>& getElementDataList(int level_to_load) const;
	};
}
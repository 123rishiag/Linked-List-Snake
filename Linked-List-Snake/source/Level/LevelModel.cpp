#include "../header/Level/LevelModel.h"

namespace Level
{
	using namespace Element;

	LevelModel::LevelModel() = default;

	LevelModel::~LevelModel() = default;

	void LevelModel::initialize(int width, int height)
	{ 
		cell_width = width / number_of_columns;
		cell_height = height / number_of_rows;

		initializeLevelData();
	}

	void LevelModel::initializeLevelData()
	{
		level_configurations.push_back(LevelData(Level::LevelNumber::ONE, &level_one_element_list));
		level_configurations.push_back(LevelData(Level::LevelNumber::TWO, &level_two_element_list));
	}

	float LevelModel::getCellWidth() const
	{
		return cell_width;
	}

	float LevelModel::getCellHeight() const
	{
		return cell_height;
	}

	const std::vector<ElementData>& LevelModel::getElementDataList(int level_to_load) const
	{
		return *level_configurations[level_to_load].element_data_list;
	}

}
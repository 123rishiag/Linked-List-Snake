#include "../header/Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel() = default;

	LevelModel::~LevelModel() = default;

	void LevelModel::initialize(int width, int height)
	{ 
		cell_width = width / number_of_columns;
		cell_height = height / number_of_rows;
	}

	float LevelModel::getCellWidth() const
	{
		return cell_width;
	}

	float LevelModel::getCellHeight() const
	{
		return cell_height;
	}

}
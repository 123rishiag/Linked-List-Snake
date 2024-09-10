#pragma once
#include "../header/Level/LevelNumber.h"
#include "../header/Element/ElementData.h"
#include<vector>

namespace Level
{
    struct LevelData
    {
        LevelData(LevelNumber index, std::vector<Element::ElementData>* data_list)
        {
            level_index = index;
            element_data_list = data_list;
        }

        LevelNumber level_index;
        std::vector<Element::ElementData>* element_data_list;
    };
}
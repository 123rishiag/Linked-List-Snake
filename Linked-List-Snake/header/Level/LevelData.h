#pragma once
#include "../header/Level/LevelNumber.h"

namespace Level
{
    struct LevelData
    {
        LevelData(LevelNumber index)
        {
            level_index = index;
        }

        LevelNumber level_index;
    };
}
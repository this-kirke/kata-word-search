// System Includes
#include <limits.h>

// Internal Includes
#include "word_search/grid.h"

bool word_search__grid__contains( WordSearch__Grid grid, WordSearch__GridCoordinates coordinates ){
    if( coordinates.row < grid.height && coordinates.column < grid.width ){
        return true;
    }

    return false;
}

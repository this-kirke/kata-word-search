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

bool word_search__grid__entry(
    WordSearch__Grid grid,
    WordSearch__GridCoordinates coordinates,
    char *out__entry_value
){
    (void)( grid );
    (void)( coordinates );
    (void)( out__entry_value );

    return false;
}

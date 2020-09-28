// Internal Includes
#include "word_search/grid_coordinates.h"

bool word_search__grid_coordinates__equals(
    WordSearch__GridCoordinates first,
    WordSearch__GridCoordinates second
){
    if(
        first.row == second.row &&
        first.column == second.column
    ){
        return true;
    }

    return false;
}

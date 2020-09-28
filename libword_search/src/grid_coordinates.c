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

bool word_search__grid_coordinates__translate(
    WordSearch__GridCoordinates coordinates,
    WordSearch__GridVector vector,
    WordSearch__GridCoordinates *out__translated_coordinates
){
    (void )( coordinates );
    (void)( vector );
    (void)( out__translated_coordinates );

    return false;
}

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
    if( word_search__grid__contains( grid, coordinates ) ){
        *out__entry_value = grid.entries.data[ ( coordinates.row * grid.width ) + coordinates.column ];
        return true;
    }

    return false;
}

bool word_search__grid__retrieve_sequence_entry(
    WordSearch__Grid grid,
    WordSearch__GridSequence sequence,
    unsigned long long index,
    char* out_entry
){
    if( index >= sequence.span.magnitude ){
        return false;
    }

    WordSearch__GridCoordinates current_coordinates;

    if(
        word_search__grid_coordinates__translate(
            sequence.start,
            (WordSearch__GridVector) {
                .magnitude = index,
                .direction = sequence.span.direction
            },
            &current_coordinates
        ) == false
    ){
        return false;
    }

    return word_search__grid__entry( grid, current_coordinates, out_entry );
}

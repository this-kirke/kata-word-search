// System Includes
#include <limits.h>

// 3rdParty includes
#include "kirke/hash_map.h"
#include "kirke/list.h"
#include "kirke/log.h"

// Internal Includes
#include "word_search/grid.h"
#include "word_search/grid_hash_map.h"

// A perfect hash function - we'll have 256 buckets, one for each char value.
#define HASH_CHAR( c ) c

HASH_MAP__DEFINE(
    HashMap__char_to_List__WordSearch__GridCoordinates,
    hash_map__char_to_list__word_search__grid_coordinates,
    char,
    List__WordSearch__GridCoordinates*,
    HASH_CHAR,
    HASH_MAP__DIRECT_COMPARE
)

void word_search__grid_hash_map__initialize( WordSearch__GridHashMap *grid_hash_map, Allocator *allocator, WordSearch__Grid grid ){

    hash_map__char_to_list__word_search__grid_coordinates__initialize( grid_hash_map, allocator, 256 );

    for( unsigned long long row_index = 0; row_index < grid.height; row_index++ ){
        for( unsigned long long column_index = 0; column_index < grid.width; column_index++ ){

            WordSearch__GridCoordinates current_coordinates = { .row = row_index, .column = column_index };

            char entry;
            // Unlikely
            if( word_search__grid__entry( grid, current_coordinates, &entry ) == false ){
                log__error( "word_search__grid_hash_map__initialize: Malformed grid." );
                return;
            }

            List__WordSearch__GridCoordinates *entry_coordinates_list;
            if( hash_map__char_to_list__word_search__grid_coordinates__retrieve( grid_hash_map, entry, &entry_coordinates_list ) == false ){
                list__word_search__grid_coordinates__initialize( &entry_coordinates_list, allocator, current_coordinates );

                hash_map__char_to_list__word_search__grid_coordinates__insert( grid_hash_map, entry, entry_coordinates_list );
            }
            else{
                list__word_search__grid_coordinates__append( entry_coordinates_list, allocator, current_coordinates );
            }
        }
    }
}

void word_search__grid_hash_map__clear( WordSearch__GridHashMap *grid_hash_map ){
    hash_map__char_to_list__word_search__grid_coordinates__clear( grid_hash_map );
}

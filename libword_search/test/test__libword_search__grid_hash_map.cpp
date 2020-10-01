// 3rdParty Includes
#include "catch2/catch.hpp"
#include "kirke/string.h"
#include "kirke/system_allocator.h"

// Internal Includes
#include "word_search/grid.h"
#include "word_search/grid_coordinates.h"
#include "word_search/grid_hash_map.h"

class GridHashMap__TestFixture{
    protected:
        GridHashMap__TestFixture(){
            system_allocator__initialize( &system_allocator, NULL );
            word_search__grid_hash_map__initialize( &grid_hash_map, system_allocator.allocator, grid );
        }

        ~GridHashMap__TestFixture(){
            word_search__grid_hash_map__clear( &grid_hash_map );
            system_allocator__deinitialize( &system_allocator );
        }

        const unsigned long long GRID_DIM = 15;

        WordSearch__Grid grid = {
            .width = GRID_DIM,
            .height = GRID_DIM,
            .entries = {
                .data = (char[]) {
                    'U', 'M', 'K', 'H', 'U', 'L', 'K', 'I', 'N', 'V', 'J', 'O', 'C', 'W', 'E',
                    'L', 'L', 'S', 'H', 'K', 'Z', 'Z', 'W', 'Z', 'C', 'G', 'J', 'U', 'Y', 'G',
                    'H', 'S', 'U', 'P', 'J', 'P', 'R', 'J', 'D', 'H', 'S', 'B', 'X', 'T', 'G',
                    'B', 'R', 'J', 'S', 'O', 'E', 'Q', 'E', 'T', 'I', 'K', 'K', 'G', 'L', 'E',
                    'A', 'Y', 'O', 'A', 'G', 'C', 'I', 'R', 'D', 'Q', 'H', 'R', 'T', 'C', 'D',
                    'S', 'C', 'O', 'T', 'T', 'Y', 'K', 'Z', 'R', 'E', 'P', 'P', 'X', 'P', 'F',
                    'B', 'L', 'Q', 'S', 'L', 'N', 'E', 'E', 'E', 'V', 'U', 'L', 'F', 'M', 'Z',
                    'O', 'K', 'R', 'I', 'K', 'A', 'M', 'M', 'R', 'M', 'F', 'B', 'A', 'P', 'P',
                    'N', 'U', 'I', 'I', 'Y', 'H', 'Q', 'M', 'E', 'M', 'Q', 'R', 'Y', 'F', 'S',
                    'E', 'Y', 'Z', 'Y', 'G', 'K', 'Q', 'J', 'P', 'C', 'Q', 'W', 'Y', 'A', 'K',
                    'S', 'J', 'F', 'Z', 'M', 'Q', 'I', 'B', 'D', 'B', 'R', 'M', 'K', 'W', 'D',
                    'T', 'G', 'L', 'B', 'H', 'C', 'B', 'E', 'C', 'E', 'T', 'O', 'Y', 'I', 'F',
                    'O', 'J', 'Y', 'E', 'U', 'L', 'N', 'C', 'K', 'L', 'Y', 'B', 'Z', 'R', 'H',
                    'W', 'Z', 'M', 'I', 'S', 'U', 'K', 'I', 'R', 'B', 'I', 'D', 'O', 'X', 'S',
                    'K', 'Y', 'L', 'B', 'Q', 'Q', 'R', 'M', 'D', 'F', 'C', 'W', 'E', 'A', 'B'
                },
                .length = 225,
                .capacity = 225,
                .element_size = 1
            }
        };

        SystemAllocator system_allocator;

        WordSearch__GridHashMap grid_hash_map;
};

TEST_CASE_METHOD( GridHashMap__TestFixture, "grid_hash_map__initialize_and_clear", "[grid_hash_map]" ){
    REQUIRE( grid_hash_map.allocator == system_allocator.allocator );
}

TEST_CASE_METHOD( GridHashMap__TestFixture, "grid_hash_map__retrieve_candidate_coordinates", "[grid_hash_map]" ){
    const String word = string__literal( "SCOTTY" );

    const unsigned long long expected_character_index = 3;
    const unsigned long long expected_coordinates_length = 7;
    WordSearch__GridCoordinates expected_coordinates[ expected_coordinates_length ] = {
        { .row = 2, .column = 13 },
        { .row = 3, .column = 8 },
        { .row = 4, .column = 12 },
        { .row = 5, .column = 3 },
        { .row = 5, .column = 4 },
        { .row = 11, .column = 0 },
        { .row = 11, .column = 10 },
    };

    unsigned long long character_index;
    List__WordSearch__GridCoordinates *candidate_coordinates_list;
    REQUIRE(
        word_search__grid_hash_map__retrieve_candidate_coordinates(
            grid_hash_map,
            word,
            &character_index,
            &candidate_coordinates_list
        )
    );

    REQUIRE( character_index == expected_character_index );
    REQUIRE( list__word_search__grid_coordinates__length( candidate_coordinates_list ) == expected_coordinates_length );

    unsigned long candidate_index = 0;
    while( candidate_coordinates_list ){
        REQUIRE( word_search__grid_coordinates__equals( candidate_coordinates_list->value, expected_coordinates[ candidate_index++ ] ) );
        candidate_coordinates_list = candidate_coordinates_list->next;
    }
}

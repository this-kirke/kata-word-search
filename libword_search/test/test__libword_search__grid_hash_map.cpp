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

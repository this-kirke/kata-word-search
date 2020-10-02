// System Includes
#include <string.h>

// 3rdParty Includes
#include "catch2/catch.hpp"

#include "kirke/system_allocator.h"

// Internal Includes
#include "word_search/word_search.h"
#include "word_search/grid_hash_map.h"
#include "word_search/solution.h"

class WordSearch__TestFixture {

    protected:

        WordSearch__TestFixture(){
            system_allocator__initialize( &system_allocator, NULL );
            word_search__grid_hash_map__initialize( &grid_hash_map, system_allocator.allocator, grid );
        }

        ~WordSearch__TestFixture(){
            word_search__grid_hash_map__clear( &grid_hash_map );
            system_allocator__deinitialize( &system_allocator );
        }

        SystemAllocator system_allocator;

        const unsigned long long GRID_DIM = 15;

        String ENTRIES = {
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
        };

        WordSearch__Grid grid = {
            .width = GRID_DIM,
            .height = GRID_DIM,
            .entries = ENTRIES
        };

        Array__String words = {
            .data = (String*) (const String[ 10 ]) {
                string__literal( "SCOTTY" ),
                string__literal( "SPOCK" ),
                string__literal( "BONES" ),
                string__literal( "UHURA" ),
                string__literal( "KIRK" ),
                string__literal( "SULU" ),
                string__literal( "KHAN" ),
                string__literal( "RIKER" ),
                string__literal( "WORF" ),
                string__literal( "ABCDEFG" )
            },
            .length = 10,
            .capacity = 10
        };

        WordSearch__GridHashMap grid_hash_map;
};

TEST_CASE_METHOD( WordSearch__TestFixture, "word_search__find_word_in_direction", "[word_search]" ){
    String scotty = string__literal( "SCOTTY" );

    WordSearch__Solution expected_solution;

    expected_solution = {
        .word = scotty,
        .disposition = WordSearch__Solution__Disposition__Found,
        .sequence = {
            .start = {
                .row = 5,
                .column = 0
            },
            .span = {
                .magnitude = 6,
                .direction = WordSearch__Direction__East
            }
        }
    };

    WordSearch__Solution solution;

    solution = word_search__find_word_in_direction(
        scotty,
        grid,
        grid_hash_map,
        WordSearch__Direction__East
    );

    REQUIRE(
        word_search__solution__equals(
            solution,
            (WordSearch__Solution) {
                .word = scotty,
                .disposition = WordSearch__Solution__Disposition__Found,
                .sequence = {
                    .start = {
                        .row = 5,
                        .column = 0
                    },
                    .span = {
                        .magnitude = 6,
                        .direction = WordSearch__Direction__East
                    }
                }
            }
        )
    );

    String does_not_exist = string__literal( "ABCDEFG" );

    solution = word_search__find_word_in_direction(
        does_not_exist,
        grid,
        grid_hash_map,
        WordSearch__Direction__East
    );

    REQUIRE(
        word_search__solution__equals(
            solution,
            (WordSearch__Solution) {
                .word = does_not_exist,
                .disposition = WordSearch__Solution__Disposition__NotFound
            }
        )
    );
}

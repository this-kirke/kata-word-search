// System Includes
#include <string.h>

// 3rdParty Includes
#include "catch2/catch.hpp"

#include "kirke/string.h"
#include "kirke/system_allocator.h"

// Internal Includes
#include "word_search/grid.h"

class WordSearch__Grid__TestFixture {
    protected:

        WordSearch__Grid__TestFixture(){
            grid = (WordSearch__Grid){
                .width = GRID_DIM,
                .height = GRID_DIM,
                .entries = ENTRIES
            };
        }

        ~WordSearch__Grid__TestFixture(){}

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

        WordSearch__Grid grid;
};

TEST_CASE_METHOD( WordSearch__Grid__TestFixture, "word_search__grid__contains", "[word_search__grid]" ){
    WordSearch__GridCoordinates current_coordinates;

    current_coordinates = { .row = 0, .column = 0 };
    REQUIRE( word_search__grid__contains( grid, current_coordinates ) );

    current_coordinates = { .row = 0, .column = 1 };
    REQUIRE( word_search__grid__contains( grid, current_coordinates ) );

    current_coordinates = { .row = 1, .column = 0 };
    REQUIRE( word_search__grid__contains( grid, current_coordinates ) );

    current_coordinates = { .row = 1, .column = 1 };
    REQUIRE( word_search__grid__contains( grid, current_coordinates ) );

    current_coordinates = { .row = 8, .column =  17 };
    REQUIRE_FALSE( word_search__grid__contains( grid, current_coordinates ) );

    current_coordinates = { .row = 15, .column = 0 };
    REQUIRE_FALSE( word_search__grid__contains( grid, current_coordinates ) );
}

TEST_CASE_METHOD( WordSearch__Grid__TestFixture, "word_search__grid__entry", "[word_search__grid]" ){
    WordSearch__GridCoordinates current_coordinates;
    char entry_value;

    current_coordinates = { .row = 0, .column = 0 };
    REQUIRE( word_search__grid__entry( grid, current_coordinates, &entry_value ) );
    REQUIRE( entry_value == 'U' );

    current_coordinates = { .row = 0, .column = 1 };
    REQUIRE( word_search__grid__entry( grid, current_coordinates, &entry_value ) );
    REQUIRE( entry_value == 'M' );

    current_coordinates = { .row = 1, .column = 0 };
    REQUIRE( word_search__grid__entry( grid, current_coordinates, &entry_value ) );
    REQUIRE( entry_value == 'L' );

    current_coordinates = { .row = 1, .column = 1 };
    REQUIRE( word_search__grid__entry( grid, current_coordinates, &entry_value ) );
    REQUIRE( entry_value == 'L' );

    current_coordinates = { .row = 14, .column = 14 };
    REQUIRE( word_search__grid__entry( grid, current_coordinates, &entry_value ) );
    REQUIRE( entry_value == 'B' );

    current_coordinates = { .row = 15, .column = 15 };
    REQUIRE_FALSE( word_search__grid__entry( grid, current_coordinates, &entry_value) );
}

TEST_CASE_METHOD( WordSearch__Grid__TestFixture, "word_search__grid__lookup_sequence_entry", "[word_search__grid]" ){
    WordSearch__GridSequence sequence = {
        .start = {
            .row = 0,
            .column = 0
        },
        .span = {
            .magnitude = 15,
            .direction = WordSearch__Direction__SouthEast
        }
    };

    char entry;
    for( unsigned long entry_index = 0; entry_index < GRID_DIM; entry_index++ ){
        REQUIRE( word_search__grid__retrieve_sequence_entry( grid, sequence, entry_index, &entry ) );
        REQUIRE( entry == ENTRIES.data[ entry_index * GRID_DIM + entry_index ] );
    }

    // Test whether index >= sequence.span.magnitude returns 0.
    REQUIRE_FALSE( word_search__grid__retrieve_sequence_entry( grid, sequence, GRID_DIM + 1, &entry ) );

    // Test whether off-grid entries return 0.
    sequence.start = (WordSearch__GridCoordinates) { .row = 0, .column = 15 };
    REQUIRE_FALSE( word_search__grid__retrieve_sequence_entry( grid, sequence, 0, &entry ) );

    // Just for fun, make sure that even if part of the sequence is off the grid, if the entry we want is on the grid,
    // we still get the desired value.
    sequence.span.magnitude = 16;
    sequence.span.direction = WordSearch__Direction__West;
    REQUIRE( word_search__grid__retrieve_sequence_entry( grid, sequence, 15, &entry ) );
    REQUIRE( entry == ENTRIES.data[ 0 ] );
}

TEST_CASE_METHOD( WordSearch__Grid__TestFixture, "word_search__grid__sequence_matches_word", "[word_search__grid]" ){
    String WORDS[ 9 ] = {
        string__literal( "SCOTTY" ),
        string__literal( "SPOCK" ),
        string__literal( "BONES" ),
        string__literal( "UHURA" ),
        string__literal( "KIRK" ),
        string__literal( "SULU" ),
        string__literal( "KHAN" ),
        string__literal( "RIKER" ),
        string__literal( "WORF" )
    };

    WordSearch__GridSequence sequences[] = {
        // SCOTTY
        {
            .start = {
                .row = 5,
                .column = 0
            },
            .span = {
                .magnitude = 6,
                .direction = WordSearch__Direction__East
            }
        },
        // SPOCK
        {
            .start = {
                .row = 1,
                .column = 2
            },
            .span = {
                .magnitude = 5,
                .direction = WordSearch__Direction__SouthEast
            }
        },
        // BONES
        {
            .start = {
                .row = 6,
                .column = 0
            },
            .span = {
                .magnitude = 5,
                .direction = WordSearch__Direction__South
            }
        },
        // UHURA
        {
            .start = {
                .row = 0,
                .column = 4
            },
            .span = {
                .magnitude = 5,
                .direction = WordSearch__Direction__SouthWest
            }
        },
        // KIRK
        {
            .start = {
                .row = 7,
                .column = 4
            },
            .span = {
                .magnitude = 4,
                .direction = WordSearch__Direction__West
            }
        },
        // SULU
        {
            .start = {
                .row = 3,
                .column = 3
            },
            .span = {
                .magnitude = 4,
                .direction = WordSearch__Direction__NorthWest
            }
        },
        // KHAN
        {
            .start = {
                .row = 9,
                .column = 5
            },
            .span = {
                .magnitude = 4,
                .direction = WordSearch__Direction__North
            }
        },
        // RIKER
        {
            .start = {
                .row = 14,
                .column = 6
            },
            .span = {
                .magnitude = 5,
                .direction = WordSearch__Direction__NorthEast
            }
        },
        // WORF
        {
            .start = {
                .row = 14,
                .column = 11
            },
            .span = {
                .magnitude = 4,
                .direction = WordSearch__Direction__NorthEast
            }
        }
    };

    for( unsigned long word_index = 0; word_index < 9; word_index++ ){
        REQUIRE( word_search__grid__sequence_matches_word( grid, sequences[ word_index ], WORDS[ word_index ] ) );
    }
}

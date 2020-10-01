// 3rdParty Includes
#include "catch2/catch.hpp"

// Internal Includes
#include "word_search/grid_sequence.h"

TEST_CASE( "word_search__grid_sequence__equals", "[word_search__grid_sequence]" ){
    WordSearch__GridSequence first = {
        .start = {
            .row = 11,
            .column = 4
        },
        .span = {
            .magnitude = 42,
            .direction = WordSearch__Direction__East,
        }
    };

    WordSearch__GridSequence second = {
        .start = {
            .row = 11,
            .column = 11
        },
        .span = {
            .magnitude = 42,
            .direction = WordSearch__Direction__East,
        }
    };

    REQUIRE( word_search__grid_sequence__equals( first, first ) == true );
    REQUIRE( word_search__grid_sequence__equals( first, second ) == false );
}

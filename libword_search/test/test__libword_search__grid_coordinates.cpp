// 3rdParty Includes
#include "catch2/catch.hpp"

// Internal Includes
#include "word_search/grid_coordinates.h"

TEST_CASE( "word_search__grid_coordinates__equals", "[word_search__grid_coordinates]" ){
    WordSearch__GridCoordinates first = {
        .row = 11,
        .column = 4
    };

    WordSearch__GridCoordinates second = {
        .row = 11,
        .column = 2
    };

    REQUIRE( word_search__grid_coordinates__equals( first, first ) == true );
    REQUIRE( word_search__grid_coordinates__equals( first, second ) == false );
}

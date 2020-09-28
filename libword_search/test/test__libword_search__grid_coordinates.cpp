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

TEST_CASE( "word_search__grid_coordinates__translate", "[word_search__grid_coordinates]" ){
    WordSearch__GridCoordinates coordinates;
    WordSearch__GridCoordinates expected_coordinates;
    WordSearch__GridCoordinates translated_coordinates;
    WordSearch__GridVector translation;

    coordinates = { .row = 5, .column = 5 };
    translation = { .magnitude = 5, .direction = WordSearch__Direction__East };

    expected_coordinates = { .row = 5, .column = 10 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.direction = WordSearch__Direction__SouthEast;
    expected_coordinates = { .row = 10, .column = 10 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.direction = WordSearch__Direction__South;
    expected_coordinates = { .row = 10, .column = 5 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.direction = WordSearch__Direction__SouthWest;
    expected_coordinates = { .row = 10, .column = 0 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.direction = WordSearch__Direction__West;
    expected_coordinates = { .row = 5, .column = 0 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.direction = WordSearch__Direction__NorthWest;
    expected_coordinates = { .row = 0, .column = 0 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.direction = WordSearch__Direction__North;
    expected_coordinates = { .row = 0, .column = 5 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.direction = WordSearch__Direction__NorthEast;
    expected_coordinates = { .row = 0, .column = 10 };
    REQUIRE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
    REQUIRE( word_search__grid_coordinates__equals( translated_coordinates, expected_coordinates ) );

    translation.magnitude = 6;
    translation.direction = WordSearch__Direction__West;
    REQUIRE_FALSE( word_search__grid_coordinates__translate( coordinates, translation, &translated_coordinates ) );
}

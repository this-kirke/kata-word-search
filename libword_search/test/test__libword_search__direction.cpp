// 3rdParty Includes
#include "catch2/catch.hpp"

// Internal Includes
#include "word_search/direction.h"

TEST_CASE( "word_search__direction__opposite", "[direction]" ){
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__East ) == WordSearch__Direction__West );
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__SouthEast ) == WordSearch__Direction__NorthWest );
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__South ) == WordSearch__Direction__North );
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__SouthWest ) == WordSearch__Direction__NorthEast );
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__West ) == WordSearch__Direction__East );
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__NorthWest ) == WordSearch__Direction__SouthEast );
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__North ) == WordSearch__Direction__South );
    REQUIRE( word_search__direction__opposite( WordSearch__Direction__NorthEast ) == WordSearch__Direction__SouthWest );
}

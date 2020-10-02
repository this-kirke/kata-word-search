// System Includes
#include <string.h>

// 3rdParty Includes
#include "catch2/catch.hpp"

#include "kirke/string.h"
#include "kirke/system_allocator.h"

// Internal Includes
#include "word_search/word_search.h"
#include "word_search/solution.h"

class WordSearch__UserStories__TestFixture {

    protected:

        WordSearch__UserStories__TestFixture(){
            system_allocator__initialize( &system_allocator, NULL );
            word_search__grid_hash_map__initialize( &grid_hash_map, system_allocator.allocator, grid );
        }

        ~WordSearch__UserStories__TestFixture(){
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

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search Eastward "
    "so that I can find forward-facing horizontal words.",
    "[user_stories]"
){
    GIVEN( "The word \"SCOTTY\"" ){

        Array__String words = {
            .data = (String*)(const String[ 1 ]){
                string__literal( "SCOTTY" )
            },
            .length = 1,
            .capacity = 1,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid Eastward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 1 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__East,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the word \"SCOTTY\" on the grid." ){
                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 1 ]){
                        {
                            .word = string__literal( "SCOTTY" ),
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
                    },
                    .length = 1,
                    .capacity = 1,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }

            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search South-Eastward "
    "so that I can find forward-facing, diagonally-descending words.",
    "[user_stories]"
){
    GIVEN( "The word \"SPOCK\"" ){

        Array__String words = {
            .data = (String*)(const String[ 1 ]){
                string__literal( "SPOCK" )
            },
            .length = 1,
            .capacity = 1,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid South-Eastward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 1 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__SouthEast,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the word \"SPOCK\" on the grid." ){

                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 1 ]){
                        {
                            .word = string__literal( "SPOCK" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 1,
                                    .column = 2
                                },
                                .span = {
                                    .magnitude = 5,
                                    .direction = WordSearch__Direction__SouthEast
                                }
                            }
                        }
                    },
                    .length = 1,
                    .capacity = 1,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }
            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search Southward "
    "so that I can find vertically-descending words.",
    "[user_stories]"
){
    GIVEN( "The word \"BONES\"" ){

        Array__String words = {
            .data = (String*)(const String[ 1 ]){
                string__literal( "BONES" )
            },
            .length = 1,
            .capacity = 1,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid Southward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 1 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__South,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the word \"BONES\" on the grid." ){

                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 1 ]){
                        {
                            .word = string__literal( "BONES" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 6,
                                    .column = 0
                                },
                                .span = {
                                    .magnitude = 5,
                                    .direction = WordSearch__Direction__South
                                }
                            }
                        }
                    },
                    .length = 1,
                    .capacity = 1,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }

            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search South-Westward "
    "so that I can find backward-facing, vertically-ascending words.",
    "[user_stories]"
){
    GIVEN( "The word \"UHURA\"" ){

        Array__String words = {
            .data = (String*)(const String[ 1 ]){
                string__literal( "UHURA" )
            },
            .length = 1,
            .capacity = 1,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid South-Westward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 1 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__SouthWest,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the word \"UHURA\" on the grid." ){
                REQUIRE( success );

                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 1 ]){
                        {
                            .word = string__literal( "UHURA" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 0,
                                    .column = 4
                                },
                                .span = {
                                    .magnitude = 5,
                                    .direction = WordSearch__Direction__SouthWest
                                }
                            }
                        }
                    },
                    .length = 1,
                    .capacity = 1,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }

            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search Westward "
    "so that I can find backward-facing horizontal words.",
    "[user_stories]"
){
    GIVEN( "The word \"KIRK\"" ){

        Array__String words = {
            .data = (String*)(const String[ 1 ] ){
                string__literal( "KIRK" )
            },
            .length = 1,
            .capacity = 1,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid Westward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 1 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__West,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the word \"KIRK\" on the grid." ){
                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 1 ]){
                        {
                            .word = string__literal( "KIRK" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 7,
                                    .column = 4
                                },
                                .span = {
                                    .magnitude = 4,
                                    .direction = WordSearch__Direction__West
                                }
                            }
                        }
                    },
                    .length = 1,
                    .capacity = 1,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }

            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search North-Westward "
    "so that I can find backward-facing, diagonally descending words.",
    "[user_stories]"
){
    GIVEN( "The word \"SULU\"" ){

        Array__String words = {
            .data = (String*)(const String[ 1 ]){
                string__literal( "SULU" )
            },
            .length = 1,
            .capacity = 1,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid North-Westward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 1 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__NorthWest,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the word \"SULU\" on the grid." ){

                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 1 ]){
                        {
                            .word = string__literal( "SULU" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 3,
                                    .column = 3
                                },
                                .span = {
                                    .magnitude = 4,
                                    .direction = WordSearch__Direction__NorthWest
                                }
                            }
                        }
                    },
                    .length = 1,
                    .capacity = 1,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }
            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search Northward "
    "so that I can find vertically-ascending words.",
    "[user_stories]"
){
    GIVEN( "The word \"KHAN\"" ){

        Array__String words = {
            .data = (String*)(const String[ 1 ]){
                string__literal( "KHAN" )
            },
            .length = 1,
            .capacity = 1,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid Northward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 1 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__North,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the word \"KHAN\" on the grid." ){
                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 1 ]){
                        {
                            .word = string__literal( "KHAN" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 9,
                                    .column = 5
                                },
                                .span = {
                                    .magnitude = 4,
                                    .direction = WordSearch__Direction__North
                                }
                            }
                       }
                    },
                    .length = 1,
                    .capacity = 1,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }

            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

SCENARIO_METHOD(
    WordSearch__UserStories__TestFixture,
    "As the Puzzle Solver, "
    "I want to search North-Eastward "
    "so that I can find forward-facing, diagonally-ascending words.",
    "[user_stories]"
){
    GIVEN( "The words \"RIKER\" and \"WORF\"" ){

        Array__String words = {
            .data = (String*)(const String[ 2 ]){
                string__literal( "RIKER" ),
                string__literal( "WORF" )
            },
            .length = 2,
            .capacity = 2,
            .element_size = sizeof( String )
        };

        WHEN( "I search the grid North-Eastward" ){

            Array__WordSearch__Solution solutions;
            array__word_search__solution__initialize( &solutions, system_allocator.allocator, 2 );

            bool success = word_search__search_in_direction(
                words,
                grid,
                grid_hash_map,
                WordSearch__Direction__NorthEast,
                &solutions,
                NULL
            );

            THEN( "The search successfully returns the location of the words \"RIKER\" and \"WORF\" on the grid." ){
                Array__WordSearch__Solution expected_solutions = {
                    .data = (WordSearch__Solution*)(const WordSearch__Solution[ 2 ]){
                        {
                            .word = string__literal( "RIKER" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 14,
                                    .column = 6
                                },
                                .span = {
                                    .magnitude = 5,
                                    .direction = WordSearch__Direction__NorthEast
                                }
                            }
                        },
                        {
                            .word = string__literal( "WORF" ),
                            .disposition = WordSearch__Solution__Disposition__Found,
                            .sequence = {
                                .start = {
                                    .row = 14,
                                    .column = 11
                                },
                                .span = {
                                    .magnitude = 4,
                                    .direction = WordSearch__Direction__NorthEast
                                }
                            }
                        }
                    },
                    .length = 2,
                    .capacity = 2,
                    .element_size = sizeof( WordSearch__Solution )
                };

                REQUIRE( success );
                REQUIRE( array__word_search__solution__equals( solutions, expected_solutions ) );
            }
            array__word_search__solution__clear( &solutions, system_allocator.allocator );
        }
    }
}

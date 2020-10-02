#include "word_search/word_search.h"

WordSearch__Solution word_search__find_word_in_direction(
    String word,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map,
    WordSearch__Direction direction
){
    unsigned long long candidate_character_index;
    List__WordSearch__GridCoordinates *candidates_list;

    if(
        word_search__grid_hash_map__retrieve_candidate_coordinates(
            grid_hash_map,
            word,
            &candidate_character_index,
            &candidates_list
        )
    ){
        while( candidates_list != NULL ){
            WordSearch__GridCoordinates start_coordinates;

            if(
                // Unlikely
                word_search__grid_coordinates__translate(
                    candidates_list->value,
                    (WordSearch__GridVector) {
                        .magnitude = candidate_character_index,
                        .direction = word_search__direction__opposite( direction ),
                    },
                    &start_coordinates
                ) == false
            ){
                candidates_list = candidates_list->next;
                continue;
            }

            WordSearch__GridSequence sequence = {
                .start = start_coordinates,
                .span = {
                    .magnitude = word.length,
                    .direction = direction
                }
            };

            if( word_search__grid__sequence_matches_word( grid, sequence, word ) ){
                return (WordSearch__Solution) {
                    .word = word,
                    .disposition = WordSearch__Solution__Disposition__Found,
                    .sequence = sequence
                };
            }
            candidates_list = candidates_list->next;
        }
    }

    return (WordSearch__Solution){
        .word = word,
        .disposition = WordSearch__Solution__Disposition__NotFound
    };
}

WordSearch__Solution word_search__find_word(
    String word,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map
){
    (void)( word );
    (void)( grid );
    (void)( grid_hash_map );

    return (WordSearch__Solution) { 0 };
}

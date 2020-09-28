// Internal Includes
#include "word_search/grid_sequence.h"

bool word_search__grid_sequence__equals(
    WordSearch__GridSequence first,
    WordSearch__GridSequence second
){
    if(
        word_search__grid_coordinates__equals( first.start, second.start ) &&
        word_search__grid_vector__equals( first.span, second.span )
    ){
        return true;
    }

    return false;
}

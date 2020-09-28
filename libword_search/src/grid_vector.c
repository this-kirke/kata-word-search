// Internal Includes
#include "word_search/grid_vector.h"

bool word_search__grid_vector__equals(
    WordSearch__GridVector first,
    WordSearch__GridVector second
){
    if(
        first.direction == second.direction &&
        first.magnitude == second.magnitude
    ){
        return true;
    }

    return false;
}

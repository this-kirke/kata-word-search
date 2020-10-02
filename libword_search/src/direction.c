// 3rdParty Includes
#include "kirke/log.h"

// Internal Includes
#include "word_search/direction.h"

WordSearch__Direction word_search__direction__opposite( WordSearch__Direction direction ){
    (void)(direction);
    return WordSearch__Direction__East;
}

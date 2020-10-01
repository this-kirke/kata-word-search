#ifndef WORD_SEARCH__GRID_HASH_MAP__H
#define WORD_SEARCH__GRID_HASH_MAP__H

// 3rdParty Includes
#include "kirke/allocator.h"
#include "kirke/hash_map.h"
#include "kirke/macros.h"
#include "kirke/string.h"

// Internal Includes
#include "word_search/grid.h"
#include "word_search/grid_sequence.h"

BEGIN_DECLARATIONS

HASH_MAP__DECLARE(
    HashMap__char_to_List__WordSearch__GridCoordinates,
    hash_map__char_to_list__word_search__grid_coordinates,
    char,
    List__WordSearch__GridCoordinates*
)

/**
 *  WordSearch__GridHashMap is a mapping from char -> List__WordSearch__GridCoordinates, where the list
 *  represents all of the locations of a given character within a WordSearch__Grid.
 */
typedef struct HashMap__char_to_List__WordSearch__GridCoordinates WordSearch__GridHashMap;

/**
 *  \brief This method initializes a WordSearch__GridHashMap structure with the provided Allocator
 *  and WordSearch__Grid.
 *  \param allocator A pointer to the Allocator which will be used to manage memory controlled by the hash map.
 *  \param grid A pointer to the WordSearch__Grid whose entries will be represented by the hash map.
 */
void word_search__grid_hash_map__initialize( WordSearch__GridHashMap *grid_hash_map, Allocator *allocator, WordSearch__Grid grid );

/**
 *  \brief This method clears a WordSearch__GridHashMap, freeing all data managed by the structure.
 *  \param grid_hash_map A pointer to the WordSearch__GridHashMap which is to be cleared.
 */
void word_search__grid_hash_map__clear( WordSearch__GridHashMap *grid_hash_map );

END_DECLARATIONS

#endif // WORD_SEARCH__GRID_HASH_MAP__H

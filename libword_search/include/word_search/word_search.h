#ifndef WORD_SEARCH__H
#define WORD_SEARCH__H

// 3rdParty Includes
#include "kirke/error.h"
#include "kirke/macros.h"
#include "kirke/string.h"

// Internal Includes
#include "word_search/grid.h"
#include "word_search/grid_coordinates.h"
#include "word_search/grid_hash_map.h"
#include "word_search/solution.h"

BEGIN_DECLARATIONS

/**
 *  \brief This method searches the grid for the given word, in the specified direction.
 *  \param word The word to search for.
 *  \param grid The WordSearch__Grid in which to search.
<<<<<<< HEAD
 *  \param grid_hash_map The WordSearch__GridHashMap from which candidate entries will be retrieved.
 *  \returns The solution to the search.
 */
WordSearch__Solution word_search__find_word_in_direction(
    String word,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map,
    WordSearch__Direction direction
);

/**
<<<<<<< HEAD
 *  \brief This method searches the grid for the given word.
 *  \param grid A pointer to the WordSearch__Grid in which to search.
 *  \param word A pointer to a String containing the word to search for.
=======
 *  \param grid_hash_map
>>>>>>> 2f96c1e... Added method word_search__find_word. This method searches the grid for the provided word, in all directions.
 *  \returns The solution to the search.
 */
WordSearch__Solution word_search__find_word_in_direction(
    String word,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map,
    WordSearch__Direction direction
);

/**
 *  \brief This method searches the grid for the given word.
 *  \param grid A pointer to the WordSearch__Grid in which to search.
 *  \param word A pointer to a String containing the word to search for.
=======
 *  \brief This method searches the grid for the given word, in all directions.
 *  \param word The word to search for.
 *  \param grid The WordSearch__Grid in which to search.
 *  \param grid_hash_map The WordSearch__GridHashMap from which candidate entries will be retrieved.
>>>>>>> dca0349... Documentation for word_search__find_word.
 *  \returns The solution to the search.
 */
WordSearch__Solution word_search__find_word(
    String word,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map
);

END_DECLARATIONS

#endif // WORD_SEARCH__H

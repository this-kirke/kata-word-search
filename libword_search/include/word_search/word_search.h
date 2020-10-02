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

typedef enum WordSearch__ErrorType {
    WordSearch__ErrorType__None,
    WordSearch__ErrorType__NullReference,
    WordSearch__ErrorType__InsufficientCapacity
} WordSearch__ErrorType;

/**
 *  \brief This method searches the grid for the given word, in the specified direction.
 *  \param word The word to search for.
 *  \param grid The WordSearch__Grid in which to search.
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
 *  \brief This method searches the grid for the given word.
 *  \param word A pointer to a String containing the word to search for.
 *  \param grid A pointer to the WordSearch__Grid in which to search.
 *  \param grid_hash_map
 *  \returns The solution to the search.
 */
WordSearch__Solution word_search__find_word_in_direction(
    String word,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map,
    WordSearch__Direction direction
);

/**
 *  \brief This method searches the grid for the given word, in all directions.
 *  \param word The word to search for.
 *  \param grid The WordSearch__Grid in which to search.
 *  \param grid_hash_map The WordSearch__GridHashMap from which candidate entries will be retrieved.
 *  \returns The solution to the search.
 */
WordSearch__Solution word_search__find_word(
    String word,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map
);

/**
 *  \brief This method searches the grid for all of the given words, in the provided direction.
 *  \param words The list of the words to be searched for in the grid.
 *  \param grid The grid in which to search for the provided words.
 *  \param grid_hash_map The WordSearch__GridHashMap from which candidate entries will be retrieved.
 *  \param out__solutions An out parameter. This is a pointer to a pre-allocated Array__WordSearch__Solution.
 *  The allocated capacity must be greater than or equal to the length of \p words.
 *  \param out__error An out parameter. If an error occurs while executing the search, then this function will return
 *  false, and this parameter will store the details of the encountered error.
 *  \returns Returns true if the search was completed successfully. The search can fail if \p out_solutions is NULL,
 *  or if it lacks the required capacity to hold solutions for every word.
 *  \returns Returns false if the search was not completed successully.
 */
bool word_search__search_in_direction(
    Array__String words,
    WordSearch__Grid grid,
    WordSearch__GridHashMap grid_hash_map,
    WordSearch__Direction direction,
    Array__WordSearch__Solution* out_solutions,
    Error *out__error
);

END_DECLARATIONS

#endif // WORD_SEARCH__H

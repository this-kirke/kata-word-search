/**
 *  \file word_search/grid_sequence.h
 */

#ifndef WORD_SEARCH__GRID_SEQUENCE__H
#define WORD_SEARCH__GRID_SEQUENCE__H

// System Includes
#include <stdbool.h>

// 3rdParty Includes
#include "kirke/macros.h"
#include "kirke/string.h"

// Internal Includes
#include "word_search/grid_coordinates.h"
#include "word_search/grid_vector.h"

BEGIN_DECLARATIONS

/**
 *  \defgroup word_search__grid_sequence WordSearch__GridSequence
 *  @{
 */

/**
 *  A structure describing a sequence of entries.
 */
typedef struct WordSearch__GridSequence{
    /**
     *  The WordSearch__GridCoordinates where this sequence of entries begins
     */
    WordSearch__GridCoordinates start;
    /**
     *  A WordSearch__GridVector describing the span of the sequence. That is, the entries.
     *  occupied by this sequence relative to the start position.
     */
    WordSearch__GridVector span;
} WordSearch__GridSequence;

/**
 *  \brief Compares two WordSearch__GridSequence objects for equality
 *  \param first A pointer to the first WordSearch__GridSequence to be compared
 *  \param second A pointer to the second WordSearch__GridSequence to be compared
 *  \returns Returns true if the two WordSearch__GridSequence objects are equal.
 *  \returns Returns false if the two WordSearch__GridSequence objects are not equal.
 */
bool word_search__grid_sequence__equals(
    WordSearch__GridSequence first,
    WordSearch__GridSequence second
);

/**
 *  @} // group word_search__grid_sequence
 */

END_DECLARATIONS

#endif // WORD_SEARCH__GRID_SEQUENCE__H

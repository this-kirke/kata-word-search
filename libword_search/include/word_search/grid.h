/**
 *  \file word_search/word_search__grid.h
 */

#ifndef WORD_SEARCH__GRID__H
#define WORD_SEARCH__GRID__H

// System Includes
#include <stdbool.h>

// 3rdParty Includes
#include "kirke/macros.h"
#include "kirke/string.h"

// Internal Includes
#include "word_search/grid_coordinates.h"
#include "word_search/grid_sequence.h"

BEGIN_DECLARATIONS

/**
 *  \defgroup word_search__grid WordSearch__Grid
 *  @{
 */

// Forward Declarations
typedef struct Allocator Allocator;

/**
 *  A structure defining a word search puzzle grid.
 *  \brief This structure contains metadata describing the grid, such as its width and height,
 *  as well as a pointer to a Slice containing all of the grid's entries.
 *
 *  Grid entries are arranged in flattened row-major format. That is, rows are placed end to
 *  end in memory, packed so that we can calculate the location of each grid coordinate
 *  (row, column) by its offset from the start of the entry data.
 */
typedef struct WordSearch__Grid {
    /** The width of the grid, in entries */
    unsigned long long width;
    /** The height of the grid, in entries */
    unsigned long long height;
    /**
     *  A String containing the grid's entries. The length of this field should always be
     *  width * height. The grid is laid out in row-major format - that is, entries are zero-indexed
     *  from the top-left corner of the grid, and can be accessed by (row, column) coordinate pair, as in
     *      char entry = grid->entries.data[ ( row * width ) + column ], OR
     *  by calling the convenience method word_search__grid__entry.
     */
    String entries;
} WordSearch__Grid;

/**
 *  \brief This method determines whether the given WordSearch__GridCoordinates reside within the confines of
 *  the grid.
 *  \param grid The grid upon which the supplied WordSearch__GridCoordinates will be tested.
 *  \param coordinates The WordSearch__GridCoordinates which will be tested.
 *  \returns Returns true if \p coordinates does reside within the grid. That is, coordinates->row < grid->height and
 *  coordinates->column < grid->width.  Returns false otherwise.
 *  \returns Returns false if \p coordinates does not reside within the grid.
 */
bool word_search__grid__contains( WordSearch__Grid grid, WordSearch__GridCoordinates coordinates );

/**
 *  \brief Convenience method to retrieve the value of the entry of the WordSearch__Grid at the specified (row, column)
 *  coordinate pair.
 *  \param grid The WordSearch__Grid from which the entry should be retrieved.
 *  \param coordinates The WordSearch__GridCoordinates at which the entry to be retrieved resides.
 *  \param out__entry_value An out parameter. Upon successful completion, this will store the value of the specified
 *  entry.
 *  \returns Returns true if the operation completed successfully. This operation can fail if the specified coordinates
 *  do not reside within the confines of the WordSearch__Grid.
 *  \returns Returns false if the operation did not complete successfully.
 */
bool word_search__grid__entry( WordSearch__Grid grid, WordSearch__GridCoordinates coordinates, char *out__entry_value );

/**
 *  \brief Given a sequence and an index into that sequence, this method looks up the value of the value of
 *  the corresponding grid entry.
 *  \param grid The WordSearch__Grid containing the desired entry.
 *  \param sequence A pointer to the WordSearch__GridSequence.
 *  \param index The index into the sequence of the desired entry.
 *  \param out_entry An out parameter. Upon successful completion, this will be assigned to the value of the
 *  desired entry.
 *  \returns Returns true if the operation completed successfully. The retrieval can fail if either the index is
 *  greater than or equal to sequence->span.magnitude, or if the corresponding entry is not contained by the
 *  grid.
 *  \returns Returns false if the operation did not complete successfully.
 */
bool word_search__grid__retrieve_sequence_entry(
    WordSearch__Grid grid,
    WordSearch__GridSequence sequence,
    unsigned long long index,
    char* out_entry
);

/**
 *  \brief This method determines whether the supplied sequence of grid entries represents the supplied word.
 *  \param grid The WordSearch__Grid containing the entries described by \p sequence.
 *  \param sequence A pointer to the WordSearch__GridSequence describing the entries of interest on the grid.
 *  \param word A pointer a String containing the word which will be matched to the grid sequence.
 *  \returns true if the entries described by \p sequence exactly match the supplied word, and false if they do not match.
 */
bool word_search__grid__sequence_matches_word(
    WordSearch__Grid grid,
    WordSearch__GridSequence sequence,
    String word
);

/**
 *  @} // group word_search__grid
 */

END_DECLARATIONS

#endif // WORD_SEARCH__GRID__H

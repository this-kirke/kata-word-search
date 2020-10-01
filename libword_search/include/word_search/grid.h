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
     *  A pointer to a String containing the grid's entries. The length of this field should always be
     *  width * height. The grid is laid out in row-major format, that is entries are 0-indexed
     *  from the top-left corner of the grid, and can be accessed by (row, column) coordinate pair, as in
     *      char entry = grid->entries.data[ ( row * width ) + column ], OR
     *  by calling the convenience method word_search__grid__entry.
     */
    String entries;
} WordSearch__Grid;

/**
 *  \brief This method determines whether the given WordSearch__GridCoordinates reside within the grid.
 *  \param grid The grid upon which the supplied WordSearch__GridCoordinates will be tested.
 *  \param coordinates The WordSearch__GridCoordinates which will be tested.
 *  \returns Returns true if \p coordinates does reside within the grid. That is, coordinates->row < grid->height and
 *  coordinates->column < grid->width.  Returns false otherwise.
 *  \returns Returns false if \p coordinates does not reside within the grid.
 */
bool word_search__grid__contains( WordSearch__Grid grid, WordSearch__GridCoordinates coordinates );

/**
 *  @} // group word_search__grid
 */

END_DECLARATIONS

#endif // WORD_SEARCH__GRID__H

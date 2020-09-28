// Internal Includes
#include "word_search/grid_coordinates.h"

bool word_search__grid_coordinates__equals(
    WordSearch__GridCoordinates first,
    WordSearch__GridCoordinates second
){
    if(
        first.row == second.row &&
        first.column == second.column
    ){
        return true;
    }

    return false;
}

bool word_search__grid_coordinates__translate( WordSearch__GridCoordinates coordinates, WordSearch__GridVector vector, WordSearch__GridCoordinates *out__translated_coordinates ){
    switch( vector.direction ){
        case WordSearch__Direction__East:
            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row,
                .column = coordinates.column + vector.magnitude
            };

            return true;
        case WordSearch__Direction__SouthEast:
            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row + vector.magnitude,
                .column = coordinates.column + vector.magnitude
            };

            return true;
        case WordSearch__Direction__South:
            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row + vector.magnitude,
                .column = coordinates.column
            };

            return true;
        case WordSearch__Direction__SouthWest:
            if( vector.magnitude > coordinates.column ){
                return false;
            }

            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row + vector.magnitude,
                .column = coordinates.column - vector.magnitude
            };

            return true;
        case WordSearch__Direction__West:
            if( vector.magnitude > coordinates.column ){
                return false;
            }

            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row,
                .column = coordinates.column - vector.magnitude
            };

            return true;
        case WordSearch__Direction__NorthWest:
            if( vector.magnitude > coordinates.row || vector.magnitude > coordinates.column ){
                return false;
            }

            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row - vector.magnitude,
                .column = coordinates.column - vector.magnitude
            };

            return true;
        case WordSearch__Direction__North:
            if( vector.magnitude > coordinates.row ){
                return false;
            }

            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row - vector.magnitude,
                .column = coordinates.column
            };

            return true;
        case WordSearch__Direction__NorthEast:
            if( vector.magnitude > coordinates.row ){
                return false;
            }

            *out__translated_coordinates = (WordSearch__GridCoordinates) {
                .row = coordinates.row - vector.magnitude,
                .column = coordinates.column + vector.magnitude
            };

            return true;
        default:
            return false;
    }
}

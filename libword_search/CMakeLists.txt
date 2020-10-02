set( libword_search__DIR "${CMAKE_CURRENT_LIST_DIR}" )

add_library(
    libword_search
    ${libword_search__DIR}/src/direction.c
    ${libword_search__DIR}/src/grid.c
    ${libword_search__DIR}/src/grid_coordinates.c
    ${libword_search__DIR}/src/grid_hash_map.c
    ${libword_search__DIR}/src/grid_sequence.c
    ${libword_search__DIR}/src/grid_vector.c
    ${libword_search__DIR}/src/solution.c
)

target_include_directories(
    libword_search
    PUBLIC
    ${libword_search__DIR}/include
)

target_link_libraries(
    libword_search
    PUBLIC
    libkirke
)

target_compile_options(
    libword_search
    PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Werror -Wall -Wextra -pedantic-errors>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

set_target_properties(
    libword_search
    PROPERTIES
    OUTPUT_NAME word_search
)

if( BUILD_TESTS )

    set_target_properties(
        libword_search
        PROPERTIES
        COMPILE_FLAGS "--coverage"
    )

    catch2__add_test(
        NAME test__libword_search__direction
        SOURCES "${libword_search__DIR}/test/test__libword_search__direction.cpp"
        LINK_LIBRARIES libword_search
    )

    catch2__add_test(
        NAME test__libword_search__grid
        SOURCES "${libword_search__DIR}/test/test__libword_search__grid.cpp"
        LINK_LIBRARIES libword_search
    )

    catch2__add_test(
        NAME test__libword_search__grid_coordinates
        SOURCES "${libword_search__DIR}/test/test__libword_search__grid_coordinates.cpp"
        LINK_LIBRARIES libword_search
    )

    catch2__add_test(
        NAME test__libword_search__grid_hash_map
        SOURCES "${libword_search__DIR}/test/test__libword_search__grid_hash_map.cpp"
        LINK_LIBRARIES libword_search
    )

    catch2__add_test(
        NAME test__libword_search__grid_sequence
        SOURCES "${libword_search__DIR}/test/test__libword_search__grid_sequence.cpp"
        LINK_LIBRARIES libword_search
    )

    catch2__add_test(
        NAME test__libword_search__grid_vector
        SOURCES "${libword_search__DIR}/test/test__libword_search__grid_vector.cpp"
        LINK_LIBRARIES libword_search
    )

    catch2__add_test(
        NAME test__libword_search__solution
        SOURCES "${libword_search__DIR}/test/test__libword_search__solution.cpp"
        LINK_LIBRARIES libword_search
    )

endif( BUILD_TESTS )

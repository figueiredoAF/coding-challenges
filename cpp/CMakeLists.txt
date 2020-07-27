cmake_minimum_required(VERSION 3.5)

project(cpp_challenges)

set(CMAKE_CXX_STANDARD 11)

set(ARRAY_STRING_DIR arrays-and-strings/)
set(LINKED_LIST_DIR linked-lists/)
set(UTIL_DIR utils/)

include_directories(
    utils/inc
)

set(SRC_IMPLACE_CHAR_RELACEMENT ${ARRAY_STRING_DIR}/001-inplace-char-replacement.cpp)
set(SRC_WORD_JUMB_LETTERS ${ARRAY_STRING_DIR}/002-word-jumbled-letters.cpp)
set(SRC_WORD_TYPOS ${ARRAY_STRING_DIR}/003-words-with-typos.cpp)
set(SRC_REMOVE_DUPLICATES ${LINKED_LIST_DIR}/001-remove-duplicates.cpp)

add_executable(inplace_char_replacement ${SRC_IMPLACE_CHAR_RELACEMENT})
add_executable(word-jumbled-letters ${SRC_WORD_JUMB_LETTERS})
add_executable(word-typos ${SRC_WORD_TYPOS})
add_executable(remove-duplicates ${SRC_REMOVE_DUPLICATES})
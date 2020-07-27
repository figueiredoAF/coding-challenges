//
// Created by isism on 18/07/2020.
//

#ifndef NATIVE_SEARCH_LIST_ARRAYSSTRINGS_H
#define NATIVE_SEARCH_LIST_ARRAYSSTRINGS_H

#include <string>

namespace util
{
    class ArraysString
    {
    public:
        static bool is_typo(const std::string &str1, const std::string &str2);
        static bool is_typo_insert(const std::string &str1, const std::string &str2);
        static bool is_typo_remove(const std::string &str1, const std::string &str2);
        static bool is_typo_replace(const std::string &str1, const std::string &str2);
        static bool is_partial_permutation(const std::string &str1, const std::string &str2);
        static bool is_permutation(std::string str1, std::string str2);
    };
};


#endif //NATIVE_SEARCH_LIST_ARRAYSSTRINGS_H

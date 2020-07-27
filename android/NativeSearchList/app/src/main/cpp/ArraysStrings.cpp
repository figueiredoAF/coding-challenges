//
// Created by isism on 18/07/2020.
//

#include "ArraysStrings.h"

#include <algorithm>

bool util::ArraysString::is_typo(const std::string &str1, const std::string &str2) {
    int delta = str1.size() - str2.size();

    if (delta == 0) return is_typo_replace(str1, str2);
    else if (delta == 1) return is_typo_remove(str1, str2);
    else if (delta == -1) return is_typo_insert(str1, str2);

    return false;
}

bool util::ArraysString::is_typo_insert(const std::string &str1, const std::string &str2)
{
    if ((str2.size() - str1.size()) != 1) return false;

    int diff = 0; // Early stop based on diff count
    int i = 0;    // Index for str1
    int j = 0;    // Index for str2
    while ((i < str1.size()) && (diff <=1))
    {
        if ((str1[i] != str2[j]) && (diff == 0)) // First difference, it may be the char inserted
        {
            diff++; // Freezes str1 index to compare with next char of str2
        }
        else if (str1[i] != str2[j])
        {
            diff++;
            i++;
        }
        else i++;

        j++; // Always advance str2 index
    }

    return (diff <= 1);
}

bool util::ArraysString::is_typo_remove(const std::string &str1, const std::string &str2)
{
    if ((str1.size() - str2.size()) != 1) return false;

    int diff = 0; // Early stop based on diff count
    int i = 0; // Index for str1
    int j = 0; // Index for str2
    while ((j < str2.size()) && (diff <=1))
    {
        if ((str1[i] != str2[j]) && (diff == 0)) // First difference, it may be the char removed
        {
            diff++; // Freezes str2 index to compare with next char of str1
        }
        else if (str1[i] != str2[j])
        {
            diff++;
            j++;
        }
        else j++;

        i++; // Always advance str1 index
    }

    return (diff <= 1);
}

bool util::ArraysString::is_typo_replace(const std::string &str1, const std::string &str2)
{
    if (str1.size() != str2.size()) return false;

    int diff = 0; // Early stop based on diff count
    for (int i = 0; (i < str1.size()) && (diff <= 1); i++)
    {
        if (str1[i] != str2[i]) diff++;
    }

    return (diff <= 1);
}

bool util::ArraysString::is_partial_permutation(const std::string &str1, const std::string &str2) {

    // Checks if the first characters are different
    if (str1[0] != str2[0]) return false;

    // Check if they are a permutation
    if (!is_permutation(str1, str2)) return false;

    // If word has less than 3 characters and is a permutation, it is also a partial permutation
    if (str1.size() <= 3) return true;

    // Count how many characters were permuted
    float count = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i]) count += 1;
    }

    // It will be a partial permutation of the amount of character permuted is no more that 2/3
    float proportion = count / str1.size();
    if (proportion <= (2.0 / 3.0)) return true;

    return false;
}

bool util::ArraysString::is_permutation(std::string str1, std::string str2)
{
    // Equal strings are not considered a permutation
    if (!str1.compare(str2)) return false;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return !str1.compare(str2);
}
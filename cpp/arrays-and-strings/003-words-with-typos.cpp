/**
 There are three types of typos that can be performed on strings: insert a character,
 remove a character, or replace a character. Given two strings, write a function to
 check if they are one typo (or zero typos) away.
 
 Examples:
 pale, ple ­> true
 pales, pale ­> true
 pale, bale ­> true
 pale, bake ­> false
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>

bool is_typo_insert(std::string str1, std::string str2)
{
    std::cout << "is_typo_insert() - ?" << std::endl;
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

    if (diff <= 1) std::cout << "INSERT typo detected!" << std::endl;
    else std::cout << "is NOT insert typo!" << std::endl;
    return (diff <= 1);
}

bool is_typo_remove(std::string str1, std::string str2)
{
    std::cout << "is_typo_remove() - ?" << std::endl;
    if ((str1.size() - str2.size()) != 1) return false;

    int diff = 0; // Early stop based on diff count
    int i = 0; // Index for str1
    int j = 0; // Index for str2
    while ((j < str2.size()) && (diff <=1))
    {
        std::cout << "is_typo_remove(), i=" << i << ", j=" << j << std::endl;
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

    if (diff <= 1) std::cout << "REMOVE typo detected!" << std::endl;
    else std::cout << "is NOT remove typo!" << std::endl;
    return (diff <= 1);
}

bool is_typo_replace(std::string str1, std::string str2)
{
    std::cout << "is_typo_replace() - ?" << std::endl;
    if (str1.size() != str2.size()) return false;

    int diff = 0; // Early stop based on diff count
    for (int i = 0; (i < str1.size()) && (diff <= 1); i++)
    {
        if (str1[i] != str2[i]) diff++;
    }

    if (diff <= 1) std::cout << "REPLACE typo detected!" << std::endl;
    else std::cout << "is NOT replace typo!" << std::endl;
    return (diff <= 1);
}

bool is_typo(std::string str1, std::string str2)
{
    int delta = str1.size() - str2.size();
    if (delta == 0) return is_typo_replace(str1, str2);
    else if (delta == 1) return is_typo_remove(str1, str2);
    else if (delta == -1) return is_typo_insert(str1, str2);
}

int main(int argc, char **argv)
{
    std::string str1("p");
    std::string str2("");

    if (is_typo(str1, str2)) std::cout << "IS TYPO!" << std::endl;
    else std::cout << "is NOT typo!" << std::endl;

    return 0;
}
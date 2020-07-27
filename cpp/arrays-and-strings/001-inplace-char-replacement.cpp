/**
1. Replacing characters in place:
Given an array of characters, write a method to replace all the spaces with “&32”.
You may assume that the array has sufficient slots at the end to hold the additional
characters, and that you are given the “true” length of the array. (Please perform this
operation in place with no other auxiliary structure).

Example:
Input: “User is not allowed “, 19
Output: "User&32is&32not&32allowed&32" 
 */

// Example program
#include <iostream>
#include <string.h>
#include <stdio.h>

static const uint MAX_SIZE = 128;
char my_array[MAX_SIZE];

// Temporal complexity: O(n)
// Spacial complexity: O(1)
void array_find_and_replace(char *str, int size, const char &search_key, const char *replace_key)
{
    if (!str) return;
    std::cout << "initial string = " << str << std::endl;

    int pen = 0;
    char nextChar = str[pen];
    for (int count = 0; count < size; count++)
    {
        if (nextChar == search_key)
        {
            int delta = strlen(replace_key);
            // Shifts string right by delta characters starting from the fist character
            // after the current pen position (which will be replaced)
            memmove(str + pen + delta, str + pen + 1, strlen(str) - pen - 1);
            // Replace the key character found at pen position
            memmove(str + pen, replace_key, delta);
            //snprintf(str + pen, MAX_SIZE - pen, "&32%s", str + pen + 3);
            pen += delta;
        }
        else
        {
            pen++;
        }
        nextChar = str[pen];
    }
    std::cout << "Final string = " << str << std::endl;
    return;    
}

int main()
{   
    const char find = ' ';
    const char replace[] = "&32";

    std::string input;
    std::cout << "Type a string and press enter:" << std::endl;
    getline(std::cin, input);

    memset(my_array, 0, MAX_SIZE);
    snprintf(my_array, MAX_SIZE, input.c_str());
    array_find_and_replace(my_array, strlen(my_array), find, replace);
}

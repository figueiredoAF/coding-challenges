/**
 Our brain can read texts even if letters are jumbled, like the following sentence: “Yuo
 cna porbalby raed tihs esaliy desptie teh msispeillgns.” Given two strings, write a
 method to decide if one is a partial ­permutation of the other. 
 Consider a partial ­permutation only if:
­ - The first letter hasn’t changed place
­ - If word has more than 3 letters, up to 2/3 of the letters have changed place

 Examples:
 you, yuo ­> true
 probably, porbalby ­> true
 despite, desptie ­> true
 moon, nmoo ­> false
 misspellings, mpeissngslli ­> false
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
static const uint LOG_BUFFER_SIZE = 512;
char log_buffer[LOG_BUFFER_SIZE];

// Temporal complexity: O(nlog(n))
// Spacial complexity: O(n)
bool is_permutation(std::string str1, std::string str2)
{
    if (!str1.compare(str2)) return false; // Equal strings are not considered a permutation
    
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return !str1.compare(str2);
}

// Temporal complexity: O(n)
// Spacial complexity: O(n)
bool is_partial_permutation(const std::string &str1, const std::string &str2)
{
    if (str1[0] != str2[0]) // Compare the first characters
    {
        std::cout << "First character is different" << std::endl;
        return false;
    }
    
    if (!is_permutation(str1, str2))
    {
        std::cout << "Strings are not a permutation" << std::endl;
        return false;
    }

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
    if (proportion <= (2.0 / 3.0))
    {
        return true;
    }
     
    return false;
      
}

int main(int argc, char **argv)
{
    std::string str1;
    std::string str2;

    std::cout << "Enter the first string, then press enter:" << std::endl;
    getline(std::cin, str1);
    std::cout << "Enter the second string, then press enter:" << std::endl;
    getline(std::cin, str2);

    if (is_partial_permutation(str1, str2))
    {
        memset(log_buffer, 0, LOG_BUFFER_SIZE);
        snprintf(log_buffer, LOG_BUFFER_SIZE, "The strings \"%s\" and \"%s\" ARE a partial permultation.",
                 str1.c_str(), str2.c_str());
        std::cout << log_buffer << std::endl;
    }
    else
    {
        memset(log_buffer, 0, LOG_BUFFER_SIZE);
        snprintf(log_buffer, LOG_BUFFER_SIZE, "The strings \"%s\" and \"%s\" are NOT a partial permultation.",
                 str1.c_str(), str2.c_str());
        std::cout << log_buffer << std::endl;
    }

    return 0;
}
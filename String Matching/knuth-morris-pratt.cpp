// KMP Algorithm for String Matching
// Assumes lowercase English letters only
// Time: O(n + m), Space: O(m)

#include <bits/stdc++.h>
using namespace std;

// Builds the Longest Prefix-Suffix (LPS) array for the given pattern.
// lps[i] = length of the longest proper prefix which is also a suffix in pattern[0..i]
vector<int> buildLongestPrefixSuffixArray(const string& pattern)
{
    int patternLength = pattern.size();
    vector<int> lps(patternLength, 0);

    // lengthOfPreviousPrefix stores the length of the last longest prefix-suffix
    int lengthOfPreviousPrefix = 0;
    int currentIndex = 1;

    while (currentIndex < patternLength)
    {
        if (pattern[currentIndex] == pattern[lengthOfPreviousPrefix])
        {
            lengthOfPreviousPrefix++;
            lps[currentIndex] = lengthOfPreviousPrefix;
            currentIndex++;
        }
        else if (lengthOfPreviousPrefix == 0)
        {
            // No valid prefix-suffix found, assign 0
            lps[currentIndex] = 0;
            currentIndex++;
        }
        else
        {
            // Try to fallback to a shorter valid prefix-suffix
            lengthOfPreviousPrefix = lps[lengthOfPreviousPrefix - 1];
        }
    }

    return lps;
}

// Finds all starting indices in `text` where `pattern` appears using the KMP algorithm
vector<int> findPatternOccurrencesKMP(const string& text, const string& pattern)
{
    int textLength = text.size();
    int patternLength = pattern.size();
    vector<int> occurrences;

    if (patternLength == 0)
    {
        occurrences.push_back(0); // By convention, empty pattern matches at index 0
        return occurrences;
    }

    vector<int> lps = buildLongestPrefixSuffixArray(pattern);

    int textIndex = 0;     // Pointer for text
    int patternIndex = 0;  // Pointer for pattern

    while (textIndex < textLength)
    {
        if (text[textIndex] == pattern[patternIndex])
        {
            textIndex++;
            patternIndex++;
        }

        if (patternIndex == patternLength)
        {
            // Match found, record the starting index
            occurrences.push_back(textIndex - patternLength);

            // Continue searching using the LPS array
            patternIndex = lps[patternIndex - 1];
        }
        else if (textIndex < textLength && text[textIndex] != pattern[patternIndex])
        {
            if (patternIndex != 0)
            {
                // Fallback in the pattern using the LPS array
                patternIndex = lps[patternIndex - 1];
            }
            else
            {
                // No prefix match, move to next character in text
                textIndex++;
            }
        }
    }

    return occurrences;
}

// Sample usage
int main()
{
    string text = "ababcabcababc";
    string pattern = "abc";

    vector<int> matchIndices = findPatternOccurrencesKMP(text, pattern);

    for (int index : matchIndices)
    {
        cout << "Pattern found at index: " << index << endl;
    }

    return 0;
}

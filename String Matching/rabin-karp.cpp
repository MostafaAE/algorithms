// Rabin-Karp Algorithm for String Matching
// Assumes lowercase English letters only ('a' to 'z')
// Time Complexity: O(n + m) average
// Space Complexity: O(1), excluding result storage

#include <bits/stdc++.h>
using namespace std;

// Use 64-bit integers to safely handle large hash values
using ll = long long;

// Constants
const int BASE = 26;          // Alphabet size for lowercase letters
const ll MOD = 1e9 + 7;        // Large prime modulus to reduce collisions

vector<int> rabinKarpSearch(const string& text, const string& pattern)
{
    int textLength = text.size();
    int patternLength = pattern.size();

    // Edge case: pattern longer than text
    if (patternLength > textLength)
        return {};

    vector<int> matchingIndices;

    ll patternHash = 0;    // Hash of the pattern
    ll windowHash = 0;     // Hash of current window in the text
    ll highestPower = 1;   // BASE^(patternLength - 1) % MOD

    // Precompute highest power of base used in hash rolling
    for (int i = 0; i < patternLength - 1; ++i)
    {
        highestPower = (highestPower * BASE) % MOD;
    }

    // Compute the hash of the pattern and the first window in text
    for (int i = 0; i < patternLength; ++i)
    {
        patternHash = (patternHash * BASE + (pattern[i] - 'a')) % MOD;
        windowHash = (windowHash * BASE + (text[i] - 'a')) % MOD;
    }

    // Slide the window over the text
    for (int i = 0; i <= textLength - patternLength; ++i)
    {
        // Check hash match
        if (patternHash == windowHash)
        {
            // Confirm actual match to eliminate false positives from hash collisions
            bool isMatch = true;
            for (int j = 0; j < patternLength; ++j)
            {
                if (text[i + j] != pattern[j])
                {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch)
                matchingIndices.push_back(i);
        }

        // Update the rolling hash: remove left char and add right char
        if (i < textLength - patternLength)
        {
            ll leftChar = (text[i] - 'a') * highestPower % MOD;
            windowHash = (windowHash - leftChar + MOD) % MOD;
            windowHash = (windowHash * BASE + (text[i + patternLength] - 'a')) % MOD;
        }
    }

    return matchingIndices;
}

// Sample usage
int main()
{
    string text = "ababcabcababc";
    string pattern = "abc";

    vector<int> result = rabinKarpSearch(text, pattern);

    for (int index : result)
    {
        cout << "Pattern found at index: " << index << endl;
    }

    return 0;
}

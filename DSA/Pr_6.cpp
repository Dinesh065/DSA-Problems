#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestPrefixSuffix(const string& s) {
    int n = s.length();
    vector<int> lps(n, 0); // lps[i] will store the length of the longest prefix suffix for s[0..i]
    
    int length = 0; // length of the previous longest prefix suffix
    int i = 1; // start from the second character

    // Loop calculates lps[i] for i = 1 to n-1
    while (i < n) {
        if (s[i] == s[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps[n - 1]; // The last value in the lps array is the result
}

int main() {
    string s = "ababcababc";
    cout << "Length of the longest prefix which is also a suffix: " << longestPrefixSuffix(s) << endl;

    // You can test with more examples
    s = "aaaa";
    cout << "Length of the longest prefix which is also a suffix: " << longestPrefixSuffix(s) << endl;

    s = "abcdabc";
    cout << "Length of the longest prefix which is also a suffix: " << longestPrefixSuffix(s) << endl;

    s = "abcab";
    cout << "Length of the longest prefix which is also a suffix: " << longestPrefixSuffix(s) << endl;

    s = "aabaa";
    cout << "Length of the longest prefix which is also a suffix: " << longestPrefixSuffix(s) << endl;

    s = "abcdef";
    cout << "Length of the longest prefix which is also a suffix: " << longestPrefixSuffix(s) << endl;

    return 0;
}

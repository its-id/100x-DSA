/*
    Problem Description: Given a string containing lower case english alphabets, what is the most occurring character?

    Example:

    Input: s = "hello"
    Output: l
    Explanation: Frequencies - 'h': 1, 'e': 1, 'l': 2, 'o': 1
*/

// Problem Link: https://leetcode.com/problems/find-the-highest-altitude

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// MAIN FUNCTION TO FOCUS ON!
char highestOccurence(string &str) {
    int max_char_occured = 0;
    char max_char = str[0];
    int freq[26] = {0};

    for(int i = 0; i < str.size(); i++){
        freq[str[i] - 'a']++;
        if(freq[str[i] - 'a'] > max_char_occured){
            max_char_occured = freq[str[i] - 'a'];
            max_char = str[i];
        }
    }

    return max_char;

}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    /** IGNORE: code to check time taken to run **/
    time_t start, end;
    time(&start); 
    ios_base::sync_with_stdio(false); 
    /** IGNORE: code to check time taken to run **/
    
    // Main Function Call
    cout << "Ans: " << highestOccurence(s) << endl;
    
    /** IGNORE: code to check time taken to run **/
    time(&end); 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
        << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    /** IGNORE: code to check time taken to run **/

    return 0;
}
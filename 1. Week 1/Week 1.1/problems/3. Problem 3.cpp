/**

Q - You are given a string containing lower-case english alphabets. You need to perform the following operation as many times as possible: 

Take the first occurrence of each alphabet if it exists and remove it from the string. Eventually the string becomes empty.

For example, let’s say the string is “ababcba”.
In the first move, we need to remove the first occurrence of each character ‘a’, ‘b’ and ‘c’. It becomes
“ababcba” → “abba”
Again, we repeat unless the string becomes empty
“abba” → “ba”
“ba” → “”

Find the last non-empty value for the string.

For eg: In this case, the answer is “ba”.
**/

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
void solve(string &s) {

    unordered_map<char, int> freq;
    int max_occurence = 0;

    //finding the maximum occurence of a character
    for(char c: s){
        freq[c]++;
        max_occurence = max(max_occurence, freq[c]);
    }

    string ans = "";

    //finding all the chars with that max occurence as those will be the ones remaining in the last phase.
    //after adding that char to answer, we remove it from map so that we don't add it again.
    for(int i = s.length() - 1; i >= 0; i--){
        if(freq.count(s[i]) && freq[s[i]] == max_occurence) ans += s[i], freq.erase(s[i]);
    }

    //we reverse since we want to maintain the order of the characters as they were in the string.
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return;

}

int main() {
    cout << "Enter number of Test Cases: ";
    int t;
    cin>>t;
    while(t--){
        cout << "Enter the string: ";
        string s;
        cin>>s;
    
        /** IGNORE: code to check time taken to run **/
        time_t start, end;
        time(&start); 
        ios_base::sync_with_stdio(false); 
        /** IGNORE: code to check time taken to run **/
        


        // Main Function Call
        solve(s);



        /** IGNORE: code to check time taken to run **/
        time(&end); 
        double time_taken = double(end - start); 
        cout << "Time taken by program is : " << fixed 
            << time_taken << setprecision(5); 
        cout << " sec " << endl; 
        /** IGNORE: code to check time taken to run **/
    }

    return 0;
}
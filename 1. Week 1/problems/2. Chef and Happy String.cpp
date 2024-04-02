//PROBLEM Link: https://www.codechef.com/practice/course/strings/STRINGS/problems/HAPPYSTR

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
    int vowels_count = 0;
    for(int i = 0; i < s.length(); i++){

        //we check if current substring window has vowel, if yes, we increment the count of vowels.
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vowels_count++;

        //else, we check if the count of vowels in the current window was > 2, if yes, we already got a substring respecting the condition.

        }else if(vowels_count > 2){
            cout << "Happy" << endl;
            return;
        
        //else, we reset our window to start from current element and reset the vowel_count to 0
        }else{
            vowels_count = 0;
        }
    }

    //last check for case when all the chars in the string are vowels. so we reach the end without going to else if or else conditions.
    if(vowels_count < 2) cout << "Sad" << endl;
    else cout << "Happy" << endl;
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--){
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
// Problem Link: https://leetcode.com/problems/number-of-good-pairs/description/

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
int numIdenticalPairs(vector<int>& nums) {
    
    int count = 0;

    unordered_map<int, int> freq;

    for(int num: nums) freq[num]++;

    for(auto it: freq) count = count + ((it.second * (it.second - 1))/2);

    return count;
    
}

int main() {
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    
    vector<int> nums(n, 0);
    cout << "Enter the array of numbers: " << endl;
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    /** IGNORE: code to check time taken to run **/
    time_t start, end;
    time(&start); 
    ios_base::sync_with_stdio(false); 
    /** IGNORE: code to check time taken to run **/
    
    // Main Function Call
    cout << "Ans: " << numIdenticalPairs(nums) << endl;
    
    /** IGNORE: code to check time taken to run **/
    time(&end); 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
        << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    /** IGNORE: code to check time taken to run **/

    return 0;
}
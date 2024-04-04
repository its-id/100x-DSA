// Problem: https://leetcode.com/problems/maximum-population-year/
// This is a Maxium Intersection problem

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
int maximumPopulation(vector<vector<int>>& logs) {
    
    int freq[101] = {0};

    for(int i = 0; i < logs.size(); i++){
        //doing mod to reduce the years down below 101.
        int bornYear = logs[i][0] % 1950;
        int deathYear = logs[i][1] % 1950;

        //inc & dec population of each year in curr range
        //in year i, how much population are we gaining or losing?
        freq[bornYear]++; 
        freq[deathYear]--;
    }

    int max_freq_idx = 0;
    for(int i = 1; i < 101; i++){

        freq[i] += freq[i-1];

        //looping over the freq arr to find the year at which idx population was highest
        if(freq[i] > freq[max_freq_idx]){
            max_freq_idx = i;
        }
    }

    //adding back the '1950' to get the actual year
    return 1950 + max_freq_idx;
}

int main() {
    int n, m;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter m: ";
    cin >> m;
    
    vector<vector<int>> nums(n, vector<int>(m, 0));
    cout << "Enter the 2D array numbers: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> nums[i][j];
        }
    }
    
    /** IGNORE: code to check time taken to run **/
    time_t start, end;
    time(&start); 
    ios_base::sync_with_stdio(false); 
    /** IGNORE: code to check time taken to run **/
    
    // Main Function Call
    cout << "Ans: " << maximumPopulation(nums) << endl;
    
    /** IGNORE: code to check time taken to run **/
    time(&end); 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
        << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    /** IGNORE: code to check time taken to run **/

    return 0;
}
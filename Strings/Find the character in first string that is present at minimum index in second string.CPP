#include <bits/stdc++.h> 
using namespace std; 
  
// function to find the minimum index character 
void printMinIndexChar(string str, string patt) 
{ 
    // unordered_map 'um' implemented as hash table 
    unordered_map<char, int> um; 
  
    // to store the index of charcter having 
    // minimum index 
    int minIndex = INT_MAX; 
  
    // lengths of the two strings 
    int m = str.size(); 
    int n = patt.size();- 
  
    // store the first index of each character of 'str' 
    for (int i = 0; i < m; i++) 
        if (um.find(str[i]) == um.end()) 
            um[str[i]] = i; 
  
    // traverse the string 'patt' 
    for (int i = 0; i < n; i++) 
  
        // if patt[i] is found in 'um', check if  
        // it has the minimum index or not accordingly  
        // update 'minIndex' 
        if (um.find(patt[i]) != um.end() &&  
            um[patt[i]] < minIndex) 
            minIndex = um[patt[i]]; 
  
    // print the minimum index character 
    if (minIndex != INT_MAX) 
        cout << "Minimum Index Character = "
             << str[minIndex]; 
  
    // if no character of 'patt' is present in 'str' 
    else
        cout << "No character present"; 
} 
  
// Driver program to test above 
int main() 
{ 
    string str = "geeksforgeeks"; 
    string patt = "set"; 
    printMinIndexChar(str, patt); 
    return 0; 
} 

Output:
Minimum Index Character = e

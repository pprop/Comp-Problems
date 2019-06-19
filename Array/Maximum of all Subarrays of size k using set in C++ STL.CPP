// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the sum of maximum of 
// all k size sub-arrays using set in C++ STL 
int maxOfSubarrays(int arr[], int n, int k) 
{ 
	// Create a set of pairs 
	set<pair<int, int> > q; 

	// Create a reverse iterator to the set 
	set<pair<int, int> >::reverse_iterator it; 

	// Insert the first k elements along 
	// with their indices into the set 
	for (int i = 0; i < k; i++) { 
		q.insert(pair<int, int>(arr[i], i)); 
	} 

	// To store the sum 
	int sum = 0; 
	for (int j = 0; j < n - k + 1; j++) { 

		// Iterator to the end of the 
		// set since it has the maximum value 
		it = q.rbegin(); 

		// Add the maximum element 
		// of the current window 
		sum += it->first; 

		// Delete arr[j] (Leftmost element of 
		// current window) from the set 
		q.erase(pair<int, int>(arr[j], j)); 

		// Insert next element 
		q.insert(pair<int, int>(arr[j + k], j + k)); 
	} 

	// Return the required sum 
	return sum; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 4, 10, 54, 11, 8, 7, 9 }; 

	int K = 3; 

	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << maxOfSubarrays(arr, n, K); 

	return 0; 
} 

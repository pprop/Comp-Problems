Input : 5, 2, 1, 1, 2, 2
Output : 5 4

#include <bits/stdc++.h> 
using namespace std; 

// Function to replace consecutive equal 
// elements 
void replace_elements(int arr[], int n) 
{ 
	int pos = 0; // Index in result 

	for (int i = 0; i < n; i++) { 
		arr[pos++] = arr[i]; 

		while (pos > 1 && arr[pos - 2] == 
						arr[pos - 1]) { 
			pos--; 
			arr[pos - 1]++; 
		} 
	} 

	// to print new array 
	for (int i = 0; i < pos; i++) 
		cout << arr[i] << " "; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 6, 4, 3, 4, 3, 3, 5 }; 
	int n = sizeof(arr) / sizeof(int); 
	replace_elements(arr, n); 
	return 0; 
} 

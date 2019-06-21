Given an Array of Integers and an Integer value k, find out k non-overlapping sub-arrays which have k maximum sums.

Input : arr1[] = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2}, 
             k = 3.
Output : Maximum non-overlapping sub-array sum1: 8, 
         starting index: 6, ending index: 7.
         
         Maximum non-overlapping sub-array sum2: 6, 
         starting index: 0, ending index: 2.
         
         Maximum non-overlapping sub-array sum3: -1, 
         starting index: 3, ending index: 3.
         
         
         
#include <bits/stdc++.h> 
using namespace std; 

void kmax(int arr[], int k, int n) { 

	for(int c = 0; c < k; c++){ 

		int max_so_far = numeric_limits<int>::min(); 
		int max_here = 0; 
 
		int start = 0, end = 0, s = 0; 
		for(int i = 0; i < n; i++) 
		{ 
			max_here += arr[i]; 
			if (max_so_far < max_here) 
			{ 
				max_so_far = max_here; 
				start = s; 
				end = i; 
			} 
			if (max_here < 0) 
			{ 
				max_here = 0; 
				s = i + 1; 
			} 
		} 

		cout << "Maximum non-overlapping sub-array sum"
			<< (c + 1) << ": "<< max_so_far 
			<< ", starting index: " << start 
			<< ", ending index: " << end << "." << endl; 

		for (int l = start; l <= end; l++) 
			arr[l] = numeric_limits<int>::min(); 
	} 
	cout << endl; 
} 

int main() 
{ 
	int arr1[] = {4, 1, 1, -1, -3, 
				-5, 6, 2, -6, -2}; 
	int k1 = 3; 
	int n1 = sizeof(arr1) / sizeof(arr1[0]); 

	kmax(arr1, k1, n1); 

	// Test case 2 
	int arr2[] = {5, 1, 2, -6, 2, -1, 3, 1}; 
	int k2 = 2; 
	int n2 = sizeof(arr2)/sizeof(arr2[0]); 
	
	// Function calling 
	kmax(arr2, k2, n2); 
	
	return 0; 
} 

Input : 1 1 2
Output : YES
swap 1 (second last element) and 2 (last element), 
to obtain 1 2 1, which has distinct neighbouring 
elements .


// C++ program to check if we can make 
// neighbors distinct. 
#include <bits/stdc++.h> 
using namespace std; 

void distinctAdjacentElement(int a[], int n) 
{ 
	// map used to count the frequency 
	// of each element occuring in the 
	// array 
	map<int, int> m; 

	// In this loop we count the frequency 
	// of element through map m . 
	for (int i = 0; i < n; ++i) 
		m[a[i]]++; 

	// mx store the frequency of element which 
	// occurs most in array . 
	int mx = 0; 

	// In this loop we calculate the maximum 
	// frequency and store it in variable mx. 
	for (int i = 0; i < n; ++i) 
		if (mx < m[a[i]]) 
			mx = m[a[i]]; 

	// By swapping we can adjust array only 
	// when the frequency of the element 
	// which occurs most is less than or 
	// equal to (n + 1)/2 . 
	if (mx > (n + 1) / 2) 
		cout << "NO" << endl; 
	else
		cout << "YES" << endl; 
} 

// Driver program to test the above function 
int main() 
{ 
	int a[] = { 7, 7, 7, 7 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	distinctAdjacentElement(a, n); 
	return 0; 
} 

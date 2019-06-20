Given an array of 0s and 1s, and k, Find the longest continuous streak of 1s after flipping k 0s to 1s. 

E.x array is {1,1,0,0,1,1,1,0,1,1} 
k = 1 (which means we can flip ‘k’ one 0 to 1) 

Answer: 6 (if we flip 0 at index 7, we get the longest continuous streak of 1s having length 6)


#include <iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a = { 1, 1, 0, 0, 1, 1, 1, 0,1,1 };
        // k is the number of bits that can be flipped
	int k = 1;

	int len = 0;
	for (int fast = 0, slow = 0; fast < a.size(); fast++) {                
		if (a[fast] == 0) --k;
        
		for (; k < 0; slow++) {
			if (a[slow] == 0) ++k;
		}
		cout<<fast-slow<<" ";		
		len = max(len, fast - slow + 1);
	}
    cout<<len;
}

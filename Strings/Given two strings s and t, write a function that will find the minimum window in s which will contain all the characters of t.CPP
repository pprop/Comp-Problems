Example 1
INPUT
S = "tutorial cup"
T = "oti"

OUTPUT
Minimum window is "tori"

Example 2
INPUT 
S = "zaaskzaa"
T = "zsk"

OUTPUT
Minimum window is "skz"


#include<bits/stdc++.h>
#define NO_OF_CHARS 256
using namespace std;
  
// Function to find smallest window containing
// all characters of T
string findSubString(string S, string T)
{
    int Slen = S.length();
    int Tlen = T.length();
 
    // check if string's length is less than T's
    // length. If yes then no such window can exist
    if (Slen < Tlen)
    {
        cout << "No such window exists";
        return "";
    }
 
    int S_count[NO_OF_CHARS] = {0};
    int T_count[NO_OF_CHARS] = {0};
 
    // store occurrence of characters of 't'
    for (int i = 0; i < Tlen; i++)
        T_count[T[i]]++;
 
    int start = 0, start_index = -1, min_len = INT_MAX;
 
    // start traversing the string
    int count = 0;  // count of characters
    for (int i = 0; i < Slen ; i++)
    {
        // count occurrence of characters of string
        S_count[S[i]]++;
 
        // If s's char matches with t's char
        // then increment count
        if (T_count[S[i]] != 0 &&
            S_count[S[i]] <= T_count[S[i]] )
            count++;
 
        // if all the characters are matched
        if (count == Tlen)
        {
            //minimizng the current window
            //If the current window has a character which occured more number of times
            //than the character in T string, then remove starting chars
            while ( S_count[S[start]] > T_count[S[start]]
                   || T_count[S[start]] == 0)
            {
 
                if (S_count[S[start]] > T_count[S[start]])
                    S_count[S[start]]--;
                start++;
            }
 
            // update window size
            int len_window = i - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }
 
    // If no window found
    if (start_index == -1)
    {
       cout << "No such window exists";
       return "";
    }
 
    // Return substring starting from start_index
    // and length min_len
    return S.substr(start_index, min_len);
}
 

int main()
{
    string S = "tutorial cup";
    string T = "oti";
 
    cout << "Smallest window is : "<< findSubString(S, T)<<endl;
    return 0;
}

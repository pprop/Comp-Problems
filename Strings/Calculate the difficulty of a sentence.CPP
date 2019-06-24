#include <iostream> 
using namespace std; 
  
// Utility function to check character is vowel 
// or not 
bool isVowel(char ch) 
{ 
    return ( ch == 'a' || ch == 'e' || 
             ch == 'i' || ch == 'o' || 
             ch == 'u'); 
} 
  
// Function to calculate difficulty 
int calcDiff(string str) 
{ 
  
    int count_vowels = 0, count_conso = 0; 
    int hard_words = 0, easy_words = 0; 
    int consec_conso = 0; 
  
    // Start traversing the string 
    for (int i = 0; i < str.length(); i++) 
    { 
        // Check if current character is vowel 
        // or consonant 
        if (str[i] != ' ' && isVowel(tolower(str[i]))) 
        { 
            // Increment if vowel 
            count_vowels++; 
            consec_conso = 0; 
        } 
  
        // Increment counter for consonant 
        // also mainatin a separate counter for 
        // counting consecutive consonants 
        else if (str[i]!= ' ') 
        { 
            count_conso++; 
            consec_conso++; 
        } 
  
        // If we get 4 consecutive consonants 
        // then it is a hard word 
        if (consec_conso == 4) 
        { 
            hard_words++; 
  
            // Move to the next word 
            while (i < str.length() && str[i]!= ' ') 
                i++; 
  
            // Reset all counts 
            count_conso = 0; 
            count_vowels = 0; 
            consec_conso = 0; 
        } 
  
        else if ( i < str.length() && 
                  (str[i] == ' ' || i == str.length()-1)) 
        { 
            // Increment hard_words, if no. of consonants are 
            // higher than no. of vowels, otherwise increment 
            // count_vowels 
            count_conso > count_vowels ? hard_words++ 
                                       : easy_words++; 
  
            // Reset all counts 
            count_conso = 0; 
            count_vowels = 0; 
            consec_conso = 0; 
        } 
    } 
  
    // Return difficulty of sentence 
    return 5 * hard_words + 3 * easy_words; 
} 
  
// Drivers code 
int main() 
{ 
    string str = "I am a geek"; 
    string str2 = "We are geeks"; 
    cout << calcDiff(str) << endl; 
    cout << calcDiff(str2) << endl; 
  
    return 0; 
} 

Output:
12
11

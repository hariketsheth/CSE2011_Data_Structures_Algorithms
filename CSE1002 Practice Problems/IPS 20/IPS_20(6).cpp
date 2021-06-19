KVP_STLVectors
Given a set of characters, design an algorithm and write a C++ code to display the characters in descending order. Also, display the total number of vowels in the vector.

Hint: Use STL Vector for implementation

Input Format:

Number of characters, 'n'

char 1

char 2

…

char n

Output Format:

Characters in descending order

Total number of vowels

Note : "N <= 0" print "Invalid Input"

Input
Output
Processing Involved
Solution Alternatives
Algorithm/ Pseudocode
Font Size
18
Language
Editor Theme 
Select a Theme





Your code has Passed Execution!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool descend (char a, char b){ return a>b; }

int main(){
    int num;
    cin>>num;
    if (num<=0)
        cout<<"Invalid Input"<<endl;
    else{
        vector<char> charac;
        char temp;
        int count_vowel = 0;
        for(int i=0; i<num; i++){
            cin>>temp;
            charac.push_back(temp);
        }
        sort(charac.begin(), charac.end(), descend);
        for(auto it : charac){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' )
                count_vowel +=1 ;
            cout<<it<<endl;
        }
        cout<<count_vowel<<endl;
    }
}

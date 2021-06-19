STL_Sort Strings
Write a C++ Program and Subsequent pseudocode to sort the given list of 'N' strings using STL(Arrays/Vectors/List) of your choice. Also, display the
names in alphabetical order without duplication.

Input Format:
Read n
Read Names


Output Format:
Display the names in alphabetical order without duplication

Note : if the value of N is -ve, Print "Invalid Input"
 

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

int main(){
    
    int num;
    string name;
    cin>>num;
    
    if(num<0)
        cout<<"Invalid Input"<<endl;
        
    else{
        vector<string> vc;
        vector<string> :: iterator it;
        for(int i=0; i<num; i++){
            cin>>name;
            it = find(vc.begin(),vc.end(),name);
            if(it == vc.end())
                vc.push_back(name);
        }
        
        sort(vc.begin(), vc.end());
        for(it = vc.begin(); it != vc.end(); ++it)
            cout << *it << endl;
    }
}

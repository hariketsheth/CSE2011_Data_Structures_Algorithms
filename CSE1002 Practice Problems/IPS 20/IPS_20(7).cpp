TestMapSTL
In connection with TechnoVIT'19, SCSE is organizing the Code Contest Program, in which they were asked you to write a C++ Application  and equivalent Pseudo code to read the 'N' pair elements, each associated with Key and Value. Use an appropiate data structure for the above.

Input : 

Read 'N'  (where N = No. of Elements)

Read next 'N' fewer lines for 'Name of the Student' and 'CGPA' (as Key-Value Pair)

Output:

Print all the elements in a Ascending order based on CGPA of a Student.

Note : if 'N' = 0, then print "No Elements"

 

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
#include <map>
using namespace std;

int main(){
    int num;
    cin>>num;
    if(num==0)
        cout<<"No Elements";
    else{
        map<float,string> students;
        float CGPA;
        string name;
        for(int i=0; i<num; i++){
            cin>>name>>CGPA;
            students.insert(pair<float,string>(CGPA,name));
        }
        for(auto it : students){
            cout<<it.first<<"-->"<<it.second<<endl;
        }
    }
    
}

KVP_STLMapsGrades
Write C++ Program and subsequent pseudo code to read both StudentName and CGPA in STL Maps, where StudentName is a 'Key' and its associated Value is CGPA. Now Compute Grades for the Student as below

if CGPA >= 9, then Grade is 'S'

if 8 <= CGPA < 9, then Grade is 'A'

if 7 <= CGPA < 8, then Grade is 'B'

if 6 <= CGPA < 7, then Grade is 'C'

if 5 <= CGPA < 6, then Grade is 'D'

if CGPA < 5, then Grade is 'F'

Create a Mulitmap to store StudentName, CGPA and Grade, Where StudentName is a 'Key' and its associated values are CGPA and Grade.

Input :

Read the Value of 'N' (Number of Students)

Output:

print the StudentName, CGPA and Grade (for N Students)

Note : if N<0, print "Invalid Input"

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
    map <string, float> student;
    map <string, float> :: iterator it;
    int num;
    float marks;
    string name;
    cin>>num;
    if(num<0)
        cout<<"Invalid Input"<<endl;
    else{
        for(int i=0; i<num; i++){
            cin>>name>>marks;
            student.insert(pair<string, float>(name,marks));
        }
        multimap <string,pair<float,char>> grades;
        char grade;
        for(it = student.begin(); it!= student.end(); it++){
            if(it->second>=9)
                grade = 'S';
            else if(it->second>=8)
                grade = 'A';
            else if(it->second>=7)
                grade = 'B';
            else if(it->second>=6)
                grade = 'C';
            else if(it->second>=5)
                grade = 'D';
            else
                grade = 'F';
            grades.insert(make_pair(it->first,make_pair(it->second,grade)));
        }
        
        multimap <string, pair<float,char>> :: iterator it1;
        for (it1 = grades.begin(); it1!= grades.end(); it1++)
            cout<<it1->first<<","<<it1->second.first<<","<<it1->second.second<<endl;
    }
}

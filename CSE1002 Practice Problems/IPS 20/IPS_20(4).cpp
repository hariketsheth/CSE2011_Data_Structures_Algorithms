KVP_STLMaps
Write a CPP program  and subsequent pseudo code to read the both Name and Age of the student in a Map(Dictionary), where Name is referred as 'key' and Age is referred as 'value'. Compute the average age of the student and  print the  elements of the Map, whose age is less than avg.

Input
Read the value of 'N' (N Elements in MAp)
Next 'N' read Name and Age.

Output
Average Age of the Student
List of Elements in Map, whose age is less than Avg   (Age in Sorted Order)

Note : if N<0, then print "Invalid Input"
 

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
#include <algorithm>
#include <vector>
using namespace std;
bool sort_age(pair<string, int>&data1, pair<string,int>&data2){
    return data1.second<data2.second;
}
void sort(map<string,int>&data, int avg){
    vector<pair<string,int>>ages;
    for(auto& it : data)
        ages.push_back(it);
    sort(ages.begin(),ages.end(),sort_age);
    for(auto it1 : ages){
        if(it1.second < avg)
            cout<<it1.first<<"-->"<<it1.second<<endl;
    }
}
int main(){
    int num, age, avg=0;
    string name;
    cin>>num;
    if(num<0)
        cout<<"Invalid Input"<<endl;
    else{
        map<string,int> data;
        for(int i=0; i<num; i++){
            cin>>name>>age;
            avg += age;
            data.insert(pair<string,int>(name,age));
        }
        avg /= num;
        map<string,int> :: iterator it;
        cout<<avg<<endl;
        sort(data,avg);
    }
}

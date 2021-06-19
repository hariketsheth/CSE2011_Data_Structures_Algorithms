KVP_STLList
Given List of numbers, write a cpp program and subsequent pseudo code to print the elements in an Even-Odd Order and also count the frequency of each element in a list.

Input : Number of Elements 'N'

Element-1

Element-2

...

....

Element-n

Output:

List of Elements in Even-Odd Order

The list of Element and its Frequency (Occurance) (i.e The Lower Valued Element with its Occurances First )

 NOte : if N is less than Zero, print "Invalid Input"
 
 
 
 
 
 #include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    int num, temp;
    cin>>num;
    if(num<0)
        cout<<"Invalid Input"<<endl;
    else{
        list<int> numbers;
        list<int> :: iterator it = numbers.begin();
        list<int> unique;
        for(int i=0; i<num; i++){
            cin>>temp;
            numbers.push_back(temp);
            if(count(unique.begin(), unique.end(),temp) == 0)
                    unique.push_back(temp);
        }
        advance(it,2);
        for(int i =1; i<numbers.size(); i+=2){
            if(i==1)
                cout<<*it;
            else
                cout<<","<<*it;
            advance(it,2);
        }
        it = numbers.begin();
        for(int i=0; i<numbers.size(); i+=2){
            cout<<","<<*it;
            advance(it,2);
        }
        unique.sort();
        for(auto it : unique){
            cout<<"\n"<<it<<","<<count(numbers.begin(), numbers.end(), it);
        }
    }
}

Maps-STL
Given 'n' names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. You will then be given the value of 'm' and  followed with 'm' number of names to query your phone book for phoneNumber. For each 'name' queried, print the associated entry from your phone book on a new line in the form name=phoneNumber; if an entry for  'name' is not found, print "Not Found" instead.

Note: Your phone book should be a Dictionary/Map/HashMap data structure.

Input Format

The first line contains an integer, 'n', denoting the number of entries in the phone book.
Each of the 'n'  subsequent lines describes an entry in the form of 2 space-separated values on a single line. The first value is a friend's name, and the second value is a 10-digit phone number.

After the  'n' lines of phone book entries, there are an unknown number of lines of queries. Each line (query) contains a  'name' to look up, and you must continue reading lines until there is no more input.

Note: Names consist of lowercase English alphabetic letters and are first names only.

Constraints

1 <= n <= 5
1 <= lines <= 3
Output Format

On a new line for each query, print "Not Found" if the name has no corresponding entry in the phone book; otherwise, print the full name and phoneNumber in the format name=phoneNumber.



#include <iostream>
#include <map>
using namespace std;

int find(map<string,string>& phone, string name);
int main(){
    int num;
    string name, number;
    cin>>num;
    if(num<=0)
        cout<<"Invalid Input"<<endl;
    else{
        map<string,string> phonebook;
        for(int i=0; i<num; i++){
            cin>>name>>number;
            phonebook.insert(pair<string,string>(name,number));
        }
        cin>>num;
        for(int i=0; i<num; i++){
            cin>>name;
            auto it = phonebook.find(name);
            if(it!=phonebook.end())
                cout<<it->first<<"="<<it->second<<endl;
            else
                cout<<"Not Found"<<endl;
        }
    }
}

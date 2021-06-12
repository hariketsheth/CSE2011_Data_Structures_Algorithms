/*
Tender scrutiny using reference variable
A government organization received tenders from ‘n’ vendors for their campus renovation work. It has to determine and select the vendor who had quoted the least amount for this renovation work. Given the registration number, address and amount quoted by vendor, design an algorithm and write a C++ code to print the details of vendor for whom the tender will be given. Write a function that returns the details of vendor by reference concept.

Input Format:

Number of tenders received

Registration number of vendor1

Address of vendor1

Amount quoted by vendor1

 Registration number of vendor2

Address of vendor2

Amount quoted by vendor2

………

………….

Registration number of vendor n

Address of vendor n

Amount quoted by vendor n

 

Output Format:

Print the registration number of vendor who won the tender

Print address of vendor who won the tender

Boundary Conditions:

Number of Tender >1

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
using namespace std;

class Vendor{
   public:
        int amount;
        int reg_id;
        string addr;
        void get_data(){
            cin>>reg_id>>addr>>amount;
        }
};
void print(Vendor *s, int n){
    int min = s[0].amount;
    int ind = 0;
    for(int i=1; i<n; i++){
        if(s[i].amount < min){
            min = s[i].amount;
            ind = i;
        }
    }
    cout<< s[ind].reg_id<<"\n"<< s[ind].addr;
    
}
int main(){
    int num;
    cin>>num;
    Vendor *s = new Vendor [num];
    for(int i=0; i<num; i++)
        s[i].get_data();
    print(s,num);
}Tender scrutiny using reference variable
A government organization received tenders from ‘n’ vendors for their campus renovation work. It has to determine and select the vendor who had quoted the least amount for this renovation work. Given the registration number, address and amount quoted by vendor, design an algorithm and write a C++ code to print the details of vendor for whom the tender will be given. Write a function that returns the details of vendor by reference concept.

Input Format:

Number of tenders received

Registration number of vendor1

Address of vendor1

Amount quoted by vendor1

 Registration number of vendor2

Address of vendor2

Amount quoted by vendor2

………

………….

Registration number of vendor n

Address of vendor n

Amount quoted by vendor n

 

Output Format:

Print the registration number of vendor who won the tender

Print address of vendor who won the tender

Boundary Conditions:

Number of Tender >1
*/

/*
Name: Hariket Sukeshkumar Sheth
Topic: CPP Practice Problems
*/

#include <iostream>
using namespace std;

class Vendor{
   public:
        int amount;
        int reg_id;
        string addr;
        void get_data(){
            cin>>reg_id>>addr>>amount;
        }
};
void print(Vendor *s, int n){
    int min = s[0].amount;
    int ind = 0;
    for(int i=1; i<n; i++){
        if(s[i].amount < min){
            min = s[i].amount;
            ind = i;
        }
    }
    cout<< s[ind].reg_id<<"\n"<< s[ind].addr;
    
}
int main(){
    int num;
    cin>>num;
    Vendor *s = new Vendor [num];
    for(int i=0; i<num; i++)
        s[i].get_data();
    print(s,num);
}

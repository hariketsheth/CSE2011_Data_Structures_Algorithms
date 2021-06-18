/*
A student may apply for an arts college or an engineering college after his school. Admission to arts college or engineering college, is based on the marks obtained in the six subjects : English, Second language, Maths, Physics, Chemistry and Computer Science.  Both the applications have the following details : application number, name, age, marks in all six subjects and cut-off for the eligibility. For Arts college, cut-off is the   average of  marks in all the subjects and whereas for engineering colleges cut-off is the average of marks in maths, physics, chemistry plus the marks scored in the entrance exam.  Given all the required details, Design an OOP model to compute the cut-off marks and implement it using C++.
Note: Syntax to print ‘x’ decimal places of variable ‘a’
include

use
cout<<fixed<<setprecision(x)<<a;

Input Format
Type of application (0 for arts student and 1 for engineering student)
Application Number
Name of student
Age
Marks scored in English
Marks scored in Second Language
Marks scored in Maths
Marks scored in Physics
Marks scored in Chemistry
Marks scored in Computer Science
Marks scored in entrance exam (only for engineering student)

Output Format
Name of student
Cut-off marks
*/

// Start of Pre-Code
#include <iostream>
#include <iomanip>
using namespace std;

class college_Appln{
    protected:
        int appln_No;
        char name[30];
        int age;
        float marks[6];
    public:
        void get();
        void print();
};

class arts_Appln : public college_Appln {
    float entrance;
    float cutoff;

    public:
        void calc_Cutoff();
        void print();
};

class engg_Appln:public college_Appln{
    float cutoff;
    float entrance;
    
    public:
        void get();
        void print();
        void calc_Cutoff();
};
// End of Pre -Code


void college_Appln :: get(){
    cin >> appln_No >> name >> age;
    for(int i=0; i < 6; i++)  
      cin>>marks[i];
}
void college_Appln :: print(){
    cout << name << endl;
}
void arts_Appln :: calc_Cutoff(){
    cutoff=0;
    for(int i=0;i < 6;i++)
      cutoff+=marks[i];
    cutoff/=6;
}
void arts_Appln :: print(){ 
    college_Appln :: print ();
    cout<< fixed << setprecision(2) << cutoff << endl; 
}  
void engg_Appln :: get(){ 
    cin>>appln_No>>name>>age;
    for(int i=0;i < 6;i++)  
      cin >> marks[i];
    cin >> entrance;
}
void engg_Appln :: calc_Cutoff(){
    cutoff = (marks[2]+marks[3]+marks[4])/3 + (entrance);
}
void engg_Appln :: print(){    
    college_Appln :: print ();
    cout<< fixed << setprecision(2) << cutoff << endl; 
}

// Start of Post - Code
int main(){
    int ch;
    cin>>ch;
    if(ch==0){
        arts_Appln a;
        a.get();
        a.calc_Cutoff();
        a.print();
    }
    else{
        engg_Appln e;
        e.get();
        e.calc_Cutoff();
        e.print();
    }
}
//End of Post - Code 

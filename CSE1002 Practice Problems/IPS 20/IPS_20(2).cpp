KVP_STLList_Fibo
Write a CPP Program and Subsequent Pseudo Code to implement fibonacci series for first 'N' numbers and store them in STL List.

Consider the below Table(Character Fibonacci)

a b c d e f  g h  i   j   k   l    m  n   o   p   q   r   s    t    u  v    w   x   y   z
0 1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

Input :

Read Choice (1... Integer Data Type / 2... Character Data Type)

Read the Value of 'N'

Output

List of Fibornacci Series using STL List.

NOte : if 'N'<0, print "Invalid Input"

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void fib_i(list<int> final, int num){
    int a =0, b=1, c=1;
    while(num>0){
        final.push_back(a);
        a = b;
        b = c;
        c = a+b;
        num--;
    }
    for(auto it = final.begin(); it!=final.end(); ++it)
        cout<<*it<<endl;
}
void fib_c(list<char> final, int num){
    int a = 0, b = 1, c = 1;
    while(num>0){
        final.push_back((char)(a+97));
        a = b;
        b = c;
        c = a+b;
        num--;
    }
    for(auto it = final.begin(); it != final.end(); ++it)
        cout<<*it<<endl;
}

int main(){
    int choice, num;
    cin>>choice;
    if(choice==1){
        list<int> vi;
        cin>>num;
        if(num<0)
            cout<<"Invalid Input"<<endl;
        else{
            fib_i(vi,num);
        }
    }
    else{
        list<char> vc;
        cin>>num;
        if(num<0)
            cout<<"Invalid Input"<<endl;
        else{
            fib_c(vc,num);
        }
    }
}

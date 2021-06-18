/*
Customer discount
A retail store is maintaining their customer details such as customer id and name, mobile number and address. They have decided to introduce a preferred customer plan for the existing customer. Any customer is given the status of preferred customer if they have made purchases more than 10 times. Preferred customers earn discounts based on their cumulative purchase amount as follows:

Cumulative Purchase Amount
Discount (%)

>= Rs. 5000
1

>= Rs 10,000
2

>= Rs 15000
3

>= Rs 20000
4

Design an OOP model and implement it using C++ program. Refer the declaration of classes and application program to do the design. The program must get the details, compute bill amount and print details both for ordinary and preferred customers.
For example, if a preferred customer makes three purchases of amounts 3000, 7000, 8000 then the amount to be paid for each bill is 3000, 6860 and 7760 and the total amount to be paid is 17620

Input Format
Type of customer (0 for ordinary customer and 1 for preferred customer)
Name
Mobile number
Address
Customer id
Number of bills
Total Cost of products in bill1

....

Total Cost of products in bill-n


Output Format
Total amount to be paid by the customer for 'n' bills
*/

#include <iostream>
using namespace std;

class customer_details{
    protected :
        string name, address, mobile;
        int id, num_bills, bills[30];
        void get_data();
};

void customer_details :: get_data(){
    cin >> name >> mobile >> address >> id >> num_bills;
    for(int i=0; i<num_bills; i++) 
        cin>>bills[i];
}

class customer : public customer_details{
    public :
        void get();
        float calc_Total();
};
void customer :: get(){
    customer_details :: get_data();
}
float customer :: calc_Total(){
    float amount = 0;
    for(int i=0; i<num_bills; i++)
        amount += bills[i];
    return(amount);
}
class preferred_Customer : public customer_details{
    public :
    void get();
    float calc_Total();
};
void preferred_Customer :: get(){
    customer_details :: get_data();
}
float preferred_Customer :: calc_Total(){
    float amount = 0, purchase = 0;
    for(int i=0; i<num_bills; i++){  
        purchase += bills[i]; 
        if(purchase >=20000)
           amount += bills[i]*0.96;
        else if(purchase >= 15000)
            amount += bills[i]*0.97;
        else if(purchase >= 10000)
            amount += bills[i]*0.98;
        else if(purchase >= 5000)
            amount += bills[i]*0.99;
        else
            amount += bills[i];
    }
    return(amount);
}


// Start of Post - Code
int main(){
      int ch;
      //get choice of customer
      cin>>ch;
      if(ch==0){
          customer c1;
          //get the details of customer
          c1.get();
          //calculate total amount to be paid
          //develop a function in customer class that will calculate 
          // the total amount and return it
          cout<<c1.calc_Total();
      }
      else{
          //preferred customer
          preferred_Customer pc;
          //get details
          pc.get();
          //function should calculate and return total amount
          cout<<pc.calc_Total();
      }
}
// End of Post - Code

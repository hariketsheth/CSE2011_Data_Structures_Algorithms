/*
Black Coin in Board game
Colored coin game is a 8X8 board game which has many colored coins. Each coin has a weight and power. Power of a coin is defined by the moves that it can make. In a move,  a black coin can move one step vertically upwards.  A red coin can move one step either horizontally, vertically or diagonally. Given the current position of a black coin and list of movements made by it, print all possible next positions of the coin. If the total number of moves made by a black coin is greater than 6, then that coin should be treated as a red coin and the subsequent moves will be as that of the red coin. At any point of time, the coin cannot move outside the board. The rows and columns of the board are numbered as 1 to 8. Print the horizontal movement of coin in an increasing order of columns and print the vertical movement of coin in increasing order of rows. To print, the diagonal movement of the coin refer the sample board config given below. If the current position of your coin is 4,4 then print P1, P2 ... P8 in order..

 
Input Format

Weight of black coin

Current row position of coin

Current column position of coin

Number of moves made by black coin

Output Format

Weight of black coin

List of possible next positions

One position in a line with row and column separated by a comma
*/

/*
Name: Hariket Sukeshkumar Sheth
Topic: CPP Practice Problems
*/

#include<iostream>
using namespace std;
class coin
{
	protected:
	int weight;
	int curr_X;
	int curr_Y;
	public:
	void get();
	void print();
	//return the current row position
	int get_Curr_X();
	//return the current col position
	int get_Curr_Y();
	//return weight of the coin
	int get_Weight();
	//pure virtual function that the derived classes must implement
	virtual void move()=0;
};
//Define two more classes black_Coin and red_Coin


void coin :: get()
{
	cin>>weight>>curr_Y>>curr_X;
}
void coin :: print()
{
	cout<<weight<<"\n"; 
}  
int coin :: get_Curr_X() 
{ 
	return(curr_X); 
}  
int coin :: get_Curr_Y() 
{ 
	return(curr_Y); 
}  
int coin :: get_Weight() 
{ 
	return(weight); 
} 
void coin :: move(){} 
class black_Coin : public coin 
{ 
	public : 
	int moves_coin; 
	void get() 
	{ 
		coin :: get(); 
		cin>>moves_coin;
	}
	bool gained_Power()
	{
		return(moves_coin>=5);
	}
	void move()
	{
	cout<<curr_Y<<","<<curr_X+1;
	}
};
class red_Coin : public coin
{
    public:
    void move();
    void set_Curr_Pos_Wt (black_Coin b){
        weight=b.get_Weight();
    	curr_X=b.get_Curr_X();
    	curr_Y=b.get_Curr_Y();
    }
};
void red_Coin :: move(){
	cout<<curr_Y-1<<","<<curr_X<<"\n"<<curr_Y+1<<","<<curr_X<<"\n"<<curr_Y<<","<<curr_X-1<<"\n"<<curr_Y<<","<<curr_X+1<<"\n";
	cout<<curr_Y-1<<","<<curr_X-1<<"\n"<<curr_Y+1<<","<<curr_X-1<<"\n"<<curr_Y-1<<","<<curr_X+1<<"\n"<<curr_Y+1<<","<<curr_X+1<<"\n";
}

int main()
{
	coin *c;
	black_Coin b;
	b.get();
	red_Coin r;
       //Function to check if the black coin has gained power
       // It gains power when the number of movements made is greater than or equal to 5
	if(b.gained_Power())
	{
	//Make the black coin as red coin
        //set weight and current position of black coin to a red coin
	 r.set_Curr_Pos_Wt(b);
	 c = &r;	
         //Print only weight of the coiin
	 c->print();
        //Print all possible moves
	 c->move();
	}
	else
	{
		c = &b;
	        //Print only weight of the coiin
	       c->print();
               //Print all possible moves
	       c->move();
	}
	
}

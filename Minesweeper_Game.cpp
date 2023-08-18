/* OOP SEMESTER 2 PROJECT 
       BSCS SECTION 2E1 
     (INDIVIDUALLY DONE)
 AISHA MUHAMMAD NAWAZ [20L-0921] */
#include <iostream>
#include "mygraphics.h" // Library included to use  Graphics
#include "myconsole.h" // Library included to use Graphics
#include <conio.h> // Library included to use Graphics
#include <iostream>
#include <stdlib.h> // Library included to use rand function
#include <time.h> // Library included to use rand function
using namespace std;

class Board{
	int x;
	int y;
public :
char board[5][5];
	Board () // Basically intializes the board 
	{
		for(int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			board[i][j]='X'; // Making each location show X
		x=0;
		y=0;
	}
	int getx() // returns x coordinate
	{
		return x;
	}
	int gety () // returns y coordinate 
	{
	return y;
	}
		void getCoordinates() // To get user input of move or x,y coordinates
	{
	      cout<<"Enter Coordinates(x, y): ";
        
		do {
		cin>>x>>y;
		if ( (x>4 || x<0)||(y>4 || y<0) )
		{
cout<<"INVALID COORDINATES BOARD IS 5x5!"<<endl;
		cout<<"Please enter Again!"<<endl;
		}
		}
		while ((x>4 || x<0)||(y>4 || y<0));
		
	}

	
	
	void PrintBoard() // To print the whole board
	{
		cout<<"Board: "<<endl;

for (int i=0;i<5;i++)
{
	for (int j=0;j<5;j++){
		cout<<"   "<<board[i][j]<<" ";
	}
        cout<<endl;
}

	}



};
class MineLocation : public Board {
	int xm[5]; // Will store the x coordinates of mine location (5 mines) [Will be random]
	int ym[5]; // Will store the y coordinates of mine location (5 mines) [Will be random]
	int noOFMinesAdj; // Will store the value of adjacent mines

public:	
	MineLocation ()
	{
		for(int i=0;i<5;i++)
	    {    		 
			 xm[i]=rand()% 5;  // Will randomly select x coordinate for the location of mine
	         ym[i]=rand()% 5;	// Will randomly select y coordinate for the location of mine	
			 if (xm[i]==0 && ym[i]==0) //This if condition will make sure that mine location is never set to (0,0)
		i--; // will basically discard the 0,0 coordinates	
			 if(i!=0)
{	for (int j=i-1;j>=0;j--) // to make sure same mine locations aren't repeated (meaning 2 mines at same coordinates)
	{
	if (xm[i]==xm[j] && ym[i]==ym[j])
		i--;
	}
		}
		}
	}
	void PrintMineCoordinates ()
	{ 
		// This function was made to see the location(coordinates) of the 5 mines and to test the winning function while making the game
	for (int k=0;k<5;k++)
		cout<<"xm : "<<xm[k]<<" ym: "<<ym[k]<<endl;
	
	}
	bool isitamine()
	{
		// As the name suggests this function checks whether the x & y coordinates the user entered has a mine or not
		for(int k=0;k<5;k++)
		{
	if (getx()==xm[k] && gety()==ym[k])
	{	board[getx()][gety()]='M'; // To show user a mine has been exploaded
	return true; // function returns true if mine found!
	}
		}
		return false; // function returns false if mine not found.
	}

	void  findAdjacentmines()
	{ // This function counts the adjacent mines of user entered x,y coordinates
		noOFMinesAdj=0;
	for(int k=0;k<5;k++)
	{
		for(int i=getx()-1;i<=getx()+1;i++)
		{
			for(int j=gety()-1;j<=gety()+1;j++)
	         {
				 if (i==xm[k] && j==ym[k])
					noOFMinesAdj++;
			}
		}
	}
	if (isitamine()==false) // This if condition makes sure the number of mines in surrounding area of user entered x,y coordinates is visible in the board
	board[getx()][gety()]=noOFMinesAdj+48; // Char Array hence have to add 48
	}
	int getxm(int i)
	{
		int xi=xm[i];
	return xi;
	}
	int getym(int i)
	{
		int yi=ym[i];

	return yi;
	}
	
	
	
};
class WinnerCheck : public MineLocation
{
public:
bool checkifwin()
	{  // This function finds if user has won the game
		int minel=0; // Just a signal variable used to identify if selected coordinate is a mine location while checking for remaining X's in board
for (int i=0;i<5;i++)
{
for (int j=0;j<5;j++)
	{
		for (int k=0;k<5;k++)
		{
	if (i==getxm(k)&&j==getym(k)) // This part makes sure the X is not of a mine's location
		minel=1;
		}
				if (board[i][j]=='X'&&minel==0)
					return false; // if not won yet returns false
		minel=0;
		}
    }
	
return true; // if user has won the game returns true
	
	}
};
int main()
{
srand (time(0)); // This is for the purpose of using rand function

// Color Declaration
    COLORREF White=RGB(255,255,255);
	COLORREF Black = RGB (0,0,0);
	COLORREF Pink = RGB (255,182,193);
	COLORREF Red = RGB (255,0,0);
	COLORREF Grey= RGB (128,128,128);
	COLORREF Green= RGB (34,139,34);
	COLORREF Yellow RGB (255, 255, 0);
	COLORREF Blue RGB (0,0,255);
	COLORREF Brown RGB(165,42,42);
	COLORREF Orange RGB(255,128,0);
	COLORREF Purple RGB(80,00,80);
	int n;
//* MENU -----------------------------------------------------------------------------------------------------------
	for (int i=0;i<800;i=i+50)
	{
		myDrawTextWithFont(80+i,2,60,"*",Pink,Black);
		Sleep(20);
		myDrawTextWithFont(80+i,350,60,"*",Pink,Black);
		Sleep(20);
	}
	Sleep(100);
	myDrawTextWithFont(250,110,55," -   Welcome to the Menu   - ",White,Black);
	myEllipse(800,100, 900,200,White,Black);
	myEllipse(100,100, 200,200,White,Black);
		myDrawTextWithFont(250,190,45,"-> To Start a New Game Enter 1 ",White,Green);
	myDrawTextWithFont(300,260,65,"-> To Exit Enter 0 ",White,Red);

		cin>>n;
	ClearScreen();
	//*-----------------------------------------------------------------------------------------------------------------------
	if (n==1){
		myDrawTextWithFont(230,250,35,"------WELCOME TO THE MINESWEEPER GAME!------------",Red, Black);
			for (int i=0;i<800;i=i+100)
			{
		myEllipse(100+i,100, 200+i,200,Black,White);
		Sleep(90);
		myEllipse(100+i,100, 200+i,200,Black,Black);
		}
		ClearScreen();
	WinnerCheck obj; // An object of derived class is made to be used in the whole game
	while (true)
	{
	//	obj.PrintMineCoordinates(); // Uncomment this to win the game & check if the win function works (for evaluator's ease)
		obj.getCoordinates(); // To get x an y coordinates (move) of user
     	obj.findAdjacentmines(); // To find adjacent mines to the move made
	    obj.PrintBoard(); // Print resultant output
		if (obj.isitamine()==true) // Check if mine exploaded
		{	cout<<"Sorry! You lost the game, a mine has exploaded at location ("<<obj.getx()<<","<<obj.gety()<<")."<<endl<<endl;
				Sleep(1000);
		ClearScreen();
			myDrawTextWithFont(350,150,65," GAME OVER! ",Red,Black);
		Sleep(600);
		break; // break; to make sure game ends.
		}
	if (obj.checkifwin()==true) // Checks if user has won the game
	{ ClearScreen();
		myDrawTextWithFont(230,200,40,"Congratulations! You have won the game!",Blue, Black);
		Sleep(1500);
		ClearScreen(); // For decoration Purposes
		myDrawTextWithFont(450,200,35,"YAY!",Yellow, Black);
		Sleep(600);
		ClearScreen();
		break; // break; to make sure game ends. 
	}
	}
	}
	else
		if (n==0)
		{	myDrawTextWithFont(300,150,100,"Game Exit!",Pink, Black);
		Sleep(600);
		ClearScreen();
}



	system("pause");
	return 0;
}
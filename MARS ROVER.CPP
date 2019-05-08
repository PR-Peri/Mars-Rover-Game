/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2018/19
Name: PERIVITTA A/P RAJENDRAN
ID  : 1171101579
Lecture Section : TC02
Tutorial Section: TT03
Assignment: 2
Email: 1171101579@STUDENT.MMU.EDU.MY
Phone: 0165260944
********************************************/

#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector> //map part
#include <fstream>
#include <ctime> //for time() in srand( time(NULL) );

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Mars    // Map is know as mars

{
 private:
 vector < vector<char> > map;
 int dimX, dimY;          // dim is known as dimensions
 int Nogold;
 char Hill;
 char Trap;
 char gold;

 public:
 Mars()
 {

 init();

 }

 int getDimX();
 int getDimY();

 void init();
 void display();

 int getObject(int x,int y);
 void setObject(int x, int y, char p);

 bool isInsideMap(int x, int y);
 bool isEmpty(int x, int y);

bool isHill(int x, int y);
bool isTrap(int x, int y);

void goldCollection(int x, int y,char gold);
void score();


};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Rover        // The movement part
{

private:
int x,y;
char heading;
int Nogold;

public:
Rover();

Rover (int,int,char);
bool turnRight (Mars& mars);    // links to map of mars and void 7
bool turnLeft(Mars& mars);      // links to map of mars and void 7
bool move(Mars& mars);
void land(Mars& mars);    //links a map of Mars to a Rover
//void displayPosition();

};

Rover::Rover()
{

  x =0;
  y =0;
  heading = '^';

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Rover::Rover ( int X , int Y , char heading ) //refrence to the rover on top
{


x= X;
y= Y;

heading = heading;


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Rover::land(Mars& mars)  //The map
{
int xCen,yCen;
char possibleHeading[] = {'^', 'v', '<', '>'};
xCen =  mars.getDimX();     // function gets the value from the void
yCen =  mars.getDimY();

 x = (xCen/2) + (xCen%2);  // Calculates the center point of the arrow based on the dimension, (depends on the dimX and dimY value)
 y = (yCen/2) + (yCen%2);

mars.setObject(x,y,heading); // The header will be set to centre
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////



//void displayPosition()
//{
//cout << x <<" "<< y <<" "<< heading;
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Rover::turnLeft(Mars& mars) // As the arrow is turned to its left side
{
if(heading=='^')
{
   heading= '<';
}

 else if(heading =='v')
 {
    heading='>';
 }

 else if(heading =='<')
 {
   heading='v';
 }

 else if(heading =='>')
 {
    heading='^';
 }


 mars.setObject(x,y,heading);  //It set's the header on the mars map
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Rover::turnRight(Mars& mars) // As the arrow is turned to its right side
{

  if(heading =='^')
  {
    heading= '>';
  }

   else if(heading =='v')
   {
     heading='<';
   }

   else if(heading =='<')
   {
      heading='^';
   }

   else if(heading =='>')
   {
      heading='v';
   }

   mars.setObject(x,y,heading);  //It set's the header on the mars map

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Rover::move(Mars& mars)  // This is created based on the x-y axis plane.
{
 if(heading=='^')
  {
      y++;   //Based on the y-axis, if it points up then its y positive axis
  }

 else if(heading=='v')
 {
      y--;  //Based on the y-axis, if it points up then its y negative axis
 }

 else if(heading=='<')
  {
      x--; //Based on the x-axis, if it points up then its x negative axis
  }

 else if(heading=='>')
  {
      x++; //Based on the x-axis, if it points up then its x positive axis
  }

 mars.setObject(x,y,heading);
 system("cls");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Mars::isEmpty(int x, int y)                               // Based on exercise 1.5
{    bool empt;
    if (map[dimY-y][x-1] ==' ')
      empt=true;
    else
      empt=false;
    return empt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Mars::isInsideMap(int x, int y)                           // Based on exercise 1.5 lab (Own refrence)- test1-6
{    bool empt;
    if (x<=dimX && x>0 && y<=dimY && y>0)
      empt=true;
    else
      empt=false;
    return empt;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Mars::isTrap(int x, int y) //OBSTACLES 1 in the map
{    bool empt;
  char trap ='#';
  char heading;

    if (heading==trap)
      empt=true;
    else
      empt=false;
    return empt;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Mars::isHill(int x, int y)  //OBSTACLES 2 in the map
{
  char heading;
  char Hill=false;

  while(true)
  {
    if (heading==Hill)
    cout << setw(2) << "It's a hill" << endl;
    cout << setw(2) << "Failed to execute "<< endl;
    break;
  }


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mars::goldCollection(int x, int y, char gold)
{
  int heading;

   gold = '*';

  cout << setw(2) << "Number of golds =>  ";
  int Nogold;
  cin >> Nogold;


  if (heading=='*')
  {
    Nogold++;   // counter as the gold's are collected
  }
  //generategold();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void score()
//{
//   score = (gold*50) - (commandSequence.size()*5) - (j++*1)
//}



int Mars::getObject(int x,int y)                     // Based on exercise 1.3 Mars Lab (My own refrence)
{
    return map[dimY-y][x-1];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mars::setObject(int x, int y, char p)
{
  map[dimY-y][x-1]=p;                                       // Based on exercise 1.4
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mars::init()
{
 int x,y;

int noOfObjects = 10; //number of objects in the objects array

// char 178 = hill from ASCII

unsigned char objects[noOfObjects] = {178,178,178,'#','#','?','?','?','?','?' };
char gold = '*';   //character have been set for the gold


cout << setw(2) << " Let's Explore Mars " << endl;
cout << setw(2) << endl;

cout << setw(2) << " Mars Dimension X => ";
int DimX;
cin >> DimX;  //User's input at the beginning

if (DimX<0)    //If user enters invalid value
{
  cout << setw(2) << " Invalid value, please re-enter the Dimension value !" << endl;
  cout << setw(2) <<endl;
  cout << setw(2) << " Mars Dimension X => ";
  cin >> DimX;
}
dimX = DimX;  // It will be used as a reference



cout << setw(2) << " Mars Dimension Y => ";
int DimY;
cin >> DimY;  //User's input at the beginning

if (DimY<0)    //If user enters invalid value
{
  cout << setw(2) << " Invalid value, please re-enter the Dimension value !" << endl;
  cout << setw(2) <<endl;
  cout << setw(2) << " Mars Dimension Y => ";
  cin >> DimY;
}
dimY = DimY;  // It will be used as a reference


cout << setw(2) << " Number of golds  => ";
int Nogold;
cin >> Nogold;     //Object under ROVER

 //create dynamic 2D array using vector

 map.resize(dimY); //create rows
 for (int i=0; i<dimY; ++i)

 {
 map[i].resize(dimX); //resize each rows
 }
 //put random chars into the vector array

 for (int i=0; i<dimY; ++i)  // Dimension for the characters to fill in
 {
   for (int j=0; j<dimX; ++j)  // Dimension for the characters to fill in
   {

     int objNo = rand() % noOfObjects; // Objects will be randomly shuffled based on the table above.
     map[i][j] = objects[ objNo ];
    // int  Noofgold = rand() % Nogold;

    }

 }


}

 int Mars::getDimX(){return dimX;}    //  Output of the dimension (dimX)
 int Mars::getDimY(){return dimY;}    // Output of the dimension (dimY)



/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mars::display()      //Printing, the lines and spaces of the map based on dimensions value by the user.
{
 system("cls");

    cout << setw(2) << endl;
    cout << setw(30) << "  Curiosity, welcome to Mars!  " <<   endl;
//Precision is for the output of cout to be accurate

 for (int i=0; i<dimY; ++i)
 {
 cout << " ";

 for (int j=0; j<dimX; ++j) // for loop for the lines to be accurate
 {
 cout << "+-";
 }

 cout << "+" << endl;

 cout << setw(2) << (dimY-i);

 for (int j=0; j<dimX; ++j)
  {
    cout << "|" << map[i][j];  // Map is [i]x[j] - based on dimension x,y
  }
    cout << "|" << endl;
  }

  cout << " ";
  for (int j=0; j<dimX; ++j)

 {
 cout << "+-";
 }
 cout << "+" << endl;

 cout << " ";
 for (int j=0; j<dimX; ++j)
 {
 int digit = (j+1) /10;
 cout << " ";

 if (digit==0)
 cout << " ";
 else
 cout << digit;
 }

 cout << endl;
 cout << " ";

 for (int j=0; j<dimX; ++j)
 {
 cout << " " << (j+1)%10;
 }
 cout << endl << endl;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void test1()  //map of mars
{
  Mars mars;
  mars.display();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void test2()     // Map of mars
{

 Mars mars;
 mars.display();  // Display the map of mars
 cout << endl;
 cout << setw(2) << "Dim X = " << mars.getDimX() << endl;  // Prints based on the size of dimension X , value is based on the user input
 cout << setw(2) << "Dim Y = " << mars.getDimY() << endl;  // Prints based on the size of dimension X , value is based on the user input
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void test3()      // Based on Mars Rover exercise [REFERENCE]
{
  Mars mars;
  mars.display();
  int x,y;
  char obj;

  x = 1; y = 1;
  obj = mars.getObject(x,y);
  cout << setw(2) << "Object at column " << x << " and row " << y << " is ["
  << obj << "]" << endl;

  x = 15; y = 5;
  obj = mars.getObject(x,y);
  cout << setw(2) << "Object at column " << x << " and row " << y << " is ["
  << obj << "]" << endl;

  x = 5; y = 2;
  obj = mars.getObject(x,y);
  cout << setw(2) << "Object at column " << x << " and row " << y << " is ["
  << obj << "]" << endl;

  x = 10; y = 4;
  obj = mars.getObject(x,y);
  cout << setw(2) << "Object at column " << x << " and row " << y << " is ["
  << obj << "]" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void test4()                  // Based on Mars Rover exercise [REFERENCE]
{
Mars mars;
mars.setObject( 1, 1, 'A');
mars.setObject(15, 1, 'B');
mars.setObject(15, 5, 'C');
mars.setObject( 1, 5, 'D');
mars.display();

cout << setw(2) << "The object A should be at column 1 and row 1" << endl;
cout << setw(2) << "The object B should be at column 15 and row 1" << endl;
cout << setw(2) << "The object C should be at column 15 and row 5" << endl;
cout << setw(2) << "The object D should be at column 1 and row 5" << endl;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void test5()                // Based on Mars Rover exercise [REFERENCE]
{
Mars mars;
mars.setObject( 2, 4, 'Z');
mars.setObject( 10, 3, ' ');
mars.display();

cout << setw(2) << "Coordinate (2,4) is ";
if ( mars.isEmpty(2,4) )
cout << setw(2) << "empty.";
else
cout << setw(2) << "Not empty.";

cout << endl;
cout << setw(2) << "Coordinate (10,3) is ";
if ( mars.isEmpty(10,3) )
cout << setw(2) << "empty.";
else
cout << setw(2) << "not empty.";
cout << endl;

cout << setw(2) << "Coordinate (15,5) is ";
if ( mars.isInsideMap(15,5) )
cout << setw(2) << "inside map.";
else
cout << setw(2) << "not inside map.";
cout << endl;

cout << setw(2) << "Coordinate (0,0) is ";
if ( mars.isInsideMap(0,0) )
cout << setw(2) << "inside map.";
else
cout << setw(2) << "not inside map.";
cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void test6()          // Based on Mars Rover exercise [REFERENCE]
{
Mars mars;
Rover curiosity;
curiosity.land(mars);
mars.display();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void test7()

{
Mars mars;
int x,y; char heading ;
Rover curiosity; //Connector

int Nogold=2;  // Fixed value for collection of gold

int gold = 0;  // intializer for the counter gold, if collected then in it will add
int j=0;  // counter for every command Sequence
int score=0 ;
//score = (gold*50) - (commandSequence.size()*5) - (j++*1)

curiosity.land(mars);
mars.display();

string commandSequence;


bool done = false;
  do
  {

      cout << setw(2) << " Mission: Get all the golds!!, Do not get trapped!! " << endl;
      cout << setw(2) << endl;
      cout << setw(2) <<" L = Turn Left, R = Turn Right, M = Move   " << endl;

      int var=178;   // To display the ASCII character [Hill]

      cout << setw(2) <<  (char)var << " = Hill   # = Trap    * = Gold    Q = Quit " << endl;
      cout << setw(2) << endl;


      cout << setw(2) << " Total Command Sequence [S] =>  " << commandSequence.size() << endl;


      cout << setw(2) << " Total Command [C] =>  " << j++ << endl;

      cout << setw(2) << " Total Golds [G] => " << gold << " " << " / " << Nogold << " " << " of golds" << endl;

      cout << setw(2) << " Total Score = [G] x 50 - [S] x 5 - [C] x 1 =>  " << score << endl;

      cout << setw(2) << endl;

      cout << setw(2) << " Example Sequence: MMLMMMRMMRMRMLLL" << endl;
      cout << setw(2) << " Enter command sequence => " << endl;
      cout << setw(2) << endl;

      cin  >> setw(2) >> commandSequence;
      cout << setw(2) << endl;



      for(int i=0 ; i < commandSequence.size() ; i++  )
      {

        if(commandSequence[i]=='L' || commandSequence[i]=='l' )
        {
          curiosity.turnLeft(mars);
          mars.display();
          system("pause");
        }


        else if (commandSequence[i]=='R'|| commandSequence[i]=='r')

        {
          curiosity.turnRight(mars);
          mars.display();
          system("pause");
        }


        else if (commandSequence[i]=='M' || commandSequence[i]=='m')
        {
          curiosity.move(mars);
          mars.display();
          system("pause");
        }

        else if (commandSequence[i] == 'Q'|| commandSequence[i]=='q')
        {
          done = true;

          break;
        }

        else
        {
          cout << setw(2) << "Invalid rover Movement " <<endl;
          cout << setw(2) << "Please, try again !" << endl;
          system("pause");
        }


      }

    }

    while (!done);
    {
      cout << setw(2)  << "Thank You, for using Mars Rover Program!" << endl;
      cout << setw(2) << "Have a great day !"<< endl;
      cout << setw(2)  << endl;

    }

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{

srand( time(NULL) ); //different map each time the program is run
srand( 1 ); //start with seed number 1, can be any other number
//test1();
//test2();
//test3();
//test4();
//test5();
//test6();

test7();
system("pause");
}


/*
{
  char again;
  do
   {
     cout << setw(2) << "Do you want to see the Map of Mars? (y/n)  =>  " << endl;
     cin >> again;
   }
   while (!done)
       (again == 'y' || again == 'Y');
        cout << setw(2)  << "Goodbye" << endl;


}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

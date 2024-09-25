/* Towers of Hanoi 

@AJ Enrique Arguello (9/23/24)

* Objective: Students will simulate the Tower of Hanoi Puzzle with 3 "blocks" (characters - A, B & C) and 3 character Vectors T1, T2 & T3

Students MUST use the character Vector container for this assignment.

Create 3 character Vectors T1, T2 and T3 . Fill T1 with the characters A, B & C (leaving the other 2 empty).  

T1   A B C

T2 

T3

  Prompt the user to enter a source Tower and a destination Tower.

  Move the last character from source vector to dest vector

      Ex) if the user entered 1 and then 2 the display should show

             T1   A B

             T2   C

             T3

        Ex) entering 1-3 would then move the B character to the T3

               T1   A

               T2   C

               T3   B

  Continue prompting the user until the A B C characters are moved to Tower 3 in the order A B C

 

The only rule is that letters can NEVER be out of alphabetical order. 

  A B is allowed but not B A.

  A C is allowed but not C A

  B C but not C B

*/

#include <iostream>
#include<vector>
#include <sstream>

using namespace std;

// prototypes vvv

void Board(); 
void tower(int &start, int &end, vector<char> &T1, vector<char> &T2, vector<char> &T3);// prototype for tower function 
vector<char> T1{}; // tower 1 vector
vector<char> T2{}; // tower 2 vector
vector<char> T3{}; // tower 3 vector

int main() {
  bool pzlComlete = false; // bool puzzle complete variable set false 
  char a = 'A', b = 'B', c = 'C'; // characters a b c 
  int source, dest; // int variables source and destination 

  T1.push_back(a); // pushes a into T1 vector 
  T1.push_back(b); // pushes b into T1 vector 
  T1.push_back(c); // pushes c into T1 vector 

  while (pzlComlete == false) {// while the puzzle complete variable is false
    Board();// displays current board 
    cout << "Enter your source:\n";
    cin >> source;// assigns userinput to source variable
    cout << "\nEnter your destination:\n";
    cin >> dest;// assings userinput to destination variable
    tower(source, dest, T1, T2, T3);// calls tower functon 


  if (T3.size() == 3 && T3[0] == 'A' && T3[1] == 'B' && T3[2] == 'C') {// checks if the T3 vector is full in length and is full in the order "A B C D"
        pzlComlete = true;// if true, puzzle variable is set to true
      }
  }
  cout << "\nCongrats you completed the puzzle!\n";
  Board();

  return 0;
} // end of program 


void Board() {
  cout << "\tT1 "; // List all the Tiles on Tower 1
  for (char y : T1)
    cout << "\t" << y;
    cout << "\n\n";
    cout << "\tT2 "; // List all the Tiles on Tower 2
  for (char y : T2)
    cout << "\t" << y;
    cout << "\n\n";
    cout << "\tT3 "; // Lst all the Tiles on Tower 3
  for (char y : T3)
    cout << "\t" << y;
    cout << "\n\n";
}

  void tower(int &start, int &end, vector<char> &T1, vector<char> &T2, vector<char> &T3) {
    vector<char> *source = nullptr, *destination = nullptr; // vectors for source and destination is declared 
    
    (start == 1) ? void(source =&T1) : // if the start variable is equal to 1, source is from the T1 vector
      (start == 2) ? void(source = &T2) : // if the start variable is equal to 2, source is from the T2 vector
        (start == 3) ? void(source = &T3) : // if the start variable is equal to 3, source is from the T3 vector 
          void(cout << " ");

    (end == 1) ? void(destination = &T1) : // if the end variable is equal to 1, the destination is from the T1 vector
      (end == 2) ? void(destination = &T2) : // if the end variable is equal to 1, the destination is from the T2 vector 
        (end == 3) ? void(destination = &T3) : // if the end variable is equal to 3, the destination is from the T3 vector 
          void(cout << "");

        if (source && destination && !source->empty()) {// checks if the source vector pointer is not empty as well as the destination, checks if the source vector is not empty 
            char disk = source->back();// retrieves the top character/disk from the source vector 
            if (destination->empty() || disk > destination->back()) {// checks if the destination vector is empty or if the disk from the source vector is smaller than the top disk on the destination vector 
                source->pop_back();// takes the top character of the source vector away
                destination->push_back(disk);// pushes the top character of the source vector into the destination vector 
            } else {
                cout << "Invalid input\n";
            }
        } else {
            cout << "Invalid input\n";
        }
}
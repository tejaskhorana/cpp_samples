#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void waitNSeconds(unsigned int numSeconds) {
  int startTime = clock();
  int numMicros = numSeconds * 1000000;
  while(clock() <= startTime + numMicros);
  return;
}

bool playGame() {
  cout << "Number Guessing Game" << endl;
  cout << "Pick a Number between 1 and 10" << endl;

  int userNumber;
  cin >> userNumber;

  cout << "Computer is now guessing a number..." << endl;

  int computerNumber = (rand() % 10) + 1;

  waitNSeconds(2);

  cout << "Computer guesses: " << computerNumber << endl;

  if(computerNumber==userNumber) {
    cout << "SUCCESS!" << endl;
  } else {
    cout << "FAILURE!" << endl;
  }

  waitNSeconds(2);

  cout << "Play again?" << endl;

  string userResponse;
  cin >> userResponse;

  if(userResponse == "y") {
    return true;
  }
  return false;
}

int main() {
  bool playAgain = true;
  while(playAgain) {
    playAgain = playGame();
  }
}

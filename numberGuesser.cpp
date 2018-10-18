#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

string yesOptions [5] = {"y", "yes", "yep", "okay", "ok"};
string noOptions [9] = {"n", "no", "nope", "never", "escape", "quit", "esc", "leave", "exit"};

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

  waitNSeconds(1);

  cout << "Computer guesses: " << computerNumber << endl;

  if(computerNumber==userNumber) {
    cout << "SUCCESS!" << endl;
  } else {
    cout << "FAILURE!" << endl;
  }

  waitNSeconds(1);

  bool promptUserResponse = true;

  while(promptUserResponse) {
    cout << "Play again?" << endl;

    string userResponse;
    cin >> userResponse;

    transform(userResponse.begin(), userResponse.end(), userResponse.begin(), ::tolower);

    if(find(begin(yesOptions), end(yesOptions), userResponse) != end(yesOptions)) {
      return true;
    } else if (find(begin(noOptions), end(noOptions), userResponse) != end(noOptions)) {
      return false;
    }
  }
}

int main() {
  bool playAgain = true;
  while(playAgain) {
    playAgain = playGame();
  }
}

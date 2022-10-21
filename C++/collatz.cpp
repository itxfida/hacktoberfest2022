// collatz conjecture implementaion in C++

#include <iostream>
#include <ctime>

using namespace std;

bool isValid(int num) {
  if(num <= 0) {
    return false;
  } else {
    return true;
  }
}

bool isEven(int num) {
  if (num % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

void calculate(int num) {
  if (num == 1) {
    cout << endl << "Finished!" << endl;
    return;
  } else if(isEven(num)) {
    num = num / 2;
    cout << num << " ";
    calculate(num);
  } else {
    num = (num * 3) + 1;
    cout << num << " ";
    calculate(num);
  }
}

int main() {

  int input;
  cout << "Please enter an integer greater than zero." << endl;
  cin >> input;

  if(isValid(input)) {
    calculate(input);
  } else {
    cout << "Not a valid input." << endl;
    return 0;
  }

  return 0;
}
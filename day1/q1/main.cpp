#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  ifstream input("./input.txt");
  if (!input.is_open()) {
    cout << "Could not open file!" << endl;
    return -1;
  }

  string line;
  int total = 0;
  while (getline(input, line)) {
    int first = -1;
    int last = -1;

    for (auto it = line.begin(); it != line.end(); ++it) {
      if (isdigit(*it)) {
        if (first == -1) {
          first = *it - '0';
          last = first;
        } else {
          last = *it - '0';
        }
      }
    }

    int sum = first * 10 + last;
    total += sum;
  }

  cout << "answer: " << total << endl;
  return 0;
}



// Write your Student class here
class Student {

private:
  int scores[5];

public:
  void input() {
    for (int i; i < 5; i++) {
      cin >> scores[i];
    }
  }

  int calculateTotalScore() {
    int total = 0;
    for (int i; i < 5; i++) {
      total += scores[i];
    }
    return total;
  }
};



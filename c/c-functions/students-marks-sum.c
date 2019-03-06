

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int i = (gender == 'b' ? 0 : 1), sum = 0;
  for (; i < number_of_students; i += 2) {
    sum += marks[i];
  }
  return sum;
}



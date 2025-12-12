#include <iomanip>
#include <iostream>
#include <string>

// ============================================================================
// PART 5 OVERVIEW
// ============================================================================
// This part will cover several data structures and related topics.
// SECTION 1 starts with built-in arrays. More sections will be added below
// (keep this format for future topics).
//
// ARRAYS QUICK NOTES
// - Contiguous memory storing elements of the same type
// - Indexing starts at 0
// - Size is fixed at compile time for built-in arrays
// - Great for fast iteration when size is known

// Helper: simple printer for string arrays
void printCars(std::string cars[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "[" << i << "] " << cars[i] << "\n";
  }
  std::cout << "\n";
}

// ============================================================================
// SECTION 1: ARRAYS
// ============================================================================
// Declaring, initializing, accessing, and modifying built-in arrays.

void carArrayDemo() {
  // Declare and initialize (size deduced from elements)
  std::string cars[]{"Corvette", "Mustang", "Dodge"};

  printCars(cars, 3);

  // Accessing and modifying elements
  std::cout << "Original first car: " << cars[0] << "\n";
  cars[0] = "Camaro"; // modify in place
  std::cout << "Updated first car : " << cars[0] << "\n\n";

  // Declaring a fixed-size array, then filling it
  std::string garage[3];
  garage[0] = "Camaro";
  garage[1] = "Mustang";
  garage[2] = "Charger";

  printCars(garage, 3);
}

void priceArrayDemo() {
  // Numeric array with inline initialization
  double prices[]{5.00, 7.50, 9.99, 15.00};

  std::cout << "Preset prices:\n";
  for (std::size_t i = 0; i < 4; ++i) {
    std::cout << "  prices[" << i << "] = $" << std::fixed
              << std::setprecision(2) << prices[i] << "\n";
  }
  std::cout << "\n";

  // Filling after declaration
  double updatedPrices[4];
  updatedPrices[0] = 5.00;
  updatedPrices[1] = 7.50;
  updatedPrices[2] = 9.99;
  updatedPrices[3] = 15.00;

  std::cout << "Updated prices:\n";
  for (std::size_t i = 0; i < 4; ++i) {
    std::cout << "  updatedPrices[" << i << "] = $" << std::fixed
              << std::setprecision(2) << updatedPrices[i] << "\n";
  }
  std::cout << "\n";
}

// ============================================================================
// SECTION 2: sizeof() BASICS
// ============================================================================
// sizeof() determines the size in bytes of a variable, data type, class,
// objects, etc. Helpful for understanding memory usage and counting elements.

// sizeof() = dtermines the size in bytes of a
//            variable, data type, class, objects, etc.

void sizeofDemo() {
  double gpa = 2.5;

  std::cout << sizeof(gpa) << " bytes\n";
  // will give 8 bytes

  std::string name = "XXX";
  std::cout << sizeof(name) << " bytes\n";
  // will give 24 bytes
  // this value is not going to change even we change XXX to something longer.
  // because : string is a referance datatype

  char grade = 'F';
  std::cout << sizeof(grade) << " bytes\n";
  bool student = true;
  std::cout << sizeof(student) << " bytes\n";
  // both will give 1 byte as output

  // now lets see arrays:
  char grades[] = {'A', 'B', 'C', 'D', 'F'};
  std::cout << sizeof(grades) << " bytes\n";
  // will give 5 bytes because we used char 5 times.

  // bytes is not will give element number everytime.
  // here is a quick trick:
  std::cout << sizeof(grades) / sizeof(char) << " elements\n";
  // we divided grades with out data type "char".
  // this equation will give number of elements.
  // How? = 5 bytes of data -> every char = 1 byte -> we have 5 char elements

  // another example
  std::string workers[] = {"Spongebob", "Patric", "Squidward"};
  std::cout << sizeof(workers) << " bytes\n";
  std::cout << sizeof(workers) / sizeof(std::string) << " elements\n";
  // you will get 72 bytes - 3 elements with this one
}

// ============================================================================
// SECTION 3: ITERATING OVER ARRAYS
// ============================================================================

// iterate over an array:
void iterationDemo() {
  std::string workers[] = {"Spongebob", "Patric", "Squidward", "Mr.Crab"};

  for (int i = 0; i < 3; i++) {
    std::cout << workers[i] << '\n';
  }
  // this for loop will stop when we reach 3.
  // So, if we add something in our array, output won't change.
  // for better version of this:
  for (int i = 0; i < sizeof(workers) / sizeof(std::string); i++) {
    std::cout << workers[i] << '\n';
  }
  // as you can see, code knows how much elements we have and acts according to
  // that.
}

// ============================================================================
// SECTION 4: FOR-EACH LOOPS
// ============================================================================

// foreach loop = loop that eases the traversal over an iterable data set.

void foreachDemo() {
  std::string workers[] = {"Spongebob", "Patric", "Squidward", "Mr.Crab"};

  for (int i = 0; i < sizeof(workers) / sizeof(std::string); i++) {
    std::cout << workers[i] << '\n';
  }
  // when you use foreach loop, you don't need to know how many elements you
  // have. foreach loop will go through all elements. it's more readable and
  // more flexible.

  for (std::string worker : workers) {
    std::cout << worker << '\n';
  }
  // you can add or remove elements and foreach loop will still work.

  // another example with "grades"
  char grades[] = {'A', 'B', 'C', 'D', 'F'};
  for (char grade : grades) {
    std::cout << grade << '\n';
  }
}

// ============================================================================
// SECTION 5: PASSING ARRAYS TO FUNCTIONS
// ============================================================================

// Definition for getTotal, which sums the elements of a double array.
// This function must be defined or declared before it is called.
double getTotal(double prices[], int size) {
  double total = 0;
  for (int i = 0; i < size; i++) {
    total += prices[i];
  }
  return total;
}

// Let's see how to pass an array to a function.
int passArrayDemo() {
  double prices[] = {49.99, 15.05, 75, 9.99};
  int size = sizeof(prices) /
             sizeof(prices[0]); // We need to pass size of array to function
  double total = getTotal(prices, size);
  std::cout << "Total: " << total << "$\n";
  return 0;
}

// ============================================================================
// SECTION 6: SEARCHING ARRAYS
// ============================================================================

// Prototype for searching an integer array
int searchArray(int array[], int size, int element);

void searchElementDemo() {

  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  int index;
  int searchedNum;

  std::cout << "Enter a number to search for: ";
  std::cin >> searchedNum;

  // Search directly (without function)
  for (int i = 0; i < size; i++) {
    if (numbers[i] == searchedNum) {
      index = i;
      break;
    } else {
      index = -1;
    }
  }
  searchArray(numbers, size, searchedNum); // For function call logic see below

  if (index == -1) {
    std::cout << "Number not found\n";
  } else {
    std::cout << "Number found at index " << index << "\n";
  }
}

// Function definition
int searchArray(int array[], int size, int element) {
  for (int i = 0; i < size; i++) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1;
}

// Prototype for searching a string array
int searchWord(std::string array[], int size, std::string element);

void wordsDemo() {
  std::string words[] = {"apple", "banana", "orange", "grape"};
  int size = sizeof(words) / sizeof(words[0]);
  int index;
  std::string searchedWord;

  std::cout << "Enter a word to search for: ";
  std::cin >> searchedWord;

  // Search directly
  for (int i = 0; i < size; i++) {
    if (words[i] == searchedWord) {
      index = i;
      break;
    } else {
      index = -1;
    }
  }
  searchWord(words, size, searchedWord); // For function call logic see below

  if (index == -1) {
    std::cout << "Word not found\n";
  } else {
    std::cout << "Word found at index " << index << "\n";
  }
}

// Function definition
int searchWord(std::string array[], int size, std::string element) {
  for (int i = 0; i < size; i++) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1;
}

// Note: You need to input the exact word to find it.

// ============================================================================
// SECTION 7: SORTING ARRAYS
// ============================================================================

// Sorting function prototype
void sortArray(int array[], int size);

void sortDemo() {
  int numbers[] = {10, 2, 1, 3, 4, 6, 7, 5, 9, 11, 8};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  sortArray(numbers, size);
  for (int element : numbers) {
    std::cout << element << " ";
  }
}

// Implementation: Bubble Sort Algorithm
void sortArray(int array[], int size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// EXPLANATION: BUBBLE SORT
// We iterate through the array and compare each element with the next one.
// If the current element is greater than the next one, we swap them using a
// temporary place (variable). We repeat this process for all elements until
// the array is sorted.
//
// This is not the best algorithm for sorting (O(n^2)), but it is the simplest.
// Other algorithms like Quicksort, Mergesort, and Heapsort are more efficient
// but more complex and may require more memory.

// ============================================================================
// SECTION 8: THE FILL() FUNCTION
// ============================================================================
// fill() fills a range of elements with a specified value.
// Syntax: fill(begin, end, value);

void fillDemo() {

  std::string workers[] = {"Spongebob", "Patric", "Squidward", "Mr.Crab"};
  fill(workers, workers + 4, "Spongebob");
  // Fills all elements with "Spongebob".

  // Filling an empty array:
  std::string foods[50];
  fill(foods, foods + 50, "Pizza");
  // Fills all 50 elements with "Pizza".

  // Using a variable for size:
  const int size = 100;
  std::string colors[size];
  fill(colors, colors + size, "Red");
  // Fills all 100 elements with "Red".

  // Filling parts of an array with different values:
  std::string cars[size];
  fill(cars, cars + (size / 2), "Toyota");
  fill(cars + (size / 2), cars + size, "Honda");
  // Fills the first half with "Toyota" and the second half with "Honda".

  // Note: Be careful with integer division for size (e.g., 100 / 3).
}

// Filling an array with user input
void fillWithUserInputDemo() {

  std::string names[5];
  int size = sizeof(names) / sizeof(names[0]);
  std::string temp;

  for (int i = 0; i < size; i++) {
    std::cout << "Enter name or type 'q' to quit (" << i + 1 << "): ";
    std::getline(std::cin, temp);

    // Check for quit condition
    if (temp == "q") {
      break;
    } else {
      names[i] = temp;
    }
  }

  std::cout << "Here is your name list!\n";
  for (int i = 0; !names[i].empty(); i++) {
    std::cout << names[i] << "\n";
  }
}
// Note: This method does not resize the array dynamically.
// Arrays have a fixed size. For dynamic resizing, we would use std::vector.

// ============================================================================
// SECTION 9: MULTIDIMENSIONAL ARRAYS
// ============================================================================
// Multidimensional arrays can be thought of as "arrays of arrays".
// Determine elements by [row][column].

void multiArrayDemo() {

  std::string workers[2][2] = {{"Spongebob", "Patric"},
                               {"Squidward", "Mr.Crab"}};
  // Creates a 2x2 array (2 rows, 2 columns).

  // Accessing elements:
  std::cout << workers[0][0] << "\n"; // Spongebob
  std::cout << workers[0][1] << "\n"; // Patric
  std::cout << workers[1][0] << "\n"; // Squidward
  std::cout << workers[1][1] << "\n"; // Mr.Crab

  // Example: Filling a 2D array with user input (diagonal fill logic):
  std::string cars[2][2];
  int size = sizeof(cars) / sizeof(cars[0]); // Number of rows
  std::string temp;

  for (int i = 0; i < size; i++) {
    std::cout << "Enter car name or type 'q' to quit (" << i + 1 << "): ";
    std::getline(std::cin, temp);
    if (temp == "q") {
      break;
    } else {
      // NOTE: This logic assigns to [i][i] (diagonal elements)
      cars[i][i] = temp;
    }
  }

  std::cout << "Here is your car list!\n";
  for (int i = 0; !cars[i][i].empty(); i++) {
    std::cout << cars[i][i] << "\n";
  }
}

// ============================================================================
// SECTION 10: PROJECT - QUIZ GAME
// ============================================================================

void quizProject() {
  std::string questions[]{"1. What is the capital of France?",
                          "2. What is the largest planet in the solar system?",
                          "3. What is the chemical symbol for gold?",
                          "4. What is the largest mammal on Earth?",
                          "5. What is the smallest country in the world?"};

  std::string options[][4]{
      {"A. Paris", "B. Berlin", "C. Madrid", "D. Rome"},
      {"A. Jupiter", "B. Saturn", "C. Mars", "D. Venus"},
      {"A. Au", "B. Ag", "C. Cu", "D. Pb"},
      {"A. Elephant", "B. Giraffe", "C. Hippopotamus", "D. Rhinoceros"},
      {"A. Vatican City", "B. Monaco", "C. San Marino", "D. Liechtenstein"}};

  std::string answers[] = {"A", "A", "A", "A", "A"};

  int score = 0;
  for (int i = 0; i < 5; i++) {
    std::cout << questions[i] << "\n";
    for (int j = 0; j < 4; j++) {
      std::cout << options[i][j] << "\n";
    }
    std::string answer;
    std::cout << "Enter your answer: ";
    std::cin >> answer;

    // Normalize input to uppercase
    answer = toupper(answer[0]);

    if (answer == answers[i]) {
      score++;
    }
  }
  std::cout << "Your score is: " << score << "\n";
}

int main() {
  quizProject();
  return 0;
}

#include <iostream>
#include <cstdlib> // for rand, srand
#include <ctime>   // for time

// ============================================================================
// SECTION 1: STRING METHODS - Working with Text in C++
// ============================================================================
// Strings in C++ have many built-in methods (functions) that make working with
// text easier. These methods help you check, modify, and manipulate strings.
//
// This section covers some of the most commonly used string methods.

// Example 1: Basic string input and validation
/*
int main() {
  std::string name;
  std::cout << "Enter your name: ";
  std::getline(std::cin, name); // You can remember this from first part.
                                 // 'getline' allows us to use spaces in inputs

  if (name.length() > 12) {
    std::cout << "Your name can't be over 12 characters\n";
  }
  else if (name.empty()) {
    std::cout << "Your name can't be empty\n";
  }
  else {
    std::cout << "Welcome " << name << std::endl;
  }

  return 0;
}
*/

// Example 2: String manipulation methods
/*
int main() {
  std::string name;
  std::cout << "Enter your name: ";
  std::getline(std::cin, name);

  // name.clear();              // This will clear the string
  // name.append("@gmail.com"); // This will add "@gmail.com" to the string
  // std::cout << name.at(0);   // This will print the first character
                                 // (because of 0 index) of the string

  // name.insert(0, "@");       // This will insert "@" at the beginning
                                 // of the string

  // std::cout << name.find(" "); // This will print the index of the first
                                   // space in the string (if there is no space,
                                   // it will print -1)

  // name.erase(0, 3);          // This will erase the first 3 characters
                                 // of the string

  // name.erase(0, name.find(" ")); // This will erase the first space and
                                     // everything before it

  return 0;
}
*/

// ============================================================================
// SECTION 2: WHILE LOOPS - Repeating Code Based on Conditions
// ============================================================================
// 'while' loops repeat code as long as a condition is true.
// Unlike 'if' statements, they keep checking and repeating until the condition
// becomes false.
//
// This section demonstrates how to use 'while' loops for input validation and
// repetition.

// Example 1: Using 'while' for input validation
/*
int main(){
  std::string name;
  //before 'while' we only had if statement
  //but you cant use 'if' for things like this
  while (name.empty()) {
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
  }
  //this code asks for name until user enters a input

  // you can create infinite loops with 'while' statement
  while(1==1){
    std::cout << "This is an infinite loop!\n"; // This will run forever until
manually stopped
  }
  return 0;
}
*/

// ============================================================================
// SECTION 3: DO-WHILE LOOPS - Execute First, Check Condition Later
// ============================================================================
// 'do-while' loops are similar to 'while' loops, but they execute the code
// block at least once before checking the condition.
//
// This is useful when you want to ensure code runs at least one time.

// Example: Comparing 'while' vs 'do-while' for input validation
/*
int main() {
  // First, let's see the 'while' approach:
  int number;
  std::cout << "Enter a positive #: ";
  std::cin >> number;
  while(number < 0) {
    std::cout << "Enter a positive #: ";
    std::cin >> number;
  }
  // Notice: We have to ask for input twice (once before the loop, once inside)

  // Now, let's see the cleaner 'do-while' approach:
  int number;
  do {
    std::cout << "Enter a positive #: ";
    std::cin >> number;
  } while(number < 0);
  // Much cleaner! The code runs at least once, then repeats if needed.

  std::cout << "The # is: " << number;

  return 0;
}
*/

// ============================================================================
// SECTION 4: FOR LOOPS - Counting and Iterating
// ============================================================================
// 'for' loops are a compact way to repeat code a specific number of times.
// It has three parts: initialization, condition, and increment/decrement.
/*
int main() {
  // Example 1: Counting from 1 to 10
  // Structure: for(initialization; condition; increment)
  for(int i = 1; i <= 10; i++) {
    std::cout << i << '\n';
  }
  // i++ increments i by 1 each iteration (i = i + 1)
  // This loop runs while i <= 10, so it prints 1, 2, 3, ..., 10

  // Example 2: Counting by 2s
  // You can change the increment to count by different amounts
  for(int i = 1; i <= 10; i += 2) {
    std::cout << i << '\n';
  }
  // i += 2 means i = i + 2, so this prints: 1, 3, 5, 7, 9

  // Example 3: Counting backwards
  // You can count down by using i-- (decrement)
  for(int i = 10; i >= 0; i--) {
    std::cout << i << '\n';
  }
  // This prints: 10, 9, 8, 7, ..., 0

  std::cout << "HAPPY NEW YEAR!\n";

  return 0;
}
*/

// ============================================================================
// SECTION 5: LOOP CONTROL - Break and Continue
// ============================================================================
// After learning about loops, let's see how we can control them
/*
int main(){
  // break = break out of a loop
  // continue = skip current iteration

  for(int i=1 ; i <=20 ; i++){
    if(i==13){
      break; //you will see there is no 13.
      //when you replaced break with continue, it will go to 20. But still there
is no 13.
    }
    std::cout << i << '\n';
  }

  return 0;
}*/

// ============================================================================
// SECTION 6: NESTED LOOPS - Loops Inside Loops
// ============================================================================
// Nested loops are loops that run inside other loops.
// They are useful for working with 2D structures like rows and columns.
/*
int main() {

  // Basic nested loop structure:
  //
  // for ( outer loop ) {
  //   for ( inner loop ) {
  //     // repeated code
  //   }
  // }

  // Example: printing 1–10 three times (3 rows)
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 10; j++) {
      // 'i' and 'j' are different variables, so the loops don't interfere
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }
  // This prints numbers 1–10 on each of 3 separate lines.

  // Now let's create a grid (matrix) of symbols using nested loops.
  int columns;
  int rows;

  std::cout << "How many rows? ";
  std::cin >> rows;

  std::cout << "How many columns? ";
  std::cin >> columns;

  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= columns; j++) {
      std::cout << "*";  // this will print a row of stars
    }
    std::cout << '\n';
  }

  // And there is your basic matrix!
  // You can also let the user choose the symbol to use:

  char symbol;
  std::cout << "Enter a symbol: ";
  std::cin >> symbol;

  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= columns; j++) {
      std::cout << symbol;
    }
    std::cout << '\n';
  }

  return 0;
}
*/

// ============================================================================
// SECTION 7: RANDOM NUMBERS - Pseudo-Random Values with rand()
// ============================================================================
// Pseudo-random numbers are not truly random, but are good enough for games
// and simple programs. We use srand(time(NULL)) to "seed" the random generator.
/*
int main() {
  // Seed the random number generator using the current time
  srand(time(NULL));

  // int num = rand();
  //   -> random number between 0 and RAND_MAX (a very large number)

  // int num = rand() % 6 + 1;
  //   -> random number between 1 and 6 (like rolling a die)
  //      we add +1, otherwise rand() % 6 would give 0–5

  // int num = (rand() % 100) + 1;
  //   -> random number between 1 and 100 (not 0–99)

  // Let's roll a die three times (simple example without loops):
  int num1 = rand() % 6 + 1;
  int num2 = rand() % 6 + 1;
  int num3 = rand() % 6 + 1;

  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  // You can find more advanced examples in the projects folder.
  return 0;
}
*/

// ============================================================================
// SECTION 8: RANDOM EVENT GENERATOR - Using switch with Random Numbers
// ============================================================================
/*
int main() {
  srand(time(0));

  // Generate a random number between 1 and 5
  int randNum = rand() % 5 + 1;

  switch (randNum) {
    case 1: std::cout << "You win an arc coin!\n";   break;
    case 2: std::cout << "You win a treasure!\n";    break;
    case 3: std::cout << "You win a potion!\n";      break;
    case 4: std::cout << "You win a sword!\n";       break;
    case 5: std::cout << "You win a shield!\n";      break;
  }
  // This code chooses a number from 1–5 and prints the matching reward.

  return 0;
}
*/

// ============================================================================
// SECTION 9: NUMBER GUESSING GAME - Putting It All Together
// ============================================================================
// This active program uses random numbers, loops, and input to create
// an interactive number guessing game.
int main() {
  int num;
  int guess;
  int tries;

  // Seed the random number generator
  srand(time(NULL));

  // Secret number between 1 and 100
  num = (rand() % 100) + 1;
  tries = 0;

  std::cout << "****** NUMBER GUESSING GAME ******\n";

  do {
    std::cout << "Enter your guess (1–100): ";
    std::cin >> guess;

    // Each guess increases the try count
    tries++;

    // Give the player a hint
    if (guess > num) {
      std::cout << "Take a smaller guess!\n";
    }
    else if (guess < num) {
      std::cout << "Take a bigger guess!\n";
    }
    else {
      std::cout << "YOU GOT IT!!\n";
      std::cout << "# of tries: " << tries << std::endl;
    }
  } while (guess != num);

  std::cout << "*********************************\n";
  return 0;
}

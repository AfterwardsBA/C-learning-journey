#include <ios>
#include <iostream>
#include <iomanip>
#include <ctime>

// ============================================================================
// SECTION 1: USER-DEFINED FUNCTIONS - Reusable Code Blocks
// ============================================================================
// Sometimes you can find yourself in a situation where one specific code is
// being repeated multiple times. In this scenario, functions are our hero.
//
// Functions allow you to write code once and reuse it anywhere in your program.
// This makes your code cleaner, easier to maintain, and reduces repetition.

// Example 1: Basic function definition and usage
/*
void HappyBirthday() {
  // Two important things:
  // 1. Function name must be unique
  // 2. There is no 'return' because we are just defining the function

  std::cout << "Happy Birthday to you!\n";
  std::cout << "Happy Birthday to you!\n";
  std::cout << "Happy Birthday dear you!\n";
  std::cout << "Happy Birthday to you!\n";
}

int main() {
  // function = block of reusable code

  HappyBirthday();
  // You can use it as you want, anywhere you want!

  return 0;
}
*/

// ============================================================================
// SECTION 2: FUNCTIONS WITH PARAMETERS - Passing Data to Functions
// ============================================================================
// Functions can accept parameters (inputs) to make them more flexible and
// useful. Parameters allow you to pass data into a function when you call it.

// Example 1: Function with a string parameter
/*
void HappyBirthday(std::string name) {
  std::cout << "Happy Birthday to " << name << "!\n";
  std::cout << "Happy Birthday to " << name << "!\n";
  std::cout << "Happy Birthday dear " << name << "!\n";
  std::cout << "Happy Birthday to " << name << "!\n";
}

int main() {
  std::string name;
  std::cout << "What is your name? ";
  std::cin >> name;

  HappyBirthday(name);
  // Be sure that 'name' is defined before calling the function.

  return 0;
}
*/

// ============================================================================
// SECTION 3: FUNCTION DECLARATIONS - Forward Declarations
// ============================================================================
// Be sure the definition comes before the using, otherwise the code won't know
// what's going on and you will get an error.
//
// However, there is a better way to do it! You can declare a function first
// (forward declaration) and define it later. This is useful for organizing
// your code.

// Example: Using function declarations (forward declarations)
/*
void HappyBirthday(std::string name); // Function declaration

int main() {
  std::string name;
  std::cout << "What is your name? ";
  std::cin >> name;

  HappyBirthday(name);
  // Be sure that 'name' is defined before calling the function.

  return 0;
}

// Function definition (can come after main)
void HappyBirthday(std::string name) {
  std::cout << "Happy Birthday to " << name << "!\n";
  std::cout << "Happy Birthday to " << name << "!\n";
  std::cout << "Happy Birthday dear " << name << "!\n";
  std::cout << "Happy Birthday to " << name << "!\n";
}
*/

// Note: It's okay if you didn't get why there is 'std::string name' inside
// our definition. We changed the place of our definition, so the function
// needs to know what type of data it will receive.

// ============================================================================
// SECTION 4: RENAMING PARAMETERS - Parameter Names Are Local
// ============================================================================
// An interesting thing is: you can rename parameters. The parameter name in
// the function definition doesn't have to match the variable name you pass
// when calling the function. The code will give the same result.

// Example: Using different parameter names
/*
void HappyBirthday(std::string birthdayKid) {
  // The parameter name 'birthdayKid' is different from what we pass in main,
  // but it works the same way!
  std::cout << "Happy Birthday to " << birthdayKid << "!\n";
  std::cout << "Happy Birthday to " << birthdayKid << "!\n";
  std::cout << "Happy Birthday dear " << birthdayKid << "!\n";
  std::cout << "Happy Birthday to " << birthdayKid << "!\n";
}

int main() {
  std::string name;
  std::cout << "What is your name? ";
  std::cin >> name;

  HappyBirthday(name); // We pass 'name', but the function uses 'birthdayKid'

  return 0;
}
*/

// ============================================================================
// SECTION 5: MULTIPLE PARAMETERS - Functions with Multiple Inputs
// ============================================================================
// Functions can accept multiple parameters. You just need to separate them
// with commas and specify the type for each one.

// Example: Function with multiple parameters
/*
void HappyBirthday(std::string name, int age);

int main() {
  std::string name;
  std::cout << "What is your name? ";
  std::cin >> name;
  int age = 19;

  HappyBirthday(name, age);
  // Pass both parameters when calling the function

  return 0;
}

void HappyBirthday(std::string name, int age) {
  std::cout << "Happy Birthday to " << name << "!\n";
  std::cout << "Happy Birthday to " << name << "!\n";
  std::cout << "Happy Birthday dear " << name << "!\n";
  std::cout << "Happy Birthday to " << name << "!\n";
  std::cout << "You are " << age << " years old now!!\n";
}
*/

// In short terms, if you want to use a function with parameters, make sure
// your code provides the required data when calling the function.

// ============================================================================
// SECTION 6: RETURN STATEMENTS - Functions That Give Back Values
// ============================================================================
// We've used 'return' everywhere in main() but never fully explained it!
//
// return = returns a value back to the spot where you called the encompassing
//          function. When a function has a return type (like int, double, etc.),
//          it must return a value of that type.
//
// Key points about return:
// 1. Functions with a return type (not 'void') MUST return a value
// 2. The returned value replaces the function call in the expression
// 3. Once return is executed, the function exits immediately
// 4. In main(), return 0 typically means "success"

// ============================================================================
// SECTION 7: PRACTICAL EXAMPLE - Calculating Area and Volume
// ============================================================================
// Let's create functions that calculate the area of a square and volume of a
// cube. These functions will demonstrate how return values work in practice.

// Function declarations (forward declarations)
// These tell the compiler that these functions exist and what they expect
/*double square(double length);  // Takes a length, returns the area (length²)
double cube(double length);    // Takes a length, returns the volume (length³)

int main() {
  // Let's create a function that calculates the area of a square to test it.
  // We'll also test a cube volume function.

  double length = 5.0;  // The side length of our square/cube in centimeters

  // Call the functions and store their return values
  // When square(length) is called, it calculates and RETURNS the area
  // That returned value is then stored in the 'area' variable
  double area = square(length);
  
  // Similarly, cube(length) calculates and RETURNS the volume
  // The returned value is stored in the 'volume' variable
  double volume = cube(length);

  // Display the results
  std::cout << "Area: " << area << "cm^2\n";
  std::cout << "Volume: " << volume << "cm^3\n";
  
  return 0;  // Return 0 to indicate successful program execution
}

// Function definition: square
// This function takes a length parameter and returns the area of a square
// Return type: double (because area can be a decimal number)
// Parameter: double length (the side length of the square)
double square(double length) {
  // Calculate area = length × length (or length²)
  // The return statement sends this calculated value back to where the
  // function was called (in main(), it gets stored in the 'area' variable)
  return length * length;
}

// Function definition: cube
// This function takes a length parameter and returns the volume of a cube
// Return type: double (because volume can be a decimal number)
// Parameter: double length (the side length of the cube)
double cube(double length) {
  // Calculate volume = length × length × length (or length³)
  // The return statement sends this calculated value back to where the
  // function was called (in main(), it gets stored in the 'volume' variable)
  return length * length * length;
}*/

// ============================================================================
// SECTION 8: RETURNING STRINGS - Functions That Return Text
// ============================================================================
// Let's make another example for understanding return values better.
// This time, we'll use strings. The program will combine a first name and
// last name, then display the full name. This is easy, but let's make it
// using a function that returns a string value.
//
// This example demonstrates:
// 1. Functions can return strings, not just numbers
// 2. String concatenation using the + operator
// 3. How return values can be used directly in expressions

// Example: Function that concatenates two strings and returns the result
/*
// Function declaration
// This function takes two string parameters and returns a combined string
std::string concatStrings(std::string string1, std::string string2);

int main() {
  // Define two separate strings
  std::string firstName = "XXX";   // Change it with your first name
  std::string lastName = "YYY";    // Change it with your last name

  // Call the function and store the returned value
  // The function returns a string, which gets stored in 'fullName'
  std::string fullName = concatStrings(firstName, lastName);

  // Display the result
  std::cout << "Hello " << fullName << "!\n";

  return 0;
}

// Function definition: concatStrings
// This function combines two strings with a space in between
// Return type: std::string (returns a text value)
// Parameters: two strings to combine
std::string concatStrings(std::string string1, std::string string2) {
  // The + operator concatenates (joins) strings together
  // " " in the middle adds a space between the two strings
  // The return statement sends this combined string back to main()
  return string1 + " " + string2;
}
*/

// ============================================================================
// SECTION 9: OVERLOADED FUNCTIONS - Same Name, Different Behaviors
// ============================================================================
// Sometimes we want to use the same function name multiple times with
// different behaviors according to what is needed. This is called
// "function overloading."
//
// Function overloading allows you to define multiple functions with the same
// name, but with different parameters. The compiler automatically chooses
// which version to call based on the arguments you provide.
//
// Key points about function overloading:
// 1. Functions must have the same name but different parameters
// 2. The number or types of parameters must differ
// 3. The compiler matches the function call to the correct version
// 4. This makes your code more intuitive and easier to use

// Example: Overloaded pizza baking functions
/*
// Function declarations - three versions of bakePizza
// Each version has a different number of parameters
void bakePizza();  // No parameters - makes a normal pizza
void bakePizza(std::string topping1);  // One topping
void bakePizza(std::string topping1, std::string topping2);  // Two toppings

int main() {
  // The compiler automatically chooses which version to call based on
  // the number of arguments provided

  bakePizza("pepperoni");
  // Output: "Here is your pepperoni pizza!"
  // Calls the version with one parameter

  bakePizza("pepperoni", "mozzarella");
  // Output: "Here is your pepperoni on mozzarella pizza!"
  // Calls the version with two parameters

  bakePizza();
  // Output: "Here is your normal pizza!"
  // Calls the version with no parameters

  return 0;
}

// Function definition: bakePizza (no parameters)
// This version makes a plain pizza with no toppings
void bakePizza() {
  std::cout << "Here is your normal pizza!\n";
}

// Function definition: bakePizza (one parameter)
// This version makes a pizza with one topping
void bakePizza(std::string topping1) {
  std::cout << "Here is your " << topping1 << " pizza!\n";
}

// Function definition: bakePizza (two parameters)
// This version makes a pizza with two toppings
void bakePizza(std::string topping1, std::string topping2) {
  std::cout << "Here is your " << topping1 << " on " << topping2 << " pizza!\n";
}
*/

// ============================================================================
// PRACTICAL USE OF OVERLOADED FUNCTIONS
// ============================================================================
// You can use function overloading to make your code act differently based on
// user input style. For example, you might have a function that can handle
// different types of input (numbers, strings, etc.) or different numbers of
// inputs.
//
// You will find more practical examples in my other projects.

// ============================================================================
// SECTION 10: VARIABLE SCOPE - Where Variables Can Be Used
// ============================================================================
// Variable scope determines where in your code a variable can be accessed and
// used. Understanding scope is crucial for writing correct and maintainable code.
//
// There are two main types of variable scope:
// 1. Local Variables = declared inside a function or block {}
//    - Only accessible within the function/block where they're declared
//    - Created when the function/block starts, destroyed when it ends
// 2. Global Variables = declared outside of all functions
//    - Accessible from anywhere in the program
//    - Exist for the entire lifetime of the program

// ============================================================================
// EXAMPLE 1: LOCAL VARIABLES - Variables Inside Functions
// ============================================================================
// We've used local variables for every step we took so far. Local variables
// are the most common and recommended way to store data because they:
// - Keep data isolated to where it's needed
// - Prevent accidental modification from other parts of the code
// - Make code easier to understand and debug

// Example: Using local variables
/*
void printNUM(int localNUM);

int main() {
  // This is a local variable - it only exists within main()
  // It cannot be accessed by other functions directly
  int localNUM = 1;

  // We pass the local variable as a parameter to the function
  printNUM(localNUM);
  
  return 0;
}

void printNUM(int localNUM) {
  // This function receives a copy of the value from main()
  // The parameter 'localNUM' is also a local variable to this function
  std::cout << localNUM << "\n";
}
*/

// ============================================================================
// EXAMPLE 2: GLOBAL VARIABLES - Variables Outside Functions
// ============================================================================
// Global variables are declared outside of all functions, typically at the
// top of the file. They can be accessed from any function without needing
// to be passed as parameters.
//
// Important notes about global variables:
// - They exist for the entire program lifetime
// - Any function can access and modify them
// - We don't need to pass them as parameters
// - However, functions can't see inside other functions' local variables

// Example: Using global variables
/*
// Global variable - declared outside all functions
// This variable is accessible from anywhere in the program
int globalNUM = 2;

void printNUM();

int main() {
  // We can call the function without passing any parameters
  // because it uses the global variable
  printNUM();
  
  return 0;
}

void printNUM() {
  // This function can access the global variable directly
  // No parameters needed!
  std::cout << globalNUM << "\n";
}
*/

// ============================================================================
// EXAMPLE 3: SCOPE RESOLUTION - Local vs Global with Same Name
// ============================================================================
// What happens if we have both local and global variables with the same name?
// This is where scope resolution comes into play.
//
// Rules:
// 1. Local variables "shadow" (hide) global variables with the same name
// 2. Inside a function, the local variable takes priority
// 3. To access the global variable when a local one exists, use the scope
//    resolution operator "::" (two colons)

// Example: Local and global variables with the same name
/*
// Global variable
int NUM = 3;

void printNUM();

int main() {
  // Local variable with the same name as the global one
  // This local variable "shadows" the global NUM inside main()
  int NUM = 1;

  printNUM();
  
  // Using "::" (scope resolution operator) to access the global variable
  // "::NUM" means "get the global NUM, not the local one"
  std::cout << "Global NUM: " << ::NUM << "\n";
  std::cout << "Local NUM: " << NUM << "\n";
  
  return 0;
}

void printNUM() {
  // Local variable in this function
  // This also shadows the global NUM within this function
  int NUM = 2;
  
  // Using "::" to access the global variable
  // Without "::", it would print the local NUM (which is 2)
  std::cout << "Global NUM from function: " << ::NUM << "\n";
  std::cout << "Local NUM from function: " << NUM << "\n";
}
*/

// ============================================================================
// SCOPE RESOLUTION OPERATOR "::" - Accessing Global Variables
// ============================================================================
// The "::" operator (scope resolution operator) tells the compiler to look
// for the global version of a variable, even when a local variable with the
// same name exists.
//
// Without "::", you would get:
// - "2" from printNUM() (the local NUM in that function)
// - "1" from main() (the local NUM in main)
//
// With "::", you access the global variable (which is 3 in the example above).
//
// Best Practice: Avoid using the same name for local and global variables
// to prevent confusion. Use descriptive, unique names instead.

// ============================================================================
// SECTION 11: END PROJECTS - Practical Applications
// ============================================================================
// These are complete projects that demonstrate all the concepts we've learned
// in this tutorial: functions, parameters, return values, and more!

// ============================================================================
// PROJECT 1: BANKING PROGRAM
// ============================================================================
// A simple banking program that allows users to:
// - View their balance
// - Deposit money
// - Withdraw money
// - Exit the program
//
// This project demonstrates:
// - Functions with return values
// - Functions with parameters
// - Switch statements
// - Do-while loops
// - Input validation

// Function declarations
void showBalance(double balance);
double deposit();
double withdraw(double balance);

int BankProject() {
  double balance = 0;
  int choice = 0;
  
  do {
    std::cout << "******************\n";
    std::cout << "Enter your choice:\n";
    std::cout << "******************\n";
    std::cout << "1. Show Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw money\n";
    std::cout << "4. Exit\n";
    std::cin >> choice;

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    switch (choice) {
      case 1: 
        showBalance(balance);
        break;
      case 2: 
        balance += deposit();
        showBalance(balance);
        break;
      case 3: 
        balance -= withdraw(balance);
        showBalance(balance);
        break;
      case 4: 
        std::cout << "Thanks for testing!\n";
        break;
      default: 
        std::cout << "ERROR: Invalid choice.\n";
    }
  } while(choice != 4);

  return 0;
}

void showBalance(double balance) {
  std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << "\n";
}

double deposit() {
  double amount = 0;
  std::cout << "Enter amount: ";
  std::cin >> amount;
  
  if(amount > 0) {
    return amount;
  }
  else {
    std::cout << "ERROR: Amount is not valid!\n";
    return 0;
  }
}

double withdraw(double balance) {
  double amount = 0;
  std::cout << "Enter amount: ";
  std::cin >> amount;

  if(amount > balance) {
    std::cout << "ERROR: Insufficient funds\n";
    return 0;
  }
  else if (amount < 0) {
    std::cout << "ERROR: Amount is not valid\n";
    return 0;
  }
  else {
    return amount;
  }
}

// ============================================================================
// PROJECT 2: ROCK PAPER SCISSORS GAME
// ============================================================================
// A classic Rock-Paper-Scissors game where the player competes against the
// computer. The computer makes random choices, and the program determines
// the winner based on the game rules.
//
// This project demonstrates:
// - Functions returning characters
// - Random number generation
// - Switch statements with multiple cases
// - Input validation with do-while loops
// - Logical operators

// Function declarations
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int RPC() {
  char player;
  char computer;

  player = getUserChoice();
  std::cout << "Your choice: ";
  showChoice(player);

  computer = getComputerChoice();
  std::cout << "Computer's choice: ";
  showChoice(computer);

  chooseWinner(player, computer);

  return 0;
}

char getUserChoice() {
  char player;
  std::cout << "Rock-Paper-Scissors Game!\n";
  do {
    std::cout << "Choose one of the following\n";  
    std::cout << "*************************\n";
    std::cout << "'r' for rock\n";
    std::cout << "'p' for paper\n";
    std::cout << "'s' for scissors\n";
    std::cin >> player;
  } while(player != 'r' && player != 'p' && player != 's');
  
  return player;
}

char getComputerChoice() {
  srand(time(0));
  int num = rand() % 3 + 1;
  switch (num) {
    case 1: return 'r';
    case 2: return 'p';
    case 3: return 's';
  }
  return 'r'; // Default return (should never reach here)
}
void showChoice(char choice) {
  switch (choice) {
    case 'r': 
      std::cout << "Rock\n";
      break;
    case 'p': 
      std::cout << "Paper\n";
      break;
    case 's': 
      std::cout << "Scissors\n";
      break;
  }
}

void chooseWinner(char player, char computer) {
  switch (player) {
    case 'r': 
      if(computer == 'r') {
        std::cout << "It's a tie!\n";
      }
      else if(computer == 'p') {
        std::cout << "Computer Wins!\n";
      }
      else {
        std::cout << "Player wins!\n";
      }
      break;
    case 'p': 
      if(computer == 'p') {
        std::cout << "It's a tie!\n";
      }
      else if(computer == 's') {
        std::cout << "Computer Wins!\n";
      }
      else {
        std::cout << "Player wins!\n";
      }
      break;
    case 's': 
      if(computer == 's') {
        std::cout << "It's a tie!\n";
      }
      else if(computer == 'r') {
        std::cout << "Computer Wins!\n";
      }
      else {
        std::cout << "Player wins!\n";
      }
      break;
  }
}

// ============================================================================
// MAIN FUNCTION - Project Selection Menu
// ============================================================================
// This main function allows the user to choose which project they want to run.
// It demonstrates how to organize multiple programs in a single file.

int main() {
  int projectChoice = 0;
  
  std::cout << "========================================\n";
  std::cout << "   PART 4 - END PROJECTS MENU\n";
  std::cout << "========================================\n";
  std::cout << "Choose a project to run:\n";
  std::cout << "1. Banking Program\n";
  std::cout << "2. Rock Paper Scissors Game\n";
  std::cout << "3. Exit\n";
  std::cout << "Enter your choice: ";
  std::cin >> projectChoice;
  
  switch(projectChoice) {
    case 1:
      std::cout << "\n=== Banking Program ===\n";
      BankProject();
      break;
    case 2:
      std::cout << "\n=== Rock Paper Scissors Game ===\n";
      RPC();
      break;
    case 3:
      std::cout << "Goodbye!\n";
      break;
    default:
      std::cout << "ERROR: Invalid choice.\n";
      break;
  }
  
  return 0;
}

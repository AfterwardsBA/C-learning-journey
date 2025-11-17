#include <iostream>

// ============================================================================
// SECTION 1: VARIABLES - Basic Data Types
// ============================================================================
/* 
Lets make variables

int main() {
   // Basic arithmetic variables
   int x = 5;
   int y = 10;
   int z = x + y;

   // Integer (whole number) examples
   int age = 25;
   int year = 2023;
   int days = 7;

   // Double (decimal number) examples
   double price = 19.99;
   double gpa = 3.7;
   double temperature = 98.6;

   // Single character (you can't write more than one character)
   char grade = 'A';
   char initial = 'B';
   char currency = '$';

   // Boolean (true or false)
   bool student = true;
   bool power = false;
   bool forSale = true;

   // String (objects that represent a sequence of text)
   std::string name = "Bro";
   std::string day = "Friday";
   std::string food = "pizza";
   std::string address = "123 Main St";

   std::cout << "Here is your food: " << food;    

   return 0;
}
*/


// ============================================================================
// SECTION 2: CALCULATIONS - Using Variables in Math Operations
// ============================================================================
/*
int main() {
   double pi = 3.14159;
   double radius = 10.0;
   double circumference = 2 * pi * radius;
   double light_speed = 299792458;
   
   std::cout << "The circumference is: " << circumference << " cm";

   return 0;
}
*/


// ============================================================================
// SECTION 3: CONSTANTS - Immutable Values
// ============================================================================
/*
int main() {
   // You can't change the value of a constant after it is declared
   const double PI = 3.14159;
   // PI = 420.69;  // This will cause an error
   
   const int LIGHT_SPEED = 299792458;
   const int WIDTH = 1920;
   const int HEIGHT = 1080;
   const int AREA = WIDTH * HEIGHT;
   
   std::cout << "The area is: " << AREA << " cm^2";
   
   return 0;
}
*/


// ============================================================================
// SECTION 4: NAMESPACES - Preventing Name Conflicts
// ============================================================================
// Namespace = provides a solution for preventing name conflicts in large projects.
// Each entity needs a unique name.
// A namespace allows for identically named entities as long as the namespaces are different

/*
namespace first {
   int x = 1;
   // int x = 2;  // This will cause an error (duplicate name in same namespace)
}

namespace second {
   int x = 2;
}

int main() {
   int x = 0;  // Local variable
   
   std::cout << first::x;  // Will output: 1 (from first namespace)
   // std::cout << second::x;  // Will output: 2 (from second namespace)
    
   return 0;
}
*/


// ============================================================================
// SECTION 5: USING DECLARATIONS - Simplifying Namespace Access
// ============================================================================
// "using" keyword allows you to bring namespace members into current scope
// This eliminates the need to prefix with std:: every time

/*
int main() {
   // Option 1: Bring entire namespace into scope (use with caution)
   using namespace std;
   
   // Option 2: Bring specific members into scope (preferred method)
   using std::cout;
   using std::string;
   
   std::string name = "Bro";
   std::cout << "Hello " << name;
   
   return 0;
}
*/


// ============================================================================
// SECTION 6: TYPE ALIASES - Creating Type Aliases (typedef vs using)
// ============================================================================
// Type aliases allow you to create an additional name (alias) for another datatype
// New identifier for an existing type helps with readability and reduces typos

/*
#include <vector>

// Method 1: typedef (older C-style, still widely used)
typedef std::vector<std::pair<std::string, int>> pairlist_t;  // Don't try to understand, just see the positive effect

// Method 2: using (modern C++11 style - looks and feels much better!)
using text_t = std::string;
using number_t = int;

int main() {
   pairlist_t pairlist;  // pairlist_t is our long input now, so we don't need to write it again!

   text_t firstName = "Burak";
   number_t age = 19;

   std::cout << firstName << "\n";  // \n creates a newline (use backslash, not forward slash. Don't be like me XD)
   std::cout << age << "\n";
   
   // Alternative ways to create newlines:
   // std::cout << firstName << std::endl;
   // std::cout << firstName << '\n';
   
   return 0;
}
*/


// ============================================================================
// SECTION 7: ARITHMETIC OPERATIONS - Math Operations and Operators
// ============================================================================
// Arithmetic operations = return the result of a specific arithmetic operation (+ - * /)
// Compound assignment operators provide shorthand ways to modify variables

/*
// Example 1: Increment and Decrement Operations
int main() {
   int students = 20;
   
   // Addition - three equivalent ways:
   // students = students + 1;
   // students += 1;
   // students++;
   
   // Subtraction - three equivalent ways:
   // students = students - 1;
   // students -= 1;
   // students--;
   
   // Multiplication - two equivalent ways:
   // students = students * 2;
   // students *= 2;
   
   // Division - two equivalent ways:
   // students = students / 2;
   // students /= 2;
   
   // NOTE: When you try to divide an even number with an odd number (or in reverse)
   // you will get integer for result, because we are using "int"
   // If you decide to use "double", then you can get the full answer
   
   // You can check if the number is even or odd using modulo operator (%)
   // int remainder = students % 2;  // Returns 0 if even, 1 if odd
   // int remainder = students % 3;  // Returns remainder after division by 3
   // std::cout << remainder;

   std::cout << students;
   
   return 0;
}
*/


// Example 2: Operator Precedence and Parentheses
/*
int main() {
   // Parentheses make things work like our math rules (PEMDAS/BODMAS)!
   
   int result1 = 6 - 5 + 4 * 3 / 2;        // Without parentheses
   int result2 = 6 - (5 + 4) * 3 / 2;      // With parentheses
   
   std::cout << "Result 1: " << result1 << "\n";
   std::cout << "Result 2: " << result2 << "\n";
   
   return 0;
}
*/

// ============================================================================
// SECTION 8: TYPE CONVERSION - Implicit and Explicit Type Casting
// ============================================================================
// Type conversion = converting a value from one data type to another
// Two types: "Implicit" (automatic) and "Explicit" (precede value with new data type [int])
// Know these ones!

/*
// Example 1: Explicit Type Conversion (C-style cast)
int main() {
   // int x = 3.14;  // This won't work, you need -> double x = 3.14 BUT!
   double x = (int) 3.14;  // Explicitly cast 3.14 to int, then assign to double
   // It's that simple!
   std::cout << x;  // Output: 3 (decimal part is truncated)
   
   return 0;
}
*/


/*
// Example 2: Character Conversion
int main() {
   char x = 100;  // Implicit conversion: int 100 to char 'd'
   std::cout << x;  // Output: 'd' (ASCII value 100)
   
   // It's too long, right? It's so simple to do actually:
   std::cout << (char) 100;  // Explicit cast: directly output char from int
   
   return 0;
}
*/


/*
// Example 3: Why is it useful? - Integer Division Problem
int main() {
   // Let's say there is an online exam and we want the score that student made:
   
   // WRONG WAY - Integer division problem:
   int correct = 8;
   int questions = 10;
   int score = correct / questions * 100;  // Integer division: 8/10 = 0, then 0*100 = 0
   std::cout << score << "%\n";
   // When you do that, code will give you "0%" as answer.
   // Because, we are trying to divide integers!
   
   // CORRECT WAY - Explicit type conversion:
   int correct2 = 8;
   int questions2 = 10;
   int score2 = correct2 / (double)questions2 * 100;  // Convert to double: 8/10.0 = 0.8, then 0.8*100 = 80
   std::cout << score2 << "%\n";
   // And you will get "80%" with this one!
   
   return 0;
}
*/

// ============================================================================
// SECTION 9: USER INPUT - Getting Input from the User
// ============================================================================
// Finally! Let's make user input!
// cout << (insertion operator) - outputs data
// cin >> (extraction operator) - inputs data

/*
// Example 1: Basic User Input with getline()
int main() {
   std::string name;
   int age;

   std::cout << "What is your name?: ";
   // std::cin >> name;  // It looks good, but you can't type your full name! Let me fix that:
   std::getline(std::cin, name);  // You can add space now!
   
   std::cout << "What is your age?: ";
   std::cin >> age;

   std::cout << "Hello " << name << '\n';
   std::cout << age << " is a great age to learn C++!";
   
   return 0;
}
*/


/*
// Example 2: Fixing the getline() Issue After cin
// OK, let me give you another info, let's say you want to get age first...
// You will see a code error when code runs your "getline" after "cin".
// But we can dodge it with some extra code:

int main() {
   std::string name;
   int age;
  
   std::cout << "What is your age?: ";     
   std::cin >> age;
   
   std::cout << "What is your name?: ";
   std::getline(std::cin >> std::ws, name);  // That's how it looks now!
   // std::ws removes leading whitespace (including the newline left by cin >>)

   std::cout << "Hello " << name << '\n';
   std::cout << age << " is a great age to learn C++!";
   
   return 0;
}
*/

// ============================================================================
// SECTION 10: MATH FUNCTIONS - Useful Math-Related Functions
// ============================================================================
// Let's look for some useful math-related functions!
// Note: For pow(), sqrt(), abs(), round(), ceil(), floor() - include <cmath>
// For std::max() and std::min() - <algorithm> is needed (or use <cmath>)

/*
#include <cmath>
#include <algorithm>

int main() {
   double x = 3.14;
   double y = 4;
   double z;

   // Comparison functions:
   z = std::max(x, y);  // Will give you the bigger one
   z = std::min(x, y);  // Will give you the smaller one
   
   // Power and root functions:
   z = pow(2, 4);       // Basically = 2^4 (2 to the power of 4)
   z = sqrt(9);         // Square root (will give you 3)
   
   // Absolute value:
   z = abs(-3);         // Absolute value (will give you 3)
   
   // Rounding functions:
   z = round(x);        // Rounds to nearest integer (3.14 becomes 3)
   z = ceil(x);         // x is rounded up (3.14 becomes 4)
   z = floor(x);        // x is rounded down (3.14 becomes 3)

   return 0;
}
*/
// Check website for more functions: https://www.cplusplus.com/reference/cmath/


// ============================================================================
// SECTION 11: PRACTICE PROJECTS - Applying What We've Learned
// ============================================================================
// Let's make a practice! I will make a basic: "Hypotenuse calculator practice program!"

/*
// Practice 1: Basic Hypotenuse Calculator (Hardcoded Values)
int main() {
   std::cout << "----Hypotenuse Calculator----" << '\n';
   double a = 6;
   double b = 8;
   double c;
   double needed = (a * a) + (b * b);
   
   c = sqrt(needed);
   
   std::cout << c;
   
   return 0;
}
*/


/*
// Practice 2: Hypotenuse Calculator with User Input
// That was an easy one, and we can make it work with user input too!
// Note: Add #include <cmath> at the top of the file for this to work
int main() {
   std::cout << "----Hypotenuse Calculator----" << '\n';
   double a, b, c;

   std::cout << "Enter side A: ";
   std::cin >> a;
   
   std::cout << "Enter side B: ";
   std::cin >> b;

   double hypo_raw = (a * a) + (b * b);
   c = sqrt(hypo_raw);

   std::cout << "Here is your hypotenuse: " << c;
   
   return 0;
}
*/


// ============================================================================
// PRACTICE 3: Advanced Triangle Calculator (ACTIVE - Currently Running)
// ============================================================================
// If you are seeking for more advanced project, here is the one!
// I did not add "if" in this one but you will be able to find it in the next share!

#include <cmath>

int main() {
   double a, b, c;
   int choice;
   
   std::cout << "=== Triangle Calculator ===\n";
   std::cout << "1. Calculate Hypotenuse\n";
   std::cout << "2. Calculate Area\n";
   std::cout << "Enter your choice (1/2): ";
   std::cin >> choice;
   
   std::cout << "Enter side A: ";
   std::cin >> a;
   
   std::cout << "Enter side B: ";
   std::cin >> b;
   
   // Validate input
   if (a <= 0 || b <= 0) {
      std::cout << "Error: Sides must be positive!\n";
      return 1;
   }
   
   // Process based on user choice
   if (choice == 1) {
      // Calculate hypotenuse using Pythagorean theorem: c = sqrt(a² + b²)
      c = sqrt(pow(a, 2) + pow(b, 2));
      std::cout << "The hypotenuse is: " << c << '\n';
   }
   else if (choice == 2) {
      // Calculate area (for right triangle: Area = (a * b) / 2)
      double area = (a * b) / 2;
      std::cout << "The area is: " << area << '\n';
   }
   else {
      std::cout << "Invalid choice!\n";
      return 1;
   }
   
   return 0;
}

// ============================================================================
// END OF LEARNING NOTES
// ============================================================================
// Don't forget to look for other posts for more advanced topics!
// Keep practicing and building projects to reinforce your learning.
// ============================================================================
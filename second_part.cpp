#include <iomanip>
#include <iostream>

// ============================================================================
// SECTION 1: IF STATEMENTS - Conditional Logic
// ============================================================================
// 'if' statements let you do something only if a condition is true.
// If it's not, the code block is skipped.
//
// This example checks a user's age and grants access if they are 18 or older.

/*
int main() {
  int age;

  std::cout << "Please enter your age: ";
  std::cin >> age;

  if (age >= 100) {
    std::cout << "You are too old to enter." << std::endl;
  }
  else if (age >= 18) {
    std::cout << "Access granted" << std::endl;
  }
  else if (age < 0) {
    std::cout << "Please enter a valid age." << std::endl;
  }
  else {
    std::cout << "Access denied" << std::endl;
  }

  return 0;
}
*/

// ============================================================================
// SECTION 2: SWITCH STATEMENTS - An Alternative to 'if-else'
// ============================================================================
// 'switch' is a clean alternative to using many 'else if' statements.
// It compares one value against several matching cases.
//
// This program gives the name of the month based on the user's input.

// Example 1: Using a long 'if-else if' chain (the hard way)
/*
int main() {
    int month;
    std::cout << "Enter a month (1-12): ";
    std::cin >> month;

    if (month == 1) {
        std::cout << "It's January";
    }
    else if (month == 2) {
        std::cout << "It's February";
    }
    else if (month == 3) {
        std::cout << "It's March";
    }
    else if (month == 4) {
        std::cout << "It's April";
    }
    else if (month == 5) {
        std::cout << "It's May";
    }
    else if (month == 6) {
        std::cout << "It's June";
    }
    else if (month == 7) {
        std::cout << "It's July";
    }
    else if (month == 8) {
        std::cout << "It's August";
    }
    else if (month == 9) {
        std::cout << "It's September";
    }
    else if (month == 10) {
        std::cout << "It's October";
    }
    else if (month == 11) {
        std::cout << "It's November";
    }
    else if (month == 12) {
        std::cout << "It's December";
    }
    else {
        std::cout << "Invalid month";
    }

    return 0;
}
*/

// Example 2: Using a 'switch' statement (the cleaner way)
/*
int main() {
  int month;
  std::cout << "Enter a month (1-12): ";
  std::cin >> month;

  // Firstly, let's make sure the user enters a number.
  if (std::cin.fail()) {
    std::cout << "Please enter a number.\n";
    return 1; // Exit with an error code
  }

  // And here are our lines for the months
  switch (month) {
    case 1:
      std::cout << "It is January";
      break;
    case 2:
      std::cout << "It is February";
      break;
    case 3:
      std::cout << "It is March";
      break;
    case 4:
      std::cout << "It is April";
      break;
    case 5:
      std::cout << "It is May";
      break;
    case 6:
      std::cout << "It is June";
      break;
    case 7:
      std::cout << "It is July";
      break;
    case 8:
      std::cout << "It is August";
      break;
    case 9:
      std::cout << "It is September";
      break;
    case 10:
      std::cout << "It is October";
      break;
    case 11:
      std::cout << "It is November";
      break;
    case 12:
      std::cout << "It is December";
      break;
    default: // This line is our "else" line.
      std::cout << "Invalid month";
      break;
  }

  return 0;
}
*/

// Example 3: Advanced 'switch' with input validation loop
// If you are interested, here is a more complicated, automatic version.
/*
int main() {
    int month;

    while (true) {
        std::cout << "Enter a month (1-12): ";
        std::cin >> month;

        // Check if the input was not a number
        if (std::cin.fail()) {
            std::cin.clear();                // Clear the error flag
            std::cin.ignore(1000, '\n');     // Discard the bad input
            std::cout << "Please enter a NUMBER between 1 and 12.\n";
            continue;                        // Ask again
        }

        switch (month) {
          case 1:
            std::cout << "It is January";
            break;
          case 2:
            std::cout << "It is February";
            break;
          case 3:
            std::cout << "It is March";
            break;
          case 4:
            std::cout << "It is April";
            break;
          case 5:
            std::cout << "It is May";
            break;
          case 6:
            std::cout << "It is June";
            break;
          case 7:
            std::cout << "It is July";
            break;
          case 8:
            std::cout << "It is August";
            break;
          case 9:
            std::cout << "It is September";
            break;
          case 10:
            std::cout << "It is October";
            break;
          case 11:
            std::cout << "It is November";
            break;
          case 12:
            std::cout << "It is December";
            break;
          default:
            std::cout << "Please enter a number between 1 and 12.\n";
            continue; // Invalid range -> ask again
        }

        break; // Valid input was handled, so exit the loop
    }

    return 0;
}
*/

// ============================================================================
// SECTION 3: SWITCH WITH CHARACTERS - Handling Letter Grades
// ============================================================================
// Let's do the same thing with letters. Grades are a good example.
// Notice how cases can "fall through" to share the same code block.

/*
int main() {
  char grade;

  std::cout << "Enter your grade (A-F): ";
  std::cin >> grade;

  switch (grade) {
    case 'A':
    case 'a': // User can enter 'A' or 'a'
      std::cout << "You nailed it";
      break;
    case 'B':
    case 'b': // User can enter 'B' or 'b'
      std::cout << "Great job";
      break;
    case 'C':
    case 'c': // etc.
      std::cout << "You passed";
      break;
    case 'D':
    case 'd':
      std::cout << "You barely passed";
      break;
    case 'E':
    case 'e':
      std::cout << "You did poorly";
      break;
    case 'F':
    case 'f':
      std::cout << "You failed.";
      break;
    default:
      std::cout << "This grade does not exist.";
      break;
  }

  std::cout << std::endl; // Add a newline for cleaner output

  return 0;
}
*/

// lets make a project: simple calculator!!
/*
int main() {
  char op;
  double num1;
  double num2;
  double result;

  std::cout << "*********CALCULATOR*********";
  std::cout << "\n";
  std::cout << "Enter a operation (+, -, *, /): ";
  std::cin >> op;

  std::cout << "Enter number 1: ";
  std::cin >> num1;
  std::cout << "Enter number 2: ";
  std::cin >> num2;

  switch (op) {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = num1 * num2;
    break;
  case '/':
    result = num1 / num2;
    break;
  default:
    std::cout << "Invalid operation";
    return 1;
  }

  std::cout << "Result: " << result;

  std::cout << "****************************";
}*/
// this one is a very simple one, don't expect too much from it
// I will build a better one in the future, so stay tuned.

// ============================================================================
// SECTION 4: TERNARY OPERATOR - A Shortcut for if/else
// ============================================================================
// ternary operator "?:" = replacement to an if/else statement.
// condition ? expression1 : expression2

// Example 1: Checking a grade
/*
int main() {
  int grade = 75;

  // The standard if/else way:
  if (grade >= 60) {
    std::cout << "You passed\n";
  } else {
    std::cout << "You failed\n";
  }

  // The ternary operator way (cleaner!):
  std::cout << (grade >= 60 ? "You passed" : "You failed");

  return 0;
}
*/

// Example 2: Checking for an even or odd number
/*
int main() {
  int number;
  std::cout << "Is my number even or odd?\n";
  std::cout << "Enter your number: ";
  std::cin >> number;

  // Using the ternary operator for a quick check
  std::cout << (number % 2 == 0 ? "Yes, your number is even.\n" : "No, your
number is odd.\n");

  return 0;
}
*/

// Example 3: Checking a boolean value
/*
int main() {
  bool hungry = true;

  // This works, but can be written more compactly:
  // hungry ? std::cout << "You are hungry" : std::cout << "You are full";

  // This is often preferred as it's a single statement:
  std::cout << (hungry ? "You are hungry\n" : "You are full\n");

  return 0;
}
*/

// ============================================================================
// SECTION 5: LOGICAL OPERATORS - Combining Conditions
// ============================================================================
// Logical operators are used to combine multiple conditions.
//  && (AND) = checks if BOTH conditions are true.
//  || (OR)  = checks if AT LEAST ONE condition is true.
//  !  (NOT) = reverses the logical state (true becomes false, and vice versa).

// Example 1: Using the AND (&&) operator
// This checks if the temperature is within a "good" range.
/*
int main() {
  int temp;
  std::cout << "Enter the temperature: ";
  std::cin >> temp;

  if (temp > 0 && temp < 30) {
    std::cout << "The temperature is good!\n";
  } else {
    std::cout << "The temperature is bad!\n";
  }

  return 0;
}
*/

// Example 2: Using the OR (||) operator
// This checks if the temperature is outside the "good" range.
/*
int main() {
  int temp;
  std::cout << "Enter the temperature: ";
  std::cin >> temp;

  if (temp <= 0 || temp >= 30) {
    std::cout << "The temperature is bad!\n";
  } else {
    std::cout << "The temperature is good!\n";
  }

  return 0;
}
*/

// Example 3: Using the NOT (!) operator
// This reverses a boolean value.
/*
int main() {
  bool sunny = true;

  if (!sunny) { // If 'not sunny'
    std::cout << "It is cloudy outside.\n";
  } else {
    std::cout << "It is sunny outside.\n";
  }

  return 0;
}
*/

// lets make the last project of the second part
// Temperature converter!!
int main() {
  double temp;
  char unit;

  std::cout << "***** Welcome to the Temperature Converter! *****" << std::endl;
  std::cout << "Choose conversion:\n";
  std::cout << "1 - Celsius to Fahrenheit\n";
  std::cout << "2 - Fahrenheit to Celsius\n";
  std::cout << "Enter your choice (1/2): ";
  std::cin >> unit;

  if (unit == '1') {
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> temp;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "❌ Invalid input! Please enter a number." << std::endl;
      return 1;
    }

    double fahrenheit = (temp * 9.0 / 5.0) + 32.0;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "🌡️  " << temp << "°C = " << fahrenheit << "°F" << std::endl;

  } else if (unit == '2') {
    std::cout << "Enter temperature in Fahrenheit: ";
    std::cin >> temp;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "❌ Invalid input! Please enter a number." << std::endl;
      return 1;
    }

    double celsius = (temp - 32.0) * 5.0 / 9.0;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "🌡️  " << temp << "°F = " << celsius << "°C" << std::endl;
  } else {
    std::cout << "❌ Invalid choice! Please enter 1 or 2." << std::endl;
    return 1;
  }

  std::cout << "***********************************************" << std::endl;
  return 0;
}

// ============================================================================
// END OF LEARNING NOTES
// ============================================================================
// Don't forget to look for other posts for more advanced topics!
// Keep practicing and building projects to reinforce your learning.
// ============================================================================
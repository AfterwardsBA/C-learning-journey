#include <iostream>

// ============================================================================
// SECTION 1: MEMORY ADDRESSES - Understanding Memory
// ============================================================================
// memory address = a location in memory where data is stored
// a memory address can accessed with & (address of operator)

void memoryAddressDemo() {

  std::string name = "XXX";
  int age = 19;
  bool student = true;

  std::cout << &name << "\n";
  std::cout << &age << "\n";
  std::cout << &student << "\n";

  // we will get hexadecimal outputs that indicates where this codes is working
  // in computer you can use hexadecimal to decimal converters if you
  // interested.

  // you are going to be able to see difference between decimal is exactly
  // equals to memory values what I'm talking about? when you use converter, you
  // will see there is 4 beetween string and integer because integer value is 4
  // bytes / 1 beetween int and bool because bool is 1bytes

  // you can understand why C++ is the fastest language, all this memory stacks
  // up on top each other. One ends and other starts right away!
}

// ============================================================================
// SECTION 2: PASS BY VALUE & REFERENCE - Modifying Variables
// ============================================================================
// pass by Value and pass by Adress
void changeDemo() {
  std::string x = "Oil";
  std::string y = "Water";
  std::string temp;

  temp = x;
  x = y;
  y = temp;

  std::cout << "X: " << x << '\n';
  std::cout << "Y: " << y << '\n';
}
// this is normal way to do it, looks like nonesense
// but I needed to give example like that
// here is a function for doing the job:
void swap(std::string &x, std::string &y) {
  std::string temp;

  temp = x;
  x = y;
  y = temp;
}
void swapDemo() {
  std::string x = "Oil";
  std::string y = "Water";

  swap(x, y);

  std::cout << "X: " << x << '\n';
  std::cout << "Y: " << y << '\n';
}
// the magic is in the '&' we used in the function parameters
// it is called pass by reference, and if you dont use it,
// function cant touch the values and cant make adjustments!

// think about it, you can see picture of something but you cant touch it
// but if you know the place intead of how it looks, you can do anything!

// 1. Pass by Reference (string &x):
// You hold the address. You CAN change the value. (Fast + Dangerous)

// Because it is dangerous, we need to be careful.

// ============================================================================
// SECTION 3: CONST REFERENCES - Secure & Fast
// ============================================================================
// 2. Pass by Const Reference (const string &x):
// You hold the address, BUT the compiler stops you from changing it. (Fast +
// Secure)

// const parameter = parameter that is effectively read-only code is more
// secure and conveys intent. Useful for references and pointers.
void printInfo(const std::string &name, const int &age, const bool &student);
void constParamDemo() {
  std::string name = "XXX";
  int age = 19;
  bool student = true;
  printInfo(name, age, student);
}
void printInfo(const std::string &name, const int &age, const bool &student) {
  // name = "0";
  // age = 0;
  // student = false;
  std::cout << name << '\n';
  std::cout << age << '\n';
  std::cout << student << '\n';

  // because of we added const to parameters, we cant change values
  // when you erase double dash you will get error
}

// 2 different things: even use & or not
// if you use: const protects original values in their homes
// if you dont use: const protects just copies of values

// ============================================================================
// SECTION 4: LUHN ALGORITHM - Credit Card Validator
// ============================================================================
// lets make a project by using our new knowledge

// credit card validator:

// base info for someone who dont know:
// we are using something called Luhn algorithm for this job.
// even your current favorite shopping app is using this algorithm

// Luhn Algorithm:
// 1. Double every second digit from right to left
// 2. If doubled number is 2 digits, split them
// 3. Add all single digits from step 1
// 4. Add all odd numbered digits from right to left
// 5. Su results from step 3 and step 4
// 6. If step 5 is multiple of 10, it is valid.

// and yes, it works with all credit card numbers.
// I will make it piece by piece with functions.
// why? = because it would be irrelevant otherwise!
// enough talk, lets do it ->

int getDigit(const int number) { return number % 10 + (number / 10 % 10); }
int sumOddDigits(const std::string &cardNumber) {
  int sum = 0;

  for (int i = cardNumber.size() - 1; i >= 0; i -= 2) {
    // looks same with Even function,
    // magic is using -1 instead of -2
    sum += cardNumber[i] - '0';
  }

  return sum;
}
// we are using string instead of int for some reason:
// 1. its easier to use
// 2. int is not flexible enough
// 3. int is not secure enough
// 4. int dont have enough space -> most important

// int usually has value between 0 and 4 billion
// we are going to deal with 16 digit numbers -> int is not enough
int sumEvenDigits(const std::string &cardNumber) {
  int sum = 0;

  for (int i = cardNumber.size() - 2; i >= 0; i -= 2) {
    sum += getDigit((cardNumber[i] - '0') * 2);
    // why we did - '0' ?
    // because cardNumber[i] is a char, not an int
    // so we need to convert it to int
    // '0' is 48 in ASCII = kinda language computer talks. Every number has +48
    // value in the other side. 0 = 48 in this story, so we are clearing this
    // problem by doing - '0', so if we do - '0', we get the actual number.
    // so you can use - 48 instead of - '0' but this looks cooler.

    // think this like you are looking a dictionary for computer language,
    // every number we use has +48 value in this language.
    // 0 = 48, 1 = 49, 2 = 50, 3 = 51 ..... 9 = 57
  }

  return sum;
}

void creditCardDemo() {
  std::string cardNumber;
  int result = 0;

  std::cout << "Enter your credit card number: ";
  std::cin >> cardNumber;

  result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

  if (result % 10 == 0) {
    std::cout << "Card number is valid" << '\n';
  } else {
    std::cout << "Card number is invalid" << '\n';
  }
}
// you can try yourself, there is plenty of credit card numbers on the internet
// you can use yourself too, you can send it to me if you want me to test it
// dont forget to send even the 3 digit CVC on the back of your card, for
// science

// ============================================================================
// SECTION 5: POINTERS - Variables That Store Addresses
// ============================================================================
// pointers:
// pointers = variable that stores memory address of another variable
// sometimes its easier to work with memory addresses

// & = address-of operator
// * = dereference operator

// easy to think about, here is the scenario:
// you want to give free pizza to your neighbors
// 1. go all houses one by one with all the pizzas (pass by value)
// 2. give your adress to neighbors so they can come and get it. (with pointers)
// of course, 2 is the best option

// Let me show you the example:

void pointerDemo() {
  std::string name = "XXX";
  std::string *pName = &name;

  std::cout << name << '\n';
  std::cout << *pName << '\n';
  // you will get same output.

  int age = 19;
  int *pAge = &age;

  std::cout << age << '\n';
  std::cout << *pAge << '\n';
  // you will get same output.

  std::string freePizzas[5] = {"Margherita", "Pepperoni", "Hawaiian", "BBQ",
                               "Mushroom"};
  std::string *pFreePizzas = freePizzas;
  // you cant set adress to an array with & because its already an adress.
  std::cout << freePizzas << '\n';  // this gives a memory adress
  std::cout << pFreePizzas << '\n'; // this gives a memory adress too
  std::cout << *pFreePizzas
            << '\n'; // this gives the first element of the array.
}

// ============================================================================
// SECTION 6: NULL POINTERS - Handling Empty Pointers
// ============================================================================
// Null value = a special value that means something has no value.
// When a pointer is holding a null value, that pointer is not pointing at
// anything (null pointer)

// nullptr = keyword rpresents a null pointer literal

// nullptrs are helpful when determining if an adress
// was successfully assigned to a pointer

// yes, giving example is easier for me too. Here it is:

void nullDemo() {
  int *pointer = nullptr;
  int x = 123;
  pointer = &x;

  if (pointer == nullptr) {
    std::cout << "adress was not assigned!\n";
  } else {
    std::cout << "adres was assigned!\n";
  }

  // we are going to get assigned message because we declared a place that our
  // pointer can point to!
  pointer = &x;
}

// ============================================================================
// SECTION 7: TIC-TAC-TOE PROJECT - Final Project
// ============================================================================
// Here is the part6 ending project:
// ****** Tic-Tac-Toe Game! ******

#include <ctime>
// wee need it because we are going to make computer choose a spot randomly

void board(char *spaces) {
  std::cout << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2]
            << "  " << '\n';
  std::cout << "_____|_____|_____" << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5]
            << "  " << '\n';
  std::cout << "_____|_____|_____" << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8]
            << "  " << '\n';
  std::cout << "     |     |     " << '\n';
}
void playerMove(char *spaces, char player) {
  int number;
  do {
    std::cout << "Enter a spot to place a marker (1-9): ";
    std::cin >> number;
    number--;
    if (number >= 0 && number < 9 && spaces[number] == ' ') {
      spaces[number] = player;
      break;
    }
  } while (true);
}
void computerMove(char *spaces, char computer) {
  int number;
  while (true) {
    number = rand() % 9;
    if (spaces[number] == ' ') {
      spaces[number] = computer;
      break;
    }
  }
}
bool checkWinner(char *spaces, char computer, char player) {

  if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
    spaces[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  } 
  else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
    spaces[3] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  } 
  else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
    spaces[6] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  } 
  else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
    spaces[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  } 
  else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
    spaces[1] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  } 
  else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
    spaces[2] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  } 
  else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
    spaces[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  } 
  else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
    spaces[2] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
  }
  else {
    return false;
  }
  return true;
}
bool checkTie(char *spaces) {
  for (int i = 0; i < 9; i++) {
    if (spaces[i] == ' ') {
      return false;
    }
  }
  std::cout << "TIE!\n";
  return true;
}
int main() {
  std::srand(std::time(0));
  std::cout << "--------Tic-Tac-Toe Game!--------\n";
  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player = 'X';
  char computer = 'O';
  // I will make this way in this part, check projects for upgraded version.
  bool running = true;

  board(spaces);

  while (running) {
    playerMove(spaces, player);
    board(spaces);
    if (checkWinner(spaces, computer, player)) {
      running = false;
      break;
    }
    if (checkTie(spaces)) {
      running = false;
      break;
    }

    computerMove(spaces, computer);
    board(spaces);
    if (checkWinner(spaces, computer, player)) {
      running = false;
      break;
    }
    if (checkTie(spaces)) {
      running = false;
      break;
    }
  }

  std::cout << "Thanks for playing!\n";

  return 0;
}
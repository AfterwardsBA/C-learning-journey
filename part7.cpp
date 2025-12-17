#include <iostream>

// ============================================================================
// SECTION 1: DYNAMIC MEMORY - Allocating Memory at Runtime
// ============================================================================
// Dynamic memory = Memory that is allocated after the program is compiled & running.
// Use the 'new' operator to allocate memory in the heap rather than the stack.
// Useful when we don't know how much memory we need. 
// Makes our programs more flexible, especially when we are accepting user input.

void dynamicMemory() {
  int *pNumber = NULL;

  pNumber = new int;
  // rent a place inside heap
  
  *pNumber = 10;
  // fill the place

  std::cout << "Address: " << pNumber << '\n';
  std::cout << "Value: " << *pNumber << '\n';

  delete pNumber;
  // you need to leave the rented place empty
  // because the memory is not yours, new people can't rent otherwise
}

void dynamicArray() {
  char *pGrades = NULL;
  int size = 0;

  std::cout << "How many grades? ";
  std::cin >> size;

  pGrades = new char[size];

  for (int i = 0; i < size; i++) {
    std::cout << "Enter grade #" << i + 1 << ": ";
    std::cin >> pGrades[i];
  }

  for (int i = 0; i < size; i++) {
    std::cout << pGrades[i] << '\n';
  }

  delete[] pGrades;
  // delete[] is used to delete an array
  // adding [] is important
}

// ============================================================================
// SECTION 2: RECURSION - Functions Calling Themselves
// ============================================================================
// Recursion = a programming technique where a function invokes itself from within.
// Break a complex concept into repeatable single steps.

// Iterative vs Recursive
// Advantages: Less code and is cleaner / Useful for sorting and searching
// Disadvantages: More memory usage / Slower

void drive(int meters) {
  for (int i = 0; i < meters; i++) {
    std::cout << "Driving...\n";
  }
}

void NOTrecursiveDemo() {
  drive(10);
}

// So it's going to be like this:
void driven(int meters){ 
  if(meters > 0){
    std::cout << "Driving...\n";
    driven(meters - 1);
  }
}

void recursiveDemo() {
  driven(10);
}
// Does same thing but you need to think if its worth it

// Example: Factorial function
int factorial(int number){
  if(number == 1){
    return 1;
  }
  return number * factorial(number - 1);
  
  // or
  /*
  if (number > 1){
    return number * factorial(number - 1);
  }
  return 1;
  */
  // just reversed version to be clear
}

// Or more likely (Iterative approach):
int factorial2(int number){
  int result = 1;
  for(int i = 1; i <= number; i++){
    result *= i;
  }
  return result;
}

void recursiveFactorialDemo() {
  std::cout << factorial(5) << '\n';
  std::cout << factorial2(5) << '\n';
}

// Note: When I say 'slower', don't expect it to be slower by a lot.
// It is just slower on numbers, you can't see in short codes or small numbers.
// Believe me, when I say "big numbers" I mean SO big numbers.

// ============================================================================
// SECTION 3: FUNCTION TEMPLATES - Generic Functions
// ============================================================================
// Function template = Describes what a function looks like.
// Can be used to generate as many overloaded functions as needed, each using 
// different data types.

int max(int a, int b){
  return (a > b) ? a : b;
}

// Or double if you want to use it with double values
double max(double a, double b){
  return (a > b) ? a : b;
}

// Or char
char max(char a, char b){
  return (a > b) ? a : b;
}

// You see, we have 3 different ones for 3 different data types.
// But we can make it better with function template.
// Here is how:

template <typename T> // first let's declare "T"
T max(T a, T b){
  return (a > b) ? a : b;
}
// And now the code knows what to do!

int showMax(){
  std::cout << max(10, 20) << '\n';
  return 0;
}

// What if we try to use 2 different data types?
// Short answer: It will not work, you will get error "no matching function for call to 'max'"
// There is the solution: Make 2 templates!

template <typename T, typename U>
// You can choose any letter by the way.

// You still get problem with using 'T' at the start:
// For this: auto is used to let compiler decide the type

auto betterMax(T a, U b){
  return (a > b) ? a : b;
}

// And now code knows what to do even with 2 different data types!
int showMax2(){
  std::cout << betterMax(10, 20.5) << '\n';  
  return 0;
}

// ============================================================================
// SECTION 4: STRUCTS - Grouping Related Variables
// ============================================================================
// Struct = A structure that groups related variables under one name.
// Structs can contain many different data types (int, float, char, etc.).
// Variables in a struct are called "members".
// Members can be accessed with "Classname.membername".

struct Player {
  std::string name;
  int health;
  int xp;
};

void structDemo(){
  Player player1;
  player1.name = "XXX";
  player1.health = 100;
  player1.xp = 10;

  Player player2;
  player2.name = "YYY";
  player2.health = 200;
  player2.xp = 20;

  std::cout << player1.name << '\n';
  std::cout << player1.health << '\n';
  std::cout << player1.xp << '\n';

  std::cout << player2.name << '\n';
  std::cout << player2.health << '\n';
  std::cout << player2.xp << '\n';

  // Creating a function is heavily suggested.
}

// Let's make another example with function 
struct Car {
  std::string make;
  std::string model;
  int year;
  std::string color; 
};

void showCar(Car car){
  std::cout << &car << '\n';
  std::cout << car.make << '\n';
  std::cout << car.model << '\n';
  std::cout << car.year << '\n'; 
  std::cout << car.color << '\n';
}

void paintCar(Car &car, std::string color);

void carDemo(){
  Car car1;
  car1.make = "XXX";
  car1.model = "YYY";
  car1.year = 2020;
  car1.color = "ZZZ";

  paintCar(car1, "Blue");
  // add before to change 
  
  std::cout << &car1 << '\n';
  showCar(car1);
  // This makes you able to see where the memory is stored,
  // and you can see that it is different from the one in the function
  // because our struct creates and uses a copy of the object.
  // You can add & (reference) to use the real one instead of copy if you want.
}

// Let's change colors:
void paintCar(Car &car, std::string color){
  car.color = color;
}

// ============================================================================
// SECTION 5: ENUMS - User Defined Data Types
// ============================================================================
// Enums = A user-defined data type that consists of paired named-integer constants.
// GREAT -> If you have a set of potential options.

/*
void withoutEnumDemo(){
 
  std::string todaysWeather = "Sunny";

  switch(todaysWeather){
    case Sunny:
      std::cout << "Go outside!" << '\n';
      break;
    case Rainy:
      std::cout << "Stay inside!" << '\n';
      break;
    default:
      std::cout << "Unknown weather!" << '\n';
      break;
  }
}
*/
// As you can see (if you uncomment the code) this won't work.
// You can't switch strings!
// But, enums are integers!
// So we can do this:

enum Weather {Sunny, Rainy, Cloudy, Snowy};

void enumDemo(){
  Weather today = Sunny;
  // You can take user input as strings now,
  // I'm leaving the rest to your imagination.

  switch(today){
    case Sunny:
      std::cout << "Go outside!" << '\n';
      break;
    case Rainy:
      std::cout << "Stay inside!" << '\n';
      break;
    default:
      std::cout << "Unknown weather!" << '\n';
      break;
  }
  // We are not using "" because enums are integers.
}

// Basically, enums give integers to strings and do the same with arrays.
// So in the scenario you didn't declare the numbers for that strings, 
// it will start from 0 and go up by 1.
// That means you can do as you like, like this:

enum planets {
  Mercury = 4880, 
  Venus = 6052, 
  Earth = 6371, 
  Mars = 3390, 
  Jupiter = 71492, 
  Saturn = 60268, 
  Uranus = 25559, 
  Neptune = 24764
};

// Now code says as 4880 = Mercury, blah blah... You get the point.



// ============================================================================
// SECTION 6: OOP - Object-Oriented Programming
// ============================================================================
// Object = A collection of attributes and methods. 
// They can have characteristics and could perform actions.
// Can be used to mimic real world items. (ex. Phone, Car, Book)
// Created from a class which acts as a "blue-print".

class Human{
  public:
    std::string name;
    int age;
    std::string gender;
    std::string job;

  void eat(){
    std::cout << "This human is eating." << '\n';
  }
  void sleep(){
    std::cout << "This human is sleeping." << '\n';
  }
  void talk(){
    std::cout << "This human is talking." << '\n';
  }

  // Basically, we created a blueprint for a human. We mimic real world things.
};

void showHuman(Human human){
  std::cout << human.name << '\n';
  std::cout << human.age << '\n';
  std::cout << human.gender << '\n';
  std::cout << human.job << '\n';
}

int OOPDemo(){
  Human human1;
  Human human2;

  human1.name = "XXX";
  human1.age = 20;
  human1.gender = "Male";
  human1.job = "Programmer";

  human2.name = "YYY";
  human2.age = 25;
  human2.gender = "Female";
  human2.job = "Doctor";

  showHuman(human1);
  showHuman(human2);

  human1.eat();
  human1.sleep();
  human1.talk();

  return 0;
}

class Cars{
  public:
    std::string make;
    std::string model;
    int year;
    std::string color;

    void accelerate(){
      std::cout << "You step on the gas!" << '\n';
    }
    void brake(){
      std::cout << "You step on the brake!" << '\n';
    }
};

void showCar2(Cars car){
  std::cout << car.make << '\n';
  std::cout << car.model << '\n';
  std::cout << car.year << '\n';
  std::cout << car.color << '\n';
}

int OOPDemo2(){
  Cars car1;
  Cars car2;

  car1.make = "XXX";
  car1.model = "YYY";
  car1.year = 2020;
  car1.color = "ZZZ";

  car2.make = "XXX";
  car2.model = "YYY";
  car2.year = 2020;
  car2.color = "ZZZ";

  showCar2(car1);
  showCar2(car2);

  car1.accelerate();
  car1.brake();

  return 0;
}

// ============================================================================
// SECTION 7: CONSTRUCTORS - Special Object Methods
// ============================================================================
// Constructor = Special method that is automatically called when an object is instantiated.
// Useful for assigning values to attributes as arguments.

class Student{
  public:
    std::string name;
    int age;
    std::string gender;
    std::string major;
    double gpa;

    // Now, think Student is a function.
    Student(std::string name, int age, std::string gender, std::string major, double gpa){
      this->name = name;
      this->age = age;
      this->gender = gender;
      this->major = major;
      this->gpa = gpa;
    }
    // Or you can do this:
    // name = x;
    // age = y;
    // gender = z;
    // ...
    // You need to change all the variable names in the function in this scenario:
    // Student(std::string x, int y, std::string z, std::string a, double b)
};

void showStudent(Student student){
  std::cout << student.name << '\n';
  std::cout << student.age << '\n';
  std::cout << student.gender << '\n';
  std::cout << student.major << '\n';
  std::cout << student.gpa << '\n';
}

void constructorDemo(){
  Student student1("XXX", 20, "Male", "Computer Science", 4.0);
  Student student2("YYY", 25, "Female", "Math", 3.5);
  Student student3("ZZZ", 22, "Male", "Physics", 4.0);

  showStudent(student1);
  showStudent(student2);
  showStudent(student3);

  // Now look how beautiful it is! So clean and much faster to create!
}

// ============================================================================
// SECTION 8: OVERLOADED CONSTRUCTORS - Multiple Ways to Create Objects
// ============================================================================
// Overloaded functions = Multiple constructors with the same name (but different parameters)
// Allows for varying arguments when instantiating an object.

class Pizza{
  public:
    std::string size;
    std::string topping1;
    std::string topping2;
    std::string topping3;

  Pizza(std::string size, std::string topping1){
    this->size = size;
    this->topping1 = topping1;
  }
  Pizza(std::string size, std::string topping1, std::string topping2){
    this->size = size;
    this->topping1 = topping1;
    this->topping2 = topping2;
  }
  Pizza(std::string size, std::string topping1, std::string topping2, std::string topping3){
    this->size = size;
    this->topping1 = topping1;
    this->topping2 = topping2;
    this->topping3 = topping3;
  }
  // So, what we've done is automatic acting code for how many variables declared.
};

void showPizza(Pizza pizza){
  std::cout << pizza.size << '\n';
  std::cout << pizza.topping1 << '\n';
  std::cout << pizza.topping2 << '\n';
  std::cout << pizza.topping3 << '\n';
  // Don't worry about fewer toppings, this will work for all of them.
}

void overloadPizzaDemo(){
  Pizza pizza1("Large", "XXX");
  Pizza pizza2("Large", "XXX", "YYY");
  Pizza pizza3("Large", "XXX", "YYY", "ZZZ");

  showPizza(pizza1);
  showPizza(pizza2);
  showPizza(pizza3);
}

// ============================================================================
// SECTION 9: ABSTRACTION & ENCAPSULATION - Hiding Data
// ============================================================================
// Abstraction = Hiding unnecessary data from outside a class.
// Getter = Function that makes private attributes READABLE.
// Setter = Function that makes private attributes MODIFIABLE.

class Stove{
  private:
    int power = 300;
  public:
    int tempreture;
    int getPower(){
      return power;
    }
    void setPower(int power){
      this->power = power;
    }
};

void abstartDemo(){
  Stove stove;
  stove.tempreture = 10000;
  stove.setPower(300);

  std::cout << stove.tempreture << '\n';
  std::cout << stove.getPower() << '\n';
}

// ============================================================================
// SECTION 10: INHERITANCE - Reusing Code
// ============================================================================
// Inheritance = A class can receive attributes and methods from another class.
// Child classes inherit from a parent class. 
// Helps to reuse similar code found within multiple classes.

class Animal{
  public:
    bool alive = true;
  void eat(){
    std::cout << "This animal is eating." << '\n';
  }
};

class Dog : public Animal{
  public:
    void bark(){
      std::cout << "The dog barks!" << '\n';
    }
};

class Cat : public Animal{
  public:
    void meow(){
      std::cout << "The cat meows!" << '\n';
    }
};

void inheritanceDemo(){
  Dog dog;
  Cat cat;

  std::cout << dog.alive << '\n';
  dog.eat();
  dog.bark();

  std::cout << cat.alive << '\n';
  cat.eat();
  cat.meow();

  // So, eat works without being inside of the other two.
}

// Here is another example, and let's say "End" for this Journey:

class Shape{
  public:
    double area;
    double volume;
};

class Cube : public Shape{
  public:
    double side;
    Cube(double side){
      this->side = side;
      this->area = side * side * 6;
      this->volume = side * side * side;
    }
};

class Sphere : public Shape{
  public:
    double radius;
    Sphere(double radius){
      this->radius = radius;
      this->area = 4 * 3.14159 * radius * radius;
      this->volume = (4/3.0) * 3.14159 * radius * radius * radius;
    }
};

void shapeDemo(){
  Cube cube(10);
  Sphere sphere(10);

  std::cout << "Cube area: " << cube.area << '\n';
  std::cout << "Cube volume: " << cube.volume << '\n';
  std::cout << "Sphere area: " << sphere.area << '\n';
  std::cout << "Sphere volume: " << sphere.volume << '\n';

}

// Thanks for your time!
// My C++ journey ends here, but I will continue to learn and improve.
// Have a nice day, see you in another journey!


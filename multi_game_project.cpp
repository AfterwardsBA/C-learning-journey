#include <ctime>
#include <iostream>

int TempretureConverter() {

  double temp;
  int unit;
  double answer;

  std::cout << "Welcome to my unit change for tempretures!" << std::endl;
  std::cout << "I have 2 unit changing options for now: " << std::endl;
  std::cout << "(1) Celcius to Fahrenheit" << std::endl;
  std::cout << "(2) Fahrenheit to Celcius" << std::endl;
  std::cout << "Please, choose your operation (1/2) ";
  std::cin >> unit;
  std::cout << std::endl;

  if (unit == 1) {
    std::cout << "What is your tempreture in Celcius? ";
    std::cin >> temp;
    std::cout << std::endl;
    answer = (temp * (double)9 / 5) + 32;
    std::cout << temp << "C " << "= " << answer << "F";
  } else if (unit == 2) {
    std::cout << "What is your tempreture in Fahrenheit? ";
    std::cin >> temp;
    std::cout << std::endl;
    answer = (temp - 32) * (double)5 / 9;
    std::cout << temp << "F " << "= " << answer << "C";
  } else {
    std::cout << "Invalid input!!";
  }

  return 0;
}

int BasicCalculator() {

  int op; // You can do it with "char" too. Looks better I think.
  double num1;
  double num2;
  double answer;

  std::cout << "Welcome to my simlpe calculator!" << std::endl;
  std::cout << "There is four operations avabile!" << std::endl;
  std::cout << "1 = Add (+)" << std::endl;
  std::cout << "2 = Substract (-)" << std::endl;
  std::cout << "3 = Multiply (*)" << std::endl;
  std::cout << "4 = Divide (/)" << std::endl;

  std::cout << "Please, enter number1: " << std::endl;
  std::cin >> num1;
  std::cout << "Please, enter number2: " << std::endl;
  std::cin >> num2;
  std::cout << "Which operation do you want to do?" << std::endl;
  std::cin >> op;

  if (op == 1) {
    answer = num1 + num2;
    std::cout << "Your answer is = " << answer << " !";

  } else if (op == 2) {
    answer = num1 - num2;
    std::cout << "Your answer is = " << answer << " !";
  } else if (op == 3) {
    answer = num1 * num2;
    std::cout << "Your answer is = " << answer << " !";
  } else if (op == 4) {
    if (num2 == 0) {
      std::cout << "You cant use 0 for devide something!";
      return 1;
    }
    answer = num1 / num2;
    std::cout << "Your answer is = " << answer << " !";
  } else {
    std::cout << "Please enter a valid operation (1-4)!";
  }

  return 0;
}

int BMI_Calculator() {
  double height;
  double weight;
  double BMI;

  std::cout << "Welcome to BMI calculator!! ";
  std::cout << "\nWhat is your weight ing 'kg'? ";
  std::cin >> weight;
  std::cout << "\nWhat is your height in meters? ";
  std::cin >> height;

  BMI = weight / (height * height);
  std::cout << "Your BMI is: " << BMI;

  if (BMI < 18.5) {
    std::cout << "Category: Underweight. ";
  } else if (18.5 <= BMI && BMI < 25) {
    std::cout << "Category: Normal. ";
  } else if (25 <= BMI && BMI < 30) {
    std::cout << "Category: Overweight. ";
  } else if (BMI >= 30) {
    std::cout << "Category: Obese. ";
  }
  return 0;
}

void showMainMenu() {
  std::cout << "\n╔═══════════════════════════════╗\n";
  std::cout << "║ ==== C++ GAME COLLECTION ==== ║\n";
  std::cout << "╚═══════════════════════════════╝\n";
  std::cout << "1. 🌡️ Tempreture Converter (F/C)\n";
  std::cout << "2. 🧮 Modular Calculator\n";
  std::cout << "3. 🧮 BMI Calculator\n";
  std::cout << "4. 💰 ATM System\n";
  std::cout << "5. ✊ Rock Paper Scissors\n";
  std::cout << "6. 🎯 Number Guessing Game\n";
  std::cout << "0. 🚪 Exit\n";
  std::cout << "─────────────────────────────────\n";
  std::cout << "Your choice: ";
}

void account_info(double balance, double loan) {
  std::cout << "\n-----------------\n";
  std::cout << "Balance: " << balance << "$\n";
  std::cout << "Loan: " << loan << "$\n";
  std::cout << "-----------------\n";
}

int ATM_System() {
  double balance;
  balance = 10000;
  double loan;
  loan = 10000;
  double gambled;
  gambled = 0;
  int operation;
  double amount;
  int bill;

  std::cout << "Welcome to my ATM simulator!\n";
  std::cout << "-----------------\n";
  std::cout << "Balance: 0$\n";
  std::cout << "-----------------";
  std::cout << "\nLet me give you some credits to try features\n";
  std::cout << "-----------------\n";
  std::cout << "Balance: 10000$\n";
  std::cout << "-----------------\n";
  std::cout << "Use it as you like!\n";

  do {
    account_info(balance, loan);
    std::cout << "Avabile operations:\n";
    std::cout << "--------------------";
    std::cout << "1.Pay loan\n";
    std::cout << "2.Pay bills\n";
    std::cout << "3.Take loan\n";
    std::cout << "4.Play gambling\n";
    std::cout << "=press 0 for geting out=\n";
    std::cout << "--------------------";
    std::cout << "\nChoose your operation: ";
    std::cin >> operation;

    if (operation == 1) {
      std::cout << "\nChoose payment amount: ";
      std::cin >> amount;
      if (amount > balance) {
        std::cout << "You dont have enough money on your account.";
        return 1;
      } else {
        balance = balance - amount;
        loan = loan - amount;
      }
    } else if (operation == 2) {
      std::cout << "Blls will be paid automaticly for your ID\n";
      std::cout << "------------------------";
      std::cout << "\nSuported bill types: ";
      std::cout << "\n1.Water";
      std::cout << "\n2.Rent";
      std::cout << "\n3.School Loan\n";
      std::cout << "\n4.Hospital Loan\n";
      std::cout << "------------------------";
      std::cout << "\nChoose your bill type: ";
      std::cin >> bill;

      if (bill == 1) {
        std::cout << "\nChoose payment amount: ";
        std::cin >> amount;
        if (amount > balance) {
          std::cout << "You dont have enough money on your account.";
          return 1;
        } else {
          balance = balance - amount;
        }
      } else if (bill == 2) {
        std::cout << "\nChoose payment amount: ";
        std::cin >> amount;
        if (amount > balance) {
          std::cout << "\nYou dont have enough money on your account.";
          return 1;
        } else {
          balance = balance - amount;
        }
      } else if (bill == 3) {
        std::cout << "\nChoose payment amount: ";
        std::cin >> amount;
        if (amount > balance) {
          std::cout << "\nYou dont have enough money on your account.";
          return 1;
        } else {
          balance = balance - amount;
        }
      } else if (bill == 4) {
        int answer;
        std::cout << "\nAre you living in US? (1 for yes / 2 for no)";
        std::cin >> answer;
        if (answer == 1) {
          std::cout << "\nYou are cooked. Use the money for moving to another "
                       "country (I know couple of ways...)";
        } else if (answer == 2) {
          std::cout << "\nChoose payment amount: ";
          std::cin >> amount;
          if (amount > balance) {
            std::cout << "\nYou dont have enough money on your account.";
            return 1;
          } else {
            balance = balance - amount;
          }
        } else {
          std::cout << "\nERROR: Non-exist answer";
          return 1;
        }
      } else {
        std::cout << "\nERROR: Bill type does mot exist";
        return 1;
      }

    } else if (operation == 3) {
      std::cout << "\nHow much do you want to take as loan?";
      std::cin >> amount;
      balance = balance + amount;
      loan = loan + amount;
    } else if (operation == 4) {
      std::cout << "\nHow much do you want to gamble?";
      std::cin >> gambled;
      if (gambled > balance) {
        std::cout << "\nYou dont have enough money on your account.";
        return 1;
      } else {
        balance = balance - gambled;
      }
    }

    else {
      std::cout << "\nERROR: There is no operation for that input";
      return 1;
    }

    if (gambled == 0) {
      std::cout << "\n-----------------\n";
      std::cout << "Balance: " << balance << "$\n";
      std::cout << "Loan: " << loan << "$\n";
      std::cout << "-----------------\n";
    } else {
      std::cout << "\n-----------------\n";
      std::cout << "Balance: " << balance << "$\n";
      std::cout << "Loan: " << loan << "$\n";
      std::cout << "Gambled: " << gambled << "$\n";
      std::cout << "-----------------\n";
    }
  } while (operation != 0);

  return 0;
}

int RockPaperScissors() {

  srand(time(0));

  char move;
  double game_count;
  game_count = 0;
  double player_point;
  player_point = 0;
  int computer_point;
  computer_point = 0;
  double success_rate;

  std::cout << "Welcome to Rock-Paper-Scissors Game!\n";
  std::cout << "You and computer will choose one and winner get one ponint\n";
  std::cout << "Rules are simple -> Choose one: Rock(R) Paper(P) Scissors(S)\n";
  std::cout << "Rock beats Scissors\n";
  std::cout << "Scissors beats Paper\n";
  std::cout << "Paper beats Rock\n";
  std::cout << "Computer will choose randomly, good luck!\n";
  do {
    std::cout << "\n------Game Starts------\n";
    std::cout << "Choose your move!\n";
    std::cout << "R(rock) P(paper) S(scissors) [enter E for exit]";
    std::cin >> move;
    int num = rand() % 3 + 1;

    if (move == 'R') {
      if (num == 1) {
        std::cout << "\nComputer chose: Rock. -> TIE!";
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      } else if (num == 2) {
        std::cout << "\nComputer chose: Paper. -> YOU LOSE!";
        computer_point++;
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      } else if (num == 3) {
        std::cout << "\nComputer chose: Scissors. -> YOU WIN!";
        player_point++;
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      }
    } else if (move == 'P') {
      if (num == 1) {
        std::cout << "\nComputer chose: Rock. -> YOU WIN!";
        player_point++;
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      } else if (num == 2) {
        std::cout << "\nComputer chose: Paper. -> TIE!";
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      } else if (num == 3) {
        std::cout << "\nComputer chose: Scissors. -> YOU LOOSE!";
        computer_point++;
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      }
    } else if (move == 'S') {
      if (num == 1) {
        std::cout << "\nComputer chose: Rock. -> YOU LOSE!";
        computer_point++;
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      } else if (num == 2) {
        std::cout << "\nComputer chose: Paper. -> YOU WIN!";
        player_point++;
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      } else if (num == 3) {
        std::cout << "\nComputer chose: Scissors. -> TIE!";
        std::cout << "\nPlayer score: " << player_point;
        std::cout << "\nComputer score: " << computer_point;
      }
    } else if (move == 'E') {
      std::cout << "Thanks for playing!\n";
      game_count--;
      break;
    } else {
      std::cout << "ERROR: Unexpected input.\n";
      return 1;
    }
    game_count++;
    std::cout << game_count << " Games Played";
  } while (move != 'E');

  success_rate = (player_point / game_count) * 100;

  if (success_rate == 100) {
    std::cout << "\n---------------------------";
    std::cout << "\n===== You nailed it! =====";
    std::cout << "\nGames Played: " << game_count;
    std::cout << "\nPlayer Scored: " << player_point << " times!";
    std::cout << "\nComputer Scored: " << computer_point << " times!";
    std::cout << "\nYour success rate: " << success_rate << "%";
    std::cout << "-----------------------------";
  } else if (success_rate < 100 && success_rate >= 70) {
    std::cout << "\n----------------------------";
    std::cout << "\n===== Very Impressive! =====";
    std::cout << "\nGames Played: " << game_count;
    std::cout << "\nPlayer Scored: " << player_point << " times!";
    std::cout << "\nComputer Scored: " << computer_point << " times!";
    std::cout << "\nYour success rate: " << success_rate << "%";
    std::cout << "------------------------------";
  } else if (success_rate < 70 && success_rate >= 50) {
    std::cout << "\n-------------------------";
    std::cout << "\n===== Not Bad! =====";
    std::cout << "\nGames Played: " << game_count;
    std::cout << "\nPlayer Scored: " << player_point << " times!";
    std::cout << "\nComputer Scored: " << computer_point << " times!";
    std::cout << "\nYour success rate: " << success_rate << "%";
    std::cout << "---------------------------";
  } else if (success_rate == 50) {
    std::cout << "\n-------------------------------";
    std::cout << "\n===== Perfectly Balanced! =====";
    std::cout << "\nGames Played: " << game_count;
    std::cout << "\nPlayer Scored: " << player_point << " times!";
    std::cout << "\nComputer Scored: " << computer_point << " times!";
    std::cout << "\nYour success rate: " << success_rate << "%";
    std::cout << "---------------------------------";
  } else if (success_rate < 50 && success_rate >= 30) {
    std::cout << "\n----------------------------";
    std::cout << "\n===== Not Good Output! =====";
    std::cout << "\nGames Played: " << game_count;
    std::cout << "\nPlayer Scored: " << player_point << " times!";
    std::cout << "\nComputer Scored: " << computer_point << " times!";
    std::cout << "\nYour success rate: " << success_rate << "%";
    std::cout << "------------------------------";
  } else if (success_rate < 30 && success_rate > 0) {
    std::cout << "\n------------------------------------------";
    std::cout << "\n===== Dont Ever Dare to Gamble Again!=====";
    std::cout << "\nGames Played: " << game_count;
    std::cout << "\nPlayer Scored: " << player_point << " times!";
    std::cout << "\nComputer Scored: " << computer_point << " times!";
    std::cout << "\nYour success rate: " << success_rate << "%";
    std::cout << "--------------------------------------------";
  } else {
  }

  return 0;
}

void easy_level(std::string name, int& score, int& left_try, int& player_try) {
  int number = rand() % 50 + 1;
  left_try = 6;
  player_try = 0;
  int guess;
  
  std::cout << "\n╔══════════════════════════════════════╗\n";
  std::cout << "║          EASY LEVEL (1-50)           ║\n";
  std::cout << "║          " << name << "'s Turn!            ║\n";
  std::cout << "╚══════════════════════════════════════╝\n";
  
  while (left_try > 0) {
      std::cout << "\n🎯 Tries left: " << left_try << " | Score: " << score;
      std::cout << "\n💭 Your guess (1-50): ";
      std::cin >> guess;
      
      // Input validation
      if (std::cin.fail() || guess < 1 || guess > 50) {
          std::cin.clear();
          std::cin.ignore(1000, '\n');
          std::cout << "❌ Invalid input! Enter number 1-50.\n";
          continue;
      }
      
      player_try++;
      left_try--;
      
      if (guess == number) {
          // Points formula: base(100) - distance penalty + try bonus
          int distance = abs(number - guess);
          int points = 100 - (distance * 2) + ((6 - player_try) * 15);
          if (points < 10) points = 10; // Minimum points
          score += points;
          
          std::cout << "\n🎉 CORRECT! The number was " << number << "!\n";
          std::cout << "⭐ You earned " << points << " points!\n";
          std::cout << "📊 Total score: " << score << "\n";
          return;
      } else if (guess < number) {
          std::cout << "📈 Higher! ";
      } else {
          std::cout << "📉 Lower! ";
      }
      
      // Give distance hint
      int difference = abs(number - guess);
      if (difference <= 5) std::cout << "🔥 You're HOT!";
      else if (difference <= 15) std::cout << "😊 Warm...";
      else std::cout << "🥶 Cold.";
      std::cout << "\n";
  }
  
  std::cout << "\n💀 OUT OF TRIES! The number was: " << number << "\n";
  std::cout << "📉 Score unchanged: " << score << "\n";
}

void medium_level(std::string name, int& score, int& left_try, int& player_try) {
  int number = rand() % 100 + 1;
  left_try = 6;
  player_try = 0;
  int guess;
  
  std::cout << "\n╔══════════════════════════════════════╗\n";
  std::cout << "║        MEDIUM LEVEL (1-100)          ║\n";
  std::cout << "║          " << name << "'s Turn!            ║\n";
  std::cout << "╚══════════════════════════════════════╝\n";
  
  while (left_try > 0) {
      std::cout << "\n🎯 Tries left: " << left_try << " | Score: " << score;
      std::cout << "\n💭 Your guess (1-100): ";
      std::cin >> guess;
      
      if (std::cin.fail() || guess < 1 || guess > 100) {
          std::cin.clear();
          std::cin.ignore(1000, '\n');
          std::cout << "❌ Invalid input! Enter number 1-100.\n";
          continue;
      }
      
      player_try++;
      left_try--;
      
      if (guess == number) {
          int distance = abs(number - guess);
          int points = 200 - (distance * 2) + ((6 - player_try) * 25);
          if (points < 20) points = 20;
          score += points;
          
          std::cout << "\n🎉 CORRECT! The number was " << number << "!\n";
          std::cout << "⭐ You earned " << points << " points!\n";
          std::cout << "📊 Total score: " << score << "\n";
          return;
      } else if (guess < number) {
          std::cout << "📈 Higher! ";
      } else {
          std::cout << "📉 Lower! ";
      }
      
      int difference = abs(number - guess);
      if (difference <= 10) std::cout << "🔥 You're HOT!";
      else if (difference <= 30) std::cout << "😊 Warm...";
      else std::cout << "🥶 Cold.";
      std::cout << "\n";
  }
  
  std::cout << "\n💀 OUT OF TRIES! The number was: " << number << "\n";
  std::cout << "📉 Score unchanged: " << score << "\n";
}

void hard_level(std::string name, int& score, int& left_try, int& player_try) {
  int number = rand() % 500 + 1;
  left_try = 6;
  player_try = 0;
  int guess;
  
  std::cout << "\n╔══════════════════════════════════════╗\n";
  std::cout << "║          HARD LEVEL (1-500)          ║\n";
  std::cout << "║          " << name << "'s Turn!            ║\n";
  std::cout << "╚══════════════════════════════════════╝\n";
  
  while (left_try > 0) {
      std::cout << "\n🎯 Tries left: " << left_try << " | Score: " << score;
      std::cout << "\n💭 Your guess (1-500): ";
      std::cin >> guess;
      
      if (std::cin.fail() || guess < 1 || guess > 500) {
          std::cin.clear();
          std::cin.ignore(1000, '\n');
          std::cout << "❌ Invalid input! Enter number 1-500.\n";
          continue;
      }
      
      player_try++;
      left_try--;
      
      if (guess == number) {
          int distance = abs(number - guess);
          int points = 500 - distance + ((6 - player_try) * 50);
          if (points < 50) points = 50;
          score += points;
          
          std::cout << "\n🎉 CORRECT! The number was " << number << "!\n";
          std::cout << "⭐ You earned " << points << " points!\n";
          std::cout << "📊 Total score: " << score << "\n";
          return;
      } else if (guess < number) {
          std::cout << "📈 Higher! ";
      } else {
          std::cout << "📉 Lower! ";
      }
      
      int difference = abs(number - guess);
      if (difference <= 25) std::cout << "🔥 You're HOT!";
      else if (difference <= 100) std::cout << "😊 Warm...";
      else std::cout << "🥶 Cold.";
      std::cout << "\n";
  }
  
  std::cout << "\n💀 OUT OF TRIES! The number was: " << number << "\n";
  std::cout << "📉 Score unchanged: " << score << "\n";
}

void impossible_level(std::string name, int& score, int& left_try, int& player_try) {
  int number = rand() % 1000 + 1;
  left_try = 7;  // One extra try for impossible!
  player_try = 0;
  int guess;
  
  std::cout << "\n╔══════════════════════════════════════╗\n";
  std::cout << "║      IMPOSSIBLE LEVEL (1-1000)       ║\n";
  std::cout << "║          " << name << "'s Turn!            ║\n";
  std::cout << "╚══════════════════════════════════════╝\n";
  
  while (left_try > 0) {
      std::cout << "\n🎯 Tries left: " << left_try << " | Score: " << score;
      std::cout << "\n💭 Your guess (1-1000): ";
      std::cin >> guess;
      
      if (std::cin.fail() || guess < 1 || guess > 1000) {
          std::cin.clear();
          std::cin.ignore(1000, '\n');
          std::cout << "❌ Invalid input! Enter number 1-1000.\n";
          continue;
      }
      
      player_try++;
      left_try--;
      
      if (guess == number) {
          int distance = abs(number - guess);
          int points = 1000 - (distance / 2) + ((7 - player_try) * 100);
          if (points < 100) points = 100;
          score += points;
          
          std::cout << "\n🎉🎉🎉 LEGENDARY! The number was " << number << "!\n";
          std::cout << "🏆 You earned " << points << " points!\n";
          std::cout << "📊 Total score: " << score << "\n";
          return;
      } else if (guess < number) {
          std::cout << "📈 Higher! ";
      } else {
          std::cout << "📉 Lower! ";
      }
      
      int difference = abs(number - guess);
      if (difference <= 50) std::cout << "🔥 You're ON FIRE!";
      else if (difference <= 200) std::cout << "😊 Warm...";
      else std::cout << "🥶 FREEZING!";
      std::cout << "\n";
  }
  
  std::cout << "\n💀💀💀 IMPOSSIBLE FAILED! The number was: " << number << "\n";
  std::cout << "📉 Score unchanged: " << score << "\n";
}

void normal_mode(std::string name, int& score, int& left_try, int& player_try) {
  int level_choice;
  
  do {
      std::cout << "\n╔══════════════════════════════════════╗\n";
      std::cout << "║           NORMAL MODE MENU          ║\n";
      std::cout << "╚══════════════════════════════════════╝\n";
      std::cout << "📊 Current Score: " << score << "\n";
      std::cout << "1. 🟢 Easy (1-50, 6 tries)\n";
      std::cout << "2. 🟡 Medium (1-100, 6 tries)\n";
      std::cout << "3. 🔴 Hard (1-500, 6 tries)\n";
      std::cout << "4. 💀 Impossible (1-1000, 7 tries)\n";
      std::cout << "0. ↩️  Return to Main Menu\n";
      std::cout << "Choice: ";
      std::cin >> level_choice;
      
      switch (level_choice) {
          case 1:
              easy_level(name, score, left_try, player_try);
              break;
          case 2:
              medium_level(name, score, left_try, player_try);
              break;
          case 3:
              hard_level(name, score, left_try, player_try);
              break;
          case 4:
              impossible_level(name, score, left_try, player_try);
              break;
          case 0:
              std::cout << "\nReturning to main menu...\n";
              break;
          default:
              std::cout << "❌ Invalid choice!\n";
      }
      
      // Pause between levels
      if (level_choice != 0) {
          std::cout << "\nPress Enter to continue...";
          std::cin.ignore();
          std::cin.get();
      }
      
  } while (level_choice != 0);
}

void tower_climb(std::string name, int& score, int& left_try, int& player_try) {
  int level = 1;  // 1=easy, 2=medium, 3=hard, 4=impossible
  
  std::cout << "\n╔══════════════════════════════════════╗\n";
  std::cout << "║           TOWER CLIMB MODE          ║\n";
  std::cout << "║   Complete all levels consecutively  ║\n";
  std::cout << "╚══════════════════════════════════════╝\n";
  
  while (level <= 4) {
      std::cout << "\n▶️  Current Level: ";
      switch (level) {
          case 1: std::cout << "EASY"; break;
          case 2: std::cout << "MEDIUM"; break;
          case 3: std::cout << "HARD"; break;
          case 4: std::cout << "IMPOSSIBLE"; break;
      }
      std::cout << " | Score: " << score << "\n";
      
      bool won = false;
      switch (level) {
          case 1:
              easy_level(name, score, left_try, player_try);
              won = (left_try > 0);  // Simplified win check
              break;
          case 2:
              medium_level(name, score, left_try, player_try);
              won = (left_try > 0);
              break;
          case 3:
              hard_level(name, score, left_try, player_try);
              won = (left_try > 0);
              break;
          case 4:
              impossible_level(name, score, left_try, player_try);
              won = (left_try > 0);
              break;
      }
      
      if (won) {
          std::cout << "\n✅ LEVEL " << level << " COMPLETED!\n";
          level++;
          
          // Bonus points for completing level
          int bonus = level * 50;
          score += bonus;
          std::cout << "🎁 Level completion bonus: +" << bonus << " points!\n";
      } else {
          std::cout << "\n❌ LEVEL FAILED! Trying again...\n";
          // Small penalty for failure
          score -= 20;
          if (score < 0) score = 0;
          std::cout << "📉 Failure penalty: -20 points\n";
      }
      
      std::cout << "\nPress Enter to continue...";
      std::cin.ignore();
      std::cin.get();
  }
  
  std::cout << "\n🏆🏆🏆 CONGRATULATIONS! 🏆🏆🏆\n";
  std::cout << "You've conquered the TOWER CLIMB!\n";
  std::cout << "Final Score: " << score << "\n";
}

void practice_mode(std::string name) {
  int level_choice;
  int infinite_tries = 999;  // Practically unlimited
  
  do {
      std::cout << "\n╔══════════════════════════════════════╗\n";
      std::cout << "║           PRACTICE MODE             ║\n";
      std::cout << "║   Unlimited tries, no score tracking  ║\n";
      std::cout << "╚══════════════════════════════════════╝\n";
      std::cout << "1. 🟢 Easy (1-50)\n";
      std::cout << "2. 🟡 Medium (1-100)\n";
      std::cout << "3. 🔴 Hard (1-500)\n";
      std::cout << "4. 💀 Impossible (1-1000)\n";
      std::cout << "0. ↩️  Return to Main Menu\n";
      std::cout << "Choice: ";
      std::cin >> level_choice;
      
      if (level_choice >= 1 && level_choice <= 4) {
          // Simple practice version - just guess until correct
          int number, guess, tries = 0;
          
          switch (level_choice) {
              case 1: number = rand() % 50 + 1; break;
              case 2: number = rand() % 100 + 1; break;
              case 3: number = rand() % 500 + 1; break;
              case 4: number = rand() % 1000 + 1; break;
          }
          
          std::cout << "\n🎯 PRACTICE SESSION - Guess until correct!\n";
          
          do {
              std::cout << "Guess: ";
              std::cin >> guess;
              tries++;
              
              if (guess == number) {
                  std::cout << "✅ Correct! It took you " << tries << " tries.\n";
              } else if (guess < number) {
                  std::cout << "📈 Higher!\n";
              } else {
                  std::cout << "📉 Lower!\n";
              }
          } while (guess != number);
      }
      
  } while (level_choice != 0);
}

int NumberGuessingGame(){
  int player_try = 0;
  int left_try;
  int score = 0;
  std::string Name;
  int mode_choice;
  int end_choice;
  
  std::cout << "--------------Welcome to Number Guessing Game!----------------\n";
  std::cout << "Your goal is guessing the number that chosen randomly by computer.\n";
  std::cout << "There are 4 different difficulties and 3 different playing rules!\n";
  std::cout << "Please enter your name for starting the system on your name.\n";
  std::cin >> Name;
  std::cout << "Ok " << Name << "here are the rules: ";
  std::cout << "\nThere is 4 different difficulties: Easy/Medium/Hard/Impossible.\n";
  std::cout << "Every different difficulty have its own point system and try chances.\n";
  std::cout << "Easy = number is between 1-50 , you have 5 chances to guess it.\n";
  std::cout << "Medium = number is between 1-100 , you have 6 chances to guess it.\n";
  std::cout << "Hard = number is between 1-500 , you have 7 chances to guess it.\n";
  std::cout << "Impossible = number is between 1-1000 , you have 7 chances yo guess it.\n";
  std::cout << "The points you get is going to increase when difficulty increased.\n";
  std::cout << "Every try you made gives point according to how close you are the answer!\n";
  std::cout << "Game modes mean rules is going to slightly change:\n";
  std::cout << "Normal mode = Choose your difficulty and do your best according to rules!\n";
  std::cout << "Tower climb = You will play every level one by one. Complete one -> next level with bonus points.\n";
  std::cout << "But be careful! Every failed level is going to make you lose points.\n";
  std::cout << "Practice mode = There is no points or try limits! Play or practice as you like!\n";
  std::cout << "This is everything you need to know, HAVE FUN!\n";
  std::cout << "---------------------------------------------------------------\n";
  do {
    std::cout << "\n------------CHOOSE AN OPERATION-----------------\n";
    std::cout << "               1. Normal Mode\n";
    std::cout << "               2. Tower Climb\n";
    std::cout << "               3. Practice Mode\n";
    std::cout << "        0. EXIT (Return to Game Collection)\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "Choice: ";
    std::cin >> mode_choice;
    
    switch(mode_choice) {
        case 1:
            std::cout << "Starting Normal Mode...\n";
            normal_mode(Name,  score ,  left_try, player_try);
            break;
        case 2:
            std::cout << "Starting Tower Climb...\n";
            tower_climb(Name,  score ,  left_try, player_try);
            break;
        case 3:
            std::cout << "Starting Practice Mode...\n";
            practice_mode(Name);
            break;
        case 0:
            std::cout << "Returning to Game Collection...\n";
            break;
        default:
            std::cout << "ERROR: Invalid choice! Please enter 0-3.\n";
    }
    
} while(mode_choice != 0);
return 0;
}

int main() {
  srand(time(0));

  int choice;

  do {

    showMainMenu();
    std::cin >> choice;

    switch (choice) {
    case 1:
      TempretureConverter();
      break;
    case 2:
      BasicCalculator();
      break;
    case 3:
      BMI_Calculator();
      break;
    case 4:
      ATM_System();
      break;
    case 5:
      RockPaperScissors();
      break;
    case 6:
      NumberGuessingGame(); 
      break;
    case 0:
      std::cout << "Goodbye!\n";
      break;
    default:
      std::cout << "Invalid choice!\n";
    }

    if (choice != 0) {
      std::cout << "\nPress Enter to continue...";
      std::cin.ignore();
      std::cin.get();
    }

  } while (choice != 0);

  return 0;
}
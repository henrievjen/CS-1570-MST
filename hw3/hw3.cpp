// Henri Evjen
// 9/11/19
// HW3
// Dr. Nick Reception Program to calculate surgery prices of paitents

#include <iostream>
using namespace std;

int main() {
  // Declarations
  const float SURGERY_PRICE = 129.95;
  const short MIN_AGE = 21, MAX_AGE = 65, MIN_REASONABLE_AGE = 1,
  MAX_REASONABLE_AGE = 120, MIN_MONEY = 0, MIN_SURGERIES = 0;
  string fName;
  double money, totalCost;
  short age, surgeries, remainSurgery, affordSurgery;
  char malpractice, repeat_visit;

  // Fixed Currency Output
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  do {
    // Sets the repeat visit to 'n' until prompt user at end
    repeat_visit = 'n';

    // Sets malpractice variable to 'n' in case it is not asked
    malpractice = 'n';

    // Greeting
    cout << "Welcome to Dr. Nick's Office!" << endl;
  
    // Gather Input
    cout << "What is your first name?" << endl;
    cin >> fName;
    cout << "Thank you " <<fName<< "!" << endl;

    do {
      cout << "How much money do you have with you?" << endl;
      cin >> money;
    } while(money < MIN_MONEY);

    if(money == MIN_MONEY) {
      cout << "Please leave the premises immediately...and have a good day." 
      << " NEXT." << endl;
    }
    else if(money < SURGERY_PRICE) {
      cout << "Please come back when you have at least $" << SURGERY_PRICE 
      << "." << endl;
    }
    else {
      cout << "Thank you." << endl;

      do {
        cout << "How old are you?" << endl; 
        cin >> age;
      } while(age < MIN_REASONABLE_AGE || age > MAX_REASONABLE_AGE);

      if(age < MIN_AGE) {
        cout << "Please leave. You're too young" << endl;
      }
      else {
        if(age >= MIN_AGE && age <= MAX_AGE) {
          do {
            cout << "Have you ever filed a malpractice suit? y/n" << endl;
            cin >> malpractice;
          } while(!(malpractice == 'y' || malpractice == 'n'));
        }

        if(malpractice == 'y') {
          cout << "I'm sorry, we're closed now!" << endl;
        }
        else {
          cout << "Each surgery will cost you $"<<SURGERY_PRICE<<"."<<endl;
          do {
            cout << "How many surgeries do you want?" << endl;
            cin >> surgeries;
          } while(surgeries < MIN_SURGERIES);

          // Calculation
	  totalCost = surgeries * SURGERY_PRICE;
	 
          // How many surgeries the user can afford  -  short type
          affordSurgery = static_cast<short>(money / SURGERY_PRICE);
          // How many surgeries the user can still purchase  -  short type
      	  remainSurgery = static_cast<short>((money-totalCost)/SURGERY_PRICE);

	  if((money - totalCost) >= SURGERY_PRICE) {
	    cout << "Your " << surgeries << " surgeries will cost you $"
	    << totalCost << "." << endl;
	    cout << "You are still able to purchase " << remainSurgery
            << " more surgeries." << endl;
	  }
          else if((money - totalCost) < MIN_MONEY) {
            cout << surgeries << " surgeries would cost you $" << totalCost
	    << " and you only have $" << money << "." << endl;
	    cout << "You can only afford " << affordSurgery << " surgeries"
  	    << endl;
  	  }

          cout << "Please come on in!" << endl;
        }
      }
    }

    // Repeat program if user inputs 'y'
    cout << "Is there anybody else there?" << endl;
    cin >> repeat_visit;
  } while(repeat_visit == 'y');

  cout << "Thank you! Please come again sometime." << endl;

  return 0;
}

// Henri Evjen
// 9/22/19
// HW4
// Code should serve purpose of a virtual vending machine for Dr. Nick.
// Allows user to purchase organs and lets user know what size pan is needed.

#include <iostream>
using namespace std;

int main() {
  // Declarations
  float const EYE_WEIGHT = 2.3, SPLEEN_WEIGHT = 5.6, LIVER_WEIGHT = 3,
  APPENDIX_WEIGHT = 1.2, BRAIN_WEIGHT = .4, EAR_LOBE_WEIGHT = 10;
  float money = 0, price = 0, weight = 0;
  short menuChoice;
  bool repeat = true;

  while(!(menuChoice > 0 && menuChoice < 8) || repeat) {
    // Main Menu
    cout << "\tMain Menu" << endl;
    cout << "1.)  eyeballs   $3.35" << endl;
    cout << "2.)  spleen     $2.75" << endl;
    cout << "3.)  liver      $14.58" << endl;
    cout << "4.)  appendix   $0.50" << endl;
    cout << "5.)  brains     $7.85" << endl;
    cout << "6.)  ear lobes  $13.45  (these are the good ones)" << endl;
    cout << "7.)  Quit" << endl << endl;

    // User Input menuchoice
    cout << "Please choose an option: ";
    cin >> menuChoice;

    switch(menuChoice) {
      case 1:
        cout << "You are purchasing eyeballs for $3.35 that weigh "
        << EYE_WEIGHT << " lb." << endl;
        price = 3.35;
        repeat = true;
        weight = EYE_WEIGHT;
        break;
      case 2:
        cout << "You are purchasing a spleen for $2.75 that weighs "
        << SPLEEN_WEIGHT << " lb." << endl;
        price = 2.75;
        repeat = true;
        weight = SPLEEN_WEIGHT;
        break;
      case 3:
        cout << "You are purchasing a liver for $14.58 that weighs "
        << LIVER_WEIGHT << " lb." << endl;
        price = 14.58;
        repeat = true;
        weight = LIVER_WEIGHT;
        break;
      case 4:
        cout<<"You are purchasing an appendix, a brain, and earlobes for " 
        << "$13.45 that weighs "
         << APPENDIX_WEIGHT + BRAIN_WEIGHT + EAR_LOBE_WEIGHT << " lb." << endl;
        price = 13.45;
        repeat = true;
        weight = APPENDIX_WEIGHT + BRAIN_WEIGHT + EAR_LOBE_WEIGHT;
        break;
      case 5:
        cout << "You are purchasing a brain and ear lobes for $13.45 that "
        << "weighs " << BRAIN_WEIGHT + EAR_LOBE_WEIGHT << " lb." << endl;
        price = 13.45;
        repeat = true;
        weight = BRAIN_WEIGHT + EAR_LOBE_WEIGHT;
        break;
      case 6:
        cout << "You are purchasing ear lobes for $13.45 that weigh " <<
        EAR_LOBE_WEIGHT << " lb." << endl;
        price = 13.45;
        repeat = true;
        break;
      case 7:
        cout << "Quitting..." << endl;
        repeat = false;
        break;
      default:
        cout << "Error. Invalid Input." << endl;
        repeat = true;
    }

    while(price > money) {
      // Input Money
      cout << "Enter money: ";
      cin >> money;

      if(price > money) {
        cout << "Sorry. That is not enough money." << endl;;
      }
      else if(weight <= 1) {
        cout << "Have at least a 1 lb pan ready..." << endl;
      }
      else if(weight <= 2) {
        cout << "Have at least a 2 lb pan ready..." << endl;
      }
      else if(weight <=5) {
        cout << "Have at least a 5 lb pan ready..." << endl;
      }
      else if(weight <= 10) {
        cout << "Have at least a 10 lb pan ready..." << endl;
      }
      else {
        cout << "Have at least a 15 lb pan ready..." << endl;
      }
    }

    // Set price and money to 0 for repeat
    price = 0, money = 0;
  }

  return 0;
}

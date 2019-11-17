// Henri Evjen
// 9/6/19
// HW2
// Dosage Calculator

#include <iostream>
using namespace std;

int main() {
  // Declarations
  short const DR_NICK_CONST = 20, TABLET_STRENGTH = 250;
  short dosage, age, iq, gender, pills_per_day;
  float weight;

  // Greeting
  cout << "Welcome to the Dosage Calculator!" << endl;
  cout << "Please enter the following information..." << endl;

  // User Prompts for Info
  cout << "Age: ";
  cin >> age;
  cout << "Weight (kg): ";
  cin >> weight;
  cout << "IQ: ";
  cin >> iq;
  cout << "Gender (Enter 1 for male, 0 for female): ";
  cin >> gender;
  cout << "Desired number of pills taken a day : ";
  cin >> pills_per_day;

  // Calculation
  dosage = (static_cast<float>(age) / iq) * ((weight / pills_per_day) + 1) *
  ((static_cast<float>(TABLET_STRENGTH) / 1000) + gender) + DR_NICK_CONST;

  // Output
  cout << endl << "Here were your inputs:" << endl;
  cout << "\t Age: " << age << endl;
  cout << "\t Weight: " << weight << " kg" << endl;
  cout << "\t IQ: " << iq << endl;
  cout << "\t Gender: " << gender << " (1 -> male, 0 -> female)" << endl;
  cout << "\t Pill Frequency: " << pills_per_day << endl;
  cout << "\t Tablet Strength is " << TABLET_STRENGTH << " mg" << endl << endl;
  cout << "The recommended dosage is " << dosage << " pills" << endl; 

  return 0;
}

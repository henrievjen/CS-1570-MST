// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include <iostream>
#include <cstdlib>
#include "X_Rayer.h"
#include "Placaeboizer.h"
#include "Pharmacy.h"
#include "Patient.h"
#include "Hospital_Room.h"
#include "Organ_Donor.h"
#include "Lobotomizer.h"
#include "Liposuctionizer.h"
#include "Doctor.h"
using namespace std;

int main()
{
  // Seeding random number with time
  srand(time(NULL));

  // Delcarations
  Patient pats[10];
  Doctor doc("Nick");
  Hospital_Room<X_Rayer> x_rayer;
  Hospital_Room<Placaeboizer> placeboizer;
  Hospital_Room<Pharmacy> pharmacy;
  Hospital_Room<Organ_Donor> organ_donor;
  Hospital_Room<Lobotomizer> lobotomizer;
  Hospital_Room<Liposuctionizer> liposuctionizer;

  cout << "----- SPRINGFIELD HOSPITAL -----" << endl;
  cout << "          DAILY REPORT" << endl << endl;
  cout << "Customers Waiting:" << endl << endl;

  for (short i = 0; i < 10; i++)
  {
    pats[i] = Patient();
    cout << pats[i];
  }

  cout << endl << endl;

  for (short i = 0; i < 10; i++)
  {
    x_rayer.admit(pats[i], doc);
    placeboizer.admit(pats[i], doc);
    pharmacy.admit(pats[i], doc);
    organ_donor.admit(pats[i], doc);
    lobotomizer.admit(pats[i], doc);
    liposuctionizer.admit(pats[i], doc);
    cout << endl;
  }

  cout << endl << "       Final Results of today's Medical Despensery:" << endl
  << endl;
  for (short i = 0; i < 10; i++)
  {
    cout << pats[i];
  }

  cout << endl << endl;

  cout << x_rayer;
  cout << placeboizer;
  cout << pharmacy;
  cout << organ_donor;
  cout << lobotomizer;
  cout << liposuctionizer;

  cout << endl << doc << endl;

  cout <<"That was a fun experience! A special thanks from Dr. "<<doc.getName()
  << ".... At Springfield Hospital, our motto is \"Quality care or your "
  << "autopsy is free.\"" << endl;

  return 0;
}

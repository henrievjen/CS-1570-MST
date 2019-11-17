// Henri Evjen
// 10/28/19
// HW8
// Purpose: the progrma will take in a complaint from the user, then it will
// diagnose the user, give a prescription with dosage, and recommend surgery 

#ifndef HW8_H
#define HW8_H

// Description: prints sentence made of up to 5 random words in complaint
// Pre-condition: WORDS char array must be populated
// Post-condition: random sentence is printed to the screen
void printSentence(const char WORDS[1000][1000], const short LEN);

// Description: randomly chooses a prognosis defending on complaint word 
// Pre-condition: none
// Post-condition: random prognosis is printed to the screen
void randomPrognosis(char complaint_word[1000]);

// Description: loops through complaint for Dr. Nick's vocab words and returns
// word count. Calls randomPrognosis() to print prognosis
// Pre-condition: complaint char array must be populated 
// Post-condition: random progrnosis is printed to the screen
short printPrognosis(const char complaint[2000]);

// Description: prints a random prescription and dosage based on the
// number of words in the complaint
// Pre-condition: complaint char array must be populated
// Post-condition: random prescription and dosage is printed to screen
void printPrescription(const short LEN);

// Description: 75% of the time recommends another surgery for the user
// Pre-condition: none
// Post-condition: either a surgery recommendation is printed or a closing
// message indicating no surgery is required
void printSurgery();

#endif

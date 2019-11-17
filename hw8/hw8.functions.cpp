// Henri Evjen
// 10/28/19
// HW8
// Purpose: the program will take in a complaint from the user, then it will
// diagnose the user, give a prescription with dosage, and recommend surgery

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "hw8.h"
using namespace std;


void printSentence(const char WORDS[1000][1000], const short LEN)
{
  // Declarations
  short total_words;
  int random_num;

  if(LEN >= 5)
  {
    total_words = 5;
  }
  else
  {
    total_words = LEN;
  }

  cout << "So, ";
  for(short i = 0; i < total_words; i++)
  {
    random_num = rand() % LEN;

    for(int j=0; static_cast<unsigned int>(j)<(strlen(WORDS[random_num])); j++)
    {
      if((isalpha(WORDS[random_num][j]) || WORDS[random_num][j] == '\'') &&
      !isblank(WORDS[random_num][j]))
      {
        cout << WORDS[random_num][j];
      }
    }

    if(i < (total_words - 1))
    {
      cout << " ";
    }
  }
  cout << "? ";

  return;
}

void randomPrognosis(char complaint_word[1000])
{
  // Declarations
  int rows, rand_num;
  char prog[1000];
  ifstream fin;

  if(!strcmp(complaint_word, "default"))
  {
    cout << "You clearly have no real complaint. Take two aspirin and get some"
    << " sleep." << endl;
  }
  else
  {
    strcat(complaint_word, ".dat");

    fin.open(complaint_word);

    fin >> rows;
    rand_num = rand() % rows;
    fin.ignore();
    
    for(short i = 0; i <= rand_num; i++)
    {
      fin.getline(prog, 50, '\n');
    }

    fin.close();

    cout << "It is clear that you have " << prog << "." << endl;
  }

  return;
}

short printPrognosis(const char complaint[20000])
{
  // Declarations
  char words[1000][1000];
  char complaint_word[80];
  bool next = true, complaint_word_found = false;
  int arr_count = 0, count = 0, original_count = 0, second_arr_count = 0,
  complaint_count = 0;

  while(next)
  {
    while(complaint[count] != ' ')
    {
      count++;
    }

    for(short i = original_count; i < count; i++)
    {
      words[arr_count][second_arr_count] = complaint[i];
      second_arr_count++;
    } 

    arr_count++;
    second_arr_count = 0;
    original_count = count + 1;
    count++;

    if(static_cast<unsigned int>(count) >= strlen(complaint))
    {
      next = false;
    }
  }

  while(complaint_count < arr_count && !complaint_word_found)
  {
    if(!strncmp(words[complaint_count], "head", 4))
    {
      strcpy(complaint_word, "head");
      complaint_word_found = true;
    }
    else if(!strncmp(words[complaint_count], "torso", 5))
    {
      strcpy(complaint_word, "torso");
      complaint_word_found = true;
    }
    else if(!strncmp(words[complaint_count], "hand", 4))
    {
      strcpy(complaint_word, "hand");
      complaint_word_found = true;
    }
    else if(!strncmp(words[complaint_count], "nose", 4))
    {
      strcpy(complaint_word, "nose");
      complaint_word_found = true;
    }
    else if(!strncmp(words[complaint_count], "leg", 3))
    {
      strcpy(complaint_word, "leg");
      complaint_word_found = true;
    }

    complaint_count++;
  }

  if(!complaint_word_found)
  {
    strcpy(complaint_word, "default");
  }

  printSentence(words, arr_count);
  randomPrognosis(complaint_word);

  return arr_count;
}

void printPrescription(const short LEN)
{
  // Declarations
  ifstream fin;
  char prescriptions[256][256], prescription[256] = "", next[256];
  short rand_num, total_prescriptions = 0;

  fin.open("scripts.dat");

  while(fin >> next)
  {
    strcpy(prescriptions[total_prescriptions++], next);
  }

  for(short i = 0; i < 4; i++)
  {
    rand_num = (rand() % (total_prescriptions + 1));
    strcat(prescription, prescriptions[rand_num]);
  }

  prescription[0] = toupper(prescription[0]);

  fin.close();

  cout << "Your prescription is to take " << LEN << " pills a day of 20mg."
  << " " << prescription << endl;

  return;
} 

void printSurgery()
{
  // Declarations
  const short RAND_NUM = rand() % 4;
  ifstream fin;
  short rows;
  char surgery[2500]; 
 
  if(RAND_NUM != 0)
  {
    fin.open("surgeries.dat");

    fin >> rows;
    for(short i = 0; i < rows; i++)
    {
      fin.getline(surgery, 256, '\n');
    }

    cout <<"I would also recommend that you undergo a "<<surgery<<"."<<endl;
  }
  else
  {
    cout << "You will not have to undergo any surgery!" << endl;
  }

  return;
}

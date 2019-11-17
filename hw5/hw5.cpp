// Henri Evjen
// 9/30/19
// HW5
// Purpose: To translate a user inputted character into either Morse code,
// ASCII, or change its case 

#include <iostream>
using namespace std;

/* Function Declarations */

// Description: outputs a greeting message to screen
// Pre-condition: none
// Post-condition: greeting message output to screen
void greeting();

// Description: outputs a goodbye message to screen
// Pre-condition: none
// Post-condition: goodbye message output to screen
void goodbye();

// Description: presents menu to user and return user's menu choice
// Pre-condition: none
// Post-condition: menu is output to screen and user's choice is returned
char present_menu();

// Description: handles translation based on user's menu choice
// Pre-condition: char option must be between 1 & 5 inclusive, char alpha must
// be an alphabetic character
// Post-condition: translation or error is output, value of quit returned 
bool option_handler(const char OPTION, char& alpha, bool& option1_chosen);

// Description: user inputs an alphabetic character that the function returns
// Pre-condition: none
// Post-condition: returns user inputted alphabetic character
char get_input_from_user();

// Description: outputs to screen morse code translation of input
// Pre-condition: alpha is an alphabetic character
// Post-condition: morse code trnaslation of alpha is output to screen
void morse(const char ALPHA);

// Description: outputs to screen ascii value of input
// Pre-condition: alpha is an alphabetic character
// Post-condition: ascii value of alpha is output to screen
void ascii(const char ALPHA);

// Description: changes the case of input and outputs result to screen
// Pre-condition: alpha is an alphabetic character
// Post-condition: function changes case of alpha and outputs result to screen
void change_case(const char ALPHA);

// Description: outputs error message to screen
// Pre-condition: none
// Post-condition: error message is output to screen
void error_message();


int main()
{
  // Declarations
  bool quit, option1_chosen = false;
  char option, alpha;

  greeting();

  do
  {
    option = present_menu();
    quit = option_handler(option, alpha, option1_chosen);
  } while(!quit);

  goodbye();

  return 0;
}



/* Function Definitions */

void greeting()
{
  cout << "Hello! Welcome to the translator program. Type '1' to enter "
  << "a character and begin translating!" << endl;

  return;
}

char present_menu()
{
  // Declarations
  const short MIN_OPTION = 0, MAX_OPTION = 5;
  char option;

  do
  {
    // Menu
    cout << endl << "    TRANSLATE" << endl;
    cout << "    ---------" << endl << endl;
    cout << "1. Enter a character (alphabetic)" << endl;
    cout << "2. Morse code equivalent" << endl;
    cout << "3. ASCII value" << endl;
    cout << "4. Change case" << endl;
    cout << "5. Kwit" << endl;
  
    // Input Choice
    cout << "Option: ";
    cin >> option;
  } while(option < MIN_OPTION && option > MAX_OPTION);

  return option;
}

bool option_handler(const char OPTION, char& alpha, bool& option1_chosen)
{
  // Declarations 
  bool quit = false;

  switch(OPTION)
  {
    case '1':
      alpha = get_input_from_user();
      option1_chosen = true;
      break;
    case '2':
      if(option1_chosen)
      {
        morse(alpha);
      }
      else
      {
        error_message();
      }
      break;
    case '3':
      if(option1_chosen)
      {
        ascii(alpha);
      }
      else
      {
        error_message();
      }
      break;
    case '4':
      if(option1_chosen)
      {
        change_case(alpha);
      }
      else
      {
        error_message();
      }
      break;
    case '5':
      quit = true;
      break;
    default:
      cout <<endl<<"Error. You must enter a valid number from 1 to 5."<<endl;
  }

  return quit;
}

char get_input_from_user()
{
// Declarations 
char input;

  do
  {
    cout << "Enter a character: ";
    cin >> input;
  
    if(!isalpha(input))
    {
      cout << "Error! Please enter an alphabetic character" << endl;
    }
  } while(!isalpha(input));

  return input;
}

void morse(const char ALPHA)
{ 
  cout << endl;

  switch(tolower(ALPHA))
  {
    case 'a':
      cout << ".-" << endl;
      break;
    case 'b':
      cout << "-..." << endl;
      break;
    case 'c':
      cout << "-.-." << endl;
      break;
    case 'd':
      cout << "-.." << endl;
      break;
    case 'e':
      cout << "." << endl;
      break;
    case 'f':
      cout << "..-." << endl;
      break;
    case 'g':
      cout << "--." << endl;
      break;
    case 'h':
      cout << "...." << endl;
      break;
    case 'i':
      cout << ".." << endl;
      break;
    case 'j':
      cout << ".---" << endl;
      break;
    case 'k':
      cout << "-.-" << endl;
      break;
    case 'l':
      cout << ".-.." << endl;
      break;
    case 'm':
      cout << "--" << endl;
      break;
    case 'n':
      cout << "-." << endl;
      break;
    case 'o':
      cout << "---" << endl;
      break;
    case 'p':
      cout << ".--." << endl;
      break;
    case 'q':
      cout << "--.-" << endl;
      break;
    case 'r':
      cout << ".-." << endl;
      break;
    case 's':
      cout << "..." << endl;
      break;
    case 't':
      cout << "-" << endl;
      break;
    case 'u':
      cout << "..-" << endl;
      break;
    case 'v':
      cout << "...-" << endl;
      break;
    case 'w':
      cout << ".--" << endl;
      break;
    case 'x':
      cout << "-..-" << endl;
      break;
    case 'y':
      cout << "-.--" << endl;
      break;
    case 'z':
      cout << "--.." << endl;
      break;
  }

  return;
}

void ascii(const char ALPHA)
{
  cout << endl << short(ALPHA) << endl;

  return;
}

void change_case(const char ALPHA)
{
  cout << endl;

  if(islower(ALPHA))
  {
    cout << char(toupper(ALPHA)) << endl;
  }
  else
  {
    cout << char(tolower(ALPHA)) << endl;
  }

  return;
}

void error_message()
{
  cout << endl;
  cout <<"Error! You must first select choice '1' and enter a character"<<endl;

  return;
}

void goodbye()
{
  cout << "Thank you for using the translator. Have a nice day!" << endl;

  return;
}

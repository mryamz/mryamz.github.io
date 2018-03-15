/*
| -~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~ |
| FILE:              App.cpp:							 |
| Finds  Min and max of a city's regions   			     |
|														 |
| Date 2018-3-14										 |
| Version 1.0											 |
| Programmer Teddy Clapp         3-14-18				 |
| ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~|
*/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

#define VERSION "Ice Yamz Salad  | 10.12.17 - 10.15.17"

/* --------------------------------------------------------
FUNCTION:
performWelcomeScreen()
DESCRIPTION:
- prints a clone display of the cmd. It then waits for the user
to continue to the next screen.

RETURNS:
void
---------------------------------------------------------- */
void performWelcomeScreen();

/* --------------------------------------------------------
FUNCTION:
performMenuScreen()
DESCRIPTION:
- Shows a menu of 4 options. The user can enter
a number to perform one of the menu items. The
input is checked for validity.

RETURNS:
void
---------------------------------------------------------- */
void performMenuScreen();

/* --------------------------------------------------------
FUNCTION:
performEncryptScreen(char[])
DESCRIPTION:
- Warns the user of existing file names. Asks the user
for a file name. Asks the user for how many entries they
want to build for this file. The loop is performed and 
entries are put. A function then waits for the user to 
continue to the back to the menu.

- It is important to note that the alphabet lives in this scope
and it is required for many of the child function calls.

RETURNS:
void
---------------------------------------------------------- */
void performEncryptScreen(char alphabet[]);

/* --------------------------------------------------------
FUNCTION:
performEncryptScreen(char[])
DESCRIPTION:
- Shows a menu of 3 options. The user can enter
a number to perform one of the menu items. The
input is checked for validity. An alphabet array
is passed in so that it can pass it on to its
child functions.

RETURNS:
void
---------------------------------------------------------- */
void performDecryptScreen(char alphabet[]);

/* --------------------------------------------------------
FUNCTION:
performDecryptScreenOption1(char[], ofstream&)
DESCRIPTION:
- Shows a menu of 2 options. The user can enter
a number to perform one of the menu items. The
input is checked for validity. An alphabet array
is process if called. It's purpose was to accept
'a keyboard entered encoded phrase and key for decoding'
as requested by the rubric. It also logs the user's decryption
attempts by applying the caesar cypher algorithm.

RETURNS:
void
---------------------------------------------------------- */
void performDecryptScreenOption1(char alphabet[], std::ofstream& o_file);

/* --------------------------------------------------------
FUNCTION:
performDecryptScreenOption2(char[], ofstream&)
DESCRIPTION:
- Shows a menu of 2 options. The user can enter
a number to perform one of the menu items. The
input is checked for validity. An alphabet array
is process if called. This will print all the possible
solutions for a given plaintext by applying ceasar
cypher algorithms.

RETURNS:
void
---------------------------------------------------------- */
void performDecryptScreenOption2(char alphabet[], std::ofstream& o_file);

/* --------------------------------------------------------
FUNCTION:
performExitScreen()
DESCRIPTION:
- Thanks the user then prints stereotypical
hackerman text to console.

RETURNS:
void
---------------------------------------------------------- */
void performExitScreen();

/* --------------------------------------------------------
FUNCTION:
initializeAlphabet(char)
DESCRIPTION:
- initializes an array by setting values
in a forloop according to the ASCII table.

RETURNS:
void
---------------------------------------------------------- */
void initializeAlphabet(char alphabet[]);

/* --------------------------------------------------------
FUNCTION:
shiftAlphabet(char[], char[], int)
DESCRIPTION:
- formats the shift input to be a value betwixt
[0-26]. It also takes in an array that will be set
at an offset.

RETURNS:
void
---------------------------------------------------------- */
void shiftAlphabet(char alphabet_source[], char alphabet_destination[], int shift);

/* --------------------------------------------------------
FUNCTION:
waitForUser(string, int)
DESCRIPTION:
- prompts the user to enter zero
while telling the user where they 
are going via message parameter.

RETURNS:
void
---------------------------------------------------------- */
void waitForUser(std::string message, int screen);


int main() {
	performWelcomeScreen();
}

void performWelcomeScreen() {
	system("cls");
	std::cout << "Welcome to Hangman";
	std::cout << "   [Version: " << VERSION << "]" << std::endl;
	std::cout << "(c) 2017 Teddy Clapp. No Rights Reserved." << std::endl;

	waitForUser("'Menu'", 0);}

void performMenuScreen() {
	system("cls");
	std::cout << "Welcome to the Caeasar Cypher [Gold Windows Delux Edition]" << std::endl;
	std::cout << "  - Enter '1' to encrypt phrase" << std::endl;
	std::cout << "  - Enter '2' to decrypt phrase" << std::endl;
	std::cout << "  - Enter '3' to see welcome screen" << std::endl;
	std::cout << "  - Enter '4' to exit" << std::endl;

	static char alphabet[27];
	initializeAlphabet(alphabet);

	int option = 0;
	bool optionIsValid = true;
	do {
		std::cin >> option;
		optionIsValid = true;
		switch (option) {
		case 1:
			performEncryptScreen(alphabet);
			break;
		case 2:
			performDecryptScreen(alphabet);
			break;
		case 3:
			performWelcomeScreen();
			break;
		case 4:
			performExitScreen();
			break;
		default:
			optionIsValid = false;
			std::cout << "Invalid Option. Try again 1, 2, 3, or 4. You know the drill." << std::endl;
			break;
		}
	} while (!optionIsValid);
}

void performEncryptScreen(char alphabet[]) {
	system("cls");
	std::cout << "Here is your working directory with .eccf files?" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	system("dir /b *.eccf");
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Be careful not to overwrite on by mistake.?" << std::endl;

	bool isRunning = true;

	std::cout << "Firstly, enter a filename (this will be your [Encoded Caesar Cypher File] / [.eccf] file)." << std::endl;
	std::string filename;
	std::cin.ignore();
	getline(std::cin, filename);
	std::ofstream out(filename + "_Caesar.eccf");

	std::cout << "How many entries do you want?" << std::endl;
	int count;
	std::cin >> count;
	std::cout << "Okay, " << count << (count == 1 ? " time" : " times") << "!" << std::endl;

	for (int trial = 0; trial < count; trial++) {
		std::cout << "\nEnter a plaintext (include only lowercase letters and spaces)" << std::endl;
		std::string plaintext;
		std::cin.ignore();
		getline(std::cin, plaintext);
		std::cout << "Now, enter a shift value." << std::endl;
		int shift;
		std::cin >> shift;
		char shiftedAlphabet[27];
		shiftAlphabet(alphabet, shiftedAlphabet, shift);

		std::cout << "The cyphertext is: " << std::endl;
		for (int i = 0; i < plaintext.length(); i++) {
			for (int j = 0; j < 27; j++) {
				if (plaintext[i] == alphabet[j]) {
					std::cout << shiftedAlphabet[j];
					if (shiftedAlphabet[j] == ' ') {
						out << "_";
					} else {
						out << shiftedAlphabet[j];
					}
				}
			}
		}
		out << " " << shift << std::endl;
	}
	waitForUser("'Menu'", 0);
}

void performDecryptScreen(char alphabet[]){
	system("cls");
	std::cout << "Welcome to the Caesar Cypher Decrypter (we automatically write your decodings to Decryption.dccf)" << std::endl;
	std::cout << "- The file extension [.dccf] stands for [Decoded Caesar Cypter File]" << std::endl;
	std::cout << "- Enter 1 or 2 for what you'd like todo" << std::endl;
	std::cout << "   1) A keyboard entered ciphertext and key (shift value) for decoding" << std::endl;
	std::cout << "   2) Decode an (Encoded Caesar Cypter File) or .eccf" << std::endl;
	std::cout << "   3) Return to menu" << std::endl;

	std::ofstream decodeLog("Decryption.dccf", std::ios_base::app);

	int option;
	do {
		std::cin >> option;
		switch (option) {
		case 1:
			performDecryptScreenOption1(alphabet, decodeLog);
			break;
		case 2:
			performDecryptScreenOption2(alphabet, decodeLog);
			break;
		case 3:
			performMenuScreen();
			break;
		default:
			std::cout << "Wrong. Enter 1 or 2." << std::endl;
			break;
		}
	} while (!(option == 1 || option == 2));
	
}

void performDecryptScreenOption1(char alphabet[], std::ofstream& decodeLog) {
	system("cls");
	std::cout << "Enter a ciphertext (include only lowercase letters and spaces)" << std::endl;
	std::string ciphertext;
	std::cin.ignore();
	getline(std::cin, ciphertext);

	std::cout << "What would you like todo with ciphertext: " << ciphertext << std::endl;
	std::cout << "   press '1' to test a user defined solution" << std::endl;
	std::cout << "   press '2' to find all possible solutions" << std::endl;

	int choice;
	std::cin >> choice;
	while (!(choice == 1 || choice == 2)) {
		std::cout << "Invalid Option. [Hint] enter '1' or '2'" << std::endl;
		std::cin >> choice;
	}

	if (choice == 1) {
		std::cout << "Now, enter a shift value." << std::endl;
		int shift;
		std::cin >> shift;
		char shiftedAlphabet[27];
		shiftAlphabet(alphabet, shiftedAlphabet, shift);

		std::cout << "The decoded text is: " << std::endl;
		for (int i = 0; i < ciphertext.length(); i++) {
			for (int j = 0; j < 27; j++) {
				if (ciphertext[i] == alphabet[j]) {
					std::cout << shiftedAlphabet[j];
					if (shiftedAlphabet[j] == ' ') {
						decodeLog << "_";
					} else {
						decodeLog << shiftedAlphabet[j];
					}
				}
			}
		}

		decodeLog << " " << shift << std::endl;
	}

	if (choice == 2) {
		std::cout << "Finding all solutions..." << std::endl;
		std::cout << "Solution Set=" << " {\n" << std::endl;
		for (int shift = 0; shift < 27; shift++) {
			char shiftedAlphabet[27];
			shiftAlphabet(alphabet, shiftedAlphabet, shift);
			std::cout <<  "[Shift: " << shift << "]  ";
			for (int i = 0; i < ciphertext.length(); i++) {
				for (int j = 0; j < 27; j++) {
					if (ciphertext[i] == alphabet[j]) {
						std::cout << shiftedAlphabet[j];
						if (shiftedAlphabet[j] == ' ') {
							decodeLog << "_";
						} else {
							decodeLog << shiftedAlphabet[j];
						}
					}
				}
			}
			decodeLog << " " << shift << std::endl;
			std::cout << std::endl;
		}
		std::cout << "}" << std::endl;
	}

	std::cout << std::endl << "Enter -1 to Continue to go back" << "..." << std::endl;

	choice = 0;
	std::cin >> choice;
	while (choice != -1) {
		std::cout << "Invalid Option. [Hint] Try -1, it's the only Option." << std::endl;
		std::cin >> choice;
	}
	performDecryptScreen(alphabet);
}

void performDecryptScreenOption2(char alphabet[], std::ofstream& decodeLog) {
	system("cls");
	std::cout << "Here is your working directory with .eccf files?" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	system("dir /b *.eccf");
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Enter the one you want to decode? (exclude the file extension, we'll save you the typing.)" << std::endl;
	std::ifstream readLog;
	std::string name;
	do {
		std::cin >> name;
		readLog.open(name + ".eccf");
	} while (!readLog);

	char mrshify[27];
	while (!readLog.eof()) {
		std::string ciphertext;
		readLog >> ciphertext;
		int shift;
		readLog >> shift;

		shiftAlphabet(alphabet, mrshify, -shift);
		std::cout << "Ciphertext: " + ciphertext << ", Answer: ";
		for (int i = 0; i < ciphertext.length(); i++) {
			for (int j = 0; j < 27; j++) {
				if (ciphertext[i] == alphabet[j]) {
					std::cout << mrshify[j];
					if (mrshify[j] == ' ') {
						decodeLog << "_";
					}
					else {
						decodeLog << mrshify[j];
					}
				}
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter -1 to Continue to go back" << "..." << std::endl;
	int choice = 0;
	std::cin >> choice;
	while (choice != -1) {
		std::cout << "Invalid Option. [Hint] Try -1, it's the only Option." << std::endl;
		std::cin >> choice;
	}
	performDecryptScreen(alphabet);
}

void performExitScreen() {
	std::cout << "Thanks for playing!" << std::endl;
	std::cout << "Enter 0 to Exit..." << std::endl;
	system("color 04");
	for (int i = 0; i < 15000; i++) {
		std::cout << (char) rand();
	}
}

void initializeAlphabet(char alphabet[]) {
	alphabet[0] = 32;
	for (int i = 1; i < 27; i++) {
		alphabet[i] = i + 97 - 1;
	}
}

void shiftAlphabet(char alphabet_source[], char alphabet_destination[], int shift) {
	shift %= 27;
	if (shift < 0) {
		shift = 27 - abs(shift);
	}
	for (int i = 0; i < 27; i++) {
		alphabet_destination[i] = alphabet_source[(i + shift) % 27];
	}
}

void waitForUser(std::string message, int screen) {
	std::cout << std::endl << "Enter 0 to Continue to " << message << "..." << std::endl;

	int choice = -1;
	std::cin >> choice;
	while (choice != 0) {
		std::cout << "Invalid Option. [Hint] Try 0, it's the only Option." << std::endl;
		std::cin >> choice;
	}

	switch (screen) {
	case 0:
		performMenuScreen();
		break;
	default:
		std::cout << "wrong. " << screen << ", is an invalid argument." << std::endl;
		break;
	}
}

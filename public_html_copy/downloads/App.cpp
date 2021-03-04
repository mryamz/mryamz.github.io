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

// does nothing
void stub1();

// does nothing
void stub2();


int main() {
	performWelcomeScreen();
}

void performWelcomeScreen() {
	// print welcome screen
	system("cls");
	std::cout << "Welcome to Encryptomaticmigee";
	std::cout << "   [Version: " << VERSION << "]" << std::endl;
	std::cout << "(c) 2018 Teddy Clapp. No Rights Reserved." << std::endl;

	// call this to wait for user's input
	waitForUser("'Menu'", 0);}

void performMenuScreen() {
	// print the menu to the user
	system("cls");
	std::cout << "Welcome to the Caeasar Cypher [Gold Windows Delux Edition]" << std::endl;
	std::cout << "  - Enter '1' to encrypt phrase to file" << std::endl;
	std::cout << "  - Enter '2' to decrypt phrase to file + (Encrypt/Decrypt with no file I/O)" << std::endl;
	std::cout << "  - Enter '3' to see welcome screen" << std::endl;
	std::cout << "  - Enter '4' to exit" << std::endl;
	std::cout << "  - Enter '5' stub 1" << std::endl;
	std::cout << "  - Enter '6' stub 2" << std::endl;

	// create a character set to use later, for ceasar related proccesses
	static char alphabet[27];
	initializeAlphabet(alphabet);

	// ask the user to select an option, then execute depending on user's inputed option.
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
		case 5:
			stub1();
			break;
		case 6:
			stub2();
			break;
		default:
			optionIsValid = false;
			std::cout << "Invalid Option. Try again 1, 2, 3, or 4... You know the drill." << std::endl;
			break;
		}
	} while (!optionIsValid);
}

void performEncryptScreen(char alphabet[]) {
	// prompt the user of existing files and a warning not to overwrite them.
	system("cls");
	std::cout << "Here is your working directory with .eccf files?" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	system("dir /b *.eccf");
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Be careful not to overwrite on by mistake.?" << std::endl;


	// prompt user to enter a file name
	std::cout << "Firstly, enter a filename (this will be your [Encoded Caesar Cypher File] / [.eccf] file)." << std::endl;
	std::string filename;
	std::cin.ignore();
	getline(std::cin, filename);
	// build outstream with a hardcoded appension
	std::ofstream out(filename + "_Caesar.eccf");

	// ask how many entries the file will need.
	std::cout << "How many entries do you want?" << std::endl;
	int count;
	std::cin >> count;
	// user tenary for handling plurals (grammar)
	std::cout << "Okay, " << count << (count == 1 ? " time" : " times") << "!" << std::endl;

	// start loop to build user defined file
	for (int trial = 0; trial < count; trial++) {
		// Ask user for the phrase to be encrypted
		std::cout << "\nEnter a plaintext (include only lowercase letters and spaces)" << std::endl;
		std::string plaintext;
		std::cin.ignore();
		getline(std::cin, plaintext);
		// Ask user for shift value
		std::cout << "Now, enter a shift value." << std::endl;
		int shift;
		std::cin >> shift;
		char shiftedAlphabet[27];
		// build shifted alphabet from requested user data
		shiftAlphabet(alphabet, shiftedAlphabet, shift);

		// display the cyphertext to user while logging it to a file
		std::cout << "The cyphertext is: " << std::endl;
		for (int i = 0; i < plaintext.length(); i++) {
			for (int j = 0; j < 27; j++) {
				if (plaintext[i] == alphabet[j]) {
					std::cout << shiftedAlphabet[j];
					// change spaces to underscores so that the data can be easily parsed when decrypting file
					if (shiftedAlphabet[j] == ' ') {
						out << "_";
					} else {
						out << shiftedAlphabet[j];
					}
				}
			}
		}
		// place the shift value by the cyphertext so the file has the structure: fggt 5
		out << " " << shift << std::endl;
	}
	// wait for user input then bolt to menu.
	waitForUser("'Menu'", 0);
}

void performDecryptScreen(char alphabet[]){
	// prompt user for how to use the decryt mode
	system("cls");
	std::cout << "Welcome to the Caesar Cypher Decrypter (we automatically write your decodings to Decryption.dccf)" << std::endl;
	std::cout << "- The file extension [.dccf] stands for [Decoded Caesar Cypter File]" << std::endl;
	std::cout << "- Enter 1, 2 or 3 for what you'd like todo" << std::endl;
	std::cout << "   1) A keyboard entered ciphertext and key (shift value) for decoding" << std::endl;
	std::cout << "   2) Decode an (Encoded Caesar Cypter File) or .eccf" << std::endl;
	std::cout << "   3) Return to menu" << std::endl;

	// build log relative to app's dir (note: destructor will close ofstream upon end of scope)
	std::ofstream decodeLog("Decryption.dccf", std::ios_base::app);

	// allow user to access menu by asking for input
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
		// exit loop when a right option is pressed
	} while (!(option == 1 || option == 2 || option == 3));
	
}

void performDecryptScreenOption1(char alphabet[], std::ofstream& decodeLog) {
	// prompt the user for un logged encryption/decryption
	system("cls");
	std::cout << "Enter a ciphertext/plaintext (include only lowercase letters and spaces)" << std::endl;
	std::string ciphertext;
	std::cin.ignore();
	getline(std::cin, ciphertext);

	// prompt the user for two option
	std::cout << "What would you like todo with ciphertext: " << ciphertext << std::endl;
	std::cout << "   press '1' to test a user defined solution (test 1 shift value)" << std::endl;
	std::cout << "   press '2' to find all possible solutions (test all shift values)" << std::endl;

	// figure out what the user wants
	int choice;
	std::cin >> choice;
	while (!(choice == 1 || choice == 2)) {
		std::cout << "Invalid Option. [Hint] enter '1' or '2'" << std::endl;
		std::cin >> choice;
	}

	// test 1 user defined shift value
	if (choice == 1) {
		std::cout << "Now, enter a shift value." << std::endl;
		int shift;
		std::cin >> shift;
		char shiftedAlphabet[27];
		// build our shifted alphabet
		shiftAlphabet(alphabet, shiftedAlphabet, shift);

		// find our answer by looking up text against the shifted alphabet
		std::cout << "The decoded text is: " << std::endl;
		for (int i = 0; i < ciphertext.length(); i++) {
			for (int j = 0; j < 27; j++) {
				// we found a match
				if (ciphertext[i] == alphabet[j]) {
					// print answer to screen by user the shifted alphabet
					std::cout << shiftedAlphabet[j];
					if (shiftedAlphabet[j] == ' ') {
						// log spaces as underscores to file
						decodeLog << "_";
					} else {
						decodeLog << shiftedAlphabet[j];
					}
				}
			}
		}
		// put spaces here to satisfy the aforemetioned file format
		decodeLog << " " << shift << std::endl;
	}

	// test all possible shift values
	if (choice == 2) {
		std::cout << "Finding all solutions..." << std::endl;
		// print this to make look similar to a json format
		std::cout << "Solution Set=" << " {\n" << std::endl;
		// this will give us all possible shift values to work with
		for (int shift = 0; shift < 27; shift++) {
			char shiftedAlphabet[27];
			shiftAlphabet(alphabet, shiftedAlphabet, shift);
			std::cout <<  "[Shift: " << shift << "]  ";
			// this works exactly as in test 1 and should be built into another method to help dry up the code
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
		// used to print a psudo-json format
		std::cout << "}" << std::endl;
	}

	// prompt user to go back after they are done looking at the results
	std::cout << std::endl << "Enter -1 to Continue to go back" << "..." << std::endl;

	choice = 0;
	std::cin >> choice;
	while (choice != -1) {
		std::cout << "Invalid Option. [Hint] Try -1, it's the only Option." << std::endl;
		std::cin >> choice;
	}
	// change back to previous state
	performDecryptScreen(alphabet);
}

void performDecryptScreenOption2(char alphabet[], std::ofstream& decodeLog) {
	// print a prompt to the user for how to use this screen
	system("cls");
	std::cout << "Here is your working directory with .eccf files?" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	system("dir /b *.eccf");
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Enter the one you want to decode? (exclude the file extension, we'll save you the typing.)" << std::endl;
	std::ifstream readLog;
	std::string name;
	// keeps asking the user for file name that is valid such that this method can decrypt it later this call
	do {
		std::cin >> name;
		readLog.open(name + ".eccf");
	} while (!readLog);

	// 'mrshifty' is someone who represents data to be that of a shifted alphabet A-Z+' '
	char mrshify[27];
	while (!readLog.eof()) {
		// grab our cipher text
		std::string ciphertext;
		readLog >> ciphertext;

		// grab our shift value
		int shift;
		readLog >> shift;

		// build mrshifty to be what he aspires to be.
		shiftAlphabet(alphabet, mrshify, -shift);

		// print our cipher text
		std::cout << "Ciphertext: " + ciphertext << ", Answer: ";
		for (int i = 0; i < ciphertext.length(); i++) {
			for (int j = 0; j < 27; j++) {
				// found match
				if (ciphertext[i] == alphabet[j]) {
					// print result
					std::cout << mrshify[j];

					// log result with spaces as underscores
					if (mrshify[j] == ' ') {
						decodeLog << "_";
					}
					else {
						decodeLog << mrshify[j];
					}
				}
			}
		}
		// new line for pleasing UX
		std::cout << std::endl;
	}

	// go back by typing a number, the number, -1!
	// the user may to this after they soak up all the console output.
	std::cout << std::endl << "Enter -1 to Continue to go back" << "..." << std::endl;
	int choice = 0;
	std::cin >> choice;
	while (choice != -1) {
		std::cout << "Invalid Option. [Hint] Try -1, it's the only Option." << std::endl;
		std::cin >> choice;
	}
	// jump back into performDecryptScreen
	performDecryptScreen(alphabet);
}

void performExitScreen() {
	// salutes the user and thanks
	std::cout << "Thanks for playing!" << std::endl;
	std::cout << "Enter 0 to Exit..." << std::endl;
	// prints error like message to the screen. Sideways red matrix screen
	system("color 04");
	for (int i = 0; i < 15000; i++) {
		std::cout << (char) rand();
	}
}

void initializeAlphabet(char alphabet[]) {
	// builds the A-Z + space alphabet by useing ASCII charset
	alphabet[0] = 32;
	for (int i = 1; i < 27; i++) {
		alphabet[i] = i + 97 - 1;
	}
}

void shiftAlphabet(char alphabet_source[], char alphabet_destination[], int shift) {
	// shifts a normal alphabet

	// format large numbers to a coterminal range between 0 to 26
	shift %= 27;
	if (shift < 0) {
		shift = 27 - abs(shift);
	}

	// then shift this data by the formated shift value
	for (int i = 0; i < 27; i++) {
		alphabet_destination[i] = alphabet_source[(i + shift) % 27];
	}
}

void waitForUser(std::string message, int screen) {
	// allows a programmer to direct the user to different states of game
	std::cout << std::endl << "Enter 0 to Continue to " << message << "..." << std::endl;

	// checks for the user input
	int choice = -1;
	std::cin >> choice;

	// validates user input
	while (choice != 0) {
		std::cout << "Invalid Option. [Hint] Try 0, it's the only Option." << std::endl;
		std::cin >> choice;
	}

	// only supports option to bolt to menu but functionallity can be extended
	switch (screen) {
	case 0:
		performMenuScreen();
		break;
	default:
		std::cout << "wrong. " << screen << ", is an invalid argument." << std::endl;
		break;
	}
}

// does nothing
void stub1()
{
}

// does nothing
void stub2()
{
}

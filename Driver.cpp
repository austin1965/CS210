// Dependencies
#include <fstream>
#include <vector>
#include <iomanip>
#include "ItemSold.h"

// Global variables
PythonWrapper python; // Call python


/*
 * Description: Print to the terminal the user's menu options.
 * Input / Parameters: None.
 * Output / Return: No explicit return. Prints menu options to the screen.
 */
void PrintMenu() {
	cout << "1 - Output cumulative purchase frequency list." << endl;
	cout << "2 - Output specified item purchase frequency." << endl;
	cout << "3 - Output cumulative purchase frequency histogram." << endl;
	cout << "4 - Exit Program." << endl;
}

/*
 * Description: Function for error checking user values.
 * Input / Parameters: No explicit parameters. User inputs values at runtime.
 * Output / Return: The error checked menu selection.
 */
int GetMenuInput() {
	// Declarations
	string inputValue;
	bool gettingInput = true;

	// Loop while error checking.
	while (gettingInput) {
		try {
			// Take input
			cout << "Selection: ";
			cin >> inputValue;

			// Error check. If in accepted value range, end getting input, else output error message.
			if (inputValue == "1" || inputValue == "2" || inputValue == "3" || inputValue == "4") {
				gettingInput = false;
			}
			else {
				throw runtime_error("Invalid input");
			}
		}
		catch (exception excpt) {
			cout << excpt.what() << endl;
		}
	}

	// Return cast input.
	return stoi(inputValue);
}

/*
 * Description: Used to read in frequency data calculated by Python.
 * Input / Parameters: Vector to hold items sold objects.
 * Output / Return: Output a populated vector of items sold, or an error message if file could not open.
 */
void ReadFrequencyFile(vector<ItemSold> &fileItems) {
	// Declarations
	ifstream fileIn;
	string tempName;
	int tempFreq;
	ItemSold tempItem;

	// Open file with item sold frequency data.
	fileIn.open("frequency.dat");

	// Check if file could be opened
	if (!fileIn.is_open()) {
		cout << "Could not open file" << endl;
	}

	// If file could be opened, fill populate data structure for items sold
	else {
		while (!fileIn.eof()) {
			fileIn >> tempName;
			fileIn >> tempFreq;

			tempItem.setItemName(tempName);
			tempItem.setNumSold(tempFreq);

			fileItems.push_back(tempItem);
		}

		// File cleanup.
		fileIn.close();
	}
}

/*
 * Description: Used to make histogram of list of items sold input to python and output to frequency file.
 * Input / Parameters: No explicit parameters, reads in values from sold items file via python and reads in frequency data
						output by python.
 * Output / Return: No explicit return. Creates a histogram in the terminal.
 */
void CreateHistogram() {
	// Declaration
	vector<ItemSold> items;

	// Retrieve data.
	python.CallProcedure("write_data_file");
	ReadFrequencyFile(items);

	// Output histogram
	cout << endl;
	for (unsigned int i = 0; i < items.size(); ++i) {
		cout << setw(20) << right <<items.at(i).getItemName() << " ";

		for (int j = 0; j < items.at(i).getNumSold(); ++j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

}

// Program driver
int main()
{
	// Declarations
	bool usingProgram = true;
	int userResponse;
	string userWord;

	// Main program loop.
	while (usingProgram) {

		PrintMenu();
		userResponse = GetMenuInput();

		// Determine route of program based on user input. 
		switch (userResponse) {
			case 1: // Output cumulative purchase frequency list
				python.CallProcedure("output_file_dict");
				break;
			case 2: // Output specified item purchase frequency
				cout << "Provide search word: ";
				cin >> userWord;
				cout << endl << "Number of results for '"<< userWord <<"': " << python.callIntFunc("output_word_freq", userWord) << endl << endl;
				break;
			case 3: // Output cumulative purchase frequency histogram
				CreateHistogram();
				break;
			case 4: // Exit program
				usingProgram = false;
				break;
		}
	}
	
	cout << endl << "Program ending..." << endl;
	return 0;
}
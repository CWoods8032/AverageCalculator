#include <iostream>
#include <string>

using namespace std;

//Function to calculate the average of numbers
double calculateAverage(int sum, int count) {
	// Check if the count of valid numbers is zero
	if (count == 0) {
		throw std::invalid_argument("Cannot calculate average: No valid numbers found");
	}
	return static_cast<double>(sum) / count; // Calculate and return the average
}

int main() {
	cout << "Welcome to the Average Calculator from File!" << endl;
	cout << "You can enter a series of numbers to calculate their average." << endl;
	cout << "Type 'done' when you are finished entering numbers." << endl;
	
	string input; // Variable to store user input
	int number; // Variable to store valid numbers
	int sum = 0; // Variable to accumulate the sum of valid numbers
	int count = 0; // Variable to count valid numbers
	bool isDone = false; // Flag to indicate when input is finished

	// Loop to read user input until the user types 'done'
	while (!isDone) {
		cout << "Enter a number (or 'done' to finish): ";
		cin >> input;

		// Check if the user wants to finish inputting numbers
		if (input == "done") {
			isDone = true; // Set the flag to true to exit the loop
		}
		else {
			try {
				// Attempt to convert the input to an integer
				number = stoi(input); // Convert string input to an integer
				sum += number; // Add the valid number to the sum
				count++; // Increment the count of valid numbers
			}
			catch (const std::invalid_argument& e) {
				// Handle invalid_argument exception for non-numeric input
				cout << "Error: Invalid input. Please enter a valid integer." << endl;
			}
			catch (const std::out_of_range& e) {
				// Handle out_of_range exception for numbers too large to fit in an int
				cout << "Error: Number is out of range. Please enter a smaller number." << endl;
			}
		}
	}

	// Try to calculate the average of the entered numbers
	try {
		double average = calculateAverage(sum, count);
		cout << "The average is: " << average << endl; // Output the average
	}
	catch (const std::invalid_argument& e) {
		// Handle the exception if no valid numbers were provided
		cout << "Error: " << e.what() << endl; // Display error message
	}

	cout << "Thank you for using the Average Calculator!" << endl; // Closing message
	return 0; // Indicate successful completion
}

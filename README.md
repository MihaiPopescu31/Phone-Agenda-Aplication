# Phone Agenda Application
Phone Agenda Application in C++

Phone Agenda is a simple C++ application for managing contacts. It allows users to add contacts with details such as name, age, address, and phone number. Users can also search for contacts by name.

## Features

Add new contacts with name, age, address, and phone number.
Search for contacts by name.
Save contacts to a file for future reference.

## Dependencies

- C++ compiler (e.g., g++, clang++)
- Standard Template Library (STL)
## Getting Started

To get started with Budget Tracker, follow these steps:

1. Clone the repository to your local machine git clone https://github.com/MihaiPopescu31/Phone-Agenda-Application.git

2. Compile the source code files using a C++ compiler.

3. Run the executable file generated to launch the Phone Agenda application.

## Usage

When the application starts, you will be presented with a menu to add contacts, search contacts, or exit the application.
![image](https://github.com/MihaiPopescu31/Phone-Agenda-Aplication/assets/138394009/d33288fd-483c-4ab2-bfde-e76ced78f5e7)

To add a new contact, choose option 1 and follow the prompts to enter the contact details.
![image](https://github.com/MihaiPopescu31/Phone-Agenda-Aplication/assets/138394009/ec2478cf-71af-4b15-8b2c-437fba081baa)

To search for a contact by name, choose option 2 and enter the search query.
![image](https://github.com/MihaiPopescu31/Phone-Agenda-Aplication/assets/138394009/b336e0e8-29dc-4045-bbba-e5246f180395)

To exit the application, choose option 3.

## Code Explanation
In this section, we'll briefly explain the key functions and components of the Phone Agenda application:

- saveContactsToFile(const string& filename, const vector<Contact>& contacts): This function saves the contacts to a text file named data.txt. It iterates through the vector of contacts and writes each contact's details to the file.

- searchInFile(const string& filename, const string& searchQuery): This function searches for contacts in the data.txt file based on the provided search query (name). It reads each line from the file, compares it with the search query, and prints the matching contacts.

- main(): The main function of the application contains the menu loop where users can choose different options (add contact, search contact, exit). It also handles user input and calls the appropriate functions based on the selected option.

## Find a bug
If you found an issue or would like to submit an improvement to this project, please contact me.

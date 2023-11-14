#include <fstream> // File stream operations
#include <vector>  // Dynamic array container
#include <string>  // String manipulation
#include <regex>   // Regular expressions
#include <conio.h> // Text-based console input/output
#include <limits>  // Limits of fundamental data types
#include <chrono>  // Time-related functionality
using namespace std;
// Function to validate an integer if it is within the requird range.
bool isValidInt(int value, int min, int max)
{
    return value >= min && value <= max;
}
// Function to get age value;
int getAge(int min = 16, int max = 35)
{
    int age = min - 1;
    // This loop continues until a valid age num is entered.
    while (!isValidInt(age, min, max))
    {
        cout << " ENTER AGE (" << min << "-" << max << "):  ";
        cin >> age;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return age;
}
// Function to get a valid requird user choice from the options provided.
int getChoice(void (*function)(), int max)
{
    int choice = 0;
    // This loop continues until a valid choice is entered.
    while (!isValidInt(choice, 1, max))
    {
        // Calls the function to display the valid options for the user.
        function();
        // Prompts the user to enter their choice.
        cout << "\n ENTER YOUR CHOICE:   ";
        cin >> choice;
        // Clears the error flag if the input is not an integer.
        cin.clear();
        // Ignores any remaining characters in the input buffer, up to '\n'.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Returns the valid choice entered by the user.
    return choice;
}
// Function to get a valid requird user choice from the options provided.
int getCategoryChoice(
    void (*function)(vector<string>), int max, const vector<string> useThis = vector<string>())
{
    // Choice set to zer0 so that the while loop, gets executed.
    int choice = 0;
    // This loop continues until a valid choice is entered.
    while (!isValidInt(choice, 1, max))
    {
        function(useThis);
        // Calls the function do display the valid options to make a choice from.
        cout << "\n ENTER YOUR CHOICE:   ";
        cin >> choice;
        // Clears the error flag if the input is not an integer.
        cin.clear();
        // Ignores any remaining characters in the input buffer, up to '\n'.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}
// Function to change a string to UPPER Or lower CASE.
string upperCase(string charecter, bool convert = true)
{
    if (convert)
        for (char &converted : charecter)
            converted = std::toupper(converted);
    else
        for (char &converted : charecter)
            converted = tolower(converted);
    return charecter;
}

// Function for getting value from the user input form.
string userInput(string label, bool isPassword = false)
{
    // A: If not entering the password.
    cout << label;
    if (!isPassword)
    {
        string value = "";
        getline(cin, value);

        return upperCase(value);
    }
    // B: When entering the password.
    else
    {
        // Declare a character array to store the password. The size is set to 24, meaning the password can be up to 23 characters long (plus null terminator).
        char password[24];
        // Declare a character variable to store the current input character.
        char eachCharacter;
        // Initialize a variable 'currentPosition' to keep track of the current position in the password array.
        int currentPosition = 0;
        // Infinite loop to keep reading characters until the user presses Enter(13) (ASCII 13) or on Mobile touch screens.
        while (1)
        {
            // Read a character without displaying it on the screen.
            eachCharacter = _getch();
            // Check if the Enter key is pressed, indicating the end of password input.
            if (eachCharacter == 13)
                break;
            // Check if the Backspace(8) key is pressed to erase the previous typed character.
            else if (eachCharacter == 8)
            {
                if (currentPosition > 0)
                {
                    currentPosition--;
                    // Move the cursor back and erase the character by printing a space and moving the cursor back again.
                    cout << "\b \b";
                }
            }
            else
            {
                // Store the current character in the password array.
                password[currentPosition] = eachCharacter;
                currentPosition++;
                // Print an asterisk (*) instead of the actual character for security reasons.
                cout << '*';
            }
        }
        // Null-terminate the password string.
        password[currentPosition] = '\0';
        // Return the entered password.
        return password;
    }
}
// Function to merge two strings and form a ("key":"value") pair string.
string formKeyValue(string key, string value)
{
    const string FORMED = "\"" + upperCase(key) + "\":\"" + value + "\"";
    return FORMED;
}
// Function for managing file operations (read/get, write/add, find/search/contains, empty/clear).
vector<string> manageFile(string method, string fileName, string content = "")
{
    string action = upperCase(method);
    vector<string> values;
    // For adding the content to be contained inside the .txt file.
    if (!action.compare("ADD") || !action.compare("WRITE"))
    {
        fstream FILE;
        FILE.open(fileName, ios::app);
        if (FILE.is_open())
        {
            FILE << content << endl;
            FILE.close();
        }
        return values;
    }
    else if (!action.compare("GET") || !action.compare("READ"))
    {
        // For getting the contained items in a .txt file.
        fstream FILE;
        FILE.open(fileName, ios::in);
        if (FILE.is_open())
        {
            string eachLine;
            while (getline(FILE, eachLine))
            {
                values.push_back(eachLine);
            }
            FILE.close();
        }
        return values;
    }
    else if (action == "FIND" || action == "SEARCH" || action == "CONTAINS")
    {
        // Used for finding a specific text inside a .txt file.
        vector<string> items = manageFile("get", fileName);
        for (string item : items)
        {
            if (item.find(content) != -1)
            {
                values.push_back(item);
            }
        }
        return values;
    }
    else if (action == "EMPTY" || action == "CLEAR")
    {
        fstream FILE;
        FILE.open(fileName, ios::out | ios::trunc);
        if (FILE.is_open())
        {
            FILE.close();
        }
        return values;
    }
    else
    {
        // Returns an empty array.
        return values;
    }
}
// Function to form a string current date and return it as a string.
string currentDate()
{
    // Get the current time.
    auto now = chrono::system_clock::now();
    // Convert the current time to seconds since 1900.
    time_t time = chrono::system_clock::to_time_t(now);
    // Convert the time to a local time structure.
    tm *timeInfo = localtime(&time);
    // Extract the current year, month, and day.
    int currentYear = (timeInfo->tm_year + 1900);
    int currentMonth = (timeInfo->tm_mon + 1);
    int currentDate = (timeInfo->tm_mday);
    // Return the date as a string in the format "day/month/year".
    return to_string(currentDate) + "/" + to_string(currentMonth) + "/" + to_string(currentYear);
}
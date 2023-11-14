#include <string>
using namespace std;
// Display the name of the innovation hub
void displayHubName()
{
    cout << " Z - H U B   I N N O V A T I O N S \n\n";
}
// Display the login or sign-up options for different roles
void displayRoleOptions()
{
    cout << " LOGIN AS HUB:  ";
    cout << "\n\n 1 - MANAGER";
    cout << "\n 2 - COORDINATOR";
    cout << "\n 3 - TECHNICIAN";
    cout << "\n     OR";
    cout << "\n 4 - SIGN UP";
}
// Display main menu options for the main user
void displayMainUserPermissionsOptions()
{
    cout << "\n M A I N   M E N U\n";
    cout << "\n 1 - ADD INNOVATOR";
    cout << "\n 2 - DELETE INNOVATOR RECORD";
    cout << "\n 3 - SEARCH FOR INNOVATOR";
    cout << "\n 4 - EDIT INNOVATOR RECORD";
    cout << "\n 5 - DISPLAY INNOVATOR BY INNOVATION CATEGORY";
    cout << "\n 6 - EXIT";
}
// Display main menu options for sub-users
void displaySubUserPermissionsOptions()
{
    cout << "\n M A I N   M E N U\n";
    cout << "\n 1 - SEARCH FOR INNOVATOR";
    cout << "\n 2 - EXIT";
}
// Display options for taking action with NRC or Passport
void displayNRCOrPassportOptions()
{
    cout << "\n T A K E   A C T I O N   W I T H ";
    cout << "\n 1 - NRC No";
    cout << "\n 2 - PASSPORT No";
    cout << "\n     OR";
    cout << "\n 3 - MAIN MENU";
}
// Display options for searching again
void displaySearchAgainOptions()
{
    cout << "\n 1 - SEARCH AGAIN ";
    cout << "\n     OR";
    cout << "\n 2 - MAIN MENU ";
}
// Display options for deleting again
void displayDeleteAgainOptions()
{
    cout << "\n 1 - DELETE AGAIN ";
    cout << "\n     OR";
    cout << "\n 2 - MAIN MENU ";
}
// Display options for adding again
void displayAddAgainOptions()
{
    cout << "\n 1 - ADD AGAIN ";
    cout << "\n     OR";
    cout << "\n 2 - MAIN MENU ";
}
// Display options for editing again
void displayEditAgainOptions()
{
    cout << "\n 1 - EDIT AGAIN ";
    cout << "\n     OR";
    cout << "\n 2 - MAIN MENU ";
}
// Display options for displaying again
void displayDisplayAgainOptions()
{
    cout << "\n 1 - DISPLAY AGAIN ";
    cout << "\n     OR";
    cout << "\n 2 - MAIN MENU ";
}
// Display options for searching to edit
void displaySearchToEditOptions()
{
    cout << "\n E D I T   I N N O V A T O R";
    cout << "\n 1 - SEARCH INNOVATOR TO EDIT ";
    cout << "\n     OR";
    cout << "\n 2 - MAIN MENU ";
}
// Display options for deleting an innovator
void displayDeleteInnovatorOption()
{
    cout << "\n D E L E T E   I N N O V A T O R";
    cout << "\n 1 - SEARCH INNOVATOR TO DELETE ";
    cout << "\n     OR";
    cout << "\n 2 - MAIN MENU ";
}
// Display options for selecting what to edit
void displayOptionsToEdit()
{
    cout << "\n W H A T   D O   Y O U   W A N T   T O   E D I T";
    cout << "\n 1 - NRC No.";
    cout << "\n 2 - PASSPORT No.";
    cout << "\n 3 - FIRSTNAME. ";
    cout << "\n 4 - LASTNAME. ";
    cout << "\n 5 - AGE. ";
    cout << "\n 6 - TITLE OF INNOVATION. ";
    cout << "\n 7 - PATENT STATUS. ";
    cout << "\n 8 - INNOVATION CATEGORY. ";
    cout << "\n     OR";
    cout << "\n 9 - MAIN MENU ";
}
// Get the prompt for entering new values when editing an innovator
string getSelectedOptionToEdit(int option)
{
    const string OPTIONS[8] = {
        " ENTER NEW NRC No:   ",
        " ENTER NEW PASSPORT No:   ",
        " ENTER NEW FIRSTNAME:   ",
        " ENTER NEW LASTNAME:   ",
        " ENTER NEW AGE:   ",
        " ENTER NEW TITLE OF INNOVATION:   ",
        " ENTER NEW PATENT STATUS:   ",
        " ENTER NEW INNOVATION CATEGORY:   ",
    };
    return "\n" + OPTIONS[option - 1];
}
// Display options for confirming an action
void displayConfirmOptions()
{
    cout << "\n ARE YOU SURE YOU WANT TO TAKE THIS ACTION?";
    cout << "\n 1 - SURE YES ";
    cout << "\n 2 - SURE NO ";
}
// Display options for choosing patent status
void displayPatentsOptions()
{
    cout << "\n CHOOSE PATENT STATUS: ";
    cout << "\n 1 - PATENTED ";
    cout << "\n 2 - IN PROGRESS ";
    cout << "\n 3 - NOT REQUIRED ";
}
// Display options for choosing innovation category
void displayInnovationCategoriesOptions()
{
    cout << "\n CHOOSE INNOVATION CATEGORY: ";
    cout << "\n 1 - FoodTech ";
    cout << "\n 2 - WoodTech ";
    cout << "\n 3 - MetalTech ";
    cout << "\n 4 - IT ";
    cout << "\n 5 - Other ";
}
// Display sign-up options for the hub
void displaySignUpOptions()
{
    cout << " SIGN UP AS HUB:  \n";
    cout << "\n 1 - MANAGER";
    cout << "\n 2 - COORDINATOR";
    cout << "\n 3 - TECHNICIAN";
    cout << "\n     OR";
    cout << "\n 4 - LOGIN";
}
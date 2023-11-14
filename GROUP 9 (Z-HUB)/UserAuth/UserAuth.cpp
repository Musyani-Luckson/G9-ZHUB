struct Status
{
    string roleName;
    string password;
    int position;
    bool access;
};
//
int SignUpUser(string directory)
{
    const string ROLES[3] = {"MANAGER", "COORDINATOR", "TECHNITIAN"};
    const int CHOICE = getChoice(displaySignUpOptions, 4);
    if (CHOICE >= 1 && CHOICE <= 3)
    {
        system("cls");
        cout << "\n SIGNING UP AN ACCOUNT AS HUB " + ROLES[CHOICE - 1] + ".\n";
        const string PASSWORD = userInput("\n ENTER PASSWORD:   ", true);
        const string CONFIRM_PASSWORD = userInput("\n CONFIRM PASSWORD:   ", true);
        const bool IS_A_MATCH = PASSWORD.compare(CONFIRM_PASSWORD);
        if (!IS_A_MATCH)
        {
            system("cls");
            string ROLE_VALUE = "\"ROLE\":\"" + ROLES[CHOICE - 1] + "\"";
            string PASSWORD_VALUE = "\"PASSWORD\":\"" + PASSWORD + "\"";
            const string USER = "{" + ROLE_VALUE + "," + PASSWORD_VALUE + "}";
            manageFile("write", directory, USER);
            return 1;
        }
        else
        {
            system("cls");
            cout << "\n\n PASSWORDS DID NOT MATCH \n\n";
            return SignUpUser(directory);
        }
    }
    else
    {
        system("cls");
        return 4;
    };
}
//
Status UserAuth(string directory)
{
    Status userStatus;
    const string ROLES[3] = {"MANAGER", "COORDINATOR", "TECHNITIAN"};
    //
    const int CHOICE = getChoice(displayRoleOptions, 4);
    system("cls");
    displayHubName();
    if (CHOICE >= 1 && CHOICE <= 3)
    {
        const string ROLE = ROLES[CHOICE - 1];
        string password;
        int hasAttempsCounter = 1;
        const int ATTEMPTS_MAX = 4;
        while (hasAttempsCounter < ATTEMPTS_MAX)
        {
            cout << "\n Y O U   H A V E (" << (ATTEMPTS_MAX - hasAttempsCounter) << ") A T T E M P T (S)\n";
            password = userInput("\n ENTER PASSWORD FOR THE HUB (" + ROLE + ") :  ", true);
            const string KEY_ROLE = formKeyValue("ROLE", ROLE);
            const string KEY_PASSWORD = formKeyValue("PASSWORD", password);
            const vector<string> USERS = manageFile("read", directory);
            for (string eachUser : USERS)
            {
                if (eachUser.find(KEY_ROLE) != -1 && eachUser.find(KEY_PASSWORD) != -1)
                {
                    userStatus.roleName = ROLE;
                    userStatus.password = password;
                    userStatus.position = CHOICE;
                    userStatus.access = true;
                    return userStatus;
                }
            }
            hasAttempsCounter += 1;
            system("cls");
            displayHubName();
            cout << "\n\n I N C O R R E C T   P A S S W O R D\n";
        }
        userStatus.roleName = "";
        userStatus.password = "";
        userStatus.position = 0;
        userStatus.access = false;
        return userStatus;
    }
    else
    {
        // The statement here returns an array of already existing users, and then determines the size of that array.
        // Then checks if the size is equal to (4) which is the maximum number of users.
        // Meaning if size is equal to maximum then no user will be allowed to create an account.
        if (manageFile("read", directory).size() == 4)
        {
            system("cls");
            displayHubName();
            cout << "\n ALL THE ROLES ARE OCCUPIED \n\n";
            return UserAuth(directory);
        }
        // Otherwise allow a user to be able to create account.
        else
        {
            // Account creater.
            const int SIGN_UP = SignUpUser(directory);
            //
            if (SIGN_UP == 1 || SIGN_UP == 4)
            {
                system("cls");
                displayHubName();
                return UserAuth(directory);
            }
        }
    }
}

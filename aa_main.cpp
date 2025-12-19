#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <direct.h>
#include <vector>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <set>
#include <ctime>
#include <algorithm>



using namespace std;



// Class defination
class Items
{
public:
    char itemname[50];
    int price;
    int inventory;

    Items() {}  // Default constructor

    Items(const char name[50], int price, int inventory)
    {
        strcpy(this->itemname, name);
        this->price = price;
        this->inventory = inventory;
    }
};
vector<Items> item;

class User 
{
    public:

    char username[20];
    char password[20];
    char balance[20];
 
};

class PinCode 
{
    public:

    char username[20];
    char pincode[5];

};



//Function Prototype
void loadimage(const char* image);
void intro();
void menupage();
void all_items();
void LoginRegister_page();
bool isUsernameUnique(const char* username);
bool isUserExist(const char* username, const char* password);
void Registerpage();
void registerUser();
void admin_loginpage();
void admin_login();
void out_loginpage();
void outlogin();
void loginUser();
void loginpage();
void items_selection(char username[20], char password[20]);
void finalarray();
void receipt_page(char username[20], char password[20]);
void receipt(char username[20], char password[20]);
void CheckStockLimit(int* amounts, string* quantities, char username[20], char password[20]);
int get_year();
int get_month();
int get_date();
void remainbalance(int rembalance, int totalamt, char username[20], char password[20]);
bool isOutExist(const char* username);
void payment_cus(char username[20], char password[20], int totalamt, int balance, int d);
void payment_out(char username[20], char password[20], int totalamt);
void resetpage();
bool pincheck(char username[20],char pincode[5]);
void cuslistpage();
void loadUserData(User users[], int &userCount, PinCode pincodes[], int &pinCount);
void displayUserData(User users[], int userCount, PinCode pincodes[], int pinCount);
void admin_das();
void transactionpage();
void allitempage();
void acccus(char username[20]);
bool searchUser(const char* username);
void loadconfirm(char username[20],char search[20],char pass[20]);
void deleteUser(const char username[20]);
void transaction_track(char syear[5], char smonth[5], char sdate[5], char fileusername[20], char b[100], int qty, int amount, int y);
void saveItemsToFile(const vector<Items>& items, const char* filename);
vector<Items> loadItemsFromFile(const char* filename);
void displayItemDetails(const Items& item);
void saveItemDetails(const Items& itemupdate, const char* originalItemName);
void deleteItem(const char* itemName);
bool searchItem(const char* searchText, Items& foundItem);
void editItemDetails(Items& item);
void appendItem(const Items& newItem);
void additem();



int selected_items[100], final_items[100], index = 0, no_ofitems = 0;
string* arr;
int* amounts;



int get_date()
{
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    
    int date = now->tm_mday;
    
    cout << date << endl;


    return date;
}



int get_year()
{
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    
    int year = now->tm_year + 1900;
    
    cout << year << endl;


    return year;
}



int get_month()
{
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    
    int month = now->tm_mon + 1;
    
    cout << month << endl;


    return month;
}



void all_items()
{
    char b[50];
    int i = 0, a = 0;

    setcolor(WHITE);

    for (i = 0; i < item.size(); i++)
    {
        // Draw rectangles
        rectangle(58, 242 + a, 416, 287 + a);
        rectangle(491, 242 + a, 849, 287 + a);
        rectangle(905, 242 + a,1262, 287 + a);
        a = a + 70;
       
        // Set text style and background color
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        int DARKCYANGREEN = COLOR(0, 100, 100);  // RGB values for a dark cyan green
        setbkcolor(DARKCYANGREEN);

        // Convert price to string
        sprintf(b, "%d", item[i].price);

        // Display item name and price
        outtextxy(165, 264 + a - 80, item[i].itemname);
        outtextxy(630, 264 + a - 80, (char *)"Rs.");
        outtextxy(680, 264 + a - 80, b);
        sprintf(b, "%d", item[i].inventory);
        outtextxy(1060, 264 + a - 80, b);  // Adjust y-coordinate for proper placement

        delay(20);
    }
}



void loadimage(const char* image)
{
    cleardevice();
    
    _flushall(); // Clear Input/Output streams

    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
    while (kbhit()) getch(); // Clears the keyboard input buffer
    
    cleardevice();
    readimagefile(image, 0, 0, getmaxx(), getmaxy());
}



void menupage()
{
    const char* image = "p2.jpg";
    loadimage(image);

    all_items();     // Calling all_items() function.

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_RBUTTONDOWN))
        {
            int x, y;
        if(ismouseclick(WM_LBUTTONDOWN))
           {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            }
        if(ismouseclick(WM_RBUTTONDOWN))
           {
            getmouseclick(WM_RBUTTONDOWN, x, y);
            }
            if (x >= 535 && x <= 799 && y >= 681 && y <= 743)
            {
                LoginRegister_page();
                break;
            }
        }
    }
}



void LoginRegister_page()
{
    const char* image = "p3.jpg";
    loadimage(image);

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_RBUTTONDOWN))
        {
            int x, y;
            if(ismouseclick(WM_LBUTTONDOWN))
            {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            }
            if(ismouseclick(WM_RBUTTONDOWN))
            {
            getmouseclick(WM_RBUTTONDOWN, x, y);
            }
            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                menupage();
                break;
            }
            if (x >= 133 && x <= 458 && y >= 228 && y <= 286)
            {
                Registerpage();
                break;
            }
            else if (x >= 133 && x <= 458 && y >= 321 && y <= 378)
            {
                out_loginpage();
                break;
            }
            else if (x >= 133 && x <= 458 && y >= 413 && y <= 469)
            {
                loginpage();
                break;
            }
            else if (x >= 133 && x <= 458 && y >= 506 && y <= 562)
            {
                admin_loginpage();
                break;
            }
        }
    }
}



bool isUsernameUnique(const char* username)
{
    ifstream readuserfile("users.bin", ios::binary);
    ifstream readoutfile("outsiders.bin", ios::binary);
    char userfileUsername[20] = {0};
    char userfilePassword[20] = {0};
    char outfileUsername[20] = {0};

    // Check the username in users.bin
    while (readuserfile.read((char*)&userfileUsername, sizeof(userfileUsername)) && readuserfile.read((char*)&userfilePassword, sizeof(userfilePassword)))
    {
        if (strcmp(userfileUsername, username) == 0)
        {
            readuserfile.close();
            readoutfile.close();
            return false;  // Username is not unique
        }
    }

    // Check the username in outsiders.bin
    while (readoutfile.read((char*)&outfileUsername, sizeof(outfileUsername)))
    {
        if (strcmp(outfileUsername, username) == 0)
        {
            readuserfile.close();
            readoutfile.close();
            return false;  // Username is not unique
        }
    }

    readuserfile.close();
    readoutfile.close();
    return true;  // Username is unique
}



void Registerpage()
{
    const char* image = "pinregister.jpg";
    loadimage(image);

    registerUser();
}



// Function to handle user registration
void registerUser()
{
    char username[20] = {0}, password[20] = {0}, confirmPassword[20] = {0}, pincode[5] = {0}, balanceStr[20];
    int balance = 100000;
    int currentField = 0;  // Start with no field selected
    int previousField = 0; // To keep track of the previously selected field
    int mycolor = COLOR(207, 209, 210);

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            previousField = currentField; // Update previousField before changing currentField

            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                LoginRegister_page();
                break;
            }

            // Check if the username field is clicked
            if (x >= 703 && x <= 1139 && y >= 234 && y <= 288)
            {
                currentField = 1;  // Username field selected
            }
            else if (x >= 703 && x <= 1139 && y >= 319 && y <= 372)
            {
                currentField = 2;  // Password field selected
            }
            else if (x >= 703 && x <= 1139 && y >= 403 && y <= 456)
            {
                currentField = 3;  // Confirm Password field selected
            }
            else if (x >= 703 && x <= 1139 && y >= 487 && y <= 531)
            {
                currentField = 4;  // Pin code field selected
            }
            else if (x >= 789 && x <= 1053 && y >= 575 && y <= 637)
            {
                // Submit button clicked
                if (strlen(username) == 0 || strlen(password) == 0 || strlen(confirmPassword) == 0 || strlen(pincode) == 0)
                {
                    const char* image = "regfillerror.jpg";
                    loadimage(image);
                    getch();
                    Registerpage();
                }
                else if (!isUsernameUnique(username))
                {
                    const char* image = "userexist.jpg";  // Display an error message indicating the username already exists
                    loadimage(image);
                    getch();
                    Registerpage();
                }
                else if (strcmp(password, confirmPassword) == 0)
                {
                    ofstream writefile("users.bin", ios::binary | ios::app);
                    writefile.write((char*)&username, sizeof(username));
                    writefile.write((char*)&password, sizeof(password));
                    writefile.close();

                    snprintf(balanceStr, sizeof(balanceStr), "%d", balance);

                    ofstream balancefile("UserBalance.bin", ios::binary | ios::app);
                    balancefile.write((char*)&username, sizeof(username));
                    balancefile.write((char*)&password, sizeof(password));
                    balancefile.write((char*)&balanceStr, sizeof(balanceStr));
                    balancefile.close();

                    ofstream pinfile("pincode.bin", ios::binary | ios::app);
                    pinfile.write((char*)&username, sizeof(username));
                    pinfile.write((char*)&pincode, sizeof(pincode));
                    pinfile.close();

                    const char* image = "regsuccess.jpg";
                    loadimage(image);
                    getch();

                    loginpage();
                }
                else
                {
                    const char* image = "pwunmatch.jpg";
                    loadimage(image);
                    getch();
                    Registerpage();
                }
                break;
            }

            // Clear the previous rectangle when a new field is selected
            if (previousField != 0 && previousField != currentField)
            {
                setcolor(mycolor);
                if (previousField == 1)
                {
                    rectangle(705, 236, 1136, 285);
                }
                else if (previousField == 2)
                {
                    rectangle(705, 321, 1136, 369);
                }
                else if (previousField == 3)
                {
                    rectangle(705, 405, 1136, 453);
                }
                else if (previousField == 4)
                {
                    rectangle(705, 489, 1136, 538);
                }
            }
        }

        if (kbhit() && currentField != 0)
        {
            char ch = getch();
            if (ch == 13) // ENTER key
            {
                previousField = currentField;

                if (currentField == 1)
                {
                    currentField = 2;  // Move to password field
                }
                else if (currentField == 2)
                {
                    currentField = 3;  // Move to confirm password field
                }
                else if (currentField == 3)
                {
                    currentField = 4;  // Move to pin code field
                }
                else if (currentField == 4)
                {
                    // Submit the form
                    if (strlen(username) == 0 || strlen(password) == 0 || strlen(confirmPassword) == 0 || strlen(pincode) == 0)
                    {
                        const char* image = "regfillerror.jpg";
                        loadimage(image);
                        getch();
                        Registerpage();
                    }
                    else if (!isUsernameUnique(username))
                    {
                        const char* image = "userexist.jpg";  // Display an error message indicating the username already exists
                        loadimage(image);
                        getch();
                        Registerpage();
                    }
                    else if (strcmp(password, confirmPassword) == 0)
                    {
                        ofstream writefile("users.bin", ios::binary | ios::app);
                        writefile.write((char*)&username, sizeof(username));
                        writefile.write((char*)&password, sizeof(password));
                        writefile.close();

                        snprintf(balanceStr, sizeof(balanceStr), "%d", balance);

                        ofstream balancefile("UserBalance.bin", ios::binary | ios::app);
                        balancefile.write((char*)&username, sizeof(username));
                        balancefile.write((char*)&password, sizeof(password));
                        balancefile.write((char*)&balanceStr, sizeof(balanceStr));
                        balancefile.close();

                        ofstream pinfile("pincode.bin", ios::binary | ios::app);
                        pinfile.write((char*)&username, sizeof(username));
                        pinfile.write((char*)&pincode, sizeof(pincode));
                        pinfile.close();

                        const char* image = "regsuccess.jpg";
                        loadimage(image);
                        getch();

                        loginpage();
                    }
                    else
                    {
                        const char* image = "pwunmatch.jpg";
                        loadimage(image);
                        getch();
                        Registerpage();
                    }
                    break;
                }

                // Clear the previous rectangle when moving to the next field
                if (previousField != 0 && previousField != currentField)
                {
                    setcolor(mycolor);
                    if (previousField == 1)
                    {
                        rectangle(705, 236, 1136, 285);
                    }
                    else if (previousField == 2)
                    {
                        rectangle(705, 321, 1136, 369);
                    }
                    else if (previousField == 3)
                    {
                        rectangle(705, 405, 1136, 453);
                    }
                    else if (previousField == 4)
                    {
                        rectangle(705, 489, 1136, 538);
                    }
                }
            }
            else if (ch == 8) // Backspace to delete characters
            {
                if (currentField == 1 && strlen(username) > 0)
                {
                    username[strlen(username) - 1] = '\0';  // Remove last character
                    outtextxy(710, 247, (char*)"                                                     "); // Clear the text area
                    outtextxy(710, 247, username); // Redraw updated username
                }
                else if (currentField == 2 && strlen(password) > 0)
                {
                    password[strlen(password) - 1] = '\0';  // Remove last character
                    outtextxy(710, 335, (char*)"                                                     "); // Clear the text area
                    for (int i = 0; i < strlen(password); i++)
                    {
                        outtextxy(710 + i * 10, 335, (char*)"*"); // Redraw updated password
                    }
                }
                else if (currentField == 3 && strlen(confirmPassword) > 0)
                {
                    confirmPassword[strlen(confirmPassword) - 1] = '\0';  // Remove last character
                    outtextxy(710, 420, (char*)"                                                     "); // Clear the text area
                    for (int i = 0; i < strlen(confirmPassword); i++)
                    {
                        outtextxy(710 + i * 10, 420, (char*)"*"); // Redraw updated confirm password
                    }
                }
                else if (currentField == 4 && strlen(pincode) > 0)
                {
                    pincode[strlen(pincode) - 1] = '\0';  // Remove last character
                    outtextxy(710, 505, (char*)"                                                     "); // Clear the text area
                    outtextxy(710, 505, pincode); // Redraw updated pin code
                }
            }
            else
            {
                if (currentField == 1 && strlen(username) < 19)
                {
                    username[strlen(username)] = ch;
                }
                else if (currentField == 2 && strlen(password) < 19)
                {
                    password[strlen(password)] = ch;
                }
                else if (currentField == 3 && strlen(confirmPassword) < 19)
                {
                    confirmPassword[strlen(confirmPassword)] = ch;
                }
                else if (currentField == 4 && strlen(pincode) < 4)
                {
                    if (isdigit(ch)) // Check if the character is a digit
                    {
                        pincode[strlen(pincode)] = ch;
                    }
                }

                // Update the display for each field
                setbkcolor(mycolor);
                setcolor(BLACK);
                outtextxy(710, 247, username);
                for (int i = 0; i < strlen(password); i++)
                {
                    outtextxy(710 + i * 10, 335, (char*)"*");
                }
                for (int i = 0; i < strlen(confirmPassword); i++)
                {
                    outtextxy(710 + i * 10, 420, (char*)"*");
                }
                outtextxy(710, 505, pincode);
            }
        }

        // Draw the inside rectangle for the selected field
        if (currentField == 1)
        {
            setcolor(RED);
            rectangle(705, 236, 1136, 285);  // Slightly inside the username field
        }
        else if (currentField == 2)
        {
            setcolor(RED);
            rectangle(705, 321, 1136, 369);  // Slightly inside the password field
        }
        else if (currentField == 3)
        {
            setcolor(RED);
            rectangle(705, 405, 1136, 453);  // Slightly inside the confirm password field
        }
        else if (currentField == 4)
        {
            setcolor(RED);
            rectangle(705, 489, 1136, 538);  // Slightly inside the pin code field
        }
    }
}



void loadUserData(User users[], int &userCount, PinCode pincodes[], int &pinCount) 
{
    ifstream usersFile("UserBalance.bin", ios::binary);
    ifstream pincodesFile("pincode.bin", ios::binary);

    if (!usersFile || !pincodesFile) 
    {
        cerr << "Error opening files!" << endl;
        return;
    }

    userCount = 0;
    pinCount = 0;

    // Read all users
    while (usersFile.read((char*)(&users[userCount]), sizeof(User))) 
    {
        userCount++;
    }

    // Read all pincodes
    while (pincodesFile.read((char*)(&pincodes[pinCount]), sizeof(PinCode))) 
    {
        pinCount++;
    }

    usersFile.close();
    pincodesFile.close();
}



void displayUserData(User users[], int userCount, PinCode pincodes[], int pinCount) 
{
    setcolor(WHITE);
    setbkcolor(COLOR(47, 117, 110));
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    
    int y = 170; // Y-coordinate for the starting position

    for (int i = 0; i < userCount; i++) 
    {
        char pin[5] = "N/A"; // Default value if no pin is found

        // Find the pin code for this user
        for (int j = 0; j < pinCount; j++) 
        {
            if (strcmp(users[i].username, pincodes[j].username) == 0) 
            {
                strcpy(pin, pincodes[j].pincode);
                break;
            }
        }

        // Display Serial Number
        char buffer[100];
        sprintf(buffer, "%d.", i + 1);
        outtextxy(326, y, buffer);

        // Display Username
        sprintf(buffer, "%s", users[i].username);
        outtextxy(508 + 40, y, buffer);

        // Display Pin Code
        sprintf(buffer, "%s", pin);
        outtextxy(856 + 40, y, buffer);

        // Display Balance
        sprintf(buffer, "Rs. %s", users[i].balance);
        outtextxy(1116 + 10, y, buffer);

        setcolor(WHITE);
        line(300, y + 32, 1290, y + 32);
        
        y += 40; // Display next user data

        setcolor(WHITE);
        // Terminnal outputfor debug
        cout << buffer << endl;
    }


}




bool searchUser(const char* username) 
{
    ifstream userfile("UserBalance.bin", ios::binary);
    if (!userfile) 
    {
        outtextxy(800, 100, (char*)"Error opening file!");
        return false;
    }

    User tempUser;
    while (userfile.read((char*)(&tempUser), sizeof(User))) 
    {
        if (strcmp(tempUser.username, username) == 0) 
        {
            userfile.close();  // Close the file after finding the user
            return true;   // User found
        }
    }
    
    userfile.close();  // Ensure the file is closed after reading
    return false;  // User not found
}



void loadconfirm(char username[20],char search[20],char pass[20])
{
    const char* image = "loadconfirm.jpg";
    loadimage(image);
    
    setbkcolor(COLOR(252, 243, 231));
    outtextxy(650+10,252+10,username);
    outtextxy(650+10,324+15,search);
    
    char searchText[20] = {0};
    int searchTextLength = 0;
    bool searchBarActive = false;
    
    while (true) 
    {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if cancel  button is clicked
            if (x >=451 && x <=706 && y >= 501 && y <= 567) 
            {
                acccus(username);
                break;
            }

            // Check if psw bar is clicked
            if (x >=650 && x <=1013 && y >= 398 && y <= 457)
            {
                searchBarActive = true;

                // Draw the rectangle excluding the rounded corners
                setcolor(RED);
                rectangle(650+4,398+4,1013-4,457-4) ;  // Right arc
        
            }

            // Check if confirm icon is clicked
            if (x >= 759 && x <= 1013  && y >= 501 && y <= 567) 
            {
                if (searchTextLength == 0)
                { 
                    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
                    while (kbhit()) getch();

                    const char* image = "passempty.jpg";
                    loadimage(image);
                    getch();

                    loadconfirm(username,search,pass);
                    return;

                }
                if(strcmp(pass, searchText) == 0)
                {
                    
                    const char* image = "loadsuccess.jpg"; //sucess image 
                    loadimage(image);
                    getch();
                   
                    int balance;
                    char fileusername[20] = {0};
                    char filepassword[20] = {0};
                    char filebalance[20] = {0};
                    int loadamt=0;
                    loadamt = atoi(search);

                    fstream file("UserBalance.bin", ios::in | ios::out | ios::binary);
                    
                    if (!file) 
                    {
                        cout << "File could not be opened!" << endl;
                        return;
                    }

                    while (!file.eof())
                    {

                        file.read((char*)&fileusername, sizeof(fileusername));
                        file.read((char*)&filepassword, sizeof(filepassword));  
                        file.read((char*)&filebalance, sizeof(filebalance));

                        cout << endl << fileusername << endl;
                        cout << username << endl;
                        cout << "Check1" << endl;
                        cout << filebalance << endl;
                    
                        balance = atoi(filebalance);

                        if (strcmp(username, fileusername) == 0)
                        {
                            balance = balance + loadamt;
                            snprintf(filebalance, sizeof(filebalance), "%d", balance);
                            file.seekp(-(int)sizeof(filebalance), ios::cur);
                            file.write((char*)&filebalance, sizeof(filebalance));

                            file.close();
                            break;
                            
                        }
                    }
                    file.close();
 
                    cuslistpage();
                    break;
                }
                else
                {
                    const char* image = "incorrectpsw.jpg"; //sucess image 
                    loadimage(image);
                    getch();

                    loadconfirm(username,search,pass);
                    break;

                }
               
                searchText[0] = '\0';  // Clear searchText after search
                searchTextLength = 0;
                searchBarActive = false;  // Deactivate search bar after search
                
            }
        }

        if (searchBarActive && kbhit()) 
        {
            char key = getch();

            if (key == 13) 
            {  
                // Enter key
                if (searchTextLength == 0)
                { 
                    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
                    while (kbhit()) getch();

                    const char* image = "passempty.jpg";
                    loadimage(image);
                    getch();

                    loadconfirm(username,search,pass);
                    return;

                }
                if(strcmp(pass, searchText) == 0)
                {
                    
                    const char* image = "loadsuccess.jpg"; //sucess image 
                    loadimage(image);
                    getch();
                   
                    int balance;
                    char fileusername[20] = {0};
                    char filepassword[20] = {0};
                    char filebalance[20] = {0};
                    int loadamt=0;
                    loadamt = atoi(search);

                    fstream file("UserBalance.bin", ios::in | ios::out | ios::binary);
                    
                    if (!file) 
                    {
                        cout << "File could not be opened!" << endl;
                        return;
                    }

                    while (!file.eof())
                    {

                        file.read((char*)&fileusername, sizeof(fileusername));
                        file.read((char*)&filepassword, sizeof(filepassword));  
                        file.read((char*)&filebalance, sizeof(filebalance));

                        cout << endl << fileusername << endl;
                        cout << username << endl;
                        cout << "Check1" << endl;
                        cout << filebalance << endl;
                    
                        balance = atoi(filebalance);

                        if (strcmp(username, fileusername) == 0)
                        {
                            balance = balance + loadamt;
                            snprintf(filebalance, sizeof(filebalance), "%d", balance);
                            file.seekp(-(int)sizeof(filebalance), ios::cur);
                            file.write((char*)&filebalance, sizeof(filebalance));

                            file.close();
                            break;
                            
                        }
                    }
                    file.close();
 
                    cuslistpage();
                    break;
                }
                else
                {
                    const char* image = "incorrectpsw.jpg"; //sucess image 
                    loadimage(image);
                    getch();

                    loadconfirm(username,search,pass);
                    break;

                }
               
                searchText[0] = '\0';  // Clear searchText after search
                searchTextLength = 0;
                searchBarActive = false;  // Deactivate search bar after search
                
                
            } 
            else if ( key == 8 ) 
            {  
                // Backspace key
                if (searchTextLength > 0) 
                {
                    searchText[--searchTextLength] = '\0';
                    
                    // Clear the rectangle area before redrawing the text
                    setfillstyle(SOLID_FILL,(COLOR(252, 243, 231)));
                    bar(660,398+20,1003,457-20) ;  // Clear inside of the rectangle
                    
                    // Set the text background color to white and redraw text
                    setbkcolor(COLOR(252, 243, 231));
                    setcolor(BLACK);
                    outtextxy(660, 398+20, (char*)"                                            ");

                     for (int i = 0; i < strlen(searchText); i++)
                    {
                        outtextxy(660+ i * 10, 398+20, (char*)"*"); // Redraw updated password
                    }
                }
            } 
            else if (key >= 32 && key <= 126 && searchTextLength < 19) 
            {  
                // Valid characters
                searchText[searchTextLength++] = key;
                searchText[searchTextLength] = '\0';
                
                // Clear the rectangle area before redrawing the text
                setfillstyle(SOLID_FILL,COLOR(252, 243, 231));
                rectangle(651,398,1013,457) ;  // Clear inside of the rectangle

                // Set the text background color to white and redraw text
                setbkcolor(COLOR(252, 243, 231));
                setcolor(BLACK);
               
                for (int i = 0; i < strlen(searchText); i++)
                {
                    outtextxy(660+ i * 10, 398+20, (char*)"*"); // Redraw updated password
                }
            }
        }
    }
                   
}



void deleteUser(const char username[20]) {
    char fileusername[20] = {0};
    char tempFileName[] = "temp.bin";

    // Deleting from UserBalance.bin
    fstream file("UserBalance.bin", ios::in | ios::binary);
    fstream tempFile(tempFileName, ios::out | ios::binary);

    if (!file || !tempFile) {
        cout << "File could not be opened!" << endl;
        return;
    }

    while (file.read((char*)&fileusername, sizeof(fileusername))) {
        char filepassword[20];
        char filebalance[20];

        file.read((char*)&filepassword, sizeof(filepassword));
        file.read((char*)&filebalance, sizeof(filebalance));

        if (strcmp(username, fileusername) != 0) {
            tempFile.write((char*)&fileusername, sizeof(fileusername));
            tempFile.write((char*)&filepassword, sizeof(filepassword));
            tempFile.write((char*)&filebalance, sizeof(filebalance));
        }
    }

    file.close();
    tempFile.close();
    remove("UserBalance.bin");
    rename(tempFileName, "UserBalance.bin");

    // Deleting from pincode.bin
    file.open("pincode.bin", ios::in | ios::binary);
    tempFile.open(tempFileName, ios::out | ios::binary);

    if (!file || !tempFile) {
        cout << "File could not be opened!" << endl;
        return;
    }

    while (file.read((char*)&fileusername, sizeof(fileusername))) {
        char pincode[5];

        file.read((char*)&pincode, sizeof(pincode));

        if (strcmp(username, fileusername) != 0) {
            tempFile.write((char*)&fileusername, sizeof(fileusername));
            tempFile.write((char*)&pincode, sizeof(pincode));
        }
    }

    file.close();
    tempFile.close();
    remove("pincode.bin");
    rename(tempFileName, "pincode.bin");

    // Deleting from users.bin
    file.open("users.bin", ios::in | ios::binary);
    tempFile.open(tempFileName, ios::out | ios::binary);

    if (!file || !tempFile) {
        cout << "File could not be opened!" << endl;
        return;
    }

    while (file.read((char*)&fileusername, sizeof(fileusername))) {
        char filepassword[20];

        file.read((char*)&filepassword, sizeof(filepassword));

        if (strcmp(username, fileusername) != 0) {
            tempFile.write((char*)&fileusername, sizeof(fileusername));
            tempFile.write((char*)&filepassword, sizeof(filepassword));
        }
    }

    file.close();
    tempFile.close();
    remove("users.bin");
    rename(tempFileName, "users.bin");
}




void acccus(char username[20])
{

    const char* image = "cusacc.jpg";
    loadimage(image);
    
    char fileusername[20] = {0};
    char filepassword[20] = {0};
    char filebalance[20] = {0};
    char pincode[5]={0};
    char searchText[20] = {0};
    char pass[20]={0};
    int searchTextLength = 0;
    bool searchBarActive = false;

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setcolor(BLACK);
    setbkcolor(COLOR(252, 243, 231));
    fstream file("UserBalance.bin", ios::in | ios::out | ios::binary);
                    
    if (!file) 
    {
        cout << "File could not be opened!" << endl;
        return;
    }

    while (!file.eof())
    {

        file.read((char*)&fileusername, sizeof(fileusername));
        file.read((char*)&filepassword, sizeof(filepassword));  
        file.read((char*)&filebalance, sizeof(filebalance));

        if (strcmp(username, fileusername) == 0)
        {
            outtextxy(632+15,153+10,fileusername);
            outtextxy(632+15,277+10,filebalance);
            strcpy(pass,filepassword);
                                                
        }
    }
    file.close();
                    
    fstream nextfile("pincode.bin", ios::in | ios::out | ios::binary);
                    
    if (!nextfile) 
    {
        cout << "File could not be opened!" << endl;
        return;
    }

    while (!nextfile.eof())
    {

        nextfile.read((char*)&fileusername, sizeof(fileusername));
        nextfile.read((char*)&pincode, sizeof(pincode));

        if (strcmp(username, fileusername) == 0)
        {
                           
            outtextxy(632+15,214+10,pincode);
                                                
        }
    }
    nextfile.close();
                    
    while (true) 
    {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                cuslistpage();
                break;
            }      
        
            // IF DELETE USER CLICKED  button is clicked
            if (x >= 574 && x <= 805 && y >= 687 && y <= 742) 
            {
                deleteUser(username);

                const char* image = "userdelsuccess.jpg";
                loadimage(image);
                getch();

                cuslistpage();
                break;
            }

            // Check if LOAD bar is clicked
            if (x >= 632 && x <= 986 && y >= 444 && y <= 486) 
            {
                searchBarActive = true;

                // Draw the rectangle excluding the rounded corners
                setcolor(RED);
                rectangle(632,444,986,486)  ; // Right arc
        
            }

            // Check if load button is clicked
            if (x >= 558 && x <=822  && y >=536  && y <= 598) 
            {
               if (searchTextLength==0)
                { 
                    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
                    while (kbhit()) getch();

                    const char* image = "loadzero.jpg";
                    loadimage(image);
                    getch();

                    acccus(username);
                    return;

                }
                else
                {
                    loadconfirm(username,searchText,pass);
                    break;


                }
                
                searchText[0] = '\0';  // Clear searchText after search
                searchTextLength = 0;
                searchBarActive = false; // Deactivate search bar after search
                
            }
        }

        if (searchBarActive && kbhit()) 
        {
            char key = getch();

            if (key == 13) 
            {   
                // Enter key
                if (searchTextLength==0)
                { 
                    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
                    while (kbhit()) getch();

                    const char* image = "loadzero.jpg";
                    loadimage(image);
                    getch();

                    acccus(username);
                    return;

                }
                else
                {
                    loadconfirm(username,searchText,pass);
                    break;
                   
                    getch();

                }
                
                searchText[0] = '\0';  // Clear searchText after search
                searchTextLength = 0;
                searchBarActive = false;  // Deactivate search bar after search
                
            } 
            else if ( key == 8 ) 
            {   
                // Backspace key
                if (searchTextLength > 0) 
                {
                    searchText[--searchTextLength] = '\0';
                    // Clear the rectangle area before redrawing the text
                    setfillstyle(SOLID_FILL, COLOR(252, 243, 231));
                    bar(632,444,986,486)  ;   // Clear inside of the rectangle
                    
                    // Set the text background color to white and redraw text
                    setbkcolor(COLOR(252, 243, 231));
                    setcolor(BLACK);
                    outtextxy(632+10, 444+10, searchText);
                }
            } 
            else if (key >= 48 && key <= 57 && searchTextLength < 5) 
            {  
                // Valid characters
                searchText[searchTextLength++] = key;
                searchText[searchTextLength] = '\0';
                
                // Clear the rectangle area before redrawing the text
                setfillstyle(SOLID_FILL, COLOR(252, 243, 231));
                bar(632,444,986,486)  ;  // Clear inside of the rectangle

                // Set the text background color to white and redraw text
                setbkcolor(COLOR(252, 243, 231));
                setcolor(BLACK);
                outtextxy(632+10, 444+10, searchText);
            }
        }
    }
                    


    getch();



}



void cuslistpage() 
{
    const char* image = "cuslist.jpg";
    loadimage(image);

    User users[100];
    PinCode pincodes[100];
    int userCount, pinCount;

    loadUserData(users, userCount, pincodes, pinCount);
    displayUserData(users, userCount, pincodes, pinCount);

    char searchText[20] = {0};
    int searchTextLength = 0;
    bool searchBarActive = false;

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    while (true) 
    {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if (x >= 255 && x <= 336 && y >= 20 && y <= 87) 
            {
                admin_das();
                break;
            }

            // Check if Transaction button is clicked
            if (x >= 50 && x <= 171 && y >= 232 && y <= 342) 
            {
                //transaction
                transactionpage();
                break;
            }

            // Check if All Items button is clicked
            if (x >= 50 && x <= 171 && y >= 446 && y <= 556) 
            {
                allitempage();
                break;
            }

            // Check if Search bar is clicked
            if (x >= 800 && x <= 1200 && y >= 34 && y <= 87) 
            {
                searchBarActive = true;

                // Draw the rectangle excluding the rounded corners
                setcolor(RED);
                line(830, 34, 1178, 34);   // Top line
                line(830, 86, 1178, 86);   // Bottom line

                // Draw the vertical sides of the rectangle
                line(804, 60, 804, 60);  // Left line
                line(1204, 60, 1204, 60);  // Right line

                // Draw the arcs (assuming the left and right edges are rounded)
                arc(830, 60, 90, 270, 26);    // Left arc
                arc(1178, 60, 270, 90, 26);   // Right arc
        
            }

            // Check if Search icon is clicked
            if (x >= 1147 && x <= 1203 && y >= 34 && y <= 87) 
            {
                if (searchTextLength == 0)
                { 
                    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
                    while (kbhit()) getch();

                    const char* image = "searchempty.jpg";
                    loadimage(image);
                    getch();

                    cuslistpage();
                    return;

                }
                if (searchUser(searchText)) 
                {
                    acccus(searchText);
                    getch();
                    break;
                } 
                else 
                {
                    const char* image = "nouser.jpg";
                    loadimage(image);
                    getch();
                    cuslistpage();
                    return;
                }
                searchText[0] = '\0';  // Clear searchText after search
                searchTextLength = 0;
                searchBarActive = false;  // Deactivate search bar after search
                
            }
        }

        if (searchBarActive && kbhit()) 
        {
            char key = getch();

            if (key == 13) 
            {  // Enter key
                if (searchTextLength==0)
                { 
                    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
                    while (kbhit()) getch();

                    const char* image = "searchempty.jpg";
                    loadimage(image);
                    getch();

                    cuslistpage();
                    return;

                }
                if (searchUser(searchText)) 
                {
                    acccus(searchText);
                    getch();
                    break;
                } 
                else 
                {
                    const char* image = "nouser.jpg";
                    loadimage(image);
                    getch();
                    cuslistpage();
                    return;
                }
                searchText[0] = '\0';
                searchTextLength = 0;
                searchBarActive = false;
                
            } 
            else if ( key == 8 ) 
            {  // Backspace key
                if (searchTextLength > 0) 
                {
                    searchText[--searchTextLength] = '\0';
                    // Clear the rectangle area before redrawing the text
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(825, 37, 1151, 83);  // Clear inside of the rectangle
                    
                    // Set the text background color to white and redraw text
                    setbkcolor(WHITE);
                    setcolor(BLACK);
                    outtextxy(828, 48, searchText);
                }
            } 
            else if (key >= 32 && key <= 126 && searchTextLength < 19) 
            {  // Valid characters
                searchText[searchTextLength++] = key;
                searchText[searchTextLength] = '\0';
                // Clear the rectangle area before redrawing the text
                setfillstyle(SOLID_FILL, WHITE);
                bar(825, 37, 1151, 83);  // Clear inside of the rectangle

                // Set the text background color to white and redraw text
                setbkcolor(WHITE);
                setcolor(BLACK);
                outtextxy(828, 48, searchText);
            }
        }
    }
}



void transaction_track(char syear[5], char smonth[5], char sdate[5], char fileusername[20], char b[100], int qty, int amount, int y)
{
    setcolor(WHITE);
    setbkcolor(COLOR(47, 117, 110));
    char buffer[200];

    // Display Year
    sprintf(buffer, "%s /", syear);
    outtextxy(290, y, buffer);

    // Display Month
    sprintf(buffer, "%s /", smonth);
    outtextxy(345, y, buffer);

    // Display Date
    sprintf(buffer, "%s", sdate);
    outtextxy(375, y, buffer);

    // Display Username
    sprintf(buffer, "%s", fileusername);
    outtextxy(538, y, buffer);

    // Display Item Name
    sprintf(buffer, "%s", b);
    outtextxy(822, y, buffer);

    // Display Quantity
    sprintf(buffer, "%d", qty);
    outtextxy(1043, y, buffer);

    // Display Amount
    sprintf(buffer, "Rs. %d", amount);
    outtextxy(1190, y, buffer);

    setcolor(WHITE);
    line(275, y + 32, 1302, y + 32);
}



void transactionpage()
{
    // Load background image
    const char* image = "transactions.jpg";
    loadimage(image);
    
    int r;
    
    // Open the binary file for reading
    ifstream readfile("transaction.bin", ios::binary);
    if (!readfile) 
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Set text color and background color
   
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    int currentField = 0;  // Start with no field selected
    int previousField = 0; // To keep track of the previously selected field
    int mycolor = COLOR(207, 209, 210);

    // Temporary buffers for the data
    char fileusername[20] = {0};
    char syear[5] = {0}, smonth[5] = {0}, sdate[5] = {0};
    char b[100] = {0};
    char username[20] = {0}, dateto[20] = {0};
    char datefile[20] = {0};

    int y = 210;  // Y-coordinate for the starting position

    // Read and display transactions initially
    while (true) 
    {
        // Read the fixed-size fields
        readfile.read((char*)&syear, sizeof(syear));
        readfile.read((char*)&smonth, sizeof(smonth));
        readfile.read((char*)&sdate, sizeof(sdate));
        readfile.read((char*)&fileusername, sizeof(fileusername));
        readfile.read((char*)&b, sizeof(b));

        // Read qty
        int qty = 0;
        readfile.read((char*)&qty, sizeof(qty));

        // Read the amount
        int amount = 0;
        readfile.read((char*)&amount, sizeof(amount));

        // If any of these reads fail, break the loop
        if (readfile.gcount() == 0)
            break;

        transaction_track(syear, smonth, sdate, fileusername, b, qty, amount, y);
        y += 40;  // Display next user data
    }

    readfile.close();

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if (x >= 232 && x <= 311 && y >= 16 && y <= 83)
            {
                admin_das();
                break;
            }

            // Check if Customer button is clicked
            if (x >= 50 && x <= 171 && y >= 232 && y <= 342)
            {
                cuslistpage();
                break;
            }

            // Check if All Items button is clicked
            if (x >= 50 && x <= 171 && y >= 446 && y <= 556)
            {
                allitempage();
                break;
            }

            // Searching
            if (x >= 463 && x <= 763 && y >= 87 && y <= 125)
            {
                currentField = 1;  // Username field selected

                // Draw red boundary around the username field
                setcolor(RED);
                rectangle(462, 86, 762, 124);
            }
            else if (x >= 881 && x <= 1182 && y >= 87 && y <= 125)
            {
                currentField = 2;  // Date from field selected

                // Draw red boundary around the date field
                setcolor(RED);
                rectangle(880, 86, 1181, 124);
            }
           
            else if (x >= 1199 && x <= 1322  && y >= 83 && y <= 120) // Search button
            {
                // Reset the screen for new search results
                cleardevice();
                
                const char* image = "specialtransaction.jpg";
                loadimage(image);

                // Open the file again for reading search results
                ifstream searchfile("transaction.bin", ios::binary);
                if (!searchfile) 
                {
                    cerr << "Error opening file!" << endl;
                    return;
                }

                y = 210;  // Reset y position for displaying search results

                while (true) 
                {
                    // Clear previous content in datefile
                    memset(datefile, 0, sizeof(datefile));

                    // Read the fixed-size fields
                    searchfile.read((char*)&syear, sizeof(syear));
                    searchfile.read((char*)&smonth, sizeof(smonth));
                    searchfile.read((char*)&sdate, sizeof(sdate));
                    searchfile.read((char*)&fileusername, sizeof(fileusername));
                    searchfile.read((char*)&b, sizeof(b));

                    // Read qty
                    int qty = 0;
                    searchfile.read((char*)&qty, sizeof(qty));

                    // Read the amount
                    int amount = 0;
                    searchfile.read((char*)&amount, sizeof(amount));

                    // If any of these reads fail, break the loop
                    if (searchfile.gcount() == 0)
                        break;

                    // Construct datefile
                    strcat(datefile, syear);
                    strcat(datefile,"/");
                    strcat(datefile, smonth);
                    strcat(datefile,"/");
                    strcat(datefile, sdate);
                    // Perform search logic
                    bool match = true;
                    if (strlen(username) > 0 && strcmp(username, fileusername) != 0)
                        match = false;

                    if (strlen(dateto) > 0 && strcmp(dateto, datefile) != 0)
                        match = false;

                    

                    if (match) 
                    {
                        transaction_track(syear, smonth, sdate, fileusername, b, qty, amount, y);
                        y += 40;  // Display next result
                    }
                }
                searchfile.close();
                
                while (true)
                {
                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        int x, y;
                        getmouseclick(WM_LBUTTONDOWN, x, y);

                        // Check if Back button is clicked
                        if (x >= 232 && x <= 311 && y >= 16 && y <= 83)
                        {
                        transactionpage();
                            break;
                        }

                        // Check if Customer button is clicked
                        if (x >= 50 && x <= 171 && y >= 232 && y <= 342)
                        {
                            cuslistpage();
                            break;
                        }

                        // Check if All Items button is clicked
                        if (x >= 50 && x <= 171 && y >= 446 && y <= 556)
                        {
                            allitempage();
                            break;
                        }
                    }
                        
                }
                        
            }

            // Clear the previous rectangle when a new field is selected
            if (previousField != 0 && previousField != currentField)
            {
                setcolor(COLOR(252,243,231));
                if (previousField == 1)
                {
                    rectangle(462, 86, 762, 124);
                }
                else if (previousField == 2)
                {
                    rectangle(880, 86, 1181, 124);
                }
                        
            }
            // Draw red rectangle around the newly selected field
            if (currentField == 1)  // Username field selected
            {
                setcolor(RED);
                rectangle(462, 86, 762, 124);
            }
            else if (currentField == 2)  // Date from field selected
            {
                setcolor(RED);
                rectangle(880, 86, 1181, 124);
            }
            previousField = currentField;

        }

        if (kbhit() && currentField != 0)
        {
            char ch = getch();
            if (ch == 13) // ENTER key
            {
                previousField = currentField;

                if (currentField == 1)
                {
                    currentField = 2;  // Move to date from field

                    setcolor(RED);
                    rectangle(880, 86, 1181, 124);
                }
                            
                else if (currentField == 2)
                {     
                    cleardevice();
                    const char* image = "specialtransaction.jpg";
                    loadimage(image);

                    // Execute search when ENTER is pressed on the date to field
                    cleardevice();
                    loadimage(image);

                    // Reopen the file for search
                    ifstream searchfile("transaction.bin", ios::binary);
                    if (!searchfile) 
                    {
                        cerr << "Error opening file!" << endl;
                        return;
                    }

                    y = 210;  // Reset y position for displaying search results

                    while (true) 
                    {
                        memset(datefile, 0, sizeof(datefile));

                        // Read the fixed-size fields
                        searchfile.read((char*)&syear, sizeof(syear));
                        searchfile.read((char*)&smonth, sizeof(smonth));
                        searchfile.read((char*)&sdate, sizeof(sdate));
                        searchfile.read((char*)&fileusername, sizeof(fileusername));
                        searchfile.read((char*)&b, sizeof(b));

                        // Read qty
                        int qty = 0;
                        searchfile.read((char*)&qty, sizeof(qty));

                        // Read the amount
                        int amount = 0;
                        searchfile.read((char*)&amount, sizeof(amount));

                        // If any of these reads fail, break the loop
                        if (searchfile.gcount() == 0)
                            break;
                                
                        strcat(datefile, syear);
                        strcat(datefile,"/");
                        strcat(datefile, smonth);
                        strcat(datefile,"/");
                        strcat(datefile, sdate);


                        bool match = true;
                        
                        if (strlen(username) > 0 && strcmp(username, fileusername) != 0)
                            match = false;

                        if (strlen(dateto) > 0 && strcmp(dateto, datefile) != 0)
                            match = false;

                        if (match) 
                        {
                            transaction_track(syear, smonth, sdate, fileusername, b, qty, amount, y);
                            y += 40;
                        }
                    }

                    searchfile.close();
                                
                    while (true)
                    {
                        if (ismouseclick(WM_LBUTTONDOWN))
                        {
                            int x, y;
                            getmouseclick(WM_LBUTTONDOWN, x, y);

                            // Check if Back button is clicked
                            if (x >= 232 && x <= 311 && y >= 16 && y <= 83)
                            {
                                transactionpage();
                                break;
                            }

                            // Check if Customer button is clicked
                            if (x >= 50 && x <= 171 && y >= 232 && y <= 342)
                            {
                                cuslistpage();
                                break;
                            }

                            // Check if All Items button is clicked
                            if (x >= 50 && x <= 171 && y >= 446 && y <= 556)
                            {
                                allitempage();
                                break;
                            }
                        }
                                        
                    }         
                            
                }
            }
            else if (ch == 8) // Backspace key
            {   
                setcolor(BLACK);
                setbkcolor(COLOR(252,243,231));
                            
                if (currentField == 1 && strlen(username) > 0)
                {
                    username[strlen(username) - 1] = '\0';
                    outtextxy(463+3+3, 87+3+3+2, (char*)"                                        "); // Clear the text area
                    outtextxy(463+3+3, 87+3+3+2, username); // Redraw updated text
                }
                        
                else if (currentField == 2 && strlen(dateto) > 0)
                {
                    dateto[strlen(dateto) - 1] = '\0';
                    outtextxy(878+3+3, 87+3+3+2, (char*)"                                   "); // Clear the text area
                    outtextxy(878+3+3, 87+3+3+2, dateto);
                }
            }
            else if (isalnum(ch) || ch == '/') // Only allow alphanumeric characters and '/'
            {
                if (currentField == 1 && strlen(username) < 19)
                {
                    username[strlen(username)] = ch;
                }
                else if (currentField == 2 && strlen(dateto) < 10)
                {
                    if (isdigit(ch) || ch == '/')
                    { 
                        dateto[strlen(dateto)] = ch;
                    }    
                }

                // Redraw the input field
                setcolor(BLACK);
                setbkcolor(COLOR(252,243,231));
                            
                if (currentField == 1)
                {
                    outtextxy(463+3+3, 87+3+3+2, username); 
                }
                else if (currentField == 2)
                {
                    outtextxy(878+3+3, 87+3+3+2, dateto);
                }
            }
        }                
    }
}



// Function to save items to file
void saveItemsToFile(const vector<Items>& items, const char* filename)
{
    ofstream outfile(filename, ios::binary );
    if (!outfile)
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& item : items)
    {
        outfile.write(reinterpret_cast<const char*>(&item), sizeof(Items));
    }
    outfile.close();
}




// Function to load items from file
vector<Items> loadItemsFromFile(const char* filename)
{
    vector<Items> items;
    ifstream infile(filename, ios::binary);
    if (!infile)
    {
        cerr << "Error opening file for reading!" << endl;
        return items;
    }

    Items item;
    while (infile.read((char*)(&item), sizeof(Items)))
    {
        items.push_back(item);
    }
    infile.close();
    return items;
}



// Function to display the item details in the edit fields
void displayItemDetails(const Items& item) 
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Set text style
    setbkcolor(COLOR(252,243,231));
    setcolor(BLACK);

    // Display Item Name
    char itemName[100];
    sprintf(itemName, "%s", item.itemname);
    outtextxy(640, 265, itemName);

    // Display price
    char price[50];
    sprintf(price, "%d", item.price);
    outtextxy(640, 335, price);

    // Display inventory
    char inventory[50];
    sprintf(inventory, "%d", item.inventory);
    outtextxy(640, 407, inventory);
}



// Function to save item details to the file
void saveItemDetails(const Items& itemupdate, const char* originalItemName)
{
    // Open the file in read-write mode
    fstream file("items.bin", ios::binary | ios::in | ios::out);
    
    if (!file) 
    {
        cerr << "Error opening file." << endl;
        return;
    }

    Items tempItem;
    bool itemFound = false;
    
    // Read through the file to find the item
    while (file.read((char*)(&tempItem), sizeof(Items))) {
        if (strcmp(tempItem.itemname, originalItemName) == 0) {
            // Move back to the item's position
            file.seekp(-static_cast<streamoff>(sizeof(Items)), ios::cur);
            // Write the updated item details
            file.write((char*)(&itemupdate), sizeof(Items));
            
            item = loadItemsFromFile("items.bin");
            // Save items to file
            saveItemsToFile(item, "items.bin");
            itemFound = true;
            break;
        }
    }

    if (!itemFound) {
        cerr << "Item not found in the file." << endl;
    }
    

    file.close();
}




void deleteItem(const char* itemName) 
{
    // Original file for reading
    ifstream readfile("items.bin", ios::binary | ios::in);
    if (!readfile) 
    {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    // Temporary file for writing
    ofstream tempFile("temp.bin", ios::binary | ios::out);
    if (!tempFile) 
    {
        cout << "Error opening temporary file!" << endl;
        return;
    }

    Items itemtemp;

    // Read each item from the original file and write to temp file if it doesn't match the itemName
    while (readfile.read((char*)(&itemtemp), sizeof(Items))) 
    {
        if (strcmp(itemtemp.itemname, itemName) != 0) 
        {
            tempFile.write((char*)(&itemtemp), sizeof(Items));
        }
    }

    // Close both files
    readfile.close();
    tempFile.close();

    // Remove the original file and rename the temp file to the original file name
    remove("items.bin");
    rename("temp.bin", "items.bin");

    item = loadItemsFromFile("items.bin");
}



// Function to search for an item by name
bool searchItem(const char* searchText, Items& foundItem) {
    for (const auto& it : item) 
    {
        if (strcmp(it.itemname, searchText) == 0) {
            foundItem = it;
            return true;
        }
    }
    return false;
}




// Function to edit item details
void editItemDetails(Items& item) 
{

    int selectedField = -1;
    int previousField = -1; // Initialize with an invalid value

    char originalItemName[50];
    strcpy(originalItemName, item.itemname); // Store the original item name

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if (x >= 0 && x <= 81 && y >= 343 && y <= 410)
            {
                allitempage();
                break;
            }

            // Check if Item Name is clicked
            if (x >= 635 && x <= 1003 && y >= 253 && y <= 300) {
                selectedField = 0; // Item Name
            }
            // Check if Price is clicked
            else if (x >= 635 && x <= 1003 && y >= 323 && y <= 371) {
                selectedField = 1; // Price
            }
            // Check if Inventory is clicked
            else if (x >= 635 && x <= 1003 && y >= 395 && y <= 442) {
                selectedField = 2; // Inventory
            }
            // Check if Update button is clicked
            else if (x >= 760 && x <= 935 && y >= 504 && y <= 551) 
            {
                saveItemDetails(item, originalItemName); // Pass original item name to function
                cout << "updated" << endl;
                
                ::item = loadItemsFromFile("items.bin");
                // Save items to file
                saveItemsToFile(::item, "items.bin");

                const char* image = "itemupdatesuccess.jpg";
                loadimage(image);
                getch();

                allitempage(); 
                break;
            }

            // Check if Delete button is clicked
            else if (x >= 574 && x <= 805 && y >= 687 && y <= 742) 
            {
                deleteItem(originalItemName); // Call the delete function

                const char* image = "delitemsuccess.jpg";
                loadimage(image);
                getch();

                allitempage();  // Return to the all item page after deletion
                break;  // Exit the loop after deletion
            }

            // If the field selection has changed, update the UI
            if (selectedField != previousField) 
            {
                // Erase previous rectangle
                if (previousField != -1) 
                {
                    setcolor(COLOR(252, 243, 231)); // Use white to erase the previous rectangle
                    rectangle(635, 252 + (previousField * 70), 1003, 300 + (previousField * 70));
                }

                // Draw the red rectangle around the newly selected field
                setcolor(RED);
                rectangle(635, 252 + (selectedField * 70), 1003, 300 + (selectedField * 70));

                previousField = selectedField;
            }

            clearmouseclick(WM_LBUTTONDOWN); // Clear mouse click buffer
        }

        // Handle keyboard input for the selected field
        if (selectedField != -1 && kbhit()) {
            char ch = getch();

            // Backspace key
            if (ch == 8) 
            {
                if (selectedField == 0 && strlen(item.itemname) > 0) 
                {
                    // Remove the last character from itemname
                    item.itemname[strlen(item.itemname) - 1] = '\0';

                    // Clear the area where the item name is displayed
                    setfillstyle(SOLID_FILL, COLOR(252,243,231));
                    bar(637, 255, 1001, 298);  // Adjust coordinates as needed

                    // Redraw the updated item name
                    setbkcolor(COLOR(252,243,231));
                    setcolor(BLACK);
                    outtextxy(640, 265, item.itemname);  // Adjust coordinates as needed
                } 
                else if (selectedField == 1 && item.price > 0) 
                {
                    // Remove the last digit from price
                    item.price /= 10;

                    // Clear the area where the price is displayed
                    setfillstyle(SOLID_FILL, COLOR(252,243,231));
                    bar(637, 325, 1001, 369);  // Adjust coordinates as needed

                    // Redraw the updated price
                    setbkcolor(COLOR(252,243,231));
                    setcolor(BLACK);

                    // Convert price to string for displaying
                    char priceStr[20];
                    sprintf(priceStr, "%d", item.price);
                    outtextxy(640, 335, priceStr);  // Adjust coordinates as needed
                } 
                else if (selectedField == 2 && item.inventory > 0) 
                {
                    // Remove the last digit from inventory
                    item.inventory /= 10;

                    // Clear the area where the inventory is displayed
                    setfillstyle(SOLID_FILL, COLOR(252,243,231));
                    bar(637, 397, 1001, 440);  // Adjust coordinates as needed

                    // Redraw the updated inventory
                    setbkcolor(COLOR(252,243,231));
                    setcolor(BLACK);

                    // Convert inventory to string for displaying
                    char inventoryStr[20];
                    sprintf(inventoryStr, "%d", item.inventory);
                    outtextxy(640, 407, inventoryStr);  // Adjust coordinates as needed
                }
            }

            else {
                if (selectedField == 0 && strlen(item.itemname) < 49) 
                {
                    item.itemname[strlen(item.itemname) + 1] = '\0';
                    item.itemname[strlen(item.itemname)] = ch;
                } 
                else if (selectedField == 1) 
                {
                    item.price = item.price * 10 + (ch - '0');
                } 
                else if (selectedField == 2) 
                {
                    item.inventory = item.inventory * 10 + (ch - '0');
                }
            }

            // Redraw the item details with the updated values
            displayItemDetails(item);
        }
    }
}



void appendItem(const Items& newItem) 
{
    ofstream file("items.bin", ios::binary | ios::app);
    if (file.is_open()) 
    {
        file.write(reinterpret_cast<const char*>(&newItem), sizeof(Items));
        file.close();
    }
    file.close();

    ::item = loadItemsFromFile("items.bin");
    // Save items to file
    saveItemsToFile(::item, "items.bin");
}



void additem() 
{
    const char* image = "additem.jpg";
    loadimage(image);

    char itemName[50] = {0};
    char priceStr[50] = {0};
    char inventoryStr[50] = {0};

    int currentField = -1; // -1 means no field is selected

    while (true)
    {
        // Handle mouse click for field selection
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                allitempage();
                break;
            }

            // Erase previous rectangle if any field was selected
            if (currentField != -1)
            {
                setcolor(COLOR(252, 243, 231));
                if (currentField == 0)
                    rectangle(597, 251, 970, 299);  // Item Name field
                else if (currentField == 1)
                    rectangle(597, 322, 970, 371);  // Price field
                else if (currentField == 2)
                    rectangle(597, 395, 970, 443);  // Inventory field
            }

            // Determine which field was clicked and select it
            if (x >= 597 && x <= 970 && y >= 251 && y <= 299) 
            {
                currentField = 0;
            }
            else if (x >= 597 && x <= 970 && y >= 322 && y <= 372) 
            {
                currentField = 1;
            }
            else if (x >= 597 && x <= 970 && y >= 395 && y <= 443) 
            {
                currentField = 2;
            }

            // Check if Submit button is clicked
            if (x >= 735 && x <= 998 && y >= 531 && y <= 593)
            {
                int price = atoi(priceStr);
                int inventory = atoi(inventoryStr);

                Items newItem(itemName, price, inventory);

                // Load existing items to check for duplicates
                vector<Items> existingItems = loadItemsFromFile("items.bin");

                bool itemExists = false;
                for (const auto& item : existingItems) 
                {
                    if (strcmp(item.itemname, newItem.itemname) == 0) 
                    {
                        itemExists = true;
                        break;
                    }
                }

                if (!itemExists) 
                {
                    item.push_back(newItem);
                    appendItem(newItem);

                    const char* successImage = "additemsuccess.jpg";
                    loadimage(successImage);
                    getch();

                    // Reset after adding item
                    currentField = -1;
                    memset(itemName, 0, sizeof(itemName));
                    memset(priceStr, 0, sizeof(priceStr));
                    memset(inventoryStr, 0, sizeof(inventoryStr));

                    allitempage();
                } 
                else 
                {
                    const char* errorImage = "duplicateitem.jpg";
                    loadimage(errorImage);
                    
                    getch();

                    additem();
                    return;
                }
            }

            // Draw the red rectangle around the selected field
            setcolor(RED);
            if (currentField == 0)
            {
                rectangle(597, 251, 970, 299);  // Item Name field
            }
            else if (currentField == 1)
            {
                rectangle(597, 322, 970, 371);  // Price field
            }
            else if (currentField == 2)
            {
                rectangle(597, 395, 970, 443);  // Inventory field
            }
        }

        // Wait for user input
        if (kbhit()) 
        {
            char ch = getch();

            // Handle navigation between fields when Enter is pressed
            if (ch == 13 && currentField != -1)  // Enter key pressed and a field is selected
            {
                if (currentField == 2) // If on the last field, finalize input
                {
                    int price = atoi(priceStr);
                    int inventory = atoi(inventoryStr);

                    Items newItem(itemName, price, inventory);
                    
                    // Load existing items to check for duplicates
                    vector<Items> existingItems = loadItemsFromFile("items.bin");

                    bool itemExists = false;
                    for (const auto& item : existingItems) 
                    {
                        if (strcmp(item.itemname, newItem.itemname) == 0) 
                        {
                            itemExists = true;
                            break;
                        }
                    }

                    if (!itemExists) 
                    {
                        item.push_back(newItem);
                        appendItem(newItem);

                        const char* successImage = "additemsuccess.jpg";
                        loadimage(successImage);
                        getch();

                        // Reset after adding item
                        currentField = -1;
                        memset(itemName, 0, sizeof(itemName));
                        memset(priceStr, 0, sizeof(priceStr));
                        memset(inventoryStr, 0, sizeof(inventoryStr));

                        allitempage();
                    } 
                    else 
                    {
                        const char* errorImage = "duplicateitem.jpg";
                        loadimage(errorImage);
                        getch();
                        additem();
                        return;
                    }
                }
                else 
                {
                    // Move to the next field
                    currentField++;
                }
            }
            else if (ch == 8 && currentField != -1)  // Backspace key pressed
            {
                // Handle backspace for the current field
                if (currentField == 0 && strlen(itemName) > 0)
                    itemName[strlen(itemName) - 1] = '\0';
                else if (currentField == 1 && strlen(priceStr) > 0)
                    priceStr[strlen(priceStr) - 1] = '\0';
                else if (currentField == 2 && strlen(inventoryStr) > 0)
                    inventoryStr[strlen(inventoryStr) - 1] = '\0';
            }
            else if (isalnum(ch) || isspace(ch))  // Valid input characters
            {
                if (currentField == 0 && strlen(itemName) < sizeof(itemName) - 1)
                    strncat(itemName, &ch, 1);
                else if (currentField == 1 && strlen(priceStr) < sizeof(priceStr) - 1 && isdigit(ch))
                    strncat(priceStr, &ch, 1);
                else if (currentField == 2 && strlen(inventoryStr) < sizeof(inventoryStr) - 1 && isdigit(ch))
                    strncat(inventoryStr, &ch, 1);
            }

            // Clear and redraw the field background to erase previous text
            setfillstyle(SOLID_FILL, COLOR(252, 243, 231));
            if (currentField == 0)
                bar(599, 253, 969, 298);  // Item Name field
            else if (currentField == 1)
                bar(599, 324, 969, 370);  // Price field
            else if (currentField == 2)
                bar(599, 398, 969, 442);  // Inventory field

            // Display the current text in the selected field
            setcolor(BLACK);
            setbkcolor(COLOR(252, 243, 231));
            if (currentField == 0)
                outtextxy(597 + 5, 251 + 5 + 5, itemName);
            else if (currentField == 1)
                outtextxy(597 + 5, 322 + 5 + 5, priceStr);
            else if (currentField == 2)
                outtextxy(597 + 5, 395 + 10, inventoryStr);
        }
    }
}



void allitempage()
{
    // Load background image
    const char* image = "allitem.jpg";
    loadimage(image);


    // Save items to file
    saveItemsToFile(item, "items.bin");

    // Load items from file
    item = loadItemsFromFile("items.bin");

    int y = 200; // Y-coordinate for the starting position

    setcolor(WHITE);
    setbkcolor(COLOR(47, 117, 110));
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Set text style

    for (size_t i = 0; i < item.size(); i++)
    {
        // Display Item Name
        char itemName[100];
        sprintf(itemName, "%s", item[i].itemname);
        outtextxy(326 + 50 + 10 + 10, y, itemName); 

        // Display Price
        char price[50];
        sprintf(price, "Rs. %d", item[i].price);
        outtextxy(508 + 40 + 200 + 25, y, price);

        // Display Inventory
        char inventory[50];
        sprintf(inventory, "%d", item[i].inventory);
        outtextxy(856 + 40 + 200 + 20 + 20, y, inventory);

        setcolor(WHITE);
        line(300, y + 32, 1290, y + 32);

        y += 40; // Display next user data

        setcolor(WHITE);
    }

    char searchText[20] = {0};
    int searchTextLength = 0;
    bool searchBarActive = false;
    
    Items foundItem;

    //bool editMode = false;  // Flag to track if edit mode is active
    int selectedField = -1; // Track which field is selected for editing (0 for name, 1 for price, 2 for inventory)

    // Declare variables for storing price and inventory as strings
    char price[50] = "";       // To store the price as a string
    char inventory[50] = "";   // To store the inventory as a string


    while (true) 
    {
        if (ismouseclick(WM_LBUTTONDOWN)) 
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if (x >= 275 && x <= 355 && y >= 20 && y <= 87) 
            {
                admin_das();
                break;
            }

            // Check if CUstomer button is clicked
            if (x >= 50 && x <= 171 && y >= 232 && y <= 342) 
            {
                //Customer List
                cuslistpage();
                break;
            }

            // Check if Transaction button is clicked
            if (x >= 50 && x <= 171 && y >= 446 && y <= 556) 
            {
                transactionpage();
                break;
            }

            // Check if Add item button is clicked
            if (x >= 1237 && x <= 1306 && y >= 25 && y <= 92) 
            {
                additem();
                
                allitempage();
                break;
            }

            // Check if Search bar is clicked
            if (x >= 800 && x <= 1200 && y >= 34 && y <= 87) 
            {
                searchBarActive = true;

                // Draw the rectangle excluding the rounded corners
                setcolor(RED);
                line(830, 34, 1178, 34);   // Top line
                line(830, 86, 1178, 86);   // Bottom line

                // Draw the vertical sides of the rectangle
                line(804, 60, 804, 60);  // Left line
                line(1204, 60, 1204, 60);  // Right line

                // Draw the arcs (assuming the left and right edges are rounded)
                arc(830, 60, 90, 270, 26);    // Left arc
                arc(1178, 60, 270, 90, 26);   // Right arc
        
            }

            // Check if Search icon is clicked
            if (x >= 1147 && x <= 1203 && y >= 34 && y <= 87) 
            {
                if (searchTextLength == 0)
                { 
                    clearmouseclick(WM_LBUTTONDOWN);  // Clear mouse click buffer
                    while (kbhit()) getch();

                    const char* image = "searchempty.jpg";
                    loadimage(image);
                    getch();

                    allitempage();
                    return;

                }
                if (searchItem(searchText, foundItem)) 
                {
                    // Load the edit item page and display the found item details
                    const char* editImage = "edititem.jpg";
                    loadimage(editImage);

                    displayItemDetails(foundItem);

                    // Call the function to edit item details
                    editItemDetails(foundItem);

                    // Save the updated items to the file
                    saveItemsToFile(item, "items.bin");
                    
                } 
                else 
                {
                    const char* image = "itemnoexist.jpg";
                    loadimage(image);
                    getch();
                    allitempage();
                    return;
                }

                searchTextLength = 0;
                searchBarActive = false;
                memset(searchText, 0, sizeof(searchText));
                
            }
            
        }

        // Handle keyboard input for the search bar
        if (searchBarActive && kbhit()) 
        {
            char ch = getch();
            if (ch == 8) 
            { // Backspace key
                if (searchTextLength > 0) 
                {
                    searchText[--searchTextLength] = '\0';
                }
            } 
            else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || isspace(ch)) 
            { 
                // A-Z or a-z
                if (searchTextLength < sizeof(searchText) - 1) 
                {
                    searchText[searchTextLength++] = ch;
                    searchText[searchTextLength] = '\0';
                }
            }
            // Clear and redraw the search bar background
            setfillstyle(SOLID_FILL, WHITE);
            bar(832, 38, 1155, 81);

            // Display the current search text in the search bar
            setcolor(BLACK);
            setbkcolor(WHITE);
            outtextxy(835, 47, searchText);
        }


    }

}



void admin_das()
{
    const char* image = "admindas.jpg";
    loadimage(image);

    while (true)
    {
        
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if(x >= 10 && x <= 90 && y >= 371 && y <= 435)
            {
                LoginRegister_page();
                break;
            }
        
            // Check if Customer List Icon clicked
            if(x >= 148 && x <= 478 && y >= 265 && y <= 551)
            {
                //customer list
                cuslistpage();
                break;
            }
            // Check if Transaction Icon clicked
            if (x >= 565 && x <= 890 && y >= 265 && y <= 551)
            {
                //transaction
                transactionpage();
                break;
            }
            // Check if All Items Icon clicked
            else if (x >= 981 && x <= 1307 && y >= 265 && y <= 551)
            {
                // items select
                allitempage();
                break;
            }
    
        }
    
    }
            
    getch();


}



void admin_loginpage()
{
    const char* image = "admin_login.jpg";
    loadimage(image);

    admin_login();
}



// Function to login into admin account
void admin_login()
{
    char username[20] = {0}, password[20] = {0};
    int currentField = 0;  // Start with no field selected
    int previousField = 0; // To keep track of the previously selected field
    int mycolor = COLOR(207, 209, 210);

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            previousField = currentField; // Update previousField before changing currentField

            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                LoginRegister_page();
                break;
            }
            // Check if the username field is clicked
            if (x >= 679 && x <= 1115 && y >= 261 && y <= 314)
            {
                currentField = 1;  // Username field selected
            }
            else if (x >= 679 && x <= 1115 && y >= 365 && y <= 418)
            {
                currentField = 2;  // Password field selected
            }
            else if (x >= 765 && x <= 1029 && y >= 480 && y <= 542)
            {
                // Submit button clicked
                if (strlen(username) == 0 || strlen(password) == 0)
                {
                    const char* image = "adminfillerror.jpg";
                    loadimage(image);
                    getch();
                    admin_loginpage();
                }  
                else
                {
                    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
                    {
                        const char* image = "adminloginsuccess.jpg";
                        loadimage(image);
                        getch();
                        admin_das();// Call the admin dashboard or main menu function here
                    }
                    else
                    {
                        const char* image = "adminnamepwerror.jpg";
                        loadimage(image);
                        getch();
                        admin_loginpage();
                    }
                }
                break;
            }

            // Clear the previous rectangle when a new field is selected
            if (previousField != 0 && previousField != currentField)
            {
                setcolor(mycolor);
                    if (previousField == 1)
                    {
                        rectangle(681, 263, 1112, 311);
                    }
                    else if (previousField == 2)
                    {
                        rectangle(681, 367, 1112, 415);
                    }
            }
        }

        if (kbhit() && currentField != 0)
        {
            char ch = getch();
            if (ch == 13) // ENTER key
            {
                previousField = currentField;

                if (currentField == 1)
                {
                    currentField = 2;  // Move to password field
                }
                else if (currentField == 2)
                {
                    // Submit the form
                    if (strlen(username) == 0 || strlen(password) == 0)
                    {
                        const char* image = "adminfillerror.jpg";
                        loadimage(image);
                        getch();
                        admin_loginpage();
                    }  
                    else
                    {
                        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
                        {
                            const char* image = "adminloginsuccess.jpg";
                            loadimage(image);
                            getch();
                             admin_das();// Call the admin dashboard or main menu function here
                        }
                        else
                        {
                            const char* image = "adminnamepwerror.jpg";
                            loadimage(image);
                            getch();;
                            admin_loginpage();
                        }
                    }
                    break;
                }

                // Clear the previous rectangle when moving to the next field
                if (previousField != 0 && previousField != currentField)
                {
                    setcolor(mycolor);
                    if (previousField == 1)
                    {
                        rectangle(681, 263, 1112, 311);
                    }
                    else if (previousField == 2)
                    {
                        rectangle(681, 367, 1112, 415);
                    }
                }
            }
            else if ( ch == 8 ) // Backspace to delete characters
            {
                if (currentField == 1 && strlen(username) > 0)
                {
                    username[strlen(username) - 1] = '\0';  // Remove last character
                    outtextxy(686, 274, (char*)"                                                     "); // Clear the text area
                    outtextxy(686, 274, username); // Redraw updated username
                }
                else if (currentField == 2 && strlen(password) > 0)
                {
                    password[strlen(password) - 1] = '\0';  // Remove last character
                    outtextxy(686, 381, (char*)"                                                     "); // Clear the text area
                    for (int i = 0; i < strlen(password); i++)
                    {
                        outtextxy(686 + i * 10, 381, (char*)"*"); // Redraw updated password
                    }
                }
            }
            else
            {
                if (currentField == 1 && strlen(username) < 19)
                {
                    username[strlen(username)] = ch;
                }
                else if (currentField == 2 && strlen(password) < 19)
                {
                    password[strlen(password)] = ch;
                }

                // Update the display for each field
                setbkcolor(mycolor);
                setcolor(BLACK);
                outtextxy(686, 274, username);
                for (int i = 0; i < strlen(password); i++)
                {
                    outtextxy(686 + i * 10, 381, (char*)"*");
                }
            }
        }

        // Draw the inside rectangle for the selected field
        if (currentField == 1)
        {
            setcolor(RED);
            rectangle(681, 263, 1112, 311);  // Slightly inside the username field
        }
        else if (currentField == 2)
        {
            setcolor(RED);
            rectangle(681, 367, 1112, 415);  // Slightly inside the password field
        }
    }
}



//check psw and username
bool isOutExist(const char* username)
{
    ifstream readfile("users.bin", ios::binary);
    char existingUsername[20] = {0};
    char existingPassword[20] = {0};

    while ((readfile.read((char*)&existingUsername, sizeof(existingUsername))) && (readfile.read((char*)&existingPassword, sizeof(existingPassword))))
    {
        if ((strcmp(existingUsername, username) == 0))
        {
            readfile.close();
            return true;  // Username is not unique
        }
    }

    readfile.close();
    return false;  // Username is unique
}



void out_loginpage()
{
    const char* image = "outlogin.jpg";
    loadimage(image);

    outlogin();
}



// Function to login into admin account
void outlogin()
{
    char username[20] = {0};
    char password[20] = "XXXX";
    int currentField = 0;  // Start with no field selected
    int previousField = 0; // To keep track of the previously selected field
    int mycolor = COLOR(207, 209, 210);

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            previousField = currentField; // Update previousField before changing currentField

            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                LoginRegister_page();
                break;
            }

            // Check if the username field is clicked
            if (x >= 671 && x <= 1107 && y >= 303 && y <= 357)
            {
                currentField = 1;  // Username field selected
            }
            else if (x >= 789 && x <= 1053 && y >= 480 && y <= 542)
            {
                // Submit button clicked
                if (strlen(username) == 0)
                {
                    const char* image = "outfillerror.jpg"; // Error message display
                    loadimage(image);
                    getch();
                    out_loginpage();
                }
                else if (isOutExist(username))
                {
                    const char* image = "outuserexist.jpg";  // Display an error message indicating the username already exists
                    loadimage(image);
                    getch();
                    out_loginpage();
                    break;
                }
                else
                {
                    ofstream writefile("outsiders.bin", ios::binary | ios::app); // Write to file
                    writefile.write((char*)&username, sizeof(username)); // Missing semicolon fixed here
                    
                    writefile.close();
                    const char* image = "outsuccess.jpg";
                    loadimage(image);
                    getch();
                    char password[20]="XXXX";
                    items_selection(username,password);
                }
                break;
            }
        }

        // Clear the previous rectangle when a new field is selected
        if (previousField != 0 && previousField != currentField)
        {
            setcolor(mycolor);
            if (previousField == 1)
            {
                rectangle(671, 303, 1107,357);
            }
        }

        if (kbhit() && currentField != 0)
        {
            char ch = getch();
            if (ch == 13) // ENTER key
            {
                if (strlen(username) == 0)
                {
                    const char* image = "outfillerror.jpg"; // Error message display
                    loadimage(image);
                    getch();
                    out_loginpage();
                }
                else if (isOutExist(username))
                {
                    const char* image = "outuserexist.jpg";  // Display an error message indicating the username already exists
                    loadimage(image);
                    getch();
                    out_loginpage();
                    break;
                }
                else
                {
                    ofstream writefile("outsiders.bin", ios::binary | ios::app); // Write to file
                    writefile.write((char*)&username, sizeof(username)); // Missing semicolon fixed here
                    writefile.close();
                    const char* image = "outsuccess.jpg";
                    loadimage(image);
                    getch();
                    char password[20]="XXXX";
                    items_selection(username,password);
                }
                break;
            }
            else if ( ch == 8 ) // Backspace to delete characters
            {
                if (currentField == 1 && strlen(username) > 0)
                {
                    username[strlen(username) - 1] = '\0';  // Remove last character
                    outtextxy(671+7, 303+13, (char*)"                                                     "); // Clear the text area
                    outtextxy(671+7, 303+13, username); // Redraw updated username
                }
            }
            else
            {
                if (currentField == 1 && strlen(username) < 19)
                {
                    username[strlen(username)] = ch;
                }

                // Update the display for each field
                setbkcolor(mycolor);
                setcolor(BLACK);
                outtextxy(671+7, 303+13, username);
            }
        }

        // Draw the inside rectangle for the selected field
        if (currentField == 1)
        {
            setcolor(RED);
            rectangle(671, 303, 1107,357);  // Slightly inside the username field
        }
    }
}



//check psw and username
bool isUserExist(const char* username, const char* password)
{
    ifstream readfile("users.bin", ios::binary);
    char existingUsername[20] = {0};
    char existingPassword[20] = {0};

    while ((readfile.read((char*)&existingUsername, sizeof(existingUsername))) && (readfile.read((char*)&existingPassword, sizeof(existingPassword))))
    {
        if ((strcmp(existingUsername, username) == 0) && ((strcmp(existingPassword, password) == 0)))
        {
            readfile.close();
            return true;  // Username is not unique
        }
    }

    readfile.close();
    return false;  // Username is unique
}



bool pincheck(char username[20],char pincode[5])
{
    
    ifstream readfile("pincode.bin", ios::binary);
    char existingUsername[20] = {0};
    char existingpincode[5] = {0};

    while ((readfile.read((char*)&existingUsername, sizeof(existingUsername))) && (readfile.read((char*)&existingpincode, sizeof(existingpincode))))
    {
        if ((strcmp(existingUsername, username) == 0) && ((strcmp(existingpincode,pincode) == 0)))
        {
            readfile.close();
            return true;  // Username is not unique
        }
    }

    readfile.close();
    return false; 

}



void resetpage()
{
    const char* image = "resetpage.jpg";  // success message indicating the username already exists
    loadimage(image);
    char username[20] = {0}, password[20] = {0}, confirmPassword[20] = {0}, pincode[5] = {0}, balanceStr[20];
   
    int currentField = 0;  // Start with no field selected
    int previousField = 0; // To keep track of the previously selected field
    int mycolor = COLOR(207, 209, 210);

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            previousField = currentField; // Update previousField before changing currentField

            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                loginpage();
                break;
            }

            // Check if the username field is clicked
            if (x >= 703 && x <= 1139 && y >= 234 && y <= 288)
            {
                currentField = 1;  // Username field selected
            }
            else if (x >= 703 && x <= 1139 && y >= 319 && y <= 372)
            {
                currentField = 2;  // Password field selected
            }
            else if (x >= 703 && x <= 1139 && y >= 403 && y <= 456)
            {
                currentField = 3;  // Confirm Password field selected
            }
            else if (x >= 703 && x <= 1139 && y >= 487 && y <= 531)
            {
                currentField = 4;  // Pin code field selected
            }
            else if (x >= 789 && x <= 1053 && y >= 575 && y <= 637)
            {
                // Submit button clicked
                if (strlen(username) == 0 || strlen(password) == 0 || strlen(confirmPassword) == 0 || strlen(pincode) == 0)
                {
                    const char* image = "resetfillerror.jpg";
                    loadimage(image);
                    getch();
                    resetpage();
                }
                else if (!pincheck(username,pincode))
                {
                    const char* image = "mismatchpin.jpg";  // Display an error message indicating the username already exists
                    loadimage(image);
                    getch();
                    resetpage();
                }
                else if (strcmp(password, confirmPassword) !=0)
                {
                    const char* image = "resetpwunmatch.jpg";
                    loadimage(image);
                    getch();
                 resetpage();

                    
                }
                else
                {
                    char fileusername[20] = {0};
                    char filepassword[20] = {0};
                    char filebalance[20] = {0};
                       fstream file("UserBalance.bin", ios::in | ios::out | ios::binary);
                    
                    if (!file) 
                    {
                    cout << "File could not be opened!" << endl;
                    return;
                    }

                    while (!file.eof())
                    {

                        file.read((char*)&fileusername, sizeof(fileusername));
                        file.read((char*)&filepassword, sizeof(filepassword));  
                        file.read((char*)&filebalance, sizeof(filebalance));

                        // cout << endl << fileusername << endl;
                        // cout << username << endl;
                        // cout << "Check1" << endl;
                        // cout << filebalance << endl;
                    
                        // balance = atoi(filebalance);

                        if (strcmp(username, fileusername) == 0)
                        {
                            
                            file.seekp(-(int)sizeof(filebalance), ios::cur);
                             file.seekp(-(int)sizeof(filepassword), ios::cur);
                            file.write((char*)&password, sizeof(password));

                            
                            file.close();
                            break;

                            
                        }
                    }
                    file.close();

                         fstream afile("users.bin", ios::in | ios::out | ios::binary);
                    
                    if (!afile) 
                    {
                    cout << "File could not be opened!" << endl;
                    return;
                    }

                    while (!afile.eof())
                    {

                        afile.read((char*)&fileusername, sizeof(fileusername));
                        afile.read((char*)&filepassword, sizeof(filepassword));  
                       

                        // cout << endl << fileusername << endl;
                        // cout << username << endl;
                        // cout << "Check1" << endl;
                        // cout << filebalance << endl;
                    
                        // balance = atoi(filebalance);

                        if (strcmp(username, fileusername) == 0)
                        {
                            
                           
                             afile.seekp(-(int)sizeof(filepassword), ios::cur);
                             cout<<"pincode";
                            afile.write((char*)&password ,sizeof(password));

                            
                            afile.close();
                            break;

                            
                        }
                    }
                    afile.close();


                   const char* image = "resetsuccess.jpg";
                    loadimage(image);
                    getch();

                    loginpage(); 
                }
                break;
            }

            // Clear the previous rectangle when a new field is selected
            if (previousField != 0 && previousField != currentField)
            {
                setcolor(mycolor);
                if (previousField == 1)
                {
                    rectangle(705, 236, 1136, 285);
                }
                else if (previousField == 2)
                {
                    rectangle(705, 321, 1136, 369);
                }
                else if (previousField == 3)
                {
                    rectangle(705, 405, 1136, 453);
                }
                else if (previousField == 4)
                {
                    rectangle(705, 489, 1136, 538);
                }
            }
        }

        if (kbhit() && currentField != 0)
        {
            char ch = getch();
            if (ch == 13) // ENTER key
            {
                previousField = currentField;

                if (currentField == 1)
                {
                    currentField = 2;  // Move to password field
                }
                else if (currentField == 2)
                {
                    currentField = 3;  // Move to confirm password field
                }
                else if (currentField == 3)
                {
                    currentField = 4;  // Move to pin code field
                }
                else if (currentField == 4)
                {
                    if (strlen(username) == 0 || strlen(password) == 0 || strlen(confirmPassword) == 0 || strlen(pincode) == 0)
                {
                    const char* image = "resetfillerror.jpg";
                    loadimage(image);
                    getch();
                    resetpage();
                }
                else if (!pincheck(username,pincode))
                {
                    const char* image = "mismatchpin.jpg";  // Display an error message indicating the username already exists
                    loadimage(image);
                    getch();
                    resetpage();
                }
                else if (strcmp(password, confirmPassword) !=0)
                {
                    const char* image = "resetpwunmatch.jpg";
                    loadimage(image);
                    getch();
                 resetpage();

                    
                }
                else
                {
                    char fileusername[20] = {0};
                    char filepassword[20] = {0};
                    char filebalance[20] = {0};
                       fstream file("UserBalance.bin", ios::in | ios::out | ios::binary);
                    
                    if (!file) 
                    {
                    cout << "File could not be opened!" << endl;
                    return;
                    }

                    while (!file.eof())
                    {

                        file.read((char*)&fileusername, sizeof(fileusername));
                        file.read((char*)&filepassword, sizeof(filepassword));  
                        file.read((char*)&filebalance, sizeof(filebalance));

                        // cout << endl << fileusername << endl;
                        // cout << username << endl;
                        // cout << "Check1" << endl;
                        // cout << filebalance << endl;
                    
                        // balance = atoi(filebalance);

                        if (strcmp(username, fileusername) == 0)
                        {
                            
                            file.seekp(-(int)sizeof(filebalance), ios::cur);
                             file.seekp(-(int)sizeof(filepassword), ios::cur);
                            file.write((char*)&password, sizeof(password));

                            
                            file.close();
                            break;

                            
                        }
                    }
                    file.close();

                         fstream afile("users.bin", ios::in | ios::out | ios::binary);
                    
                    if (!afile) 
                    {
                    cout << "File could not be opened!" << endl;
                    return;
                    }

                    while (!afile.eof())
                    {

                        afile.read((char*)&fileusername, sizeof(fileusername));
                        afile.read((char*)&filepassword, sizeof(filepassword));  
                       

                        // cout << endl << fileusername << endl;
                        // cout << username << endl;
                        // cout << "Check1" << endl;
                        // cout << filebalance << endl;
                    
                        // balance = atoi(filebalance);

                        if (strcmp(username, fileusername) == 0)
                        {
                            
                           
                             afile.seekp(-(int)sizeof(filepassword), ios::cur);
                             cout<<"pincode";
                            afile.write((char*)&password ,sizeof(password));

                            
                            afile.close();
                            break;

                            
                        }
                    }
                    afile.close();


                   const char* image = "resetsuccess.jpg";
                    loadimage(image);
                    getch();

                    loginpage(); 
                }
                break;
                }

                // Clear the previous rectangle when moving to the next field
                if (previousField != 0 && previousField != currentField)
                {
                    setcolor(mycolor);
                    if (previousField == 1)
                    {
                        rectangle(705, 236, 1136, 285);
                    }
                    else if (previousField == 2)
                    {
                        rectangle(705, 321, 1136, 369);
                    }
                    else if (previousField == 3)
                    {
                        rectangle(705, 405, 1136, 453);
                    }
                    else if (previousField == 4)
                    {
                        rectangle(705, 489, 1136, 538);
                    }
                }
            }
            else if (ch == 8) // Backspace to delete characters
            {
                if (currentField == 1 && strlen(username) > 0)
                {
                    username[strlen(username) - 1] = '\0';  // Remove last character
                    outtextxy(710, 247, (char*)"                                                     "); // Clear the text area
                    outtextxy(710, 247, username); // Redraw updated username
                }
                else if (currentField == 2 && strlen(password) > 0)
                {
                    password[strlen(password) - 1] = '\0';  // Remove last character
                    outtextxy(710, 335, (char*)"                                                     "); // Clear the text area
                    for (int i = 0; i < strlen(password); i++)
                    {
                        outtextxy(710 + i * 10, 335, (char*)"*"); // Redraw updated password
                    }
                }
                else if (currentField == 3 && strlen(confirmPassword) > 0)
                {
                    confirmPassword[strlen(confirmPassword) - 1] = '\0';  // Remove last character
                    outtextxy(710, 420, (char*)"                                                     "); // Clear the text area
                    for (int i = 0; i < strlen(confirmPassword); i++)
                    {
                        outtextxy(710 + i * 10, 420, (char*)"*"); // Redraw updated confirm password
                    }
                }
                else if (currentField == 4 && strlen(pincode) > 0)
                {
                    pincode[strlen(pincode) - 1] = '\0';  // Remove last character
                    outtextxy(710, 505, (char*)"                                                     "); // Clear the text area
                    outtextxy(710, 505, pincode); // Redraw updated pin code
                }
            }
            else
            {
                if (currentField == 1 && strlen(username) < 19)
                {
                    username[strlen(username)] = ch;
                }
                else if (currentField == 2 && strlen(password) < 19)
                {
                    password[strlen(password)] = ch;
                }
                else if (currentField == 3 && strlen(confirmPassword) < 19)
                {
                    confirmPassword[strlen(confirmPassword)] = ch;
                }
                else if (currentField == 4 && strlen(pincode) < 4)
                {
                    if (isdigit(ch)) // Check if the character is a digit
                    {
                        pincode[strlen(pincode)] = ch;
                    }
                }

                // Update the display for each field
                setbkcolor(mycolor);
                setcolor(BLACK);
                outtextxy(710, 247, username);
                for (int i = 0; i < strlen(password); i++)
                {
                    outtextxy(710 + i * 10, 335, (char*)"*");
                }
                for (int i = 0; i < strlen(confirmPassword); i++)
                {
                    outtextxy(710 + i * 10, 420, (char*)"*");
                }
                outtextxy(710, 505, pincode);
            }
        }

        // Draw the inside rectangle for the selected field
        if (currentField == 1)
        {
            setcolor(RED);
            rectangle(705, 236, 1136, 285);  // Slightly inside the username field
        }
        else if (currentField == 2)
        {
            setcolor(RED);
            rectangle(705, 321, 1136, 369);  // Slightly inside the password field
        }
        else if (currentField == 3)
        {
            setcolor(RED);
            rectangle(705, 405, 1136, 453);  // Slightly inside the confirm password field
        }
        else if (currentField == 4)
        {
            setcolor(RED);
            rectangle(705, 489, 1136, 538);  // Slightly inside the pin code field
        }
    }
     
    getch();
}




//loginpage
void loginpage()
{
    const char* image = "cuslogin.jpg";
    loadimage(image);

    loginUser();
}



// Function to handle user registration
void loginUser()
{
    char username[20] = {0}, password[20] = {0};
    int currentField = 0;  // Start with no field selected
    int previousField = 0; // To keep track of the previously selected field
    int mycolor = COLOR(207, 209, 210);

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            previousField = currentField; // Update previousField before changing currentField

            // Check if Back button is clicked
            if (x >= 10 && x <= 90 && y >= 371 && y <= 438)
            {
                LoginRegister_page();
                break;
            }

            // Check if the username field is clicked
            if (x >= 703 && x <= 1139 && y >= 234 && y <= 288)
            {
                currentField = 1;  // Username field selected
            }
            else if (x >= 703 && x <= 1139 && y >=319 && y <= 371)
            {
                currentField = 2;  // Password field selected
            }
           
            else if (x >= 789 && x <= 1053 && y >= 480 && y <= 542)
            {
                 if (strlen(username) == 0 || strlen(password) == 0 )
                {
                    const char* image = "cusfillerror.jpg";
                    loadimage(image);
                    getch();
                    loginpage();
                }
                else if (isUserExist(username,password))
                {
                    const char* image = "cusloginsuccess.jpg";  // success message indicating the username already exists
                    loadimage(image);
                    getch();

                    items_selection(username,password);
                    //order page
                }
                else if (!isUserExist(username,password))
                {
                    const char* image = "cusfail.jpg";  // Display an error message indicating the username already exists
                    loadimage(image);
                    getch();
                    loginpage();
                }
                break;
            }
            else if(x >= 798 && x <= 1047 && y >= 574 && y <= 601)
            {
                   resetpage();
                   return;
            }

            // Clear the previous rectangle when a new field is selected
            if (previousField != 0 && previousField != currentField)
            {
                setcolor(mycolor);
                    if (previousField == 1)
                    {
                        rectangle(703, 234, 1139, 288);
                    }
                    else if (previousField == 2)
                    {
                        rectangle(703, 319, 1139, 371);
                    }                 
            }
        }

        if (kbhit() && currentField != 0)
        {
            char ch = getch();
            if (ch == 13) // ENTER key
            {
                previousField = currentField;

                if (currentField == 1)
                {
                    currentField = 2;  // Move to password field
                }
                else if (currentField == 2)
                {
                    // Submit the form
                   if (strlen(username) == 0 || strlen(password) == 0 )
                {
                    const char* image = "cusfillerror.jpg";
                    loadimage(image);
                    getch();
                    loginpage();
                }
                else if (isUserExist(username,password))
                {
                    const char* image = "cusloginsuccess.jpg";  // success message indicating the username already exists
                    loadimage(image);
                    getch();
                    items_selection(username, password);
                    //order page
                }
                else if (!isUserExist(username,password))
                {
                    const char* image = "cusfail.jpg";  // Display an error message indicating the username already exists
                    loadimage(image);
                    getch();
                    loginpage();
                }
   
                    break;
                }

                // Clear the previous rectangle when moving to the next field
                if (previousField != 0 && previousField != currentField)
                {
                    setcolor(mycolor);
                    if (previousField == 1)
                    {
                        rectangle(703, 234, 1139, 288);
                    }
                    else if (previousField == 2)
                    {
                        rectangle(703, 319, 1139, 371);
                    }
                   
                }
            }
            else if ( ch == 8 ) // Backspace to delete characters
            {
                if (currentField == 1 && strlen(username) > 0)
                {
                    username[strlen(username) - 1] = '\0';  // Remove last character
                    outtextxy(703+7, 234+13, (char*)"                                                     "); // Clear the text area
                    outtextxy(703+7, 234+13, username); // Redraw updated username
                }
                else if (currentField == 2 && strlen(password) > 0)
                {
                    password[strlen(password) - 1] = '\0';  // Remove last character
                    outtextxy(703+7, 319+13, (char*)"                                                     "); // Clear the text area
                    for (int i = 0; i < strlen(password); i++)
                    {
                        outtextxy(703+7 + i * 10, 319+13, (char*)"*"); // Redraw updated password
                    }
                }
               
               
            }
            else
            {
                if (currentField == 1 && strlen(username) < 19)
                {
                    username[strlen(username)] = ch;
                }
                else if (currentField == 2 && strlen(password) < 19)
                {
                    password[strlen(password)] = ch;
                }
               
                // Update the display for each field
                setbkcolor(mycolor);
                setcolor(BLACK);
                outtextxy(703+7, 234+13, username);
                for (int i = 0; i < strlen(password); i++)
                {
                    outtextxy(703+7 + i * 10, 319+13, (char*)"*"); // Redraw updated password
                }
               
            }
        }

        // Draw the inside rectangle for the selected field
        if (currentField == 1)
        {
            setcolor(RED);
            rectangle(703, 234, 1139, 288);  // Slightly inside the username field
        }
        else if (currentField == 2)
        {
            setcolor(RED);
            rectangle(703, 319, 1139, 371);  // Slightly inside the password field
        }
       
    }
}



void items_selection(char username[20], char password[20])
{
    const char* image = "select1menu.jpg";
    loadimage(image);
 int BOARDGREEN = COLOR(22, 60, 20); 
    char fileusername[20] = {0};
    char filepassword[20] = {0};
    char filebalance[20] = {0};

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

    if(strcmp(password, "XXXX") == 0)
    {
        setcolor(WHITE);
        setbkcolor(BOARDGREEN);
        outtextxy(1030, 46, username);
        outtextxy(1011, 101, (char*) "Rs.");
        outtextxy(1060, 101, password);
        

    }
    else
    {
        ifstream readfile("UserBalance.bin", ios::binary);
        while (!readfile.eof())
        {

            readfile.read((char*)&fileusername, sizeof(fileusername));
            readfile.read((char*)&filepassword, sizeof(filepassword));  
            readfile.read((char*)&filebalance, sizeof(filebalance));
            
            if (strcmp(username, fileusername) == 0)
            {
                setcolor(WHITE);
        setbkcolor(BOARDGREEN);
                outtextxy(1030, 43, fileusername);
                outtextxy(1011, 97, (char*) "Rs.");
                outtextxy(1038, 97, filebalance);
                
                readfile.close();
                break;

                
            }
        }

        readfile.close();

    }



    // Order Menu
    all_items();

    index = 0;

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_RBUTTONDOWN))
        {
            int x, y, a = 0;
            if(ismouseclick(WM_LBUTTONDOWN))
            {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            }
            if(ismouseclick(WM_RBUTTONDOWN))
            {
            getmouseclick(WM_RBUTTONDOWN, x, y);
            }
            // Check if Back button is clicked
            if (x >= 154 && x <= 234 && y >= 37 && y <= 105)
            {   
                for (int i = 0; i < 100; i++) 
                {
                    selected_items[i] = 0;
                }
                LoginRegister_page();
                break;
            }
            //check if refresh button is clicked 
            if (x >= 123 && x <= 161 && y >= 151 && y <= 188)
            {   
                for (int i = 0; i < 100; i++) 
                {
                    selected_items[i] = 0;
                }
                items_selection(username,password);
                break;
            }


            for(int i=1; i <= item.size(); i++)
            {
                if (x >= 58 && x <= 416 && y >= 242 + a && y <= 287 + a)
                {
                    selected_items[index] = i;
                    index += 1;

                    // Draw a small tick mark enclosed in a green square at the top right corner
                    int square_size = 15;
                    int square_x = 416 - square_size - 5;
                    int square_y = 242 + a + 5;
                    
                    // Draw the green square boundary
                    setcolor(LIGHTGREEN);
                    rectangle(square_x, square_y, square_x + square_size, square_y + square_size);

                    // Draw the white tick mark inside the square
                    setcolor(WHITE);
                    line(square_x + 3, square_y + square_size / 2, square_x + square_size / 2, square_y + square_size - 3);
                    line(square_x + square_size / 2, square_y + square_size - 3, square_x + square_size - 3, square_y + 3);

                    break; // Ensure only one field is selected at a time
                }
                a = a + 70;
            }

            // Proceed button clicked
            if (x >= 535 && x <= 799 && y >= 681 && y <= 743)
            {
                if (index == 0)  // No items selected
                {
                    const char* image = "noitemerror.jpg";
                    loadimage(image);
                    getch();

                    items_selection(username, password);;
                }
                else
                {
                    finalarray();
                    receipt_page(username,password);
                    break;
                }
            }
        } 
    }

    getch();
}


void finalarray()
{
    for (int i=0; i<index; i++)
    {
        cout << selected_items[i] << " ";
    }
    cout << endl;

    

    int n = sizeof(selected_items) / sizeof(selected_items[0]);

    // set is used to remove duplicates
    set <int> uniqueSet(selected_items, selected_items + n);

    // Converts the set back to a vector (or array)
    vector <int> uniqueVec(uniqueSet.begin(), uniqueSet.end());

    // Output the unique values
    int i = 0;
    for (int value : uniqueVec) 
    {
        cout << value << " ";
        final_items[i] = value;
        i++;
    }
    cout << endl;
    no_ofitems = i-1;
    
    for(int j = 1; j <i; j++)
    {
        cout << final_items[j] << " ";
    }

}



void receipt_page(char username[20],char password[20])
{
    const char* image = "receiptpage.jpg";
    loadimage(image);

    receipt(username,password);
}



void CheckStockLimit(int* amounts, string* quantities,char username[20],char password[20])  //pointers that takes pre-declared pointers
{
    char b[100],c[100],d[100];
    int count=0;

    for (int i = 0; i < no_ofitems; i++)
    {
        int qty = atoi(quantities[i].c_str()); // Convert quantity string to integer
        amounts[i] = item[final_items[i + 1] - 1].price * qty; // Multiply price by quantity
    }

    for (int i = 0; i < no_ofitems; i++)
    { 
        int qty = atoi(quantities[i].c_str()); // Convert quantity string to integer
        
        if( item[final_items[i + 1] - 1].inventory<qty)
        {
            const char* image = "stocklimit.jpg";
            loadimage(image);
            strcpy(c, item[final_items[i + 1] - 1].itemname);
            setbkcolor(COLOR(252,243,231));
            outtextxy(824+15, 282+15, c);
            sprintf(b, "%d",  item[final_items[i + 1] - 1].inventory);
            strcpy(c, b);
            outtextxy(824+15, 375+15, c);
            count++;
            getch();
        }
    }

    if(count > 0)
    {
        for (int i = 0; i < no_ofitems; i++)
        {
            amounts[i] = '\0'; // Reset amounts[]
        }

        receipt_page(username, password);

    }
    
}



void remainbalance(int rembalance, int totalamt, char username[20], char password[20])
{
    const char* image = "remainbalance.jpg";
    loadimage(image);
    char b[50] = {0};
   
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);

    sprintf(b,"%d",totalamt);
    setfillstyle(SOLID_FILL, COLOR(217, 217, 217));
    bar(707, 250, 1026, 318);
    setbkcolor(COLOR(217, 217, 217));
    outtextxy(755,267,b);

    sprintf(b,"%d",rembalance);
    setfillstyle(SOLID_FILL, COLOR(217, 217, 217));
    bar(707, 408, 1026, 476);
    setbkcolor(COLOR(217, 217, 217));
    outtextxy(755,425,b);


    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            
            getmouseclick(WM_LBUTTONDOWN, x, y);
            // Check if Go TO MENU button clicked
            if (x >= 735 && x <= 998 && y >= 531 && y <= 591)
            {   
               items_selection(username,password);
                break;
            }
            // Check if LOG OUT button clicked
            if (x >= 568 && x <= 798 && y >= 694 && y <= 748)
            {
                const char* image = "outropage.jpg";
                loadimage(image);
    

                getch();
                menupage();
            }

        }
    }
    
}



void payment_cus(char username[20], char password[20], int totalamt, int balance, int d)
{
    int passamount = 0;
    
    if(balance < totalamt || balance == 0)
    {
        const char* image = "balanceerror.jpg";    // Error message display
        loadimage(image);

        getch();

        cout << endl << balance;
        
        for (int i = 0; i < 100; i++) 
        {
            selected_items[i] = 0;
        
        }
        items_selection(username, password);
    }
    else
    {
        const char* image = "confirmpay.jpg";    // Error message display
        loadimage(image);

        int a=0;
        char b[100];
       
        setcolor(BLACK);
        setbkcolor(COLOR(252,243,231));
        // Displays Selected Items
        for (int i=1; i <= no_ofitems; i++)
        {
            int qty = atoi(arr[i-1].c_str());
            if (qty != 0)
            {

                cout << item[final_items[i] - 1].itemname;
                strcpy(b, item[final_items[i] - 1].itemname);

                if(i!=no_ofitems)
                {
                    strcat(b,", ");
                    outtextxy(511 + a, 318, b);
                }
                else
                {
                    outtextxy(511 + a, 318, b);
                }

                a = a + textwidth(b);
            }
 
        }
        // Displays Total Amount
        sprintf(b, "%d", totalamt);
        outtextxy(511, 431, b);

        

        while (true)
        {
            // Handle mouse clicks
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                int x, y;
                getmouseclick(WM_LBUTTONDOWN, x, y);

                // Check if Cancel button is clicked
                if (x >= 435 && x <= 668 && y >= 536 && y <= 591)
                {
                    for (int i = 0; i < 100; i++) 
                    {
                        selected_items[i] = 0;
                    }
                    items_selection(username, password); 
               
                    break; // Exit the while loop
                }

                // Check if Confirm button is clicked
                if (x >= 762 && x <= 992 && y >= 536 && y <= 591)
                {

                    for (int i = 1; i <= no_ofitems; i++)
                    {
                        int qty = atoi(arr[i-1].c_str());
                        item[final_items[i] - 1].inventory -= qty;
                    }

                    const char* image = "paysuccess.jpg";    // Error message display
                    loadimage(image);

                    getch();

                    for (int i = 0; i < 100; i++) 
                    {
                        selected_items[i] = 0;
                    }

                    // Updating Balance
                    int balance;
                    char fileusername[20] = {0};
                    char filepassword[20] = {0};
                    char filebalance[20] = {0};

                    fstream file("UserBalance.bin", ios::in | ios::out | ios::binary);
                    
                    if (!file) 
                    {
                    cout << "File could not be opened!" << endl;
                    return;
                    }

                    while (!file.eof())
                    {

                        file.read((char*)&fileusername, sizeof(fileusername));
                        file.read((char*)&filepassword, sizeof(filepassword));  
                        file.read((char*)&filebalance, sizeof(filebalance));

                        cout << endl << fileusername << endl;
                        cout << username << endl;
                        cout << "Check1" << endl;
                        cout << filebalance << endl;
                    
                        balance = atoi(filebalance);

                        if (strcmp(username, fileusername) == 0)
                        {
                            balance = balance - totalamt;
                            snprintf(filebalance, sizeof(filebalance), "%d", balance);
                            file.seekp(-(int)sizeof(filebalance), ios::cur);
                            file.write((char*)&filebalance, sizeof(filebalance));

                            
                            file.close();
                            break;

                            
                        }
                    }
                    file.close();

                    
                    int year, month, date;

                    year = get_year();
                    month = get_month();
                    date = get_date();

                    char syear[5], smonth[5], sdate[5];

                    snprintf(syear, sizeof(syear), "%d", year);
                    snprintf(smonth, sizeof(smonth), "%d", month);
                    snprintf(sdate, sizeof(sdate), "%d", date);

                    cout << syear << "/" << smonth << "/" << sdate << endl;

                    ofstream writefile("transaction.bin", ios::binary | ios::app);

                    if (!writefile) 
                    {
                        cout << "File could not be opened!" << endl;
                        return;
                    }
                     else
                    {

                        for (int i=1; i <= no_ofitems; i++)
                        {
                            int qty = atoi(arr[i-1].c_str());                        
                                
                            if (qty != 0)
                            {   
                                int amounts = qty * item[final_items[i] - 1].price;  // Calculate amount
                                float amount=0.0;
                                
                                if(d == 1)
                                {
                                    amount=amounts-(amounts*0.1);
                                    amounts=int(amount);
                                }
                                
                                strcpy(b, item[final_items[i] - 1].itemname);
                                writefile.write((char*)&syear, sizeof(syear));
                                writefile.write((char*)&smonth, sizeof(smonth));
                                writefile.write((char*)&sdate, sizeof(sdate));
                                writefile.write((char*)&fileusername, sizeof(fileusername));
                                writefile.write((char*)&b, sizeof(b));
                                writefile.write((char*)&qty, sizeof(qty));
                                writefile.write((char*)&amounts, sizeof(amounts));  // Store amount
                            
                                
                            }
                            
                
                        }

                        writefile.close();
                        
                    }

                    


                    // For Demo
                    remainbalance(balance, totalamt,username,password);
                    //items_selection(username, password); 
               
                    getch();
               
                    break; // Exit the while loop

                }

            }
        }

        getch();

    }
    
}




void payment_out(char username[20],char password[20],int totalamt)
{
    const char* image = "confirmpay.jpg";    // Error message display
    loadimage(image);

    int a=0;
    char b[100];
       
    setcolor(BLACK);
    setbkcolor(COLOR(252,243,231));
        
    // Displays Selected Items
    for (int i=1; i <= no_ofitems; i++)
    {
        int qty = atoi(arr[i-1].c_str());
        
        if (qty != 0)
        {

            cout << item[final_items[i] - 1].itemname;
            strcpy(b, item[final_items[i] - 1].itemname);

            if(i!=no_ofitems)
            {
                strcat(b,", ");
                outtextxy(511 + a, 318, b);
                
            }
            else
            {
                outtextxy(511 + a, 318, b);
            
            }

            a = a + textwidth(b);
            
        }
 
    }
        
    // Displays Total Amount
    sprintf(b, "%d", totalamt);
    outtextxy(511, 431, b);
        
    while (true)
    {
        // Handle mouse clicks
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Cancel button is clicked
            if (x >= 435 && x <= 668 && y >= 536 && y <= 591)
            {
                for (int i = 0; i < 100; i++) 
                {
                    selected_items[i] = 0;
                    
                }
                    
                items_selection(username, password); 
               
                break; // Exit the while loop
                
            }

            // Check if Confirm button is clicked
            if (x >= 762 && x <= 992 && y >= 536 && y <= 591)
            { 
                //updating inventory
                for (int i = 1; i <= no_ofitems; i++)
                {
                    int qty = atoi(arr[i-1].c_str());
                    item[final_items[i] - 1].inventory -= qty;
                    
                }

                int year, month, date;
                int balance;
                char fileusername[20] = {0};
                char filepassword[20] = {0};
                char filebalance[20] = {0};

                year = get_year();
                month = get_month();
                date = get_date();

                char syear[5], smonth[5], sdate[5];
                strcpy(fileusername,username);

                snprintf(syear, sizeof(syear), "%d", year);
                snprintf(smonth, sizeof(smonth), "%d", month);
                snprintf(sdate, sizeof(sdate), "%d", date);

                cout << syear << "/" << smonth << "/" << sdate << endl;
                ofstream writefile("transaction.bin", ios::binary | ios::app);

                if (!writefile) 
                    {
                        cout << "File could not be opened!" << endl;
                        return;
                    }
                    else
                    {

                        for (int i=1; i <= no_ofitems; i++)
                        {
                            int qty = atoi(arr[i-1].c_str());                        
                                
                            if (qty != 0)
                            {   
                                int amount = qty * item[final_items[i] - 1].price;  // Calculate amount

                                strcpy(b, item[final_items[i] - 1].itemname);
                                writefile.write((char*)&syear, sizeof(syear));
                                writefile.write((char*)&smonth, sizeof(smonth));
                                writefile.write((char*)&sdate, sizeof(sdate));
                                writefile.write((char*)&fileusername, sizeof(fileusername));
                                writefile.write((char*)&b, sizeof(b));
                                writefile.write((char*)&qty, sizeof(qty));
                                writefile.write((char*)&amount, sizeof(amount));  // Store amount
                            
                                
                            }
                        
                
                        }

                        writefile.close();
                        
                    }

                for (int i = 0; i < 100; i++) 
                {
                    selected_items[i] = 0;
                    
                }

                const char* image = "outpay.jpg";    
                loadimage(image);
                                   
                while (true)
                {
                    // Handle mouse clicks
                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        int x, y;
                        getmouseclick(WM_LBUTTONDOWN, x, y);

                        // Check if Exit button is clicked
                        if (x >=597  && x <=828 && y >= 531 && y <=584)
                        { 
                            cout<<"click"<<endl;
                            menupage();
                            break;
                                
                        }
                    }

                    // Detects Keyboard hit
                    if(kbhit())
                    {
                        menupage();
                        break;
                                    
                    }

    
                }
                                
                getch();
                    
                break; // Exit the while loop
                
            }
        
        }

    }
    
}



void receipt(char username[20], char password[20])
{ 
    int balance;

    char fileusername[20] = {0};
    char filepassword[20] = {0};
    char filebalance[20] = {0};



    if(strcmp(password, "XXXX") == 0)
    {
        setbkcolor(COLOR(14, 168, 145));
        outtextxy(660, 82, username);
        outtextxy(1046, 82, password);
        

    }
    else
    {
        ifstream readfile("UserBalance.bin", ios::binary);
        while (!readfile.eof())
        {

            readfile.read((char*)&fileusername, sizeof(fileusername));
            readfile.read((char*)&filepassword, sizeof(filepassword));  
            readfile.read((char*)&filebalance, sizeof(filebalance));

            cout << endl << fileusername << endl;
            cout << username << endl;
            cout << "Check1" << endl;
            cout << filebalance << endl;

            balance=atoi(filebalance);
            
            if (strcmp(username, fileusername) == 0)
            {
                cout << "Check2";
                setbkcolor(COLOR(14, 168, 145));
                outtextxy(660, 82, fileusername);
                outtextxy(1046, 82, filebalance);
                
                readfile.close();
                break;

                
            }
        }

        readfile.close();

    }

    

    if(no_ofitems<=0)
    {
        while (true)
        {
            // Handle mouse clicks
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                int x, y;
                getmouseclick(WM_LBUTTONDOWN, x, y);

                // Check if Back button is clicked
                if (x >= 0 && x <= 80 && y >= 343 && y <= 410)
                {
                    for (int i = 0; i < 100; i++) 
                    {
                        selected_items[i] = 0;
                    }
                    items_selection(username, password); // Navigate back to the previous page
               
                    return; // Exit the while loop
                }
            }
        }
    }


    int mycolor = COLOR(207, 209, 210);  // Default color for deselecting
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    int DARKCYANGREEN = COLOR(0, 100, 100);  // RGB values for a dark cyan green
    setbkcolor(DARKCYANGREEN);

    int r = 0;
    char b[50];

    // Draw all rectangles
    for (int i = 1, a = 0; i <= no_ofitems; i++, a += 68)
    {
        r = final_items[i];

        setcolor(WHITE);

        rectangle(210, 229 + a, 464, 276 + a);
        rectangle(545, 229 + a, 654, 276 + a);
        rectangle(748, 229 + a, 857, 276 + a);  // QTY. Rectangle
        rectangle(928, 229 + a, 1178, 276 + a);  // AMOUNT Rectangle

        setcolor(mycolor);
        setfillstyle(SOLID_FILL, mycolor);
        bar(748, 229 + a, 857, 276 + a);
        setbkcolor(DARKCYANGREEN);

        sprintf(b, "%d", item[r-1].price);

        setcolor(WHITE);
        
        outtextxy(260, 240 + a , item[r-1].itemname);
        outtextxy(576, 240 + a, b);

        delay(20);
    }
    
    b[50] = {0};

    int currentBox = 1;
    int previousBox = 0;
    char qtyText[20] = {0};
    arr = new string[no_ofitems];
    amounts = new int[no_ofitems]{0}; // Array to store calculated amounts
    
    while (true)
    {
       
        // Detect Keyboard Hit
        if (kbhit() && currentBox != 0)
        {
            char ch = getch();

            if ( ch == 13 )  // ENTER key to move to the next box
            {
                arr[currentBox - 1] = qtyText;
                previousBox = currentBox;

                // Clear the highlight from the previous box
                setcolor(mycolor);
                rectangle(748, 229 + (previousBox - 1) * 68, 857, 276 + (previousBox - 1) * 68);

                // Clear and re-display the stored qtyText
                setfillstyle(SOLID_FILL, mycolor);
                bar(749, 230 + (previousBox - 1) * 68, 856, 275 + (previousBox - 1) * 68);
                setbkcolor(mycolor);
                setcolor(BLACK);
                strcpy(b, arr[previousBox - 1].c_str());
                outtextxy(758, 240 + (previousBox -1) * 68, b);

                // Automatically move to the next box
                if (currentBox < no_ofitems)
                {
                    currentBox++;

                    // Load any previously stored quantity into qtyText
                    strncpy(qtyText, arr[currentBox - 1].c_str(), sizeof(qtyText) - 1);
                    qtyText[sizeof(qtyText) -1] = '\0'; // Ensure null-termination

                    // Highlight the new selected rectangle
                    setcolor(RED);
                    rectangle(748, 229 + (currentBox - 1) * 68, 857, 276 + (currentBox - 1) * 68);

                    // Display the existing qtyText in the selected rectangle
                    setfillstyle(SOLID_FILL, mycolor);
                    bar(749, 230 + (currentBox - 1) * 68, 856, 275 + (currentBox - 1) * 68);
                    setbkcolor(mycolor);
                    setcolor(BLACK);
                    outtextxy(758, 240 + (currentBox - 1) * 68, qtyText);
                }
                else
                {
                    // If at the last box, trigger TOTAL AMOUNT action
                    if (currentBox == no_ofitems)
                    { 
                        // Perform the same operation as clicking the TOTAL AMOUNT button
                        arr[currentBox - 1] = qtyText;

                        // Calculate the total amounts
                        CheckStockLimit(amounts, arr,username,password);

                        // Display the calculated amounts in the AMOUNT rectangles
                        for (int i = 1, a = 0; i <= no_ofitems; i++, a += 68)
                        {
                            setcolor(WHITE);
                            setfillstyle(SOLID_FILL, DARKCYANGREEN);
                            bar(929, 230 + a, 1177, 275 + a); // Clear previous content in the AMOUNT rectangles
                            sprintf(b, "%d", amounts[i - 1]);
                            setbkcolor(DARKCYANGREEN);
                            outtextxy(960, 240 + a, b); // Display the calculated amount
                        }

                        // Calculate the sum of all amounts
                        int totalAmount = 0;
                        for (int k = 0; k < no_ofitems; k++)
                        {
                            totalAmount += amounts[k];
                        }

                        b[50] = {0};

                        // Display the total amount in the specified field
                        setcolor(WHITE);
                        setfillstyle(SOLID_FILL, COLOR(14, 168, 145));
                        bar(1046, 617, 1212, 661); // Clear previous content in the total amount rectangle
                        sprintf(b, "%d", totalAmount);
                        setbkcolor(COLOR(14, 168, 145));
                        outtextxy(1060, 629, b); // Display the total amount
                    }

                    // Reset currentBox to zero
                    currentBox = 0;
                }

            }
            else if ( ch == 8 )  // BACKSPACE key to delete characters
            {
                int len = strlen(qtyText);
                if (len > 0)
                {
                    qtyText[len - 1] = '\0';

                    // Clear the rectangle and re-display the updated qtyText
                    setfillstyle(SOLID_FILL, mycolor);
                    bar(749, 230 + (currentBox - 1) * 68, 856, 275 + (currentBox - 1) * 68);
                    setbkcolor(mycolor);
                    setcolor(BLACK);
                    outtextxy(758, 240 + (currentBox - 1) * 68, qtyText);
                }
            }
            else if (isdigit(ch)) // Accept only numeric input for quantities
            {
                int len = strlen(qtyText);
                if (len < sizeof(qtyText) - 1)
                {
                    qtyText[len] = ch;
                    qtyText[len + 1] = '\0';

                    // Clear the rectangle and re-display the updated qtyText
                    setfillstyle(SOLID_FILL, mycolor);
                    bar(749, 230 + (currentBox - 1) * 68, 856, 275 + (currentBox - 1) * 68);
                    setbkcolor(mycolor);
                    setcolor(BLACK);
                    outtextxy(758, 240 + (currentBox - 1) * 68, qtyText);
                }
            }
        }

        // Handle mouse clicks
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if Back button is clicked
            if (x >= 0 && x <= 80 && y >= 343 && y <= 410)
            {
                for (int i = 0; i < 100; i++) 
                {
                    selected_items[i] = 0;
                }
                items_selection(username, password); // Navigate back to the previous page
                delete[] arr;
                delete[] amounts;
                return; // Exit the while loop
            }

            // Pay button clicked
            if (x >= 568 && x <= 798 && y >= 694 && y <= 748)
            {
                // If the user didn't press ENTER, calculate the amounts now
                if (currentBox != 0)
                {
                    arr[currentBox - 1] = qtyText;
                }

                // Calculate the total amounts
                CheckStockLimit(amounts, arr, username, password);

                // Display the calculated amounts in the AMOUNT rectangles
                for (int i = 1, a = 0; i <= no_ofitems; i++, a += 68)
                {
                    setcolor(WHITE);
                    setfillstyle(SOLID_FILL, DARKCYANGREEN);
                    bar(929, 230 + a, 1177, 275 + a); // Clear previous content in the AMOUNT rectangles
                    sprintf(b, "%d", amounts[i - 1]);
                    setbkcolor(DARKCYANGREEN);
                    outtextxy(960, 240 + a, b); // Display the calculated amount
                }

                // Calculate the sum of all amounts
                int totalAmount = 0;
                for (int k = 0; k < no_ofitems; k++)
                {
                    totalAmount += amounts[k];
                }

                float disamount = 0.0;
                int disamt = 0;
                int d=0;
                if(strcmp(password,"XXXX")!=0)
                {
                    if (totalAmount > 500)
                    {
                        d = 1;
                        disamount = (totalAmount) - (0.1 * totalAmount);
                        disamt = (int)disamount;
                
                    }
                    else
                    {
                        d = 0;
                        disamt = totalAmount;
                
                    }
                }

                b[50] = {0};

                // Display the total amount in the specified field
                setcolor(WHITE);
                setfillstyle(SOLID_FILL, COLOR(14, 168, 145));
                bar(1046, 617, 1212, 661); // Clear previous content in the total amount rectangle
                sprintf(b, "%d", totalAmount);
                setbkcolor(COLOR(14, 168, 145));
                outtextxy(1046, 628, b);// Display the total amount

                if(strcmp(password,"XXXX")!=0)
                { 
                    if(d==0)
                    {
                        setbkcolor(COLOR(14, 168, 145));
                        bar(521, 620, 845, 660);
                        outtextxy(521+80, 629+3, (char *)"No discount!!");}
                    else
                    {
                        bar(733, 620, 845, 660);
                        sprintf(b, "%d", disamt);
                        outtextxy(733, 630, b);
                    }

                }
                else
                {
                    setbkcolor(COLOR(14, 168, 145));
                    bar(521, 620, 845, 660);
                    outtextxy(521+80, 629+3, (char *)"No discount!!");
                }

                delay(20);
                settextstyle(GOTHIC_FONT, HORIZ_DIR,1);
                setbkcolor(COLOR(3,68,61));
                outtextxy(245, 669, (char*)"PRESS ANY KEY TO  CONTINUE PAYMENT!!");
                settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

                // Hold the screen until any key is pressed
                getch();
                //delay(20);

                if (totalAmount == 0)
                {
                    const char* image = "totalamterror.jpg";    // Error message display
                    loadimage(image);

                    getch();

                    receipt_page(username, password);
                }



                if(strcmp(password, "XXXX") == 0)
                {
                    payment_out(username, password, totalAmount);
               
                }
                else
                {
                    payment_cus(username, password, disamt, balance, d);


                }
                

                // Delete dynamic arrays to prevent memory leak
                delete[] arr;
                delete[] amounts;

                return;
            }
            // Total Amount button clicked
            if (x >= 926 && x <= 1221 && y >=617 && y <= 665)
            {
                arr[currentBox - 1] = qtyText;

                // Calculate the total amounts
                CheckStockLimit(amounts, arr,username,password);

                // Display the calculated amounts in the AMOUNT rectangles
                for (int i = 1, a = 0; i <= no_ofitems; i++, a += 68)
                {
                    setcolor(WHITE);
                    setfillstyle(SOLID_FILL, DARKCYANGREEN);
                    bar(929, 230 + a, 1177, 275 + a); // Clear previous content in the AMOUNT rectangles
                    sprintf(b, "%d", amounts[i - 1]);
                    setbkcolor(DARKCYANGREEN);
                    outtextxy(960, 240 + a, b); // Display the calculated amount
                }

                // Calculate the sum of all amounts
                int totalAmount = 0;
                for (int k = 0; k < no_ofitems; k++)
                {
                    totalAmount += amounts[k];
                }

                b[50] = {0};

                // Display the total amount in the specified field
                setcolor(WHITE);
                setfillstyle(SOLID_FILL, COLOR(14, 168, 145));
                bar(1046, 617, 1212, 661); // Clear previous content in the total amount rectangle
                sprintf(b, "%d", totalAmount);
                setbkcolor(COLOR(14, 168, 145));
                outtextxy(1046, 628, b); // Display the total amount


            }          

            // Check if any quantity box is clicked
            for (int i = 1, a = 0; i <= no_ofitems; i++, a += 68)
            {
                if (x >= 748 && x <= 857 && y >= 229 + a && y <= 276 + a)
                {
                    // Before switching, store the current qtyText into arr[currentBox -1] if currentBox != 0 and currentBox != i
                    if (currentBox != 0 && currentBox != i)
                    {
                        arr[currentBox -1] = qtyText;

                        // Clear the previous rectangle when a new box is selected
                        setcolor(mycolor);
                        rectangle(748, 229 + (currentBox - 1) * 68, 857, 276 + (currentBox - 1) * 68);

                        // Clear and re-display the stored qtyText
                        setfillstyle(SOLID_FILL, mycolor);
                        bar(749, 230 + (currentBox - 1) * 68, 856, 275 + (currentBox - 1) * 68);
                        setbkcolor(mycolor);
                        setcolor(BLACK);
                        strcpy(b, arr[currentBox - 1].c_str());
                        outtextxy(758, 240 + (currentBox - 1) * 68, b);
                    }

                    // Set currentBox to the newly clicked box
                    currentBox = i;

                    // Load any previously stored quantity into qtyText
                    strncpy(qtyText, arr[currentBox - 1].c_str(), sizeof(qtyText) - 1);
                    qtyText[sizeof(qtyText) - 1] = '\0'; // Ensure null-termination

                    // Highlight the selected rectangle
                    setcolor(RED);
                    rectangle(748, 229 + a, 857, 276 + a);

                    // Display the existing qtyText in the selected rectangle
                    setfillstyle(SOLID_FILL, mycolor);
                    bar(749, 230 + a, 856, 275 + a);
                    setbkcolor(mycolor);
                    setcolor(BLACK);
                    outtextxy(758, 240 + a, qtyText);

                    break;  // Exit the for loop
                }
            }
        }

    }

    delete[] arr;
    delete[] amounts;

}



int main()
{

    initwindow(1366, 768, (char*)"Khwopa Canteen");
    clearviewport();

    intro();
    getch();

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setcolor(BLACK);


    item = loadItemsFromFile("items.bin"); // cannot be removed. Menupage will not work


    menupage();

    getch();

    closegraph();
    return 0;
}


void intro() 
{
    const char* image = "p1.jpg";
    loadimage(image);
}



#include <iostream>
#include <direct.h>
#include <windows.h>
#include <string>

using namespace std;

void main_menu();
void list_files();
void create_directory();
void change_directory();
void all_files();
void extension_files();
void name_wise();
void show_current_directory();  

string dir_path = ".";

int main() {
    while (true) {
        main_menu();
    }
    return 0;
}

void main_menu() {
    int choice;
    cout << endl << "     MENU OPTIONS\n";
    cout << "----------------------\n";
    cout << "1. Display List of Files\n";
    cout << "2. Create New Directory\n";
    cout << "3. Change the Working Directory\n";
    cout << "4. Show Current Directory\n";
    cout << "5. Exit\n";
    cout << "Enter the Number: ";  
    cin >> choice; 
    cout << endl;

    switch (choice) {
        case 1:
            list_files();
            break;
        case 2:
            create_directory();
            break;
        case 3:
            change_directory();
            break;
        case 4:
            show_current_directory();  
            break;
        case 5:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice, try again." << endl;   
    }
}

void list_files() {
    int choice;
    cout << "     LIST FILE DETAIL     \n";
    cout << "--------------------------\n";
    cout << "1. List All Files\n";
    cout << "2. List Files by Extension\n";
    cout << "3. List of Name Wise\n";
    cout << "Enter the Number: ";
    cin >> choice;
    cout << "\n"

    switch (choice) {
        case 1:
            all_files();
            break;
        case 2:
            extension_files();
            break;
        case 3:
            name_wise();
            break;
        default:
            cout << "Invalid choice, returning to main menu." << endl;
    }
}

void create_directory() {
    string dir_name;
    cout << "Enter the name of the directory to create: ";
    cin >> dir_name;

    if (_mkdir((dir_path + "\\" + dir_name).c_str()) == 0) {
        cout << "Directory created successfully.\n";
    } else {
        cout << "Failed to create directory or directory already exists.\n";
    }
}

void change_directory() {
    int choice;
    cout << "     Change Directory     \n";
    cout << "--------------------------\n";
    cout << "1. Move one step back (to the parent directory)\n";
    cout << "2. Go to Root Directory\n";
    cout << "3. Enter Directory\n";
    cout << "Enter the Number: ";
    cin >> choice;

    char dir_name[100];
    switch (choice) {
        case 1:
            _chdir("..");
            dir_path = ".";  
            break;
        case 2:
            _chdir("\\");
            dir_path = "\\";  
            break;
        case 3:
            cout << "Enter the Directory Name: ";
            cin >> dir_name;
            if (_chdir(dir_name) == 0) {
                dir_path = dir_name; 
            } else {
                cout << "Failed to change directory.\n";
            }
            break;
        default:
            cout << "Invalid choice, returning to main menu." << endl;
    }
}

void show_current_directory() {
    char buffer[MAX_PATH];
    if (_getcwd(buffer, MAX_PATH)) {
        dir_path = string(buffer);
        cout << "Current Directory: " << dir_path << endl;
    } else {
        cout << "Failed to get current directory.\n";
    }
}

void all_files() {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((dir_path + "\\*").c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "Failed to list files." << endl;
        return;
    }

    cout << "Listing all files:\n";
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            cout << findFileData.cFileName << endl;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void extension_files() {
    string ext;
    cout << "Enter the file extension (e.g., .txt, .doc, .cpp): ";
    cin >> ext;

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((dir_path + "\\*" + ext).c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "Failed to list files." << endl;
        return;
    }

    cout << "Listing files with extension " << ext << ":\n";
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            cout << findFileData.cFileName << endl;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void name_wise() {
    string pattern;
    cout << "Enter the file name pattern: ";
    cin >> pattern;

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((dir_path + "\\*" + pattern + "*").c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "Failed to list files." << endl;
        return;
    }

    cout << "Listing files matching pattern " << pattern << ":\n";
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            cout << findFileData.cFileName << endl;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}




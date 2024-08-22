#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void list_files();
void create_directory();
void change_directory();
void display_main_menu();

int main() {
    int choice;

    do {
        display_main_menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // To ignore newline character left in the buffer

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
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}

void display_main_menu() {
    std::cout << "\nDirectory Management System" << std::endl;
    std::cout << "1. List files in the current directory" << std::endl;
    std::cout << "2. Create a new directory" << std::endl;
    std::cout << "3. Change the working directory" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void list_files() {
    int list_choice;
    std::string extension, pattern;
    std::string current_directory = getcwd(NULL, 0);

    std::cout << "\nList Files Menu" << std::endl;
    std::cout << "1. List all files in the current directory" << std::endl;
    std::cout << "2. List files based on a specific extension (e.g., .txt)" << std::endl;
    std::cout << "3. List files based on a pattern (e.g., moha*.*)" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> list_choice;
    std::cin.ignore();

    DIR *dir;
    struct dirent *ent;
    dir = opendir(current_directory.c_str());

    if (dir != NULL) {
        switch (list_choice) {
            case 1:
                std::cout << "\nFiles in the current directory:" << std::endl;
                while ((ent = readdir(dir)) != NULL) {
                    if (ent->d_type == DT_REG)
                        std::cout << ent->d_name << std::endl;
                }
                break;
            case 2:
                std::cout << "Enter the file extension (e.g., .txt): ";
                std::getline(std::cin, extension);
                std::cout << "\nFiles with " << extension << " extension:" << std::endl;
                while ((ent = readdir(dir)) != NULL) {
                    std::string file_name = ent->d_name;
                    if (ent->d_type == DT_REG && file_name.size() >= extension.size() &&
                        file_name.substr(file_name.size() - extension.size()) == extension)
                        std::cout << file_name << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter the file pattern (e.g., moha*.*): ";
                std::getline(std::cin, pattern);
                std::cout << "\nFiles matching pattern \"" << pattern << "\":" << std::endl;
                while ((ent = readdir(dir)) != NULL) {
                    // Simplified pattern matching for demonstration purposes
                    if (ent->d_type == DT_REG && std::string(ent->d_name).find(pattern) != std::string::npos)
                        std::cout << ent->d_name << std::endl;
                }
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
    }
}

void create_directory() {
    std::string dir_name;
    std::cout << "Enter the name of the directory to create: ";
    std::getline(std::cin, dir_name);

    if (mkdir(dir_name.c_str(), 0777) == 0) {
        std::cout << "Directory " << dir_name << " created successfully." << std::endl;
    } else {
        perror("Failed to create directory");
    }
}

void change_directory() {
    int choice;
    std::string dir_name;

    std::cout << "\nChange Directory Menu" << std::endl;
    std::cout << "1. Move one step back (to the parent directory)" << std::endl;
    std::cout << "2. Move to the root directory" << std::endl;
    std::cout << "3. Move to a specific directory" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1:
            if (chdir("..") == 0) {
                std::cout << "Moved to the parent directory." << std::endl;
            } else {
                perror("Failed to move to parent directory");
            }
            break;
        case 2:
            if (chdir("/") == 0) {
                std::cout << "Moved to the root directory." << std::endl;
            } else {
                perror("Failed to move to root directory");
            }
            break;
        case 3:
            std::cout << "Enter the directory path: ";
            std::getline(std::cin, dir_name);
            if (chdir(dir_name.c_str()) == 0) {
                std::cout << "Changed directory to " << dir_name << std::endl;
            } else {
                perror("Failed to change directory");
            }
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
    }
}

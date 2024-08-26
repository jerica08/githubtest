#include <iostream>
#include <filesystem>
#include <fstream> 
#include <direct.h>

using namespace std;
namespace fs = filesystem;


fs::path dir_path = fs::current_path();

void main_menu();
void list_files();
void create_directory();
void change_directory();
void all_files();
void extension_files();
void name_wise();

int main(){
     
     
      while(true){
         main_menu ();
      }
      return 0;
}
         
void main_menu(){
   int choice;

   cout <<  endl << "     MENU OPTIONS\n";
   cout << "----------------------\n";
   cout << "1. To Display List of Files\n";
   cout << "2.To Create  New Directory\n";
   cout << "3. To Change the Working Directory\n";
   cout << "4.Exit\n";
   cout << "Enter the Number: ";  
   cin >> choice; 
   cout << endl;

     switch(choice){
      case 1:
               list_files();
               break;
         case 2:
               create_directory();
               break;
         case 3:
               cout << "Current Directory:" << dir_path << endl << endl;
               change_directory();

               break;
         case 4:
               cout << "Exiting program." << endl;
               break;
            default:
               cout << "Invalid choice, try again." << endl;   
               return main_menu();     
     }
       while (choice !=4);
      
}
void list_files(){
   int choice;
   
   cout << "     LIST FILE DETAIL     \n";
   cout << "--------------------------\n";
   cout << "1. List All Files\n";
   cout << "2. List of Extension Files\n";
   cout << "3. List of Name Wise\n";
   cout << "Enter th Number: ";
   cin >> choice;

   switch (choice){
      case 1:
          all_files();
           return main_menu();
          break;
      case 2:
          extension_files();
           return main_menu();
          break;
      case 3:
           name_wise();
            return main_menu();
           break;    
   }
       
}            
void create_directory(){ // To create a directory
      string dir_name;
        cout << "Enter the name of the directory to create: ";
        cin >> dir_name;
      

    fs::path dir_path = fs::current_path() / dir_name;

    if (fs::exists(dir_path)) {
         cout << "Directory already exists.\n";
    } else {
        if (fs::create_directory(dir_path)) {
            cout << dir_name << " " << "Directory created successfully.\n";
            cout << "Current Directory: " << dir_path  << endl;
        } else {
            cout << "Failed to create directory.\n";
            
        }
    }
      return main_menu();
   
} 
void change_directory(){ // To change a directory
   
   int choice;
   
   cout << "     Change Directory     \n";
   cout << "--------------------------\n";
   cout << "1. Step by Step Backward\n";
   cout << "2. Goto Root Directory\n";
   cout << "3. Forward Directory\n";
   cout << "Enter the Number:  ";
   cin >> choice;

   char dir_name[100];

    switch(choice){
         case 1:
            _chdir("..");
            cout << "Moved to parent directory.\n";

         break;
      case 2:
          _chdir("\\");
            cout << "Moved to root directory.\n";
         break;
      case 3:
           
         cout << "Please enter the Directory Name: ";
         cin >> dir_name;
            if (_chdir(dir_name) == 0) {
                cout << "Current Directory: " << dir_path << endl;
            } 
         return main_menu();
         break;
   }
   
    
}
void all_files(){ // To view all the files
   fs:: path directory = fs:: current_path();
   int file_count = 0;

   cout << endl << "Listing all Files" << endl << endl;
   for(const auto& entry : fs:: directory_iterator(fs::current_path())){
      cout << entry.path().filename().string() << endl; 
      file_count++;
   }
     cout << "Total File: " << file_count << endl;

    
}
void extension_files(){
     string ext;
      cout << "Enter the file extension (ex. .txt,.doc,pdf): ";
      cin >> ext;
      
       cout << "Listing all files with extension: " << endl;
       for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        if (entry.path().extension() == ext) {
            cout << entry.path().filename().string() << endl;
        }
         
    }
   
    
}
void name_wise(){
   string pattern;
    cout << "Enter the file pattern: ";
    cin >> pattern;

    cout << "\nListing all files matching the pattern " << pattern << ":\n";
    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        if (entry.path().filename().string().find(pattern) != string::npos) {
            cout << entry.path().filename().string() << endl;
        }
         
    }
   
    
}





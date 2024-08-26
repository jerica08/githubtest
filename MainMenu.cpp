#include <iostream>
#include <filesystem>
#include <fstream> 

using namespace std;
 namespace fs = filesystem;

string current_path = "C:mainfile";

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
               change_directory();
               
              
     }

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
          break;
      case 2:
          extension_files();
          break;
      case 3:
           name_wise();
           break;    
   }
       
}            
void create_directory(){ // To create a directory
       string dir_name;
   
       cout << "Enter the name of Directory: ";
       cin >> dir_name;

       if(fs::create_directory(dir_name)){
         cout << dir_name << " " << "Directory Successfully Created" << endl;
         cout << "Current Directory:" << current_path << endl;
       } else{
         cout << "Failed to create directory" << endl;
       }
     
   
} 
void change_directory(){ // To change a directory
   
   int choice;
   string path;
   
   cout << "     Change Directory     \n";
   cout << "--------------------------\n";
   cout << "1. Step by Step Backward\n";
   cout << "2. Goto Root Directory\n";
   cout << "3. Forward Directory\n";
   cout << "Enter the Number: \n";
   cin >> choice;
   cin >> path;

    switch(choice){
         case 1:
            fs::current_path(fs::current_path().parent_path());
            cout << "Moved to parent directory.\n";

         break;
      case 2:
           fs::current_path(fs::current_path().root_path());
            cout << "Moved to root directory.\n";
         break;
      case 3:
           string path;
    cout << "Enter the path to the directory: ";
            cin >> path;
            if (fs::exists(path) && fs::is_directory(path)) {
                fs::current_path(path);
                cout << "Directory changed successfully to: " << path << endl;
            } else {
                cout << "Failed to change directory. Check the path and try again.\n";
            }

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
      cout << "Enter the file extension (ex. .txt): ";
      cin >> ext;
      
       cout << "Listing all files with extension " << ext << ":\n";
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





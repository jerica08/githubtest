#include <iostream>
#include <fstream> 
#include <iostream>
#include <direct.h>
using namespace std;

string path = "C:\Documents\Jerica\githubtest";

int main(){
     
      while(true){
         main_menu();
      }
}
         
void main_menu(){
   int choice;

   cout << "     MENU OPTIONS\n";
   cout << "----------------------\n";
   cout << "1. To Display List of Files\n";
   cout << "2.To Create  New Directory\n";
   cout << "3. To Change the Working Directory\n";
   cout << "4.Exit\n";
   cout << "Enter the Number: \n";  
   cin >> choice;   

     switch(choice){
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
              
     }

}
void list_files(){
   int choice;
   
   cout << "     LIST FILE DETAIL     \n";
   cout << "--------------------------\n";
   cout << "1. List All Files\n";
   cout << "2. List of Extension Files\n";
   cout << "3. List of Name Wise\n";
   cout << "Enter th Number: \n";

   switch(choice){
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
void create_directory(){
   string dir_name;
      cout << "Enter the Directory name: \n";
   getline(cin,dir_name);
      cout << "Current directory: \n";
   if(mkdir(dir_name.c_str()) == 0){
      
      cout << "Directory" << dir_name << "created successfully.\n";
   }else{
      perror("Failed to create directory.");
   }

   cout << "Current directory: \n";
     
   
} 
void change_directory(){
   int choice;
   
   

   cout << "     Change Directory     \n";
   cout << "--------------------------\n";
   cout << "1. Step by Step Backward\n";
   cout << "2. Goto Root Directory\n";
   cout << "3. Forward Directory\n";
   cout << "Enter the Number: \n\n";
   cout << "Current Directory:\n";
   cin >> path;
   switch(choice){
         case 1:
           one_step_back();
         break;
      case 2:
           root_directory();
         break;
      case 3:
           forward_directory();
         break;


   }
}
void all_files(){
   system("C:\Documents\Jerica\githubtest");

}
void extension_files(){

}
void name_wise(){

}
void one_step_back(){

}
void root_directory(){

}
void forward_directory(){

}
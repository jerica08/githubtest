#include <iostream>
using namespace std;

class Queue{
	private:
		int front;
		int rear;
		int arr[5];
		
	public:
		Queue()
		{
		
			front = -1;
			rear = -1;
			for(int i=0;i<6;i++)
			{
				arr[i]=0;
			 } 
		}
		bool isEmpty()
		{
			if(front == -1 && rear ==-1)
				return true;
			else 
				return false;			
		}
		
		 bool isFull()
		{
			if (rear==4)
				return true;
			else 
				return false;	
		}		
	void insert (int val)
		{ if (isEmpty())
			{
				rear=0;
				front=0;
				arr[rear]=val;
			}
			else
			{ 
				rear++;
				arr[rear]=val;
				
			}
		  
		}
		
	void remove()
		{    
			int x;
			if(isEmpty())
			{
				cout << "Queue is EMPTY" <<endl;
				return;
			}
			else if (front == rear)
			{
				x = arr[front];
				arr[front]=0;
				front = -1;
				return  ;
			}
			else
			{x = arr[front];
				arr[front]=0;
				front++;
				return ;	
			}
			
		}
		
	void display()
			{
				cout <<"Value/s in the Queue"<< endl;
				cout <<"--------------------" << endl;
				for (int i= 0;i<5;i++)
				{
					cout <<arr[i]<<"  ";
				}
				    cout << "\n--------------------" << endl;
		}			
			
};

	int main(){
	Queue bbq;
	int option,value;
	
	
	do
	{
		cout << "\n\nWhat operator do you want to perform? Select option number." << endl;
		cout << "1. Insert" << endl;
		cout << "2. Remove" << endl;
		cout << "3. Check if Empty" << endl;
		cout << "Option:"; + option;
		cin >>option;
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				cout << "Enqueue Operation \n";
				cout << "Enter an item to Insert in the Queue: " << endl;
				cin >> value ;
				cout << "Added Value:" << value << endl;
				bbq.insert(value);
				bbq.display();
				break;
				
			case 2:
				cout << "Dequeue Operation \n";
				cout << "Removed value:";
				bbq.remove();
				bbq.display();
			
				break;
				
			case 3:
			    bbq.display();
                if (bbq.isEmpty()){
					cout<< "Queue is Empty" <<endl;
				}
				else {
                    cout <<"Queue is not Empty" << endl;  
				}						
			break;
				
			system("cls");
				break;
			default:
				cout << "Invalid.Enter proper option number." << endl;
				break;	
		}
			
				  
	}while (option!=0);
	
	return 0;
}

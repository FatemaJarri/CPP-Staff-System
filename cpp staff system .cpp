/* 
students-ID:
fatema Al jarri-2200003851
Leenah Alsheneber-2200002229
layal Abualsaud-2200005303
Sarah Alabbas-2200004557
Nouf Alshahrani-2190001231
Reham Alzahrani-2200001931
Dhikra Aldakheel- 2200003240
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double sum=0;

// struct function for contact for the user
struct Contact_Type{
string email; 
string phone;	
};

// struct function about staff information 
struct Employee{
  string name;
  int id;
  int age;
  string department;
  string position;
  int  salary;
  Contact_Type Conatct;  // array of struct calling Contact_Type stuct 
  };
  

    
    // add employee information function.
void addemp(Employee staff[],int size){
		for(int i=0;i<size;i++){
			// asking the user to enter their information 
	    cout << " >> Enter employee name, id, age, department, position, salary, email, and phone number : \n";
		cin>>staff[i].name>>staff[i].id>>staff[i].age>>staff[i].department>>staff[i].position>>staff[i].salary>>staff[i].Conatct.email>>staff[i].Conatct.phone;
		  cout<<"       ----------------------------------------------------------------"<<endl;
		}
		cout<<endl;
	}
     // display employees list function.
	void display(Employee staff[],int size){
		cout<<"\n~List of Employee: "<<endl;
		for(int i=0;i<size;i++)
		{
		cout<<"\nEmployee #"<<i+1<< endl;
		cout<<endl;	
		cout<<staff[i].name<<"  "<<staff[i].id<<"  "<<staff[i].age<<"  "<<staff[i].department<<"  "<<staff[i].position<<"  "<<staff[i].salary <<"  "<<staff[i].Conatct.email<<"  "<<staff[i].Conatct.phone<<endl;	
		cout<<endl;
		cout<<"-----------------------------------------------------------------------------"<<endl;
		}
		cout<<endl;
	}
	
// functions below belong to the update function called "updated"
	// updating name 
void editing_name(Employee em[],int i){
	cout<<"     >> Enter new name: ";
	cin>>em[i-1].name;
}
	// updating id
editing_id(Employee em[],int i){
	cout<<"     >> Enter new id: ";
	cin>>em[i-1].id;
}
// updating age 
void editing_age(Employee em[],int i){
	cout<<"    >> Enter new age: ";
	cin>>em[i-1].age;
}
// updating department
editing_department(Employee em[],int i){
	cout<<"    >> Enter new department: ";
	cin>>em[i-1].department;
}

 //updating position 
void editing_position(Employee em[],int i){
	cout<<"    >> Enter new position: ";
	cin>>em[i-1].position;
} 
 //updating salary 
void editing_salary(Employee em[],int i){
	cout<<"    >> Enter new salary: ";
	cin>>em[i-1].salary;
} 
//updating email
void editing_email(Employee em[],int i){
	cout<<"    >> Enter new email: ";
	cin>>em[i-1].Conatct.email;
}
//updating phone num
void editing_phone(Employee em[],int i){
	cout<<"    >> Enter new phone number: ";
	cin>>em[i-1].Conatct.phone;
}

// updating function 
void updated (Employee emm[],int size){
	char option;
	// depending on array size starting from 1 - till the user size
	int i;
	
	cout<<">> Enter the serial number of the selected staff (depending on the list you added) :"; 
    cin>>i;
    // choice menu for upditing user information 
	cout<<"\n>> What item Do You Want To Update"<<endl;

   cout<<"\n [n]Name \n [d]Department \n [i]id \n [a]Age \n [p]position \n [s]salary \n [e]Email \n [h]phone number";
   cout<<"\nEnter your Option Please ---->>  ";
   cin>>option;
   cout<<endl<<endl;
   switch(option){
   	case 'n':
   	editing_name(emm,i);
   	display(emm,size);
   	break;
   	case 'i':
	editing_id(emm,i);
	display(emm,size);
   	break;
   	case 'd':
	editing_department(emm,i);
	display(emm,size);
   	break;
   	case 'a':
	editing_age(emm,i);
	display(emm,size);
   	break;
   	case 'p':
   	editing_position(emm,i);
	display(emm,size);
   	break;
   	case 's':
   	editing_salary(emm,i);
	display(emm,size);
   	break;
   	case 'e':
   	editing_email(emm,i);
	display(emm,size);
   	break;
   	case 'h':
   	editing_phone(emm,i);
	display(emm,size);
   	break;
   	default: 
   	cout<<"The entered number wasn't on the list! " <<endl;
	     }


  }
   // overloading fuction called deleteEmp
  // delete function by name 
	void deleteEmp(Employee staff[],int &size, string name){
bool checkname=false;
		for (int i=0 ; i<size; i++){
			if (staff[i].name==name){
				checkname=true;
			for (int j=i ; j<size-1; j++){
				staff[j]=staff[j+1];
				}
				cout << ">> Employee deleted. "<<endl; 
				size--;	
				display(staff,size);
			}
		}
		if (checkname==false){
		cout<<"Employee not found!"<<endl;
		}
		 	
	}
	 // overloading delete function by id
		void deleteEmp(Employee staff[],int &size, int id){
		string name;
bool checked=false;
		for (int i=0 ; i<size; i++){
			if (staff[i].id==id){
				checked=true;
			for (int j=i ; j<size-1; j++){
				staff[j]=staff[j+1];
				}
				cout << ">> Employee deleted. "<<endl; 
				size--;	
				display(staff,size);
			}	 
		}
		if (checked==false){
		cout<<"Employee not found!"<<endl;	
		}
		 	
	}


// function to search by id 
void searchEmp(Employee staff[],int size){
		int id2;
		bool checkid=false;
		cout << "\nEnter the ID of the Employee you are searching for : "; 
		cin >> id2;
		cout<<endl;
		cout<<"-----------------------------------------------------------------------------"<<endl;
		for (int i=0 ; i<size; i++){
			if (staff[i].id==id2){
				checkid=true;
	cout << "            Employee found in location :        " << i+1<<endl;
	cout << "     --------------------------------------------               "<<endl;
			}
			
		}
		if(checkid==false){
		cout<<"ID is not found!"<<endl;
			cout<<endl;	
		}
		
	}
// function to sort employees by their age
	void sortEmp(Employee staff[],int size){
	cout<<endl<<"             Sorting employee by there ages ascendingly:              "<<endl;
	cout<<"            --------------------------------------------               "<<endl;
	
	struct Employee sort[size];
	struct Employee temp[size];
	 
	 int i ,j;
     
     // to check the size of the array.
    if (size<2){
    	cout<<"Nothing to sort!"<<endl; 
	}
	
	else {
		
	for (i=0;i<=size-1;i++){
	// to save emlpyees info in new array sort.
		sort[i]=staff[i];
	}
    for(i=0;i<size-1;i++) {
   for(j=0;j<size-1;j++){
 // to sort the the ages ascendingly.
   	if(sort[j].age>sort[j+1].age) {
    	temp[j]=sort[j];
    	sort[j]=sort[j+1];
    	sort[j+1]=temp[j];
    } 	
   }
	}
    cout<<"    Employees and their informations sorted ascendingly by the (age). "<<endl;
// calling display function to print the array after sorting.
    display(sort,size);
	}

}

// Function to calculate employee ages average.
double avg(Employee staff[],int size, double average, double sum=0){
// for loop to add employee ages 
	for(int i=0;i<size;i++){ 
	sum=sum+staff[i].age; 
	}
	average=sum/size;
	cout<<endl;
return average; 
}
// writing file to save changes.
void writeInFile(Employee staff[], int size ){
	
double av, total=0, x;
x=avg(staff,size,av,total);
 // output file
ofstream projectfile;
projectfile.open("cppsystem.txt",ios::out);
	if (projectfile.is_open()){
	projectfile<<"Employee ages average is : ";
		projectfile<<x;	
		projectfile<<endl;
		
		projectfile<<"Number of Employee(s)  : ";
		projectfile<<size;
		projectfile<<endl;
	}
		
		projectfile.close();
	}
	
// reading from file 
void  readFile(Employee emp[], int size){
	
  double av,x, sum=0;
  x=avg(emp,size,av,sum);
 // same file used in dataInFile function 
ifstream projectfile;

projectfile.open("cppsystem.txt",ios::in);
//print averge 
cout<<"Employee ages average is : ";
cout<<x;
projectfile>>x;
cout<<endl;

// print size 
cout<<"Number of Employee(s)  : ";
cout<<size;
projectfile>>size;

cout<<endl<<endl;


	projectfile.close();
}
	
//  menu function
void menu(int &num,Employee staff[],int &size)
	
{
	int answer,id;
	string name;
	switch(num){
	
		case 0:
		cout<<"\nGoodbye. Have a nice day!\n";
		break;
		case 1:
		addemp(staff,size);
		break;
		case 2:
		updated(staff,size);
		break;
		case 3:
		cout << "Which way do you prefer to delete your data:\n[1]ID \n[2]Name \nAnswer:   "; 
		cin >> answer;
		cout<<endl;
		if(answer==1){
		cout << "\nEnter ID of Employee to delete its information from the system: "; 
		cin >> id;
		cout<<endl;
		deleteEmp(staff,size, id);
		cout<<"The Number of Employee(s) now is: "<<size<<endl<<endl;
		}
		else if(answer==2){
		cout << "\nEnter name of Employee to delete its information from the system: "; 
		cin >> name;
		cout<<endl;
		deleteEmp(staff,size,name);
		cout<<"The Number of Employee(s) now is: "<<size<<endl<<endl;
		}
		else
		cout<<"The entered number wasn't on the list!\n "<<endl;
		break;
		case 4:
	    searchEmp(staff,size);
		break;
		case 5:
		sortEmp(staff,size);
		break;
		case 6:
		display(staff,size);
		break;
		case 7:// display averge of employee age & their size
		writeInFile(staff, size);
		readFile(staff, size);
		break;
		default: 
		cout<<"Invalid number, please pick a number from 1 to 7.\n"<<endl;
	}
	
}




int main(){	
    int size,i;
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t~~~(WELCOME TO THE CPP STAFF SYSTEM)~~~"<<endl;
    cout<<"\t\t\t\t\t\t\t---------------------------------------"<<endl;
cout<<endl;cout<<endl;
    cout<<">> Enter number of employees you want to modify in the system : ";
    cin>>size;
    cout<<"       ----------------------------------------------------------------"<<endl;
    int num;
	Employee em[size];
	
	
	do {
		
		// choices for menu 
        cout<<"  >> Please enter a number from the list \n*You will have to add items first if its the first time.*";
		cout<<"\n\n [1] add new item \n [2] update existed item \n [3] delete exited item "<<endl;
		cout<<" [4] search for an a item \n [5] sort the items \n [6] Display items \n [7] Display Statistical report    \n press 0 to quit."<<endl;
		 
		cout<<"\nAnswer:  ";
		cin>>num;
		cout<<endl;
		cout<<"-----------------------------------------------------------------------------"<<endl;
		menu(num,em,size);
		
		
	} while(num!=0);// to exit the program.
	

	return 0;
}

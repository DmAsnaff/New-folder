#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>


using namespace std;

class User{
	private:
		string fn, ln, reg, course, Ccode, email;
		char coursename[50],courselist;
		int y;
	public:
		void menu();
		void add();
		void display();
		void addcourse();
		void showcourses();
};
void User::menu(){
    menustart:
	int z;
	char x;
	cout << "\nWelcome to University student registration system" << endl;
	cout << "\n";
	cout << "1 - Student\n2 - Academics\n3 - Mgt staff\n4 - Admin\n5 - Exit\n" << endl;
	cout << "Login Through: ";
	cin >> z;

	switch(z){
	case 1:
		add();
		break;
    case 2:
        display();
		break;
    case 3:
        display();
		break;
    case 4:
        addcourse();
        break;
    case 5:
        exit(0);
	default:
		cout << "\nInvalid !\n" << endl;
	}

	goto menustart;
}

void User::add(){
	fstream doc;
	cout << "---------------\nEnter your details:\n" << endl;
	cout << "First name: ";
    cin >> fn;
    cout << "Last name: ";
    cin >> ln;
    cout << "Registration number: ";
    cin >> reg;
	cout << "Email: ";
	cin >> email;
    cout << "\nSelect the course:\n";
    showcourses();
    cout << "Enter the course code: ";
    cin >> course;

    cout << "\nSuccessfully registered !\n\n-------------\n";

    doc.open("Student.txt", ios::app | ios::out);
    doc << fn <<"\t" << ln << "\t" << reg << "\t" << email << "\t" << course << endl;
    doc.close();
}

void User::display(){
    fstream doc;
    doc.open("Student.txt",ios::in);
    doc >> fn >> ln >> reg >> email >> course;
    cout << "First name\tLast name\tReg No\tEmail\t\tCourse" << endl;
    while(!doc.eof()){
        cout << fn << " \t" << ln << "  \t" << reg << "\t" << email << "  \t" << course << endl;
        doc >> fn >> ln >> reg >> email >> course;
    }
    doc.close();
}

void User::addcourse(){
    fstream doc;
    cout << "1 - Add course\n2 - Add account\n3 - Total Available Courses" << endl;
    cout << "Choose Action: ";
    cin >> y;
    if(y==1){
        cout << "\nEnter the course code: ";
        cin >> Ccode;
        cin.ignore(); 
        cout << "Enter the course name: ";
        cin.getline(coursename, sizeof(coursename));

        cout << "\nSuccessfully added!" << endl;
        doc.open("courses.txt",ios::app | ios::out);
        doc << Ccode << " - " << coursename << endl;
        doc.close();
    }
    else if(y==2){
        add();
    }
     else if(y==3){
       showcourses();
    }
    else{
        cout << "\nInvalid  !" << endl;
    }
}

void User::showcourses(){
    fstream doc;
    cout << "Available Courses:" << endl;
    cout << "ICT2403 - Graphics and Image Processing\nICT2402 - Software Engineering\nICT2301 - Design and Analysis of Algorithms";
    doc.open("courses.txt",ios::in);
    doc >> Ccode >> coursename;
    cout << "\n";
    cout << Ccode << " " << coursename ;

    while(doc>>noskipws>>courselist){
        cout << courselist;
    }
    doc.close();
    cout << endl;
}

int main(){
	User srs;
	srs.menu();
	return 0;
}


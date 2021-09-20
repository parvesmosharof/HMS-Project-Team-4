#include<iostream>
#include<bits/stdc++.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#define ROWV 4
#define MAX_LIMIT 100
#define COLMNV 10
using namespace std;

void admin();
void user();
void admin_login();
void user_login();
void registration(string text, string fileName, void (*login)());
void admin_panel(string username);
void user_panel(string username);
void PatientInformationAdd();
void PatientInformationView();
void DoctorInformationAdd();

string header = "********************************************************";

int main() {
    int choice;
    system("cls");
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\t\t\t*                                                                  *\n";
    cout<<"\t\t\t*             Welcome To Hospital Management System                *\n";
    cout<<"\t\t\t*                                                                  *\n";
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\n\t\t\t==>   Dashboard   <== \n\n";
    for(int i=0; i<=119; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Admin \n";
    cout<<"\t\t\t2. User\n";
    cout<<"\t\t\t3. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        default:
            cout<<"Invalid choice";
            main();
    }

    return 0;
}

void admin() {
    int choice;
    system("cls");
    cout<<"*********************************Admin Panel*************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=80; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Register \n";
    cout<<"\t\t\t3. Go back \n";
    cout<<"\t\t\t4. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            admin_login();
            break;
        case 2:
            registration("Admin", "admin.txt", admin_login);
            break;
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            admin();
    }
}

void user() {
    int choice;
    system("cls");
    cout<<"********************************User Panel************************************\n";
    cout<<"\nOptions \n\n";
    for(int i=0; i<=80; i++) cout<<"-";
    cout<<"\n\n\t\t\t1. Login \n";
    cout<<"\t\t\t2. Register \n";
    cout<<"\t\t\t3. Go back \n";
    cout<<"\t\t\t4. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
        case 1:
            user_login();
            break;
        case 2:
            registration("User", "users.txt", user_login);
            break;
        case 3:
            main();
            break;
        default:
            cout<<"Invalid choice";
            user();
    }
}

void admin_login() {
    string username, password, uname, pass;
    int is_exists=0;
    system("cls");
    cout<<"*********************Admin login*************************\n\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream input("admin.txt");

    while (input>>uname>>pass)
        {
            if(uname == username && pass == password)
            {
                is_exists = 1;
            }
        }
    input.close();

    if (is_exists)
        {
            admin_panel(username);
        }
    else
    {
        cout<<"Invalid Login. Try again !\n";
        cout<<"Press enter to continue\n";
        cin.get();
        cin.get();
        admin_login();
    }
}

void user_login() {
    string username, password, uname, pass;
    int is_exists=0;
    system("cls");
    cout<<"*********************User login*************************\n\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream input("users.txt");

    while (input>>uname>>pass) {
        if(uname == username && pass == password) {
            is_exists = 1;
        }
    }
    input.close();

    if (is_exists)
        {
            user_panel(username);
        }
    else
        {
        cout<<"Invalid credentials. Try again !\n";
        cout<<"Press enter to continue\n";
        cin.get();
        cin.get();
        user_login();
        }
}

void registration(string text, string fileName, void (*login)()) {
    string username, password, email , phone_number;
    system("cls");
    cout<<"********************************"<< text << " " << "Panel************************************\n";
    cout<<"\nChoose a username and password \n\n";
    for(int i=0; i<=119; i++) cout<<"-";
    cout<<"\n\n\t\t\tEnter username: ";
    cin>>username;
    cout << "\t\t\tEnter Email: ";
    cin >> email;
    cout << "\t\t\tEnter Phone Number: ";
    cin >> phone_number;
    cout<<"\t\t\tEnter password: ";
    cin>>password;

    ofstream reg(fileName, ios::app);
    reg << username << " " << password << " " << email << endl;
    reg.close();
    system("cls");
    cout<<"********************************"<< text << " " << "Panel************************************\n";
    cout<<"\nRegistration Successfull\n";
    cout<<"Press enter to login";
    cin.get();
    cin.get();
    (*login)();
}

void admin_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************Admin panel*************************\n\n";
    cout << "Welcome to the admin portal " << username << ".\n";
    cout << "Options-> \n";
    cout <<"\t1. Add Patient Information \n";
    cout <<"\t2. View Patient Information \n";
    cout <<"\t3. Add Doctor Information \n";
    cout <<"\t4. Edit Patient Information \n";
    cout <<"\t5. Search Patient Information \n";
    cout <<"\t6. Delete Patient Information \n";
    cout <<"\t7. Go back \n";
    cout <<"\t8. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        PatientInformationAdd();
        break;
    case 2:
        PatientInformationView();
        break;
    case 3:
        cout << "Coming soon :)";
        break;
    case 4:
        cout << "Coming soon :)";
        break;
    case 5:
        cout << "Coming soon :)";
        break;
    case 6:
        cout << "Coming soon :)";
        break;
    case 7:
        main();
        break;
    default:
        cout<<"Invalid choice";
        admin_panel(username);
    }
}

void user_panel(string username) {
    int choice;
    system("cls");
    cout<<"*********************User panel*************************\n\n";
    cout << "Welcome to the user " << username << ".\n";
    cout << "Options-> \n";
    cout<<"\t1. Doctor Specialist \n";
    cout<<"\t2. Doctor Schedule \n";
    cout<<"\t2. Doctor Fee's \n";
    cout<<"\t2. Booking \n";
    cout<<"\t3. Go back \n";
    cout<<"\t9. Choose an option to continue: ";
    cin>>choice;

    switch (choice) {
    case 1:
        cout<<"Coming soon :)";
        break;
    case 2:
        cout<<"Coming soon :)";
        break;
    case 3:
        cout<<"Coming soon :)";
        break;
    case 4:
        main();
        break;
    default:
        cout<<"Invalid choice";
        user_panel(username);
    }
}







void PatientInformationAdd()
{
    ofstream patientFile("patient.txt", ios::app);
    string patient_name, disease, age, cabin_no, phone_number;
    cout << header << endl;
    cout << "Patient Information Add" << endl;
    cout << header << endl;
    cout << "  " << endl;
    cout << "Enter Patient's Name = " ;
    cin >> patient_name;
    cout << "Enter disease = ";
    cin >> disease;
    cout << "Enter the age =  ";
    cin >> age;
    cout << "Enter cabin no =  ";
    cin >> cabin_no;
    cout << "Enter phone number = ";
    cin >> phone_number;
    patientFile << patient_name << " " << disease << " " << age << " " << cabin_no << " " << phone_number << "\n";

    patientFile.close();

    cout << header << endl;
    cout << "Patient's Information  Data Saved Successfully !!" << endl
         << patient_name << endl;
    cout << header << endl;
}



void PatientInformationView()
{
    ifstream patientFile("patient.txt");
    char ch;
    string patient_name, disease, age, cabin_no, phone_number;
    if (!patientFile)
    {
        cout << "Data File Not Found !" << endl;
        exit(1);
    }
    cout<<"\t\t\t********************************************************************\n";
    cout<<"\t\t\t*            Patient Information View                              *\n";
    cout<<"\t\t\t********************************************************************\n";

    cout << "\t----------------------------------------------------------------------------------------------------------" << endl;

    while (patientFile >> patient_name >> disease >> age >> cabin_no >> phone_number)
    {
        if (patientFile >> patient_name >> disease >> age >> cabin_no >> phone_number)
        {
            cout << "\t Name = " << patient_name << " \t| Disease = " << disease << " \t| Age = " << age
                 << "  \t| Cabin no = " << cabin_no << "  \t| Phone Number no = " << phone_number <<  endl;
        }
    }
    patientFile.close();
    cout << "\t---------------------------------------------------------------------------------------------------------" << endl;
}





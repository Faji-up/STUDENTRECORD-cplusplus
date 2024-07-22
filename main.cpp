#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string FILENAME = "student_records.txt";

struct Student {
    int studentID;
    string fullName;
    string birthday;
    string address;
    char gender;
    string degreeProgram;
    int yearLevel;
};

void addNewRecord(Student* students, int& count);
void searchRecord(Student* students, int count);
void displayAllRecords();
void displaySpecificRecord(Student* students, int count);
void deleteRecord(Student* students, int& count);
void displayGroupInfo();
bool validateGender(char gender);

int main() {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        cout << "Welcome to Group Progremmez Student Information System" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1. Add New Record\n2. Search Record\n3. Display All Records\n4. Display Specific Record\n5. Delete Record\n6. Exit" << endl;
        cout << "Please type your selection: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addNewRecord(students, count);
                break;
            case 2:
                searchRecord(students, count);
                break;
            case 3:
                displayAllRecords();
                break;
            case 4:
                displaySpecificRecord(students, count);
                break;
            case 5:
                deleteRecord(students, count);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid input. Please enter a valid selection." << endl;
        }
    } while (choice != 6);

    displayGroupInfo();

    return 0;
}

void addNewRecord(Student* students, int& count) {
    if (count >= 100) {
        cout << "Cannot add more records. Maximum limit reached." << endl;
        return;
    }

    Student newStudent;

    cout << "Enter Student ID: ";
    cin >> newStudent.studentID;

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, newStudent.fullName);

    cout << "Enter Birthday: ";
    getline(cin, newStudent.birthday);

    cout << "Enter Address: ";
    getline(cin, newStudent.address);

    cout << "Enter Gender (M/F): ";
    cin >> newStudent.gender;

    cout << "Enter Degree Program: ";
    cin.ignore();
    getline(cin, newStudent.degreeProgram);

    cout << "Enter Year Level: ";
    cin >> newStudent.yearLevel;

    students[count++] = newStudent;


    ofstream outFile(FILENAME, ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }
    outFile << newStudent.studentID << "," << newStudent.fullName << "," << newStudent.birthday << "," << newStudent.address << "," << newStudent.gender << "," << newStudent.degreeProgram << "," << newStudent.yearLevel << endl;
    outFile.close();

    cout << "Record added successfully." << endl;
}

void searchRecord(Student* students, int count) {
    int idToSearch;
    cout << "Enter Student ID to search: ";
    cin >> idToSearch;

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].studentID == idToSearch) {
            cout << "Record found:" << endl;
            cout << "Student ID: " << students[i].studentID << endl;
            cout << "Full Name: " << students[i].fullName << endl;
            cout << "Birthday: " << students[i].birthday << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "Gender: " << students[i].gender << endl;
            cout << "Degree Program: " << students[i].degreeProgram << endl;
            cout << "Year Level: " << students[i].yearLevel << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record with ID " << idToSearch << " not found." << endl;
    }
}

void displayAllRecords() {
    ifstream inFile(FILENAME);
    if (!inFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void displaySpecificRecord(Student* students, int count) {
    int idToDisplay;
    cout << "Enter Student ID to display: ";
    cin >> idToDisplay;

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].studentID == idToDisplay) {
            cout << "Record found:" << endl;
            cout << "Student ID: " << students[i].studentID << endl;
            cout << "Full Name: " << students[i].fullName << endl;
            cout << "Birthday: " << students[i].birthday << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "Gender: " << students[i].gender << endl;
            cout << "Degree Program: " << students[i].degreeProgram << endl;
            cout << "Year Level: " << students[i].yearLevel << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record with ID " << idToDisplay << " not found." << endl;
    }
}

void deleteRecord(Student* students, int& count) {
    int idToDelete;
    cout << "Enter Student ID to delete: ";
    cin >> idToDelete;

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].studentID == idToDelete) {

            for (int j = i; j < count - 1; ++j) {
                students[j] = students[j + 1];
            }
            --count; 
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record with ID " << idToDelete << " not found." << endl;
    } else {
        cout << "Record with ID " << idToDelete << " deleted successfully." << endl;
    }
}

void displayGroupInfo() {
    cout << "Group Name: Group Progremmez" << endl;
    cout << "Group Members: [List of members]" << endl;
}

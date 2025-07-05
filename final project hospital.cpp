#include <iostream>
#include<fstream>
#include<cstring>

using namespace std;


struct Patient {



    int PatientID;
    char PatientName[200];  // use char because string is not  has a  specific length
    int RoomNumber;
    double DurationOfStay;
    int Roomprice;
    bool isAssigned;

};

Patient patients[50];


void search_Patient() {
    char Name_patient[200];
    int Id_number;
    cout << "Enter patient name: ";
    cin >> Name_patient;
    cout << "Enter patient ID: ";
    cin >> Id_number;
    bool found = false;

    for (int i = 0; i < 50; i++) {
        if (patients[i].isAssigned && strcmp(Name_patient, patients[i].PatientName) == 0 && Id_number == patients[i].PatientID) {
            cout << "Patient found" << endl;
            cout << "Name: " << patients[i].PatientName << endl;
            cout << "ID: " << patients[i].PatientID << endl;
            cout << "Duration Of Stay: " << patients[i].DurationOfStay << endl;
            cout << "Room Price: " << patients[i].Roomprice << endl;
            cout << "Room Number: " << patients[i].RoomNumber << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Patient not found" << endl;
    }
}

bool isRoomTaken(int roomNumber)
{
    for (int i = 0; i < 50; i++)
    {
        if (patients[i].isAssigned && patients[i].RoomNumber == roomNumber)
        {
            return true;
        }
    }
    return false;
}

void assignPatient()
{
    Patient newPatient;
    cout << "Enter patient ID: ";
    cin >> newPatient.PatientID;
    cout << "Enter patient name: ";
    cin >> newPatient.PatientName, 200;
    cout << "Enter room number: ";
    cin >> newPatient.RoomNumber;
    cout << "Enter duration of stay: ";
    cin >> newPatient.DurationOfStay;
    cout << "Enter room price: ";
    cin >> newPatient.Roomprice;
    if (isRoomTaken(newPatient.RoomNumber))
    {
        cout << "Sorry, the room is already taken." << endl;
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            if (!patients[i].isAssigned)
            {
                patients[i] = newPatient;
                patients[i].isAssigned = true;
                cout << "Patient assigned to room successfully." << endl;
                return;
            }
        }
        cout << "No available rooms." << endl;
    }
}

void dischargePatient()
{
    int roomNumber;
    cout << "Enter room number of the patient to discharge: ";
    cin >> roomNumber;

    for (int i = 0; i < 50; i++)
    {
        if (patients[i].isAssigned && patients[i].RoomNumber == roomNumber)
        {
            patients[i].isAssigned = false;
            cout << "Patient discharged successfully." << endl;
            return;
        }
    }
    cout << "Patient not found in the specified room." << endl;
}

void bill(int patientID) {
    double durationOfStay = 0;
    bool found = false;
    for (int i = 0; i < 50; ++i) {
        if (patients[i].isAssigned && patients[i].PatientID == patientID) {
            durationOfStay = patients[i].DurationOfStay;
            found = true;
            break;
        }
    }
    if (found) {
        double result = durationOfStay * 100;
        cout << "Bill amount for Patient ID " << patientID << ": " << result << endl;
    }
    else {
        cout << "Patient with ID " << patientID << " not found." << endl;
    }
}

void SaveDatabinary(Patient b) {
    ofstream output;
    output.open("Hospital_Management_System.dat", ios::out | ios::binary | ios::app);
    output.write(reinterpret_cast<char*>(&b), sizeof(b)); // to cast the address of a value or an object to a char array

    output.close(); //to ensure that data correctly stored
}


void ReadDatabinary() {
    ifstream input;
    input.open("Hospital_Management_System.dat", ios::in | ios::binary);
    int i = 0;
    while (input.read(reinterpret_cast<char*>(&patients[i]), sizeof(Patient))) {
        i++;
    }

    input.close();
}


//void printData(const Patient& b) {
//
//
//    cout << "ID = " << b.PatientID << endl;
//    cout << "DurationOfStay = " << b.DurationOfStay << endl;
//    cout << "PatientName is  " << b.PatientName << endl;
//    cout << "Roomprice = " << b.Roomprice << endl;
//    cout << "RoomNumber is  " << b.RoomNumber << endl;
//
//}

void initializePatients() {
    for (int i = 0; i < 50; ++i) {
        patients[i] = Patient();
    }
}

void showMenu() {
    cout << "Hospital Management System Menu" << endl;
    cout << "1- Assign Patient" << endl;
    cout << "2- Discharge Patient" << endl;
    cout << "3- Search Patient" << endl;
    cout << "4- Generate Bill" << endl;
    cout << "5- Save Patient Data" << endl;
    cout << "6- Read Patient Data" << endl;
    cout << "7- Display All Patients" << endl;
    cout << "8- Update Patient" << endl;
    cout << "9- Exit" << endl;
    cout << "Enter your choice: ";
}

void displayAllPatients() {
    bool anyPatients = false;
    for (int i = 0; i < 50; i++) {
        if (patients[i].isAssigned) {
            cout << "ID: " << patients[i].PatientID << endl;
            cout << "Name: " << patients[i].PatientName << endl;
            cout << "Room Number: " << patients[i].RoomNumber << endl;
            cout << "Duration Of Stay: " << patients[i].DurationOfStay << endl;
            cout << "Roomprice: " << patients[i].Roomprice << endl;
            anyPatients = true;
        }
        if (!anyPatients) {
            cout << "No patients found." << endl;
        }
    }
}

void updatePatient() {
    int id;
    char name[200];
    bool patientFound = false;

    cout << "Enter patient ID  ";
    cin >> id;
    cout << "Enter patient name  ";
    cin >> name;

    for (int i = 0; i < 50; i++) {
        if (patients[i].isAssigned && patients[i].PatientID == id && strcmp(patients[i].PatientName, name) == 0) {
            patientFound = true;
            cout << "Patient found.." << endl;

            while (true) {
                cout << "What would you like to update?" << endl;
                cout << "1)name" << endl;
                cout << "2)RoomNumber" << endl;
                cout << "3)DurationofStay" << endl;
                cout << "4) Exit" << endl;
                cout << "Enter your choice   ";
                int choice;
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "Enter new name   ";
                    cin >> patients[i].PatientName;
                    break;
                case 2:
                    cout << "Enter new room number   ";
                    cin >> patients[i].RoomNumber;
                    break;
                case 3:
                    cout << "Enter new duration of stay  ";
                    cin >> patients[i].DurationOfStay;
                    break;
                case 4:
                    return;
                default:
                    cout << "invalid choice, try again  " << endl;
                    continue;
                }
                break;
            }
            break;
        }
    }

    if (!patientFound) {
        cout << "Patient not found." << endl;
    }
}

int main() {
    initializePatients();
    int choice;
    bool exit = false;

    while (!exit) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            assignPatient();
            break;
        case 2:
            dischargePatient();
            break;
        case 3:
            search_Patient();
            break;
        case 4: {
            int id;
            cout << "Enter patient ID to generate bill  " << endl;
            cin >> id;
            bill(id);
            break;
        }
        case 5: {
            int id;
            cout << "Enter ID of patient to save  " << endl;
            cin >> id;
            bool found = false;
            for (int i = 0; i < 50; i++) {
                if (patients[i].isAssigned && patients[i].PatientID == id) {
                    SaveDatabinary(patients[i]);
                    cout << "Patient data saved .." << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Patient not found.. " << endl;
            }
            break;
        }
        case 6: {

            ReadDatabinary();
            cout << "Patient data read from file " << endl;
            displayAllPatients();
            break;
        }
        case 7:
            displayAllPatients();
            break;
        case 8:
            updatePatient();
            break;
        case 9:
            exit = true;
            break;
        default:
            cout << "invalid choice, try again ";
        }
    }
    return 0;
}
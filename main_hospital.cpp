#include "hospital_header.h"

int main() {
    HospitalPriorityQueue triageQueue;
    int choice = 0;

    while (choice != 5) {
        cout << "\n============================================\n";
        cout << "   Hospital Emergency Triage System\n";
        cout << "============================================\n";
        cout << "1. Register New Patient\n";
        cout << "2. Attend Highest Priority Patient\n";
        cout << "3. Display All Waiting Patients\n";
        cout << "4. Check Queue Status\n";
        cout << "5. Exit\n";
        cout << "Select Option (1-5): ";
        cin >> choice;

        if (choice == 1) {
            int id, priority;
            string name, condition;

            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Condition/Issue: ";
            getline(cin, condition);
            cout << "Enter Triage Level (1: Critical, 2: Urgent, 3: Non-Urgent): ";
            cin >> priority;

            PatientNode* p = CreatePatient(id, name, condition, priority);
            triageQueue.Add(p);
            cout << "Patient added to queue successfully!\n";

        } else if (choice == 2) {
            PatientNode* attended = triageQueue.Remove();
            if (attended != nullptr) {
                cout << "\n--- Attending Patient ---\n";
                cout << "Patient Name: " << attended->patientName << endl;
                cout << "Condition: " << attended->condition << endl;
                cout << "Priority: P" << attended->priority << endl;
                delete attended;
            } else {
                cout << "Queue is empty! No patients waiting.\n";
            }

        } else if (choice == 3) {
            cout << "\n--- Patients Waiting in Order of Priority ---\n";
            triageQueue.DisplayQueue();

        } else if (choice == 4) {
            if (triageQueue.IsEmpty()) {
                cout << "Status: Emergency Room Queue is Empty.\n";
            } else {
                cout << "Status: Patients are currently waiting in the ER.\n";
            }

        } else if (choice == 5) {
            cout << "Exiting system...\n";
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

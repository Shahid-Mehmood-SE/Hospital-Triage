#include "hospital_header.h"

HospitalPriorityQueue::HospitalPriorityQueue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
}

void HospitalPriorityQueue::Add(PatientNode* newPatient) {
    newPatient->next = nullptr;
    if (front == nullptr) {
        front = newPatient;
        rear = newPatient;
    } else if (newPatient->priority < front->priority) {
        newPatient->next = front;
        front = newPatient;
    } else {
        PatientNode* current = front;
        while (current->next != nullptr && current->next->priority <= newPatient->priority) {
            current = current->next;
        }
        newPatient->next = current->next;
        current->next = newPatient;
        if (newPatient->next == nullptr) {
            rear = newPatient;
        }
    }
    count++;
}

PatientNode* HospitalPriorityQueue::Remove() {
    if (front == nullptr) {
        return nullptr;
    }
    PatientNode* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    temp->next = nullptr;
    count--;
    return temp;
}

bool HospitalPriorityQueue::IsEmpty() {
    return front == nullptr;
}

void HospitalPriorityQueue::DisplayQueue() {
    if (IsEmpty()) {
        cout << "No patients waiting in queue.\n";
        return;
    }
    PatientNode* current = front;
    while (current != nullptr) {
        cout << "ID: " << current->patientID 
             << " | Name: " << current->patientName 
             << " | Condition: " << current->condition 
             << " | Priority: P" << current->priority << endl;
        current = current->next;
    }
}

HospitalPriorityQueue::~HospitalPriorityQueue() {
    while (front != nullptr) {
        PatientNode* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

PatientNode* CreatePatient(int id, string name, string condition, int priority) {
    PatientNode* node = new PatientNode;
    node->patientID = id;
    node->patientName = name;
    node->condition = condition;
    node->priority = priority;
    node->next = nullptr;
    return node;
}

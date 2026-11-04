#ifndef HOSPITAL_HEADER_H
#define HOSPITAL_HEADER_H

#include <iostream>
#include <string>
using namespace std;

// Patient Node structure
struct PatientNode {
    int patientID;
    string patientName;
    string condition;
    int priority; // 1 = Critical, 2 = Urgent, 3 = Non-Urgent
    PatientNode* next;
};

// Hospital Priority Queue class declaration
class HospitalPriorityQueue {
private:
    PatientNode* front;
    PatientNode* rear;
    int count;

public:
    HospitalPriorityQueue();
    void Add(PatientNode* newPatient);
    PatientNode* Remove();
    bool IsEmpty();
    void DisplayQueue();
    ~HospitalPriorityQueue();
};

// Helper function declaration
PatientNode* CreatePatient(int id, string name, string condition, int priority);

#endif

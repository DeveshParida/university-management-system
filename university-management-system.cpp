#include<iostream>
using namespace std;
struct University {
    int universityID;
    string universityName;
    string universityLocation;
    int startYear;
};
struct Branch {
    int universityID;
    string universityName;
    string branchID;
};
struct Student {
    int rollNumber;
    string name;
    string branchID;
    int cgpa;
    struct Student *next;
    struct Student *prev;
};
void create(struct Student **start, struct Student **last) {
    Student *ptr = new Student;
    cout<<"Enter Name: ";
    cin>>ptr->name;
    cout<<"Enter Roll Number: ";
    cin>>ptr->rollNumber;
    cout<<"Enter Branch ID: ";
    cin>>ptr->branchID;
    cout<<"Enter CGPA: ";
    cin>>ptr->cgpa;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (*start == NULL) {
        *start = ptr;
        *last = ptr;  
    }
    else {
        (*last)->next = ptr;
        ptr->prev = *last;
        *last = ptr;
    }
}
void display(struct Student **start, struct Student **last) {
    struct Student *ptr;
    ptr = *start;
    while (ptr != NULL) {
        cout<<"\nRoll Number: "<<ptr->rollNumber;
        cout<<"\nName: "<<ptr->name;
        cout<<"\nBranch ID: "<<ptr->branchID;
        cout<<"\nCGPA: "<<ptr->cgpa;
        cout<<"\n\n";
        ptr = ptr->next;
    }
}
int main()
{
    struct Student *st = NULL;
    struct Student *last = NULL;
    char ch;
    struct Branch b1;
    b1.branchID = "B001";
    b1.universityID = 1;
    b1.universityName = "KIIT Bhubaneswar";
    struct Branch b2;
    b2.branchID = "B002";
    b2.universityID = 2;
    b2.universityName = "MIT Manipal";
    struct Branch b3;
    b3.branchID = "B003";
    b3.universityID = 3;
    b3.universityName = "VIT Vellore";
    do {
        create(&st, &last);
        cout<<"\nDo You Want to Continue (Y/N)?";
        cout<<"\nEnter Your Choice: ";
        getchar();
        cin>>ch;
        cout<<"\n";
    } while (ch == 'Y');
    display(&st, &last);
    return 0;
}

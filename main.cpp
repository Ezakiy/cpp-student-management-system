#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

const int MAX_GRADES = 4;
const int MAX_STUDENTS = 5;

// Student structure
struct Student
{
    int number;
    string name;
    int age;
    string phone;
    int grades[MAX_GRADES];
};

// Function Section

// Return to menu timer
void returnMenuTimer(int seconds)
{
    for (int i = seconds; i >= 0; i--)
    {
        cout << "Returning to main menu in " << i << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// Calculate average grade
float calculateAverage(int grades[], int totalGrades)
{
    int sum = 0;

    // Traverse grades array
    for (int i = 0; i < totalGrades; i++)
    {
        sum += grades[i];
    }

    return (float)sum / totalGrades;
}

// Add students
void addStudents(Student students[], int &totalStudents, int maxStudents)
{
    int timer = 5;
    int quantity;

    // Show total students
    cout << "Current total students in class: " << totalStudents << endl;
    cout << endl;

    // Ask how many students to add
    cout << "How many students do you want to add?" << endl;
    cin >> quantity;
    cout << endl;

    // Check if maximum limit is exceeded
    if (quantity + totalStudents > maxStudents)
    {
        cout << "Maximum student limit exceeded: " << maxStudents << endl;
        cout << "You can only add "
             << maxStudents - totalStudents
             << " more students." << endl;
        return;
    }

    // Check if class is already full
    if (totalStudents == maxStudents)
    {
        Sleep(150);

        cout << "Maximum student limit already reached." << endl;

        returnMenuTimer(timer);

        return;
    }

    cin.ignore();

    // Add students
    for (int i = 0; i < quantity; i++)
    {
        cout << "Student " << totalStudents + 1 << endl;

        cout << "Number: ";
        cin >> students[totalStudents].number;
        cout << endl;

        cin.ignore();

        cout << "Name: ";
        getline(cin, students[totalStudents].name);
        cout << endl;

        cout << "Age: ";
        cin >> students[totalStudents].age;
        cout << endl;

        cin.ignore();

        cout << "Phone: ";
        getline(cin, students[totalStudents].phone);
        cout << endl;

        totalStudents += 1;
    }
}

// List students
void listStudents(Student students[], int totalStudents, int totalGrades)
{
    float average = 0;
    string status;

    cout << "There are "
         << totalStudents
         << " students in this class."
         << endl;

    cout << endl;

    for (int i = 0; i < totalStudents; i++)
    {
        cout << "Student " << i + 1 << endl;

        cout << "Number: " << students[i].number << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Phone: " << students[i].phone << endl;

        cout << endl;

        // Show grades
        for (int j = 0; j < 4; j++)
        {
            cout << "Grade " << j + 1
                 << ": "
                 << students[i].grades[j]
                 << endl;
        }

        cout << endl;

        // Show average
        average = calculateAverage(students[i].grades, totalGrades);

        cout << "Average: " << average << endl;

        // Show status
        if (average >= 10)
        {
            status = "Approved";
            cout << status << endl;
        }
        else
        {
            status = "Failed";
            cout << status << endl;
        }

        cout << endl;
    }
}

// Insert student grades
void insertGrades(Student students[], int totalStudents, int maxGrades)
{
    int selectedStudent;

    cout << "Enter the student number to insert grades." << endl;
    cin >> selectedStudent;

    cout << endl;

    // Search student
    for (int i = 0; i < totalStudents; i++)
    {
        if (selectedStudent == students[i].number)
        {
            cout << students[i].number
                 << ", "
                 << students[i].name
                 << endl;

            // Insert grades
            for (int j = 0; j < maxGrades; j++)
            {
                cout << "Grade " << j + 1 << ": " << endl;

                cin >> students[i].grades[j];
            }

            return;
        }
    }

    cout << "Student does not exist." << endl;
    cout << endl;

    return;
}

// Search student
void searchStudent(Student students[], int totalStudents, int totalGrades)
{
    int studentNumber;

    float average = 0;

    string status;

    cout << "Search student by number: ";
    cin >> studentNumber;

    cout << endl;

    // Search in array
    for (int i = 0; i < totalStudents; i++)
    {
        if (studentNumber == students[i].number)
        {
            cout << "\n===== STUDENT FOUND =====\n";

            cout << endl;

            cout << "Number: "
                 << students[i].number
                 << endl;

            cout << "Name: "
                 << students[i].name
                 << endl;

            cout << "Age: "
                 << students[i].age
                 << endl;

            cout << "Phone: "
                 << students[i].phone
                 << endl;

            cout << endl;

            cout << "Grades:\n";

            // Show grades
            for (int j = 0; j < totalGrades; j++)
            {
                cout << "Grade "
                     << j + 1
                     << ": "
                     << students[i].grades[j]
                     << endl;
            }

            // Show average
            average = calculateAverage(students[i].grades,
                                       totalGrades);

            cout << "Average: "
                 << average
                 << endl;

            // Show status
            if (average >= 10)
            {
                status = "Approved";
                cout << status << endl;
            }
            else
            {
                status = "Failed";
                cout << status << endl;
            }

            cout << endl;
        }
    }
}

// Best student
void bestStudent(Student students[], int totalStudents, int totalGrades)
{
    float bestAverage = 0;

    int bestStudentIndex = 0;

    // Traverse students
    for (int i = 0; i < totalStudents; i++)
    {
        // Calculate average
        float average =
            calculateAverage(students[i].grades,
                             totalGrades);

        // Compare averages
        if (average > bestAverage)
        {
            bestAverage = average;
            bestStudentIndex = i;
        }
    }

    cout << "Best student in class: "
         << students[bestStudentIndex].name
         << endl;

    cout << "Average: "
         << bestAverage
         << endl;

    cout << endl;

    return;
}

// Worst student
void worstStudent(Student students[], int totalStudents, int totalGrades)
{
    float worstAverage = 20;

    int worstStudentIndex = 0;

    // Traverse students
    for (int i = 0; i < totalStudents; i++)
    {
        // Calculate average
        float average =
            calculateAverage(students[i].grades,
                             totalGrades);

        // Compare averages
        if (average < worstAverage)
        {
            worstAverage = average;
            worstStudentIndex = i;
        }
    }

    cout << "Worst student in class: "
         << students[worstStudentIndex].name
         << endl;

    cout << "Average: "
         << worstAverage
         << endl;

    cout << endl;

    return;
}

// Class average
void classAverage(Student students[], int totalStudents, int totalGrades)
{
    float average = 0;
    float gradesSum = 0;

    int totalExistingGrades = 0;

    // Traverse all students
    for (int i = 0; i < totalStudents; i++)
    {
        // Traverse grades
        for (int j = 0; j < totalGrades; j++)
        {
            gradesSum += students[i].grades[j];

            totalExistingGrades++;
        }
    }

    average = gradesSum / totalExistingGrades;

    cout << "Class average: "
         << average
         << endl;

    cout << endl;

    return;
}

int main()
{
    Student students[MAX_STUDENTS];

    int totalStudents = 0;
    int totalGrades = 4;

    int option;

    do
    {
        cout << endl;

        cout << "===== MENU =====" << endl;

        cout << "1 - Add Students" << endl;
        cout << "2 - List Students" << endl;
        cout << "3 - Insert Student Grades" << endl;
        cout << "4 - Search Student" << endl;
        cout << "5 - Best Student" << endl;
        cout << "6 - Worst Student" << endl;
        cout << "7 - Class Average" << endl;
        cout << "0 - Exit Application" << endl;

        cout << "Option: ";

        cin >> option;

        cout << endl;

        switch (option)
        {
        case 1:
            addStudents(students,
                        totalStudents,
                        MAX_STUDENTS);
            break;

        case 2:
            listStudents(students,
                         totalStudents,
                         totalGrades);
            break;

        case 3:
            insertGrades(students,
                         totalStudents,
                         MAX_GRADES);
            break;

        case 4:
            searchStudent(students,
                          totalStudents,
                          totalGrades);
            break;

        case 5:
            bestStudent(students,
                        totalStudents,
                        totalGrades);
            break;

        case 6:
            worstStudent(students,
                         totalStudents,
                         totalGrades);
            break;

        case 7:
            classAverage(students,
                         totalStudents,
                         totalGrades);
            break;

        case 0:

            cout << "Exiting..." << endl;
            Sleep(1500);
            break;
        }

    } while (option != 0);

    return 0;
}
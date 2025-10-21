#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Course {
public:
    string courseNumber;
    string name;
    vector<string> prerequisites;

    Course() {}
    Course(string number, string title, vector<string> prereqs)
        : courseNumber(number), name(title), prerequisites(prereqs) {
    }
};

void loadCourses(map<string, Course>& courses, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string number, title, prereq;
        vector<string> prereqs;

        getline(ss, number, ',');
        getline(ss, title, ',');

        while (getline(ss, prereq, ',')) {
            if (!prereq.empty()) prereqs.push_back(prereq);
        }

        courses[number] = Course(number, title, prereqs);
    }

    file.close();
    cout << "Courses loaded successfully.\n";
}

void printCourseList(const map<string, Course>& courses) {
    for (const auto& pair : courses) {
        cout << pair.second.courseNumber << ", " << pair.second.name << endl;
    }
}

void printCourseDetails(const map<string, Course>& courses, const string& courseNumber) {
    auto it = courses.find(courseNumber);
    if (it == courses.end()) {
        cout << "Course not found.\n";
        return;
    }

    const Course& course = it->second;
    cout << course.courseNumber << ", " << course.name << endl;

    if (course.prerequisites.empty()) {
        cout << "Prerequisites: None\n";
    }
    else {
        cout << "Prerequisites:\n";
        for (const string& prereq : course.prerequisites) {
            auto preIt = courses.find(prereq);
            if (preIt != courses.end()) {
                cout << "  " << preIt->second.courseNumber << ", " << preIt->second.name << endl;
            }
            else {
                cout << "  " << prereq << " (not found)\n";
            }
        }
    }
}

int main() {
    map<string, Course> courses;
    int choice;
    string filename, courseNumber;

    do {
        cout << "\nMenu:\n";
        cout << "1. Load Data File\n";
        cout << "2. Print Course List\n";
        cout << "3. Print Course Details\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter filename: ";
            cin >> filename;
            loadCourses(courses, filename);
            break;
        case 2:
            if (courses.empty()) {
                cout << "Please load data first.\n";
            }
            else {
                printCourseList(courses);
            }
            break;
        case 3:
            if (courses.empty()) {
                cout << "Please load data first.\n";
            }
            else {
                cout << "Enter course number: ";
                cin >> courseNumber;
                printCourseDetails(courses, courseNumber);
            }
            break;
        case 9:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
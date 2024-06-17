#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "===== To-Do List =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Done" << endl;
    cout << "4. Clear All Tasks" << endl;
    cout << "5. Quit" << endl;
    cout << "======================" << endl;
    cout << "Enter your choice: ";
}

// Function to add a task to the list
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    cin.ignore(); // Ignore newline character
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added!\n\n";
}

// Function to view all tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks added yet.\n\n";
    } else {
        cout << "Tasks:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << setw(3) << i + 1 << ". " << tasks[i] << endl;
        }
        cout << endl;
    }
}

// Function to mark a task as done
void markTaskDone(vector<string>& tasks) {
    int index;
    cout << "Enter the task number to mark as done: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task marked as done!\n\n";
    } else {
        cout << "Invalid task number!\n\n";
    }
}

// Function to clear all tasks
void clearAllTasks(vector<string>& tasks) {
    tasks.clear();
    cout << "All tasks cleared!\n\n";
}

int main() {
    vector<string> tasks; // Vector to store tasks

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskDone(tasks);
                break;
            case 4:
                clearAllTasks(tasks);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    } while (choice != 5);

    return 0;
}

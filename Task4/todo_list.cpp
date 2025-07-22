#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure for Task
struct Task {
    string name;
    bool isCompleted;
};

// Function to display the menu
void displayMenu() {
    cout << "\n==== TO-DO LIST MENU ====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    string taskName;
    cout << "Enter task name: ";
    cin.ignore(); // clear buffer
    getline(cin, taskName);
    tasks.push_back({taskName, false});
    cout << "✅ Task added successfully.\n";
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "📋 No tasks available.\n";
        return;
    }

    cout << "\n==== YOUR TASKS ====\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].name 
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark task as completed
void markCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "⚠️ No tasks to mark.\n";
        return;
    }

    viewTasks(tasks);
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = true;
        cout << "✅ Task marked as completed.\n";
    } else {
        cout << "❌ Invalid task number.\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "⚠️ No tasks to remove.\n";
        return;
    }

    viewTasks(tasks);
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        cout << "🗑️ Task '" << tasks[index - 1].name << "' removed.\n";
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "❌ Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
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
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "👋 Exiting program. Bye!\n";
                break;
            default:
                cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}


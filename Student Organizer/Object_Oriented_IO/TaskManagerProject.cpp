#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Task {
public:
    int id;
    string name;
    string status;

    Task(int i, string n, string s) {
        id = i;
        name = n;
        status = s;
    }

    void displayTask() {
        cout << "ID: " << id << " | Task: " << name << " | Status: " << status << endl;
    }
};

class TaskManager {
private:
    vector<Task> tasks;
    string filename = "tasks.txt";

    void loadTasks() {
        ifstream file(filename);
        if (!file) return;

        int id;
        string name, status;
        while (file >> id) {
            file.ignore();
            getline(file, name);
            getline(file, status);
            tasks.push_back(Task(id, name, status));
        }
        file.close();
    }

    void saveTasks() {
        ofstream file(filename);
        for (Task t : tasks) {
            file << t.id << endl << t.name << endl << t.status << endl;
        }
        file.close();
    }

public:
    TaskManager() { loadTasks(); }

    void addTask(string name) {
        int id = tasks.size() + 1;
        tasks.push_back(Task(id, name, "Pending"));
        saveTasks();
        cout << "Task Added Successfully!\n";
    }

    void completeTask(int id) {
        for (Task &t : tasks) {
            if (t.id == id) {
                t.status = "Completed";
                saveTasks();
                cout << "Task Marked as Completed!\n";
                return;
            }
        }
        cout << "Task Not Found!\n";
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        for (Task t : tasks) {
            t.displayTask();
        }
    }
};

int main() {
    TaskManager tm;
    int choice;
    string name;
    int id;

    while (true) {
        cout << "\n1. Add Task\n2. Complete Task\n3. Show Tasks\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Task Name: ";
                getline(cin, name);
                tm.addTask(name);
                break;
            case 2:
                cout << "Enter Task ID to Complete: ";
                cin >> id;
                tm.completeTask(id);
                break;
            case 3:
                tm.displayTasks();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    }
}

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void saveToFile(const vector<string>& todoList) {
    ofstream outFile("todo_list.txt");
    if (outFile.is_open()) {
        for (const string& task : todoList) {
            outFile << task << endl;
        }
        outFile.close();
        cout << "Tasks saved to 'todo_list.txt'." << endl;
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

int main() {
    vector<string> todoList;
    int choice;
    string task;
    int taskIndex;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                todoList.push_back(task);
                break;
            case 2:
                cout << "To-Do List:\n";
                for(size_t i = 0; i < todoList.size(); ++i) {
                    cout << i + 1 << ". " << todoList[i] << endl;
                }
                break;
            case 3:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                if (taskIndex > 0 && taskIndex <= todoList.size()) {
                    todoList.erase(todoList.begin() + taskIndex - 1);
                    cout << "Task removed." << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
                break;
            case 4:
                saveToFile(todoList);
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}

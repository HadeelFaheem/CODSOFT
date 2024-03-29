#include <iostream>
#include <string>
using namespace std;

const int MAXTASKS = 10;

void displayMenu() {
    cout << "=====** My To-Do List **=====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
}
int main() {
    string tasks[MAXTASKS];
    bool completed[MAXTASKS] = {false};
    int numTasks = 0;
    int choice;
  do {  displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

    switch(choice) {
          case 1: {
             if (numTasks < MAXTASKS) {
                    cout << "Enter task: ";
                    cin.ignore(); 
                    getline(cin, tasks[numTasks]);
                    numTasks++;
                    cout << "Task added successfully.\n" << endl;
                } else {
                    cout << "To-Do list is full.\n" << endl;
                }
                break;
            }
            case 2: {
                cout << "Tasks:" << endl;
                for (int i = 0; i < numTasks; i++) {
                    cout << i + 1 << ". ";
                    if (completed[i])
                        cout << "[X] ";
                    else
                        cout << "[ ] ";
                    cout << tasks[i] << endl;
                }
                if (numTasks == 0) {
                    cout << "No tasks added yet To-Do List is empty.\n" << endl;
                }
                break;
            }
            case 3: {
                int taskIndex;
                cout << "Enter the task number to mark as completed:";
                cin >> taskIndex;
                if (taskIndex >= 1 && taskIndex <= numTasks) {
                    completed[taskIndex - 1] = true;
                    cout << "Task marked as completed.\n" << endl;
                } else {
                    cout << "Invalid task number.\n" << endl;
                }
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task number to delete: ";
                cin >> taskIndex;
                if (taskIndex >= 1 && taskIndex <= numTasks) {
                    for (int i = taskIndex - 1; i < numTasks - 1; i++) {
                        tasks[i] = tasks[i + 1];
                        completed[i] = completed[i + 1];
                    }
                    numTasks--;
                    cout << "Task deleted successfully.\n" << endl;
                } else {
                    cout << "Invalid task number.\n" << endl;
                }
                break;
            }
            case 5: {
                cout << "\nExiting program." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n" << endl;
        }
    } 
	while (choice != 5);
    return 0;
}


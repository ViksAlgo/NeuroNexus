/*
TASK 4 - TO-DO List
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Structure to represent a task
struct Task
{
    string description;
    bool completed;
};

// Function to display the to-do list
void displayTodoList(const vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "** To-Do List **" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << "[" << (tasks[i].completed ? "X" : " ") << "] " << i + 1 << ". " << tasks[i].description << endl;
    }
}

// Function to add a task to the list
void addTask(vector<Task> &tasks)
{
    string description;
    cout << "Enter task description: ";
    getline(cin, description); // Use getline to handle spaces in descriptions

    tasks.push_back({description, false}); // Add new task with default status (pending)
    cout << "Task added successfully." << endl;
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks)
{
    int taskIndex;
    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskIndex - 1].completed = true; // Adjust for 0-based indexing
    cout << "Task marked as completed." << endl;
}

// Function to remove a task from the list
void removeTask(vector<Task> &tasks)
{
    int taskIndex;
    cout << "Enter the number of the task to remove: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks.erase(tasks.begin() + taskIndex - 1); // Remove task using iterator and adjust for indexing
    cout << "Task removed successfully." << endl;
}

int main()
{
    vector<Task> tasks; // Vector to store tasks

    int choice;
    do
    {
        cout << "\n** To-Do List Manager **" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;
        case 2:
            displayTodoList(tasks);
            break;
        case 3:
            markTaskCompleted(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}

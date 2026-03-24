// To-Do list;
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

// Structure to represent a task
struct Task {
    int id;
    string description;
    bool isCompleted;
    
    Task(int taskId, string taskDesc) {
        id = taskId;
        description = taskDesc;
        isCompleted = false;
    }
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
void clearInputBuffer();
bool isValidTaskId(const vector<Task>& tasks, int id);
void showTaskStatistics(const vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;
    int nextId = 1;
    
    cout << "╔════════════════════════════════════════════╗" << endl;
    cout << "║     TO-DO LIST MANAGER - COMPLETE EDITION ║" << endl;
    cout << "╠════════════════════════════════════════════╣" << endl;
    cout << "║     Organize, Track, and Complete         ║" << endl;
    cout << "║           Your Tasks Efficiently!         ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    do {
        displayMenu();
        cout << "\n➡️  Enter your choice (1-6): ";
        
        while (!(cin >> choice)) {
            cout << "❌ Invalid input! Please enter a number (1-6): ";
            clearInputBuffer();
        }
        
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                showTaskStatistics(tasks);
                break;
            case 6:
                cout << "\n╔════════════════════════════════════════════╗" << endl;
                cout << "║     Thanks for using To-Do List Manager!  ║" << endl;
                cout << "║     Keep organizing and achieving your    ║" << endl;
                cout << "║                goals! 🎯                  ║" << endl;
                cout << "╚════════════════════════════════════════════╝" << endl;
                break;
            default:
                cout << "\n❌ Invalid choice! Please enter a number between 1 and 6." << endl;
        }
        
        if (choice != 6) {
            cout << "\n📌 Press Enter to continue...";
            clearInputBuffer();
            cin.get();
        }
        
    } while (choice != 6);
    
    return 0;
}

void displayMenu() {
    cout << "\n┌──────────────────────────────────────────┐" << endl;
    cout << "│              📋 MAIN MENU                │" << endl;
    cout << "├──────────────────────────────────────────┤" << endl;
    cout << "│  1. ➕  ADD NEW TASK                     │" << endl;
    cout << "│  2. 👁️   VIEW ALL TASKS                  │" << endl;
    cout << "│  3. ✅  MARK TASK AS COMPLETED           │" << endl;
    cout << "│  4. 🗑️   REMOVE TASK                     │" << endl;
    cout << "│  5. 📊  VIEW STATISTICS                  │" << endl;
    cout << "│  6. 🚪  EXIT APPLICATION                 │" << endl;
    cout << "└──────────────────────────────────────────┘" << endl;
}

void addTask(vector<Task>& tasks) {
    string taskDescription;
    static int nextId = 1;
    
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║           ➕ ADD NEW TASK                  ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    cout << "📝 Enter task description: ";
    
    clearInputBuffer(); // Clear any remaining newline characters
    getline(cin, taskDescription);
    
    // Validate input
    if (taskDescription.empty()) {
        cout << "\n❌ Error: Task description cannot be empty!" << endl;
        return;
    }
    
    // Trim leading and trailing spaces
    size_t start = taskDescription.find_first_not_of(" \t");
    size_t end = taskDescription.find_last_not_of(" \t");
    if (start != string::npos && end != string::npos) {
        taskDescription = taskDescription.substr(start, end - start + 1);
    }
    
    // Create and add the task
    tasks.push_back(Task(nextId, taskDescription));
    
    cout << "\n✅ Task added successfully!" << endl;
    cout << "   ┌─────────────────────────────────┐" << endl;
    cout << "   │ Task ID       : " << setw(4) << nextId << "          │" << endl;
    cout << "   │ Description   : " << taskDescription << endl;
    cout << "   │ Status        : ⏳ Pending         │" << endl;
    cout << "   └─────────────────────────────────┘" << endl;
    
    nextId++;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║           👁️  YOUR TASKS LIST              ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    if (tasks.empty()) {
        cout << "\n   📭 Your to-do list is empty!" << endl;
        cout << "   💡 Use option 1 to add some tasks." << endl;
        return;
    }
    
    // Display header
    cout << "\n┌──────┬────────────┬────────────────────────────────────┐" << endl;
    cout << "│  ID  │   STATUS   │           TASK DESCRIPTION          │" << endl;
    cout << "├──────┼────────────┼────────────────────────────────────┤" << endl;
    
    // Display each task
    for (const auto& task : tasks) {
        cout << "│ " << setw(4) << task.id << " │ ";
        
        if (task.isCompleted) {
            cout << "✅ COMPLETED ";
        } else {
            cout << "⏳ PENDING   ";
        }
        
        cout << "│ " << task.description;
        
        // Add padding for alignment
        int padding = 36 - task.description.length();
        if (padding > 0) {
            cout << string(padding, ' ');
        }
        cout << " │" << endl;
    }
    
    cout << "└──────┴────────────┴────────────────────────────────────┘" << endl;
    
    // Show summary
    int completedCount = 0;
    for (const auto& task : tasks) {
        if (task.isCompleted) completedCount++;
    }
    
    cout << "\n📈 Quick Summary:" << endl;
    cout << "   📊 Total tasks   : " << tasks.size() << endl;
    cout << "   ✅ Completed     : " << completedCount << endl;
    cout << "   ⏳ Pending       : " << (tasks.size() - completedCount) << endl;
}

void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n❌ No tasks available to mark as completed!" << endl;
        cout << "   💡 Please add tasks first using option 1." << endl;
        return;
    }
    
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║        ✅ MARK TASK AS COMPLETED           ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    // Show only pending tasks
    cout << "\n📋 PENDING TASKS:" << endl;
    cout << "┌────────────────────────────────────────────┐" << endl;
    
    vector<int> pendingIds;
    bool hasPending = false;
    
    for (const auto& task : tasks) {
        if (!task.isCompleted) {
            cout << "│ ID " << setw(3) << task.id << ": " << task.description << endl;
            pendingIds.push_back(task.id);
            hasPending = true;
        }
    }
    
    if (!hasPending) {
        cout << "│   🎉 ALL TASKS ARE COMPLETED!           │" << endl;
        cout << "│   🌟 Great job! You're doing amazing!   │" << endl;
        cout << "└────────────────────────────────────────────┘" << endl;
        return;
    }
    
    cout << "└────────────────────────────────────────────┘" << endl;
    
    int taskId;
    cout << "\n🔢 Enter the ID of the completed task: ";
    
    while (!(cin >> taskId)) {
        cout << "❌ Invalid input! Please enter a valid task ID: ";
        clearInputBuffer();
    }
    
    // Find and mark task as completed
    bool found = false;
    for (auto& task : tasks) {
        if (task.id == taskId) {
            if (!task.isCompleted) {
                task.isCompleted = true;
                cout << "\n✅ Task marked as completed!" << endl;
                cout << "   📝 \"" << task.description << "\"" << endl;
                cout << "   🎉 Great progress! Keep going!" << endl;
            } else {
                cout << "\nℹ️  Task \"" << task.description << "\" is already completed!" << endl;
            }
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\n❌ Task with ID " << taskId << " not found!" << endl;
        cout << "   💡 Please check the task ID and try again." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n❌ No tasks available to remove!" << endl;
        cout << "   💡 Please add tasks first using option 1." << endl;
        return;
    }
    
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║          🗑️  REMOVE TASK                   ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    // Display current tasks
    cout << "\n📋 CURRENT TASKS:" << endl;
    cout << "┌────────────────────────────────────────────┐" << endl;
    
    for (const auto& task : tasks) {
        cout << "│ ID " << setw(3) << task.id << ": ";
        if (task.isCompleted) {
            cout << "✅ ";
        } else {
            cout << "⏳ ";
        }
        cout << task.description << endl;
    }
    
    cout << "└────────────────────────────────────────────┘" << endl;
    
    int taskId;
    cout << "\n🔢 Enter the ID of the task to remove: ";
    
    while (!(cin >> taskId)) {
        cout << "❌ Invalid input! Please enter a valid task ID: ";
        clearInputBuffer();
    }
    
    // Find and remove the task
    bool found = false;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == taskId) {
            cout << "\n🗑️  Task removed successfully!" << endl;
            cout << "   📝 \"" << it->description << "\" has been deleted." << endl;
            tasks.erase(it);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\n❌ Task with ID " << taskId << " not found!" << endl;
        cout << "   💡 Please check the task ID and try again." << endl;
    }
}

void showTaskStatistics(const vector<Task>& tasks) {
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║         📊 TASK STATISTICS                 ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    if (tasks.empty()) {
        cout << "\n   📭 No tasks available for statistics." << endl;
        cout << "   💡 Add some tasks to see your progress!" << endl;
        return;
    }
    
    int completedCount = 0;
    int pendingCount = 0;
    size_t totalLength = 0;
    
    for (const auto& task : tasks) {
        if (task.isCompleted) {
            completedCount++;
        } else {
            pendingCount++;
        }
        totalLength += task.description.length();
    }
    
    double completionRate = (static_cast<double>(completedCount) / tasks.size()) * 100;
    double avgTaskLength = (tasks.size() > 0) ? static_cast<double>(totalLength) / tasks.size() : 0;
    
    cout << "\n┌────────────────────────────────────────────┐" << endl;
    cout << "│           📈 OVERALL STATISTICS           │" << endl;
    cout << "├────────────────────────────────────────────┤" << endl;
    cout << "│ Total Tasks        : " << setw(5) << tasks.size() << "                    │" << endl;
    cout << "│ Completed Tasks    : " << setw(5) << completedCount << "  ✅              │" << endl;
    cout << "│ Pending Tasks      : " << setw(5) << pendingCount << "  ⏳              │" << endl;
    cout << "│ Completion Rate    : " << setw(5) << fixed << setprecision(1) << completionRate << "%                  │" << endl;
    cout << "│ Avg Task Length    : " << setw(5) << fixed << setprecision(0) << avgTaskLength << " chars              │" << endl;
    cout << "└────────────────────────────────────────────┘" << endl;
    
    // Visual progress bar
    cout << "\n📊 PROGRESS BAR:" << endl;
    cout << "   [";
    int progressBars = static_cast<int>(completionRate / 5); // 20 segments total
    for (int i = 0; i < 20; i++) {
        if (i < progressBars) {
            cout << "█";
        } else {
            cout << "░";
        }
    }
    cout << "] " << fixed << setprecision(1) << completionRate << "%" << endl;
    
    // Motivational message based on completion rate
    cout << "\n💡 MOTIVATION:" << endl;
    if (completionRate == 100) {
        cout << "   🌟 PERFECT! All tasks completed! You're a superstar!" << endl;
    } else if (completionRate >= 75) {
        cout << "   🎯 Excellent progress! You're almost there!" << endl;
    } else if (completionRate >= 50) {
        cout << "   👍 Good job! More than halfway there!" << endl;
    } else if (completionRate >= 25) {
        cout << "   💪 Keep going! Every completed task counts!" << endl;
    } else if (completionRate > 0) {
        cout << "   🌱 Great start! Build momentum by completing more tasks!" << endl;
    } else {
        cout << "   🚀 Ready to start? Complete your first task today!" << endl;
    }
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isValidTaskId(const vector<Task>& tasks, int id) {
    for (const auto& task : tasks) {
        if (task.id == id) {
            return true;
        }
    }
    return false;
}
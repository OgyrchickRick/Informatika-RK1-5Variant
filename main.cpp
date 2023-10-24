#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Task {
    std::string name;
    int priority;
    std::string deadline;
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.priority > task2.priority;
}

int main() {
    std::vector<Task> tasks;

    std::string addMore;
    do {
        Task task;
        std::cout << "Введите название задачи: ";
        std::getline(std::cin, task.name);
        std::cout << "Введите приоритет задачи (целое число): ";
        std::cin >> task.priority;
        std::cout << "Введите срок выполнения задачи: ";
        std::cin.ignore();
        std::getline(std::cin, task.deadline);

        tasks.push_back(task);

        std::cout << "Задача добавлена!\n";
        std::cout << "Хотите добавить еще задачу? (да/нет): ";
        std::getline(std::cin, addMore);
    } while (addMore == "да");

    std::sort(tasks.begin(), tasks.end(), compareTasks);

    std::cout << "Список задач:\n";
    for (const Task& task : tasks) {
        std::cout << "Название: " << task.name << "\n";
        std::cout << "Приоритет: " << task.priority << "\n";
        std::cout << "Срок выполнения: " << task.deadline << "\n";
        std::cout << "\n";
    }

    return 0;
}
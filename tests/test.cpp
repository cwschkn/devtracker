#include "task.h"
#include "task_manager.h"
#include <iostream>
#include <string>

void print_tasks(Task* task_array, int task_count);
int task_counter(const Task* task_array, int task_count);

int main() {

    int task_count = 2;
    int capacity = 3;

    Task* task_array = new Task[capacity]();

    task_array[0] = {1, "Залипание кнопки", MEDIUM, OPEN};
    task_array[1] = {2, "Ошибка проверки логина", CRITICAL, IN_PROGRESS};

    task_array = add_task(task_array, task_count, capacity, "Утечка данных", CRITICAL, IN_PROGRESS);

    print_tasks(task_array, task_count);

    int len_array = task_counter(task_array, task_count);

    std::cout << len_array << '\n';

    std::cout << "===========================" << '\n';
    
    task_array = add_task(task_array, task_count, capacity, "Неверный логотип в шапке", LOW, OPEN);

    print_tasks(task_array, task_count);

    len_array = task_counter(task_array, task_count);

    std::cout << len_array << '\n';

    delete[] task_array;
}

void print_tasks(Task* task_array, int task_count) {
    for (int i = 0; i < task_count; i++)
    {
        std::cout << task_array[i].id << ' ' << task_array[i].title << ' ' << static_cast<Priority>(task_array[i].priority) << ' ' << static_cast<Status>(task_array[i].status) << '\n';
    }
}

int task_counter(const Task* task_array, int task_count) {

    int count{};

    for (int i = 0; i < task_count; i++)
    {
        if (task_array[i].id != 0)
        {
            count++;
        }
    }
    
    return count;
}

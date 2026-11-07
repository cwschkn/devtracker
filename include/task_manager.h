#pragma once
#include "task.h"

Task* add_task(Task* task_array, int& task_count, int& capacity, const std::string& title, const Priority& priority, const Status& status) {

    if (task_count == capacity)
    {
        int new_capacity = capacity * 2;
        Task* new_task_array = new Task[new_capacity]();

        for (int i = 0; i < task_count; i++)
        {
            new_task_array[i] = task_array[i];
        }

        delete[] task_array;

        task_array = new_task_array;
        capacity = new_capacity;

    }
    
    task_array[task_count].id = task_count + 1;
    task_array[task_count].title = title;
    task_array[task_count].priority = priority;
    task_array[task_count].status = status;

    task_count++;

    return task_array;
}
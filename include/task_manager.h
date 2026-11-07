#pragma once
#include "task.h"
#include <string>

/**
 * @brief Добавляет задачу в массив
 * 
 * При заполнении массива увеличивает его вместимость в два раза
 * 
 * @param task_array Массив задач (Task)
 * @param task_count Текущее кол-во задач в массиве
 * @param capacity Текущая вместимость выделенного массива
 * @param title Название задачи
 * @param priority Приоритет задачи
 * @param status Статус задачи
 * @return Task* Возвращает динамический массив задач
 */
inline Task* add_task(Task* task_array, int& task_count, int& capacity, const std::string& title, Priority priority, Status status) {

    // Расширение массива задач
    if (task_count == capacity) // Проверка заполненности
    {
        int new_capacity = capacity == 0 ? 1 : capacity * 2;

        Task* new_task_array = new Task[new_capacity](); // Создание нового расширенного массива

        // Копирование данных из прошлго массива в новый
        for (int i = 0; i < task_count; i++)
        {
            new_task_array[i] = task_array[i];
        }
        
        // Освобождение памяти старого массива
        delete[] task_array;

        // Обновление указателя и вместимости массива
        task_array = new_task_array;
        capacity = new_capacity;

    }
    
    // Добавление новой задачи
    task_array[task_count].id = task_count + 1;
    task_array[task_count].title = title;
    task_array[task_count].priority = priority;
    task_array[task_count].status = status;

    ++task_count;

    return task_array;
}
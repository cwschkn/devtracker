#pragma once
#include <string>

/*===========================================================================
Описание задач: перечисления приоритетов, статусов задач и самих задач. ru
Tasks description: enums of priorities, statuses and struct of tasks eng.
===========================================================================*/

enum Priority // Перечисление приоритетов
{
    LOW = 0, // Низкий приоритет | Low priority
    MEDIUM = 1, // Средний приоритет | Medium priority
    HIGH = 2, // Высокий приоритет | High priority
    CRITICAL = 3 // Критический приоритет | Critical priority
};

enum Status {
    OPEN = 0, // Открытая задача | Open task
    IN_PROGRESS = 1, // Задача в работе | Task in progress
    COMPLETED = 2 // Работа над задачей окончена | Work is completed
};

struct Task
{
    int id; // id задачи | task id
    std::string title; // Название задачи | task name
    Priority priority; // Приоритет задачи | task priority
    Status status; // Статус задачи | task status
};

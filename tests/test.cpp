#include "task.h"
#include "task_manager.h"
#include <iostream>
#include <cassert>

void test_add_task();
void test_add_task_expansion();
void test_add_task_empty_array();

int main() {

    test_add_task();
    test_add_task_expansion(); 
    test_add_task_empty_array();

    std::cout << "All tests passed" << '\n';
}


/**
 * @brief Проверяет добавление задачи при наличии свободного места в массиве.
 * 
 */
void test_add_task() {

    int task_count = 2;
    int capacity = 3;

    Task* task_array = new Task[capacity]();

    task_array[0] = {1, "Залипание кнопки", MEDIUM, OPEN};
    task_array[1] = {2, "Ошибка проверки логина", CRITICAL, IN_PROGRESS};

    task_array = add_task(task_array, task_count, capacity, "Утечка данных", CRITICAL, IN_PROGRESS);

    assert(task_count == 3); // Проверка количества задач после добавления
    assert(capacity == 3); // Проверка вместимости массива после добавления

    // Проверка сохранности ранее добавленных задач
    assert(task_array[0].id == 1);
    assert(task_array[0].title == "Залипание кнопки");
    assert(task_array[0].priority == MEDIUM);
    assert(task_array[0].status == OPEN);

    assert(task_array[1].id == 2);
    assert(task_array[1].title == "Ошибка проверки логина");
    assert(task_array[1].priority == CRITICAL);
    assert(task_array[1].status == IN_PROGRESS);

    // Проверка корректности добавленной задачи
    assert(task_array[2].id == 3);
    assert(task_array[2].title == "Утечка данных");
    assert(task_array[2].priority == CRITICAL);
    assert(task_array[2].status == IN_PROGRESS);

    delete[] task_array;
}

/**
 * @brief Проверяет расширение массива при отсутствии свободного места.
 * 
 */
void test_add_task_expansion() {

    int task_count = 3;
    int capacity = 3;

    Task* task_array = new Task[capacity]();

    task_array[0] = {1, "Залипание кнопки", MEDIUM, OPEN};
    task_array[1] = {2, "Ошибка проверки логина", CRITICAL, IN_PROGRESS};
    task_array[2] = {3, "Неверный логотип", LOW, COMPLETED};

    task_array = add_task(task_array, task_count, capacity, "Утечка данных", CRITICAL, IN_PROGRESS);

    assert(task_count == 4); // Проверка количества задач после расширения массива
    assert(capacity == 6); // Проверка новой вместимости массива

    // Проверка сохранности ранее добавленных задач

    // Проверка первой задачи
    assert(task_array[0].id == 1);
    assert(task_array[0].title == "Залипание кнопки");
    assert(task_array[0].priority == MEDIUM);
    assert(task_array[0].status == OPEN);
    
    // Проверка второй задачи
    assert(task_array[1].id == 2);
    assert(task_array[1].title == "Ошибка проверки логина");
    assert(task_array[1].priority == CRITICAL);
    assert(task_array[1].status == IN_PROGRESS);
    
    // Проверка третьей задачи
    assert(task_array[2].id == 3);
    assert(task_array[2].title == "Неверный логотип");
    assert(task_array[2].priority == LOW);
    assert(task_array[2].status == COMPLETED);

    // Проверка корректности новой задачи
    assert(task_array[3].id == 4);
    assert(task_array[3].title == "Утечка данных");
    assert(task_array[3].priority == CRITICAL);
    assert(task_array[3].status == IN_PROGRESS);

    delete[] task_array;
}

/**
 * @brief Проверяет добавление первой задачи в массив с нулевой вместимостью.
 * 
 */
void test_add_task_empty_array() {

    int task_count = 0;
    int capacity = 0;

    Task* task_array = nullptr; // Создание пустого массива

    task_array = add_task(task_array, task_count, capacity, "Проверка логина и пароля неисправна", CRITICAL, IN_PROGRESS);

    // Проверка корректности указателя после выделения памяти
    assert(task_array != nullptr);

    assert(task_count == 1); // Проверка количества задач после добавления
    assert(capacity == 1); // Проверка вместимости массива после добавления

    // Проверка корректности добавленной задачи
    assert(task_array[0].id == 1);
    assert(task_array[0].title == "Проверка логина и пароля неисправна");
    assert(task_array[0].priority == CRITICAL);
    assert(task_array[0].status == IN_PROGRESS);

    delete[] task_array;
}

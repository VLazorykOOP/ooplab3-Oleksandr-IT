// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

// Ваші файли загловки 
//
#include "Lab3Example.h"
int main()
{
    std::cout << " Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту

    int conv = 1;
    
    // Завдання 1.6 - Diamond (Ромб)
    if (conv == 1) conv = mainExample1_6();
    
    // Завдання 2.6 - Vector3D
    if (conv == 1) conv = mainExample2_6();
    
    // Завдання 3.6 - Matrix2D
    if (conv == 1) conv = mainExample3_6();
}


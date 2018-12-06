#include <iostream>
using namespace std;
 
class OneClass
{
 int *ptr; // какой-то указатель
 
public:
 OneClass() // конструктор без параметров
 {
 cout << "\nСработал Конструктор без параметров\n";
 }
 
 OneClass(const OneClass &object)
 {
 cout << "\nСработал Конструктор копирования\n";
 }
 
 ~OneClass()
 {
 cout << "\nСработал Дестркуктор\n";
 }
};
 
void showFunc(OneClass object)
{
 cout << "\nЭта функция принимает объект класса, как параметр.\n";
 cout << "Сначала срабатывает конструктор копирования (т.к. создается реальная копия объекта).\n";
 cout << "Затем выполняется код функции. А при выходе из нее - сработает деструктор.\n";
}
 
OneClass returnObjectFunc()
{
 OneClass object; // тут сработает конструктор без параметров
 cout << "\nЭта функция возвращает объект.\n";
 cout << "При выходе из нее, деструктор сработает дважды.\n";
 return object; // тут сработает конструктор копирования
}
 
int main()
{
 setlocale(LC_ALL, "rus");
 
 cout << "~~~~~~~~~~~~~~~  Блок 1  ~~~~~~~~~~~~~~~\n";
 OneClass object1; // объявляем объект класса
 
 cout << "\n~~~~~~~~~~~~~~~  Блок 2  ~~~~~~~~~~~~~~~\n";
 showFunc(object1); // передаем объект в showFunc()
 
 cout << "\n~~~~~~~~~~~~~~~  Блок 3  ~~~~~~~~~~~~~~~\n";
 returnObjectFunc(); // функция returnObjectFunc() возвращает объект
 
 cout << "\n~~~~~~~~~~~~~~~  Блок 4  ~~~~~~~~~~~~~~~\n";
 OneClass object2 = object1;  // инициализация объекта object2 при создании
 return 0;
}


#include <iostream>

//1.1
int firGlobalVar = 10; 
int secGlobalVar = 20;
int thirGlobalVar = 30;

//1.2
void func(){
    static int staticLocalVar = 20;
    std::cout << "адрес стат. локальной переменной: " << &staticLocalVar << std::endl;
}

//2.2 
void SecFunc(int var){
    std::cout << "Адрес переменной из функици: " << &var << std::endl;
}

int main() {

    setlocale(LC_ALL, "russian");

    //1.3 Как итог все четыре переменных лежат рядом, в Data Segment, Статической памяти.
    std::cout << "Адрес первой глобальной переменной: " << &firGlobalVar << std::endl;
    std::cout << "Адрес второй глобальной переменной: " << &secGlobalVar << std::endl;
    std::cout << "Адрес третей глобальной переменной: " << &thirGlobalVar << std::endl;

    func();

    //2.1
    int firLocalVar = 5;

    //Адреса поменялись, но они лежат рядом, на стеке, отличаются на 44
    std::cout << "Адрес локальной переменной в мейне: " << &firLocalVar << std::endl;
    SecFunc(firLocalVar);

    int* arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
        std::cout << "arr[" << i << "] =" << arr[i] << ", адресс: " 
        << &arr[i] << std::endl;
    }
    delete[] arr;

    /* Ответы на вопросы: 
    1. static int создается на этапе компиляции, и хранится в статической памяти 
    int обычная локальная переменная хранится на стеке.

    2. Он выделяется заранее при запуске программы.

    3. если перед или во время инициализации переменной создавался указатель
    указываюший на новую выделеную память, при помощи оператора new.

    4. При каждом забытом new программа накапливает мусор в памяти, в результате 
    произойдет утечка памяти, memory leak
    */

    return 0;
}

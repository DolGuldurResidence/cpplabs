#include <iostream>

//6
int sumOfArray(int* ptrToArray, size_t sizeOfArray){
    int counter = 0;
    for(int i = 0; i < sizeOfArray; ++i) {
        counter += *(ptrToArray + i);
    }
    return counter;
}

int main() {

    setlocale(LC_ALL, "Russian");
    //1
    int x = 10;
    int y = 20;
    int z = 30;

    //2
    int* p1 = &x;
    int* p2 = &y;
    int* p3 = &z;

    //3.1
    std::cout << "Адреса переменных x, y, z соответственно: ";     
    std::cout << p1 << ' ' << p2 << ' ' << p3 << ' ' << std::endl;

    //3.2
    std::cout << "Переменные x, y, z соответственно: ";
    std::cout << *p1 << ' ' << *p2 << ' ' << *p3 << ' ' << std::endl;

    //4.1
    int arr[3] = {x,y,z};
    int* ptr = arr;
    int* ptr_copy = ptr; 

    std::cout << "ptr указывает на: " << *ptr << std::endl;
    std::cout << "ptr_copy указывает на: "  << *ptr_copy << std::endl;

    //4.2
    //нельзя использовать постфиксный инкремент 
    int* ptrPlusPlus = ++ptr;
    std::cout << "ptrPlusPlus " << *ptrPlusPlus << std::endl;

    //5
    int anArr[5] = {5,10,15,20,25};
    int* anPtr = anArr;

    for(int i = 0; i < std::size(anArr); ++i){
        std::cout << *(anPtr + i) << std::endl;
    }

    //6
    size_t  sizeOfArray = std::size(anArr);
    std::cout << "Сумма элементов массива " << sumOfArray(anPtr, sizeOfArray) << std::endl;

    //7.1
    int var = 7;
    int* ptrVar = &var;
    int** ptrPtr = &ptrVar;

    std::cout << "var равняется: " << **ptrPtr << std::endl;

    //7.2
    std::cout << "Размеры указателей на компиляторе:" << std::endl;
    std::cout << "sizeof(int*): " << sizeof(int*) << " байт" << std::endl;
    std::cout << "sizeof(double*): " << sizeof(double*) << " байт" << std::endl;
    std::cout << "sizeof(char*):  " << sizeof(char*) << " байт" << std::endl;
    std::cout << "sizeof(void*):  " << sizeof(void*) << " байт" << std::endl; 

    return 0;
}
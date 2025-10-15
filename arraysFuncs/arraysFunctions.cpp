#include <iostream> 

//3
void printArray(int* arr, int size){
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << std::endl;
    }
}

void printArray(int arr[5]){
    for(int i = 0; i < 5; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

/* вот это вот ошибка
void f(int* arr) {
    std::cout << "Pointer version\n";
}

void f(int arr[5]) {
    std::cout << "Array version\n";
}
*/

int main() {

    //1 
    int a[5] = {1,2,3};
    
    for(int i = 0; i < 5; ++i){
        std::cout << a[i] << std::endl;
    }
    /*нулями инициализируются все явно не определенные 
    элементы массива под которые выделена память*/ 

    /*по факту у меня не выводитя сообщение об UB, вероятнее
    из за настроек флагов компилятора, но в строчке а[5] выводится
    0, а в стр a[6] выводится мусор*/
    std::cout << a[5] << std::endl;
    std::cout << a[6] << std::endl;

    //2
    int* p = a;

    for(int i = 0; i < 5; ++i){
        std::cout << *(p + i) << std::endl;
    }
    
    //a[j] = *(a + j) = *(j + a) = j[a] :-)
    for(int j = 0; j < 5; ++j) {
        std::cout << j[a] << std::endl;
    }

    //3 в целом компилятор не сказал ничего)  
    std::cout << "массив из функции" << std::endl;
    printArray(p, sizeof(a)/sizeof(a[0]));
    std::cout << std::endl;
    printArray(a);

    //4
    std::cout << "размер массива: " << sizeof(a) << std::endl;
    std::cout << "размер указателя: " << sizeof(p) << std::endl;
    /*в итоге размер массива = 20 так как он содержит пять интов каждый
    4 байта, размер указателя 8 байт, так как размер указателя в 64 битной
    архитектуре равен 8 байт. */
    

    //5
    int n;
    std::cin >> n;

    int* dynArr = new int[n];
    
    for(int i = 0; i < n; ++i) {
        dynArr[i] = 0;
    }

    for(int j = 0; j < n; ++j) {
        std::cout << dynArr[j];
    }
    delete[] dynArr;

    //delete dynArr; это UB, потому что в этом случае
    //удаляется только указатель на первый элемент массива
    //но не весь массив целиком.


    //технически это UB, и читается память вниз стека
    std::cout << dynArr[-1] << std::endl;
    std::cout << dynArr[-2] << std::endl;

    return 0;
}
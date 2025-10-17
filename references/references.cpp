#include <iostream>
#include <vector>


//1.3
int square(int x) {
    return x * x; 
}

int twoMultiplyX(int x){
    return 2 * x;
}

int increaseX(int x){
    return ++x;
}

//2.2
void increment(int& y){
    ++y;
}

/*2.3
int& getRef() {
    int x = 5;
    return x; // не скомпилируется из за попытки возврата ссылки на локальную переменную 
}
*/

//если мы обьявим переменую static, то она будет жить в памяти на протяжении всего рантайма программы

int& getStaticRef(){ //и как бы все шоколад
    static int x = 5;
    return x; 
}

int main(){

    //1.1
    int (*pf1)(int); //указатель на на функцию которая принимает и возвращает int.
    int *ap[10]; // массив из 10 указателей на инт.
    int (*fp1[10])(int); //массив из 10 указателей на функцию  принимающюю и возвращающую int.
    int (*(*fp2[5])())(); //массив из 5 указателей на функции которые возвращают указатель на функцию. 
    char *(*(*x[3])())[5]; //массив из 3 указателей, каждый элемент явл-ся указателем
    //на функцию без параметров, которая возвращает указатель на массив из 5 элементов, в котором
    //каждый элемент явл-ся указателем на char.

    //1.2
    void (*fp)(int);
    void (*fp3[5])(int);
    void (*(*fp4()))();
    char* (*(*fp5[3])())[];

    //1.3
    typedef int (*func_ptr)(int);

    func_ptr arr[3];//массив из трех указателей на функции, которые принимают инт и возвращают инт;

    arr[0] = square;
    arr[1] = increaseX;
    arr[2] = twoMultiplyX;

    int y  = 10; 
    
    std::cout << "arr[0](" << y << ") = " << arr[0](y) << std::endl;
    std::cout << "arr[1](" << y << ") = " << arr[1](y) << std::endl;
    std::cout << "arr[2](" << y << ") = " << arr[2](y) << std::endl;

    //2.1
    int& ref = y;

    ref++;

    std::cout << y << std::endl; 

    //2.2
    increment(ref);

    std::cout << ref << std::endl;

    const int& ref1 = y; 

    //increment(ref1); //будет ошибка потому что нельзя изменять константное значение. 

    std::cout << ref1 << std:: endl; 

    //2.3
    int& r = getStaticRef();

    std::cout << r << std::endl;

    //2.4
    std::vector<int> a = {1, 2, 3};
    std::vector<int>& b = a;
    b[0] = 5; //a[0] тоже меняется
    for(int i = 0; i < 3; ++i){
        std::cout << "a[" << i << "]" << a[i] << std::endl;
    }

    std::vector<int> c = a;
    c[0] = 4;//a[0] не изменится, а вот с[0] уже поменяет свое значение
    for(int i = 0; i < 3; ++i){
        std::cout << "a[" << i << "]" << a[i] << std::endl;
    }

    for(int i = 0; i < 3; ++i){
        std::cout << "с[" << i << "]" << c[i] << std::endl;
    }

    return 0;
}
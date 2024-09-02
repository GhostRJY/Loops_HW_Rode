#include <iostream>

void diapasonePrint(const int endOfDiapasone)
{
    int diapasone{ 0 };
    while(diapasone < endOfDiapasone) {
        if(!(diapasone % 20))
            std::cout << '\n';
        if(diapasone < 9)
            std::cout << '0';
        std::cout << ++diapasone << ' ';
    }
    std::cout << '\n' << std::endl;
}

int sumOfDiapasone(const int start = 0, const int finish = 100)
{    
    int result{ 0 };
    for(int i{ start }; i < finish; ++i)
        result += i;

    return result;
}

void factorial(const int &userValue)
{
    int factorial = 1;
    for(int i{ 1 }; i <= userValue; ++i)
        factorial *= i;

    std::cout << "Факториал числа " << userValue << " составляет " << factorial << std::endl;
}

int recursiveFactorial(int userValue)
{
    if(userValue == 1)
        return 1;
    else
        return userValue * recursiveFactorial(userValue - 1);
}

//фун-ия переворота чисел любой длины
void sumOfValue(const int &userValue)
{
    int temp{ userValue };
    int result{ 0 };
    int counter{ 0 };

    //вычисляем кол-во цифр в значении их сумму
    while(temp != 0) {
        result += (temp % 10);
        temp /= 10;
        ++counter;
    }
    std::cout << "В вашем числе " << counter << " цифр и их сумма составляет " << result << std::endl;
}

void mirrorValue(int &userValue)
{
    int temp = userValue;
    int counter{ 0 };

    //вычисляем кол-во цифр в значении
    while(temp != 0) {
        temp /= 10;
        ++counter;
    }

    //сохраняем число которое нужно перевернуть
    temp = userValue;
    //обнуляю пользовательское число
    userValue = 0;

    //получаю перевернутое число
    while(temp != 0) {
        userValue += (temp % 10) * std::pow(10, --counter);
        temp /= 10;
    }

}

//на что число делиться без остатка
void divisionWithoutRemainder(int userValue)
{
    std::cout << "Число " << userValue << " делится без остатка на: ";
    for(int i{ 1 }; i <= userValue; ++i) {
        if(!(userValue % i)) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}

//проверяем на палиндром
bool checkPalindrome(const std::string &userString)
{
    int length = userString.length();

    for(int i{ 0 }; i < length / 2; ++i) {
        if(userString[i] != userString[length - i - 1])
            return false;
    }

    return true;
}

//Пузырек
void startHiLo(const int range = 1000)
{
    //начало диапазона
    int fromValue = 0;
    //конец диапазона
    int toValue = range;
    //искомое число
    int machineValue{ 0 };
    //кол-во попыток
    int counter{ 0 };
    //подсказка пользователя
    char choice;

    std::cout << "\nЗагадай число)\n";
    
    for(;fromValue<=toValue;) {
        ++counter;
        machineValue = (fromValue + toValue) / 2;
        std::cout << machineValue << " Это твое число? (\'+\'-больше, \'-\'-меньше, любой символ верно )";
        std::cin >> choice;

        if(choice == '+') {
            fromValue = machineValue;
        }
        else if(choice == '-') {
            toValue = machineValue;
        }
        else {
            std::cout << '\n';
            break;
        }
        std::cout << '\n';
    }

    std::cout << "Я угадал число за " << counter << " попыток" << std::endl;
}

int main()
{
    //1.	Написать программу, выводящую на экран только чётные целые числа из диапазона от 1 до 100.
    diapasonePrint(100);

    //2.	Вычислить сумму чисел в диапазоне от M до N.
    const int start{ 100 }, finish{ 200 };
    std::cout << "Сумма чисел в диапазоне от " << start << " до " << finish << " составляет " << sumOfDiapasone(start, finish) << std::endl;

    //4.	Написать программу, вычисляющую факториал введённого числа.
    int userValue{ 5 };
    factorial(userValue);
    std::cout << "Факториал числа " << userValue << " составляет " << recursiveFactorial(userValue) << std::endl;

    //5.	С клавиатуры вводится целое число любой разрядности.Определить количество цифр в нём и их сумму.
    userValue = 0;
    std::cout << "\nВведите число ->";
    std::cin >> userValue;
    sumOfValue(userValue);

    //6.	С клавиатуры вводится целое число любой разрядности.Необходимо перевернуть это число,
    // т.е.цифры должны располагаться в обратном порядке(например, вводим число 1234 – в результате будет 4321).
    userValue = 0;
    std::cout << "\nВведите число ->";
    std::cin >> userValue;
    
    mirrorValue(userValue);

    std::cout << userValue << "\nХА - ХА, Я перевернул твое число!!!" << std::endl;

    //7.	С клавиатуры вводится целое число.Вывести на экран все числа, на которые введённое число делится без остатка.
    // Например, для 60 такими числами станут 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60.
    userValue = 0;
    std::cout << "\nВведите число ->";
    std::cin >> userValue;

    divisionWithoutRemainder(userValue);
    
    //7.	Определить, является ли введённое число любой разрядности палиндромом(например, 1234321 – палиндром, 12345 – не палиндром).
    std::string userString;

    std::cout << "\nВведите строку ->";
    std::cin >> userString;

    if(checkPalindrome(userString)) {
        std::cout << "Это палиндром\n";
    } else {
        std::cout << "Это не палиндром\n";
    }
    
    //11.	Написать игру «Угадай число».Пользователь мысленно загадывает число от 0 до 1000, компьютер отгадывает его за минимальное количество попыток.
    startHiLo();

    return 0;
}
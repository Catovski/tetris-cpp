#pragma execution_character_set("windows-1251")
#include <iostream>
#include <thread>
#include <chrono>

int main(){
    std::cout << "===== Простейший тетрис =====\n\n";

    //Простое игравое поле 10х20.
    const int width  = 10;
    const int height = 20;

    char board[height][width];

    //Заполняем поля точками
    for(int y = 0; y < height; ++y){
        for(int x = 0; x < width; ++x){
            board[y][x] = '.';
        }
    }

    //добавляем квадрат 2х2.
    board[0][4] = '#';
    board[0][5] = '#';
    board[1][4] = '#';
    board[1][4] = '#';
    
    bool gameRunning = true;
    int playerX = 4;

    while(gameRunning){
        //Очищаем экран
        #ifdef _WIN32
            system("cls");
        #else
            system("slear");
        #endif

        //Отрисовываем поля
        std::cout << "Тетрис, минимальная версия\n";
        std::cout << "Управление: А - влево, D - вправо, Q - выход\n\n";

        for(int y = 0; y < height; ++y){
            std::cout << "|";
            for(int x = 0; x < width; ++x){
                std::cout << board[y][x];
            }
            std::cout << "|\n";
        }

        std::cout << "+";
        for(int y = 0; y < width; ++y){
            std::cout << "-";
        }
        std::cout << "+\n";

        //Обработка ввода
        std::cout << "\nВведите команду(a/d/q): ";
        char input;
        std::cin >> input;

        //Обновляем игровое состояние
        switch (input)
        {
            case 'a':
                if(playerX > 0) playerX--;
                break;
            case 'd':
                if(playerX < width - 2) playerX++;
                break;
            case 'q':
                gameRunning = false;
                std::cout << "\nВыход из игры...\n";
            default:
                break;
        }

        //Обновляем фигурки на поле
        for(int y = 0; y < height; ++y){
            for(int x = 0; x < width; ++x){
                board[y][x] = '.';
            }
        }

        //Рисуем фигуру новой позиции
        board[0][playerX] = '#';
        board[0][playerX + 1] = '#';
        board[1][playerX] = '#';
        board[1][playerX + 1] = '#';
    }
    return 0;
}
#include <iostream>
#include <thread>
#include <chrono>

int main(){
    std::cout << "===== The simplest Tetris =====\n\n";

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
    board[1][5] = '#';
    
    bool gameRunning = true;
    int playerX = 4;

    int playerY = 0;
    int fallCounter = 0;
    const int FALL_DELAY = 20;

    while(gameRunning){
        //Очищаем экран
        #ifdef _WIN32
            system("cls");
        #else
            system("slear");
        #endif

        //Отрисовываем поля
        std::cout << "Tetris, the minimal version\n";
        std::cout << "Control: A - left, D - right, Q - exit\n\n";

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
        std::cout << "\nEnter the command(a/d/q): ";
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
                std::cout << "\nExit the game...\n";
                break;
            default:
                break;
        }

        //Обновляем фигурки на поле
        for(int y = 0; y < height; ++y){
            for(int x = 0; x < width; ++x){
                board[y][x] = '.';
            }
        }
        
        //Автаматическое падение
        if(fallCounter++ >= FALL_DELAY){
            fallCounter = 0;
            playerY++;
        }

        //Рисуем фигуру новой позиции
        board[playerY][playerX] = '#';
        board[playerY][playerX + 1] = '#';
        board[playerY + 1][playerX] = '#';
        board[playerY + 1][playerX + 1] = '#';

        //Проверка столкновение с дном
        if(playerY >= height -2){ //Достигаем дна
            playerY = height - 2; //Фиксируем у дна

            //Создаем новую фигуру сверху
            playerY = 0;
            playerX = 0;
        }
    }
    return 0;
}
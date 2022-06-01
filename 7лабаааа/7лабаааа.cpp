#include <iostream>
#include <vector>
using namespace std;

//s
//,xmcSDLvbSvjS
//wlfMk;nWIOUWLJN4OUGF; vu wui cCK CK JK CKLCAбо додо рчранлпглорапдшлорам лорппрор
int check(int a) //проверка на число 
{
    while (!(cin >> a)) // пока не будет введено целое число  
    {
        if ((cin.fail())) // если ошибка ввода  
        {
            cout << "Повторите попытку" << endl;
            cin.clear(); // Очищаем буфер ввода  
            cin.ignore(1000, '\n'); // Убирает новую строку из cin  
        }
    } return a; // возвращение функцией числа, прошедшего проверку  
}

int check(int a) //проверка на число 
{
    while (!(cin >> a)) // пока не будет введено целое число  
    {
        if ((cin.fail())) // если ошибка ввода  
        {
            cout << "Повторите попытку" << endl;
            cin.clear(); // Очищаем буфер ввода  
            cin.ignore(1000, '\n'); // Убирает новую строку из cin  
        }
    } return a; // возвращение функцией числа, прошедшего проверку  
}



int check_num(int a, int min) //проверка на число больше min 
{
    while (!(cin >> a) || (a <= min)) // пока не будет введено целое число  
    {
        if ((cin.fail()) || (a <= min)) // если ошибка ввода  
        {
            cout << "Повторите попытку" << endl;
            cin.clear(); // Очищаем буфер ввода  
            cin.ignore(1000, '\n'); // Убирает новую строку из cin  
        }
    } return a; // возвращение функцией числа, прошедшего проверку  
}
int check_coord(int x, int n)//проверка координаты на вхождение в поле 
{
    while (!(cin >> x) || (x < 0) || (x > (n - 1)))  // пока не будет введено целое число  
    {
        if ((cin.fail()) || (x < 0) || (x > (n - 1))) // если ошибка ввода  
        {
            cout << "Повторите попытку" << endl;
            cin.clear(); // Очищаем буфер ввода  
            cin.ignore(1000, '\n'); // Убирает новую строку из cin  
        }
    } return x; // возвращение функцией числа, прошедшего проверку  
}

// Закрашивание поля ходами
vector<vector<int>> paint_Board(int a, int b, vector<vector<int>> board, vector<vector<int>> T, int turn)
{
    int a_current, b_current; // текущие координаты
    int board_size_x = board.size(); // размер поля по х
    int board_size_y = board[0].size(); // размер поля по у
    for (int i = 0; i < T.size(); i++) { // от 0 до колва ходов
        a_current = a + T[i][0]; // делаем ход
        b_current = b + T[i][1];
        // если текущие коорд входят в поле и на этом месте на поле 0 ходов
        if (a_current < board_size_x && b_current < board_size_y && a_current >= 0 && b_current >= 0 && board[a_current][b_current] == 0) {
            board[a_current][b_current] = turn + 1; // увеличиваем число ходов
            board = paint_Board(a_current, b_current, board, T, turn + 1); // дальше заходим в рекурсию
        }
    }
    return board;
}

int main()
{
    setlocale(LC_ALL, "");
    int a1=-1, b1=-1, a2=-1, b2=-1, N = 0, M = 0;
    // Ввод необходимых данных
    cout << "Введите количество столбцов (х) поля, больше 1: ";
    N = check_num(N, 1);
    cout << "Введите количество строк (у) поля, больше 1: ";
    M = check_num(M, 1);

    vector<vector<int>> board1(N, vector<int>(M)); // двумерный вектор поля для 1 фигуры
    vector<vector<int>> board2(N, vector<int>(M)); // двумерный вектор поля для 2 фигуры
    bool ch_same = false; // проверяем вдруг координаты фигур одинаковые
        while (ch_same == false)
        {
            ch_same = true;
            cout << endl << "Введите стартовую координату х первой фигуры: ";
            a1 = check_coord(a1, N);
            cout << "Введите стартовую координату y первой фигуры: ";
            b1 = check_coord(b1, M);

            cout << endl << "Введите стартовую координату х второй фигуры: ";
            a2 = check_coord(a2, N);
            cout << "Введите стартовую координату у второй фигуры: ";
            b2 = check_coord(b2, M);
            if (((a1 == a2) && (b1 == b2)))
            {
                ch_same = false;
                cout << endl << "Вы ввели одинаковые координаты для обеих фигур. Повторите попытку.";
            }
        }

    cout << endl << "Введите количество правил хода первой фигуры, >0: ";
    int rules_amount = 0;
        rules_amount = check_num(rules_amount, 0);

    vector<vector<int>> T1(rules_amount, vector<int>(2));
    for (int i = 0; i < rules_amount; i++) {
        cout << endl << "Введите смещение по х " << i+1 << " правила хода 1 фигуры: ";
        T1[i][0] = 0;
        T1[i][0] = check(T1[i][0]);
        cout << "Введите смещение по у " << i+1 << " правила хода 1 фигуры: ";
        T1[i][1] = 0;
        T1[i][1] = check(T1[i][1]); 
    }

    cout << endl << "Введите количество правил хода второй фигуры: ";
    rules_amount = 0;
    rules_amount = check_num(rules_amount, 0); 

    vector<vector<int>> T2(rules_amount, vector<int>(2));
    for (int i = 0; i < rules_amount; i++) {
        cout << endl << "Введите смещение по х " << i+1 << " правила хода 2 фигуры: ";
        T2[i][0] = 0;
        T2[i][0] = check(T2[i][0]);
        cout << "Введите смещение по у " << i+1 << " правила хода 2 фигуры: ";
        T2[i][1] = 0;
        T2[i][1] = check(T2[i][1]);
    }

    // Закрашивание полей ходами
    int turn = 0; // колво ходов
    board1[a1][b1] = -1; // колво ходов в начальной точке делаем -1 чтобы оно не менялось
    board1 = paint_Board(a1, b1, board1, T1, turn);
    board2[a2][b2] = -1; // колво ходов в начальной точке делаем -1 чтобы оно не менялось
    board2 = paint_Board(a2, b2, board2, T2, turn);
   
    // Поиск кратчайшего пересечения и глубины рекурсии
    int min_turns_to_cross = INT_MAX;
    int deep1 = 0;
    int deep2 = 0;
    vector<int> shortest_cross(2); // вектор с коорд мин пересечения
    for (int i = 0; i < board1.size(); i++) { // перебор по х
        for (int j = 0; j < board1[i].size(); j++) { // перебор по у
            if (board1[i][j] != 0 && board2[i][j] != 0) { // если колво ходов до точки каждой фигуры не 0
                if (board1[i][j] >= board2[i][j] && board1[i][j] < min_turns_to_cross) { // если колво ходов 1 фигуры больше 2 и меньше мин
                    min_turns_to_cross = board1[i][j];
                    shortest_cross[0] = i;
                    shortest_cross[1] = j;
                }
                else if (board2[i][j] >= board1[i][j] && board2[i][j] < min_turns_to_cross) { // ну или наоборот
                    min_turns_to_cross = board2[i][j];
                    shortest_cross[0] = i;
                    shortest_cross[1] = j;
                }
                    deep1 = board1[i][j];
                    deep2 = board2[i][j];
            }
        }
    }
    if (deep1 == -1) deep1 = 0; // если фигура не делала ходы
    if (deep2 == -1) deep2 = 0;

        if ((deep1 == 0) && (deep2 == 0))
            cout << endl << "Пересечение невозможно";
        else
        {
            cout << endl << "Глубина рекурсии для фигуры 1 равна: " << deep1 << endl;
            cout << "Глубина рекурсии для фигуры 2 равна: " << deep2 << endl;
            cout << "Координаты кратчайшего пересечения фигур равны: [" << shortest_cross[0] << ',' << shortest_cross[1] << ']';
        }
}
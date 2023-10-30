//Подключение необходимых библиотек
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <chrono>  //библиотека для вычисления времени работы алгоритмов

#define NOT_FOUND -1 //Возвращаемый индекс, в случае если элемент не найден
#define N 4//кол-во функций

//Подключаем стандартное пространство имён
using namespace std;

int better_linear_search(int* sequestion,//последовательность для поиска
	int size,//размер последовательности
	int& number_of_key_comparisons,//кол-во сравнений
	int& number_of_comparisons_at_index_analysis,//количество сравнений при анализе индекса элемента массива в цикле
	int element_to_search//элемент для поиска
);//последовательный поиск возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND

int sentinel_linear_search(
	int* sequestion,//последовательность для поиска
	int size,//размер последовательности
	int& number_of_key_comparisons,//кол-во сравнений
	int element_to_search//элемент для поиска
);//быстрый последовательный поиск возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND

int ordered_array_search(
	int* sequestion,//последовательность для поиска
	int size,//размер последовательности
	int element_to_search//элемент для поиска
);//последовательный поиск в упорядоченном массиве возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND

int binary_search(
	int* sequestion,//последовательность для поиска
	int size,//размер последовательности
	int element_to_search//элемент для поиска
);//бинарный поиск возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND

//Функция вывода в файл
void fill_file(double* sequestion,//Замеры времени
	int number_of_key_comparisons_bls,//кол-во сравнений BLS
	int number_of_comparisons_at_index_analysis_bls,//кол-во сравнений индекса BLS
	int number_of_key_comparisons_sls,//кол-во сравнений SLS
	int& error_code
);//код ошибки

//Функция создания возрастающей целочисленной последовательности
void increase_seq(int* arr, //массив
	int size,				//количество элементов
	int max_value);				//ограничение на рандомное число

//Функция создания случайной вещественной последовательности
void random_seq(int* arr, //массив
	int size,				 //количество элементов
	int max_value);				 //ограничение на рандомное число
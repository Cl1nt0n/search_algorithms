/**************************************************************************************************/
/*                                       АЛГОРИТМЫ                                                */
/**************************************************************************************************/
/*	Project Type	: Win64 Console Applicatoin                                                   */
/*	Progect Name	: Лаб.р. №1 массивы время													  */
/*	File Name		: Лаб.р. №1 массивы время.cpp                                                 */
//*	Language		: CPP, MSVS ver 2022                                                          */
//*	Programmers		: Исламов Раиль Азатович, Чиняков Игорь Павлович М3О-210Б-22                  */
/*	Modified by		:                                                                             */
/*	Created			:                                                                             */
/*	Last Revision	:                                                                             */
/*                                                                                                */
/*________________________________________________________________________________________________*/
/*	Comment			: Лабораторная работа №1, 3 семестр                                           */
/**************************************************************************************************/

//Подключение небобходимых библиотек
#include "Header.h"

//Подключаем стандартное пространство имён
using namespace std;

//Точка входа в программу
int main()
{
	//Подключаем русский язык
	setlocale(LC_ALL, "ru");
	srand(time(NULL));//Подключаем генерацию случайных чисел

	int count, //количество элементов в массиве
		limit, //ограничение на последовательность
		error_code,//код ошибки
		number_of_key_comparisons_bls = 0,//кол-во сравнений BLS
		number_of_key_comparisons_sls = 0,//кол-во сравнений SLS
		number_of_comparisons_at_index_analysis = 0;//количество сравнений при анализе индекса элемента массива в цикле

	cout << "Введите количество элементов последовательности: ";
	cin >> count;//Вводим кол-во элементов
	while (cin.fail() || count <= 0) {//Вводим кол-во элементов пока оно не будет больше 0
		cout << "Количество элементов должно быть больше 0. Введите ещё раз: ";
		cin >> count;//Вводим кол-во элементов
	}

	cout << "Введите ограничение для целых чисел: ";
	cin >> limit;//Вводим ограничение для целых чисел
	while (cin.fail() || limit <= 0) {//Вводим кол-во элементов пока оно не будет больше 0
		cout << "Ограничение должно быть больше 0. Введите ещё раз: ";
		cin >> limit;
	}

	double* time = new double[N];//массив,хранящий замеры времени выполнения функции
	int* bls_sls_sequestion = new int[count];//выделение памяти под последовательность для алгоритмов SLS и BLS
	int* oas_bs_sequestion = new int[count];//выделение памяти под последовательность для алгоритмов OAS и BS 

	//Генерация последовательностей
	random_seq(bls_sls_sequestion, count, limit);
	increase_seq(oas_bs_sequestion, count, limit);

	cout << "Случайно сгенерированная последовательность:\n";
	for (int i = 0; i < count; ++i)
	{
		cout << bls_sls_sequestion[i] << " ";
	}

	cout << "\nНеубывающая последовательность:\n";
	for (int i = 0; i < count; ++i)
	{
		cout << oas_bs_sequestion[i] << " ";
	}

	int bls_sls_key,//елемент, который нужно найти в случайной последовательности 
		oas_bs_key,//елемент, который нужно найти в неубывающей последовательности 
		search_result;//результат поиска

	cout << "\nВведите елемент, который нужно найти в случайной последовательности: ";
	cin >> bls_sls_key;//bls_sls_key
	while (cin.fail()) {//bls_sls_key пока он не перестанет быть не числом
		cin >> bls_sls_key;//bls_sls_key
	}

	cout << "Введите елемент, который нужно найти в неубывающей последовательности: ";
	cin >> oas_bs_key;//Вводим oas_bs_key
	while (cin.fail()) {//Вводим oas_bs_key пока он не перестанет быть не числом
		cin >> oas_bs_key;
	}

	//Замер времени
	/*                                   Better Linear Search                                   */
	//Начинаем отчёт времени
	auto begin1 = std::chrono::steady_clock::now();

	//Вызов функции 
	search_result = better_linear_search(bls_sls_sequestion, count, number_of_key_comparisons_bls, number_of_comparisons_at_index_analysis, bls_sls_key);

	auto end1 = std::chrono::steady_clock::now();//останавливаем подчёт времени
	auto res_time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);//вычисляем время работы
	time[0] = res_time1.count();//записываем время работы функции
	cout << "\nBetter Lenear Search: " << res_time1.count() << " мкС\nРезультат: " << search_result
		<< "\nКол-во сравнений: " << number_of_key_comparisons_bls
		<< "\nКол-во сравнений при анализе индекса элемента массива в цикле: " << number_of_comparisons_at_index_analysis;

	/*                                   Sentinel Linear Search                                   */
	//Начинаем отчёт времени
	begin1 = std::chrono::steady_clock::now();

	//Вызов функции 
	search_result = sentinel_linear_search(bls_sls_sequestion, count, number_of_key_comparisons_sls, bls_sls_key);

	end1 = std::chrono::steady_clock::now();//останавливаем подчёт времени
	res_time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);//вычисляем время работы
	time[1] = res_time1.count();//записываем время работы функции
	cout << "\nSentinel Linear Search: " << res_time1.count() << " мкС\nРезультат: " << search_result
		<< "\nКол-во сравнений: " << number_of_key_comparisons_sls;

	/*                                   Ordered Array Search                                      */
	//Начинаем отчёт времени
	begin1 = std::chrono::steady_clock::now();

	//Вызов функции 
	search_result = ordered_array_search(oas_bs_sequestion, count, oas_bs_key);

	end1 = std::chrono::steady_clock::now();//останавливаем подчёт времени
	res_time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);//вычисляем время работы
	time[2] = res_time1.count();//записываем время работы функции
	cout << "\nOrdered Array Search: " << res_time1.count() << " мкС\nРезультат: " << search_result;

	/*                                      Binary Search                                           */
	//Начинаем отчёт времени
	begin1 = std::chrono::steady_clock::now();

	//Вызов функции 
	search_result = binary_search(oas_bs_sequestion, count, oas_bs_key);

	end1 = std::chrono::steady_clock::now();//останавливаем подчёт времени
	res_time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);//вычисляем время работы
	time[3] = res_time1.count();//записываем время работы функции
	cout << "\nBinary Search: " << res_time1.count() << " мкС\nРезультат: " << search_result << '\n';

	//Сохраняем данные  в файл
	fill_file(time, number_of_key_comparisons_bls, number_of_comparisons_at_index_analysis, number_of_key_comparisons_sls, error_code);

	//Проверяем на наличие ошибок
	switch (error_code)
	{
	case 1: cout << "Файл не найден!\n"; break;
	case 0: cout << "Данные успешно сохранены в файл!\n"; break;
	}

	//Освобождаем память
	delete[] time;
	delete[] bls_sls_sequestion;
	delete[] oas_bs_sequestion;

	system("pause");//Чтобы консоль не закрывалась сразу после выполения
	return 0;//Возвращаем 0,программа успешно завершилась
}//Конец программы

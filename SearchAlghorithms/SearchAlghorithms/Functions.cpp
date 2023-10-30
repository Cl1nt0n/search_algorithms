#include "Header.h"

//последовательный поиск возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND
int better_linear_search(int* sequestion, int size, int& number_of_key_comparisons, int& number_of_comparisons_at_index_analysis, int element_to_search)
{
	int i = 0;
	while (*(sequestion + i) != element_to_search)//Пока  i-ый эл-т массива не равен ключу 
	{
		++i;//Переходим к следующему эл-ту
		++number_of_key_comparisons;//Увеличиваем счётчик кол-ва сравнений
		if (i > size - 1)//Если индекс вышел за границу массива
		{
			return NOT_FOUND;//Возвращаем, т.к. эл-т не найден
		}
		++number_of_comparisons_at_index_analysis;//Увеличиваем счётчик сравнения индексов
	}

	return i;//Возвращаем индекс найденного эл-та

}

//быстрый последовательный поиск возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND
int sentinel_linear_search(int* sequestion, int size, int& number_of_key_comparisons, int element_to_search)
{
	int last = *(sequestion + size - 1);//Сохраняем последний эл-т массива
	*(sequestion + size - 1) = element_to_search;//устанавливаем ключ в конец массива

	int i = 0;//Устанавливаем индекс на 0
	while (*(sequestion + i) != element_to_search)//Пока  i-ый эл-т массива не равен ключу 
	{
		++i;//Переходим к следующему эл-ту
		++number_of_key_comparisons;//Увеличиваем счётчик кол-ва сравнений
	}

	*(sequestion + size - 1) = last;//Возвращаем последний эл-т на своё место
	if (i < size //Если индекс не вышел за пределы массива или последний эл-т массива равен ключу
		|| *(sequestion + size - 1) == element_to_search)
	{
		return i;//Возвращаем индекс найденного эл-та
	}

	return NOT_FOUND;//Возвращаем,если эл-т не найден
}

//последовательный поиск в упорядоченном массиве возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND
int ordered_array_search(int* sequestion, int size, int element_to_search)
{
	int i = 0;
	while (*(sequestion + i) < element_to_search)//Пока  i-ый эл-т массива меньше,чем нужный
	{
		++i;//Переходим к следующему
	}
	if (i < size)//Если индекс не вышел за границы массива,то возвращаем его
	{
		return i;//Возвращаем индекс найденного эл-та
	}

	return NOT_FOUND;//Возвращаем,если эл-т не найден
}

//бинарный поиск возвращает индекс искомого элемента,если элемента нет,то вернёт NOT_FOUND
int binary_search(int* sequestion, int size, int element_to_search)
{
	int begin_index = 0,//начальный индекс
		end_index = size - 1,//индекс последнего эл-та массива
		midle;//середина между начальным и конечным индексом

	while (begin_index <= end_index)//Пока начало не больше,чем конец
	{
		midle = (begin_index + end_index) / 2;//Вычисляем среднее значение между началом и концом
		if (*(sequestion + midle) == element_to_search)//Если средний эл-т совпал с ключом
		{
			return midle;//Возвращаем индекс этого эл-та
		}
		else if (*(sequestion + midle) > element_to_search)//Если средний эл-т больше ключа
		{
			end_index = midle;//Сдвигаем конечный индекс на место среднего
		}
		else//Если средний эл-т меньше ключа
		{
			begin_index = midle;//Сдвигаем начальный индекс на место среднего
		}
	}

	return NOT_FOUND;//Возвращаем,если эл-т не найден
}

//Функция вывода в файл
void fill_file(double* sequestion, int number_of_key_comparisons_bls, int number_of_comparisons_at_index_analysis_bls, int number_of_key_comparisons_sls, int& error_code)
{
	ofstream out;//Поток для вывода
	out.open("data.csv", //Название файла
		ios_base::app);//Указание, что нужно добавлять данные, но не перезаписывать файл

	if (!out.is_open())
	{//Если файл для записи целых чисел не открыт
		error_code = 1;//Выходим из программы и устанавливаем код ошибки `1`
		return;
	}

	for (int i = 0; i < N; ++i)
	{//Выводим данные в файл
		out << *(sequestion + i) << ';';
	}
	//Вывод кол-ва сравнений
	out << number_of_key_comparisons_bls << ';'
		<< number_of_comparisons_at_index_analysis_bls << ';'
		<< number_of_key_comparisons_sls << '\n';
	out.close();//Закрываем файл
	error_code = 0;//ошибок не обнаружено
}

//Функция создания возрастающей целочисленной последовательности
void increase_seq(int* arr, int size, int max_value)
{
	*arr = rand() % max_value;//первое число - случайное из указанного диапазона
	for (int i = 1; i < size; ++i) {//Каждое следущее - предыдущее,к которому прибавили случайное число
		*(arr + i) = *(arr + i - 1) + rand() % max_value;//Присваиваем случайное число + предыдущее зачение
	}
}

//Функция создания случайной целочисленной последовательности
void random_seq(int* arr, int size, int max_value)
{
	//Заполняем массив случайными числами в указанном диапазоне
	for (int i = 0; i < size; ++i) 
	{
		*(arr + i) = rand() % max_value;//В i-ый элемент присваиваем случайный элемент
	}
}
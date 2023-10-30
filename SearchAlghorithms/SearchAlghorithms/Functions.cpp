#include "Header.h"

//���������������� ����� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND
int better_linear_search(int* sequestion, int size, int& number_of_key_comparisons, int& number_of_comparisons_at_index_analysis, int element_to_search)
{
	int i = 0;
	while (*(sequestion + i) != element_to_search)//����  i-�� ��-� ������� �� ����� ����� 
	{
		++i;//��������� � ���������� ��-��
		++number_of_key_comparisons;//����������� ������� ���-�� ���������
		if (i > size - 1)//���� ������ ����� �� ������� �������
		{
			return NOT_FOUND;//����������, �.�. ��-� �� ������
		}
		++number_of_comparisons_at_index_analysis;//����������� ������� ��������� ��������
	}

	return i;//���������� ������ ���������� ��-��

}

//������� ���������������� ����� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND
int sentinel_linear_search(int* sequestion, int size, int& number_of_key_comparisons, int element_to_search)
{
	int last = *(sequestion + size - 1);//��������� ��������� ��-� �������
	*(sequestion + size - 1) = element_to_search;//������������� ���� � ����� �������

	int i = 0;//������������� ������ �� 0
	while (*(sequestion + i) != element_to_search)//����  i-�� ��-� ������� �� ����� ����� 
	{
		++i;//��������� � ���������� ��-��
		++number_of_key_comparisons;//����������� ������� ���-�� ���������
	}

	*(sequestion + size - 1) = last;//���������� ��������� ��-� �� ��� �����
	if (i < size //���� ������ �� ����� �� ������� ������� ��� ��������� ��-� ������� ����� �����
		|| *(sequestion + size - 1) == element_to_search)
	{
		return i;//���������� ������ ���������� ��-��
	}

	return NOT_FOUND;//����������,���� ��-� �� ������
}

//���������������� ����� � ������������� ������� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND
int ordered_array_search(int* sequestion, int size, int element_to_search)
{
	int i = 0;
	while (*(sequestion + i) < element_to_search)//����  i-�� ��-� ������� ������,��� ������
	{
		++i;//��������� � ����������
	}
	if (i < size)//���� ������ �� ����� �� ������� �������,�� ���������� ���
	{
		return i;//���������� ������ ���������� ��-��
	}

	return NOT_FOUND;//����������,���� ��-� �� ������
}

//�������� ����� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND
int binary_search(int* sequestion, int size, int element_to_search)
{
	int begin_index = 0,//��������� ������
		end_index = size - 1,//������ ���������� ��-�� �������
		midle;//�������� ����� ��������� � �������� ��������

	while (begin_index <= end_index)//���� ������ �� ������,��� �����
	{
		midle = (begin_index + end_index) / 2;//��������� ������� �������� ����� ������� � ������
		if (*(sequestion + midle) == element_to_search)//���� ������� ��-� ������ � ������
		{
			return midle;//���������� ������ ����� ��-��
		}
		else if (*(sequestion + midle) > element_to_search)//���� ������� ��-� ������ �����
		{
			end_index = midle;//�������� �������� ������ �� ����� ��������
		}
		else//���� ������� ��-� ������ �����
		{
			begin_index = midle;//�������� ��������� ������ �� ����� ��������
		}
	}

	return NOT_FOUND;//����������,���� ��-� �� ������
}

//������� ������ � ����
void fill_file(double* sequestion, int number_of_key_comparisons_bls, int number_of_comparisons_at_index_analysis_bls, int number_of_key_comparisons_sls, int& error_code)
{
	ofstream out;//����� ��� ������
	out.open("data.csv", //�������� �����
		ios_base::app);//��������, ��� ����� ��������� ������, �� �� �������������� ����

	if (!out.is_open())
	{//���� ���� ��� ������ ����� ����� �� ������
		error_code = 1;//������� �� ��������� � ������������� ��� ������ `1`
		return;
	}

	for (int i = 0; i < N; ++i)
	{//������� ������ � ����
		out << *(sequestion + i) << ';';
	}
	//����� ���-�� ���������
	out << number_of_key_comparisons_bls << ';'
		<< number_of_comparisons_at_index_analysis_bls << ';'
		<< number_of_key_comparisons_sls << '\n';
	out.close();//��������� ����
	error_code = 0;//������ �� ����������
}

//������� �������� ������������ ������������� ������������������
void increase_seq(int* arr, int size, int max_value)
{
	*arr = rand() % max_value;//������ ����� - ��������� �� ���������� ���������
	for (int i = 1; i < size; ++i) {//������ �������� - ����������,� �������� ��������� ��������� �����
		*(arr + i) = *(arr + i - 1) + rand() % max_value;//����������� ��������� ����� + ���������� �������
	}
}

//������� �������� ��������� ������������� ������������������
void random_seq(int* arr, int size, int max_value)
{
	//��������� ������ ���������� ������� � ��������� ���������
	for (int i = 0; i < size; ++i) 
	{
		*(arr + i) = rand() % max_value;//� i-�� ������� ����������� ��������� �������
	}
}
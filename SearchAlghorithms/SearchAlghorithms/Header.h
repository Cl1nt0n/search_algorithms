//����������� ����������� ���������
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <chrono>  //���������� ��� ���������� ������� ������ ����������

#define NOT_FOUND -1 //������������ ������, � ������ ���� ������� �� ������
#define N 4//���-�� �������

//���������� ����������� ������������ ���
using namespace std;

int better_linear_search(int* sequestion,//������������������ ��� ������
	int size,//������ ������������������
	int& number_of_key_comparisons,//���-�� ���������
	int& number_of_comparisons_at_index_analysis,//���������� ��������� ��� ������� ������� �������� ������� � �����
	int element_to_search//������� ��� ������
);//���������������� ����� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND

int sentinel_linear_search(
	int* sequestion,//������������������ ��� ������
	int size,//������ ������������������
	int& number_of_key_comparisons,//���-�� ���������
	int element_to_search//������� ��� ������
);//������� ���������������� ����� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND

int ordered_array_search(
	int* sequestion,//������������������ ��� ������
	int size,//������ ������������������
	int element_to_search//������� ��� ������
);//���������������� ����� � ������������� ������� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND

int binary_search(
	int* sequestion,//������������������ ��� ������
	int size,//������ ������������������
	int element_to_search//������� ��� ������
);//�������� ����� ���������� ������ �������� ��������,���� �������� ���,�� ����� NOT_FOUND

//������� ������ � ����
void fill_file(double* sequestion,//������ �������
	int number_of_key_comparisons_bls,//���-�� ��������� BLS
	int number_of_comparisons_at_index_analysis_bls,//���-�� ��������� ������� BLS
	int number_of_key_comparisons_sls,//���-�� ��������� SLS
	int& error_code
);//��� ������

//������� �������� ������������ ������������� ������������������
void increase_seq(int* arr, //������
	int size,				//���������� ���������
	int max_value);				//����������� �� ��������� �����

//������� �������� ��������� ������������ ������������������
void random_seq(int* arr, //������
	int size,				 //���������� ���������
	int max_value);				 //����������� �� ��������� �����
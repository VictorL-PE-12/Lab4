

//
//
//int main() {
//
//	//�������� ������ ������ ������ ����� ����
//
//	int a = 25;
//	int* p;// zminna p zberaigje adresu komirku w jakie zberja czyslo typu int
//	int** p2; // zberigaja adresu w jaki zberijatsja adresa
//	int*** p3; // �������� ���� ����� ������ ���������� �� ��������
//
//	p = &a;
//	p2 = &p; 
//
//	printf("p = %p", p);
//	printf("\n\np2 = %p", p2);
//	printf("\n\n&p2 = %p", &p2);
//	return 0;
//}


//
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <conio.h>
//#include <time.h>
//
//#define SIZE 7
//
//void printArray(int [], int);//prototyp, w nych imenna ignorujutsa
//
//
//int main() {
//	int x [SIZE];
//	int z [SIZE] = { 1, 8 , 12, 15 , 22 ,35 ,43 };
//	printArray(z, SIZE);
//
//	return 0;
//}
//
//void printArray(int Z[], int S)
//{
//	int j;
//
//	for(j = 0;  j <= S-1 ; j++)
//	{
//		printf("%4d", Z[j]);
//
//	}
//
//}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include < malloc.h >  // ��� ������������ ������� ���������� �������� ���'�� 


const size_t SIZE = 30;

//#define SIZE 4  //����� ������ ���� ���������� � �������� 
//
//void printArray(int[], int); // 1 ������� ����� ���� ��� � 2 �������� ����� ������ (� ���������� ����� �����������)
//int search_MAX(int[], int);
//int search_MIN(int[], int);
//
//int ArrayBFunc(int[SIZE], int); // ����� ���������� �� 4��������
//
//
//void search_Max2(int z[], int S, int* pMax, int* pIndex);//������� ���� ���������� �����, ���� �����, ������, ������ ����� ��� ���� ������� ������ ������������� �������� 
//
//
//void sort_1D(int[], int S);



void CreateValues(int* iArr, size_t size); //������� ����� �� �������
//void BubbleSort(int* iArr);
//void SelectSort(int* iArr); 
//void InsertSort(int* iArr);
void RecursionSort(int* iArr, size_t l, size_t r);// ���������� �� �����o�o�  ������

//int* SetArray(void) //������� ������� �������� �� int, (void) - ����������� ���������� �, ��� ����� () 
//{
//	int* iTmpArr = (int*) calloc(SIZE, sizeof(int));// ����������� �����(����������) ������� SIZE
//
//	CreateValues(iTmpArr);
//
//	return iTmpArr;
//
//}



int main()
{
	int num1;


	//___________________________________________

	int* a;  // �������� �� �����
	int i, j, n, m;
	system("chcp 1251");
	system("cls");
	printf("ʳ������ �����: ");
	scanf_s("%d", &n);
	printf("ʳ������ ��������: ");
	scanf_s("%d", &m);
	// �������� ���'��
	//malloc - ������� ��� ���������� ������ ������ � ������ 
	// int sizeof() - ��� ������� ���������� ������ ��������
	// �������� ���'��
	a = (int*)malloc(n * m * sizeof(int));// n�m�(����� ��������) - ��'�� ���'� ���������� ��� ��������� ����������� ������

	//printf("%d ����� ������\n\t = ", a);
	// ������ ����� ������� ������
	for (i = 0; i < n; i++)  // ������ ������
	{
		for (j = 0; j < m; j++)  // ���� �� ��������
		{
			printf("a[%d][%d] = ", i, j);//index = i*m+j;
			scanf_s("%d", (a + i * m + j)); // � - �������� �� �����, m - ������� ��������  i - ������ �����  j ������ �������
		}
	}
	// �u����� ����� ������� ������
	for (i = 0; i < n; i++)  // �� ������
	{
		for (j = 0; j < m; j++) //  ���� �� ��������
		{
			//*(a + i * m + j) ��������� �� �������� index = i*m+j; // ����� �����
			printf("%5d ", *(a + i * m + j)); // ���� ������� 5 ������� �� ������ ������
		}
		printf("\n");
	}

	int ArrayA = *(a + i * m + j);


	num1 = *(a + 0 * m + 1); // ������� � �� j ����� ��������� ���� ���� �������� ������

	printf("\n������������� ������� A\n");
	for (i = 0; i < n; i++)// ��������� �������, ��� ��������� ���������� � �������
	{
		for (j = 0; j < m; j++)

		{
			int ArrayAT = *(a + j * m + i);
			printf("\t %d ", ArrayAT);
		}
		printf("\n");
	}

	printf("\t\n");


	//printf("����� = \n%5d   ", num1);

//	free(a);
	//getchar();   getchar();
	//-------------------------------------------------------

	int* b;  // �������� �� �����


	// �������� ���'��
	//malloc - ������� ��� ���������� ������ ������ � ������ 
	// int sizeof() - ��� ������� ���������� ������ ��������
	// �������� ���'��
	b = (int*)malloc(n * m * sizeof(int));// n�m�(����� ��������) - ��'�� ���'� ���������� ��� ��������� ����������� ������

	//printf("%d ����� ������\n\t = ", a);
	// ������ ����� ������� ������

	for (i = 0; i < n; i++)  // ������ ������
	{
		for (j = 0; j < m; j++)  // ���� �� ��������
		{
			printf("b[%d][%d] = ", i, j);//index = i*m+j;
			scanf_s("%d", (b + i * m + j)); // � - �������� �� �����, m - ������� ��������  i - ������ �����  j ������ �������
		}
	}
	printf("\n������� B\t\n ");
	// ������ ����� ������� ������
	for (i = 0; i < n; i++)  // �� ������
	{
		for (j = 0; j < m; j++) //  ���� �� ��������
		{
			//*(a + i * m + j) ��������� �� �������� index = i*m+j; // ����� �����
			printf("%5d ", *(b + i * m + j)); // ���� ������� 5 ������� �� ������ ������
		}
		printf("\n ");
	}
	int ArrayB = *(b + i * m + j);

	//�������� �������
	//(ArrayA) (ArrayB);
	int* c;
	c = (int*)malloc(n * m * sizeof(int));
	int k;
	for (i = 0; i < n; i++)// ��������� �������, ��� ��������� ���������� � �������
	{
		for (j = 0; j < m; j++)

		{

			for (k = 0; k < m; k++) // ������� �������� � ����� ��������
			{
				*(c + i * m + j) = 0;
				/*int tmp2 = (*(b + k * m + j));
				int tmp3 = (*(a + i * m + k));*/


				*(c + i * m + j) += (*(a + k * m + i)) * (*(b + k * m + j));
				/**(c + i * m + j) = (*(a + i * m + k )) * (*(b + k * m + j));*/
				//int nk = (*(a + k * m + i)) * (*(b + k * m + j));
				//printf("\n%d - [%d][%d]", &nk, i,j);
			   // printf("\n%d - [%d][%d]", *(c + i * m + j), i,j);

			}


		}

	}
	printf("\n��������� �������� ������� � * �( A �������������)\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%5dc ", *(c + i * m + j));
		printf("\n");
	}

	/*int ArrayAxB=* (c + 1 * m + 1) = (*(a + 1 * m + 1)) * (*(b + 1 * m + 1));
	printf("%5dC ", ArrayAxB);*/
	//------------------------------------------------------------------------���������

	int* d;
	d = (int*)malloc(n * m * sizeof(int));

	printf("\n���� ������� � + � = \n");
	for (i = 0; i < n; i++)// ��������� �������, ��� ��������� ���������� � �������
	{
		for (j = 0; j < m; j++)

		{
			*(d + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
			printf("\t %5d ", *(d + i * m + j));
		}
		printf("\n");
	}

	printf("\t\n");
	//____________________________________________________

	// ���� ������ ������������ �� ���������� �������� ������� � _____________________

	int MinNum, MaxNum;
	MinNum = MaxNum = *(a + 0 * m + 0);
	for (i = 0; i < n; i++)
	{
		// ��������� ������ �������� ������ �
		for (j = 0; j < m; j++)
		{
			//���������� ����� ������� ������ � ����������
			if (*(a + j * m + i) > MaxNum)
			{
				MaxNum = *(a + j * m + i);


			}
			if (*(a + j * m + i) < MinNum)
			{
				MinNum = *(a + j * m + i);


			}

		}
	}
	//������� ������������ �������
	printf("\t\n������������ ������� ������� � -  %d\n", MaxNum);


	//������� ��������� �������
	printf("\t\n��������� ������� ������� � - %d\n", MinNum);



	//__________________________________________________________________________

	//__________________________________________________________________________________
	int sort;
	//���� ���������� ������� �� ���������� ______
	printf("\n\t�o�������� ������� � �� ���������� ");
	sort = *(a + j * m + i);
	for (int k = 0; k < n * m; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (j != n - 1) {
					if (*(a + (j + 1) * m + i) < *(a + j * m + i)) {
						int tmp = *(a + (j + 1) * m + i);
						*(a + (j + 1) * m + i) = *(a + j * m + i);
						*(a + j * m + i) = tmp;
					}
				}
				else {
					if ((*(a + 0 * m + (i + 1)) < *(a + j * m + i)) && (i != n - 1)) {
						int tmp = *(a + 0 * m + (i + 1));
						*(a + 0 * m + (i + 1)) = *(a + j * m + i);
						*(a + j * m + i) = tmp;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("\t%d", *(a + j * m + i));



	}
	printf("\t\n\n");
	//_-------------------------------------------------------
//	int ArrayA = *(a + i * m + j);

	//int* v;  
	//int g, s;
	//system("chcp 1251");
	//system("cls");
	//printf("����� ������: ");
	//scanf("%d", &s);
	//v = (int*)malloc(s * sizeof(int));
	//// �u����� ����� ������� ������
	//for (i = 0; i < n; i++)
	//{
	//	printf("a[%d] = ", g);
	//	scanf("%d", &v[g]);
	//}
	//for (g = 0; g < s; g++)  // �� ������
	//{
	//	
	//	for (i = 0; i < n; i++)
	//	{
	//		printf("a[%d] = ", g);
	//		scanf("%d", &v[g]);
	//	}
	//	
	//	printf("\n");
	//}

	//int A [15] = { 3,62,6,2,89,24,8,3,7,0,3,6,9 };

	// 2 �����
	srand(time(0));

	printf("\t\n\n");
	//printf("2 ���Ѳ�");
	printf("\t\n\n");

	//int* p0 = NULL; //����� ��������� �������� �� ������ �������� 
	//int* p1 = NULL;
	//int* p2 = NULL;
	//int* p3 = NULL;

	//p0 = (int*)malloc(SIZE * sizeof(int)); // malloc - ������� ����� ���������� ������*
	//p1 = (int*)calloc(SIZE, sizeof(int)); //calloc - ������ ����� ��������� ������, SIZE - �����, sizeof(int) - ����� 1 ��������
	//�������� � ��������� �������� (1 ��)
	// (int*) malloc ������� �������� �� void - ���� ���� ����� �������� ����-��� ��������

//	printf("%d %x\n", p0[0], p0);// ������� 0 ������� ������ � ������* �� ������ ������� �������
//	printf("%d %x\n", p1[0], p1);
//	printf("%d %x\n", sizeof(p0), sizeof(p0[0]));

	//p0 = (int*)realloc(p0, (SIZE+1) * sizeof(int)); // realloc - �������� ������ �����
	//// �������� ����� �� 1 �������
	//p1 = (int*)realloc(p1, sizeof(int));// ����������� ����� �� ����� � 1 ��������

	//free(p0);
	//free(p1);// ���� �� �� ������� ���� ���� ���'��
	//free(p2);// ������� �� ���� ��� NULL ������
	//
	//int* iArr = SetArray();
	int* iArr = (int*)calloc(SIZE, sizeof(int));
	CreateValues(iArr, SIZE);
	/*printf("BubbleSort \t");
	BubbleSort(iArr,SIZE);
	CreateValues(iArr, SIZE);


	printf("SelectSort\t");
	SelectSort(iArr, SIZE);
	CreateValues(iArr, SIZE);


	printf("InsertSort\t");
	InsertSort(iArr, SIZE);
	CreateValues(iArr, SIZE);*/

	printf("RecursionSort\t");
	RecursionSort(iArr, 0, SIZE - 1);
	CreateValues(iArr, SIZE);
	system("pause");

	/*for (size_t i = 0; i < 30; ++i)
	{
		printf("%d\t", iArr[i]);
	}
	for (int i = 0; i < SIZE; i++)
		printf("\n\t%4d ", iArr[i]);
	free(iArr);*/
	system("pause");
	


	//-----------------------------------------------------------------------------------
	//int z[SIZE] = { 1,245,-12,15 }; // ����� 
	//int max, min, Max2, index;

	//printArray(z, SIZE);

	//max = search_MAX(z, SIZE);

	//printf("\n\n max=%d", max);

	//min = search_MIN(z, SIZE);
	//printf("\n\n min=%d", min);

	//search_Max2(z, SIZE, &Max2, &index);
	//printf("\n\nMax2=%d    index=%d\t", Max2, index);
	//-----------------------------------------------------------------------------------

	return 0;
}

void CreateValues(int* iArr, size_t size) // 
{
	for (size_t i = 0; i < SIZE; ++i) // ������� ���� �������� �������� � ������� : 128 - 64
		iArr[i] = rand() % 128 - 64;
}

//
//void BubbleSort(int* iArr)
//{
//	for (size_t i = 0; i < SIZE; i++)
//	{
//		for (size_t j = 0; j < SIZE-i-1; i++)
//		{
//			if (iArr[j] > iArr[j+1])
//			{
//				
//				int iTmp = iArr[j];
//				iArr[j] = iArr[j + 1];
//				iArr[j + 1] = iTmp;
//				
//			}
//		}
//	}
//}
//
//void SelectSort(int* iArr)
//{
//	for (size_t i = 0; i < SIZE; i++)
//	{
//		size_t iMinIndex = i;
//		for (size_t j = i + 1; j < SIZE; j++)
//		{
//			if (iArr[j] < iArr[iMinIndex])
//			{
//				iMinIndex = j;
//			}
//			int tmp = iArr[i];
//			iArr[i] = iArr[iMinIndex];
//			iArr[iMinIndex] = tmp;
//		}
//	}
//}
//
//void InsertSort(int* iArr)
//{
//	int iTmp = 0;
//	size_t iIndex = 0;
//	for (size_t i = 1; i < SIZE; i++)
//	{
//		iTmp = iArr[i];
//		iIndex = i - 1;
//		while (iIndex >= 0 && iArr [iIndex]> iTmp)
//		{
//			iArr[iIndex + 1] = iArr[iIndex];
//			iArr[iIndex] = iTmp;
//			--iIndex;
//		}
//	}
//}
void RecursionSort(int* iArr, size_t l, size_t r)
{
	int pivot = iArr[(l + r) / 2]; // �������� ��������
	size_t lMargin = l;//��� �������
	size_t rMargin = r;// ����� �������
	while (l<r)//// ���� ������� �� ���������
	{
		while ((iArr[r] >= pivot) && (l<r))
			--r;// ������� ����� ������� ���� ������� [right] ����� [pivot]
		if (l != r)// ���� ������� �� ���������
		{
				iArr[l] = iArr[r];// ��������� ������� [right] 
				++l;
		}
		
		while ((iArr[l] <= pivot) && (l < r))
			++l;// ������� ��� �������, ���� ������� [left] ����� [pivot]
		if (l != r) //���� ������� �� ���������
		{
			iArr[r] = iArr[l];; // ��������� ������� [left] �� ���� [right]
			--r;// ���� ������� ������� ������
		}
		
	}
	iArr[l] = pivot; // ������� ��������� ������� �� ����
	pivot = l;
								//printf("%d\t%d\t", l,r);
								//printf("%d\t%d\t", iArr[l], iArr[r]);
//printf("%d\t", pivot);//
	l = lMargin;
	r = rMargin;

	if (l < pivot) // ���������� ��������� ���������� ��� ��� �� ����� ������� ������
		RecursionSort(iArr, l, pivot - 1);
	if (r > pivot)
		RecursionSort(iArr, pivot + 1, r);
}














//__________________________________________________
//void printArray(int Z[], int S)// S - �������� ����� ��� ���� ���������� �������� �������� SIZE ������������� ��� �������� ������ �� ��� ������
//{
//	int j;
//
//	for (j = S - 1; j >= 0; j--) // j = S-1 - ������� ������� �� 0
//	{
//		printf("%4d", Z[j]); // ���� ������� 4 ������� ���������� �������� ������  Z[j]  Z- ��'� j- ������
//
//	}
//}
////__________________________________________________
//int search_MAX(int z[], int S)
//{
//	int temp_max = z[0]; // �������, ����� 
//	int j;//localna zminna dije w mezach fucniji
//
//	for (j = 1; j <= S - 1; j++)//�������� �� ��� ��������� ������ ��������� � 2 �������� � �� ���� � ��������� � temp_ma�  ����� ������ ���� �������� ������� ������ 
//		// �� ������� �������� temp_ma� �� ����� ������������
//		// j <= S - 1   j - �� ������� �������� �� ��� ������
//		// j = 1 �������� �� ������ �� ���������� ������� ������� 0
//	{
//		if (z[j] > temp_max)// ���� �������� ������� ������ ��� ���� ������ �� �������� ���� ��� ��� �������� ���� ��� ���� ������������� �������� ����� �������� ������
//		{
//			temp_max = z[j];
//			//	printf("\ntemp_max=%d", temp_max);
//			//	_getch();
//		}
//	}
//	return temp_max;
//}
////__________________________________________________
//int search_MIN(int z[], int S)
//{
//	int temp_min = z[0];
//	int j;//localna zminna dije w mezach fucniji
//
//	for (j = 1; j <= S - 1; j++)
//	{
//		if (z[j] < temp_min)
//		{
//			temp_min = z[j];
//			//printf("\ntemp_min=%d", temp_min);
//			//_getch();
//		}
//	}
//	return temp_min;
//}
//
//
////_________________________________
//
//void search_Max2(int z[], int S, int* pMax, int* pIndex)
//{
//	int temp_max;
//	int temp_index;
//	int j;
//
//	temp_max = z[0];//1.01
//	temp_index = 0;
//
//	for (j = 1; j < S - 1; j++)
//	{
//		if (z[j] > temp_max)
//		{
//			temp_max = z[j];
//			temp_index = j;
//		}
//	}
//	*pMax = temp_max;//otrymyje dostup 
//	*pIndex = temp_index;
//}
////________________________________________________

#include <stdio.h>
#include <stdlib.h>

void swap(double* x, double* y);

int main()
{
	double detcoef = 1;		// ERO 수행시 determinant 값의 변화를 저장

	int m, n;
	printf("행렬의 행숫자(식수)를 입력하세요 : ");
	scanf_s("%d", &m);		// 행숫자(m) 입력
	printf("행렬의 열숫자(미지수 개수)를 입력하세요 : ");
	scanf_s("%d", &n);		// 열숫자(n) 입력

	double* ptr;		// 1차원 포인터
	ptr = (double*)calloc(n, sizeof(double));		// leading variable에 1을 저장, free variable에 0을 저장

	if (ptr == NULL)		// 메모리를 할당하지 못한 경우 메시지 출력 후 종료
	{
		printf("# 메모리가 부족합니다. 다시 실행해주세요!\n");
		exit(1);
	}

	double** unit_pptr = calloc(n, sizeof(double*));		// 역행렬을 저장할 공간

	for (int i = 0; i < n; i++)
	{
		*(unit_pptr + i) = (double*)calloc(n, sizeof(double));
	}

	for (int i = 0; i < n; i++)
	{
		*(*(unit_pptr + i) + i) = 1;
	}

	double** pptr = malloc(sizeof(double*) * m);

	for (int i = 0; i < m; i++)
	{
		*(pptr + i) = (double*)malloc(sizeof(double) * (n + 1));
	}

	printf("Augmented 행렬의 각 행의 내용을 입력하시오 : \n");
	for (int i = 0; i < m; i++)
	{
		printf("%d행:    ", i + 1);
		for (int j = 0; j < n + 1; j++)
		{
			scanf_s("%lf", &*(*(pptr + i) + j));
		}
		printf("\n");
	}

	printf("Augmented 행렬 : \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%.4lf   ", *(*(pptr + i) + j));
		}
		printf("\n");
	}


	// 첨가행렬의 완성
	// 먼저 가우스소거법 완성하기

	int col = 0;		// 열을 뜻하는 col저장

	for (int row = 0; row < m; row++)		// 1행부터 m까지 반복해서 처리
	{
		for (;;)
		{
			int judge = 0;
			for (int i = row; i < m; i++)
			{
				if (*(*(pptr + i) + col) != 0)
				{
					judge++;		// 0이 아닌 행 judge에 저장
				}
			}

			if (judge == 0)		// 만약 열이 모두 0이라면
			{
				col++;		// 행은 그대로 열은 하나추가
				if (col >= n)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}

		if (col >= n)
		{
			break;
		}

		int index = 0;
		for (int i = row; i < m; i++)
		{
			if (*(*(pptr + i) + col) != 0)
			{
				index = i; // 0이 아닌 행 index에 저장
				break; // 0이 아닌 최초의 행 저장한 후 탈출
			}
		}

		if (index != 0)
		{
			for (int j = col; j < n + 1; j++)// 행교환
			{
				if (index != row)
				{
					swap(&*(*(pptr + row) + j), &*(*(pptr + index) + j));
				}
			}
			if (m == n)		// 단위행렬 행교환(역행렬 계산)
			{
				for (int j = 0; j < n; j++)
				{
					if (index != row)
					{
						swap(&*(*(unit_pptr + row) + j), &*(*(unit_pptr + index) + j));
					}
				}
			}
			if (index != row)
			{
				detcoef = (-detcoef);		// 행교환(-det)
			}
		}

		// row이하 열의 계수 모두 1로 만들기 (row행 포함)
		for (int i = row; i < m; i++)
		{
			double point_start = *(*(pptr + i) + col); // arr[i][0]의 값이 바뀌기 때문에 저장해줘야함
			for (int j = col; j < n + 1; j++) // 첫번째 행 arr[i][0]으로 나누기
			{
				if (*(*(pptr + i) + col) != 0) // 계수가 0이 아니면
				{
					*(*(pptr + i) + j) = *(*(pptr + i) + j) / point_start;
				}
			}
			if (m == n)		// 단위행렬의 첫번째 행 arr[i][0]으로 나누기(역행렬 계산)
			{
				for (int j = 0; j < n; j++)
				{
					if (*(*(pptr + i) + col) != 0) // 계수가 0이 아니면
					{
						*(*(unit_pptr + i) + j) = *(*(unit_pptr + i) + j) / point_start;
					}
				}
			}
			if (point_start != 0)
			{
				detcoef *= point_start;		// 행에 상수곱(kdet)
			}
		}

		// 행에서 행을 빼는 함수만 만들면 됨
		// leading 1 만들기

		for (int i = row + 1; i < m; i++) // m = 1 에서 leading 1 만들기
		{
			if (*(*(pptr + i) + col) != 0)// arr[i][0] 이 0이 아닐 때만 실행
			{
				for (int j = col; j < n + 1; j++)
				{
					*(*(pptr + i) + j) -= *(*(pptr + row) + j);
				}
				if (m == n)		// leading 1을 만들 때 단위행렬에서의 계산(역행렬 계산)
				{
					for (int j = 0; j < n; j++)
					{
						*(*(unit_pptr + i) + j) -= *(*(unit_pptr + row) + j);
					}
				}
			}
		}

		col++;
		// 여기서 col은 n을 넘기면 안된다
		if (col >= n)
		{
			break;
		}
	}

	printf("\n\n-----가우스 소거법 완료------\n");
	printf("Augmented 행렬 : \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%.4lf   ", *(*(pptr + i) + j));
		}
		printf("\n");
	}

	// 가우스 소거법 완료
	// 가우스 조던 소거법 시작
	if ((m > 1) && (n > 1))		// 행과 열이 1보다 클때만 가우스 조던 소거법 시행
	{
		int t = 0;
		for (int l1_row = m - 1; l1_row > 0; l1_row--)		// 맨 아래 행부터 leading-1의 위치를 찾는 반복문
		{
			int l1_col = -1;
			for (int k = 0; k < n; k++)
			{
				if (*(*(pptr + l1_row) + k) != 0)		// 특정 행에서 leading-1인 열을 찾아 저장
				{
					l1_col = k;
					break;
				}
			}
			if (l1_col == -1)		// 행에 leading-1이 없을 경우 윗 행으로 이동
			{
				t++;
				continue;
			}
			else
			{
				for (int i = 0; i < m - 1 - t; i++)		// 가우스 조던 소거법을 완성하기 위해 연산 수행
				{
					double reduced_echelon = *(*(pptr + i) + l1_col);		// arr[i][j]값이 바뀌기 때문에 저장해주어야 함
					if (reduced_echelon != 0)
					{
						*(*(pptr + i) + l1_col) = 0;
						*(*(pptr + i) + n) -= reduced_echelon * (*(*(pptr + l1_row) + n));

						for (int j = l1_col + 1; j < n; j++)
						{
							*(*(pptr + i) + j) -= reduced_echelon * (*(*(pptr + l1_row) + j));
						}
						
						if (m == n)		// 단위행렬에 원래 함수의 가우스 조던 소거법 연산 수행(역행렬 계산)
						{
							for (int k = 0; k < n; k++)
							{
								*(*(unit_pptr + i) + k) -= reduced_echelon * (*(*(unit_pptr + l1_row) + k));
							}
						}
					}
				}
				t++;
			}
		}
	}

	printf("\n\n-----가우스 조던 소거법 완료------\n");
	printf("Augmented 행렬 : \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%.4lf   ", *(*(pptr + i) + j));
		}
		printf("\n");
	}
	// 가우스 조던 소거법 완료
	// 해 판별 시작

	int zero = 0;		// Ax = b에서 b가 0벡터인지 확인
	for (int i = 0; i < m; i++)
	{
		if (*(*(pptr + i) + n) == 0)
		{
			zero++;
		}
	}

	int no_sol = 0;		// 모순되는 행을 판단(Ax = b에서 특정 행의 변수 열이 모두 0이지만 b값은 0이 아닌 경우)
	for (int i = m - 1; i >= 0; i--)
	{
		int zero_col = 0;
		for (int j = 0; j < n; j++)
		{
			if (*(*(pptr + i) + j) == 0)
			{
				zero_col++;
			}
		}
		if ((zero_col == n) && (*(*(pptr + i) + n)) != 0)
		{
			no_sol++;
		}
	}

	if (m < n)		// 열이 행보다 많은 경우(무수히 많은 해 존재 or 해가 존재하지 않음)
	{
		if (zero == m)		// Homogeneous(무수히 많은 해 존재)
		{
			printf("\n\n무수히 많은 해 존재\n\n");

			for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// 맨 아래 행부터 leading-1의 위치를 찾는 반복문
			{
				int l1_col = -1;
				for (int k = 0; k < n; k++)
				{
					if (*(*(pptr + l1_row) + k) != 0)
					{
						l1_col = k;
						break;
					}
				}
				if (l1_col == -1)		// leading-1이 없을 경우 윗 행으로 이동
				{
					continue;
				}
				else
				{
					*(ptr + l1_col) = 1;
				}
			}

			int count = 0;
			for (int i = 0; i < n; i++)
			{
				if (*(ptr + i) != 0)
				{
					int zero_sol = 0;		// 특정 행에서 변수 열의 값이 0인 갯수
					for (int j = 0; j < n; j++)
					{
						if (*(*(pptr + count) + j) == 0)
						{
							zero_sol++;
						}
					}

					if (zero_sol == n - 1)		// Xn = c인경우
					{
						printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
					}
					else  // leading variable의 값을 free variable 값으로 표현
					{
						printf("X%d =", i + 1);
						for (int j = i + 1; j < n; j++)
						{
							if (*(ptr + j) == 0)
							{
								if (*(*(pptr + count) + j) != 0)
								{
									if (*(*(pptr + count) + j) > 0)
									{
										printf(" - %.4lf X%d", *(*(pptr + count) + j), j + 1);
									}
									else
									{
										printf(" + %.4lf X%d", -(*(*(pptr + count) + j)), j + 1);
									}
								}
							}
						}
					}
					printf("\n\n");
					count++;
				}
				else  // free variable 표현
				{
					printf("X%d = X%d\n\n", i + 1, i + 1);
				}
			}
		}
		else  // Non-Homogeneous(무수히 많은 해 존재 or 해가 존재하지 않음)
		{
			if (no_sol > 0)
			{
				printf("\n\n해가 존재하지 않음\n\n");
			}
			else
			{
				printf("\n\n무수히 많은 해 존재\n\n");

				for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// 맨 아래 행부터 leading-1의 위치를 찾는 반복문
				{
					int l1_col = -1;
					for (int k = 0; k < n; k++)
					{
						if (*(*(pptr + l1_row) + k) != 0)
						{
							l1_col = k;
							break;
						}
					}
					if (l1_col == -1)		// leading-1이 없을 경우 윗 행으로 이동
					{
						continue;
					}
					else
					{
						*(ptr + l1_col) = 1;
					}
				}

				int count = 0;
				for (int i = 0; i < n; i++)
				{
					if (*(ptr + i) != 0)
					{
						int zero_sol = 0;		// 특정 행에서 변수 열의 값이 0인 갯수
						for (int j = 0; j < n; j++)
						{
							if (*(*(pptr + count) + j) == 0)
							{
								zero_sol++;
							}
						}
						if (zero_sol == n - 1)		// Xn = c일때를 표현
						{
							printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
						}
						else  // leading variable의 값을 free variable 값으로 표현
						{
							if (*(*(pptr + count) + n) != 0)
							{
								printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
							}
							else
							{
								printf("X%d =", i + 1);
							}
							for (int j = i + 1; j < n; j++)
							{
								if (*(ptr + j) == 0)
								{
									if (*(*(pptr + count) + j) != 0)
									{
										if (*(*(pptr + count) + j) > 0)
										{
											printf(" - %.4lf X%d", *(*(pptr + count) + j), j + 1);
										}
										else
										{
											printf(" + %.4lf X%d", -(*(*(pptr + count) + j)), j + 1);
										}
									}
								}
							}
						}
						printf("\n\n");
						count++;
					}
					else
					{
						printf("X%d = X%d\n\n", i + 1, i + 1);
					}
				}
			}
		}
	}
	else  // 행이 열보다 같거나 많을 때(유일해 존재, 무수히 많은 해 존재, 해가 존재하지 않음)
	{
		int unit_mat = 0;
		for (int i = 0; i < n; i++)
		{
			if (*(*(pptr + i) + i) != 0)
			{
				unit_mat++;
			}
		}

		if (zero == m)		// Homogeneous(유일해 존재, 무수히 많은 해 존재)
		{
			if (unit_mat == n)
			{
				printf("\n\n유일해 존재\n\n");
				for (int i = 1; i <= n; i++)
				{
					printf("X%d = 0\n\n", i);
				}
			}
			else
			{
				printf("\n\n무수히 많은 해 존재\n\n");

				for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// 맨 아래 행부터 leading-1의 위치를 찾는 반복문
				{
					int l1_col = -1;
					for (int k = 0; k < n; k++)
					{
						if (*(*(pptr + l1_row) + k) != 0)
						{
							l1_col = k;
							break;
						}
					}
					if (l1_col == -1)		// leading-1이 없을 경우 윗 행으로 이동
					{
						continue;
					}
					else
					{
						*(ptr + l1_col) = 1;
					}
				}

				int count = 0;
				for (int i = 0; i < n; i++)
				{
					if (*(ptr + i) != 0)
					{
						int zero_sol = 0;		// 특정 행에서 변수 열의 값이 0인 갯수
						for (int j = 0; j < n; j++)
						{
							if (*(*(pptr + count) + j) == 0)
							{
								zero_sol++;
							}
						}

						if (zero_sol == n - 1)		// Xn = c일때를 표현
						{
							printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
						}
						else  // leading variable의 값을 free variable 값으로 표현
						{
							printf("X%d =", i + 1);
							for (int j = i + 1; j < n; j++)
							{
								if (*(ptr + j) == 0)
								{
									if (*(*(pptr + count) + j) != 0)
									{
										if (*(*(pptr + count) + j) > 0)
										{
											printf(" - %.4lf X%d", *(*(pptr + count) + j), j + 1);
										}
										else
										{
											printf(" + %.4lf X%d", -(*(*(pptr + count) + j)), j + 1);
										}
									}
								}
							}
						}
						printf("\n\n");
						count++;
					}
					else
					{
						printf("X%d = X%d\n\n", i + 1, i + 1);
					}
				}
			}
		}
		else  // Non-Homogeneous(유일해 존재, 무수히 많은 해 존재, 해가 존재하지 않음)
		{
			if (no_sol > 0)
			{
				printf("\n\n해가 존재하지 않음\n\n");
			}
			else
			{
				if (unit_mat == n)
				{
					printf("\n\n유일해 존재\n\n");
					for (int i = 0; i < n; i++)
					{
						printf("X%d = %.4lf\n\n", i + 1, *(*(pptr + i) + n));
					}
				}
				else
				{
					printf("\n\n무수히 많은 해 존재\n\n");

					for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// 맨 아래 행부터 leading-1의 위치를 찾는 반복문
					{
						int l1_col = -1;
						for (int k = 0; k < n; k++)
						{
							if (*(*(pptr + l1_row) + k) != 0)
							{
								l1_col = k;
								break;
							}
						}
						if (l1_col == -1)		// leading-1이 없을 경우 윗 행으로 이동
						{
							continue;
						}
						else
						{
							*(ptr + l1_col) = 1;
						}
					}

					int count = 0;
					for (int i = 0; i < n; i++)
					{
						if (*(ptr + i) != 0)
						{
							int zero_sol = 0;		// 특정 행에서 변수 열의 값이 0인 갯수
							for (int j = 0; j < n; j++)
							{
								if (*(*(pptr + count) + j) == 0)
								{
									zero_sol++;
								}
							}

							if (zero_sol == n - 1)
							{
								printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
							}
							else  // leading variable의 값을 free variable 값으로 표현
							{
								if (*(*(pptr + count) + n) != 0)
								{
									printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
								}
								else
								{
									printf("X%d =", i + 1);
								}
								for (int j = i + 1; j < n; j++)
								{
									if (*(ptr + j) == 0)
									{
										if (*(*(pptr + count) + j) != 0)
										{
											if (*(*(pptr + count) + j) > 0)
											{
												printf(" - %.4lf X%d", *(*(pptr + count) + j), j + 1);
											}
											else
											{
												printf(" + %.4lf X%d", -(*(*(pptr + count) + j)), j + 1);
											}
										}
									}
								}
							}
							printf("\n\n");
							count++;
						}
						else
						{
							printf("X%d = X%d\n\n", i + 1, i + 1);
						}
					}
				}
			}
		}
	}

	if (m == n)		// Determinant와 역행렬 계산
	{
		int unit_det;
		double determinant;

		int unit_mat = 0;		// 단위행렬(I)인지 확인
		for (int i = 0; i < n; i++)
		{
			if (*(*(pptr + i) + i) != 0)
			{
				unit_mat++;
			}
		}

		if (unit_mat == n)		// 단위행렬(I)일 때 determinant=1
		{
			unit_det = 1;
		}
		else  // 단위행렬(I)가 아닐 때 determinant=0
		{
			unit_det = 0;
		}

		if (unit_det == 0)
		{
			printf("Determinant : 0\n");
			printf("역행렬 계산 불가!\n");
		}
		else
		{
			determinant = detcoef * unit_det;
			printf("Determinant : %.4lf\n", determinant);
			printf("\n역행렬 계산 가능!\n");

			// 역행렬
			printf("\n역행렬 : \n");
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("%.4lf   ", *(*(unit_pptr + i) + j));
				}
				printf("\n");
			}
		}
	}

	free(ptr);

	for (int i = 0; i < n; i++)
	{
		free(*(unit_pptr + i));
	}

	for (int i = 0; i < m; i++)
	{
		free(*(pptr + i));
	}

	return 0;
}

void swap(double* x, double* y)
{
	double mege;
	mege = *x;
	*x = *y;
	*y = mege;
}
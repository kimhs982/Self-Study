#include <stdio.h>
#include <stdlib.h>

void swap(double* x, double* y);

int main()
{
	double detcoef = 1;		// ERO ����� determinant ���� ��ȭ�� ����

	int m, n;
	printf("����� �����(�ļ�)�� �Է��ϼ��� : ");
	scanf_s("%d", &m);		// �����(m) �Է�
	printf("����� ������(������ ����)�� �Է��ϼ��� : ");
	scanf_s("%d", &n);		// ������(n) �Է�

	double* ptr;		// 1���� ������
	ptr = (double*)calloc(n, sizeof(double));		// leading variable�� 1�� ����, free variable�� 0�� ����

	if (ptr == NULL)		// �޸𸮸� �Ҵ����� ���� ��� �޽��� ��� �� ����
	{
		printf("# �޸𸮰� �����մϴ�. �ٽ� �������ּ���!\n");
		exit(1);
	}

	double** unit_pptr = calloc(n, sizeof(double*));		// ������� ������ ����

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

	printf("Augmented ����� �� ���� ������ �Է��Ͻÿ� : \n");
	for (int i = 0; i < m; i++)
	{
		printf("%d��:    ", i + 1);
		for (int j = 0; j < n + 1; j++)
		{
			scanf_s("%lf", &*(*(pptr + i) + j));
		}
		printf("\n");
	}

	printf("Augmented ��� : \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%.4lf   ", *(*(pptr + i) + j));
		}
		printf("\n");
	}


	// ÷������� �ϼ�
	// ���� ���콺�ҰŹ� �ϼ��ϱ�

	int col = 0;		// ���� ���ϴ� col����

	for (int row = 0; row < m; row++)		// 1����� m���� �ݺ��ؼ� ó��
	{
		for (;;)
		{
			int judge = 0;
			for (int i = row; i < m; i++)
			{
				if (*(*(pptr + i) + col) != 0)
				{
					judge++;		// 0�� �ƴ� �� judge�� ����
				}
			}

			if (judge == 0)		// ���� ���� ��� 0�̶��
			{
				col++;		// ���� �״�� ���� �ϳ��߰�
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
				index = i; // 0�� �ƴ� �� index�� ����
				break; // 0�� �ƴ� ������ �� ������ �� Ż��
			}
		}

		if (index != 0)
		{
			for (int j = col; j < n + 1; j++)// �౳ȯ
			{
				if (index != row)
				{
					swap(&*(*(pptr + row) + j), &*(*(pptr + index) + j));
				}
			}
			if (m == n)		// ������� �౳ȯ(����� ���)
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
				detcoef = (-detcoef);		// �౳ȯ(-det)
			}
		}

		// row���� ���� ��� ��� 1�� ����� (row�� ����)
		for (int i = row; i < m; i++)
		{
			double point_start = *(*(pptr + i) + col); // arr[i][0]�� ���� �ٲ�� ������ �����������
			for (int j = col; j < n + 1; j++) // ù��° �� arr[i][0]���� ������
			{
				if (*(*(pptr + i) + col) != 0) // ����� 0�� �ƴϸ�
				{
					*(*(pptr + i) + j) = *(*(pptr + i) + j) / point_start;
				}
			}
			if (m == n)		// ��������� ù��° �� arr[i][0]���� ������(����� ���)
			{
				for (int j = 0; j < n; j++)
				{
					if (*(*(pptr + i) + col) != 0) // ����� 0�� �ƴϸ�
					{
						*(*(unit_pptr + i) + j) = *(*(unit_pptr + i) + j) / point_start;
					}
				}
			}
			if (point_start != 0)
			{
				detcoef *= point_start;		// �࿡ �����(kdet)
			}
		}

		// �࿡�� ���� ���� �Լ��� ����� ��
		// leading 1 �����

		for (int i = row + 1; i < m; i++) // m = 1 ���� leading 1 �����
		{
			if (*(*(pptr + i) + col) != 0)// arr[i][0] �� 0�� �ƴ� ���� ����
			{
				for (int j = col; j < n + 1; j++)
				{
					*(*(pptr + i) + j) -= *(*(pptr + row) + j);
				}
				if (m == n)		// leading 1�� ���� �� ������Ŀ����� ���(����� ���)
				{
					for (int j = 0; j < n; j++)
					{
						*(*(unit_pptr + i) + j) -= *(*(unit_pptr + row) + j);
					}
				}
			}
		}

		col++;
		// ���⼭ col�� n�� �ѱ�� �ȵȴ�
		if (col >= n)
		{
			break;
		}
	}

	printf("\n\n-----���콺 �ҰŹ� �Ϸ�------\n");
	printf("Augmented ��� : \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%.4lf   ", *(*(pptr + i) + j));
		}
		printf("\n");
	}

	// ���콺 �ҰŹ� �Ϸ�
	// ���콺 ���� �ҰŹ� ����
	if ((m > 1) && (n > 1))		// ��� ���� 1���� Ŭ���� ���콺 ���� �ҰŹ� ����
	{
		int t = 0;
		for (int l1_row = m - 1; l1_row > 0; l1_row--)		// �� �Ʒ� ����� leading-1�� ��ġ�� ã�� �ݺ���
		{
			int l1_col = -1;
			for (int k = 0; k < n; k++)
			{
				if (*(*(pptr + l1_row) + k) != 0)		// Ư�� �࿡�� leading-1�� ���� ã�� ����
				{
					l1_col = k;
					break;
				}
			}
			if (l1_col == -1)		// �࿡ leading-1�� ���� ��� �� ������ �̵�
			{
				t++;
				continue;
			}
			else
			{
				for (int i = 0; i < m - 1 - t; i++)		// ���콺 ���� �ҰŹ��� �ϼ��ϱ� ���� ���� ����
				{
					double reduced_echelon = *(*(pptr + i) + l1_col);		// arr[i][j]���� �ٲ�� ������ �������־�� ��
					if (reduced_echelon != 0)
					{
						*(*(pptr + i) + l1_col) = 0;
						*(*(pptr + i) + n) -= reduced_echelon * (*(*(pptr + l1_row) + n));

						for (int j = l1_col + 1; j < n; j++)
						{
							*(*(pptr + i) + j) -= reduced_echelon * (*(*(pptr + l1_row) + j));
						}
						
						if (m == n)		// ������Ŀ� ���� �Լ��� ���콺 ���� �ҰŹ� ���� ����(����� ���)
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

	printf("\n\n-----���콺 ���� �ҰŹ� �Ϸ�------\n");
	printf("Augmented ��� : \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%.4lf   ", *(*(pptr + i) + j));
		}
		printf("\n");
	}
	// ���콺 ���� �ҰŹ� �Ϸ�
	// �� �Ǻ� ����

	int zero = 0;		// Ax = b���� b�� 0�������� Ȯ��
	for (int i = 0; i < m; i++)
	{
		if (*(*(pptr + i) + n) == 0)
		{
			zero++;
		}
	}

	int no_sol = 0;		// ����Ǵ� ���� �Ǵ�(Ax = b���� Ư�� ���� ���� ���� ��� 0������ b���� 0�� �ƴ� ���)
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

	if (m < n)		// ���� �ຸ�� ���� ���(������ ���� �� ���� or �ذ� �������� ����)
	{
		if (zero == m)		// Homogeneous(������ ���� �� ����)
		{
			printf("\n\n������ ���� �� ����\n\n");

			for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// �� �Ʒ� ����� leading-1�� ��ġ�� ã�� �ݺ���
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
				if (l1_col == -1)		// leading-1�� ���� ��� �� ������ �̵�
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
					int zero_sol = 0;		// Ư�� �࿡�� ���� ���� ���� 0�� ����
					for (int j = 0; j < n; j++)
					{
						if (*(*(pptr + count) + j) == 0)
						{
							zero_sol++;
						}
					}

					if (zero_sol == n - 1)		// Xn = c�ΰ��
					{
						printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
					}
					else  // leading variable�� ���� free variable ������ ǥ��
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
				else  // free variable ǥ��
				{
					printf("X%d = X%d\n\n", i + 1, i + 1);
				}
			}
		}
		else  // Non-Homogeneous(������ ���� �� ���� or �ذ� �������� ����)
		{
			if (no_sol > 0)
			{
				printf("\n\n�ذ� �������� ����\n\n");
			}
			else
			{
				printf("\n\n������ ���� �� ����\n\n");

				for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// �� �Ʒ� ����� leading-1�� ��ġ�� ã�� �ݺ���
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
					if (l1_col == -1)		// leading-1�� ���� ��� �� ������ �̵�
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
						int zero_sol = 0;		// Ư�� �࿡�� ���� ���� ���� 0�� ����
						for (int j = 0; j < n; j++)
						{
							if (*(*(pptr + count) + j) == 0)
							{
								zero_sol++;
							}
						}
						if (zero_sol == n - 1)		// Xn = c�϶��� ǥ��
						{
							printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
						}
						else  // leading variable�� ���� free variable ������ ǥ��
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
	else  // ���� ������ ���ų� ���� ��(������ ����, ������ ���� �� ����, �ذ� �������� ����)
	{
		int unit_mat = 0;
		for (int i = 0; i < n; i++)
		{
			if (*(*(pptr + i) + i) != 0)
			{
				unit_mat++;
			}
		}

		if (zero == m)		// Homogeneous(������ ����, ������ ���� �� ����)
		{
			if (unit_mat == n)
			{
				printf("\n\n������ ����\n\n");
				for (int i = 1; i <= n; i++)
				{
					printf("X%d = 0\n\n", i);
				}
			}
			else
			{
				printf("\n\n������ ���� �� ����\n\n");

				for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// �� �Ʒ� ����� leading-1�� ��ġ�� ã�� �ݺ���
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
					if (l1_col == -1)		// leading-1�� ���� ��� �� ������ �̵�
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
						int zero_sol = 0;		// Ư�� �࿡�� ���� ���� ���� 0�� ����
						for (int j = 0; j < n; j++)
						{
							if (*(*(pptr + count) + j) == 0)
							{
								zero_sol++;
							}
						}

						if (zero_sol == n - 1)		// Xn = c�϶��� ǥ��
						{
							printf("X%d = %.4lf", i + 1, *(*(pptr + count) + n));
						}
						else  // leading variable�� ���� free variable ������ ǥ��
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
		else  // Non-Homogeneous(������ ����, ������ ���� �� ����, �ذ� �������� ����)
		{
			if (no_sol > 0)
			{
				printf("\n\n�ذ� �������� ����\n\n");
			}
			else
			{
				if (unit_mat == n)
				{
					printf("\n\n������ ����\n\n");
					for (int i = 0; i < n; i++)
					{
						printf("X%d = %.4lf\n\n", i + 1, *(*(pptr + i) + n));
					}
				}
				else
				{
					printf("\n\n������ ���� �� ����\n\n");

					for (int l1_row = m - 1; l1_row >= 0; l1_row--)		// �� �Ʒ� ����� leading-1�� ��ġ�� ã�� �ݺ���
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
						if (l1_col == -1)		// leading-1�� ���� ��� �� ������ �̵�
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
							int zero_sol = 0;		// Ư�� �࿡�� ���� ���� ���� 0�� ����
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
							else  // leading variable�� ���� free variable ������ ǥ��
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

	if (m == n)		// Determinant�� ����� ���
	{
		int unit_det;
		double determinant;

		int unit_mat = 0;		// �������(I)���� Ȯ��
		for (int i = 0; i < n; i++)
		{
			if (*(*(pptr + i) + i) != 0)
			{
				unit_mat++;
			}
		}

		if (unit_mat == n)		// �������(I)�� �� determinant=1
		{
			unit_det = 1;
		}
		else  // �������(I)�� �ƴ� �� determinant=0
		{
			unit_det = 0;
		}

		if (unit_det == 0)
		{
			printf("Determinant : 0\n");
			printf("����� ��� �Ұ�!\n");
		}
		else
		{
			determinant = detcoef * unit_det;
			printf("Determinant : %.4lf\n", determinant);
			printf("\n����� ��� ����!\n");

			// �����
			printf("\n����� : \n");
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
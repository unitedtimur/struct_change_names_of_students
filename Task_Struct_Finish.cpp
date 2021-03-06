/*
*
*Created by UnitedTimur
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

struct Student {

	char secondname[30] = {};

	int marks[3] = { 0 };

};

int main(void) {

	FILE * student;
	
	FILE * output;

	student = fopen("student.txt", "rt");
	
	output = fopen("output.txt", "wt");


	if (student == NULL || output == NULL) {
		
		cout << "ERROR #1. Try again ;(" << endl;
	
		exit(0);
	
	}

	unsigned int amount = 0;
	
	unsigned int marks = 0;
	
	cout << "How many students? Student =  ";
	
	cin >> amount;

	Student *person = new Student[amount];

	unsigned int Size = 0;
	
	unsigned int j = 0;
	
	char ch;

	fscanf(student, "%c", &ch);
	
	float All = 0;


	while (!feof(student)) {

		while (ch >= 65 && ch <= 122) {
			
			person[j].secondname[Size] = ch;
			
			Size++;
		
			fscanf(student, "%c", &ch);
		
		}

		for (int i = 0; i < 3; i++) {
			
			fscanf(student, "%d", &person[j].marks[i]);
		
			All += person[j].marks[i];
		
		}

		fscanf(student, "%c", &ch);

		if ((All / 3.0) > 4) {
			
			for (int i = 0; i < Size; i++) {
				
				person[j].secondname[i] -= 32;
			
			}
		
		}

		for (int i = 0; i < Size; i++) {

			fprintf(output, "%c", person[j].secondname[i]);

		}

		for (int i = 0; i < 3; i++) {

			fprintf(output, " %d", person[j].marks[i]);
		
		}
		
		fprintf(output, "\n");

		Size = 0;
		
		All = 0;

		fscanf(student, "%c", &ch);
		
		j++;
	
	}

	delete[] person;
	
	fclose(student);
	
	fclose(output);

	cout << "Operating time of the program = " << clock() / 1000 << " sec" << endl;
	
	system("pause");
}
/*В файле, содержащем фамилии студентов и их оценки,
изменить на прописные буквы фамилии тех студентов,
которые имеют средний балл за национальной
шкалой более «4».*/

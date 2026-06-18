#include <stdio.h>

int inputQuiz(){
	int quiz;
	printf("Enter the quiz score(0-100):");
	scanf("%d", &quiz);
	return quiz;	
	
}

int inputExam(){
	int exam;
	printf("Enter the exam score(0-100):");
	scanf("%d", &exam);
	return exam;	
}

int calculate(int quiz, int exam){
	int score = (quiz*0.4) + (exam*0.4);
	return score;
}

char getLetter(int score){
	char A, B, C, D, F;
	if (score>=90){
		return A;
	} if(score>=80){
		return B;
		}
			if (score>=70){
				return C;
			}
			if (score>=60){
				return D;
			} else{
				return F;
			}
			
		}
	
	


void display(int quiz, int exam, int final, int letter){
printf("========= GRADE REPORT =========\n");
printf("Quiz Score: %d\n", &quiz);
printf("Exam Score: %d\n", &exam);
printf("Final Grade: %d\n", &final);
printf("Letter Grade: %d\n", &letter);
printf("================================");
}


int main(){
	int input;
	int quiz = inputQuiz();
	int exam = inputExam();
	int final = calculate(quiz,exam);
	char letter = getLetter();
	
	display(quiz, exam, final, letter);
	return 0;
}


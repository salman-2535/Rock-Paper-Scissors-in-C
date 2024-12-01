#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int selection = 0, cpu = 0, yourScore = 0, cpuScore = 0, ext = 0;

void blue(char*);
void green(char*);
void red(char*);
void yellow(char*);
void game();
void menu();
void score(int, int);
void yourSelect();
void show_selection();
void show_res();
void cal_score();
void goodbye();

/*********** MAIN *************/

int main(void) {  
  game();
  score(yourScore, cpuScore);
  menu();
  yourSelect();
  while (1) {
		if (ext == 1)
			break;
    show_selection();
    show_res();
    yourSelect();
  }   
}

void blue(char*str) {
  char s[100] = "\x1B[36m";
  strcat(s, str);
  strcat(s, "\033[0m");
  printf("%s", s);
}

void green(char*str) {
  char s[100] = "\x1B[92m";
  strcat(s, str);
  strcat(s, "\033[0m");
  printf("%s", s);
}

void red(char*str) {
  char s[100] = "\x1B[91m";
  strcat(s, str);
  strcat(s, "\033[0m");
  printf("%s", s);
}

void yellow(char*str) {
  char s[100] = "\x1B[93m";
  strcat(s, str);
  strcat(s, "\033[0m");
  printf("%s", s);
}

void game() {
	system("clear");
  puts("\x1B[32m **************** GAME **************** \033[0m");
  printf("\x1B[33m           Rock Paper Scissors\033[0m\n");
  printf("\x1B[34m========================================\033[0m\n");
  puts("You are playing with CPU for ever!\n");
}

void score(int a, int b) {
  char s1[2];
  char s2[2];
  sprintf(s1, "%d", a);
  sprintf(s2, "%d", b);
  printf("%s", "Your score: "); green(s1);
  printf("%s", "\t\tCPU's score: "); green(s2);
  puts("\n");
}

void menu() {
  printf("%s", "Select '1' for "); blue("Rock\n");
  printf("%s", "Select '2' for "); blue("Paper\n");
  printf("%s", "Select '3' for "); blue("Scissors\n\n");
}

void yourSelect() {
  char s[3];
  while (1) {
    printf("%s", "\n\nYour selection(e -> exit): ");
    scanf("%s", s);
    if (s[0] == 'e') {
			ext = 1;
			goodbye();
			break;
    }
		else if (s[0] == '1' || s[0] == '2' || s[0] == '3') {
      char a[] = {s[0], '\0'};
      int n = atoi(a);
      selection = n;
      srand(time(NULL));
	    cpu = 1 + rand() % 3;
	    cal_score();
      system("clear");
      game();
      score(yourScore, cpuScore);
      menu();      
      break;
    }
    else {
      system("clear");
      game();
      score(yourScore, cpuScore);
      menu();
      red("Wrong selection!!\n");
      printf("%s", "Your selection was: ");
      char ss[] = {'\'', s[0], '\'','\n', '\0'};
      yellow(ss);
    }
  }
}

void show_selection() {
	printf("%s", "You: ");
	if (selection == 1) 
	  blue("Rock");
	else if (selection == 2)
    blue("Paper");
  else
		blue("Scissors");	
	printf("%s", "\t\tCPU: ");
	if (cpu == 1) 
	  blue("Rock");
	else if (cpu == 2)
    blue("Paper");
  else
		blue("Scissors");
}

void show_res() {
	if (selection == cpu)
	  yellow("\n\n\tThe game is tied.");
	else if (selection == 1) {
		if (cpu == 2)
		  yellow("\n\n\tYou lost the game.");
		else 
		  yellow("\n\n\tYou won the game.");
	}
	else if (selection == 2) {
		if (cpu == 3)
		  yellow("\n\n\tYou lost the game.");
		else 
		  yellow("\n\n\tYou won the game.");
	}
	else {
		if (cpu == 1)
		  yellow("\n\n\tYou lost the game.");
		else 
		  yellow("\n\n\tYou won the game.");
	}
}

void cal_score() {
	if (selection == 1) {
		if (cpu == 2)
		  cpuScore++;
		else if (cpu == 3)
		  yourScore++;
	}
	else if (selection == 2) {
		if (cpu == 1)
		  yourScore++;
		else if (cpu == 3)
		  cpuScore++;
	}
	if (selection == 3) {
		if (cpu == 1)
		  cpuScore++;
		else if (cpu == 2)
		  yourScore++;
	}
}

void goodbye() {
	system("clear");
	puts("  ____                 _ _");
	puts(" / ___| ___   ___   __| | |__  _   _  ___");
	puts("| |  _ / _ \\ / _ \\ / _` | '_ \\| | | |/ _ \\");
	puts("| |_| | (_) | (_) | (_| | |_) | |_| |  __/");
	puts(" \\____|\\___/ \\___/ \\__,_|_.__/ \\__, |\\___|");
	puts("                               |___/");
	sleep(3);
	system("clear");
}

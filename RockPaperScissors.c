#include <stdio.h>
#include "RockPaperScissors.h"

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


#include "creatures/jumpingspider.h"

int main(){

	Jumpingspider jumpingspider;
	Creature goblin("goblin", 50, 8);

	jumpingspider.attack(goblin);
	jumpingspider.specialMove(goblin);
	
	return 0;
}

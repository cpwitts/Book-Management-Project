#include "UserMenu.h"

int main()
{
	//Get the instance of usermenu, and display the user select menu.
	UserMenu menu = UserMenu::getInstance();
	menu.displayUserSelectMenu();
}
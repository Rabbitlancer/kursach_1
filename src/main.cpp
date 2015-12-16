//kursach_1 - entry point
//by Rabbitlancer
#include <iostream>
#include <cstdlib>
#include <curses.h>
#include "headers/main.h"

using namespace std;

void finalize() {
	endwin();
}

int main(int argc, char *argv[]) {
	atexit(finalize);

	char choice;

choose:
	cout<<"Choose a renderer:"<<endl<<" (a) console output"<<endl<<" (b) Irrlicht software renderer"<<endl<<" (c) Irrlicht OpenGL renderer"<<endl;
	cout<<"Pick an option (a, b, c): ";
	cin>>choice;
	cout<<endl;
	if (choice!='a' && choice!='b' && choice!='c') {
		cout<<"Please enter a, b or c"<<endl;
		goto choose;
	}

	if (choice == 'a') {
		cout<<"Console rendering has been chosen"<<endl<<endl;
		k_renderer = CONSOLE;
	}
	if (choice == 'b') {
		cout<<"Irrlicht renderers are coming soon!"<<endl<<endl;
		goto choose;
	}
	if (choice == 'c') {
		cout<<"Irrlicht renderers are coming soon!"<<endl<<endl;
		goto choose;
	}

	if (init()) {
		return 1;
	}

	while (is_complete()) {
		loop();
		wait();
	}

	return 0;
}

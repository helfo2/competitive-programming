#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int main(void){
	char maze[150];

	while(gets(maze)){
		int n = 0;

		for(int i = 0; maze[i]; i++){
			if(isdigit(maze[i])){
				n += maze[i] - '0';
			} 
			else if(maze[i] == 'b'){
				for(int j = 0; j < n; j++){
					cout << ' ';
				}
				n = 0;
			}
			else if(maze[i] == '!'){
				cout << endl;
			}
			else {
				for(int j = 0; j < n; j++){
					cout << maze[i];
				}
				n = 0;
			}
		}

		cout << "\n";
	}
	
	return 0;
}
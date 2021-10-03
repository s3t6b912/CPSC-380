#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	pid_t pid;
	string input;
	int status;
	while (input != "quit" && input != "exit"){
		cout << "osh>";
		cin >> input;
		cout << "\n";
		if ((pid = fork()) < 0) {
         		cout << "Error forking process\n";
         		exit(1);
      		}else if ( pid == 0){
      			input.erase(remove(input.begin(), input.end(), '&'), input.end());
      			string temp = "/bin/" + input;
      			execlp(temp.c_str(), input.c_str(), NULL);
      			cout << "osh>";
		}else if (input.find('&') != std::string::npos){
			while (wait(&status) != pid){
			;
			}
		}
	}
}

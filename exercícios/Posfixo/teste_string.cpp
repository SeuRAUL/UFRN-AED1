#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string Nome;

	cout << "Nome: ";
	getline (cin, Nome);

	int i = 0;
	while (Nome[i] != '\0'){
		cout << Nome[i] << "\n";
		i++;
	}
	cout << "::\n\n";

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>

const char* GLOBAL_FILE_W = "AssolutamenteNonPassword.sndr";
const char* NAPOL = "Snadro Manager";

void ReadFile()
{
	std::fstream myfile;
	myfile.open(GLOBAL_FILE_W, std::ios::in);
	if (myfile.is_open())
	{
		std::string line;
		while (getline(myfile, line))
		{
			std::cout << line << std::endl;
		}
		myfile.close();
	}
}

void AppendToFile(std::string& text)
{
	std::fstream myfile;
	myfile.open(GLOBAL_FILE_W, std::ios::app);

	if (myfile.is_open())
	{
		myfile << text << std::endl;
		myfile.close();
	}
}

void Run(std::string& cmd)
{
	if (cmd == "test")
	{
		std::cout << "test fatto\nrisultati: gabbibboblu" << std::endl;
		return;
	}

	if (cmd == "help")
	{
		std::cout << "exit : exits the program" << std::endl
			<< "test : ;)" << std::endl
			<< "help : shows this text" << std::endl
			<< "add : adds login credentials" << std::endl
			<< "list : shows all login credentials" << std::endl;
		return;
	}

	if (cmd == "add")
	{
		std::string toadd;

		std::cout << NAPOL << "/add> ";
		std::cin >> toadd;

		AppendToFile(toadd);

		return;
	}

	if (cmd == "list")
	{
		ReadFile();
	}

	if (cmd == "exit")
	{
		std::cout << "Goodbye ;)" << std::endl;
		exit(0);
	}


}

int main()
{

	std::string cmd;

	while (1)
	{
		std::cout << NAPOL << "> ";
		std::cin >> cmd;
		Run(cmd);
	}

	return 0;
}

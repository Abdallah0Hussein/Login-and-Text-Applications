#include <bits/stdc++.h>
using namespace std;

void Merge(fstream &dataFile);
void count_Words(fstream &dataFile);
void count_Chars(fstream &dataFile);
void count_Lines(fstream &dataFile);
void search_Word(fstream &dataFile);

int main()
{
	fstream dataFile;
	char name[80];
	cout << "Pls input an existing file name: ";
	cin >> name;
	string file1 = name;
	if (file1.find(".txt") == -1)
	{
		file1 = strcat(name, ".txt");
	}
	dataFile.open(file1, ios::in | ios::app);
	if (dataFile.fail())
	{
		cout << "This File doesn't Exists.\n";
		cout << "This is a new file. I created it for you.\n";
		dataFile.open(file1, ios::out);
		cout << "Your file name is: " << file1 << '\n';
	}
	else
	{
		cout << "This File Already Exists.\n ";
	}
	cout << "Ahlan ya user ya habibi :D\n";
	cout << "Please select what you want or enter 16 to exit: \n";
	cout << "1- Add new text to the end of the file\n";
	cout << "2- Display the content of the file\n";
	cout << "3- Empty the file\n";
	cout << "4- Encrypt the file content\n";
	cout << "5- Decrypt the file content\n";
	cout << "6- Merge another file\n";
	cout << "7- Count the number of words in the file.\n";
	cout << "8- Count the number of characters in the file\n";
	cout << "9- Count the number of lines in the file\n";
	cout << "10- Search for a word in the file\n";
	cout << "11- Count the number of times a word exists in the file\n";
	cout << "12- Turn the file content to upper case\n";
	cout << "13- Turn the file content to lower case\n";
	cout << "14- Turn file content to 1st caps (1st char of each word is capital)\n";
	cout << "15- Save\n";
	cout << "16- Exit\n";
	// choose number one if you want Filter_InvertImage.
	int num_of_filter;
	cin.ignore(99999, '\n'); // Validate the input.
	cin.clear();
	string get_num;
	while (true)
	{
		getline(cin, get_num);
		if (get_num == "1" || get_num == "2" || get_num == "3" || get_num == "4" || get_num == "5" || get_num == "6" || get_num == "7" || get_num == "8" || get_num == "9" || get_num == "10" || get_num == "11" || get_num == "12" || get_num == "13" || get_num == "14" || get_num == "15" || get_num == "16")
		{
			num_of_filter = stoi(get_num);
			break;
		}
		else
		{
			cout << "INVALD\n";
		}
	}

	// if (num_of_filter == 1)
	// {

	// }
	// if (num_of_filter == 2)
	// {

	// }
	// if (num_of_filter == 3)
	// {

	// }
	// if (num_of_filter == 4)
	// {

	// }
	// if (num_of_filter == 5)
	// {

	// }
	if (num_of_filter == 6)
	{
		Merge(dataFile);
	}
	if (num_of_filter == 7)
	{
		count_Words(dataFile);
	}

	if (num_of_filter == 8)
	{
		count_Chars(dataFile);
	}
	if (num_of_filter == 9)
	{
		count_Lines(dataFile);
	}
	if (num_of_filter == 10)
	{
		search_Word(dataFile);
	}
	// if (num_of_filter == 11)
	// {

	// }
	// if (num_of_filter == 12)
	// {

	// }
	// if (num_of_filter == 13)
	// {

	// }
	// if (num_of_filter == 14)
	// {

	// }
	// if (num_of_filter == 15)
	// {

	// }
	if (num_of_filter == 16)
	{
		return 1;
	}
	return 0;

	dataFile.close();
}
void search_Word(fstream &dataFile)
{
	cout << "Enter the word: ";
	string search1;
	string new_str = "";
	cin >> search1;
	bool find = false;
	for (int i = 0; i < search1.length(); i++)
	{
		search1[i] = (char)tolower(search1[i]);
	}
	while (getline(dataFile, new_str))
	{
		for (int i = 0; i < new_str.length(); i++)
		{
			new_str[i] = (char)tolower(new_str[i]);
		}
		if (new_str.find(search1) != -1)
		{
			cout << "The Word was found in the file. :'D\n";
			find = true;
			break;
		}
	}
	if (!find)
		cout << "The word was not found in the file. :(\n";
}

void count_Lines(fstream &dataFile)
{
	string new_str = "";
	int tot_Lines = 0;
	int i = 0;
	while (dataFile.peek() != EOF)
	{
		new_str += dataFile.get();
	}
	while (new_str[i] != '\0')
	{
		if (new_str[i] == '\n')
			++tot_Lines;
		i++;
	}
	++tot_Lines;
	cout << "The number of lines in the file is: " << tot_Lines << '\n';
}
void count_Chars(fstream &dataFile)
{
	string new_str = "";
	int num = 0;
	string enter;
	int option;
	cout << "Choose what you want: \n";
	cout << "1- Count the number of characters without spaces.\n";
	cout << "2- Count the number of characters with spaces.\n";
	while (true)
	{
		getline(cin, enter);
		if (enter == "1" || enter == "2")
		{
			option = stoi(enter);
			break;
		}
		else
		{
			cout << "INVALD\n";
		}
	}
	if (option == 1)
	{
		while (getline(dataFile, new_str))
		{
			for (int i = 0; i < new_str.length(); i++)
			{
				if ((int)new_str[i] != 32)
					++num;
			}
		}
		cout << "The number of characters without spaces in the file is: " << num << '\n';
	}
	if (option == 2)
	{
		while (getline(dataFile, new_str))
		{
			for (int i = 0; i < new_str.length(); i++)
			{
				++num;
			}
		}
		cout << "The number of characters with spaces in the file is: " << num << '\n';
	}
}
void count_Words(fstream &dataFile)
{
	string new_str = "";
	int tot_Words = 0;
	int i = 0;
	while (dataFile.peek() != EOF)
	{
		new_str += dataFile.get();
	}
	while (new_str[i] != '\0')
	{
		if ((new_str[i] == ' ' && new_str[i + 1] != ' ' && new_str[i + 1] != '\n') || (new_str[i] == '\n' && new_str[i + 1] != '\n' && new_str[i + 1] != ' '))
		{
			++tot_Words;
		}
		++i;
	}
	cout << "The number of words in the file is: " << tot_Words << '\n';
}
void Merge(fstream &dataFile)
{
	fstream dataFile2;
	char name[80];
	string new_str = "";
	cout << "Pls input an existing file name: ";
	cin >> name;
	string file1 = name;
	int i = 0;
	if (file1.find(".txt") == -1)
	{
		file1 = strcat(name, ".txt");
	}
	dataFile2.open(file1);
	if (dataFile2.fail())
	{
		cout << "This File doesn't Exists.\n";
	}
	else
	{
		cout << "This File Already Exists.\n ";

		while (dataFile2.peek() != EOF)
		{
			new_str += dataFile2.get();
		}
		while (new_str[i] != '\0')
		{
			dataFile << new_str[i];
			++i;
		}
	}
	dataFile2.close();
}
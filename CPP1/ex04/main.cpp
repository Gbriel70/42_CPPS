/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:38 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:39 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int PrintError(string error)
{
	cerr << "Error: " << error << endl;
	return 1;
}

int SearchandReplace(const char *filename, string search, string replace)
{
	string new_file;
	string buffer;
	string line;
	ifstream file(filename);

	if (!file.is_open())
		return PrintError("could not open file");

	new_file = filename;
	ofstream outfile(new_file.append(".replace").c_str(), ios_base::out);
	if (!outfile.is_open())
		return PrintError("could not create file");

	while (getline(file, line))
	{
		for (size_t i = 0; i < line.length(); i++)
		{
			if (line.substr(i, search.length()) == search)
			{
				outfile << replace;
				i += search.length() - 1;
			}
			else
				outfile << line[i];
		}
		outfile << endl;
	}

	file.close();
	outfile.close();

	return 0;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		cout << "Usage: " << av[0] << " <file> <search> <replace>" << endl;
		return 1;
	}

	string search = av[2];
	string replace = av[3];

	if (search.empty())
	{
		cout << "Error: search string is empty" << endl;
		return 1;
	}

	return (SearchandReplace(av[1], search, replace));
}

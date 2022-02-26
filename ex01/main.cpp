/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:10:49 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 13:41:54 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ctype.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

bool all(std::string str, int (*is_thing)(int))
{
	for(int i = 0; i < str.length(); i++)
		if (!is_thing(str[i]))
			return (false);
	return (true);
}

int main() {
	PhoneBook phoneBook;
	std::string command;
	bool isEvenAttempt = true;

	std::cout	<< "# Welcome to your crappy awesome phonebook software!" << std::endl
				<< "# Here are your commands:" << std::endl << "#" << std::endl
				<< "# > ADD:" << std::setw(26) << std::right << "adds a new contact." << std::endl
				<< "# > SEARCH:" << std::setw(25) << std::right << "search for a contact." << std::endl
				<< "# > EXIT:" << std::setw(21) << std::right << "exit phonebook." << std::endl
				<< "#" << std::endl;

	while (true)
	{
		std::cout << "# > "; std::getline(std::cin, command);

		if (std::cin.eof())
			exit(1) ;

		std::cout << "#" << std::endl;
		if (command != "ADD" && command != "SEARCH" && command != "EXIT")
		{
			if (isEvenAttempt)
			{
				std::cout << "# Are you autistic or something?" << std::endl;
				isEvenAttempt = false;
			}
			else
			{
				std::cout << "# The f#ck is wrong with you?" << std::endl;
				isEvenAttempt = true;
			}
			std::cout	<< "# I SAID YOUR COMMANDS ARE: ADD; SEARCH; EXIT"
						<< std::endl << "#" << std::endl;
			continue ;
		}

		// ADD
		else if (command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNumber;
			std::string darkestSecret;

			// First name
			while (true)
			{
				std::cout << "# First name: "; std::getline(std::cin, firstName);

				if (std::cin.eof())
					exit(1) ;
				
				std::cout << "#" << std::endl;
				if (!all(firstName, isalpha))
				{
					std::cout	<< "# The first name can only consist of alphabetic characters."
								<< std::endl << "#" << std::endl;
					continue ;
				}
				else {
					// do class stuff here
					break ;
				}
			}

			// Last name
			while (true)
			{
				std::cout << "# Last name: "; std::getline(std::cin, lastName);

				if (std::cin.eof())
					exit(1) ;

				std::cout << "#" << std::endl;
				if (!all(lastName, isalpha))
				{
					std::cout	<< "# The last name can only consist of alphabetic characters."
								<< std::endl << "#" << std::endl;
					continue ;
				}
				else {
					// do class stuff here
					break ;
				}
			}
			
			// Nickname
			while (true)
			{
				std::cout << "# Nickname: "; std::getline(std::cin, nickName);

				if (std::cin.eof())
					exit(1) ;

				std::cout << "#" << std::endl;
				if (!all(nickName, isalpha))
				{
					std::cout	<< "# The nickname can only consist of alphabetic characters."
								<< std::endl << "#" << std::endl;
					continue ;
				}
				else {
					// do class stuff here
					break ;
				}
			}

			// Phone number
			while (true)
			{
				std::cout << "# Phone number: "; std::getline(std::cin, phoneNumber);

				if (std::cin.eof())
					exit(1) ;

				std::cout << "#" << std::endl;
				if (!all(phoneNumber, isdigit))
				{
					std::cout	<< "# The phone number can only consist of digits."
								<< std::endl << "#" << std::endl;
					continue ;
				}
				else {
					// do class stuff here
					break ;
				}
			}

			// Darkest secret
			while (true)
			{
				std::cout << "# Darkest secret: "; std::getline(std::cin, darkestSecret);

				if (std::cin.eof())
					exit(1) ;

				std::cout << "#" << std::endl;

				// do class stuff here
				break ;
			}

			// create contact
			Contact const contact(firstName, lastName, nickName, phoneNumber, darkestSecret);

			// add contact to PhoneBook.contacts[8]
			phoneBook.addContact(contact);
			
		}
		else if (command == "SEARCH")
		{
		}
		else if (command == "EXIT")
		{
		}
	}
}

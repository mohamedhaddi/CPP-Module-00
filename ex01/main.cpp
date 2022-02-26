/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:10:49 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 19:37:29 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ctype.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

#define RED     "\033[31m"
#define BOLDRED "\033[1m\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

bool all(std::string str, int (*is_thing)(int))
{
	if (!str.length())
		return (false);
	for (unsigned long i = 0; i < str.length(); i++)
		if (!is_thing(str[i]))
			return (false);
	return (true);
}

int main() {
	PhoneBook phoneBook;
	std::string command;
	bool isEvenAttempt = true;

	std::cout	<< "# Welcome to your crappy awesome phonebook software!" << std::endl
				<< "# Here are your commands (must be in all caps):" << std::endl << "#" << std::endl;

	while (true)
	{
		std::cout	<< "# > ADD:" << std::setw(26) << std::right
					<< "adds a new contact." << std::endl
					<< "# > SEARCH:" << std::setw(25) << std::right
					<< "search for a contact." << std::endl
					<< "# > EXIT:" << std::setw(21) << std::right
					<< "exit phonebook." << std::endl
					<< "#" << std::endl
					<< "# " << GREEN << "> "; std::getline(std::cin, command);
		std::cout << RESET;

		if (std::cin.eof())
			exit(1) ;

		std::cout << "#" << std::endl;
		if (command != "ADD" && command != "SEARCH" && command != "EXIT")
		{
			if (isEvenAttempt)
			{
				std::cout	<< "# " << BOLDRED
							<< "Are you autistic or something?"
							<< RESET << std::endl;
				isEvenAttempt = false;
			}
			else
			{
				std::cout	<< "# " << BOLDRED
							<< "# The f#ck is wrong with you?"
							<< RESET << std::endl;
				isEvenAttempt = true;
			}
			std::cout	<< "# " << RED
						<< "I SAID YOUR COMMANDS ARE: ADD; SEARCH; EXIT"
						<< RESET << std::endl << "#" << std::endl;
			continue ;
		}

		else if (command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNumber;
			std::string darkestSecret;

			while (true)
			{
				std::cout	<< "# " << GREEN << "First name: " << RESET;
				std::getline(std::cin, firstName);

				if (std::cin.eof())
					exit(1) ;
				
				if (!all(firstName, isalpha))
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "The first name can only consist of alphabetic characters."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else
					break ;
			}

			while (true)
			{
				std::cout	<< "# " << GREEN << "Last name: " << RESET;
				std::getline(std::cin, lastName);

				if (std::cin.eof())
					exit(1) ;

				if (!all(lastName, isalpha))
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "The last name can only consist of alphabetic characters."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else
					break ;
			}
			
			while (true)
			{
				std::cout	<< "# " << GREEN << "Nickname: " << RESET;
				std::getline(std::cin, nickName);

				if (std::cin.eof())
					exit(1) ;

				if (!all(nickName, isalpha))
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "The nickname can only consist of alphabetic characters."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else
					break ;
			}

			while (true)
			{
				std::cout	<< "# " << GREEN << "Phone number: " << RESET;
				std::getline(std::cin, phoneNumber);

				if (std::cin.eof())
					exit(1) ;

				if (!all(phoneNumber, isdigit))
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "The phone number can only consist of digits."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else
					break ;
			}

			while (true)
			{
				std::cout	<< "# " << GREEN << "Darkest secret: " << RESET;
				std::getline(std::cin, darkestSecret);

				if (std::cin.eof())
					exit(1) ;

				std::cout << "#" << std::endl;

				break ;
			}

			Contact const contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
			phoneBook.addContact(contact);
			
		}
		else if (command == "SEARCH")
		{
			std::cout	<< "# "
						<< CYAN
						<< "|" << std::setw(10) << "Index"
						<< "|" << std::setw(10) << "First Name"
						<< "|" << std::setw(10) << "Last Name"
						<< "|" << std::setw(10) << "Nickname"
						<< "|" << RESET << std::endl;

			for (int i = 0; i < phoneBook.getNumberOfContacts(); i++)
			{
				Contact currentContact = phoneBook.getContact(i);
				std::string currentFirstName = currentContact.getFirstName();
				std::string currentLastName = currentContact.getLastName();
				std::string currentNickName = currentContact.getNickName();

				std::cout	<< "# "
							<< CYAN
							<< "|" << std::setw(10) << i
							<< "|" << std::setw(9) << currentFirstName.substr(0, 8)
							<< (currentFirstName.length() > 10 ? "." : "")
							<< "|" << std::setw(9) << currentLastName.substr(0, 8)
							<< (currentLastName.length() > 10 ? "." : "")
							<< "|" << std::setw(9) << currentNickName.substr(0, 8)
							<< (currentNickName.length() > 10 ? "." : "")
							<< "|" << RESET << std::endl;
			}

			std::cout << "#" << std::endl;
		}
		else if (command == "EXIT")
		{
		}
	}
}

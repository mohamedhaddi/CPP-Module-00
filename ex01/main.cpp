/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:10:49 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/27 17:06:40 by mhaddi           ###   ########.fr       */
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
#define BOLDGREEN "\033[1m\033[32m"
#define CYAN    "\033[36m"
#define BOLDCYAN "\033[1m\033[36m"
#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

bool all(std::string str, int (*is_thing)(int))
{
	for (unsigned long i = 0; i < str.length(); i++)
		if (!is_thing(str[i]))
			return (false);
	return (true);
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	std::cout	<< "# Welcome to your crappy awesome phonebook software!" << std::endl
				<< "# Here are your commands (must be in all caps):" << std::endl
				<< "#" << std::endl;

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
			std::cout	<< "# " << BOLDRED << "You must enter one of the valid commands:"
						<< RESET << std::endl << "# " << RED
						<< "ADD, SEARCH, EXIT (make sure to use all caps)."
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
				
				if (firstName.empty())
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "You must enter a first name."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else if (!all(firstName, isalpha))
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

				if (lastName.empty())
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "You must enter a last name."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else if (!all(lastName, isalpha))
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

				if (nickName.empty())
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "You must enter a nickname."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else if (!all(nickName, isalpha))
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
				
				if (phoneNumber.empty())
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "You must enter a phone number."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else if (!all(phoneNumber, isdigit))
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

				if (darkestSecret.empty())
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "This field cannot be empty."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}

				std::cout << "#" << std::endl;

				break ;
			}

			Contact const contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
			phoneBook.addContact(contact);
			
		}
		else if (command == "SEARCH")
		{
			std::cout	<< "# "
						<< BOLDCYAN
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
							<< "|" << std::setw(10) << i << "|";

				if (currentFirstName.length() > 10)
					std::cout << std::setw(9) << currentFirstName.substr(0, 9) << ".|";
				else
					std::cout << std::setw(10) << currentFirstName << "|";

				if (currentLastName.length() > 10)
					std::cout << std::setw(9) << currentLastName.substr(0, 9) << ".|";
				else
					std::cout << std::setw(10) << currentLastName << "|";

				if (currentNickName.length() > 10)
					std::cout << std::setw(9) << currentNickName.substr(0, 9) << ".|";
				else
					std::cout << std::setw(10) << currentNickName << "|";

				std::cout << RESET << std::endl;
			}

			std::cout	<< "#" << std::endl;

			std::string contactIndex;

			while (true)
			{

				std::cout	<< "# " << GREEN << "Choose index: " << RESET;
				std::getline(std::cin, contactIndex);

				if (std::cin.eof())
					exit(1) ;

				if (contactIndex.empty())
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "This field cannot be empty."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else if (!all(contactIndex, isdigit))
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "The index can only consist of digits."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else if (std::stoi(contactIndex) >= phoneBook.getNumberOfContacts())
				{
					std::cout	<< "#" << std::endl
								<< "# " << BOLDRED
								<< "There is no contact with this index."
								<< RESET << std::endl
								<< "# " << RED << "Try again!" << RESET << std::endl
								<< "#" << std::endl;
					continue ;
				}
				else
					break ;
			}

			Contact currentContact = phoneBook.getContact(std::stoi(contactIndex));

			std::cout	<< "#" << std::endl
						<< "# " << "First name: "
						<< currentContact.getFirstName() << std::endl
						<< "# " << "Last name: "
						<< currentContact.getLastName() << std::endl
						<< "# " << "Nickname: "
						<< currentContact.getNickName() << std::endl
						<< "# " << "Phone number: "
						<< currentContact.getPhoneNumber() << std::endl
						<< "# " << "Darkest secret: "
						<< currentContact.getDarkestSecret() << std::endl
						<< "#" << std::endl;
		}
		else if (command == "EXIT")
		{
			std::cout	<< "# 👋" << std::endl
						<< "# " << BOLDGREEN << "Goodbye!" << RESET << std::endl
						<< "#" << std::endl;
			break ;
		}
	}
}

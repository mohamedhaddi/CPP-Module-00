/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:10:49 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/28 12:14:42 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void printWelcomeMessage(void)
{
	std::cout	<< "# Welcome to your crappy awesome phonebook software!" << std::endl
				<< "# Here are your commands (must be in all caps):" << std::endl;
}

void printCommandOptions(void)
{
	std::cout	<< "#" << std::endl
				<< "# > ADD:" << std::setw(26) << std::right
				<< "adds a new contact." << std::endl
				<< "# > SEARCH:" << std::setw(25) << std::right
				<< "search for a contact." << std::endl
				<< "# > EXIT:" << std::setw(21) << std::right
				<< "exit phonebook." << std::endl
				<< "#" << std::endl;
}

std::string	getCommand()
{
	std::string command;

	std::cout << "# " << GREEN << "> ";
	std::getline(std::cin, command);
	std::cout << RESET;
	std::cout << "#" << std::endl;

	if (std::cin.eof())
		exit(1) ;

	return (command);
}

std::string getInput(std::string what)
{
	std::string input;

	std::cout	<< "# " << GREEN << what << ": " << RESET;
	std::getline(std::cin, input);

	if (std::cin.eof())
		exit(1) ;

	return (input);
}

bool isValidName(std::string whatName, std::string name)
{
	if (name.empty())
	{
		std::cout	<< "#" << std::endl
					<< "# " << BOLDRED
					<< "You must enter a " << whatName << "."
					<< RESET << std::endl
					<< "# " << RED << "Try again!" << RESET << std::endl
					<< "#" << std::endl;
		return (false);
	}
	else if (!all(name, isalpha))
	{
		std::cout	<< "#" << std::endl
					<< "# " << BOLDRED
					<< "The " << whatName << " can only contain alphabetic characters."
					<< RESET << std::endl
					<< "# " << RED << "Try again!" << RESET << std::endl
					<< "#" << std::endl;
		return (false);
	}
	return (true);
}

bool isValidNumber(std::string whatNumber, std::string number)
{
	if (number.empty())
	{
		std::cout	<< "#" << std::endl
					<< "# " << BOLDRED
					<< "You must enter a " << whatNumber << "."
					<< RESET << std::endl
					<< "# " << RED << "Try again!" << RESET << std::endl
					<< "#" << std::endl;
		return (false);
	}
	else if (!all(number, isdigit))
	{
		std::cout	<< "#" << std::endl
					<< "# " << BOLDRED
					<< "The " << whatNumber << " can only contain digits."
					<< RESET << std::endl
					<< "# " << RED << "Try again!" << RESET << std::endl
					<< "#" << std::endl;
		return (false);
	}
	return (true);
}

bool isEmpty(std::string input)
{
	if (input.empty())
	{
		std::cout	<< "#" << std::endl
					<< "# " << BOLDRED
					<< "This field cannot be empty."
					<< RESET << std::endl
					<< "# " << RED << "Try again!" << RESET << std::endl
					<< "#" << std::endl;
		return (true);
	}
	return (false);
}

Contact const createContact()
{
	std::string firstName;
	while (true)
	{
		firstName = getInput("First name");
		if (isValidName("first name", firstName))
			break ;
	}

	std::string lastName;
	while (true)
	{
		lastName = getInput("Last name");
		if (isValidName("first name", lastName))
			break ;
	}

	std::string nickName;
	while (true)
	{
		nickName = getInput("Nickname");
		if (isValidName("nickname", nickName))
			break ;
	}

	std::string phoneNumber;
	while (true)
	{
		phoneNumber = getInput("Phone number");
		if (isValidNumber("phone number", phoneNumber))
			break ;
	}

	std::string darkestSecret;
	while (true)
	{
		darkestSecret = getInput("Darkest secret");
		if (!isEmpty(darkestSecret))
			break ;
	}

	Contact const contact(firstName, lastName, nickName, phoneNumber, darkestSecret);

	return (contact);
}

bool isValidCommand(std::string command)
{
	if (command == "ADD")
		return (true);
	else if (command == "SEARCH")
		return (true);
	else if (command == "EXIT")
		return (true);
	else
	{
		std::cout	<< "# " << BOLDRED << "You must enter one of the valid commands:"
					<< RESET << std::endl << "# " << RED
					<< "ADD, SEARCH, EXIT (make sure to use all caps)."
					<< RESET << std::endl;
		return (false);
	}
}

void printContactRow(int index, Contact const & contact)
{
	std::string firstName = contact.getFirstName();
	std::string lastName = contact.getLastName();
	std::string nickName = contact.getNickName();

	std::cout	<< "# "
				<< CYAN
				<< "|" << std::setw(10) << index << "|";

	if (firstName.length() > 10)
		std::cout << std::setw(9) << firstName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << firstName << "|";

	if (lastName.length() > 10)
		std::cout << std::setw(9) << lastName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << lastName << "|";

	if (nickName.length() > 10)
		std::cout << std::setw(9) << nickName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << nickName << "|";

	std::cout << RESET << std::endl;
}

void printAllContacts(PhoneBook const & phoneBook)
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
		printContactRow(i, currentContact);
	}

	std::cout << "#" << std::endl;
}

bool contactIndexInRange(PhoneBook const & phoneBook, int const index)
{
	if (index < 0 || index >= phoneBook.getNumberOfContacts())
	{
		std::cout	<< "#" << std::endl
					<< "# " << BOLDRED
					<< "The index must be between 0 and "
					<< phoneBook.getNumberOfContacts() - 1
					<< "."
					<< RESET << std::endl
					<< "# " << RED << "Try again!" << RESET << std::endl
					<< "#" << std::endl;
		return (false);
	}
	return (true);
}

void printContactFields(Contact const & contact)
{
	std::cout	<< "#" << std::endl
				<< "# " << BOLDCYAN << "First name: " << RESET
				<< contact.getFirstName() << std::endl
				<< "# " << BOLDCYAN << "Last name: " << RESET
				<< contact.getLastName() << std::endl
				<< "# " << BOLDCYAN << "Nickname: " << RESET
				<< contact.getNickName() << std::endl
				<< "# " << BOLDCYAN << "Phone number: " << RESET
				<< contact.getPhoneNumber() << std::endl
				<< "# " << CYAN << "Darkest secret: " << RESET
				<< contact.getDarkestSecret() << std::endl;
}

int inquireContactIndex(PhoneBook const & phoneBook)
{
	std::string index;

	while (true)
	{
		index = getInput("Choose index [0-"
				+ std::to_string(phoneBook.getNumberOfContacts() - 1) + "]");
		if (!isEmpty(index)
				&& isValidNumber("index", index)
				&& contactIndexInRange(phoneBook, std::stoi(index)))
			break ;
	}

	return (std::stoi(index));
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	printWelcomeMessage();

	while (true)
	{
		printCommandOptions();
		command = getCommand();

		if (!isValidCommand(command))
			continue ;
		else if (command == "ADD")
			phoneBook.addContact(createContact());
		else if (command == "SEARCH")
		{
			if (phoneBook.getNumberOfContacts() > 0)
			{
				printAllContacts(phoneBook);
				int const index = inquireContactIndex(phoneBook);
				Contact const contact = phoneBook.getContact(index);
				printContactFields(contact);
			}
			else
				std::cout	<< "# " << BOLDCYAN
							<< "There are no contacts in the phonebook."
							<< RESET << std::endl;
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

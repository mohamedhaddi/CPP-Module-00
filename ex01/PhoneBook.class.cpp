/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:59:27 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/27 23:52:50 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void): _nextIndex(0), _numberOfContacts(0)
{
	return ;
}

void	PhoneBook::addContact(Contact const contact)
{
	if (this->_nextIndex >= MAX_CONTACTS)
		this->_nextIndex = 0;
	this->_contacts[this->_nextIndex] = contact;
	this->_nextIndex += 1;
	this->_numberOfContacts += 1;
	if (this->_numberOfContacts >= MAX_CONTACTS)
		this->_numberOfContacts = MAX_CONTACTS;
	return ;
}

Contact PhoneBook::getContact(int const index) const
{
	if (index >= MAX_CONTACTS)
		return Contact("", "", "", "", "");
	else
		return this->_contacts[index];
}

int		PhoneBook::getNumberOfContacts(void) const
{
	return this->_numberOfContacts;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

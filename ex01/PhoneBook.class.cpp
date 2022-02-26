/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:59:27 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 13:51:32 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void): _oldestContactIndex(0), _nextIndex(0) {
	return ;
}

void	PhoneBook::addContact(Contact const contact) {
	if (this->_nextIndex > 7)
		this->_nextIndex = 0;
	this->_contacts[this->_nextIndex] = contact;
	this->_nextIndex += 1;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

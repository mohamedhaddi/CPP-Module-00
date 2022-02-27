/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:05:42 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 18:29:09 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void): _firstName(""),
						_lastName(""),
						_nickName(""),
						_phoneNumber(""),
						_darkestSecret("")
{
	return ;
}

Contact::Contact(
					std::string const firstName,
					std::string const lastName,
					std::string const nickName,
					std::string const phoneNumber,
					std::string const darkestSecret
				):
					_firstName(firstName),
					_lastName(lastName),
					_nickName(nickName),
					_phoneNumber(phoneNumber),
					_darkestSecret(darkestSecret)
{
	return ;
}

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

std::string Contact::getNickName(void) const {
	return this->_nickName;
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

Contact::~Contact(void) {
	return ;
}

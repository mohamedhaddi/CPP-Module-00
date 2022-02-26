/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:05:42 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 17:07:04 by mhaddi           ###   ########.fr       */
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

Contact::~Contact(void) {
	return ;
}

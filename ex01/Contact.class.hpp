/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:03:41 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 13:33:55 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

	public:

		Contact(
					std::string const firstName,
					std::string const lastName,
					std::string const nickName,
					std::string const phoneNumber,
					std::string const darkestSecret
				);
		~Contact(void);

	private:

		std::string _firstName;
		std::string _lastName;		
		std::string _nickName;		
		std::string _phoneNumber;		
		std::string _darkestSecret;		

};

#endif

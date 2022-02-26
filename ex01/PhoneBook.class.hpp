/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:57:59 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 13:51:28 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook {

	public:

		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(Contact const contact);

	private:

		Contact _contacts[8] = {
			Contact(NULL, NULL, NULL, NULL, NULL),
			Contact(NULL, NULL, NULL, NULL, NULL),
			Contact(NULL, NULL, NULL, NULL, NULL),
			Contact(NULL, NULL, NULL, NULL, NULL),
			Contact(NULL, NULL, NULL, NULL, NULL),
			Contact(NULL, NULL, NULL, NULL, NULL),
			Contact(NULL, NULL, NULL, NULL, NULL),
			Contact(NULL, NULL, NULL, NULL, NULL)
		};
		int		_oldestContactIndex;
		int		_nextIndex;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 08:57:59 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/26 16:51:53 by mhaddi           ###   ########.fr       */
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
		Contact	getContact(int const index) const;
		int		getNumberOfContacts(void) const;

	private:

		Contact _contacts[8];
		int		_oldestContactIndex;
		int		_nextIndex;
};

#endif

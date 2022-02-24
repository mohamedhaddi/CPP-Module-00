/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:31:11 by mhaddi            #+#    #+#             */
/*   Updated: 2022/02/24 18:52:51 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char **argv)
{
	std::string message;

	for (int i = 1; i < argc; i++)
		for (size_t j = 0; j < strlen(argv[i]); j++)	
			message += toupper(argv[i][j]);

	if (message.empty())
		message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << message << std::endl;

	return (0);
}


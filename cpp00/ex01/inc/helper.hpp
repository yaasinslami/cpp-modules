/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 23:22:46 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 12:45:11 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <iostream>

std::string get_input(const std::string& prompt);
std::string trim(const std::string& str);
bool		is_printable(const std::string& str);
void		printwelcome(void);

#endif

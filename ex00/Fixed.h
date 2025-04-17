/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:16:48 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/17 13:40:44 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed&);
    Fixed& operator=(const Fixed&);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
}; 
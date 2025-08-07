/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:36:55 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/23 15:20:10 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed&);
    Fixed(const int);
    Fixed(const float);
    Fixed& operator=(const Fixed&);
    void operator<<(const Fixed&);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
}; 
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
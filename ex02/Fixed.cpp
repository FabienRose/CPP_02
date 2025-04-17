/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:45:48 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/17 14:47:23 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed(void)
{
    this->value = 0;
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}

Fixed::Fixed(const int value)
{
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = other.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return value >> fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& comp) const {
    return this->value > comp.value;
}

bool Fixed::operator<(const Fixed& comp) const {
    return this->value < comp.value;
}

bool Fixed::operator>=(const Fixed& comp) const {
    return this->value >= comp.value;
}

bool Fixed::operator<=(const Fixed& comp) const {
    return this->value <= comp.value;
}

bool Fixed::operator==(const Fixed& comp) const {
    return this->value == comp.value;
}

bool Fixed::operator!=(const Fixed& comp) const {
    return this->value != comp.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->value + rhs.value);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->value - rhs.value);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    long long temp = static_cast<long long>(this->value) * static_cast<long long>(rhs.value);
    result.setRawBits(static_cast<int>(temp >> fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs.value == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    long long temp = static_cast<long long>(this->value) << fractionalBits;
    result.setRawBits(static_cast<int>(temp / rhs.value));
    return result;
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}
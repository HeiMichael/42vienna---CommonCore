/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:41:15 by miheider          #+#    #+#             */
/*   Updated: 2024/08/23 14:20:33 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;

std::string CurrentTimestamp() {
    char buffer[20];
    std::time_t now = std::time(0); 
    std::tm *parts = std::localtime(&now); // Convert to local time structure
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", parts);
    return std::string(buffer);
}

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void	Account::makeDeposit( int deposit ) {
    std::cout << CurrentTimestamp() << " index:" << _accountIndex << ";" << "p_amount:" << _amount
            << ";" << "deposit:" << deposit << ";" << "amount:" << (_amount + deposit)
            << ";" << "nb_deposits:" << (_nbDeposits + 1) << std::endl;
    _amount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    std::cout << CurrentTimestamp() << " index:" << _accountIndex << ";" << "p_amount:" << _amount << ";";
    if (withdrawal < _amount) {
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ";" << "amount:" << _amount << ";"
                << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else { 
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
}

int		Account::checkAmount( void ) const {
    return _amount;
}

Account::Account(int initialDeposit) {
    _accountIndex = _nbAccounts;
    _amount = initialDeposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts += 1;
    _totalAmount += initialDeposit;
    std::cout << CurrentTimestamp() << " index:" << _accountIndex << ";" << "amount:"
            << _amount << ";" << "created" << std::endl;
}

Account::~Account() {
    std::cout << CurrentTimestamp() << " index:" << _accountIndex << ";" << "amount:" << _amount
            << ";" << "closed" << std::endl;
}

void Account::displayAccountsInfos( void ) {
    std::cout << CurrentTimestamp() << " accounts:" << _nbAccounts 
            << ";" << "total:" << _totalAmount << ";" << "deposits:" << _totalNbDeposits 
            << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus( void ) const {
    std::cout << CurrentTimestamp() << " index:" << _accountIndex << ";" << "amount:"
            << _amount << ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:"
            << _nbWithdrawals << std::endl;
}

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
    std::time_t t = std::time(NULL);
    struct tm* timeinfo = localtime(&t);
    std::cout << "[";
    std::cout << (timeinfo->tm_year + 1900);
    std::cout << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1);
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_sec;
    std::cout << "]";
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts()
                << ";total:" << Account::getTotalAmount()
                << ";deposits:" << Account::getNbDeposits()
                << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;
    std::cout << " index:" 
    << this->_accountIndex 
    << this->_amount 
    << this->_nbDeposits 
    << this->_nbWithdrawals 
    << ";created" 
    << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << " index:" 
    << this->_accountIndex 
    << ";amount:" 
    << this->_amount 
    << ";deposits:" 
    << this->_nbDeposits 
    << ";withdrawals:" 
    << this->_nbWithdrawals 
    << ";closed" 
    << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    this->_nbDeposits++;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << " index:"
    << this->_accountIndex
    << ";p_amount:"
    << this->_amount - deposit
    << ";deposit:"
    << deposit
    << ";amount:"
    << this->_amount
    << ";nb_deposits:"
    << this->_nbDeposits
    << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    if (this->_amount < withdrawal)
    {
        std::cout << " index:"
        << this->_accountIndex
        << ";p_amount:"
        << this->_amount
        << ";withdrawal:"
        << "refused"
        << std::endl;
        return false;
    }
    this->_nbWithdrawals++;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    std::cout << " index:"
    << this->_accountIndex
    << ";p_amount:"
    << this->_amount + withdrawal
    << ";withdrawal:"
    << withdrawal
    << ";amount:"
    << this->_amount
    << ";nb_withdrawals:"
    << this->_nbWithdrawals
    << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:"
    << this->_accountIndex
    << ";amount:"
    << this->_amount
    << ";deposits:"
    << this->_nbDeposits
    << ";withdrawals:"
    << this->_nbWithdrawals
    << std::endl;
}

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
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;

    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    int p_amount = _amount;
    _nbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << " index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    if (_amount < withdrawal) {
        std::cout << " index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return false;
    }

    int p_amount = _amount;
    _nbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << " index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

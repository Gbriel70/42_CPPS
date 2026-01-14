/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:37:34 by gcosta-m          #+#    #+#             */
/*   Updated: 2026/01/14 10:37:35 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv) {

   if (argc < 2) {
      std::cerr << "Usage: ./PmergeMe [positive integers]" << std::endl;
      return (1);
   }   

   try {
      PmergeMe pmerge;
      pmerge.processArgs(argv);
      pmerge.displayElapsedTime();
      pmerge.displaySorting();
   } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return (2);
   }

   return 0;
}
#pragma once

#include "ticket.h"
#include "connections.h"
#include "purchases.h"

int check_size(std::vector<connections>& vec, int& user);
void chech_if_tickets_was_booked2(const std::string& file, const std::string& file2, purchases& p1, std::vector<connections>& vec);
//void chech_if_tickets_was_booked2(const std::string& file, const std::string& file2, purchases& p1);
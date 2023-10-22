#include "functions.h"



int check_size(std::vector<connections>& vec, int& user) {
    while (user >= vec.size()) {
        std::cout << "Bad input, try again:";
        std::cin >> user;
    }
    return user;

}


void chech_if_tickets_was_booked2(const std::string& file, const std::string& file2, purchases& p1, std::vector<connections>& vec) {
    std::ifstream inputFile(file);
    std::ifstream inputFile2(file2);

    if (!inputFile.is_open() or !inputFile2.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return;
    }

    std::string line1, line2;
    while (std::getline(inputFile, line1) and std::getline(inputFile2, line2)) {
        std::stringstream ss1(line1);
        std::stringstream ss2(line2);
        std::string temporary1, temporary2;

        ticket t;

        if (std::getline(ss1, temporary1, ',')) {
            t.set_id(temporary1);
        }
        if (std::getline(ss1, temporary1, ',')) {
            t.set_category(temporary1);
        }
        if (std::getline(ss1, temporary1, ',')) {
            t.set_price(std::stod(temporary1));
        }
        if (std::getline(ss1, temporary1, ',')) {
            t.set_seat2(std::stoi(temporary1));
        }
        if (std::getline(ss1, temporary1, ',')) {
            t.set_data_user(temporary1);
        }


        std::string destination, departure, day;
        int hours, minutes;
        while (ss2 >> departure >> destination >> day >> hours >> minutes) {
            vec.push_back(connections(destination, departure, day, hours, minutes));
            t.add_connection(vec.back());
        }

        p1.add_purchase(t);
    }

    inputFile2.close();
    inputFile.close();
}


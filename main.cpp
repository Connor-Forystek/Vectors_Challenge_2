//Connor Forystek
//September 8, 2025
//Purpose: To create a dynamic grade analysis with std::vector
//Assignment: Lab Activities: Arrays & Vectors

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
int displayMenu() {
    std::cout << "Option 1: Add a Grade" << std::endl;
    std::cout << "Option 2: Display All Grades" << std::endl;
    std::cout << "Option 3: Calculate Average Grade" << std::endl;
    std::cout << "Option 4: Find Highest and Lowest Grade" << std::endl;
    std::cout << "Option 5: Count Grades Above Threshold" << std::endl;
    std::cout << "Option 6: Quit" << std::endl;

    int choice;
    std::cin >> choice;
        while (choice == 0) {
            std::cout << "That is an invalid input. Clearing your input" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std:: cout <<"Invalid choice" << std::endl;
            std:: cout <<"Enter another choice between 1 and 6" << std::endl;
            std::cout << "Option 1: Add a Grade" << std::endl;
            std::cout << "Option 2: Display All Grades" << std::endl;
            std::cout << "Option 3: Calculate Average Grade" << std::endl;
            std::cout << "Option 4: Find Highest and Lowest Grade" << std::endl;
            std::cout << "Option 5: Count Grades Above Threshold" << std::endl;
            std::cout << "Option 6: Quit" << std::endl;
            std::cin >> choice;
        }
    return choice;
}

void startMenu() {
    std::vector<double> grades;
    int input;
    int gradeInput = -1;
    double hGrade;
    double lGrade;
    double threshold;
    double avg = 0;
    int i;
    int total = 0;
    bool hasData = false;

    do {
        input = displayMenu();
        switch (input) {
            case 1:
                std::cout << "Enter a grade" << std::endl;
                std::cin >> gradeInput;
                do {
                    std::cout << "That is an invalid input. Clearing your input" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std:: cout <<"Invalid Grade" << std::endl;
                    std:: cout <<"Enter a grade" << std::endl;
                    std::cin >> gradeInput;
                } while (gradeInput < 0 || gradeInput > 100 );
                grades.push_back(gradeInput);
                hasData = true;
                break;
            case 2:
                if (hasData == false) {
                    std::cout << "Please Enter A Grade First" << std::endl;
                    break;
                }
                std::cout << "All of your grades" << std::endl;
                for (i = 0; i < grades.size(); ++i) {
                    std::cout << grades.at(i) << std::endl;
                }
                break;
            case 3:
                if (hasData == false) {
                    std::cout << "Please Enter A Grade First" << std::endl;
                    break;
                }
                for (i = 0; i < grades.size(); ++i) {
                    avg += grades.at(i);
                }
                avg /= grades.size();
                std::cout << "The average of your grades are " << avg << std::endl;
                break;
            case 4:
                if (hasData == false) {
                    std::cout << "Please Enter A Grade First" << std::endl;
                    break;
                }
                hGrade = grades.at(0);
                for (i = 0; i < grades.size(); ++i) {
                    if (grades.at(i) > hGrade) {
                        hGrade = grades.at(i);
                    }
                }
                std::cout << "Your highest grade is " << hGrade << std::endl;
                lGrade = grades.at(0);
                for (i = 0; i < grades.size(); ++i) {
                    if (grades.at(i) < lGrade) {
                        lGrade = grades.at(i);
                    }
                }
                std::cout << "Your lowest grade is " << lGrade << std::endl;
                break;
            case 5:
                if (hasData == false) {
                    std::cout << "Please Enter A Grade First" << std::endl;
                    break;
                }
                std::cout <<"Choose a threshold" << std::endl;
                std::cin >> threshold;
                for (i = 0; i < grades.size(); ++i) {
                    if (grades.at(i) > threshold) {
                        ++total;
                    }
                }
                std::cout << "There are " << total << " grades above the threshold" << std::endl;
                break;
            case 6:
                std::cout << "Exiting the Program." << std::endl;
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "That is an invalid choice. Please choose 1-6" << std::endl;
                break;
        }

    } while(input != 6);
}
int main() {
    //This section calls the function startMenu to allow the user to select an option
    startMenu();
    return 0;
}
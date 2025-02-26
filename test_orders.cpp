#include <iostream>
#include "main.cpp" // Include the implementation file or use a header file if you have one

void runTests() {
    // Test case 1: New Order Insertion
    maintain_book(Action::NEW, "order1", "", Side::BUY, 10, 100);
    maintain_book(Action::NEW, "order2", "", Side::SELL, 5, 120);

    // Print the order book after new order insertion
    std::cout << "After New Order Insertion:" << std::endl;
    std::cout << "Buy Book: " << std::endl;
    for (auto &pair : buy_book) {
        std::cout << "Price: " << pair.first << ", Size: " << pair.second << std::endl;
    }

    std::cout << "Sell Book: " << std::endl;
    for (auto &pair : sell_book) {
        std::cout << "Price: " << pair.first << ", Size: " << pair.second << std::endl;
    }

    // Test case 2: Trade Orders
    maintain_book(Action::TRADE, "order1", "order2", Side::BUY, 100, 50);

    std::cout << "After Trade Orders:" << std::endl;
    std::cout << "Buy Book: " << std::endl;
    for (auto &pair : buy_book) {
        std::cout << "Price: " << pair.first << ", Size: " << pair.second << std::endl;
    }

    std::cout << "Sell Book: " << std::endl;
    for (auto &pair : sell_book) {
        std::cout << "Price: " << pair.first << ", Size: " << pair.second << std::endl;
    }

    // Test case 3: Cancel Orders
    maintain_book(Action::CANCEL, "order1", "", Side::BUY, 50, 60);

    std::cout << "After Cancel Orders:" << std::endl;
    std::cout << "Buy Book: " << std::endl;
    for (auto &pair : buy_book) {
        std::cout << "Price: " << pair.first << ", Size: " << pair.second << std::endl;
    }
}


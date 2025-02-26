#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

enum Side {
    BUY,
    SELL,
};

enum Action {
    NEW,
    MODIFY,
    TRADE,
    CANCEL
};

struct OrderDetails {
    int price = 0;
    int size = 0;
    Side side;
};

std::unordered_map<std::string, OrderDetails> orders;
std::unordered_map<int, int> buy_book; // Fixed: Removed std::greater<int>
std::unordered_map<int, int> sell_book;

auto isOrderPresent(string name) {
    return orders.find(name) != orders.end();
};

void book_insert(int price, int size, Side side) {
    if (side == Side::BUY) {
        buy_book[price] += size;
    } else {
        sell_book[price] += size;
    }
}

void book_pop(int price, int size, Side side) {
    if (side == Side::BUY) {
        buy_book[price] -= size;
        if (buy_book[price] == 0)
            buy_book.erase(price);
    } else {
        sell_book[price] -= size;
        if (sell_book[price] == 0)
            sell_book.erase(price);
    }
}

void order_insert(string orderId, int price, int size, Side side) {
    OrderDetails orderDetails;
    orderDetails.price = price;
    orderDetails.size = size;
    orderDetails.side = side;

    orders[orderId] = orderDetails;
    book_insert(price, size, side);
}

void order_pop(string orderId_1, string orderId_2, int size) {
    if (isOrderPresent(orderId_1)) {
        book_pop(orders[orderId_1].price, size, orders[orderId_1].side);
        orders[orderId_1].size -= size;
        if (orders[orderId_1].size == 0)
            orders.erase(orderId_1);
    }

    if (isOrderPresent(orderId_2)) {
        book_pop(orders[orderId_2].price, size, orders[orderId_2].side);
        orders[orderId_2].size -= size;
        if (orders[orderId_2].size == 0)
            orders.erase(orderId_2);
    }
}

void maintain_book(Action action, string orderId, string orderId_2, Side side, int size, int price) {
    switch (action) {
        case (Action::NEW):
            order_insert(orderId, price, size, side);
            break;
        case (Action::MODIFY):
            book_pop(orders[orderId].price, orders[orderId].size, orders[orderId].side);
            order_insert(orderId, price, size, side);
            break;
        case (Action::TRADE):
            order_pop(orderId, orderId_2, size);
            break;
        case (Action::CANCEL):
            if (isOrderPresent(orderId)) {
                book_pop(orders[orderId].price, size, side);
                orders[orderId].size -= size;
                if (orders[orderId].size == 0)
                    orders.erase(orderId);
            }
            break;
    }
}

#ifndef RUN_TESTS
int main() {
    maintain_book(Action::NEW, "order1", "", Side::BUY, 10, 100);
    maintain_book(Action::NEW, "order2", "", Side::SELL, 5, 120);
    maintain_book(Action::TRADE, "order1", "order2", Side::BUY, 50, 10);

    cout << "Buy Book: " << endl;
    for (auto &pair : buy_book) {
        cout << "Price: " << pair.first << ", Size: " << pair.second << endl;
    }

    cout << "Sell Book: " << endl;
    for (auto &pair : sell_book) {
        cout << "Price: " << pair.first << ", Size: " << pair.second << endl;
    }

    cout << "Orders: " << endl;
    for (auto &pair : orders) {
        cout << "Order ID: " << pair.first << ", Price: " << pair.second.price
             << ", Size: " << pair.second.size << ", Side: " << (pair.second.side == Side::BUY ? "BUY" : "SELL") << endl;
    }

    return 0;
}
#endif

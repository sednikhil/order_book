# Order Book Management System

The **Order Book Management System** is a simple implementation of an order book in C++. It supports creating, modifying, trading, and canceling orders for a financial trading platform. The system manages two books: a **Buy Book** and a **Sell Book**, sorted by price levels.

---

## Features

- **Order Management**:
  - Add new orders to the order book.
  - Modify existing orders with updated price and size.
  - Execute trades between buy and sell orders.
  - Cancel orders from the order book.

- **Books Management**:
  - Maintain a Buy Book (sorted in descending order of price).
  - Maintain a Sell Book (sorted in ascending order of price).

---

## Technology Stack

- **Language**: C++ (requires support for C++11 or later)
- **Compiler**: GCC or any compatible C++ compiler
- **Operating System**: Works on Linux, macOS, and Windows

---

## Installation and Setup

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/order-book-management.git
   cd order-book-management


## How to Run
### Compile and Run the Main Program
To compile the main implementation:
```bash
g++ -o order_book main.cpp
g++ -o test test_orders.cpp
./test
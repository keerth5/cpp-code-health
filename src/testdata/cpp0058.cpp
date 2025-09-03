#include <iostream>
#include <string>
#include <sqlite3.h>  // Using SQLite for demonstration

// BAD: SQL injection via string concatenation (violation)
void bad_example(sqlite3* db, const std::string& user_input) {
    std::string query = "SELECT * FROM users WHERE name='" + user_input + "';";
    std::cout << "BAD example: executing query = " << query << std::endl;

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::cout << "User found: " << sqlite3_column_text(stmt, 0) << std::endl;
        }
        sqlite3_finalize(stmt);
    }
}

// GOOD: Use prepared statements to prevent SQL injection
void good_example(sqlite3* db, const std::string& user_input) {
    const char* query = "SELECT * FROM users WHERE name = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement" << std::endl;
        return;
    }

    // Bind user input safely
    sqlite3_bind_text(stmt, 1, user_input.c_str(), -1, SQLITE_STATIC);

    std::cout << "GOOD example: executing prepared statement" << std::endl;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "User found: " << sqlite3_column_text(stmt, 0) << std::endl;
    }
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3* db;
    sqlite3_open(":memory:", &db);

    // Sample user inputs
    std::string unsafe_input = "'; DROP TABLE users;--";
    std::string safe_input = "Alice";

    bad_example(db, unsafe_input);  // Vulnerable
    good_example(db, unsafe_input); // Safe
    good_example(db, safe_input);   // Safe

    sqlite3_close(db);
    return 0;
}

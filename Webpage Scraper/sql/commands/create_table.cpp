#include "commands.h"

#include <iostream>

#include "../sqlite3.h"

void swc::cmds::create_table()
{
    sqlite3* DB;
    std::string sql = "CREATE TABLE Webpages("
        "ID TEXT PRIMARY KEY    NOT NULL, "
        "Title           TEXT    NOT NULL, "
        "URL          TEXT     NOT NULL);";
    int exit = 0;
    exit = sqlite3_open("Webpages.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Creating Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    sqlite3_close(DB);
}
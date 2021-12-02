#include "commands.h"
#include "../sqlite3.h"
#include <iostream>

void swc::cmds::truncate()
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("Webpages.db", &DB);

    std::string sql("DELETE FROM Webpages;");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Deleting" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records Deleted Successfully!" << std::endl;
    sqlite3_close(DB);
}
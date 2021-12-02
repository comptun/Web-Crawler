#include "commands.h"
#include "../sqlite3.h"
#include <iostream>

void swc::cmds::insert(std::string param1, std::string param2)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("Webpages.db", &DB);

    std::string sql("INSERT INTO Webpages VALUES('" + swc::cmds::randstr(10) + "', '" + param1 + "','" + param2 + "');");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Inserting" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
    sqlite3_close(DB);
}
#include "student.h"
#include "database.h"
#include "input.h"
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool valid_id(int id) {
    if (id <= 0) {
        return false;
    }

    return true;
}

bool valid_name(const char* name) {
    if (strlen(name) < 3) {
        return false;
    }

    return true;
}

bool valid_date(const char* date) {
    regex_t regex;
    int regexResponse;

    const char* pattern = "^[0-9]{4}-[0-9]{2}-[0-9]{2}$";

    regexResponse = regcomp(&regex, pattern, REG_EXTENDED);
    if (regexResponse != 0) {
        printf("Regex compilation failed.\n");
        return false;
    }

    regexResponse = regexec(&regex, date, 0, NULL, 0);
    regfree(&regex);

    if (regexResponse == 0) {
        return true;
    } else if (regexResponse == REG_NOMATCH) {
        printf("Pattern not found.\n");
    } else {
        printf("Regex execution error.\n");
    }
    return false;
}

bool valid_address(const char* name) {
    if (strlen(name) < 8) {
        return false;
    }

    return true;
}

bool valid_department(const char* name) {
    if (strlen(name) < 5) {
        return false;
    }

    return true;
}

void add_student() {
    struct Student s;
    s.id = fetch_last_id() + 1;
    get_user_input_str("Enter first name", s.first_name, sizeof(s.first_name), *valid_name);
    get_user_input_str("Enter last name", s.last_name, sizeof(s.last_name), *valid_name);
    get_user_input_str("Enter date of birth (YYYY-MM-DD)", s.date_of_birth, sizeof(s.date_of_birth),
                       *valid_date);
    get_user_input_str("Enter address", s.address, sizeof(s.address), *valid_address);
    get_user_input_str("Enter department", s.department, sizeof(s.department), *valid_address);

    store_student(&s);
}

#include "database.h"
#include "input.h"

void add_student() {
    struct Student s;
    s.id = getUserInputInt("Enter id");
    getUserInputStr("Enter first name", s.first_name, sizeof(s.first_name));
    getUserInputStr("Enter last name", s.last_name, sizeof(s.last_name));
    getUserInputStr("Enter date of birth (YYYY-MM-DD)", s.date_of_birth, sizeof(s.date_of_birth));
    getUserInputStr("Enter address", s.address, sizeof(s.address));
    getUserInputStr("Enter department", s.department, sizeof(s.department));

    store_student(&s);
}

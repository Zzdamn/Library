#ifndef TEACHER_H
#define TEACHER_H
#include "Student.h"

class Teacher : public Student {
public:
    Teacher();
    void initTeacher(const std::string& id, const std::string& name, const std::string& dep);

    bool borrowBook(Book* book) override;
    bool returnBook(Book* book) override;
};

#endif
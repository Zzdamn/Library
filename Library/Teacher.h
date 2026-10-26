#ifndef TEACHER_H
#define TEACHER_H
#include "Student.h"

// 教师类：公有继承学生基类，重写借阅/归还逻辑，实现用户身份差异化
class Teacher : public Student {
public:
    Teacher();
    void initTeacher(const std::string& id, const std::string& name, const std::string& dep);

    bool borrowBook(Book* book) override;
    bool returnBook(Book* book) override;
};

#endif
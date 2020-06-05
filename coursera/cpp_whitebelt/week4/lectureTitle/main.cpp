#include <iostream>
#include <string>
#include <utility>

struct Specialization {
  std::string specialization;
  explicit Specialization(std::string s) {
    this->specialization = std::move(s);
  }
};

struct Course {
  std::string course;
  explicit Course(std::string c) {
    this->course = std::move(c);
  }
};

struct Week {
  std::string week;
  explicit Week(std::string w) {
    this->week = std::move(w);
  }
};

struct LectureTitle {
  std::string specialization;
  std::string course;
  std::string week;
  LectureTitle(const Specialization &s, const Course &c, const Week &w) : course{c.course},
                                                                          specialization{s.specialization},
                                                                          week{w.week} {}
};

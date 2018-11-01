#include <iostream>
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#include "college.h"

using namespace std;

// Declaring test function so I can pass different "students" later on
College test(string filename);

// Creating Those Students from the given text files
College test1 = test("Wes.txt");
College test2 = test("Wes1.txt");
College test3 = test("Wes2.txt");


// Following Test cases
TEST(gpaTest, test1){
  ASSERT_EQ(4, test1.gpa());
}

TEST(gpaTest, test2){
  ASSERT_EQ(3.4, test2.gpa());
}

TEST(gpaTest, test3){
  ASSERT_EQ(0, test3.gpa());
}


// Calling the gTest
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// the function test just creates the student/college course from
// given text files
College test(string filename){
  ifstream fin;
  string username = "Wes";
  string fullname = "Test";

	College mycollege(fullname);
  fin.open(filename.c_str());
  if(!fin.fail())
    mycollege.load(fin);
    fin.close();
  return mycollege;
}

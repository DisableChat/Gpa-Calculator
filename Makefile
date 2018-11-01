all: build

build: test.o college.o course.o
	g++ -o test test.o college.o course.o -lgtest -lgtest_main -pthread

test.o: collegemain.cc course.h node.h college.h
	g++ -c test.cc

college.o: college.cc college.h
	g++ -c college.cc

course.o: course.cc course.h
	g++ -c course.cc

clean:
	rm  test *.o

CC := gcc
CFLAGS := -std=c11 -ggdb #-Wall -Werror -Wextra
C_LIBS := -lm
TST_LIBS := -lcheck -lm -lpthread
#-pthread -lcheck_pic -pthread -lrt -lm -lsubunit

DATE_TIME := $(shell sh -c "date '+%F %T'")
PWD := $(shell pwd)
NICKNAME := $(shell pwd | awk 'BEGIN {FS="/";} { print $$3}')
SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJECTS := $(wildcard *.o)
LIBS := $(wildcard *.a)
OS := $(shell uname -s)

ifeq ($(OS),Linux)
	CFLAGS+=-D LINUX
	TST_LIBS+= -lcheck_pic -lrt -lsubunit
else
	ifeq ($(OS),Darwin)
		CFLAGS+=-D MAC
	else
		CFLAGS+=-D LINUX
		TST_LIBS+= -lcheck_pic -lrt -lsubunit
	endif
endif

all: build

rebuild: clean build

build: test s21_string.a

test:  test.o s21_string.a
	$(CC) $(CFLAGS) test.o s21_string.a $(TST_LIBS) -o test
	./test

test_sprintf: s21_string.a test_printf.c
	$(CC) $(CFLAGS) test_printf.c s21_string.a $(C_LIBS) -o s21_sprintf

test.o: tests/test.c
	$(CC) $(CFLAGS) -c tests/test.c -o test.o

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

s21_sprintf.o: s21_sprintf.c
	$(CC) $(CFLAGS) -c s21_sprintf.c -ggdb -o s21_sprintf.o

s21_sscanf.o: s21_sscanf.c
	$(CC) $(CFLAGS) -c s21_sscanf.c -o s21_sscanf.o

s21_string.a: s21_string.o s21_sprintf.o s21_sscanf.o
	ar rc s21_string.a s21_string.o s21_sscanf.o s21_sprintf.o
	ranlib s21_string.a

gcov_test: tests/test.c s21_string.a
	$(CC) $(CFLAGS) --coverage tests/test.c s21_sprintf.c s21_sscanf.c s21_string.c s21_string.a $(TST_LIBS) -o gcov_test

gcov_test.gcda: gcov_test
	chmod +x *
	./gcov_test

gcov_test.info: gcov_test gcov_test.gcda
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .

gcov_report: clean gcov_test.info
	genhtml -o report/ gcov_test.info
	open report/index.html

report_open: gcov_report
	open report/index.html

clean: clean_o clean_build clean_test

clean_o:
ifdef OBJECTS
	rm *.o
endif

clean_build:
ifdef LIBS
	rm *.a
	rm -rf s21_sprintf
endif

clean_test:
	@rm -rf report/ gcov_test exe *.gcda *.gcno *.info test test CPPLINT.cfg
	@echo "\nclean DONE)\n"

lint: lint_launch clean

lint_launch:
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../materials/linters/cpplint.py --extensions=c *.h *.c tests/*

lint_clean:
	@rm CPPLINT.cfg

check: clean
	@cppcheck *.c *.h tests/

leaks: test
	CK_FORK=no leaks --atExit -- ./test
	@make clean

git: clean
ifdef SOURCES
	git add ${SOURCES}
endif
ifdef HEADERS
	git add ${HEADERS}
endif
	git add Makefile
	git commit -m "${NICKNAME} '${m}' commit at $(DATE_TIME)"
	git push origin ${NICKNAME}

merge: git
	git merge origin/develop

valgrind:
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test

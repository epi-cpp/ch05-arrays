TST =$(TGT).t
DEBUG =-g
GTEST =../../googletest/googletest
CXXFLAGS =-Wall -std=c++11 -I. $(DEBUG)
TESTLIBS =-lgtest -lpthread
OBJS =$(patsubst %.cc,.obj/%.o,$(wildcard *.cc))
CXX=clang++
LD=clang++

$(TGT): $(OBJS)

test/$(TST): $(TGT).o test/.obj/$(TST).o

main.o: main.cc $(TGT).h

.obj/$(TGT).o: $(TGT).cc $(TGT).h

test/.obj/$(TST).o: test/$(TST).cc $(TGT).o

clean:
	$(RM) .obj/*.o *~ $(TGT) test/.obj/*.o $(TST)

test: test/$(TST)
	test/$(TST)

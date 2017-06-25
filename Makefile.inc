TST =$(TGT).t
DEBUG =-g
GTEST =../../googletest/googletest
CXXFLAGS =-Wall -std=c++11 -I. -I$(GTEST)/include $(DEBUG)
TESTLIBS =-L$(GTEST) -lgtest -lpthread
OBJS =$(patsubst %.cc,.obj/%.o,$(wildcard *.cc))
CXX=clang++

$(TGT): $(OBJS)
	$(LINK.cc) $^ $(LOADLIBS) $(LDLIBS) -o $@

test/$(TST): $(TGT).o test/.obj/$(TST).o
	$(LINK.cc) $^ $(LOADLIBS) $(TESTLIBS) -o $@

main.o: main.cc $(TGT).h

$(TGT).o: $(TGT).cc $(TGT).h

$(TST).o: $(TST).cc .obj/$(TGT).o

clean:
	rm -f .obj/*.o *~ $(TGT) test/.obj/*.o $(TST)

test: test/$(TST)
	test/$(TST)

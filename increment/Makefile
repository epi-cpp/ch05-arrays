CXX=clang++-3.5
TGT =increment
TST =$(TGT).t
DEBUG =-g
GTEST =../../googletest/
CXXFLAGS =-Wall -std=c++11 -I. -I$(GTEST)/include $(DEBUG)
TESTLIBS =-L$(GTEST) -lgtest -lpthread
OBJS =$(patsubst %.cc,.obj/%.o,$(wildcard *.cc))

$(TGT): $(OBJS)
	$(LINK.cc) $^ $(LOADLIBS) $(LDLIBS) -o $@

test/$(TST): $(TGT).o test/.obj/$(TST).o
	$(LINK.cc) $^ $(LOADLIBS) $(TESTLIBS) -o $@

.obj:
	mkdir -p .obj test/.obj

.obj/%.o: %.cc .obj
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

test/.obj/%.o: test/%.cc
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

main.o: main.cc asm6502.h

$(TGT).o: $(TGT).cc $(TGT).h

$(TST).o: $(TST).cc .obj/$(TGT).o

clean:
	rm -f .obj/*.o *~ $(TGT) test/.obj/*.o $(TST)

test: test/$(TST)
	test/$(TST)

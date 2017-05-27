
BIN = out

SRC = $(wildcard src/*.cc)
OBJS = $(SRC:%.cc=%.o)
DEPS = $(SRC:%.cc=%.d)

CPPFLAGS += -MMD -MP
CXXFLAGS += -std=c++17 -lstdc++fs

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.phony: all test auto

auto:
	./make-periodically.sh test

test: $(BIN)
	./test.sh

-include $(DEPS)

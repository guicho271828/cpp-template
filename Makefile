
BIN = out

SRC = $(wildcard src/*.cpp)
OBJS = $(SRC:%.cpp=%.o)
DEPS = $(SRC:%.cpp=%.d)

CPPFLAGS += -MMD -MP -Ilib/cereal/include -Ilib/backward-cpp
CXXFLAGS += -std=c++17 -lstdc++fs

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.phony: all test auto

auto:
	./make-periodically.sh test

test: $(BIN)
	./test.sh

-include $(DEPS)

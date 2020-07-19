CXX = g++
CXXFLAGS = -g -Wall
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

LIBS =

BUILDIR = build

DEPDIR := $(BUILDIR)/dep
OBJDIR = $(BUILDIR)/obj
# INCDIR := include
SRCDIR = .

TARGET = TestMath

# DIRS = input main math
# SRCDIRS = $(foreach dir,$(DIRS), $(addprefix $(SRCDIR)/,$(dir)))
# SRCS = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))

MLIBDIR = $(SRCDIR)/userInput
MSRCDIR = $(SRCDIR)/Maths
MMAINDIR = $(SRCDIR)/TestMaths

_SRCS := main.cpp complex.cpp checkType.cpp getInput.cpp
SRCS := $(foreach dir,$(_SRCS),$(addprefix $(SRCDIR)/,$(dir)))

OBJS = $(_SRCS:%.cpp=$(OBJDIR)/%.o)

INCLUDES = -I$(MLIBDIR) -I$(MSRCDIR)

DEPFILES := $(_SRCS:%.cpp=$(DEPDIR)/%.d)
COMPILECXX = $(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


$(OBJDIR)/%.o : $(MMAINDIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR) $(OBJDIR)
	$(COMPILECXX) $< -o $(OBJDIR)/$*.o

$(OBJDIR)/%.o : $(MSRCDIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR) $(OBJDIR)
	$(COMPILECXX) $< -o $(OBJDIR)/$*.o

$(OBJDIR)/%.o : $(MLIBDIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR) $(OBJDIR)
	$(COMPILECXX) $< -o $(OBJDIR)/$*.o

$(OBJDIR): ; @mkdir -p $@
$(DEPDIR): ; @mkdir -p $@

$(DEPFILES):
include $(wildcard $(DEPFILES))

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

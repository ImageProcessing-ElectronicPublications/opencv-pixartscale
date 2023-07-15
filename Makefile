PROJECT = opencv-pixartscale
CXX = g++
OCV = opencv4
CXXFLAGS = -Wall `pkg-config --cflags $(OCV)`
LDFLAGS = `pkg-config --libs $(OCV)` -s
OBJS =  src/buildingsimilaritygraph.o src/cells.o src/cellsreconstruct.o src/combine.o src/curvessearching.o src/depixelizing.o src/heuristics.o src/visualization.o src/main.o

all: $(PROJECT)

$(PROJECT): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(PROJECT)
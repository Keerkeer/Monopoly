CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = main.o compplayer.o gameboard.o humanplayer.o player.o acabuilding.o buyable.o coopfee.o dctimsline.o goosenesting.o gotims.o gym.o needleshall.o notbuyable.o osap.o property.o residence.o slc.o tuition.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

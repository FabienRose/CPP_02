

#--------------------------------------------------
#                  ENVIRONMENT
#--------------------------------------------------

#----- CPP language compiler -----
CPL=c++
CPL_FLAGS=-std=c++98 -Wall -Wextra -Werror

#----- Program informations -----
PNAME=rawbits

#----- RM Command -----
RM_FLAGS=-f


#--------------------------------------------------
#              SOURCES AND OBJECTS
#--------------------------------------------------

#----- Sources -----
SRCS=	./Fixed.cpp \
		./main.cpp

#----- Objects -----
OBJS=$(SRCS:.cpp=.o)


#--------------------------------------------------
#              DEPENDENCIES (LIBS)
#--------------------------------------------------

#----- Common -----
DEPS_LIST=
DEPS_CALLS=


#--------------------------------------------------
#                COMPILING RULES
#--------------------------------------------------

#----- Main Rules -----
all: $(PNAME)

$(PNAME): $(DEPS_LIST) $(OBJS)
	$(CPL) $(CPL_FLAGS) $(DEPS_LIST) $(OBJS) $(DEPS_CALLS) -o $@


%.o: %.cpp
	$(CPL) $(CPL_FLAGS) -I./ -c $< -o $@

#----- Libs Rules -----


#--------------------------------------------------
#                CLEANING RULES
#--------------------------------------------------
clean:
	rm $(RM_FLAGS) $(OBJS)

fclean: clean
	rm $(RM_FLAGS) $(PNAME)


#--------------------------------------------------
#                EXTRA RULES
#--------------------------------------------------
re: fclean all

.phony: all clean fclean re

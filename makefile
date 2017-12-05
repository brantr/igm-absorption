
EXEC   = igm-absorption

CC       =  gcc
OPTIMIZE =  -O2 -Wall -g        # sets optimization and warning flags


GSL_INCL  =  -I/home/brant/code/gsl/include
GSL_LIBS  =  -L/home/brant/code/gsl/lib -lgsl -lgslcblas

OPTIONS =  $(OPTIMIZE) $(OPT)


OBJS   = main.o igm-absorption.o

INCL   = igm-absorption.h

CFLAGS = $(OPTIONS) $(GSL_INCL)

LIBS   =  -lm $(GSL_LIBS) 

$(EXEC): $(OBJS) 
	$(CC) $(OBJS) $(LIBS)   -o  $(EXEC)  

$(OBJS): $(INCL) 


clean:
	rm -f $(OBJS) $(EXEC)

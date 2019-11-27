
objects = main.o Net.o Mythread.o timer.o ReadConfig.o Queue.o

main:$(objects)
	arm-linux-gnueabihf-gcc  -o main $(objects) -lpthread

main.o:main.c Net.h Mythread.h timer.h ReadConfig.h Queue.h
	arm-linux-gnueabihf-gcc -g -c main.c -o main.o
	
Net.o: Net.c Net.h
	arm-linux-gnueabihf-gcc -g -c Net.c -o Net.o
timer.o: timer.c timer.h ReadConfig.h
	arm-linux-gnueabihf-gcc -g -c timer.c -o timer.o
ReadConfig.o:ReadConfig.c ReadConfig.h 
	arm-linux-gnueabihf-gcc -g -c ReadConfig.c -o ReadConfig.o
Mythread.o:Mythread.c Mythread.h
	arm-linux-gnueabihf-gcc -g -c Mythread.c -o Mythread.o  -lpthread
Queue.o:Queue.c Queue.h timer.h ReadConfig.h
	arm-linux-gnueabihf-gcc -g -c Queue.c -o Queue.o
.PHONY : clean

clean:
	rm main $(objects)
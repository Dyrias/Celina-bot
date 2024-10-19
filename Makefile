obj ?= main.o #memory.o
#VPATH = ./Memory

program: $(obj)
	gcc $^ -o $@

main.o: main.c
	gcc -c $^ -o $@

memory.o: memory.c
	gcc -c $^ -o $@
fetch : 
	git fetch origin
	git merge origin/merge

pull :
	git pull origin main

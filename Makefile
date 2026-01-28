all:
	cc main.c map.c pso.c logger.c utils.c -o pso -lm

clean:
	rm -f pso wyniki.csv
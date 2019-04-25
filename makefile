all: euler.dat rk4.dat leapfrog.dat grafica.png

%.png: %.dat grafica.png
	python3 graficar.py
	
%.dat: a.out
	./a.out

a.out: JuanVelasquez_Ejercicio26.cpp
	g++ JuanVelasquez_Ejercicio26.cpp

clean:
	rm -rf *.x *.dat *.png
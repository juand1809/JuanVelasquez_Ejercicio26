#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename);

float dzdt(float t, float y, float z, float omega);
float dydt(float t, float y, float z, float omega);

int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat");
  return 0;
}

float dzdt(float t, float y, float z, float omega){
	return -(omega*omega)*y;
}

float dydt(float t, float y, float z, float omega){
	return z;
}

void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0.0;
  float y_old,z_old;  
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){ 
   outfile << t << " " << y << " " << z << endl;
   y_old = y;
   z_old = z;	  
   y = y_old + delta_t * z;
   z = z_old - delta_t * pow(omega,2) * y_old;
   t = t + delta_t;
  }
  outfile.close();
}

void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0.0;
  float y_old,z_old;
  float k,k1,k2,k3,k4;
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){
   outfile << t << " " << y << "" << z << endl;
   y_old = y;
   z_old = z;
   k1 = -(omega*omega)*y_old;
   k2 = -(omega*omega)*(y_old + (delta_t*k1/2));
   k3 = -(omega*omega)*(y_old + (delta_t*k2/2));
   k4 = -(omega*omega)*(y_old + (delta_t*k3));
   k = (k1 + 2*k2 + 2*k3 + k4)/6;
   y = y_old + delta_t*k;
   z = z_old + delta_t*y;
   t = t + delta_t;
  }
  outfile.close();
}

void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float z=0.0;
  float y_old,z_old,z_medio;  
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){
   outfile << t << " " << y << "" << z << endl;
   y_old = y;
   z_old = z;	
   z_medio = z_old - (delta_t/2)*(omega*omega)*y_old;
   y = y_old + z_medio*delta_t;
   z = z_medio - (delta_t/2)*(omega*omega)*y;
   t = t + delta_t;
  }
  outfile.close();
}


// Funciones para el main
void Usage(int argc, char *argv[]);
void cabecera(void);
bool todo_default(Mundo* &mundo);
Mundo* crear_mundo(void);
char tipo_mundo(void);
char default_tipo(int tipo);
Posicion posiciones(Mundo* mundo);
int control_errores_int(void);
std::list<Hormiga> eleccion_hormigas(Mundo* mundo, unsigned& num_hormigas);
unsigned turnos(void);
Velocidad velocidad_preferida(void);
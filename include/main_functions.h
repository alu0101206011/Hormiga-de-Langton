// Funciones para el main
void Usage(int argc, char *argv[]);
void cabecera(void);
bool todo_default(Mundo* &mundo, std::list<Hormiga*> &hormiga_list);
Mundo* crear_mundo(void);
char tipo_mundo(void);
char default_tipo(int tipo);
Posicion posiciones(Mundo* mundo);
int control_errores_int(void);
Hormiga* crear_hormiga(Mundo* mundo, Posicion posicion);
std::list<Hormiga*> eleccion_hormigas(Mundo* mundo, int& num_hormigas);
unsigned turnos(void);
Velocidad velocidad_preferida(void);
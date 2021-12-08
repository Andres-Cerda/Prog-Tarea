// Variables 

// Los códigos van en orden es decir el 101 es de las papas, el 102 es de los fideos, el 103 es del aceite y el 104 es de la leche.

int  PRODUCTO [4] = {101,102,103,104};
int  PRECIOS [4] = {1000,500,1300,1000};
int  cantidadSala [4] = {8,8,7,5};
int  cantidadBodega [4] = {5,7,8,8};
int  totalBodegaSala = 0;

long USUARIO_TRABAJADOR_ENTREGADO = 123456789;
long usuarioTrabajador = 0; 
int  usuarioBloqueado = 0; 

char producto_1[6] = "Papas";
char producto_2[7] = "Fideos";
char producto_3[7] = "Aceite";
char producto_4[6] = "Leche";

long usuarioCreado = 0;
long usuarioCreado0 = 0;

int  opcion = 0;
int  menu = 0;
int  inventario = 0;
int  inventario_2 = 0;
int  compra = 0;
int  Total = 0;
int  Pago = 0;
int  Restante = 0; 

int  compraCancelada = 0;

int  codigoProductosAgregados = 0;
int  cantidadProductosAgregados = 0;
int  otroProducto = 0;

int  codigoProductoRobado = 0;
int  cantidadProductosRobados = 0;
int  otroProductoRobado = 0;

int  codigoProductoFalla = 0;
int  cantidadProductosFalladosSala = 0;
int  cantidadProductosFalladosBodega = 0;
int  otroProductoFallado = 0;

int  codigoProductoVendido = 0;
int  vendidos = 0; 
int  cantidadProductoVendido = 0;

// Nuevas varianbles 

char agendaSeccionNueva[50];
int  Cantidad_Por_Producto[1000];
FILE * baseDeDatos;
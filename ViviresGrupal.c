/**
 * @file ViviresGrupal.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTOS 30
#define CLIENTE_INFO_SIZE 250
#define PRODUCTO_INFO_SIZE 80

typedef struct {
    char nombres[100], cedula[14], correo[60], direccion[90];
    int id;
} Cliente;

typedef struct {
    char codigo[12], descripcion[60];
    float cantidad, precioUnitario;
} Producto;

typedef struct {
    char fechaEmision[11];
    int numeroFactura;
    Cliente cliente;
    Producto productos[MAX_PRODUCTOS];
    int numProductos;
    float subtotal, totalIVA, totalPagar;
} Factura;

int generarNumeroFactura() { return rand() % 1000000; }

void obtenerFechaDelSistema(char *fecha) {
    time_t t = time(NULL);
    strftime(fecha, 11, "%Y-%m-%d", localtime(&t));
}

void mostrarInformacion(const char *info) { printf("%s\n", info); }

float calcularPrecioTotal(const Producto *producto) { return producto->cantidad * producto->precioUnitario; }

float calcularSubtotal(const Factura *factura) {
    float subtotal = 0;
    for (int i = 0; i < factura->numProductos; ++i)
        subtotal += calcularPrecioTotal(&factura->productos[i]);
    return subtotal;
}

void guardarFacturaEnArchivoYMostrar(const Factura *factura) {
    FILE *archivo = fopen("factura.txt", "w");
    if (!archivo) { printf("Error al abrir el archivo.\n"); return; }

    fprintf(archivo, "Factura de Venta\nFecha de Emision: %s\nNumero de Factura: %06d\n", factura->fechaEmision, factura->numeroFactura);
    fprintf(archivo, "Cliente:\n%s\nID: %d\n\nProductos:\n", CLIENTE_INFO_SIZE, factura->cliente.nombres, factura->cliente.cedula, factura->cliente.correo, factura->cliente.direccion, factura->cliente.id);
    for (int i = 0; i < factura->numProductos; ++i)
        fprintf(archivo, "Codigo: %s\nDescripcion: %s\nCantidad: %.2f\nPrecio Unitario: %.2f\n\n", PRODUCTO_INFO_SIZE, factura->productos[i].codigo, factura->productos[i].descripcion, factura->productos[i].cantidad, factura->productos[i].precioUnitario);

    factura->subtotal = calcularSubtotal(factura);
    factura->totalIVA = factura->subtotal * 0.14; // IVA del 14%
    factura->totalPagar = factura->subtotal + factura->totalIVA;

    fprintf(archivo, "Subtotal Neto: %.2f USD\nIVA(14%%): %.2f\nTotal a Pagar: %.2f USD\n", factura->subtotal, factura->totalIVA, factura->totalPagar);
    fclose(archivo);
    mostrarInformacion("La factura se ha guardado correctamente en el archivo 'factura.txt'.");
}

void registrarCliente(Cliente *cliente) {
    mostrarInformacion("Ingrese los datos del cliente:");
    printf("Nombres: "); scanf(" %[^\n]", cliente->nombres);
    printf("Cedula: "); scanf("%s", cliente->cedula);
    printf("Correo: "); scanf("%s", cliente->correo);
    printf("Direccion: "); scanf(" %[^\n]", cliente->direccion);
    printf("ID: "); scanf("%d", &cliente->id);
}

void registrarProductos(Factura *factura) {
    mostrarInformacion("Ingrese los productos comprados:");
    printf("Cantidad de productos: "); scanf("%d", &factura->numProductos);
    for (int i = 0; i < factura->numProductos; ++i) {
        printf("Producto %d:\n", i + 1);
        printf("Codigo: "); scanf("%s", factura->productos[i].codigo);
        printf("Descripcion: "); scanf(" %[^\n]", factura->productos[i].descripcion);
        printf("Cantidad: "); scanf("%f", &factura->productos[i].cantidad);
        printf("Precio unitario: "); scanf("%f", &factura->productos[i].precioUnitario);
    }
}

int main() {
    Factura factura;
    srand(time(NULL));

    factura.numeroFactura = generarNumeroFactura();
    obtenerFechaDelSistema(factura.fechaEmision);
    registrarCliente(&factura.cliente);
    registrarProductos(&factura);
    guardarFacturaEnArchivoYMostrar(&factura);
    return 0;
}

#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento(){
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 3};  /* 200 x 3 = 600 */
    carrito_agregar(&c, p);
    Producto l = {"Leche", 350, 2}; /* 350 x 2 = 700 */
    carrito_agregar(&c, l);
    int total_esperado =carrito_total(&c);  /* total = 600 + 700 = 1300 */
    ASSERT_IGUAL(1300, total_esperado); 
    int total_con_descuento = carrito_descuento(total_esperado, 10); /* 10% de descuento */
    ASSERT_IGUAL(1170, total_con_descuento);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar(){
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 1};
    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));
    }
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
